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

bool myCompare(ListNode* A,ListNode* B)
{
	return A->val < B->val;
}

ListNode* mergeKLists(vector<ListNode*>& lists) 
{
	ListNode* head = NULL;
	ListNode* tail = NULL;

	vector<ListNode*> newLists;
	for (int i=0;i<lists.size();i++)
	{
		if (lists[i])
		{
			newLists.push_back(lists[i]);
		}
	}

	sort(newLists.begin(),newLists.end(),myCompare);

	while (newLists.size()>0)
	{
		if (head == NULL)
		{
			head = newLists[0];
			tail = head;
			newLists[0] = tail->next;
		}
		else
		{
			tail->next = newLists[0];
			tail = tail->next;
			newLists[0] = tail->next;

		}

		if (newLists[0] == NULL)
		{
			newLists.erase(newLists.begin());
		}
		else
		{
			for (int i=0;i<(int)newLists.size()-1 && newLists[i]->val>newLists[i+1]->val;i++)
			{
				ListNode* tmp = newLists[i];
				newLists[i] = newLists[i+1];
				newLists[i+1] = tmp;
			}
		}
	}

	return head;


}

int main()
{
	int N;
	cin>>N;
	vector<ListNode*> lists;

	for (int i=0;i<N;i++)
	{
		lists.push_back(createList());
	}


	ListNode* l1 = mergeKLists(lists);

	printList(l1);

	destroyList(l1);

	int tmp;
	cin>>tmp;
	return 1;
}