#pragma once
#ifndef BITREE_H

#define BITREE_H

#include<iostream>
#include<fstream>


#define elementType char
#define TREE_PATH "../trees/"

using namespace std;

#endif // !BITREE_H

//*********************二叉树结构定义***********************//
#define MAXLEN 100											//
															//
typedef struct lBNode										//
{															//
	elementType data;										//
	struct lBNode *lChild, *rChild;							//
}BiNode, *BiTree;											//
//**********************************************************//

//************************链队列结构************************//
//链队列结点结构											//
typedef struct LNode										//
{															//
	elementType data[4];									//
	struct LNode* next;										//
}node;														//
															//
//链队列结构												//
typedef struct LNodes										//
{															//
	node* front;					//队头指针				//
	node* rear;						//队尾指针				//
}linkQueue;													//
//**********************************************************//

//********************************************函数声明**************************************************//
//链队列函数声明																						//
void enQueue(linkQueue& Q, elementType data[]);						//链队列入队						//
bool outQueue(linkQueue& Q);										//链队列出队						//
//二叉树函数声明																						//
void createSubTree(BiTree q, int k);								//二叉树子树控制台创建				//
bool createBiTree(BiTree& BT);										//二叉树控制台创建					//
bool BiTreeFlie(string fileName, linkQueue& Q);						//判断并获取二叉树文件				//
void createBiTree(BiTree& BT, string fileName);						//二叉树文件创建					//
void createSubTree(BiTree& BT, linkQueue& Q);						//二叉树队列创建					//
void preTraverse(BiTree T);											//二叉树先序遍历					//
void inOrderTraverse(BiTree T);										//二叉树中序遍历					//
void postTraverse(BiTree T);										//二叉树后序遍历					//
void inOrderFloor(BiTree T);										//中序输出二叉树及层次数			//
void inOrderFloor(BiTree T, int floor);								//中序输出二叉树及层次数			//
int getTreeHeight(BiTree T);										//求二叉树高度						//
int getTreeNodes(BiTree T);											//求二叉树结点个数					//
void getTreeLeaves(BiTree T, int& num);								//求二叉树叶子结点个数				//
int getTreeLeaves(BiTree T);										//求二叉树叶子结点个数				//
void getTreeTwoDegree(BiTree T, int& num);							//求二叉树2度结点个数				//
int getTreeTwoDegree(BiTree T);										//求二叉树2度结点个数				//
void printFBNodes(BiTree T, elementType x, bool& flag);				//求二叉树结点关系					//
bool printFBNodes(BiTree T, elementType x);							//求二叉树结点关系					//
void getNodeFloor(BiTree T, elementType x, int floor, int& res);	//求二叉树结点层次					//
int getNodeFloor(BiTree T, elementType x);							//求二叉树结点层次					//
void tranSeqToLink(BiTree& T, elementType sBiTree[], int i, int len);//求二叉树结点层次					//
bool tranSeqToLink(BiTree& T, elementType sBiTree[]);				//求二叉树结点层次					//
//******************************************************************************************************//


//******************************函数定义********************************

//***************************二叉树函数定义*****************************
//****************辅助函数：二叉树子树控制台创建****************
//输入：当前子树根节点，插入子树位置
//返回：成功返回true，失败返回false
void createSubTree(BiTree q, int k)						//q为当前子树的根节点
{														//k=-1时表示左子树；k=1时表示右子树
	elementType x;
	BiNode* u = nullptr;

	cin >> x;
	if (x != '/')
	{
		u = new BiNode;
		u->data = x;
		u->lChild = nullptr;
		u->rChild = nullptr;
		if (k == -1)
		{
			q->lChild = u;
		}
		if (k == 1)
		{
			q->rChild = u;
		}
		createSubTree(u, -1);
		createSubTree(u, 1);
	}
}


//****************辅助函数：二叉树控制台创建****************
//输入：二叉树根节点
//返回：成功返回true，失败返回false
bool createBiTree(BiTree& BT)
{
	elementType x;

	if (BT == nullptr)
	{
		cout << "输入二叉树先序序列：" << endl;
		cin >> x;
		if (x == '/')
		{
			return true;
		}
		else
		{
			BT = new BiNode;
			BT->data = x;
			BT->lChild = nullptr;
			BT->rChild = nullptr;

			createSubTree(BT, -1);
			createSubTree(BT, 1);

			return true;
		}
	}
	else return false;
}


