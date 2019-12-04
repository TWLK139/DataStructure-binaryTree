#ifndef BITREE_H

#define BITREE_H

#include<iostream>
#include<fstream>


#define elementType char
#define TREE_PATH "../trees/"

using namespace std;

#endif // !BITREE_H

//*********************�������ṹ����***********************//
typedef struct lBNode										//
{															//
	elementType data;										//
	struct lBNode *lChild, *rChild;							//
}BiNode, *BiTree;											//
//**********************************************************//

//**********************���������нṹ**********************//
//�����н��ṹ											//
typedef struct LNode										//
{															//
	elementType data[4];									//
	struct LNode* next;										//
}node;														//
															//
//�����нṹ												//
typedef struct LNodes										//
{															//
	node* front;					//��ͷָ��				//
	node* rear;						//��βָ��				//
}linkQueue;													//
//**********************************************************//

//**********************ָ�������нṹ**********************//
//�����н��ṹ											//
typedef struct LNodeP										//
{															//
	BiTree data;											//
	struct LNodeP* next;									//
}nodeP;														//
															//
//�����нṹ												//
typedef struct LNodesP										//
{															//
	nodeP* front;					//��ͷָ��				//
	nodeP* rear;					//��βָ��				//
}pLinkQueue;												//
//**********************************************************//

//************************************************��������******************************************************//
//�����к�������																								//
void initialQueue(linkQueue& Q);											//�����г�ʼ��						//
void initialQueue(pLinkQueue& Q);											//�����г�ʼ��						//
void enQueue(linkQueue& Q, elementType data[]);								//���������						//
void enQueue(linkQueue& Q, elementType data);								//���������						//
void enQueue(pLinkQueue& Q, BiTree tNode);									//���������						//
bool outQueue(linkQueue& Q);												//�����г���						//
bool outQueue(linkQueue& Q, elementType& data);								//�����г���						//
bool outQueue(pLinkQueue& Q, BiTree& tP);									//�����г���						//
//��������������																								//
void createSubTree(BiTree q, int k);										//��������������̨����				//
bool createBiTree(BiTree& BT);												//����������̨����					//
bool BiTreeFlie(string fileName, linkQueue& Q);								//�жϲ���ȡ�������ļ�				//
void createBiTree(BiTree& BT, string fileName);								//�������ļ�����					//
void createSubTree(BiTree& BT, linkQueue& Q);								//���������д���					//
void destoryTree(BiTree BT);												//���ٶ�����						//
void preTraverse(BiTree T);													//�������������					//
void inOrderTraverse(BiTree T);												//�������������					//
void postTraverse(BiTree T);												//�������������					//
void inOrderFloor(BiTree T, int floor);										//��������������������			//
void inOrderFloor(BiTree T);												//��������������������			//
int getTreeHeight(BiTree T);												//��������߶�						//
int getTreeNodes(BiTree T);													//�������������					//
void getTreeLeaves(BiTree T, int& num);										//�������Ҷ�ӽ�����				//
int getTreeLeaves(BiTree T);												//�������Ҷ�ӽ�����				//
void getTreeLeaves(BiTree T, linkQueue& Q);									//�Ѷ�����Ҷ�ӽڵ��ŵ�������		//
void getTreeTwoDegree(BiTree T, int& num);									//�������2�Ƚ�����				//
int getTreeTwoDegree(BiTree T);												//�������2�Ƚ�����				//
void printFBNodes(BiTree T, elementType x, bool& flag);						//�����������ϵ					//
bool printFBNodes(BiTree T, elementType x);									//�����������ϵ					//
void getNodeFloor(BiTree T, elementType x, int floor, int& res);			//������������					//
int getNodeFloor(BiTree T, elementType x);									//������������					//
void tranSeqToLink(BiTree& T, elementType sBiTree[], int i, int len);		//��˳�������ת������ʽ������		//
void tranSeqToLink(BiTree& T, elementType sBiTree[]);						//��˳�������ת������ʽ������		//
void exchangeChild(BiTree T);												//�������������Һ��ӽ��			//
//������ѡ��ʵ�麯������																						//
void copyBiTree(BiTree T, BiTree& cT);										//���ƶ�����						//
void getLeavesPath(BiTree T, elementType data, bool& flag);					//��ӡָ����㵽������·��		//
void getLeavesPath(BiTree T);												//��ȡ����Ҷ�ӵ�������·��		//
void floorTraverse(BiTree T);												//��������α���					//
//**************************************************************************************************************//


