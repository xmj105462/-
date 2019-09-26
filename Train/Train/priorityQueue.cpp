#include"PriorityQueue.h"
 namespace priorityQ{
	 PriorityQueue::PriorityQueue() {
		 length = 0; front = nullptr; rear = nullptr; maxPriority = MAX_PRIORITY;
	 }
	 qNode::qNode() {
		 date = 0; next = nullptr; priority = 0;
	 }
	 void addPriorityQueue(qNode& qn, QnH& head, PriorityQueue& lq) {
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


	 void subPriorityQueue(PriorityQueue& pq, QnH& head) {
		 if (pq.front == nullptr) { cout << "�Ƴ�ʧ��\n"; return; }
		 qNode* p = &head; qNode* tp = pq.front;
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
				 if (p->next == pq.front) {//��һ���ڵ����ȼ����,�����нڵ�
					 pq.front = dp->next; cout << "��һ���ڵ㣨���У�";
				 }
				 else {
					 cout << "�����ڵ㣨���У�";
				 }
				 p->next = dp->next;  
			 }
			 else {
				 
				 //else {//���ڵ����ȼ����
					 pq.rear = p; p->next = nullptr; cout << "���ڵ�";
				// }

			 }
			 
		 }
		 else {
			 if (p->next == pq.front) {//��һ���ڵ����ȼ����,�����޽ڵ�
				 pq.front = nullptr; pq.rear = nullptr; p->next = nullptr; cout << "��һ���ڵ㣨���ޣ�";
			 }
		 }delete dp; cout << "�Ƴ��ɹ�\n";
		 pq.length--;
	 }

	 bool deletePriorityQueue(PriorityQueue& lq, QnH head) {
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

	 qNode** findQn(PriorityQueue& llh, Date date) {
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

	 void printfPriorityQueue(PriorityQueue& lq) {
		 if (!lq.front) {
			 cout << "����Ϊ��"; return;
		 }
		 qNode* qn = lq.front;
		 cout << lq.front->date << "\tfront���ȼ���" << lq.front->priority << endl;
		 cout << lq.rear->date << "\trear���ȼ���" << lq.rear->priority << endl;
		 for (int i = 0; i < lq.length; i++) {
			 cout << qn->date << "���ȼ���"<<qn->priority<<"\t";
			 qn = qn->next;
		 }
	 }
 }