//****************辅助函数：链队列入队****************
//辅助函数：链队列入队
//输入：需要进行入队的队列指针 
void enQueue(linkQueue& Q, elementType data[])
{
		Q.rear->next = new node;
		Q.rear = Q.rear->next;
		Q.rear->data[0] = data[0];
		Q.rear->data[1] = data[2];
		Q.rear->data[2] = data[4];
		Q.rear->data[3] = '\0';
		Q.rear->next = nullptr;
}


//****************辅助函数：链队列出队****************
//辅助函数：链队列出队
//输入：需要进行出队的队列指针
bool outQueue(linkQueue& Q)
{
	node* dp = nullptr;

	if (Q.front != Q.rear)
	{
		dp = Q.front->next;
		Q.front->next = dp->next;
		delete(dp);
		if (Q.front->next == nullptr)
		{
			Q.rear = Q.front;
		}

		return true;
	}
	else return false;
}


//****************辅助函数：判断文件是否是二叉树文件****************
//输入：二叉树根节点，文件名
//返回：成功返回true，失败返回false
bool BiTreeFlie(string fileName, linkQueue& Q)
{
	char buffer[11] = {'\0'};
	ifstream infile(fileName);

	if (infile.is_open())
	{
		do
		{
			infile.get(buffer[0]);
			//cout << buffer[0];
			if (buffer[0] == '/')
			{
				infile.get(buffer[0]);
				//cout << buffer[0];
				if (buffer[0] == '/')				//判断改行文件为注释
				{
					while (buffer[0] != '\n')		//控制文件流指针移动到行末
					{
						infile.get(buffer[0]);
						//cout << buffer[0];
					}
				}
			}
			else if (buffer[0] == ' ')				//该行文件开始为空格
			{
				while (buffer[0] != '/')			//向后读取文件，直到出现第一个非空格为止
				{
					infile.get(buffer[0]);
					//cout << buffer[0];
				}
				infile.get(buffer[0]);
				//cout << buffer[0];
				if (buffer[0] == '/')				//判断改行文件为注释
				{
					while (buffer[0] != '\n')		//控制文件流指针移动到行末
					{
						infile.get(buffer[0]);
						//cout << buffer[0];
					}
				}
			}
		} while (buffer[0]=='\n');					//当文件流指针指向换行符时，说明该行为注释，继续循环进入下一行
													//当文件流指针不指向换行符时，要判断改行是否是二叉树文件标识行
		infile.getline(&buffer[1], 10);				//第一个字符在之前的循环已读入字符串，因此将该行剩余字符从字符串第二个位置开始存入
		if ((string)buffer == "BinaryTree")			//判断是否是标识行，要将char类型数组转换成字符串
		{
			infile.getline(buffer, 6);				//重新读入文件
			Q.front = new node;
			Q.rear = Q.front;
			Q.front->next = nullptr;
			while (!infile.eof())					//如果文件没有结束，要将正文读入队列
			{
				if ((string)buffer != "\0")			//如果该行是空行，需跳过
				{
					enQueue(Q, buffer);				//不是空行读入队列
				}
				infile.getline(buffer, 6);
			}

			infile.close();							//关闭文件流

			return true;
		}
		else
		{
			cout << "当前文件不是二叉树文件！" << endl;

			infile.close();							//关闭文件流

			return false;
		}
	}
	else
	{
		cout << "文件打开失败！" << endl;

		infile.close();								//关闭文件流

		return false;
	}
}


//****************辅助函数：二叉树队列创建****************
//输入：二叉树根节点，队列指针
void createSubTree(BiTree& BT, linkQueue& Q)
{
	//记录当前结点的子树情况，因为结点队列会进行全局修改
	const elementType lChild = Q.front->next->data[1], rChild = Q.front->next->data[2];

	if (Q.front != Q.rear)						//当队列不为空时，进行子树插入
	{

		BT = new BiNode;						//为当前子树插入结点
		BT->data = Q.front->next->data[0];
		BT->lChild = nullptr;
		BT->rChild = nullptr;
		if (lChild == '1')
		{
			outQueue(Q);						//对列出队
			createSubTree(BT->lChild, Q);		//递归创建子树
		}
		if (rChild == '1')
		{
			outQueue(Q);						//队列出队
			createSubTree(BT->rChild, Q);		//递归创建子树
		}
	}
}


