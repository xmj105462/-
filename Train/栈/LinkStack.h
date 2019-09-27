#pragma once
#ifndef LINK_STACK_H
#define LINK_STACK_H
namespace xmj{
#define MAX_SIZE 20
	/*
	******��ҵ˼·
	******����˫������
	*****ջ��ָ��ͷ�ڵ㣬ջ��ָ����ջ�Ľڵ㡣��ջ��ջ��ָ�����ýڵ㷴����ָ���۷�
	*/
	typedef int DateType;
	typedef struct DateLink {
		//DateType* date;
		DateType date;
		DateLink* front;
		DateLink* next;
		DateLink();
		/*DateLink(const DateLink& other);
		const DateLink& operator=(const DateLink& other);
		~DateLink();*/
	}DLhead;
	typedef DateLink* DateLink_ptr;
	typedef struct LinkStack {
		size_t length;
		DateLink_ptr top;		
		LinkStack();
	}LS;
	bool initLinkStack(LinkStack& linkStack, DLhead& head);
	bool pushLinkStack(LinkStack& linkStack, DateLink& dateNode, DLhead& head);
	bool popLinkStack(LinkStack& linkStack, DateLink& dateNode);
	size_t LinkStackCount(LinkStack& linkStack);
	bool deleteLinkStack(LinkStack& linkStack);
}

#endif // !LINK_STACK_H
