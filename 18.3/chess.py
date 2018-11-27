N = int(input())

def dot(a, b):
    return [x*y for x,y in zip(a,b)]

s = []
s.extend([slice(x*3, x*3+3) for x in range(3)])
s.extend([slice(x, None, 3) for x in range(3)])
s.append(slice(0, None, 4))
s.append(slice(2, 8, 2))
# m = list(range(9))
# print([m[x] for x in s])
# print([str(x)+'      ' for x in range(9)])

zero_loc = [[0,3,6], [0,4], [0,5,7], [1,3], [1,4,6,7], [1,5], [2,3,7], [2,4], [2,5,6]]

def process(m):
    count = [m.count(i) for i in range(3)]
    alice_turn = count[1] == count[2]
    bob_turn = count[1] > count[2]
    zero_count = count[0]

    triplet = [m[si] for si in s] # 8x3
    triplet = [(x.count(1), x.count(2)) for x in triplet] # 8x2
    flags = [((x[0]==2 and x[1]==0), (x[0]==0 and x[1]==2), x[0]==3, x[1]==3) for x in triplet] # 8x4
    count = list(zip(*flags)) # 4x8
    if True in count[2]: return zero_count+1
    if True in count[3]: return -zero_count-1
    t1 = count[0].count(True)
    if t1>0 and alice_turn: return zero_count
    t2 = count[1].count(True)
    if t2>0 and bob_turn: return -zero_count
    if t1==0 and t2==0: return 0
    alice_count2 = bob_count2 = 0
    for i in range(9):
        if m[i] == 0:
            if True in [count[0][x] for x in zero_loc[i]]:
                alice_count2 += 1
            if True in [count[1][x] for x in zero_loc[i]]:
                bob_count2 += 1
    if alice_count2>1: return zero_count-1
    if bob_count2>1: return -zero_count+1
    if t1>0 and (2 not in (m[0], m[2], m[6], m[8])):
        return zero_count-3
    return 0

result = []
for i in range(N):
    matrix = []
    for j in range(3):
        matrix.extend([int(x) for x in input().split()])
    result.append(process(matrix))

print('\n'.join([str(x) for x in result]))
