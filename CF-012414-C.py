import math

N = input()
nums = [int(x) for x in raw_input().split(' ')]
queries = input()

#preprocess
isprime = []
primefactors = dict()
primes = set()
largest = sorted(nums)[-1]
for i in range(largest + 1):
    isprime.append(True)
for i in range(2, largest + 1):
    if isprime[i]:
        primes.add(i)
        for j in range(i, largest + 1, i):
            if j != i:
                isprime[j] = False

for i in range(queries):
    pikachu = [int(x) for x in raw_input().split(' ')]
    start = pikachu[0]
    end = pikachu[1]
    if end >= len(isprime):
        end = len(isprime) - 1

    ans = 0
    for i in range(len(nums)):
        for j in primes:
            if j <= end and j >= start:
                if nums[i] % j == 0:
                    ans = ans + 1

        
    print ans
