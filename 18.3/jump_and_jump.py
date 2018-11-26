l = input().split()
l = [int(x) for x in l]
score = 0
last = 0
for x in l:
    if x == 2:
        if last < 2:
            last = 2
            score += 2
        else:
            last += 2
            score += last
    elif x == 1:
        last = 1
        score += 1
    else:
        break
print(score)