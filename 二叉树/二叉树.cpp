#include"BiTree.h"

int main(void)
{
	int order = NULL, res = NULL;
	BiTree BT = nullptr, CT = nullptr;
	elementType sBiTree_1[] = "12836//45/7////";
	elementType sBiTree_2[] = "ab/ci//dfj//////eg/kl///////////////h////m//////////////////////////////////////////n///////////////////////////////////////////";

	while (1)
	{
		cout << "ʵ������������ʵ��" << endl;
		cout << "*****************************************************************" << endl;
		cout << "*1���������ֱ�����\t\t\t\t\t\t*" << endl;
		cout << "*2�����н�㼰�������\t\t\t\t\t\t*" << endl;
		cout << "*3����������߶ȡ�\t\t\t\t\t\t*" << endl;
		cout << "*4����������������\t\t\t\t\t\t*" << endl;
		cout << "*5���������Ҷ�ӽ������\t\t\t\t\t*" << endl;
		cout << "*6���������2�Ƚ������\t\t\t\t\t\t*" << endl;
		cout << "*7����ȡԪ����Ӧ��ϵ��\t\t\t\t\t\t*" << endl;
		cout << "*8����ȡԪ�ز�Ρ�\t\t\t\t\t\t*" << endl;
		cout << "*9����˳�������ת��Ϊ��ʽ��������\t\t\t\t*" << endl;
		cout << "*10���������Һ���ָ�롣\t\t\t\t\t\t*" << endl;
		cout << "*\t\t\t\t\t\t\t\t*" << endl;
		cout << "*11�����ƶ�������\t\t\t\t\t\t*" << endl;
		cout << "*12�����ÿ��Ҷ�ӽ�㵽�����·����\t\t\t\t*" << endl;
		cout << "*13����α�����������\t\t\t\t\t\t*" << endl;
		cout << "*\t\t\t\t\t\t\t\t*" << endl;
		cout << "*0���˳�����\t\t\t\t\t\t\t*" << endl;
		cout << "*****************************************************************" << endl;
		cout << "������˵���ţ�\t";
		cin >> order;

		switch (order)
		{
		case 1:
			system("cls");
			//��һ�����**********************************************************
			cout << "��һ��ʵ�飨�ļ���bt151.btr����";
			createBiTree(BT, "bt151.btr");
			cout << endl << "���������\t";
			preTraverse(BT);
			cout << endl << "���������\t";
			inOrderTraverse(BT);
			cout << endl << "���������\t";
			postTraverse(BT);
			destoryTree(BT);
			cout << endl;
			//********************************************************************
			//�ڶ������**********************************************************
			cout << "�ڶ���ʵ�飨�ļ���bt21.btr����";
			createBiTree(BT, "bt21.btr");
			cout << endl << "���������\t";
			preTraverse(BT);
			cout << endl << "���������\t";
			inOrderTraverse(BT);
			cout << endl << "���������\t";
			postTraverse(BT);
			destoryTree(BT);
			cout << endl;
			//********************************************************************
			break;
		case 2:
			system("cls");
			//��һ�����**********************************************************
			cout << "��һ��ʵ�飨�ļ���bt151.btr����";
			cout << endl << "��Ӧ���������" << endl;
			createBiTree(BT, "bt151.btr");
			inOrderFloor(BT);
			destoryTree(BT);
			cout << endl;
			//********************************************************************
			//�ڶ������**********************************************************
			cout << "�ڶ���ʵ�飨�ļ���bt21.btr����";
			cout << endl << "��Ӧ���������" << endl;
			createBiTree(BT, "bt21.btr");
			inOrderFloor(BT);
			destoryTree(BT);
			cout << endl;
			//********************************************************************
			break;
		case 3:
			system("cls");
			//��һ�����**********************************************************
			cout << "��һ��ʵ�����ݣ����ļ���bt261.btr��" << endl;
			createBiTree(BT, "bt261.btr");
			cout << endl << "�������߶�Ϊ��" << getTreeHeight(BT) << endl;
			destoryTree(BT);
			//********************************************************************
			//�ڶ������**********************************************************
			cout << "�ڶ���ʵ�����ݣ����ļ���bt21.btr��" << endl;
			createBiTree(BT, "bt21.btr");
			cout << endl << "�������߶�Ϊ��" << getTreeHeight(BT) << endl;
			destoryTree(BT);
			//********************************************************************
			break;
		case 4:
			system("cls");
			//��һ�����**********************************************************
			cout << "��һ��ʵ�����ݣ����ļ���bt261.btr��" << endl;
			createBiTree(BT, "bt261.btr");
			cout << endl << "�����������Ϊ��" << getTreeNodes(BT) << endl;
			destoryTree(BT);
			//********************************************************************
			//�ڶ������**********************************************************
			cout << "�ڶ���ʵ�����ݣ����ļ���bt21.btr��" << endl;
			createBiTree(BT, "bt21.btr");
			cout << endl << "�����������Ϊ��" << getTreeNodes(BT) << endl;
			destoryTree(BT);
			//********************************************************************
			break;
		case 5:
			system("cls");
			//��һ�����**********************************************************
			cout << "��һ��ʵ�����ݣ����ļ���bt261.btr��" << endl;
			createBiTree(BT, "bt261.btr");
			cout << endl << "������Ҷ�ӽ����Ϊ��" << getTreeLeaves(BT) << endl;
			destoryTree(BT);
			//********************************************************************
			//�ڶ������**********************************************************
			cout << "�ڶ���ʵ�����ݣ����ļ���bt21.btr��" << endl;
			createBiTree(BT, "bt21.btr");
			cout << endl << "������Ҷ�ӽ����Ϊ��" << getTreeLeaves(BT) << endl;
			destoryTree(BT);
			//********************************************************************
			cout << endl;
			break;
		case 6:
			system("cls");
			//��һ�����**********************************************************
			cout << "��һ��ʵ�����ݣ����ļ���bt261.btr��" << endl;
			createBiTree(BT, "bt261.btr");
			cout << endl << "������2�Ƚ����Ϊ��" << getTreeTwoDegree(BT) << endl;
			destoryTree(BT);
			//********************************************************************
			//�ڶ������**********************************************************
			cout << "�ڶ���ʵ�����ݣ����ļ���bt21.btr��" << endl;
			createBiTree(BT, "bt21.btr");
			cout << endl << "������2�Ƚ����Ϊ��" << getTreeTwoDegree(BT) << endl;
			destoryTree(BT);
			//********************************************************************
			break;
		case 7:
			system("cls");
			//��һ�����**********************************************************
			cout << "��һ��ʵ�����ݣ����ļ���bt31.btr��";		//��ȡԪ����Ӧ��ϵ
			createBiTree(BT, "bt31.btr");
			cout << endl << "��1�β��������ݣ�a" << endl;
			if (!printFBNodes(BT, 'a')) cout << "Ԫ�ز���ʧ��";
			cout << endl << "��2�β��������ݣ�q" << endl;
			if (!printFBNodes(BT, 'q')) cout << "Ԫ�ز���ʧ��";
			cout << endl << "��3�β��������ݣ�n" << endl;
			if (!printFBNodes(BT, 'k')) cout << "Ԫ�ز���ʧ��";
			cout << endl << "��4�β��������ݣ�2" << endl;
			if (!printFBNodes(BT, '2')) cout << "Ԫ�ز���ʧ��";
			cout << endl << "��5�β��������ݣ�6" << endl;
			if (!printFBNodes(BT, '6')) cout << "Ԫ�ز���ʧ��";
			cout << endl;
			destoryTree(BT);
			//********************************************************************
			//�ڶ������**********************************************************
			cout << "�ڶ���ʵ�����ݣ����ļ���bt21.btr��";		//��ȡԪ����Ӧ��ϵ
			createBiTree(BT, "bt21.btr");
			cout << endl << "��1�β��������ݣ�a" << endl;
			if (!printFBNodes(BT, 'a')) cout << "Ԫ�ز���ʧ��";
			cout << endl << "��2�β��������ݣ�h" << endl;
			if (!printFBNodes(BT, 'h')) cout << "Ԫ�ز���ʧ��";
			cout << endl << "��3�β��������ݣ�p" << endl;
			if (!printFBNodes(BT, 'p')) cout << "Ԫ�ز���ʧ��";
			cout << endl << "��4�β��������ݣ�t" << endl;
			if (!printFBNodes(BT, 't')) cout << "Ԫ�ز���ʧ��";
			cout << endl << "��5�β��������ݣ�f" << endl;
			if (!printFBNodes(BT, 'f')) cout << "Ԫ�ز���ʧ��";
			cout << endl << "��6�β��������ݣ�z" << endl;
			if (!printFBNodes(BT, 'z')) cout << "Ԫ�ز���ʧ��";
			cout << endl;
			destoryTree(BT);
			//********************************************************************
			break;
		case 8:
			system("cls");
			//��һ�����**********************************************************
			cout << "��һ��ʵ�����ݣ����ļ���bt26.btr��";		//��ȡԪ�ز��
			createBiTree(BT, "bt26.btr");
			cout << endl << "��1�β��������ݣ�a" << endl;
			res = getNodeFloor(BT, 'a');
			if (res < 0) cout << "Ԫ�ز���ʧ��";
			else cout << "��ǰԪ�ز��Ϊ��" << res;
			cout << endl << "��2�β��������ݣ�n" << endl;
			res = getNodeFloor(BT, 'n');
			if (res < 0) cout << "Ԫ�ز���ʧ��";
			else cout << "��ǰԪ�ز��Ϊ��" << res;
			cout << endl << "��3�β��������ݣ�i" << endl;
			res = getNodeFloor(BT, 'i');
			if (res < 0) cout << "Ԫ�ز���ʧ��";
			else cout << "��ǰԪ�ز��Ϊ��" << res;
			cout << endl << "��4�β��������ݣ�s" << endl;
			res = getNodeFloor(BT, 's');
			if (res < 0) cout << "Ԫ�ز���ʧ��";
			else cout << "��ǰԪ�ز��Ϊ��" << res;
			cout << endl << "��5�β��������ݣ�v" << endl;
			res = getNodeFloor(BT, 'v');
			if (res < 0) cout << "Ԫ�ز���ʧ��";
			else cout << "��ǰԪ�ز��Ϊ��" << res;
			cout << endl << "��6�β��������ݣ�6" << endl;
			res = getNodeFloor(BT, '6');
			if (res < 0) cout << "Ԫ�ز���ʧ��";
			else cout << "��ǰԪ�ز��Ϊ��" << res;
			destoryTree(BT);									//���ٶ�����
			cout << endl;
			//********************************************************************
			cout << endl;
			//�ڶ������**********************************************************
			cout << "�ڶ���ʵ�����ݣ����ļ���bt21.btr��";		//��ȡԪ�ز��
			createBiTree(BT, "bt21.btr");
			cout << endl << "��1�β��������ݣ�a" << endl;
			res = getNodeFloor(BT, 'a');
			if (res < 0) cout << "Ԫ�ز���ʧ��";
			else cout << "��ǰԪ�ز��Ϊ��" << res;
			cout << endl << "��2�β��������ݣ�b" << endl;
			res = getNodeFloor(BT, 'b');
			if (res < 0) cout << "Ԫ�ز���ʧ��";
			else cout << "��ǰԪ�ز��Ϊ��" << res;
			cout << endl << "��3�β��������ݣ�l" << endl;
			res = getNodeFloor(BT, 'l');
			if (res < 0) cout << "Ԫ�ز���ʧ��";
			else cout << "��ǰԪ�ز��Ϊ��" << res;
			cout << endl << "��4�β��������ݣ�m" << endl;
			res = getNodeFloor(BT, 'm');
			if (res < 0) cout << "Ԫ�ز���ʧ��";
			else cout << "��ǰԪ�ز��Ϊ��" << res;
			cout << endl << "��5�β��������ݣ�u" << endl;
			res = getNodeFloor(BT, 'u');
			if (res < 0) cout << "Ԫ�ز���ʧ��";
			else cout << "��ǰԪ�ز��Ϊ��" << res;
			cout << endl << "��6�β��������ݣ�z" << endl;
			res = getNodeFloor(BT, 'z');
			if (res < 0) cout << "Ԫ�ز���ʧ��";
			else cout << "��ǰԪ�ز��Ϊ��" << res;
			destoryTree(BT);									//���ٶ�����
			cout << endl;
			//********************************************************************
			break;
		case 9:
			system("cls");
			//��һ�����**********************************************************
			cout << "��һ��ʵ�����ݣ�" << endl;					//��˳�������ת��Ϊ��ʽ������
			cout << "˳��洢��" << sBiTree_1;
			tranSeqToLink(BT, sBiTree_1);
			cout << endl << "���������\t";
			preTraverse(BT);
			cout << endl << "���������\t";
			inOrderTraverse(BT);
			cout << endl << "���������\t";
			postTraverse(BT);
			cout << endl;
			destoryTree(BT);
			BT = nullptr;
			//********************************************************************
			//�ڶ������**********************************************************
			cout << "�ڶ���ʵ�����ݣ�" << endl;					//��˳�������ת��Ϊ��ʽ������
			cout << "˳��洢��" << sBiTree_2;
			tranSeqToLink(BT, sBiTree_2);
			cout << endl << "���������\t";
			preTraverse(BT);
			cout << endl << "���������\t";
			inOrderTraverse(BT);
			cout << endl << "���������\t";
			postTraverse(BT);
			cout << endl;
			destoryTree(BT);
			BT = nullptr;
			//********************************************************************
			break;
		case 10:
			system("cls");
			//��һ�����**********************************************************
			cout << "��һ��ʵ�����ݣ����ļ���bt151.btr��";		//�������Һ���ָ��
			createBiTree(BT, "bt151.btr");
			cout << endl << "ԭ�ļ�����";
			preTraverse(BT);
			cout << endl << "ԭ�ļ�����";
			inOrderTraverse(BT);
			cout << endl << "ԭ�ļ�����";
			postTraverse(BT);
			exchangeChild(BT);
			cout << endl << "�������ļ�����";
			preTraverse(BT);
			cout << endl << "�������ļ�����";
			inOrderTraverse(BT);
			cout << endl << "�������ļ�����";
			postTraverse(BT);
			destoryTree(BT);
			BT = nullptr;
			cout << endl;
			//********************************************************************
			//�ڶ������**********************************************************
			cout << "�ڶ���ʵ�����ݣ����ļ���bt21.btr��";		//�������Һ���ָ��
			createBiTree(BT, "bt21.btr");
			cout << endl << "ԭ�ļ�����";
			preTraverse(BT);
			cout << endl << "ԭ�ļ�����";
			inOrderTraverse(BT);
			cout << endl << "ԭ�ļ�����";
			postTraverse(BT);
			exchangeChild(BT);
			cout << endl << "�������ļ�����";
			preTraverse(BT);
			cout << endl << "�������ļ�����";
			inOrderTraverse(BT);
			cout << endl << "�������ļ�����";
			postTraverse(BT);
			destoryTree(BT);
			BT = nullptr;
			cout << endl;
			//********************************************************************
			break;
		case 11:
			system("cls");
			//��һ�����**********************************************************
			cout << "��һ��ʵ�����ݣ����ļ���bt151.btr��" << endl;	//���ƶ�����
			createBiTree(BT, "bt151.btr");
			cout << endl << "ԭ�ļ�����";
			preTraverse(BT);
			cout << endl << "ԭ�ļ�����";
			inOrderTraverse(BT);
			cout << endl << "ԭ�ļ�����";
			postTraverse(BT);
			copyBiTree(BT, CT);
			cout << endl << "�����ļ�����";
			preTraverse(CT);
			cout << endl << "�����ļ�����";
			inOrderTraverse(CT);
			cout << endl << "�����ļ�����";
			postTraverse(CT);
			destoryTree(BT);
			destoryTree(CT);
			BT = nullptr;
			CT = nullptr;
			cout << endl;
			//********************************************************************
			//�ڶ������**********************************************************
			cout << "�ڶ���ʵ�����ݣ����ļ���bt21.btr��" << endl;	//���ƶ�����
			createBiTree(BT, "bt21.btr");
			cout << endl << "ԭ�ļ�����";
			preTraverse(BT);
			cout << endl << "ԭ�ļ�����";
			inOrderTraverse(BT);
			cout << endl << "ԭ�ļ�����";
			postTraverse(BT);
			copyBiTree(BT, CT);
			cout << endl << "�����ļ�����";
			preTraverse(CT);
			cout << endl << "�����ļ�����";
			inOrderTraverse(CT);
			cout << endl << "�����ļ�����";
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
			//��һ�����**********************************************************
			cout << "��һ��ʵ�����ݣ����ļ���bt261.btr��" << endl;	//���ÿ��Ҷ�ӽ�㵽�����·��
			createBiTree(BT, "bt261.btr");
			getLeavesPath(BT);
			destoryTree(BT);
			cout << endl;
			//********************************************************************
			//�ڶ������**********************************************************
			cout << "�ڶ���ʵ�����ݣ����ļ���bt21.btr��" << endl;	//���ÿ��Ҷ�ӽ�㵽�����·��
			createBiTree(BT, "bt21.btr");
			getLeavesPath(BT);
			destoryTree(BT);
			cout << endl;
			//********************************************************************
			break;
		case 13:
			system("cls");
			//��һ�����**********************************************************
			cout << "��һ��ʵ�����ݣ����ļ���bt261.btr��" << endl;	//��α���������
			createBiTree(BT, "bt261.btr");
			floorTraverse(BT);
			destoryTree(BT);
			cout << endl;
			//********************************************************************
			//�ڶ������**********************************************************
			cout << "�ڶ���ʵ�����ݣ����ļ���bt21.btr��" << endl;	//��α���������
			createBiTree(BT, "bt21.btr");
			floorTraverse(BT);
			destoryTree(BT);
			cout << endl;
			//********************************************************************
			break;
		case 0:
			cout << "�˳�����" << endl;
			return 0;
		default:
			system("cls");
			cout << "�������" << endl;
			break;
		}
	}

	return 0;
}