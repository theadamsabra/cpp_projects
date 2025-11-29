# Tensor Formalization and Indexing

## I. Tensor Definition and Rank

A **Tensor** $\mathbf{A}$ is a multidimensional array holding elements of a certain type, $T$.

* **Rank (or Order), $N$:** The number of dimensions.
* **Shape, $\mathbf{D}$:** A vector of dimension sizes.
    $$\mathbf{D} = (d_0, d_1, \dots, d_{N-1})$$
    where $d_i$ is the extent (size) of the $i$-th dimension.
* **Total Number of Elements, $L$:** The product of all dimensions.
    $$L = \prod_{i=0}^{N-1} d_i = d_0 \times d_1 \times \dots \times d_{N-1}$$
* **Storage:** Data is stored in a single, **contiguous 1D array** of length $L$.

---

## II. Strides Calculation (Row-Major Order)

The **Stride Vector**, $\mathbf{S}$, defines the memory jump needed to move one step along each dimension. This uses **Row-Major Order** (C-style), where the last dimension ($d_{N-1}$) is fastest changing.

### Formal Definition:

The stride $s_i$ for dimension $d_i$ is calculated as:

$$
s_i = \begin{cases}
1 & \text{if } i = N-1 \quad (\text{Last dimension}) \\
\prod_{j=i+1}^{N-1} d_j & \text{if } 0 \le i < N-1
\end{cases}
$$

### Example (Shape $\mathbf{D} = (2, 3, 4)$):

The stride vector is $\mathbf{S} = (12, 4, 1)$.

| Dimension $i$ | $d_i$ | Calculation | Stride $s_i$ |
| :---: | :---: | :---: | :---: |
| 2 | 4 | $s_2 = 1$ | 1 |
| 1 | 3 | $s_1 = d_2 = 4$ | 4 |
| 0 | 2 | $s_0 = d_1 \times d_2 = 3 \times 4$ | 12 |

---

## III. Indexing Formula

Given the coordinate vector $\mathbf{I} = (i_0, i_1, \dots, i_{N-1})$, the **Flat Array Index** $k$ is calculated as the **dot product** of the coordinate vector $\mathbf{I}$ and the stride vector $\mathbf{S}$.

### Formal Definition:

$$
k = \text{Flat Index} = \sum_{j=0}^{N-1} (i_j \cdot s_j)
$$

### Example (Coordinates $\mathbf{I} = (1, 0, 2)$):

Using Strides $\mathbf{S}=(12, 4, 1)$:

$$
k = (1 \cdot 12) + (0 \cdot 4) + (2 \cdot 1) = 14
$$