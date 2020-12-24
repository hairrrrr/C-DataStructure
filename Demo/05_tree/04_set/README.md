课本上阐述了集合的 `find` 和 `merge` 操作和优化，但是没有将集合的操作进行系统的演示。所以带来的问题就是程序写出来跑不了，find 和 merge 甚至集合的数据类型设定都有严重的不协调性。

首先，集合的抽象数据类型，书上是这样定义的：

```c
#define MAX_TREE_SIZE 100

typedef struct PTNode
{
	TElemType data;
	int parent; // 该结点的父节点
}PTNode;

typedef struct
{
	PTNode nodes[MAX_TREE_SIZE];
	int root, size; // 集合的根和大小
}PTree;
```

试问，书上的例子（P141，有两个集合）应该如何用这种数据类型表示？

我认为至少 `nodes` 数组应该是所有集合公用的。

其次是 `find` 和 `merge` 的优化：

`merge` 的优化把根节点的 `parent` 域置为了当前集合的元素个数，方便两个集合进行大小比较从而按秩归并。但是，`merge` 后的 `find` 操作应该如何表示根？书上写的是:

```c
S.nodes[k].parent > 0
```

仅仅大于 0 就能表示根？

目前我的程序还没有完善，仅仅提出这两个问题供诸君思考。



#### 示例

![](https://www.hairrrrr.github.io/assets/2020-12-24-3.png)























