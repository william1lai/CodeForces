#include <iostream>
#include <deque>

using namespace std;

struct IntPair
{
	int f;
	int s;
};

int main()
{
	int n, m, i, j, a, b;
	cin >> n >> m >> i >> j >> a >> b;

	i--; j--;
	
	int** board = new int*[n];
	for (int ii = 0; ii < n; ii++)
	{
		board[ii] = new int[m];
		for (int jj = 0; jj < m; jj++)
			board[ii][jj] = -1;
	}

	deque<IntPair> dq;
	board[i][j] = 0;
	IntPair ip;
	ip.f = i; ip.s = j;
	dq.push_back(ip);

	while (!dq.empty())
	{
		IntPair temp = dq.front();
		dq.pop_front();
		
		if (temp.f + a < n)
		{
			if (temp.s + b < m)
			{
				if (board[temp.f + a][temp.s + b] == -1)
				{
					board[temp.f+a][temp.s+b] = board[temp.f][temp.s] + 1;
					ip.f = temp.f + a; ip.s = temp.s + b;
					dq.push_back(ip);
				}
			}
			if (temp.s - b >= 0)
			{
				if (board[temp.f + a][temp.s - b] == -1)
				{
					board[temp.f+a][temp.s-b] = board[temp.f][temp.s] + 1;
					ip.f = temp.f + a; ip.s = temp.s - b;
					dq.push_back(ip);
				}
			}
		}
		if (temp.f - a >= 0)
		{
			if (temp.s + b < m)
			{
				if (board[temp.f - a][temp.s + b] == -1)
				{
					board[temp.f-a][temp.s+b] = board[temp.f][temp.s] + 1;
					ip.f = temp.f - a; ip.s = temp.s + b;
					dq.push_back(ip);
				}
			}
			if (temp.s - b >= 0)
			{
				if (board[temp.f - a][temp.s - b] == -1)
				{
					board[temp.f-a][temp.s-b] = board[temp.f][temp.s] + 1;
					ip.f = temp.f - a; ip.s = temp.s - b;
					dq.push_back(ip);
				}
			}
		}
	}

	//find min steps to squares on edge
	int min = 987654321;

		if (board[0][0] != -1 && board[0][0] < min)
			min = board[0][0];
		if (board[0][m-1] != -1 && board[0][m-1] < min)
			min = board[0][m-1];
		if (board[n-1][0] != -1 && board[n-1][0] < min)
			min = board[n-1][0];
		if (board[n-1][m-1] != -1 && board[n-1][m-1] < min)
			min = board[n-1][m-1];

	if (min == 987654321)
		cout << "Poor Inna and pony!\n";
	else
		cout << min << "\n";
}