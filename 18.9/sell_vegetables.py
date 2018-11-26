mean = lambda x: sum(x)/len(x)
n = input()
l = input()
l = [int(x) for x in l.split()]
l = [str(int(mean(l[max(0,i-1):i+2]))) for i in range(len(l))]
print(' '.join(l))