#include"BiTree.h"

int main(void)
{
	BiTree BT = nullptr, BT2 = nullptr;
	string fn = "bt9.btr";
	elementType sBiTree[] = "ABCDEF///GH/I//";

	createBiTree(BT,fn);
	preTraverse(BT);
	cout << endl;
	inOrderTraverse(BT);
	cout << endl;
	postTraverse(BT);
	cout << endl;
	inOrderFloor(BT);
	cout << endl << getTreeHeight(BT);
	cout << endl << getTreeNodes(BT);
	cout << endl << getTreeLeaves(BT);
	cout << endl << getTreeTwoDegree(BT);
	cout << endl;
	if (printFBNodes(BT, 'c'))
	{
		cout << "查找成功！" << endl;
	}
	else
	{
		cout << "查找失败！" << endl;
	}
	cout << getNodeFloor(BT, 'k');
	tranSeqToLink(BT2, sBiTree);
	preTraverse(BT2);
	cout << endl;
	inOrderTraverse(BT2);
	cout << endl;
	postTraverse(BT2);
	cout << endl;
	inOrderFloor(BT2);
}