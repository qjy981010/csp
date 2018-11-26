n = int(input())
h = [[int(x) for x in input().split()] for i in range(n)]
w = [[int(x) for x in input().split()] for i in range(n)]
i, j = 0, 0
result = 0
while i<n and j<n:
    if h[i][1] <= w[j][0]:
        i += 1
    elif h[i][0] >= w[j][1]:
        j += 1
    else:
        if h[i][1] > w[j][1]:
            result += w[j][1] - max(h[i][0], w[j][0])
            j += 1
        elif h[i][1] < w[j][1]:
            result += h[i][1] - max(h[i][0], w[j][0])
            i += 1
        else:
            result += h[i][1] - max(h[i][0], w[j][0])
            i += 1
            j += 1
print(result)