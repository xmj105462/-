#include"AllType2WayLoopQueue.h"
//inline void initAllType2WayLLN(AllType2WayLLN* ll1, AllType2WayH& lllh);
namespace allType2WayLoopQ{
	AllType2WayLoopQueue::AllType2WayLoopQueue() { 
		length = 0; qHead = nullptr; rear = nullptr; maxPriority = MAX_PRIORITY;
	}
	qNode::qNode() {
		next = nullptr; front = nullptr;
	}
	void addAllType2WayLoopQueue(qNode& qn, QnH& head, AllType2WayLoopQueue& lq) {
		if (head.next == nullptr || lq.qHead == nullptr) { head.next = &qn; lq.qHead = &qn; lq.length++; cout << "��ӳɹ�\n"; return; }
		qNode* p = head.next;
		while (1) {
			if (p->next == nullptr) {
				p->next = &qn;  break;
			}
			else {
				p = p->next;
			}
		}lq.rear = &qn; lq.length++;
		cout << "��ӳɹ�\n";/*if (lllh.p_next == &lllh || lllh.p_next == nullptr) {
		lllh.p_next = &ll1; ll1.p_front = &lllh;
		ll1.p_next = &lllh;//β��ͷ
		lllh.p_front = &ll1;
	}
	else {
		ll1.p_next = lllh.p_next; lllh.p_next->p_front = &ll1; ll1.p_front = &lllh;
		initAllType2WayLLN(lllh.p_next, lllh);
		lllh.p_next = &ll1;

	}*/
	}

	void subAllType2WayLoopQueue(AllType2WayLoopQueue& pq, QnH& head) {
		if (pq.qHead == nullptr) { cout << "�Ƴ�ʧ��\n"; return; }
		qNode* p = &head; qNode* tp = pq.qHead;
		qNode* dp = p->next;
		if (tp->next) {
			while (tp->next) {
				if (p->next->priority == pq.maxPriority)break;
				if ((p->next->priority) < (tp->next->priority)) {
					p = tp;
				}
				tp = tp->next;
			}
			dp = p->next;
			if (dp->next) {
				if (p->next == pq.qHead) {//��һ���ڵ����ȼ����,�����нڵ�
					pq.qHead = dp->next; cout << "��һ���ڵ㣨���У�";
				}
				else {
					cout << "�����ڵ㣨���У�";
				}
				p->next = dp->next;
			}
			else {
				pq.rear = p; p->next = nullptr; cout << "���ڵ�";
			}
		}
		else {
			if (p->next == pq.qHead) {//��һ���ڵ����ȼ����,�����޽ڵ�
				pq.qHead = nullptr; pq.rear = nullptr; p->next = nullptr; cout << "��һ���ڵ㣨���ޣ�";
			}
		}delete dp; cout << "�Ƴ��ɹ�\n";
		pq.length--;/*if (llh.p_next == NULL || i <= 0 || llh.p_next == &lllh) { cout << "�Ƴ�ʧ��\n"; return NULL; }
	size_t j = 2;
	AllType2WayLLN* p = llh.p_next;
	while ((p) != &lllh || p != nullptr) {
		if (i == 1) {
			if (p) {
				AllType2WayLLN* tp = p->p_next;
				llh.p_next = p->p_next; tp->p_front = &llh;
				  cout << "�Ƴ��ɹ�\n"; return tp;
			}
		}
		else if (j == i) {
			if (p->p_next == nullptr || p->p_next == &lllh) { cout << "�Ƴ�ʧ��\n"; return NULL; }
			AllType2WayLLN* tp = (*(p)).p_next->p_next;
			AllType2WayLLN* tp1 = (*(p)).p_next;
			p->p_next = tp; tp->p_front = p;
			   cout << "�Ƴ��ɹ�\n"; return tp;
		}
		else if (j < i) {
			if ((*(p)).p_next == NULL || (*(p)).p_next == &lllh) {
				cout << "�Ƴ�ʧ��\n"; return NULL;
			}
			p = (*(p)).p_next; j++;
		}
	}cout << "�Ƴ�ʧ��\n";
	return nullptr;*/
	}

	bool deleteAllType2WayLoopQueue(AllType2WayLoopQueue& lq, QnH head) {
		if (head.next == NULL || lq.qHead == nullptr) { cout << "û��Ԫ��ɾ��ʧ��,���ͷ�ڵ��ڶ����������\n"; return false; }
		qNode* p;
		p = head.next;
		while (p) {
			qNode* tp = p;
			p = p->next;
			delete tp;
		}head.next = NULL; lq.qHead = nullptr; lq.rear = nullptr;
		cout << "ɾ���ɹ�\n"; return true;
	}

	qNode** findQn(AllType2WayLoopQueue& llh, Date date) {
		if (llh.qHead == NULL) { cout << "����ʧ��\n"; return NULL; }
		qNode* p; qNode** pArr = new qNode * [FIND_COUNT](); int count = 0;
		p = llh.qHead;
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
		}/*if (llh.p_next == NULL || llh.p_next == &llh) { cout << "����ʧ��\n"; return NULL; }
	AllType2WayLLN* p; AllType2WayLLN** pArr = new AllType2WayLLN * [FIND_COUNT](); int count = 0;
	p = llh.p_next;
	while (p != &llh) {
		////if (*(p->date) == i) {
		//	cout << "���ҳɹ�\t���ڽڵ��ַΪ" << p << endl; pArr[count] = p; count++;
		//	p = p->p_next;
		////}
		//else {
		//	p = p->p_next;
		//}
	}if (pArr[0]) {
		return pArr;
	}
	else {
		cout << "����ʧ��\n"; return nullptr;
	}*/
	}

	void printfAllType2WayLoopQueue(AllType2WayLoopQueue& lq) {
		if (!lq.qHead) {
			cout << "����Ϊ��"; return;
		}
		qNode* qn = lq.qHead;
		cout << lq.qHead->date << "\tqHead���ȼ���" << lq.qHead->priority << endl;
		cout << lq.rear->date << "\trear���ȼ���" << lq.rear->priority << endl;
		for (int i = 0; i < lq.length; i++) {
			cout << qn->date << "���ȼ���" << qn->priority << "\t";
			qn = qn->next;
		}/*if (llh.p_next == NULL || llh.p_next == &llh) { cout << "���ʧ��\n"; return; }
	AllType2WayLLN* p;
	p = llh.p_next;
	while (p != &llh) {
		cout << *((int*)(((int)p)-4)) << "\t";
		p = p->p_next;
	}cout << "��������ɹ�\n";
	p = llh.p_front;
	while (p != &llh) {
		cout << *((int*)(((int)p) - 4)) << "\t";
		p = p->p_front;
	}cout << "��������ɹ�\n";*/
	}
}
//inline void initAllType2WayLLN(AllType2WayLLN* ll1, AllType2WayH& llh) {
//	if (ll1->p_next == nullptr) {
//		ll1->p_next = &llh;
//		llh.p_front = ll1;
//	}
//}
