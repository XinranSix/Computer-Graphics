# Review of Linear Algebra

## Vectors

<img src="https://xingqiu-tuchuang-1256524210.cos.ap-shanghai.myqcloud.com/8919/yank-note-picgo-485ed7b3.png" alt="Img" style="zoom:50%;" />

1. Direction and length.
2. No absolute starting position.
3. Magnitude (length): $\left\|\vec{a} \right\|$.
4. Unit vector: $\vec{a}$ is a unit vector $\Leftrightarrow$ $\|\vec{a}\| = 1$.
5. Vector Normalization: find the unit vector of $\vec{a}$: $\hat{a}= \frac{\vec{a}}{\|\vec{a}\|}$.
6. The unit vector is used to represent directions.

### Vector Addition

<img src="https://xingqiu-tuchuang-1256524210.cos.ap-shanghai.myqcloud.com/8919/yank-note-picgo-img-20230228161055.png" alt="Img" style="zoom:50%;" />

-   Geometrically: Parallelogram law and Triangle law.
-   Algebraically: Simply add coordinates.

### Cartesian Coordinates

<img src="https://xingqiu-tuchuang-1256524210.cos.ap-shanghai.myqcloud.com/8919/yank-note-picgo-img-20230228161418.png" alt="Img" style="zoom:50%;" />

$$
A=\begin{bmatrix}
x \\
y
\end{bmatrix}=\begin{bmatrix}
x & y
\end{bmatrix}^{T}
$$

$$
\left\| A\right\|=\sqrt{x^2+y^2}
$$

### Vector Multiplication

#### Dot product

<img src="https://xingqiu-tuchuang-1256524210.cos.ap-shanghai.myqcloud.com/8919/image-20230228162822802.png" alt="image-20230228162822802" style="zoom:50%;" />

$$
\vec{a} \cdot \vec{b}=\|\vec{a}\|\|\vec{b}\| \cos \theta
$$

$$
\cos \theta=\frac{\vec{a} \cdot \vec{b}}{\|\vec{a}\|\|\vec{b}\|}
$$

$$
\cos \theta=\hat{a} \cdot \hat{b}
$$

Properties：

-   $\vec{a} \cdot \vec{b}=\vec{b} \cdot \vec{a}$
-   $\vec{a} \cdot(\vec{b}+\vec{c})=\vec{a} \cdot \vec{b}+\vec{a} \cdot \vec{c}$
-   $(k \vec{a}) \cdot \vec{b}=\vec{a} \cdot(k \vec{b})=k(\vec{a} \cdot \vec{b})$

Dot Product in Cartesian Coordinates:

-   In 2D:

$$
\vec{a} \cdot \vec{b}= \left[\begin{array}{l}
x_a \\
y_a
\end{array}\right] \cdot \left[\begin{array}{l}
x_b \\
y_b
\end{array}\right]=x_a x_b+y_a y_b
$$

-   In 3D:

$$
\vec{a} \cdot \vec{b}= \left[\begin{array}{l}
x_a \\
y_a \\
z_{a}
\end{array}\right] \cdot \left[\begin{array}{l}
x_b \\
y_b \\
z_{b}
\end{array}\right]=x_a x_b+y_a y_b + z_{a}z_{b}
$$

Dot Product in Graphics：

-   Find angle between two vectors: $\cos \theta=\frac{\vec{a} \cdot \vec{b}}{\|\vec{a}\|\|\vec{b}\|}$.
-   Finding <span style="color: rgb(255, 76, 65);">projection</span> of one vector on another.

<img src="https://xingqiu-tuchuang-1256524210.cos.ap-shanghai.myqcloud.com/8919/image-20230228183811832.png" alt="image-20230228183811832" style="zoom:50%;" />

$$
\overrightarrow{b}_{\perp}=k \hat{a} \\
k=\left\|\vec{b}_{\perp}\right\|=\|\vec{b}\| \cos \theta
$$

-   Measure how close two directions are.
-   Decompose a vector.

<img src="https://xingqiu-tuchuang-1256524210.cos.ap-shanghai.myqcloud.com/8919/image-20230228183940097.png" alt="image-20230228183940097" style="zoom:50%;" />

