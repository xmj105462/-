#pragma once
#pragma once
#include<stdio.h> 
#include<stdlib.h> 
#include<string>
#include <iostream> 
#define MAXSIZE 100 
#define MaxSize 128 //Ԥ�ȷ���ռ䣬�����ֵ����ʵ����ҪԤ��ȷ�� 
using namespace std;
typedef int ElemType;
typedef struct _SqStack {
	ElemType* base; //ջ��ָ��
	ElemType* top; //ջ��ָ�� 
}SqStack;
bool InitStack(SqStack& S) //����һ����ջ S
{
	S.base = new ElemType[MaxSize];//Ϊ˳��ջ����һ���������Ϊ Maxsize �Ŀռ�
	if (!S.base)return false; //�ռ����ʧ�� 		 
	S.top = S.base;
	//top ��ʼΪ base����ջ 
	return true;
}
bool isLarger(const int& lhs, const int& rhs);
int operate(int left, int right, int op);
bool PushStack(SqStack& S, ElemType e)
// ����Ԫ�� e Ϊ�µ�ջ��Ԫ�� 
{
	if (S.top - S.base == MaxSize)return false; //ջ�� 
	*(S.top) = e; //Ԫ�� e ѹ��ջ����Ȼ��ջ��ָ��� 1���ȼ���*S.top=e; 
	++S.top; return true;
}
bool PopStack(SqStack& S, ElemType& e) //ɾ�� S ��ջ��Ԫ�أ��ݴ��ڱ��� e ��
{
	if (S.base == S.top) { //ջ�� 
		return false;
	}e = *(--S.top); //ջ��ָ��� 1����ջ��Ԫ�ظ��� e 
	return true;
}
ElemType* GetTop(SqStack& S) //���� S ��ջ��Ԫ�أ�ջ��ָ�벻�� 
{
	if (S.top != S.base) { //ջ�ǿ�
		return S.top - 1; //����ջ��Ԫ�ص�ֵ��ջ��ָ�벻��
	}
	else { return NULL; }
}
int GetSize(SqStack& S) {//����ջ��Ԫ�ظ��� 
	return (S.top - S.base);
}
bool IsEmpty(SqStack& S) {//�ж�ջ�Ƿ�Ϊ�� 
	if (S.top == S.base) { return true; }
	else { return false; }
}
void DestoryStack(SqStack& S) {//����ջ 
	if (S.base) { free(S.base); S.base = NULL; S.top = NULL; }
}

bool isLarger(const int& lhs, const int& rhs) {//�Ƚ� lhs �����ȼ��Ƿ񲻸��� rhs��rhs ��ʾջ���ķ��� 
	if ((rhs == '+' || rhs == '-') && (lhs == '*' || lhs == '/')) {
		return true;
	}
	return false;
}
int operate(int left, int right, int op)//���������ֵ
{
	int result = 0; cout << "left:" << left << (char)op << " right:" << right  << endl;
	switch (op) {
	case '+': result = left + right; break;
	case '-': result = left - right; break;
	case '*': result = left * right; break;
	case '/': result = left / right; break;
	default: break;
	}
	cout << "result: " << result << endl;
	return result;
}
int calculate(string input) {
	SqStack data_stack;//��������ջ
	SqStack opt_stack; //�������ջ 
	int status = 0; //0-����������� 1-��������� "+-*/" 2-�����Ҳ����� 
	int ldata = 0, rdata = 0; char last_opt = '\0';

	InitStack(data_stack); InitStack(opt_stack);//��ʼ��ջ���������Ͳ����� 
	for (size_t i = 0; i < input.length(); i++) {
		if (isspace(input[i])) continue;//�ո���Ⱥ��Ե� 
		switch (status) {
		case 0: if (isdigit(input[i])) { //�����0-9֮��������ͷ��ط�0����ֵ�����򷵻�0
			ldata *= 10; ldata += input[i] - '0';
		}
				else {
			cout << "�õ��������:" << ldata << endl; PushStack(data_stack, ldata);//���������ջ 
			i--; status = 1;//�������������ǰһ��������
		}
				break;
		case 1:
			if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/') {
				if (IsEmpty(opt_stack)) {//��һ�������,��ʱ�����κδ����� �������ջ���� 
					cout << "����ջΪ��" << endl; PushStack(opt_stack, input[i]);//��������ջ 
					cout << "����" << (char)input[i] << "��ջ" << endl; status = 2;
				}
				else {//�ǵ�һ�������������֮ǰ��������Ƚ����ȼ� 
					cout << "��ǰ����ջ���:" << (char)(*GetTop(opt_stack)) << " &�Ա��·��� " << input[i] << endl;
					if (isLarger(input[i], *GetTop(opt_stack))) {//��������Ƿ��ǰһ����
						cout << "true" << endl; PushStack(opt_stack, input[i]);//��������ջ 
						cout << "����" << (char)input[i] << "��ջ" << endl; status = 2; rdata = 0;
					}
					else {//��ǰ����������ȼ�������ǰһ�������������� ǰһ���������ֵ 
						int left = 0, right = 0;
						int opt;
						cout << "false" << endl;
						do {
							PopStack(data_stack, right);
							PopStack(data_stack, left); PopStack(opt_stack, opt);
							cout << "����" << (char)opt << "��ջ" << endl;
							cout << "����ǰһ�������" << (char)opt << endl;
							int result = operate(left, right, opt);
							PushStack(data_stack, result);
						}
						while (!IsEmpty(opt_stack) && !isLarger(input[i], *GetTop(opt_stack)));
						PushStack(opt_stack, input[i]);
						cout << "����" << (char)input[i] << "��ջ" << endl;
						status = 2; rdata = 0;
					}
				}
			}
			else if (input[i] == '=') {//������ 
				int opt, result;
				do {
					PopStack(data_stack, rdata);
					PopStack(data_stack, ldata);
					PopStack(opt_stack, opt);
					result = operate(ldata, rdata, opt);
					PushStack(data_stack, result);
				}
				while (!IsEmpty(opt_stack)); return result;
			}
			else { cerr << "�������������" << endl; }break;
		case 2: if (isdigit(input[i])) { rdata *= 10; rdata += input[i] - '0'; }
				else {
			cout << "�õ��Ҳ�����:" << rdata << endl; PushStack(data_stack, rdata);//�Ҳ�������ջ 
			i--;
			status = 1;
		}break;
		}
	}return -1;//���Ľ��Ϊջ��Ԫ��
}
