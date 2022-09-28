def gcd(m, n):
    while m != n:
        if m > n:
            m = m - n
        else:
            n = n - m
    return m


def multi_gcd(array):
    l = len(array)
    if l == 1:
        return array[0]
    elif l == 2:
        return gcd(array[0], array[1])
    else:
        return gcd(multi_gcd(array[:l//2]), multi_gcd(array[l//2:]))

cipher=input()
pos=[]
for i in range(len(cipher)-2):
    if cipher[i]=='x' and cipher[i+1]=='y' and cipher[i+2]=='i':
        pos.append(i)
div=[]
for i in range(25,30):
    div.append(pos[i+1]-pos[i])

print(multi_gcd(div))