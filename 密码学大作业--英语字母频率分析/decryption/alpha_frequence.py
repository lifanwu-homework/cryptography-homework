import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

with open("alpha_frequence.txt") as file_obj:
     content = file_obj.read()

temp = content.split()
sample_1 = []
for i in range(0,26):
    sample_1.append(int(temp[i]))
    


p1 = plt.bar(range(1, len(sample_1) + 1),
             height = sample_1,
             width = 0.3)
plt.ylabel('frequence')
plt.title('alpha_frequence')
plt.show()


with open("double_alpha_frequence.txt") as file_obj:
     content = file_obj.read()

temp = content.split()

#构造需要显示的值
X = np.arange(0, 26, step=1)#X轴的坐标
Y = np.arange(0, 26, step=1)#Y轴的坐标
                           #设置每一个（X，Y）坐标所对应的Z轴的值，在这边Z（X，Y）=X+Y
Z = np.zeros(shape=(26, 26))
for i in range(26):
    for j in range(26):
        Z[i, j] = int(temp[i * 26 + j])

xx, yy = np.meshgrid(X, Y)#网格化坐标
X, Y = xx.ravel(), yy.ravel()#矩阵扁平化
bottom = np.zeros_like(X)#设置柱状图的底端位值
Z = Z.ravel()#扁平化矩阵
width = height = 1#每一个柱子的长和宽

#绘图设置
fig = plt.figure()
ax = fig.gca(projection='3d')#三维坐标轴
ax.bar3d(X, Y, bottom, width, height, Z, shade=True)#
                                                    #坐标轴设置
ax.set_xlabel('X')
ax.set_ylabel('Y')
ax.set_zlabel('frequence')
plt.show()