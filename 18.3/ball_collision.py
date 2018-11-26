from collections import Counter

n, l, t = [int(x) for x in input().split()]
location = [int(x) for x in input().split()]
v = [1] * n

for i in range(t):
    location = [location[i] + v[i] for i in range(n)]
    counter = Counter(location)
    for j in counter:
        if counter[j] > 1:
            idx = location.index(j)
            v[idx] = -v[idx]
            idx = location[idx+1:].index(j)+idx+1
            v[idx] = -v[idx]
    for j in range(n):
        if location[j] == 0:
            v[j] = 1
        if location[j] == l:
            v[j] = -1
print(' '.join([str(x) for x in location]))