//******************************��������********************************

//***************************��������������*****************************
//****************���������������г�ʼ��****************
//���룺���н��
//���أ��ɹ�����true��ʧ�ܷ���false
void initialQueue(linkQueue& Q)
{
	Q.front = new node;
	Q.rear = Q.front;
	Q.front->next = nullptr;
}


//****************���������������г�ʼ��****************
//���룺���н��
//���أ��ɹ�����true��ʧ�ܷ���false
void initialQueue(pLinkQueue& Q)
{
	Q.front = new nodeP;
	Q.rear = Q.front;
	Q.front->next = nullptr;
}


//****************������������������������̨����****************
//���룺��ǰ�������ڵ㣬��������λ��
//���أ��ɹ�����true��ʧ�ܷ���false
void createSubTree(BiTree q, int k)						//qΪ��ǰ�����ĸ��ڵ�
{														//k=-1ʱ��ʾ��������k=1ʱ��ʾ������
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


//****************��������������������̨����****************
//���룺���������ڵ�
//���أ��ɹ�����true��ʧ�ܷ���false
bool createBiTree(BiTree& BT)
{
	elementType x;

	if (BT == nullptr)
	{
		cout << "����������������У�" << endl;
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


//****************�������������ٶ�����****************
//���룺���������ڵ�
void destoryTree(BiTree BT)
{
	if (BT)
	{
		destoryTree(BT->lChild);
		destoryTree(BT->rChild);
		delete(BT);
	}
}


//****************�������������������****************
//��������������������
//���룺��Ҫ������ӵĶ���ָ�룬��Ž���������ַ
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


//****************�������������������****************
//�������������������
//���룺��Ҫ������ӵĶ���ָ�룬��Ž�������ݵ�ַ
void enQueue(linkQueue& Q, elementType data)
{
	Q.rear->next = new node;
	Q.rear = Q.rear->next;
	Q.rear->data[0] = data;
	Q.rear->data[1] = '\0';
	Q.rear->next = nullptr;
}


//****************�������������������****************
//�������������������
//���룺��Ҫ������ӵĶ���ָ�룬��Ž���Ķ�����ָ���ַ
void enQueue(pLinkQueue& Q, BiTree tNode)
{
	Q.rear->next = new nodeP;
	Q.rear = Q.rear->next;
	Q.rear->data = tNode;
	Q.rear->next = nullptr;
}


//****************���������������г���****************
//���������������г���
//���룺��Ҫ���г��ӵĶ���ָ��
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


//****************���������������г���****************
//���������������г���
//���룺��Ҫ���г��ӵĶ���ָ�룬��Ŷ�β���ݵĵ�ַ
bool outQueue(linkQueue& Q, elementType& data)
{
	node* dp = nullptr;

	if (Q.front != Q.rear)
	{
		dp = Q.front->next;
		data = dp->data[0];
		Q.front->next = dp->next;
		delete(dp);
		if (Q.front->next == nullptr)
		{
			Q.rear = Q.front;
		}

		return true;
	}
	else
	{
		return false;
	}
}


//****************���������������г���****************
//���������������г���
//���룺��Ҫ���г��ӵĶ���ָ�룬��Ŷ�βָ��ĵ�ַ
bool outQueue(pLinkQueue& Q, BiTree& tP)
{
	nodeP* dp = nullptr;

	if (Q.front != Q.rear)
	{
		dp = Q.front->next;
		tP = dp->data;
		Q.front->next = dp->next;
		delete(dp);
		if (Q.front->next == nullptr)
		{
			Q.rear = Q.front;
		}

		return true;
	}
	else
	{
		return false;
	}
}


//****************�����������ж��ļ��Ƿ��Ƕ������ļ�****************
//���룺���������ڵ㣬�ļ���
//���أ��ɹ�����true��ʧ�ܷ���false
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
				if (buffer[0] == '/')				//�жϸ����ļ�Ϊע��
				{
					while (buffer[0] != '\n')		//�����ļ���ָ���ƶ�����ĩ
					{
						infile.get(buffer[0]);
						//cout << buffer[0];
					}
				}
			}
			else if (buffer[0] == ' ' || buffer[0] == '\t')				//�����ļ���ʼΪ�ո�
			{
				while (buffer[0] != '/' && buffer[0] != 'B')			//����ȡ�ļ���ֱ�����ֵ�һ���ǿո�Ϊֹ
				{
					infile.get(buffer[0]);
					//cout << buffer[0];
				}
				if (buffer[0] == 'B')				//ƥ��BinaryTreeǰ����ܴ��ڵĿտͻ��Ʊ��
				{
					break;
				}
				infile.get(buffer[0]);
				//cout << buffer[0];
				if (buffer[0] == '/')				//�жϸ����ļ�Ϊע��
				{
					while (buffer[0] != '\n')		//�����ļ���ָ���ƶ�����ĩ
					{
						infile.get(buffer[0]);
						//cout << buffer[0];
					}
				}
			}
		} while (buffer[0]=='\n');					//���ļ���ָ��ָ���з�ʱ��˵������Ϊע�ͣ�����ѭ��������һ��
													//���ļ���ָ�벻ָ���з�ʱ��Ҫ�жϸ����Ƿ��Ƕ������ļ���ʶ��
		infile.getline(&buffer[1], 10);				//��һ���ַ���֮ǰ��ѭ���Ѷ����ַ�������˽�����ʣ���ַ����ַ����ڶ���λ�ÿ�ʼ����
		if ((string)buffer == "BinaryTree")			//�ж��Ƿ��Ǳ�ʶ�У�Ҫ��char��������ת�����ַ���
		{
			Q.front = new node;						//��ʼ������
			Q.rear = Q.front;
			Q.front->next = nullptr;
			do					//����ļ�û�н�����Ҫ�����Ķ������
			{
				infile.getline(buffer, 8);				//���¶����ļ�
				if ((string)buffer != "\0" && buffer[0] != ' ' && buffer[0] != '/')
				{									//��������ǿ��С�ע���У�������
					if (buffer[2] == ' ')			//ƥ��ĳЩ������Ч�ַ��м���������ո�����
					{
						buffer[2] = buffer[3];
					}
					if (buffer[4] == ' ')			//ƥ��ĳЩ������Ч�ַ��м���������ո�����
					{
						buffer[4] = buffer[6];
					}
					enQueue(Q, buffer);				//���ǿ��ж������
				}
			} while (!infile.eof());

			infile.close();							//�ر��ļ���

			return true;
		}
		else
		{
			cout << "��ǰ�ļ����Ƕ������ļ���" << endl;

			infile.close();							//�ر��ļ���

			return false;
		}
	}
	else
	{
		cout << endl << "�ļ���ʧ�ܣ�" << endl;

		infile.close();								//�ر��ļ���

		return false;
	}
}


