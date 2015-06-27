#include <vector>
#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/*void ladderLengthHelper(unordered_set<string>& S, unordered_map<string,vector<string>>& M, unordered_set<string>& wordDict, string& endWord)
{
	unordered_set<string> newS;
	bool find = false;

	for (unordered_set<string>::const_iterator itr = S.begin(); itr != S.end(); itr++)
	{
		string word = *itr;
		for (int i = 0; i < itr->length(); i++)
		{
			char oldC = word[i];
			for (char c = 'a'; c <= 'z'; c++)
			{
				if (c == oldC)
					continue;
				word[i] = c;

				int type = 0;
				if (word == endWord)
				{
					type = 1;
					find = true;
				}
				if (wordDict.count(word))
				{
					type = 2;
					newS.insert(word);
				}
				if ( type > 0)
				{
					unordered_map<string,vector<string>>::iterator mItr = M.find(word); 
					if (mItr == M.end())
					{
						M.insert(pair<string,vector<string>>(word,vector<string>()));
						M[word].push_back(*itr);
					}
					else
					{
						mItr->second.push_back(*itr);
					}
				}
			}
			word[i] = oldC;

		}
	}

	S = newS;
	for (unordered_set<string>::const_iterator itr = S.begin(); itr != S.end(); itr++)
	{
		wordDict.erase(*itr);
	}

	if (find || S.empty())
	{
		return;
	}
	ladderLengthHelper(S,M,wordDict,endWord);
}*/

void ladderLengthHelper(unordered_set<string>& s1, unordered_set<string>& s2, unordered_set<string>& wordDict, unordered_map<string,vector<string>>& M, bool front, bool& find)
{
	if (s1.empty())
		return ;

	unordered_set<string> s3;

	for (unordered_set<string>::const_iterator itr = s1.begin(); itr != s1.end(); itr++)
	{
		string word = *itr;
		for (int i = 0; i < itr->length(); i++)
		{
			char oldC = word[i];
			for (char c = 'a'; c <= 'z'; c++)
			{
				if (c == oldC)
					continue;
				word[i] = c;

				bool flag = false;
				if (s2.count(word))
				{
					find = true;
					flag = true;
				}
				if (wordDict.count(word))
				{
					s3.insert(word);
					flag = true;
				}
				if (flag)
				{
					string w1 = front ? *itr : word;
					string w2 = front ? word : *itr;
					unordered_map<string,vector<string>>::iterator mItr = M.find(w1); 
					if (mItr == M.end())
					{
						M.insert(pair<string,vector<string>>(w1,vector<string>()));
						M[w1].push_back(w2);
					}
					else
					{
						mItr->second.push_back(w2);
					}
				}
			}
			word[i] = oldC;
		}
	}

	for (unordered_set<string>::const_iterator itr = s3.begin(); itr != s3.end(); itr++)
	{
		wordDict.erase(*itr);
	}

	if (find)
	{
		return;
	}

	if (s3.size() < s2.size())
	{
		ladderLengthHelper(s3,s2,wordDict,M,front,find);
	}
	else
	{
		ladderLengthHelper(s2,s3,wordDict,M,!front,find);
	}
}

void generateHelper(unordered_map<string,vector<string>>& M, vector<string>& curPath, vector<vector<string>>& solutions, string& word, string& endWord)
{
	curPath.push_back(word);

	if (word == endWord)
	{
		solutions.push_back(curPath);
	}
	else
	{
		vector<string>& words = M[word];

		for (int i = 0; i < words.size(); i++)
		{
			generateHelper(M,curPath,solutions,words[i],endWord);
		}
	}

	curPath.pop_back();
}

vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) 
{
	vector<vector<string>> solutions;
	vector<string> curPath;
	unordered_set<string> s1;
	unordered_set<string> s2;
	unordered_map<string,vector<string>> M;
	s1.insert(start);
	s2.insert(end);
	dict.erase(start);
	dict.erase(end);

	bool find = false;
	ladderLengthHelper(s1,s2,dict,M,true,find);

	if (find)
		generateHelper(M,curPath,solutions,start,end);

	return solutions;
	

}

int main()
{
	unordered_set<string> set;
	set.insert("hot");
	set.insert("dot");
	set.insert("dog");
	set.insert("lot");
	set.insert("log");

	findLadders("hit","cog",set);

	return 1;
}