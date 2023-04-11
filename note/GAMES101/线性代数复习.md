# 线性代数复习（Review of Linear Algebra）

## 向量（Vectors）

向量指的是具有**大小**（Magnitude）和**方向**（Direction）的量。在物理学中也称为矢量。向量的表示通常使用小写字母上面加上向右的箭头 $\rightarrow$ 表示，例如 $\vec{a}$，或者使用粗体的小写字母表示，例如 $\boldsymbol{a}$.

向量具有平移不变形。向量只与大小和方向有关系，和向量的起点和终点没有关系。向量也只包含两个属性：**大小**和**方向**。

对于空间中的两个点 $𝐴$ 和 $𝐵$，从 $𝐴$ 到 $𝐵$ 的向量可以表示为 $\overrightarrow{AB}$，计算方法为 $\overrightarrow{AB} = B - A$.

对于向量 $\vec{a}$ 来说，其大小，即 $\vec{a}$ 的模（norm）记为：$\left\| \vec{a} \right\|$.

### 向量归一化（Vector Normalization）

**模为 1 的向量**称之为**单位向量（Unit vector）**，对于向量 $\vec{a}$，与其方向相同的单位向量记为：$\hat{a}$，计算公式为：

$$
\hat{a} = \frac{\vec{a}}{\left\| \vec{a} \right\|}
$$

> 上述公式不适应于零向量。零向量方向是唯一的，没有对应的单位向量。
>
> 单位向量一般用来表示方向。

### 向量加法（Vector Addition）

向量的加法可以用两种法则：**平行四边形法则**（Parallelogram law）或者**三角形法则**（Triangle law）。

<center>
    <img src="https://user-images.githubusercontent.com/62458905/229414846-986e11d8-e705-4cea-bdc0-f76aa376d60a.png" alt="Img" style="zoom:30%;" />
</center>

两个向量相加时，以表示这两个向量的线段为邻边作平行四边形，这两个邻边之间的对角线就代表向量和的大小和方向，这就叫做平行四边形定则。

三角形法则是指，将一个向量的起点移动到另一个向量的终点时，向量和为从未移动向量的起点指向所移动向量的终点的向量。三角形法则适用于多个向量求和，只需要将向量按照相加顺序依次首尾排列，第一个向量的起点指向最后一个向量的终点的向量就是求和的结果。

在代数上，对于在笛卡尔坐标系中定义的向量，向量求和可以简化为求向量各个对应坐标值的和。

### 笛卡尔坐标系（Cartesian Coordinates System）

笛卡尔坐标系，亦称直角坐标系，是一种正交坐标系。二维的直角坐标系是由两条相互垂直，相交于原点的数线构成的。在平面内，任何一点的坐标是根据数轴上对应的点的坐标设定的。对于向量，我们认为所有向量都是以原点为起点，那么终点的坐标就可以表示一个唯一的向量。

在计算机图形学中，我们默认所有的向量都是列向量，用符号表示向量，向量的转置以及向量的模如下：

$$
A=\begin{bmatrix}
x \\
y
\end{bmatrix}
$$

$$
A^{\mathrm{T}} = \begin{bmatrix}
x & y
\end{bmatrix}^{T}
$$

$$
\left\| A \right\| = \sqrt{x^2 + y^{2}}
$$

### 向量乘法（Vector Multiplication）

#### 点乘（Dot Product）

点乘，又称为向量的内积。计算公式为：

$$
\vec{a} \cdot \vec{b}=\left\| \vec{a} \right\| \left\|\vec{b} \right\| \cos \theta
$$

在笛卡尔坐标系下点乘的计算结果是逐坐标元素相乘后相加的结果。

在 2 维情况下：

$$
\vec{a} \cdot \vec{b} = \begin{bmatrix} x_a \\ y_a \end{bmatrix} \cdot \begin{bmatrix} x_b \\ y_b \end{bmatrix} = x_a x_b + y_a y_b
$$

在 3 维情况下：

$$
\vec{a} \cdot \vec{b} = \begin{bmatrix} x_a \\ y_a \\ z_a  \end{bmatrix} \cdot \begin{bmatrix} x_b \\ y_b \\ z_b \end{bmatrix} = x_a x_b + y_a y_b + z_a z_b
$$

点乘的性质：

$$
\begin{align*} 
\vec{a} \cdot \vec{b} &= \vec{b} \cdot \vec{a} \text{ (交换律)} \\
\vec{a} \cdot (\vec{b} + \vec{c}) &= \vec{a} \cdot \vec{b} + \vec{a} \cdot \vec{c} \text{ (分配律)} \\
(k \vec{a}) \cdot \vec{b} &= \vec{a} \cdot (k\vec{b}) = k(\vec{a} \cdot \vec{b})
\end{align*}
$$