//****************�������������������д���****************
//���룺���������ڵ㣬����ָ��
void createSubTree(BiTree& BT, linkQueue& Q)
{
	//��¼��ǰ���������������Ϊ�����л����ȫ���޸�
	elementType lChild = NULL, rChild = NULL;

	if (Q.front != Q.rear)						//�����в�Ϊ��ʱ��������������
	{
		lChild = Q.front->next->data[1];
		rChild = Q.front->next->data[2];
		BT = new BiNode;						//Ϊ��ǰ����������
		BT->data = Q.front->next->data[0];
		BT->lChild = nullptr;
		BT->rChild = nullptr;
		if (lChild == '1')
		{
			outQueue(Q);						//���г���
			createSubTree(BT->lChild, Q);		//�ݹ鴴������
		}
		if (rChild == '1')
		{
			outQueue(Q);						//���г���
			createSubTree(BT->rChild, Q);		//�ݹ鴴������
		}
	}
}


//****************�����������������ļ�����****************
//���룺���������ڵ㣬�ļ���
void createBiTree(BiTree& BT, string fileName)
{
	linkQueue Q;

	if (BiTreeFlie(TREE_PATH + fileName, Q))	//�ļ���ȡ�ɹ���ͬʱ�ᴴ������
	{
		createSubTree(BT, Q);					//��ʼ�ݹ鴴������
	}
}


//****************�������������****************
//ʵ����.������.1���������������
//���룺������ָ�� 
//��ӡ�������ڴ�ӡ���������
void preTraverse(BiTree T)
{
	if (T)
	{
		cout << T->data << '\t';
		preTraverse(T->lChild);
		preTraverse(T->rChild);
	}
}


//****************�������������****************
//ʵ����.������.1���������������
//���룺������ָ�� 
//��ӡ�������ڴ�ӡ���������
void inOrderTraverse(BiTree T)
{
	if (T)
	{
		inOrderTraverse(T->lChild);
		cout << T->data << '\t';
		inOrderTraverse(T->rChild);
	}
}