//****************辅助函数：二叉树文件创建****************
//输入：二叉树根节点，文件名
void createBiTree(BiTree& BT, string fileName)
{
	linkQueue Q;

	if (BiTreeFlie(TREE_PATH + fileName, Q))	//文件读取成功的同时会创建队列
	{
		createSubTree(BT, Q);					//开始递归创建子树
	}
}


//****************二叉树先序遍历****************
//实验六.二叉树.1，二叉树先序遍历
//输入：二叉树指针 
//打印：函数内打印二叉树结点
//返回：二叉树未创建返回false，否则返回true
void preTraverse(BiTree T)
{
	if (T)
	{
		cout << T->data << '\t';
		preTraverse(T->lChild);
		preTraverse(T->rChild);
	}
}


//****************二叉树中序遍历****************
//实验六.二叉树.1，二叉树中序遍历
//输入：二叉树指针 
//打印：函数内打印二叉树结点
void inOrderTraverse(BiTree T)
{
	if (T)
	{
		inOrderTraverse(T->lChild);
		cout << T->data << '\t';
		inOrderTraverse(T->rChild);
	}
}


//****************二叉树后序遍历****************
//实验六.二叉树.1，二叉树后序遍历
//输入：二叉树指针 
//打印：函数内打印二叉树结点
void postTraverse(BiTree T)
{
	if (T)
	{
		postTraverse(T->lChild);
		postTraverse(T->rChild);
		cout << T->data << '\t';
	}
}


//****************中序输出二叉树及层次数****************
//实验六.二叉树.2，中序输出二叉树及层次数，当前层次数
//输入：二叉树指针 
//打印：函数内打印二叉树结点及层次数
void inOrderFloor(BiTree T, int floor)
{
	if (T)
	{
		inOrderFloor(T->lChild, floor + 1);
		cout << "结点：" << T->data << "；层次数：" << floor << '\t';
		inOrderFloor(T->rChild, floor + 1);
	}
}
//增加一个调用函数，不需用过户再传入初始化floor
void inOrderFloor(BiTree T)
{
	inOrderFloor(T, 1);
}


//****************求二叉树的高度****************
//实验六.二叉树.2，求二叉树的高度
//输入：二叉树指针 
//返回：二叉树高度
int getTreeHeight(BiTree T)
{
	int lh = 0, rh = 0;

	if (!T)
	{
		return 0;
	}
	else
	{
		lh = 1 + getTreeHeight(T->lChild);
		rh = 1 + getTreeHeight(T->rChild);

		return lh > rh ? lh : rh;
	}
}


//****************求二叉树的结点个数****************
//实验六.二叉树.2，求二叉树的结点个数
//输入：二叉树指针 
//返回：二叉树结点个数
int getTreeNodes(BiTree T)
{
	int num = 0;

	if (!T)
	{
		return 0;
	}
	else
	{
		num = 1 + getTreeNodes(T->lChild);
		num += getTreeNodes(T->rChild);

		return num;
	}
}


//****************求二叉树的叶子结点个数****************
//实验六.二叉树.2，求二叉树的叶子结点个数
//输入：二叉树指针 
//返回：二叉树叶子结点个数
void getTreeLeaves(BiTree T, int& num)
{
	if (!T)
	{
		return;
	}
	else
	{
		if ((!T->lChild) && (!T->rChild))
		{
			num++;
		}
		getTreeLeaves(T->lChild, num);
		getTreeLeaves(T->rChild, num);
	}
}
//增加一个调用函数，不需用过户再传入初始化num
int getTreeLeaves(BiTree T)
{
	int num = 0;

	getTreeLeaves(T, num);

	return num;
}


//****************求二叉树的叶子结点个数****************
//实验六.二叉树.2，求二叉树的叶子结点个数
//输入：二叉树指针 
//返回：二叉树叶子结点个数
void getTreeTwoDegree(BiTree T, int& num)
{
	if (!T)
	{
		return;
	}
	else
	{
		if (T->lChild && T->rChild)
		{
			num++;
		}
		getTreeTwoDegree(T->lChild, num);
		getTreeTwoDegree(T->rChild, num);
	}
}
//增加一个调用函数，不需用过户再传入初始化num
int getTreeTwoDegree(BiTree T)
{
	int num = 0;

	getTreeTwoDegree(T, num);

	return num;
}