点乘的应用：

1. 计算出两个向量的夹角：

$$
\cos \theta=\frac{\vec{a} \cdot \vec{b}}{\left\| \vec{a} \right \| \left\| \vec{b} \right\|}
$$

用 $\vec{a}$ 和 $\vec{b}$ 的单位向量表示为：

$$
\cos \theta = \hat{a} \cdot \hat{b}
$$

2. 计算一个向量在另外一个向量上的投影：

向量 $\vec{b}$ 在向量 $\vec{a}$ 上的投影满足：

$$
\vec{b}_{\perp} = k \vec{a}
$$

$k$ 的大小为：

$$
k = \left\| \vec{b}_{\perp} \right\| = \left\| \vec{b} \right\| \cos \theta
$$

已知两个向量的内积，则 $k$ 的大小可表示如下：

$$
k = \left\| \vec{b} \right\| \cos \theta = \frac{\vec{a} \cdot \vec{b}}{\left\| \vec{a} \right\|}
$$

3. 计算两个向量的接近程度：根据 $\cos$ 在角度 $\left[0, \pi \right]$ 之间的值可以得出结论，越接近（夹角比较小）的两个向量的单位向量点乘结果越接近于 $1$，反之越远离（夹角比较大）的两个向量的单位向量点乘结果越接近于 $-1$.
4. 计算两个向量的方向是相同还是相反的：首先我们定义两个向量的方向相同或者相反。如图所示，向量 $\vec{a}$ 以其垂线为分界，在上半部分（上半圆）的向量认为和向量 $\vec{a}$ 方向基本相同，在下半部分（下半圆）的向量认为和向量 $\vec{a}$ 方向基本相反。

<center>
    <img src="https://user-images.githubusercontent.com/62458905/229419075-8481a506-5625-415a-9119-046d7eb172be.png" alt="Img" style="zoom:45%;" />
</center>

如果两个向量方向基本相同，那么点乘的结果大于 $0$；如果两个向量的方向基本相反，点乘的结果小于 $0$；如果两个向量是垂直的，那么点乘的结果等于 $0$.

#### 叉乘（Cross product）

叉乘，又称作向量的外积。两个向量叉乘的结果还是一个向量，这个向量和原来的两个向量垂直。叉乘的结果向量的长度为：

$$
\left\| \vec{a} \times \vec{b} \right\| = \left\| \vec{a} \right\| \left\| \vec{b} \right\| \sin {\varphi}
$$

结果向量的方向满足**右手定则**。叉乘不满足交换律。

<center>
    <img src="https://user-images.githubusercontent.com/62458905/229419697-1137b072-5391-4dd0-9f7f-bfa03129e82a.png" alt="Img" style="zoom:100%;" />
</center>

> 叉乘在右手坐标系中满足右手定则，在左手坐标系中满足左手定则，但其代数运算在右手坐标系和左手坐标系的是一样的。

叉乘的性质：

$$
\begin{align*}
\vec{a} \times \vec{b} &= - \vec{b} \times \vec{a} \\
\vec{a} \times \vec{a} &= \vec{0} \\
\vec{a} \times (\vec{b} + \vec{c}) &= \vec{a} \times \vec{b} + \vec{a} \times \vec{c} \\
\vec{a} \times {k \vec{b}} &= k (\vec{a} \times \vec{b}) \\
\end{align*}
$$

在笛卡尔坐标系的表示下进行叉乘计算的结果可以写作：

$$
\vec{a} \times \vec{b} = \begin{bmatrix} 
y_a z_b-y_b z_a \\
z_a x_b-x_a z_b \\
x_a y_b-y_a x_b
\end{bmatrix}
$$

我们可以将向量 $\vec{a}$ 写成等价的矩阵形式：

$$
\vec{a} \times \vec{b} = A^{*} b = \begin{bmatrix}
0 & -z_a & y_a  \\ 
z_a & 0 & -x_a \\ 
-y_a & x_a & 0
\end{bmatrix} 
\begin{bmatrix}
x_b \\
y_b \\
z_b
\end{bmatrix}
$$

称 $A^*$ 为向量 $\vec{a}$ 的对偶矩阵（dual matrix）.

叉乘的应用：

