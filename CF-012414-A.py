pikachu = [int(x) for x in raw_input().split(' ')]
N = pikachu[0]
C = pikachu[1]

maxdrop = C
prices = [int(x) for x in raw_input().split(' ')]
for i in range(len(prices) - 1):
    diff = prices[i] - prices[i+1]
    if (diff > maxdrop):
        maxdrop = diff

print (maxdrop - C)
