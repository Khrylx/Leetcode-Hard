#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

struct charIndex
{
	char c;
	int index;
	charIndex(char _c,int _index) : c(_c),index(_index){};
};

int longestValidParentheses(string s) 
{
	int maxLen = 0;

	stack<charIndex> S;
	S.push(charIndex(')',-1));

	for (int i=0;i<s.length();i++)
	{
		if (s[i] == ')')
		{
			if (S.top().c == '(')
			{
				S.pop();
				int len = i - S.top().index;
				maxLen = max(maxLen,len);
			}
			else
				S.push(charIndex(')',i));
		}
		if (s[i] == '(')
		{
			S.push(charIndex('(',i));
		}
	}

	return maxLen;
}

int main()
{
	
	int num = longestValidParentheses(")()())");

	return 1;
}