1. 判断一个向量在另一个向量的左边还是右边：如果 $\vec{a} \times \vec{b}$ 的方向与 $z$ 轴正方向相同，则说明 $\vec{b}$ 在 $\vec{a}$ 的左侧；如果相反，则说明 $\vec{b}$ 在 $\vec{a}$ 的右侧。将 $\vec{a}$ 和 $\vec{b}$ 的起点移动到重合到一起，如果 $\vec{b}$ 在 $\vec{a}$ 的左侧，则 $\vec{b}$ 的终点在 $\vec{a}$ 的左侧；如果 $\vec{b}$ 在 $\vec{a}$ 的右侧，则 $\vec{b}$ 的终点在 $\vec{a}$ 的右侧。
2. 判定一个点在三角形的内部还是外部：如果 点 $P$ 在点 $\overrightarrow{AB}$，$\overrightarrow{BC}$，$\overrightarrow{CA}$ 的同一侧，则说明点 $P$ 在 $\triangle ABC$ 的内部。即可以判断 $\overrightarrow{AB} \times \overrightarrow{AP}$，$\overrightarrow{BC} \times \overrightarrow{BP}$，$\overrightarrow{CA} \times \overrightarrow{CP}$ 的方向是否全部相同。

<center>
    <img src="https://user-images.githubusercontent.com/62458905/229421008-1c4ef68b-ca64-4d19-9517-151b5d051c03.png" alt="Img" style="zoom:50%;" />
</center>

## 正交基和笛卡尔坐标系（Orthonormal bases and coordinate frames）

对于任意的 3 个 3 维向量，满足：

$$
\begin{align*}
& \left\| \vec{u} \right\| = \left\| \vec{v} \right\| = \left\| \vec{w} \right\| = 1 \\ 
& \vec{u} \cdot \vec{v}=\vec{v} \cdot \vec{w}=\vec{u} \cdot \vec{w}=0 \\
& \vec{w}=\vec{u} \times \vec{v} \quad \text {(right-handed)} \\
\end{align*}
$$

则向量 $\vec{u}$、$\vec{v}$、$\vec{w}$ 定义了一个右手坐标系，对于任意一个向量 $\vec{p}$，在这个坐标系中的表示为：

$$
\vec{p}=(\vec{p} \cdot \vec{u}) \vec{u}+(\vec{p} \cdot \vec{v}) \vec{v}+(\vec{p} \cdot \vec{w}) \vec{w}
$$

其中 $\vec{p} \cdot \vec{u}$ 是 $\vec{p}$ 在 $\vec{u}$ 的投影（projection）。

## 矩阵（Matrices）

矩阵是一个数的阵列（array），这个阵列中的数可以是实数也可以是虚数。如下所示是一个由实数组成的矩阵。

$$
\begin{bmatrix}
1 & 3 \\
5 & 2 \\
0 & 4
\end{bmatrix}
$$

矩阵的加法和标量乘法（multiplication by a scalar）只需逐元素操作即可。

### 矩阵乘法（Matrix Multiplication）

矩阵乘法 $A \times B$ 必须满足 $A$ 的列数 = $B$ 的行数。求出的矩阵的大小为：

$$
A_{n\times m} B_{n \times p} = C_{n \times p}
$$

乘法性质：

$$
\begin{align*}
AB &\neq BA \text{ (一般来说不满足交换律)}. \\
(AB)C &= A(BC) \\
(A + B)C &= AC + BC \\
(AB)^{\mathrm{T}} &= B^{\mathrm{T}} A^{\mathrm{T}} \\
\end{align*}
$$

矩阵和向量相乘时，认为向量是一个列向量并乘在矩阵的右边。

### 单位矩阵和逆（Identity Matrix And Inverses）

单位矩阵是一个左上到右下对角线值为 1，其他值为 0 的正方形矩阵，以长度为 3 的单位矩阵为例：

$$
I_{3 \times 3}=\begin{bmatrix}
1 & 0 & 0 \\
0 & 1 & 0\\
0 & 0 & 1
\end{bmatrix}
$$

单位矩阵定义了矩阵的逆运算。对于矩阵 $A$ 来说，矩阵的逆 $A^{-1}$ 满足：

$$
\begin{align*}
AA^{-1} &= A^{-1}A = I \\
(AB)^{-1} &= B^{-1} A^{-1} \\
(A^\mathrm{T})^{-1} &= (A^{-1})^\mathrm{T} = A^{-\mathrm{T}}
\end{align*}
$$

### 向量乘法的矩阵形式（Vector Multiplication In Matrix form）

点乘：

$$
\vec{a} \cdot \vec{b} = \vec{a}^{\mathrm{T}}\vec{b} = \begin{bmatrix} x_a & y_a & z_a \end{bmatrix} \begin{bmatrix} x_b \\ y_b \\ z_b \end{bmatrix} = x_a y_a + y_a y_b + z_a z_ b
$$

叉乘：

$$
\vec{a} \times \vec{b} = A^{*} b = \begin{bmatrix} 
0 & -z_a & y_a \\
z_a & 0 & -x_a \\
-y_a & x_a & 0
\end{bmatrix}
\begin{bmatrix}
x_b \\
y_b \\
z_b
\end{bmatrix}
$$
