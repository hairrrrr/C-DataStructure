#pragma once
#include<myhead/ds.h>

typedef int TElemType;

typedef struct BiTNode
{
	TElemType data;
	struct BiTNode* lchild, * rchild;// ���Һ���ָ��
}BiTNode, *BiTree;

Status CreateBiTree(BiTree* T);
Status DestoryBiTree(BiTree T);
// �������� ǰ���У��󣬲������
Status PreOrderTraverse(BiTree T);
Status InOrderTraverse(BiTree T);
Status PostOrderTraverse(BiTree T);
// �����Ƿǵݹ�汾
Status PreOrderTraverseNoR(BiTree T);
Status InOrderTraverseNoR(BiTree T);
Status PostOrderTraverseNoR(BiTree T);
Status LevelOrderTraverseNoR(BiTree T);

