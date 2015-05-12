#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* createList()
{
	ListNode* head=NULL;
	ListNode* curL;
	int n;

	cin>>n;

	for (int i=0;i<n;i++)
	{
		int input;
		cin>>input;
		if (head==NULL)
		{
			head=new ListNode(input);
			curL=head;
		}
		else
		{
			curL->next=new ListNode(input);
			curL=curL->next;
		}
	}

	return head;
}

void printList(ListNode* head)
{
	ListNode* curL=head;

	while (curL!=NULL)
	{
		cout<<curL->val<<" ";
		curL=curL->next;
	}
	cout<<endl;
}

void destroyList(ListNode* head)
{
	ListNode* curL=head;

	while (curL!=NULL)
	{
		ListNode* tmpL=curL;
		curL=curL->next;
		delete tmpL;
	}
}

ListNode* reverseKGroup(ListNode* head, int k) 
{
	ListNode* tail = head;
	int len = 0;

	if (k<2)
	{
		return head;
	}

	while (tail)
	{
		tail = tail->next;
		len++;
	}

	int itrNum = len/k;
	if (itrNum<1)
	{
		return head;
	}

	
	ListNode* p1 = head;
	ListNode* p2 = head;
	ListNode* p3 = head;

	tail = NULL;
	for (int i=0;i<itrNum;i++)
	{
		ListNode* newHead;
		ListNode* tailRecord;

		tailRecord = p3;
		p1 = p3;
		p2 = p1->next;

		for (int j=0;j<k-1;j++)
		{
			p3 = p2->next;
			p2->next = p1;
			p1 = p2;
			p2 = p3;
			newHead = p1;
		}

		if (tail)
		{
			tail->next = newHead;
		}
		else
		{
			head = newHead;
		}

		tail = tailRecord;
	}
	tail->next = p3;

	return head;
}

int main()
{

	ListNode* l1 = createList();


	l1 = reverseKGroup(l1,3);

	printList(l1);

	destroyList(l1);

	int tmp;
	cin>>tmp;
	return 1;
}