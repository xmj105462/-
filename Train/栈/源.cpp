//#include<iostream>
//#include"SqStack.h"
//#include"SqStack2.h"
//#include"LinkStack.h"
//#include<string>
#include "exp.h"
//using namespace std;
//using namespace xmj;
//#include"Man.h"
//#include"Maze.h"
//#include"expression.h"
int main() {
	//�Թ�
	/*initFrame();
	LinkStack ls; DLhead head;
	initLinkStack(ls, head);
	initPosition(head, ls);
	move(ls, head);*/
	//���ʽ��ֵ
	string str = "12+3*6/3+4*5="; //int ldate = 0;
	//for (size_t i = 0; i < str.length(); i++) {
	//	//cout<< isdigit(str[i])<<"\t";
	//	if (isdigit(str[i])) {
	//		cout << "ldateǰ==" << ldate << endl;
	//		ldate *= 10; 
	//		cout << "ldate��==" << ldate  << endl;
	//		ldate += str[i] - '0';
	//		cout << "str[i]- '0' ==" << (int)(str[i] - '0') << endl;
	//		cout << "ldate��==" << ldate << endl;
	//	}
	//	else {
	//		cout << "�õ��������:" << ldate << endl; //PushStack(data_stack, ldata);//���������ջ 
	//		//i--; //status = 1;
	//	}
	//}
	cout << calculate(str) << endl;
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
	/*LinkStack ls; DLhead head;
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
	}*/
	/*string s1; string s2 = "sfasdf";
	memcpy(&s1,&s2,sizeof(s2));
	cout << s1;*/
	system("pause");
	return 0;
}