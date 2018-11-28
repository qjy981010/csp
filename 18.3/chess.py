N = int(input())

s = []
s.extend([slice(x*3, x*3+3) for x in range(3)])
s.extend([slice(x, None, 3) for x in range(3)])
s.append(slice(0, None, 4))
s.append(slice(2, 8, 2))

def process(k):
    for i in range(9):
        if matrix[i] == 0:


result = []
matrix = None
for i in range(N):
    matrix = []
    for j in range(3):
        matrix.extend([int(x) for x in input().split()])
    result.append(process(1))

print('\n'.join([str(x) for x in result]))
