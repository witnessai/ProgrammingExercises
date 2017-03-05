#引入二叉树的建立
//创建二叉树
typedef struct node{
	int data;
	struct node *lchild, *rchild;
}bitree;
bitree * root;
bitree* CreateTree()
{
	char ch;
	bitree *Q[MAXSIZE];
	int front, rear;
	bitree *root, *s;
	root = NULL;
	front = 1, rear = 0;
	while((ch=getchar()) != '#')
	{
		s = NULL;
		if(ch != '@')
		{
			s = (bitree *)malloc(size(bitree));
			s->data = ch;
			s->lchild = NULL:
			s->rchild = NULL;
		}
		rear++;
		Q[rear] = s;
		if(rear == 1)
			root = s;
		else
		{
			if(s&&Q[front])
			{
				if(rear%2 == 0)
					Q[front]->lchild = s;
				else
					Q[front]->rchild = s;
			}
			if(rear%2 == 1)
				front++;
		}
	}
	return root;
}


#二叉树的遍历
##DFS 深度优先遍历 
这里先介绍递归算法，比较简单容易理解
二叉树的遍历按根的遍历顺序不同可以分为，先序遍历（根左右），中序遍历（左根右），后序遍历（左右根）


###DFS 递归版本
1.先序遍历
void PreOrder(bitree *p)
{
	if(p != NULL)
	{
		printf("%c", p->data);
		PreOrder(p->lchild);
		PreOrder(p->rchild);
	}
}

2.中序遍历
void InOrder(bitree *p)
{
	if(p != NULL)
	{
		InOrder(p->lchild);
		printf("%c", p->data);
		InOrder(p->rchild);
	}
}

3.后序遍历
void PostOrder(bitree *p)
{
	if(p != NULL)
	{
		PostOrder(p->lchild);
		PostOrder(p->rchild);
		printf("%c", p->data);
	}
}

###DFS非递归版本——代码为中序遍历




##BFS 广度优先遍历
void BFS(bitree * p)
{
	bitree *Q[MAXSIZE];
	bitree *s;
	int rear = 1, front = 0;
	Q[rear] = p;
	while(front < rear)
	{
		fornt++;
		s = Q[front];
		printf("%c", s->data);
		
		if(s->lchild != NULL)
		{
			//rear++;
			Q[rear++] = s->lchild;
		}
		if(s->rchild != NULL)
		{
			//rear++;
			Q[rear++] = s->rchild;
		}
	}
}





#hash表