//****************�������������****************
//ʵ����.������.1���������������
//���룺������ָ�� 
//��ӡ�������ڴ�ӡ���������
void postTraverse(BiTree T)
{
	if (T)
	{
		postTraverse(T->lChild);
		postTraverse(T->rChild);
		cout << T->data << '\t';
	}
}


//****************��������������������****************
//ʵ����.������.2��������������������������ǰ�����
//���룺������ָ�� 
//��ӡ�������ڴ�ӡ��������㼰�����
void inOrderFloor(BiTree T, int floor)
{
	if (T)
	{
		inOrderFloor(T->lChild, floor + 1);
		cout << "��㣺" << T->data << "���������" << floor << '\t';
		inOrderFloor(T->rChild, floor + 1);
	}
}
//����һ�����ú����������ù����ٴ����ʼ��floor
void inOrderFloor(BiTree T)
{
	inOrderFloor(T, 1);
}


//****************��������ĸ߶�****************
//ʵ����.������.2����������ĸ߶�
//���룺������ָ�� 
//���أ��������߶�
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


//****************��������Ľ�����****************
//ʵ����.������.2����������Ľ�����
//���룺������ָ�� 
//���أ�������������
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


//****************���������Ҷ�ӽ�����****************
//ʵ����.������.2�����������Ҷ�ӽ�����
//���룺������ָ�� 
//���أ�������Ҷ�ӽ�����
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
//����һ�����ú����������ù����ٴ����ʼ��num
int getTreeLeaves(BiTree T)
{
	int num = 0;

	getTreeLeaves(T, num);

	return num;
}


//****************���������Ҷ�ӽ���ڶ�����****************
//ʵ����.������.2�����������Ҷ�ӽ���ڶ�����
//���룺������ָ�� 
//�������Ŷ�����Ҷ�ӽ��Ķ���
void getTreeLeaves(BiTree T, linkQueue& Q)
{
	if (!T)
	{
		return;
	}
	else
	{
		if ((!T->lChild) && (!T->rChild))
		{
			enQueue(Q, T->data);
		}
		getTreeLeaves(T->lChild, Q);
		getTreeLeaves(T->rChild, Q);
	}
}


//****************���������2�Ƚ�����****************
//ʵ����.������.2�����������2�Ƚ�����
//���룺������ָ�� 
//���أ�������2�Ƚ�����
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
//����һ�����ú����������ù����ٴ����ʼ��num
int getTreeTwoDegree(BiTree T)
{
	int num = 0;

	getTreeTwoDegree(T, num);

	return num;
}


//****************��ĳԪ�ظ������ֵܽ��****************
//ʵ����.������.2����ĳԪ�ظ������ֵܽ��
//���룺������ָ�룬����Ԫ��
//��ӡ�������ڴ�ӡ�ý���ϵ
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
			cout << x << "�ĸ����Ԫ��Ϊ��" << T->data << "��";
			if (T->rChild)
			{
				cout << "���ֵܽ��Ԫ��Ϊ��" << T->rChild->data << "��";
			}
			else
			{
				cout << "û���ֵܽ��" << "��";
			}
			if (T->lChild->lChild)
			{
				cout << "���ӽ��Ԫ��Ϊ��" << T->lChild->lChild->data << "��";
			}
			else
			{
				cout << "û�����ӽ��" << "��";
			}
			if (T->lChild->rChild)
			{
				cout << "�Һ��ӽ��Ԫ��Ϊ��" << T->lChild->rChild->data << "��";
			}
			else
			{
				cout << "û���Һ��ӽ��" << "��";
			}

			flag = true;
			return;
		}
		else if (T->rChild && T->rChild->data == x)
		{
			cout << x << "�ĸ����Ԫ��Ϊ��" << T->data << "��";
			if (T->lChild)
			{
				cout << "���ֵܽ��Ԫ��Ϊ��" << T->lChild->data << "��";
			}
			else
			{
				cout << "û���ֵܽ��" << "��";
			}
			if (T->rChild->lChild)
			{
				cout << "���ӽ��Ԫ��Ϊ��" << T->rChild->lChild->data << "��";
			}
			else
			{
				cout << "û�����ӽ��" << "��";
			}
			if (T->rChild->rChild)
			{
				cout << "�Һ��ӽ��Ԫ��Ϊ��" << T->rChild->rChild->data << "��";
			}
			else
			{
				cout << "û���Һ��ӽ��" << "��";
			}

			flag = true;
			return;
		}
		else if (T->data == x)
		{
			cout << x << "�޸���㣬���Ҳ���ֵܽ�㣻";
			if (T->lChild)
			{
				cout << "���ӽ��Ԫ��Ϊ��" << T->lChild->data << "��";
			}
			else
			{
				cout << "û�����ӽ��" << "��";
			}
			if (T->rChild)
			{
				cout << "�Һ��ӽ��Ԫ��Ϊ��" << T->rChild->data << "��";
			}
			else
			{
				cout << "û���Һ��ӽ��" << "��";
			}

			flag = true;
			return;
		}
		printFBNodes(T->lChild, x, flag);
		printFBNodes(T->rChild, x, flag);
	}
}
//����һ�����ú����������ù����ٴ����ʼ��flag���ҿ��Է�����ж��Ƿ��ѯ�ɹ�
bool printFBNodes(BiTree T, elementType x)
{
	bool flag = false;
	printFBNodes(T, x, flag);

	return flag;
}


