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
	//迷宫
	/*initFrame();
	LinkStack ls; DLhead head;
	initLinkStack(ls, head);
	initPosition(head, ls);
	move(ls, head);*/
	//表达式求值
	string str = "12+3*6/3+4*5="; //int ldate = 0;
	//for (size_t i = 0; i < str.length(); i++) {
	//	//cout<< isdigit(str[i])<<"\t";
	//	if (isdigit(str[i])) {
	//		cout << "ldate前==" << ldate << endl;
	//		ldate *= 10; 
	//		cout << "ldate中==" << ldate  << endl;
	//		ldate += str[i] - '0';
	//		cout << "str[i]- '0' ==" << (int)(str[i] - '0') << endl;
	//		cout << "ldate后==" << ldate << endl;
	//	}
	//	else {
	//		cout << "得到左操作数:" << ldate << endl; //PushStack(data_stack, ldata);//左操作数入栈 
	//		//i--; //status = 1;
	//	}
	//}
	cout << calculate(str) << endl;
	/*SQ_S sqs;
	initSqStack(sqs, MAX_SIZE);
	for (size_t i = 0; i <= MAX_SIZE; i++) {
		if (pushSqStack(sqs, i + 1)) {
			cout <<"进栈"<< *(sqs.top - 1) << "\t";
		}
		else {
			cout << "进栈失败\n";
		}
	}cout << "栈中元素个数:" << sqStackCount(sqs)<<endl;
	for (size_t i = 0; i <= MAX_SIZE; i++) {
		DateType popDate = 0;
		if (popSqStack(sqs, popDate)) {
			cout <<"弹出"<< popDate << "\t";
		}
		else {
			cout << "弹出失败\n";
		}
	}
	cout << "栈中元素个数:" << sqStackCount(sqs)<<endl;
	if (deleteSqStack(sqs)) {
		cout << "删除栈成功";
	}
	else {
		cout << "删除栈失败";
	}*/
	//作业1，栈顶用int
	/*SQ_S2 sqs2;
	initSqStack2(sqs2, MAX_SIZE);
	for (size_t i = 0; i <= MAX_SIZE; i++) {
		if (pushSqStack2(sqs2, i + 1)) {
			cout << "进栈" << *(sqs2.base+(sqs2.top - 1)) << "\t";
		}
		else {
			cout << "进栈失败\n";
		}
	}cout << "栈中元素个数:" << sqStackCount2(sqs2) << endl;
	for (size_t i = 0; i <= MAX_SIZE; i++) {
		DateType popDate = 0;
		if (popSqStack2(sqs2, popDate)) {
			cout << "弹出" << popDate << "\t";
		}
		else {
			cout << "弹出失败\n";
		}
	}
	cout << "栈中元素个数:" << sqStackCount2(sqs2) << endl;
	if (deleteSqStack2(sqs2)) {
		cout << "删除栈成功";
	}
	else {
		cout << "删除栈失败";
	}*/
	//作业2，链式栈
	/*LinkStack ls; DLhead head;
	initLinkStack(ls, head);
	for (size_t i = 0; i <= MAX_SIZE; i++) {
		DateLink *dateNode = new DateLink();
		dateNode->date = i + 1;
		if (pushLinkStack(ls, *dateNode,head)) {
			cout << "进栈" << (ls.top)->date << "\t";
		}
		else {
			cout << "进栈失败\n";
		}
	}cout << "栈中元素个数:" << LinkStackCount(ls) << endl;
	for (size_t i = 0; i <= MAX_SIZE; i++) {
		DateLink popDate ;
		if (popLinkStack(ls, popDate)) {
			cout << "弹出" << popDate.date << "\t";
		}
		else {
			cout << "弹出失败\n";
		}
	}
	cout << "栈中元素个数:" << LinkStackCount(ls) << endl;
	if (deleteLinkStack(ls)) {
		cout << "删除栈成功";
	}
	else {
		cout << "删除栈失败";
	}*/
	/*string s1; string s2 = "sfasdf";
	memcpy(&s1,&s2,sizeof(s2));
	cout << s1;*/
	system("pause");
	return 0;
}