//****************求某元素父结点和兄弟结点****************
//实验六.二叉树.2，求某元素父结点和兄弟结点
//输入：二叉树指针，查找元素
//打印：函数内打印该结点关系
void printFBNodes(BiTree T, elementType x, bool& flag)
{
	if (!T)
	{
		return;
	}
	else
	{
		if (T->lChild && T->lChild->data == x)
		{
			cout << x << "的父结点元素为：" << T->data << "；";
			if (T->rChild)
			{
				cout << "右兄弟结点元素为：" << T->rChild->data << "；";
			}
			else
			{
				cout << "没有兄弟结点" << "；";
			}
			if (T->lChild->lChild)
			{
				cout << "左孩子结点元素为：" << T->lChild->lChild->data << "；";
			}
			else
			{
				cout << "没有左孩子结点" << "；";
			}
			if (T->lChild->rChild)
			{
				cout << "右孩子结点元素为：" << T->lChild->rChild->data << "。";
			}
			else
			{
				cout << "没有右孩子结点" << "。";
			}

			flag = true;
			return;
		}
		else if (T->rChild && T->rChild->data == x)
		{
			cout << x << "的父结点元素为：" << T->data << "；";
			if (T->lChild)
			{
				cout << "左兄弟结点元素为：" << T->lChild->data << "；";
			}
			else
			{
				cout << "没有兄弟结点" << "；";
			}
			if (T->rChild->lChild)
			{
				cout << "左孩子结点元素为：" << T->rChild->lChild->data << "；";
			}
			else
			{
				cout << "没有左孩子结点" << "；";
			}
			if (T->rChild->rChild)
			{
				cout << "右孩子结点元素为：" << T->rChild->rChild->data << "。";
			}
			else
			{
				cout << "没有右孩子结点" << "。";
			}

			flag = true;
			return;
		}
		else if (T->data == x)
		{
			cout << x << "无父结点，因此也无兄弟结点；";
			if (T->lChild)
			{
				cout << "左孩子结点元素为：" << T->lChild->data << "；";
			}
			else
			{
				cout << "没有左孩子结点" << "；";
			}
			if (T->rChild)
			{
				cout << "右孩子结点元素为：" << T->rChild->data << "。";
			}
			else
			{
				cout << "没有右孩子结点" << "。";
			}

			flag = true;
			return;
		}
		printFBNodes(T->lChild, x, flag);
		printFBNodes(T->rChild, x, flag);
	}
}
//增加一个调用函数，不需用过户再传入初始化flag，且可以方便地判断是否查询成功
bool printFBNodes(BiTree T, elementType x)
{
	bool flag = false;
	printFBNodes(T, x, flag);

	return flag;
}


//****************求二叉树结点层次****************
//实验六.二叉树.2，求二叉树结点层次
//输入：二叉树指针，查找元素
void getNodeFloor(BiTree T, elementType x, int floor, int& res)
{
	if (T)
	{
		if (T->data == x)
		{
			res = floor;
			return;
		}
		getNodeFloor(T->lChild, x, floor + 1, res);
		getNodeFloor(T->rChild, x, floor + 1, res);
	}
}
//增加一个调用函数，不需用过户再传入初始化floor，不需要传入额外变量
int getNodeFloor(BiTree T, elementType x)
{
	int res = -1;

	getNodeFloor(T, x, 1, res);

	return res;
}


//****************将顺序二叉树转换为链式二叉树****************
//实验六.二叉树.2，将顺序二叉树转换为链式二叉树
//输入：二叉树指针，顺序二叉树数组
void tranSeqToLink(BiTree& T, elementType sBiTree[], int i, int len)
{
	if (i <= len && sBiTree[i - 1] != '/')
	{
		T = new BiNode;
		T->data = sBiTree[i - 1];
		T->lChild = nullptr;
		T->rChild = nullptr;
		tranSeqToLink(T->lChild, sBiTree, i * 2, len);
		tranSeqToLink(T->rChild, sBiTree, i * 2 + 1, len);
	}
}
//增加一个调用函数，不需用过户再传入初始化i
bool tranSeqToLink(BiTree& T, elementType sBiTree[])
{
	if (!T)
	{
		tranSeqToLink(T, sBiTree, 1, ((string)sBiTree).length());

		return true;
	}
	else
	{
		cout << "当前二叉树结点已占用！" << endl;

		return false;
	}
}