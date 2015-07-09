#include <vector>
#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>
#include <unordered_set>

using namespace std;
struct ListNode {
	 int key;
     int val;
     ListNode *next;
	 ListNode *prev;
     ListNode(int x, int y) : key(x), val(y), next(NULL), prev(NULL) {}
 };

class LRUCache{

typedef unordered_map<int,ListNode*> ListMap;

private:
	ListMap listMap;
	ListNode* head;
	ListNode* tail;
	int capacity;

public:
	LRUCache(int capacity) {
		this->capacity = capacity;
		head = NULL;
		tail = NULL;
	}

	int get(int key) {
		unordered_map<int,ListNode*>::iterator itr = listMap.find(key);
		if (itr == listMap.end())
		{
			return -1;
		}
		else
		{
			ListNode* node = itr->second;
			if (node != head)
			{
				if (node == tail)
					tail = node->prev;
				if (node->prev)
					node->prev->next = node->next;
				if (node->next)
					node->next->prev = node->prev;
				node->next = head;
				node->prev = NULL;
				head->prev = node;
				head = node;
			}
			return node->val;
		}
	}

	void set(int key, int value){
		unordered_map<int,ListNode*>::iterator itr = listMap.find(key);
		if (itr == listMap.end())
		{
			int lSize = listMap.size();
			if (lSize == 0)
			{
				ListNode* node = new ListNode(key,value);
				head = node;
				tail = node;
				listMap.insert(pair<int,ListNode*>(key,node));
			}
			else if (lSize < capacity)
			{
				ListNode* node = new ListNode(key,value);
				node->next = head;
				head->prev = node;
				head = node;
				listMap.insert(pair<int,ListNode*>(key,node));
			}
			else
			{
				listMap.erase(tail->key);
				listMap.insert(pair<int,ListNode*>(key,tail));
				tail->val = value;
				tail->key = key;
				if (capacity > 1)
				{
					tail->next = head;
					head->prev = tail;
					head = tail;
					tail = tail->prev;
					tail->next = NULL;
					head->prev = NULL;
				}
			}
		}
		else
		{
			ListNode* node = itr->second;
			node->val = value;
			if (node != head)
			{
				if (node == tail)
					tail = node->prev;
				if (node->prev)
					node->prev->next = node->next;
				if (node->next)
					node->next->prev = node->prev;
				node->next = head;
				node->prev = NULL;
				head->prev = node;
				head = node;
			}
		}
	}


	/*void set(int key, int value) {
		
		int lSize = listMap.size();
		if (lSize == 0 )
		{
			ListNode* node = new ListNode(key,value);
			head = node;
			tail = node;
			listMap.insert(pair<int,ListNode*>(key,node));
		}
		else if (lSize < capacity)
		{
			unordered_map<int,ListNode*>::iterator itr = listMap.find(key);
			if (itr == listMap.end())
			{
				ListNode* node = new ListNode(key,value);
				node->next = head;
				head->prev = node;
				head = node;
				listMap.insert(pair<int,ListNode*>(key,node));
			}
			else
			{
				ListNode* node = itr->second;
				node->val = value;
				if (node == tail && lSize > 1)
					tail = node->prev;
				if (node->prev)
					node->prev->next = node->next;
				if (node->next)
					node->next->prev = node->prev;
				node->next = head;
				node->prev = NULL;
				head->prev = node;
				head = node;
			}

		}
		else
		{
			unordered_map<int,ListNode*>::iterator itr = listMap.find(key);
			if (itr == listMap.end())
			{
				listMap.erase(tail->key);
				listMap.insert(pair<int,ListNode*>(key,tail));
				tail->val = value;
				tail->key = key;
				if (capacity > 1)
				{
					tail->next = head;
					head->prev = tail;
					head = tail;
					tail = tail->prev;
					tail->next = NULL;
				}
			}
			else
			{
				ListNode* node = itr->second;
				node->val = value;
				if (node == tail)
					tail = node->prev;
				if (node->prev)
					node->prev->next = node->next;
				if (node->next)
					node->next->prev = node->prev;
				node->next = head;
				node->prev = NULL;
				head->prev = node;
				head = node;
			}
		}
	}*/
};


int main()
{
	LRUCache cache(5);
	cache.set(1,101);
	cache.set(2,102);
	cache.set(3,103);
	cache.set(4,104);
	cache.set(5,105);
	cache.set(2,109);
	cache.set(6,106);
	cout << cache.get(2) <<endl;
	return 1;
}