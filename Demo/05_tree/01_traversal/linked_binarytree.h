#pragma once
#include<myhead/ds.h>

typedef int TElemType;

typedef struct BiTNode
{
	TElemType data;
	struct BiTNode* lchild, * rchild;// 左右孩子指针
}BiTNode, *BiTree;

Status CreateBiTree(BiTree* T);
Status DestoryBiTree(BiTree T);
// 二叉树的 前，中，后，层序遍历
Status PreOrderTraverse(BiTree T);
Status InOrderTraverse(BiTree T);
Status PostOrderTraverse(BiTree T);
// 下面是非递归版本
Status PreOrderTraverseNoR(BiTree T);
Status InOrderTraverseNoR(BiTree T);
Status PostOrderTraverseNoR(BiTree T);
Status LevelOrderTraverseNoR(BiTree T);

