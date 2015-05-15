//
//  main.cpp
//  Leetcode
//
//  Created by Eric on 15/5/14.
//  Copyright (c) 2015年 Eric. All rights reserved.
//

#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;


vector<int> findSubstring(string s, vector<string>& words)
{
	vector<int> solution;
	if (words.size() == 0)
		return solution;


	int wordLen = (int) words[0].length();

	unordered_map<string, int> origWordMap;
	for (int i = 0 ; i<(int)words.size(); i++) {
		unordered_map<string, int>::iterator itr = origWordMap.find(words[i]);
		if (itr == origWordMap.end()) {
			origWordMap.insert(pair<string, int>(words[i],1));
		}
		else
		{
			itr->second++;
		}

	}

	for (int i=0; i<wordLen; i++) {
		int bIndex = i;
		int eIndex = i;

		unordered_map<string, int> wordMap = origWordMap;
		
		while (eIndex <= (int)s.length()-wordLen) {

			string tmpS = s.substr(eIndex,wordLen);
			bool flag = false;

			unordered_map<string, int>:: iterator itr = wordMap.find(tmpS);
			if (itr == wordMap.end()) {
				flag = true;
			}
			else {
				itr->second--;
				if (itr->second==0) {
					wordMap.erase(itr);
				}
				if (wordMap.empty()) {
					flag = true;
					solution.push_back(bIndex);
				}
				eIndex+=wordLen;
			}
			if (flag)
			{
				tmpS = s.substr(bIndex,wordLen);
				itr = wordMap.find(tmpS);
				if (itr == wordMap.end()) {
					wordMap.insert(pair<string, int>(tmpS,1));
				}
				else{
					itr->second++;
				}
				bIndex+=wordLen;
			}
			
		}
	}

	return solution;


}

int main()
{

	//    string s ="lingmindraboofooowingdingbarrwingmonkeypoundcake";
	//    vector<string> words;
	//    words.push_back("fooo");
	//    words.push_back("barr");
	//    words.push_back("wing");
	//    words.push_back("ding");
	//    words.push_back("wing");

	string s ="abababab";
	vector<string> words;
	words.push_back("a");
	words.push_back("b");
	words.push_back("a");



	//["fooo","barr","wing","ding","wing"]
	vector<int>  solution = findSubstring(s, words);


	return 1;
}


