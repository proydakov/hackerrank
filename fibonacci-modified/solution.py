import sys

data = []

for line in sys.stdin:
    for var in line.split():
        var = int(var)
        data.append(var)

t1 = data[0]
t2 = data[1]
n  = data[2]

cache = []
for x in range(0, n):
    cache.append(0)

cache[0] = t1
cache[1] = t2

for i in range(2, n):
    cache[i] = cache[i - 2] + cache[i - 1] * cache[i - 1]

print(cache[n - 1])
