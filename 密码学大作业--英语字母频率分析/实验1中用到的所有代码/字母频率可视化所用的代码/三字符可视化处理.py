
import numpy as np
import matplotlib.pyplot as plt
import matplotlib.cm
import math
cmap = matplotlib.cm.get_cmap("rainbow")

def color(x):#将一个0~1之间的实数映射到一个颜色点，实数越大颜色越红越深
    origin_color=list(cmap(math.sqrt(math.sqrt(math.sqrt(x)))))
    origin_color[3]=math.sqrt(math.sqrt(x))#设置透明度
    return tuple(origin_color)#返回颜色的三元组

file=open('cipher_triple_alpha_frequence.txt')
frequence=list(map(int,file.read().split()))
max_frequence=max(frequence)
print(max_frequence)
print(frequence.index(max_frequence))
def plot_colormap(cmap_name):
    fig, ax = plt.subplots(figsize=(6, 2))
    # cmap = matplotlib.cm.get_cmap(cmap_name)
    colors = cmap(np.linspace(0, 1, cmap.N))
    ax.imshow([colors], extent=[0, 10, 0, 1])
    ax.set_xticks([])
    ax.set_yticks([])
    ax.set_title(cmap_name)
    plt.show()
#print color map
plot_colormap("rainbow")

Dice3 = plt.axes(projection="3d")
 
print(cmap)

x=[]
y=[]
z=[]
draw=[]
for i in range(26):
    for j in range(26):
        for k in range(26):
            if frequence[i*26*26+j*26+k]>5:#不统计出现次数过小的点
                x.append(i)
                y.append(j)
                z.append(k)
                draw.append(color(1.0*frequence[i*26*26+j*26+k]/max_frequence))
# Creating plot
# print(draw)
Dice3.scatter3D(x, y, z, color=draw)
Dice3.set_xlabel("first letter")
Dice3.set_ylabel("second letter")
Dice3.set_zlabel("third letter")
# show plot
plt.show()
