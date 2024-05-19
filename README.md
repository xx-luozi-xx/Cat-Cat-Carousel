# Cat-Cat-Carousel
 22级T3大模拟Round 3

## 猫猫的鼓励：
&emsp;&emsp;别急着放弃，看看部分分，能做。

## 题目背景：

&emsp;&emsp;猫猫很贪玩，这天猫猫来到了旋转木马游乐园，想要挑选一个最喜欢的旋转木马进行游玩，但是游乐园“乱花渐欲迷猫眼”，没走两步猫猫就迷路了，猫猫想让你帮她找到她最喜欢的旋转木马，以及旋转木马的入口位置。

## 问题描述：
&emsp;&emsp;这个游乐场具有很多的游乐设施和道路，整个游乐场可以看作一张具有$n$个顶点的有向图，这个游乐场非常魔幻，每一个顶点只会有唯一的出边。每一个“旋转木马”就是图上的一个简单环（从一个点出发最终能回到自己，中途不能访问重复顶点），对于每个“旋转木马”猫猫会有不同的喜爱程度，由于猫猫既想体验更大的“旋转木马”又不想被打扰，所以“旋转木马”简单环上的节点越多，猫猫越喜欢；同时不在这个“旋转木马”简单环上，但是存在路径能到达这个“旋转木马”简单环的节点越少，猫猫越喜欢。

&emsp;&emsp;所以猫猫对于一个“旋转木马”的喜爱程度定义为：“旋转木马”简单环上的节点数量减去不在这个“旋转木马”简单环上，但是存在路径能到达这个“旋转木马”简单环的节点数量。

&emsp;&emsp;形式化地，设图$G=(V,E)$上存在一个简单环$R \subseteq V$, 那么环$R$的喜爱程度为：
$$
\text{Love}(R) = |R|-|\{v\in V|(v \notin R) \wedge (\exist u\in R(v \leadsto u)) \}|
$$

&emsp;&emsp;一个“旋转木马”的入口位置是这个“旋转木马”简单环上编号最小的节点。现在猫猫会将游乐场的地图告诉你，请帮猫猫找到她最喜欢的“旋转木马”以及入口位置。如果猫猫对多个“旋转木马”的喜爱程度相同，那么她会更偏爱“旋转木马”简单环中最大节点编号最大的那一个。

## 输出格式：

&emsp;&emsp;第一行一个整数$n$，表示节点个数，节点编号从$1$到$n$
&emsp;&emsp;接下来$n$行，每一行两个整数$a, b$，表示节点$a$到$b$具有一条有向边。


## 输出格式：

&emsp;&emsp;输出一行若干个用空格隔开的整数，表示猫猫最喜欢的“旋转木马”简单环。其中第一个数是“旋转木马”的入口位置，随后按环的顺序逐个输出其他顶点编号。


## 样例
### 样例 1
**输入**
```
4
1 2
2 3
3 4
4 1
```
**输出**
```
1 2 3 4
```

### 样例 2
**输入**
```
10
1 2
2 1
3 4
4 5
5 3
6 7
7 8
8 9
9 6
10 6
```
**输出**
```
6 7 8 9
```

## 问题规模：

&emsp;&emsp;对于所有的测试点保证：
&emsp;&emsp;$1<n \leq 1e5$，且每个节点有且仅有唯一出边。

## 子任务
|测试点|图中只有唯一的环|所有节点均在环上|分数|
|-|-|-|-|
|$1, 2$| $\checkmark$ |$\checkmark$|$10$|
|$3\sim 8$|$\checkmark$ |不保证|$30$|
|$9\sim 14$|不保证|$\checkmark$ |$30$|
|$15\sim 20$|不保证|不保证|$30$|



## 样例解释
**样例1**
&emsp;&emsp;图中只有唯一环路。
**样例2**
&emsp;&emsp;图中具有三个环，其中猫猫对环$\{3, 4, 5\}$和环$\{6, 7, 8, 9\}$的喜爱程度相同，但是后者最大节点编号更大，受到猫猫的偏爱。