-   Determine forward / backward. if $\vec{a} \cdot \vec{b} \gt 0$, $\vec{a}$ and $\vec{b}$ are almost in the same direction.

<img src="https://xingqiu-tuchuang-1256524210.cos.ap-shanghai.myqcloud.com/8919/image-20230228183959719.png" alt="image-20230228183959719" style="zoom:50%;" />

#### Cross product

<img src="https://xingqiu-tuchuang-1256524210.cos.ap-shanghai.myqcloud.com/8919/image-20230228184314851.png" alt="image-20230228184314851" style="zoom: 67%;" />

-   Cross product is orthogonal to two initial vectors.
-   Direction determined by right-hand rule

Properties:

-   $\vec{a} \times \vec{b}=-\vec{b} \times \vec{a}$
-   $\vec{a} \times \vec{a}=\vec{0}$
-   $\vec{a} \times(\vec{b}+\vec{c})=\vec{a} \times \vec{b}+\vec{a} \times \vec{c}$
-   $\vec{a} \times(k \vec{b})=k(\vec{a} \times \vec{b})$

Cartesian Formula:

$$
\vec{a} \times \vec{b}=\left[\begin{array}{l}
y_a z_b-y_b z_a \\
z_a x_b-x_a z_b \\
x_a y_b-y_a x_b
\end{array}\right]
$$

$$
\vec{a} \times \vec{b}=A^* b=
\begin{bmatrix}
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

Call $A^*$ the dual matrix of vector a.

Cross Product in Graphics:

-   Determine left / right.

<img src="https://xingqiu-tuchuang-1256524210.cos.ap-shanghai.myqcloud.com/8919/image-20230228185244895.png" style="zoom:50%;" />

如果 $\vec{a} \times \vec{b}$ 的方向与 $z$ 轴正方向相同，则说明 $\vec{b}$ 在 $\vec{a}$ 的左侧；如果相反，则说明 $\vec{b}$ 在 $\vec{a}$ 的右侧。将 $\vec{a}$ 和 $\vec{b}$ 的起点移动到重合到一起，如果 $\vec{b}$ 在 $\vec{a}$ 的左侧，则 $\vec{b}$ 的终点在 $\vec{a}$ 的左侧；如果 $\vec{b}$ 在 $\vec{a}$ 的右侧，则 $\vec{b}$ 的终点在 $\vec{a}$ 的右侧。

-   Determine inside / outside.

<img src="https://xingqiu-tuchuang-1256524210.cos.ap-shanghai.myqcloud.com/8919/image-20230228185652144.png" style="zoom:67%;" />

如果 点 $P$ 在点 $\overrightarrow{AB}$，$\overrightarrow{BC}$，$\overrightarrow{CA}$ 的同一侧，则说明点 $P$ 在 $\triangle ABC$ 的内部。即可以判断 $\overrightarrow{AB} \times \overrightarrow{AP}$，$\overrightarrow{BC} \times \overrightarrow{BP}$，$\overrightarrow{CA} \times \overrightarrow{CP}$ 的方向是否全部相同。

#### Orthonormal bases and coordinate frames

Any set of 3 vectors (in 3D) that:

$$
\begin{aligned}
& \|\vec{u}\|=\|\vec{v}\|=\|\vec{w}\|=1 \\
& \vec{u} \cdot \vec{v}=\vec{v} \cdot \vec{w}=\vec{u} \cdot \vec{w}=0 \\
& \vec{w}=\vec{u} \times \vec{v} \quad \text {(right-handed)} \\
& \vec{p}=(\vec{p} \cdot \vec{u}) \vec{u}+(\vec{p} \cdot \vec{v}) \vec{v}+(\vec{p} \cdot \vec{w}) \vec{w}
\end{aligned}
$$

$\vec{p} \cdot \vec{u}$ is the projection of $\vec{p}$ on $\vec{u}$.

## Matrices

Matrix is an array of numbers.

$$
\begin{bmatrix}
1 & 3 \\
5 & 2 \\
0 & 4
\end{bmatrix}
$$

Addition and multiplication by a scalar are trivial: element by element

### Matrix-Matrix Multiplication

Number of columns in A must = number of rows in B.

