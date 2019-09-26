#include"LinkQueue.h"
#include<iostream>
constexpr auto FIND_COUNT = 10;
using namespace std;
//using namespace linkQ;
namespace linkQ {
	qNode::qNode() {
		date = 0; next = nullptr;
	}

	LinkQueue::LinkQueue() {
		length = 0; front = nullptr; rear = nullptr;
	}

	void addLinkQueue(qNode& qn, QnH& head, LinkQueue& lq) {
		if (head.next == nullptr || lq.front == nullptr) { head.next = &qn; lq.front = &qn; lq.length++; cout << "��ӳɹ�\n"; return; }
		qNode* p = head.next;
		while (1) {
			if (p->next == nullptr) {
				p->next = &qn;  break;
			}
			else {
				p = p->next;
			}
		}lq.rear = &qn; lq.length++;
		cout << "��ӳɹ�\n";
	}

	void subLinkQueue(LinkQueue& lq, QnH& head) {
		if (lq.front == nullptr) { cout << "�Ƴ�ʧ��\n"; return; }
		qNode* tp = head.next;
		if (tp->next) {
			head.next = tp->next; lq.front = tp->next;
			delete tp; cout << "�Ƴ��ɹ�\n";
		}

		else {
			lq.rear = nullptr; lq.rear = nullptr;
			head.next = nullptr; delete tp; cout << "�Ƴ��ɹ�\n";
		}
		lq.length--;

	}

	bool deleteLinkQueue(LinkQueue& lq, QnH head) {
		if (head.next == NULL || lq.front == nullptr) { cout << "û��Ԫ��ɾ��ʧ��,���ͷ�ڵ��ڶ����������\n"; return false; }
		qNode* p;
		p = head.next;
		while (p) {
			qNode* tp = p;
			p = p->next;
			delete tp;
		}head.next = NULL; lq.front = nullptr; lq.rear = nullptr;
		cout << "ɾ���ɹ�\n"; return true;
	}

	qNode** findQn(LinkQueue& llh, Date date) {
		if (llh.front == NULL) { cout << "����ʧ��\n"; return NULL; }
		qNode* p; qNode** pArr = new qNode * [FIND_COUNT](); int count = 0;
		p = llh.front;
		while (p) {
			if ((p->date) == date) {
				cout << "���ҳɹ�\t���ڽڵ��ַΪ" << p << endl; pArr[count] = p; count++;
				p = p->next;
				//continue;
			}
			else {
				p = p->next;
			}
		}if (pArr[0]) {
			return pArr;
		}
		else {
			cout << "����ʧ��\n"; return NULL;
		}
	}

	void printfLinkQueue(LinkQueue& lq) {
		if (!lq.front) {
			cout << "����Ϊ��"; return;
		}
		qNode* qn = lq.front;
		for (int i = 0; i < lq.length; i++) {
			cout << qn->date << "\t";
			qn = qn->next;
		}
	}
}

