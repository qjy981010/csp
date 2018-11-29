# if c++: score = 100
# elif python: score = 85

N = int(input())

s = []
s.extend([slice(x * 3, x * 3 + 3) for x in range(3)])
s.extend([slice(x, None, 3) for x in range(3)])
s.append(slice(0, None, 4))
s.append(slice(2, 8, 2))

result = []
matrix = None


def process(k):
    zero_count = matrix.count(0)
    if zero_count == 0:
        return 0
    finish = [x[0] for x in [matrix[j] for j in s] if x[0] == 3 - k and x.count(x[0]) == len(x)]
    if finish:
        return zero_count + 1 if finish[0] == 1 else -zero_count - 1
    max_or_min = max if k==1 else min
    max_or_min_value = -10 if k==1 else 10
    for i in range(9):
        if matrix[i] == 0:
            matrix[i] = k
            max_or_min_value = max_or_min(process(3 - k), max_or_min_value)
            matrix[i] = 0
    return max_or_min_value


for i in range(N):
    matrix = []
    for j in range(3):
        matrix.extend([int(x) for x in input().split()])
    result.append(process(1))

print('\n'.join([str(x) for x in result]))
