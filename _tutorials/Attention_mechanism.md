

# The basic transformer



## Query, Key & Value

为了表示一个序列中各个部分(token)间相互的语义关系，Attention机制被引入进来，可以想见，在一个序列$X=(E_0, E_1, \ldots, E_n)$中，每个元素间都有一定的relationship。在总体语义中，如果$E_i$和$E_j$是“同义词”的话，那么二者之间的某种“关联度”$s_{ij}$应当是比较高的。

在这里，Attention机制使用了"Query-key"的方式，来计算各个部分间的关联关系。

### Query 

Query向量是针对特定向量的一个查询向量，其可写为：
$$
Q_i=W_QE_i
$$
这里$W_Q$是一个形如$d_k\times d_{model}$的矩阵，$d_{model}$是Word-embedding后的维度(也称为整体隐藏层维度)，其参数是可训练的。通过与$W_Q$的乘法，$E_i$由一个高维向量($d_{model}$)转化为了一个相对低维的向量($d_k$)。我们可k以形象地理解"$Q_i$"某种程度上是$E_i$的一种"代表"，像是在发问："和我($E_i$)'相似'的单元在哪里'"。

将各个Query向量拼接在一起，那么总的矩阵$Q$即为：
$$
Q=\begin{bmatrix}Q_0&Q_1&\ldots&Q_n\end{bmatrix}=W_QX,\quad Q\in \mathbb R^{d_k\times n}
$$

### Key

Key向量是针对特定向量的一种指示，可以"回应"Query向量的"发问"。比如说，输入的序列有十个token长($E_0, E_1, \ldots, E_9$)，经过$W_Q$变换后，形成了十个"问题"——十个Query向量$Q_0, Q_1, \ldots, Q_9$。"从$E_0$的角度"来说，可以通过一定变换，形成一个Key向量$K_0$，然后分别与它们进行点积，以"回答"$E_0$和$E_0, E_1, ...$是否"相似"的问题：
$$
K_i=W_KE_i
$$
这里$W_K$是一个形如$d_k\times d_{model}$的矩阵($W_K$和$W_Q$有相同的尺寸，以便后续(Query, Key)之间能够顺利执行点积运算)。同样地，总体的$K$矩阵应当为：
$$
K=W_QX,\quad K\in \mathbb R^{d_k\times n}
$$


### Attention pattern (table) & Value

针对各个向量的(Query, Key)向量制作好后，就可以计算它们之间的关联程度了。使用点积运算，一个Query向量$Q_i$和Key向量$K_i$之间的"关联度"即为：
$$
s(i,j)=E_i^TW_K^T W_QE_j
$$

> 需要注意，$Q_i$和$K_j$的点积与$Q_j$和$K_i$的点积不一定是相等的，因此我们不能想当然地把Attention矩阵想成是一个对称阵。此外需要注意二者之间实际"含义"的不同，可以说，$Q_i$和$K_j$进行点积，是$E_j$在"回应"$E_i$的"发问"，对于后续的

由此可以形成一个完整的Attention矩阵，即：
$$
\text{Attention}\quad \text{pattern}=K^TQ=X^T(W_K^T W_Q)X
$$
需要注意的是，这些"关联度"还没有经过充分比较(比如说，$K_1^TQ_1=5000$，说明$E_1$对于它自身非常相关，但其实不一定，假设同时还有$K_2^TQ_1=10000$，这就表明$E_2$较$E_1$对$E_1$更"相关"些)，所以，这里需要经过一次$softmax$操作，具体对$K^TQ$**按列**进行操作。原论文中使用了一种相当简洁的记法表示归一化后的Attention table，即：
$$
softmax(Q^TK)
$$
上述公式中的记法是**按行进行**的，或者说，我们记一个$n\times m$的矩阵$K$及其$softmax$操作后的矩阵为$K_s$，那么应当有：
$$
K_s(i,j)=\frac {\exp(K(i,j))}{\sum_j \exp(K(i,j))}
$$
此外，我们还应当注意掩码(Mask)的存在，掩码的存在，是为了让特定的Key对于特定的Query“不可见”，按照常理理解，就是让某个$s(i,j)$等于$0$——不过事实上是让它等于$-\infty$，这样其对应的$\exp(-\infty)$为0。

最后让我们查看一下Value向量，类似地：
$$
V_i = W_VE_i
$$
其中$W_V$是一个形如$d_V \times d_{model}$的矩阵，其中参数均是可训练的。最后，这些Value向量应当与Attention pattern表作加权和。同样可以将各个Value向量拼接在一起形成$V=W_V X$

整体回顾一下，从某个"$E_i$"的"角度"来说，首先通过$W_Q$生成了一个Query向量$Q_i$，然后每个向量$E_l(l=0,1,\ldots,n)$的Key向量$K_l(l=0,1,\ldots,n)$分别"回答"$Q_i$的问题。通过$softmax$操作，每个$E_l$与$E_i$的"关联度"$s(l, i)$都被计算出来。其随后作为权值与各个Value向量$V_l$求和，最终生成一个整体的"修正"向量$M_i$作用于$E_i$。用公式来表示即
$$
\begin{align*}
M_i&=
\begin{bmatrix}V_0&V_1&\ldots&V_n\end{bmatrix}
\begin{bmatrix}s_{0i}\\s_{1i}\\\vdots\\s_{ni}\end{bmatrix}
\\
&=V softmax \left( \begin{bmatrix}K_0^TQ_i \\ K_1^TQ_i \\\vdots\\K_n^TQ_i\end{bmatrix} \right)
\\
&=V softmax \left( K^TQ_i \right)
\end{align*}
$$

### Real cases: Column vector or Row vector ?

需要注意的是，在主流的神经网络框架上，Embedding序列$X$通常尺寸为`(batch_size, sequence_len, embedding_dim)`，考虑按`batch`切分的一个矩阵，不难发现它形为$n \times d_{model}$而非前述的$d_{model}\times n$，也就是说$E_i$是一个行向量而非列向量，这样做更有利于实际实现下的内存连续性，有着更好的并行读写能力。

按照行向量的写法，我们再将上述的Query，Key和Value矩阵重写一下，即：
$$
Q=XW_Q,\quad W_Q\in \mathbb R^{d_{model} \times d_k},Q\in \mathbb R^{n \times d_k}\\
K=XW_K,\quad W_Q\in \mathbb R^{d_{model} \times d_k},K\in \mathbb R^{n \times d_k}\\
V=XW_V, \quad W_Q\in \mathbb R^{d_{model} \times d_v},K\in \mathbb R^{n \times d_v}
$$
 这样Attention pattern表就可以表为
$$

$$






这个矩阵转置后其中的核心部分就是$W_Q^T W_K$，也就是论文原文中的$Q^TK$。