$$
A_{n\times m} B_{n \times p} = C_{n \times p}
$$

Element (i, j) in the product is the dot product of row i from A and column j from B.

$$
\left[\begin{array}{l}
1 & 3 \\
5 & 2 \\
0 & 4
\end{array}\right] \left[\begin{array}{l}
3 & 6 & 9 & 4 \\
2 & 7 & 8 & 3
\end{array}\right]=\left[\begin{array}{l}
9 & ? & 33 & 13 \\
19 & 44 & 61 & 26 \\
8 & 28 & 32 & ?
\end{array}\right]
$$

Properties:

-   $AB \neq BA$ (in general).
-   $(AB)C = A(BC)$
-   $(A + B)C = AC + BC$

### Matrix-Vector Multiplication

Treat vector as a column matrix ($m \times 1$).

for example: 2D reflection about y-axis:

$$
\begin{bmatrix}
-1 & 0 \\
0 & 1
\end{bmatrix}
\left[\begin{array}{c}
x  \\
y
\end{array}\right]=\left[\begin{array}{c}
-x \\
y
\end{array}\right]
$$

### Transpose of a Matrix

Switch rows and columns.

$$
\left[\begin{array}{c}
1 & 2 \\
3 & 4 \\
5 & 6
\end{array}\right]^{T}=\left[\begin{array}{c}
1 & 2 & 3 \\
2 & 4 & 6
\end{array}\right]
$$

Property:

-   $(AB)^{T} = B^{T} A^{T}$

### Identity Matrix and Inverses

$$
I_{3 \times 3}=\left[\begin{array}{c}
1 & 0 & 0 \\
0 & 1 & 0\\
0 & 0 & 1
\end{array}\right]=\left[\begin{array}{c}
1 & 2 & 3 \\
2 & 4 & 6
\end{array}\right] \\
AA^{-1} = A^{-1}A = I \\
(AB)^{-1} = B^{-1} A^{-1} \\
(A^T)^{-1} = (A^{-1})^T = A^{-T}
$$

### Vector multiplication in Matrix form

Dot product:

$$
\vec{a} \cdot \vec{b}= \vec{a}^{T} \vec{b}
=\left[\begin{array}{c}
x_{a} & y_{a} & z_{a}
\end{array}\right]\left[\begin{array}{c}
x_{b} \\
y_{b} \\
z_{b}
\end{array}\right] = x_{a}x_{b} + y_{a} y_{b} + z_{a}z_{b}
$$

Cross product:

$$
\vec{a} \times \vec{b} = A^{*}b =\left[\begin{array}{c}
0 & -z_a & y_a \\
z_a & 0 & -x_a \\
-y_a & x_a & 0
\end{array}\right]\left[\begin{array}{c}
x_b \\
y_b \\
z_b
\end{array}\right]
$$

# Transformation

## 2D transformations

### Scale Transform

