pifpr = [5, 13, 17, 29, 37, 41, 53, 61, 73, 89, 97]
n = int(input())
i, a = 0, 1
while True :
    if pifpr[i] <= n :
        a *= pifpr[i]
        n //= pifpr[i]
    elif pifpr[i - 1] <= n :
        a *= pifpr[i - 1]
        n //= pifpr[i - 1]
    else :
        break
    i += 1
print(a)