#include <vector>
#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>
#include <unordered_set>

using namespace std;

void ladderLengthHelper(unordered_set<string>& S, unordered_map<string,vector<string>>& M, unordered_set<string>& wordDict, string& endWord)
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
}

void generateHelper(unordered_map<string,vector<string>>& M, vector<string>& curPath, vector<vector<string>>& solutions, string& word)
{
	curPath.push_back(word);
	unordered_map<string,vector<string>>::iterator itr = M.find(word);

	if (itr == M.end())
	{
		solutions.push_back(curPath);
	}
	else
	{
		vector<string>& words = itr->second;

		for (int i = 0; i < words.size(); i++)
		{
			generateHelper(M,curPath,solutions,words[i]);
		}
	}

	curPath.pop_back();
}

vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) 
{
	vector<vector<string>> solutions;
	vector<string> curPath;
	unordered_set<string> S;
	unordered_map<string,vector<string>> M;
	S.insert(end);
	dict.erase(start);
	dict.erase(end);

	ladderLengthHelper(S,M,dict,start);

	if (M.find(start) != M.end())
		generateHelper(M,curPath,solutions,start);

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