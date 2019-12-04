#include"BiTree.h"

int main(void)
{
	int order = NULL, res = NULL;
	BiTree BT = nullptr, CT = nullptr;
	elementType sBiTree_1[] = "12836//45/7////";
	elementType sBiTree_2[] = "ab/ci//dfj//////eg/kl///////////////h////m//////////////////////////////////////////n///////////////////////////////////////////";

	while (1)
	{
		cout << "实验六：二叉树实验" << endl;
		cout << "*****************************************************************" << endl;
		cout << "*1，树的三种遍历序。\t\t\t\t\t\t*" << endl;
		cout << "*2，树中结点及层次数。\t\t\t\t\t\t*" << endl;
		cout << "*3，求二叉树高度。\t\t\t\t\t\t*" << endl;
		cout << "*4，求二叉树结点数。\t\t\t\t\t\t*" << endl;
		cout << "*5，求二叉树叶子结点数。\t\t\t\t\t*" << endl;
		cout << "*6，求二叉树2度结点数。\t\t\t\t\t\t*" << endl;
		cout << "*7，获取元素相应关系。\t\t\t\t\t\t*" << endl;
		cout << "*8，获取元素层次。\t\t\t\t\t\t*" << endl;
		cout << "*9，将顺序二叉树转换为链式二叉树。\t\t\t\t*" << endl;
		cout << "*10，交换左右孩子指针。\t\t\t\t\t\t*" << endl;
		cout << "*\t\t\t\t\t\t\t\t*" << endl;
		cout << "*11，复制二叉树。\t\t\t\t\t\t*" << endl;
		cout << "*12，输出每个叶子结点到根结点路径。\t\t\t\t*" << endl;
		cout << "*13，层次遍历二叉树。\t\t\t\t\t\t*" << endl;
		cout << "*\t\t\t\t\t\t\t\t*" << endl;
		cout << "*0，退出程序。\t\t\t\t\t\t\t*" << endl;
		cout << "*****************************************************************" << endl;
		cout << "请输入菜单编号：\t";
		cin >> order;

		switch (order)
		{
		case 1:
			system("cls");
			//第一组测试**********************************************************
			cout << "第一组实验（文件：bt151.btr）：";
			createBiTree(BT, "bt151.btr");
			cout << endl << "先序遍历序：\t";
			preTraverse(BT);
			cout << endl << "中序遍历序：\t";
			inOrderTraverse(BT);
			cout << endl << "后序遍历序：\t";
			postTraverse(BT);
			destoryTree(BT);
			cout << endl;
			//********************************************************************
			//第二组测试**********************************************************
			cout << "第二组实验（文件：bt21.btr）：";
			createBiTree(BT, "bt21.btr");
			cout << endl << "先序遍历序：\t";
			preTraverse(BT);
			cout << endl << "中序遍历序：\t";
			inOrderTraverse(BT);
			cout << endl << "后序遍历序：\t";
			postTraverse(BT);
			destoryTree(BT);
			cout << endl;
			//********************************************************************
			break;
		case 2:
			system("cls");
			//第一组测试**********************************************************
			cout << "第一组实验（文件：bt151.btr）：";
			cout << endl << "对应结点层次数：" << endl;
			createBiTree(BT, "bt151.btr");
			inOrderFloor(BT);
			destoryTree(BT);
			cout << endl;
			//********************************************************************
			//第二组测试**********************************************************
			cout << "第二组实验（文件：bt21.btr）：";
			cout << endl << "对应结点层次数：" << endl;
			createBiTree(BT, "bt21.btr");
			inOrderFloor(BT);
			destoryTree(BT);
			cout << endl;
			//********************************************************************
			break;
		case 3:
			system("cls");
			//第一组测试**********************************************************
			cout << "第一组实验数据：（文件：bt261.btr）" << endl;
			createBiTree(BT, "bt261.btr");
			cout << endl << "二叉树高度为：" << getTreeHeight(BT) << endl;
			destoryTree(BT);
			//********************************************************************
			//第二组测试**********************************************************
			cout << "第二组实验数据：（文件：bt21.btr）" << endl;
			createBiTree(BT, "bt21.btr");
			cout << endl << "二叉树高度为：" << getTreeHeight(BT) << endl;
			destoryTree(BT);
			//********************************************************************
			break;
		case 4:
			system("cls");
			//第一组测试**********************************************************
			cout << "第一组实验数据：（文件：bt261.btr）" << endl;
			createBiTree(BT, "bt261.btr");
			cout << endl << "二叉树结点数为：" << getTreeNodes(BT) << endl;
			destoryTree(BT);
			//********************************************************************
			//第二组测试**********************************************************
			cout << "第二组实验数据：（文件：bt21.btr）" << endl;
			createBiTree(BT, "bt21.btr");
			cout << endl << "二叉树结点数为：" << getTreeNodes(BT) << endl;
			destoryTree(BT);
			//********************************************************************
			break;
		case 5:
			system("cls");
			//第一组测试**********************************************************
			cout << "第一组实验数据：（文件：bt261.btr）" << endl;
			createBiTree(BT, "bt261.btr");
			cout << endl << "二叉树叶子结点数为：" << getTreeLeaves(BT) << endl;
			destoryTree(BT);
			//********************************************************************
			//第二组测试**********************************************************
			cout << "第二组实验数据：（文件：bt21.btr）" << endl;
			createBiTree(BT, "bt21.btr");
			cout << endl << "二叉树叶子结点数为：" << getTreeLeaves(BT) << endl;
			destoryTree(BT);
			//********************************************************************
			cout << endl;
			break;
		case 6:
			system("cls");
			//第一组测试**********************************************************
			cout << "第一组实验数据：（文件：bt261.btr）" << endl;
			createBiTree(BT, "bt261.btr");
			cout << endl << "二叉树2度结点数为：" << getTreeTwoDegree(BT) << endl;
			destoryTree(BT);
			//********************************************************************
			//第二组测试**********************************************************
			cout << "第二组实验数据：（文件：bt21.btr）" << endl;
			createBiTree(BT, "bt21.btr");
			cout << endl << "二叉树2度结点数为：" << getTreeTwoDegree(BT) << endl;
			destoryTree(BT);
			//********************************************************************
			break;
		case 7:
			system("cls");
			//第一组测试**********************************************************
			cout << "第一组实验数据：（文件：bt31.btr）";		//获取元素相应关系
			createBiTree(BT, "bt31.btr");
			cout << endl << "第1次测试数数据：a" << endl;
			if (!printFBNodes(BT, 'a')) cout << "元素查找失败";
			cout << endl << "第2次测试数数据：q" << endl;
			if (!printFBNodes(BT, 'q')) cout << "元素查找失败";
			cout << endl << "第3次测试数数据：n" << endl;
			if (!printFBNodes(BT, 'k')) cout << "元素查找失败";
			cout << endl << "第4次测试数数据：2" << endl;
			if (!printFBNodes(BT, '2')) cout << "元素查找失败";
			cout << endl << "第5次测试数数据：6" << endl;
			if (!printFBNodes(BT, '6')) cout << "元素查找失败";
			cout << endl;
			destoryTree(BT);
			//********************************************************************
			//第二组测试**********************************************************
			cout << "第二组实验数据：（文件：bt21.btr）";		//获取元素相应关系
			createBiTree(BT, "bt21.btr");
			cout << endl << "第1次测试数数据：a" << endl;
			if (!printFBNodes(BT, 'a')) cout << "元素查找失败";
			cout << endl << "第2次测试数数据：h" << endl;
			if (!printFBNodes(BT, 'h')) cout << "元素查找失败";
			cout << endl << "第3次测试数数据：p" << endl;
			if (!printFBNodes(BT, 'p')) cout << "元素查找失败";
			cout << endl << "第4次测试数数据：t" << endl;
			if (!printFBNodes(BT, 't')) cout << "元素查找失败";
			cout << endl << "第5次测试数数据：f" << endl;
			if (!printFBNodes(BT, 'f')) cout << "元素查找失败";
			cout << endl << "第6次测试数数据：z" << endl;
			if (!printFBNodes(BT, 'z')) cout << "元素查找失败";
			cout << endl;
			destoryTree(BT);
			//********************************************************************
			break;
		case 8:
			system("cls");
			//第一组测试**********************************************************
			cout << "第一组实验数据：（文件：bt26.btr）";		//获取元素层次
			createBiTree(BT, "bt26.btr");
			cout << endl << "第1次测试数数据：a" << endl;
			res = getNodeFloor(BT, 'a');
			if (res < 0) cout << "元素查找失败";
			else cout << "当前元素层次为：" << res;
			cout << endl << "第2次测试数数据：n" << endl;
			res = getNodeFloor(BT, 'n');
			if (res < 0) cout << "元素查找失败";
			else cout << "当前元素层次为：" << res;
			cout << endl << "第3次测试数数据：i" << endl;
			res = getNodeFloor(BT, 'i');
			if (res < 0) cout << "元素查找失败";
			else cout << "当前元素层次为：" << res;
			cout << endl << "第4次测试数数据：s" << endl;
			res = getNodeFloor(BT, 's');
			if (res < 0) cout << "元素查找失败";
			else cout << "当前元素层次为：" << res;
			cout << endl << "第5次测试数数据：v" << endl;
			res = getNodeFloor(BT, 'v');
			if (res < 0) cout << "元素查找失败";
			else cout << "当前元素层次为：" << res;
			cout << endl << "第6次测试数数据：6" << endl;
			res = getNodeFloor(BT, '6');
			if (res < 0) cout << "元素查找失败";
			else cout << "当前元素层次为：" << res;
			destoryTree(BT);									//销毁二叉树
			cout << endl;
			//********************************************************************
			cout << endl;
			//第二组测试**********************************************************
			cout << "第二组实验数据：（文件：bt21.btr）";		//获取元素层次
			createBiTree(BT, "bt21.btr");
			cout << endl << "第1次测试数数据：a" << endl;
			res = getNodeFloor(BT, 'a');
			if (res < 0) cout << "元素查找失败";
			else cout << "当前元素层次为：" << res;
			cout << endl << "第2次测试数数据：b" << endl;
			res = getNodeFloor(BT, 'b');
			if (res < 0) cout << "元素查找失败";
			else cout << "当前元素层次为：" << res;
			cout << endl << "第3次测试数数据：l" << endl;
			res = getNodeFloor(BT, 'l');
			if (res < 0) cout << "元素查找失败";
			else cout << "当前元素层次为：" << res;
			cout << endl << "第4次测试数数据：m" << endl;
			res = getNodeFloor(BT, 'm');
			if (res < 0) cout << "元素查找失败";
			else cout << "当前元素层次为：" << res;
			cout << endl << "第5次测试数数据：u" << endl;
			res = getNodeFloor(BT, 'u');
			if (res < 0) cout << "元素查找失败";
			else cout << "当前元素层次为：" << res;
			cout << endl << "第6次测试数数据：z" << endl;
			res = getNodeFloor(BT, 'z');
			if (res < 0) cout << "元素查找失败";
			else cout << "当前元素层次为：" << res;
			destoryTree(BT);									//销毁二叉树
			cout << endl;
			//********************************************************************
			break;
		case 9:
			system("cls");
			//第一组测试**********************************************************
			cout << "第一组实验数据：" << endl;					//将顺序二叉树转换为链式二叉树
			cout << "顺序存储：" << sBiTree_1;
			tranSeqToLink(BT, sBiTree_1);
			cout << endl << "先序遍历序：\t";
			preTraverse(BT);
			cout << endl << "中序遍历序：\t";
			inOrderTraverse(BT);
			cout << endl << "后序遍历序：\t";
			postTraverse(BT);
			cout << endl;
			destoryTree(BT);
			BT = nullptr;
			//********************************************************************
			//第二组测试**********************************************************
			cout << "第二组实验数据：" << endl;					//将顺序二叉树转换为链式二叉树
			cout << "顺序存储：" << sBiTree_2;
			tranSeqToLink(BT, sBiTree_2);
			cout << endl << "先序遍历序：\t";
			preTraverse(BT);
			cout << endl << "中序遍历序：\t";
			inOrderTraverse(BT);
			cout << endl << "后序遍历序：\t";
			postTraverse(BT);
			cout << endl;
			destoryTree(BT);
			BT = nullptr;
			//********************************************************************
			break;
		case 10:
			system("cls");
			//第一组测试**********************************************************
			cout << "第一组实验数据：（文件：bt151.btr）";		//交换左右孩子指针
			createBiTree(BT, "bt151.btr");
			cout << endl << "原文件先序：";
			preTraverse(BT);
			cout << endl << "原文件中序：";
			inOrderTraverse(BT);
			cout << endl << "原文件后序：";
			postTraverse(BT);
			exchangeChild(BT);
			cout << endl << "交换后文件先序：";
			preTraverse(BT);
			cout << endl << "交换后文件中序：";
			inOrderTraverse(BT);
			cout << endl << "交换后文件后序：";
			postTraverse(BT);
			destoryTree(BT);
			BT = nullptr;
			cout << endl;
			//********************************************************************
			//第二组测试**********************************************************
			cout << "第二组实验数据：（文件：bt21.btr）";		//交换左右孩子指针
			createBiTree(BT, "bt21.btr");
			cout << endl << "原文件先序：";
			preTraverse(BT);
			cout << endl << "原文件中序：";
			inOrderTraverse(BT);
			cout << endl << "原文件后序：";
			postTraverse(BT);
			exchangeChild(BT);
			cout << endl << "交换后文件先序：";
			preTraverse(BT);
			cout << endl << "交换后文件中序：";
			inOrderTraverse(BT);
			cout << endl << "交换后文件后序：";
			postTraverse(BT);
			destoryTree(BT);
			BT = nullptr;
			cout << endl;
			//********************************************************************
			break;
		case 11:
			system("cls");
			//第一组测试**********************************************************
			cout << "第一组实验数据：（文件：bt151.btr）" << endl;	//复制二叉树
			createBiTree(BT, "bt151.btr");
			cout << endl << "原文件先序：";
			preTraverse(BT);
			cout << endl << "原文件中序：";
			inOrderTraverse(BT);
			cout << endl << "原文件后序：";
			postTraverse(BT);
			copyBiTree(BT, CT);
			cout << endl << "复制文件先序：";
			preTraverse(CT);
			cout << endl << "复制文件中序：";
			inOrderTraverse(CT);
			cout << endl << "复制文件后序：";
			postTraverse(CT);
			destoryTree(BT);
			destoryTree(CT);
			BT = nullptr;
			CT = nullptr;
			cout << endl;
			//********************************************************************
			//第二组测试**********************************************************
			cout << "第二组实验数据：（文件：bt21.btr）" << endl;	//复制二叉树
			createBiTree(BT, "bt21.btr");
			cout << endl << "原文件先序：";
			preTraverse(BT);
			cout << endl << "原文件中序：";
			inOrderTraverse(BT);
			cout << endl << "原文件后序：";
			postTraverse(BT);
			copyBiTree(BT, CT);
			cout << endl << "复制文件先序：";
			preTraverse(CT);
			cout << endl << "复制文件中序：";
			inOrderTraverse(CT);
			cout << endl << "复制文件后序：";
			postTraverse(CT);
			destoryTree(BT);
			destoryTree(CT);
			BT = nullptr;
			CT = nullptr;
			cout << endl;
			//********************************************************************
			break;
		case 12:
			system("cls");
			//第一组测试**********************************************************
			cout << "第一组实验数据：（文件：bt261.btr）" << endl;	//输出每个叶子结点到根结点路径
			createBiTree(BT, "bt261.btr");
			getLeavesPath(BT);
			destoryTree(BT);
			cout << endl;
			//********************************************************************
			//第二组测试**********************************************************
			cout << "第二组实验数据：（文件：bt21.btr）" << endl;	//输出每个叶子结点到根结点路径
			createBiTree(BT, "bt21.btr");
			getLeavesPath(BT);
			destoryTree(BT);
			cout << endl;
			//********************************************************************
			break;
		case 13:
			system("cls");
			//第一组测试**********************************************************
			cout << "第一组实验数据：（文件：bt261.btr）" << endl;	//层次遍历二叉树
			createBiTree(BT, "bt261.btr");
			floorTraverse(BT);
			destoryTree(BT);
			cout << endl;
			//********************************************************************
			//第二组测试**********************************************************
			cout << "第二组实验数据：（文件：bt21.btr）" << endl;	//层次遍历二叉树
			createBiTree(BT, "bt21.btr");
			floorTraverse(BT);
			destoryTree(BT);
			cout << endl;
			//********************************************************************
			break;
		case 0:
			cout << "退出程序！" << endl;
			return 0;
		default:
			system("cls");
			cout << "输入错误！" << endl;
			break;
		}
	}

	return 0;
}