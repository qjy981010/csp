
# score: 50

length = int(input())
second = [int(x) for x in input().split()]

def process(result, idx):
    if idx == 0:
        result.append(1)
    elif idx == 1:
        num = 2*second[idx-1] - result[idx-1]
        while num < 1:
            num += 1
            if num >= 2*(second[idx-1]+1) - result[idx-1]:
                return False
        result.append(num)
    elif idx == length:
        if (result[idx-2]+result[idx-1])//2 != second[idx-1]:
            return False
        else:
            print(' '.join([str(x) for x in result]))
            return True
    else:
        num = 3*second[idx-1] - result[idx-1] - result[idx-2]
        while num < 1:
            num += 1
            if num >= 3*(second[idx-1]+1) - result[idx-1] - result[idx-2]:
                return False
        result.append(num)


    while True:
        if (process(result.copy(), idx+1) == False):
            result[idx] = result[idx]+1
            if idx==1 and (result[idx]>= 2*(second[idx-1]+1) - result[idx-1]):
                return False
            elif idx>1 and (result[idx] >= 3*(second[idx-1]+1) - result[idx-1] - result[idx-2]):
                return False
        else:
            return True


process([], 0)