![image-20230228193346056](https://xingqiu-tuchuang-1256524210.cos.ap-shanghai.myqcloud.com/8919/image-20230228193346056.png)

$$
\begin{aligned}
x^{\prime} & =s x \\
y^{\prime} & =s y
\end{aligned}
$$

Scale Matrix:

$$
\left[\begin{array}{l}
x^{\prime} \\
y^{\prime}
\end{array}\right]=\left[\begin{array}{ll}
s & 0 \\
0 & s
\end{array}\right]\left[\begin{array}{l}
x \\
y
\end{array}\right]
$$

Scale (Non-Uniform):

![image-20230228193521251](https://xingqiu-tuchuang-1256524210.cos.ap-shanghai.myqcloud.com/8919/image-20230228193521251.png)

$$
\left[\begin{array}{l}
x^{\prime} \\
y^{\prime}
\end{array}\right]=\left[\begin{array}{cc}
s_x & 0 \\
0 & s_y
\end{array}\right]\left[\begin{array}{l}
x \\
y
\end{array}\right]
$$

### Reflection Transform

![image-20230228193632022](https://xingqiu-tuchuang-1256524210.cos.ap-shanghai.myqcloud.com/8919/image-20230228193632022.png)

Horizontal reflection:

$$
\begin{aligned}
& x^{\prime}=-x \\
& y^{\prime}=y
\end{aligned}
$$

Reflection Matrix:

$$
\left[\begin{array}{l}
x^{\prime} \\
y^{\prime}
\end{array}\right]=\left[\begin{array}{cc}
-1 & 0 \\
0 & 1
\end{array}\right]\left[\begin{array}{l}
x \\
y
\end{array}\right]
$$

### Shear Transform

![image-20230228193840206](https://xingqiu-tuchuang-1256524210.cos.ap-shanghai.myqcloud.com/8919/image-20230228193840206.png)

-   Horizontal shift is 0 at y=0
-   Horizontal shift is a at y=1
-   Vertical shift is always 0

Shear Matrix:

$$
\left[\begin{array}{l}
x^{\prime} \\
y^{\prime}
\end{array}\right]=\left[\begin{array}{ll}
1 & a \\
0 & 1
\end{array}\right]\left[\begin{array}{l}
x \\
y
\end{array}\right]
$$

### Rotate Transform

About the origin (0, 0), CCW by default.

![image-20230228195155887](https://xingqiu-tuchuang-1256524210.cos.ap-shanghai.myqcloud.com/8919/image-20230228195155887.png)

Rotate Matrix:

$$
\mathbf{R}_\theta=\left[\begin{array}{cc}
\cos \theta & -\sin \theta \\
\sin \theta & \cos \theta
\end{array}\right]
$$

### Linear

Linear Transforms = Matrices of the same dimension.

$$
\begin{aligned}
x^{\prime} & =a x+b y \\
y^{\prime} & =c x+d y
\end{aligned}
$$

$$
\left[\begin{array}{l}
x^{\prime} \\
y^{\prime}
\end{array}\right]=\left[\begin{array}{ll}
a & b \\
c & d
\end{array}\right]\left[\begin{array}{l}
x \\
y
\end{array}\right]
$$

Scale Transform, Reflection Transform, Shear Transform and Rotate Transform are all linear transformations.

## Homogeneous Coordinates

### Translation Transform

![image-20230228203916533](https://xingqiu-tuchuang-1256524210.cos.ap-shanghai.myqcloud.com/8919/image-20230228203916533.png)

$$
\begin{aligned}
x^{\prime} & =x+t_x \\
y^{\prime} & =y+t_y
\end{aligned}
$$

Translation cannot be represented in matrix form. (So, translation is NOT linear transform!)

$$
\left[\begin{array}{l}
x^{\prime} \\
y^{\prime}
\end{array}\right]=\left[\begin{array}{ll}
a & b \\
c & d
\end{array}\right]\left[\begin{array}{l}
x \\
y
\end{array}\right]+\left[\begin{array}{l}
t_x \\
t_y
\end{array}\right]
$$

### Homogenous Coordinates

Add a third coordinate (w-coordinate):

-   2D point = $\left[\begin{array}{l}x & y & 1 \\  \end{array}\right]^{T}$
-   2D vector = $\left[\begin{array}{l}x & y & 0 \\  \end{array}\right]^{T}$

Matrix representation of translations:

$$
\left[\begin{array}{cccc}
x^{\prime} \\
y^{\prime} \\
w^{\prime}
\end{array}\right]=\left[\begin{array}{cccc}
1 & 0 & t_x \\
0 & 1 & t_y \\
0 & 0 & 1
\end{array}\right]\left[\begin{array}{cccc}
x \\
y \\
1
\end{array}\right]+\left[\begin{array}{cccc}
x+t_x \\
y+t_y \\
1
\end{array}\right]
$$

Valid operation if w-coordinate of result is 1 or 0:

-   vector + vector = vector
-   point – point = vector
-   point - vector = point
-   point + point = midpoint

In homogeneous coordinates, $\left[\begin{array}{l}x \\y \\w \end{array}\right]$ is the 2D point $\left[\begin{array}{cccc} \frac{x}{w} \\ \frac{y}{w} \\1 \end{array}\right]$, $w \neq 0$.

### Affine Transformations

Affine map = linear map + translation.

$$
\left[\begin{array}{cccc}
x^{\prime} \\
y^{\prime}
\end{array}\right]=\left[\begin{array}{cccc}
a & b \\
c & d
\end{array}\right]\left[\begin{array}{cccc}
x \\
y
\end{array}\right]+\left[\begin{array}{cccc}
t_x \\
t_y
\end{array}\right]
$$

Using homogenous coordinates:

$$
\left[\begin{array}{cccc}
x^{\prime} \\
y^{\prime} \\
1
\end{array}\right]=\left[\begin{array}{cccc}
a & b & t_x \\
c & d & t_y \\
0 & 0 & 1
\end{array}\right] \left[\begin{array}{cccc}
x \\
y \\
1
\end{array}\right]
$$

### 2D Transformations In Homogeneous Coordinates

Scale:

$$
\mathbf{S}\left(s_x, s_y\right)=\left[\begin{array}{ccc}
s_x & 0 & 0 \\
0 & s_y & 0 \\
0 & 0 & 1
\end{array}\right]
$$

Rotation:

$$
\mathbf{R}(\alpha)=\left[\begin{array}{ccc}
\cos \alpha & -\sin \alpha & 0 \\
\sin \alpha & \cos \alpha & 0 \\
0 & 0 & 1
\end{array}\right]
$$

Translation:

$$
\mathbf{T}\left(t_x, t_y\right)=\left[\begin{array}{ccc}
1 & 0 & t_x \\
0 & 1 & t_y \\
0 & 0 & 1
\end{array}\right]
$$

### Inverse Transform

$$
{M}^{-1}
$$

$M^{-1}$ is the inverse of transform $M$ in both a matrix and geometric sense.

<img src="https://xingqiu-tuchuang-1256524210.cos.ap-shanghai.myqcloud.com/8919/image-20230228210007049.png" alt="image-20230228210007049" style="zoom:50%;" />

### Composing Transforms

Transform Ordering Matters:

![image-20230228210810706](https://xingqiu-tuchuang-1256524210.cos.ap-shanghai.myqcloud.com/8919/image-20230228210810706.png)

Matrix multiplication is not commutative.

$$
R_{45} \cdot T_{(1,0)} \neq T_{(1,0)} \cdot R_{45}
$$

Note that matrices are applied right to left:

$$
T_{(1,0)} \cdot R_{45}\left[\begin{array}{l}
x \\
y \\
1
\end{array}\right]=\left[\begin{array}{lll}
1 & 0 & 1 \\
0 & 1 & 0 \\
0 & 0 & 1
\end{array}\right]\left[\begin{array}{ccc}
\cos 45^{\circ} & -\sin 45^{\circ} & 0 \\
\sin 45^{\circ} & \cos 45^{\circ} & 0 \\
0 & 0 & 1
\end{array}\right]\left[\begin{array}{l}
x \\
y \\
1
\end{array}\right]
$$

#### Composing Transforms

Sequence of affine transforms: $A_{1}, A_{2}, A_{3}, \dots$

$$
A_n\left(\ldots A_2\left(A_1(\mathbf{x})\right)\right)=\mathbf{A}_n \cdots \mathbf{A}_2 \cdot \mathbf{A}_1 \cdot\left[\begin{array}{l}
x \\
y \\
1
\end{array}\right]
$$

Pre-multiply n matrices to obtain a single matrix representing combined transform.

### Decomposing Complex Transforms

How to rotate around a given point c?

1. Translate center to origin.
2. Rotate.
3. Translate back.

![image-20230228211506439](https://xingqiu-tuchuang-1256524210.cos.ap-shanghai.myqcloud.com/8919/image-20230228211506439.png)

$$
T(c) \cdot R(\alpha) \cdot T(-c)
$$

## 3D Transformations

Use homogeneous coordinates:

-   3D point = $\left[\begin{array}{l}x & y & z & 1 \\  \end{array}\right]^{T}$
-   3D vector = $\left[\begin{array}{l}x & y & z &  0 \\  \end{array}\right]^{T}$

In general, $\left[\begin{array}{l}x & y & z & 1 \\  \end{array}\right]^{T}(w \neq 0)$ is the 3D point: $\left[\begin{array}{l} \frac{x}{w} & \frac{y}{w} & \frac{z}{w} & 1 \end{array}\right]^{T}$

Use 4×4 matrices for affine transformations:

$$
\left[\begin{array}{l}
x^{\prime} \\
y^{\prime} \\
z^{\prime} \\
1
\end{array}\right]=\left[\begin{array}{lllc}
a & b & c & t_x \\
d & e & f & t_y \\
g & h & i & t_z \\
0 & 0 & 0 & 1
\end{array}\right]  \left[\begin{array}{l}
x \\
y \\
z \\
1
\end{array}\right]
$$

### Scale

$$
\mathbf{S}\left(s_x, s_y, s_z\right)=\left[\begin{array}{cccc}
s_x & 0 & 0 & 0 \\
0 & s_y & 0 & 0 \\
0 & 0 & s_z & 0 \\
0 & 0 & 0 & 1
\end{array}\right]
$$

### Translation

$$
\mathbf{T}\left(t_x, t_y, t_z\right)=\left[\begin{array}{cccc}
1 & 0 & 0 & t_x \\
0 & 1 & 0 & t_y \\
0 & 0 & 1 & t_z \\
0 & 0 & 0 & 1
\end{array}\right]
$$

### Rotation

Rotation around x-axis, y-axis, or z-axis.

<img src="https://xingqiu-tuchuang-1256524210.cos.ap-shanghai.myqcloud.com/8919/image-20230228212533203.png" alt="image-20230228212533203" style="zoom: 50%;" />

$$
\begin{aligned}
& \mathbf{R}_x(\alpha)=\left[\begin{array}{cccc}
1 & 0 & 0 & 0 \\
0 & \cos \alpha & -\sin \alpha & 0 \\
0 & \sin \alpha & \cos \alpha & 0 \\
0 & 0 & 0 & 1
\end{array}\right] \\
& \mathbf{R}_y(\alpha)=\left[\begin{array}{cccc}
\cos \alpha & 0 & \sin \alpha & 0 \\
0 & 1 & 0 & 0 \\
-\sin \alpha & 0 & \cos \alpha & 0 \\
0 & 0 & 0 & 1
\end{array}\right] \\
& \mathbf{R}_z(\alpha)=\left[\begin{array}{cccc}
\cos \alpha & -\sin \alpha & 0 & 0 \\
\sin \alpha & \cos \alpha & 0 & 0 \\
0 & 0 & 1 & 0 \\
0 & 0 & 0 & 1
\end{array}\right]
\end{aligned}
$$

#### Compose any 3D rotation from $R_x,R_y, R_z$

$$
R_{x y z}(\alpha, \beta, \gamma)=R_x(\alpha) R_y(\beta) R_z(\gamma)
$$

Call $\alpha, \beta, \gamma$ Euler angles.

#### Rodrigues’ Rotation Formula

Rotation by angle $\alpha$ around axis $n$.

$$
R(\mathbf{n}, \alpha)=\cos (\alpha) \mathbf{I}+ (1-\cos \alpha)\mathbf{n} \mathbf{n}^T+\sin \alpha \cdot\left[\begin{array}{ccc}
0 & -n_z & n_y \\
n_z & 0 & -n_x \\
-n_y & n_x & 0
\end{array}\right]
$$

## Viewing transformation

### View / Camera Transformation

-   model transformation
-   view transformation
-   projection transformation

**Define the camera**

<img src="https://xingqiu-tuchuang-1256524210.cos.ap-shanghai.myqcloud.com/8919/image-20230228222857436.png" alt="image-20230228222857436" style="zoom: 67%;" />

-   Position: $\vec{e}$.
-   Look-at / gaze direction: $\hat{g}$.
-   Up direction: $\hat{t}$.

**Key observation**:

If the camera and all objects move together, the "photo" will be the same.

<img src="https://xingqiu-tuchuang-1256524210.cos.ap-shanghai.myqcloud.com/8919/image-20230228223134416.png" alt="image-20230228223134416" style="zoom: 67%;" />

We always transform the camera to:

-   The origin, up at Y, look at -Z.
-   And transform the objects along with the camera.

<img src="https://xingqiu-tuchuang-1256524210.cos.ap-shanghai.myqcloud.com/8919/image-20230228223222670.png" alt="image-20230228223222670" style="zoom:67%;" />

Transform the camera by $M_{view}$.

$M_{view}$ in math:

-   Translates e to origin.
-   Rotates g to -Z.
-   Rotates t to Y.
-   Rotates (g x t) To X.

<img src="https://xingqiu-tuchuang-1256524210.cos.ap-shanghai.myqcloud.com/8919/image-20230228223635703.png" alt="image-20230228223635703" style="zoom:50%;" />

Let’s write $M_{view} = R_{view}T_{view}$.

Translate e to origin:

$$
T_{\text {view }}=\left[\begin{array}{cccc}
1 & 0 & 0 & -x_e \\
0 & 1 & 0 & -y_e \\
0 & 0 & 1 & -z_e \\
0 & 0 & 0 & 1
\end{array}\right]
$$

Rotate g to -Z, t to Y, (g x t) To. Consider its inverse rotation: X to (g x t), Y to t, Z to -g.

$$
R_{\text {view }}^{-1}=\left[\begin{array}{cccc}
x_{\hat{g} \times \hat{t}} & x_t & x_{-g} & 0 \\
y_{\hat{g} \times \hat{t}} & y_t & y_{-g} & 0 \\
z_{\hat{g} \times \hat{t}} & z_t & z_{-g} & 0 \\
0 & 0 & 0 & 1
\end{array}\right] \Leftrightarrow R_{\text {view }}=\left[\begin{array}{cccc}
x_{\hat{g} \times \hat{t}} & y_{\hat{g} \times \hat{t}} & z_{\hat{g} \times \hat{t}} & 0 \\
x_t & y_t & z_t & 0 \\
x_{-g} & y_{-g} & z_{-g} & 0 \\
0 & 0 & 0 & 1
\end{array}\right]
$$

> Modelview transformation is prepared for projection transformation.

### Projection Transformation

Projection in Computer Graphics:

-   3D to 2D.
-   Orthographic projection.
-   Perspective projection.

![image-20230301084855250](https://xingqiu-tuchuang-1256524210.cos.ap-shanghai.myqcloud.com/8919/image-20230301084855250.png)

Perspective projection vs.orthographic projection:

<a href="https://stackoverflow.com/questions/36573283/from-perspective-picture-to-orthographic-picture"><img src="https://xingqiu-tuchuang-1256524210.cos.ap-shanghai.myqcloud.com/8919/q1SNB.png" alt="q1SNB" /></a>

#### Orthographic Projection

A simple way of understanding:

-   Camera located at origin, looking at -Z, up at Y.
-   Drop Z coordinate.
-   Translate and scale the resulting rectangle to $[-1,1]^2$.

![image-20230301085701599](https://xingqiu-tuchuang-1256524210.cos.ap-shanghai.myqcloud.com/8919/image-20230301085701599.png)

In general:

-   We want to map a cuboid [l, r] x [b, t] x [f, n] to the canonical (正则、规范、标准) cube $[-1, 1]^{3}$.

![image-20230301085806312](https://xingqiu-tuchuang-1256524210.cos.ap-shanghai.myqcloud.com/8919/image-20230301085806312.png)

Translate (center to origin) first, then scale (length / width / height to 2).

Transformation matrix:

$$
M_{\text {ortho }}=\left[\begin{array}{cccc}
\frac{2}{r-l} & 0 & 0 & 0 \\
0 & \frac{2}{t-b} & 0 & 0 \\
0 & 0 & \frac{2}{n-f} & 0 \\
0 & 0 & 0 & 1
\end{array}\right]\left[\begin{array}{cccc}
1 & 0 & 0 & -\frac{r+l}{2} \\
0 & 1 & 0 & -\frac{t+b}{2} \\
0 & 0 & 1 & -\frac{n+f}{2} \\
0 & 0 & 0 & 1
\end{array}\right]
$$

Caveat:

-   Looking at / along -Z is making near and far not intu itive (n > f).
-   FYI: that’s why OpenGL (a Graphics API) uses left hand coords.

#### Perspective Projection

-   Most common in Computer Graphics, art, visual system.
-   Further objects are smaller.
-   Parallel lines not parallel; converge to single point.

<img src="https://xingqiu-tuchuang-1256524210.cos.ap-shanghai.myqcloud.com/8919/image-20230301090140176.png" alt="image-20230301090140176" style="zoom:67%;" />

How to do perspective projection:

-   First "squish" the frustum into a cuboid ($n \rightarrow n, f \rightarrow f$). ($(M_{persp} \rightarrow M_{ortho}$).

-   Do orthographic projection ($M_{ortho}$).

![image-20230301090712104](https://xingqiu-tuchuang-1256524210.cos.ap-shanghai.myqcloud.com/8919/image-20230301090712104.png)

Find the relationship between transformed points $(x^{\prime}, y^{\prime}, z^{\prime})$ and the original points $(x,y,z)$.

![image-20230301090756316](https://xingqiu-tuchuang-1256524210.cos.ap-shanghai.myqcloud.com/8919/image-20230301090756316.png)

$$
y^{\prime}=\frac{n}{z} y \quad x^{\prime}=\frac{n}{z} x
$$

In homogeneous coordinates:

$$
\left[\begin{array}{c}
x \\
y \\
z \\
1
\end{array}\right] \Rightarrow\left[\begin{array}{c}
n x / z \\
n y / z \\
\text { unknown } \\
1
\end{array}\right] \stackrel{\times z}{=}\left[\begin{array}{c}
n x \\
n y \\
\text { unknown } \\
z
\end{array}\right]
$$

So the "squish" (persp to ortho) projection does this:

$$
M_{\text {persp } \rightarrow \text { ortho }}^{(4 \times 4)}\left[\begin{array}{l}
x \\
y \\
z \\
1
\end{array}\right]=\left[\begin{array}{c}
n x \\
n y \\
\text { unknown } \\
z
\end{array}\right]
$$

Already good enough to figure out part of $M_{persp->ortho}$.

Observation: the third row is responsible for $z^{\prime}$.

-   Any point on the near plane will not change.

-   Any point’s z on the far plane will not change.

$$
M_{\text {persp } \rightarrow \text { ortho }}^{(4 \times 4)}\left[\begin{array}{l}
x \\
y \\
z \\
1
\end{array}\right]=\left[\begin{array}{c}
n x \\
n y \\
\text { unknown } \\
z
\end{array}\right] \stackrel{\text { replace with } \mathrm{n}}{\Longrightarrow}\left[\begin{array}{l}
x \\
y \\
n \\
1
\end{array}\right] \Rightarrow\left[\begin{array}{l}
x \\
y \\
n \\
1
\end{array}\right]=\left[\begin{array}{l}
n x \\
n y \\
n^2 \\
n
\end{array}\right]
$$

So the third row must be of the form $\left[\begin{array}{llll}0 & 0 & A & B \end{array}\right]$:

$$
\left[\begin{array}{llll}
0 & 0 & A & B
\end{array}\right]\left[\begin{array}{l}
x \\
y \\
n \\
1
\end{array}\right]=n^2 \Longrightarrow  A n+B=n^2
$$

Any point’s z on the far plane will not change:

$$
\left[\begin{array}{l}
0 \\
0 \\
f \\
1
\end{array}\right] \Rightarrow\left[\begin{array}{l}
0 \\
0 \\
f \\
1
\end{array}\right]==\left[\begin{array}{c}
0 \\
0 \\
f^2 \\
f
\end{array}\right] \Longrightarrow A f+B=f^2
$$

Solve for A and B:

$$
\begin{aligned}
& A n+B=n^2 \\
& A f+B=f^2
\end{aligned} \Longrightarrow \begin{aligned}
& A=n+f \\
& B=-n f
\end{aligned}
$$

Finally, every entry in $M_{persp \rightarrow ortho}$ is known:

$$
\left[\begin{array}{cccc}
n & 0 & 0 & 0 \\
0 & n & 0 & 0 \\
0 & 0 & n + f & -nf \\
0 & 0 & 1 & 0
\end{array}\right]
$$

What’s next?

-   Do orthographic projection ($M_{ortho}$) to finish.

-   $M_{persp} = M_{ortho}M_{persp \rightarrow ortho}$