//****************������������****************
//ʵ����.������.2��������������
//���룺������ָ�룬����Ԫ��
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
//����һ�����ú����������ù����ٴ����ʼ��floor������Ҫ����������
int getNodeFloor(BiTree T, elementType x)
{
	int res = -1;

	getNodeFloor(T, x, 1, res);

	return res;
}


//****************��˳�������ת��Ϊ��ʽ������****************
//ʵ����.������.2����˳�������ת��Ϊ��ʽ������
//���룺������ָ�룬˳�����������
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
//����һ�����ú����������ù����ٴ����ʼ��i
void tranSeqToLink(BiTree& T, elementType sBiTree[])
{
	tranSeqToLink(T, sBiTree, 1, ((string)sBiTree).length());
}


//****************�������������Һ��ӽ��****************
//ʵ����.������.2���������������Һ��ӽ��
//���룺������ָ��
void exchangeChild(BiTree T)
{
	BiTree TSave = nullptr;

	if (T)
	{
		TSave = T->lChild;
		T->lChild = T->rChild;
		T->rChild = TSave;
		
		exchangeChild(T->lChild);
		exchangeChild(T->rChild);
	}
}


//****************���ƶ�����****************
//ʵ����.������.2�����ƶ�����
//���룺������ָ�룬��Ÿ���ֵ�ĵ�ַ
void copyBiTree(BiTree T, BiTree& cT)
{

	if (T && !cT)
	{
		cT = new BiNode;
		cT->data = T->data;
		cT->lChild = nullptr;
		cT->rChild = nullptr;
		copyBiTree(T->lChild, cT->lChild);
		copyBiTree(T->rChild, cT->rChild);
	}
	else if (cT)
	{
		cout << "��ǰ������ָ����ռ�ã�" << endl;
	}
}


//****************������������ӡָ����㵽������·��****************
//���룺��ǰ�����ڵ㣬ָ�����Ԫ�أ���ʼ��Ϊfalse��bool���ͱ�ʶ
//��ӡ�������ڴ�ӡָ����㵽������·��
void getLeavesPath(BiTree T, elementType data, bool& flag)
{
	if (T && !flag)
	{
		if (T->data == data)
		{
			flag = true;
			cout << T->data << "\t";
			return;
		}
		getLeavesPath(T->lChild, data, flag);
		getLeavesPath(T->rChild, data, flag);
		if (flag)
		{
			cout << T->data << "\t";
		}
	}
}


//****************�������Ҷ�ӽ�㵽���ڵ��·��****************
//ʵ����.������.2���������Ҷ�ӽ�㵽���ڵ��·��
//���룺������ָ��
void getLeavesPath(BiTree T)
{
	bool flag = false;
	linkQueue Q;
	elementType data = NULL;

	Q.front = new node;
	Q.rear = Q.front;
	Q.front->next = nullptr;

	getTreeLeaves(T, Q);

	while (outQueue(Q, data))
	{
		getLeavesPath(T, data, flag);
		flag = false;
		cout << endl;
	}
}


//****************��������α���****************
//ʵ����.������.1����������α���
//���룺������ָ�� 
//��ӡ�������ڴ�ӡ���������
void floorTraverse(BiTree T)
{
	pLinkQueue Q;
	BiTree Tp = nullptr;

	initialQueue(Q);

	enQueue(Q, T);
	while (outQueue(Q, Tp))
	{
		cout << Tp->data << '\t';
		if (Tp->lChild)
		{
			enQueue(Q, Tp->lChild);
		}
		if (Tp->rChild)
		{
			enQueue(Q, Tp->rChild);
		}
	}
}