#include<iostream>
//#include"SqStack.h"
//#include"SqStack2.h"
#include"LinkStack.h"
using namespace std;
using namespace xmj;

int main() {
	/*SQ_S sqs;
	initSqStack(sqs, MAX_SIZE);
	for (size_t i = 0; i <= MAX_SIZE; i++) {
		if (pushSqStack(sqs, i + 1)) {
			cout <<"��ջ"<< *(sqs.top - 1) << "\t";
		}
		else {
			cout << "��ջʧ��\n";
		}
	}cout << "ջ��Ԫ�ظ���:" << sqStackCount(sqs)<<endl;
	for (size_t i = 0; i <= MAX_SIZE; i++) {
		DateType popDate = 0;
		if (popSqStack(sqs, popDate)) {
			cout <<"����"<< popDate << "\t";
		}
		else {
			cout << "����ʧ��\n";
		}
	}
	cout << "ջ��Ԫ�ظ���:" << sqStackCount(sqs)<<endl;
	if (deleteSqStack(sqs)) {
		cout << "ɾ��ջ�ɹ�";
	}
	else {
		cout << "ɾ��ջʧ��";
	}*/
	//��ҵ1��ջ����int
	/*SQ_S2 sqs2;
	initSqStack2(sqs2, MAX_SIZE);
	for (size_t i = 0; i <= MAX_SIZE; i++) {
		if (pushSqStack2(sqs2, i + 1)) {
			cout << "��ջ" << *(sqs2.base+(sqs2.top - 1)) << "\t";
		}
		else {
			cout << "��ջʧ��\n";
		}
	}cout << "ջ��Ԫ�ظ���:" << sqStackCount2(sqs2) << endl;
	for (size_t i = 0; i <= MAX_SIZE; i++) {
		DateType popDate = 0;
		if (popSqStack2(sqs2, popDate)) {
			cout << "����" << popDate << "\t";
		}
		else {
			cout << "����ʧ��\n";
		}
	}
	cout << "ջ��Ԫ�ظ���:" << sqStackCount2(sqs2) << endl;
	if (deleteSqStack2(sqs2)) {
		cout << "ɾ��ջ�ɹ�";
	}
	else {
		cout << "ɾ��ջʧ��";
	}*/
	//��ҵ2����ʽջ
	LinkStack ls; DLhead head;
	initLinkStack(ls, head);
	for (size_t i = 0; i <= MAX_SIZE; i++) {
		DateLink *dateNode = new DateLink();
		dateNode->date = i + 1;
		if (pushLinkStack(ls, *dateNode,head)) {
			cout << "��ջ" << (ls.top)->date << "\t";
		}
		else {
			cout << "��ջʧ��\n";
		}
	}cout << "ջ��Ԫ�ظ���:" << LinkStackCount(ls) << endl;
	for (size_t i = 0; i <= MAX_SIZE; i++) {
		DateLink popDate ;
		if (popLinkStack(ls, popDate)) {
			cout << "����" << popDate.date << "\t";
		}
		else {
			cout << "����ʧ��\n";
		}
	}
	cout << "ջ��Ԫ�ظ���:" << LinkStackCount(ls) << endl;
	if (deleteLinkStack(ls)) {
		cout << "ɾ��ջ�ɹ�";
	}
	else {
		cout << "ɾ��ջʧ��";
	}
	system("pause");
	return 0;
}