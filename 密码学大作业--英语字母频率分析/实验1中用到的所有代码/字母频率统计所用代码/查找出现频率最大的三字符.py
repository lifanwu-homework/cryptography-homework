
import numpy as np
all_double_alpha=list(map(int,input().split()))
alpha_frequence = np.array(all_double_alpha)
a=alpha_frequence.argsort()[-10:][::-1]

for i in a:
    alpha1=int(i/(26*26))
    alpha2=int((i/(26))%26)
    alpha3=i%26
    print(chr(alpha1+ord('a')),chr(alpha2+ord('a')),chr(alpha3+ord('a')))
print(a)