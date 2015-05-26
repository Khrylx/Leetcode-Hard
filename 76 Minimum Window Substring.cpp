//
//  main.cpp
//  Leetcode
//
//  Created by Eric on 15/5/14.
//  Copyright (c) 2015年 Eric. All rights reserved.
//

#include <vector>
#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>
#include <unordered_set>

using namespace std;

string minWindow(string s, string t)
{
    int minSize = 99999;
    string solution;
    
    unordered_map<char,int> S,M,O;
    for (int i = 0; i < (int)t.length(); i++) {
        unordered_map<char, int>::iterator itr = S.find(t[i]);
        if (itr == S.end()) {
            S.insert(pair<char, int>(t[i],1));
        }
        else{
            itr->second++;
        }
        
    }
    M = S;
    
    int bIndex = -1;
    for (int i = 0; i < (int)s.length(); i++) {
        if (S.find(s[i]) != S.end()) {
            if (bIndex == -1){
                bIndex = i;
            }
            if (s[i] == s[bIndex]) {
                if (M.find(s[i]) != M.end()) {
                    M[s[i]]--;
                    if (M[s[i]] == 0) {
                        M.erase(s[i]);
                    }
                }
                else{
                    while (1) {
                        bIndex++;
                        if (S.find(s[bIndex]) != S.end()) {
                            unordered_map<char, int>::iterator itr = O.find(s[bIndex]);
                            if (itr != O.end()){
                                itr->second--;
                                if (itr->second == 0) {
                                    O.erase(itr);
                                }
                            }
                            else{
                                break;
                            }
                        }
                    }
                }
            }
            else{
                unordered_map<char, int>::iterator itr = M.find(s[i]);
                if (itr == M.end()){
                    unordered_map<char, int>::iterator itr1 = O.find(s[i]);
                    if(itr1 == O.end())
                        O.insert(pair<char,int>(s[i],1));
                    else
                        itr1->second++;
                }
                else{
                    itr->second--;
                    if(itr->second == 0)
                        M.erase(itr);
                }
            }
            
            if (M.empty()) {
                int newSize = i - bIndex + 1;
                if (newSize < minSize) {
                    minSize = newSize;
                    solution = s.substr(bIndex,newSize);
                }
            }

        }
    }
    
    return solution;
}

int main(){
    
    cout << minWindow("abc", "ab") <<endl;
    
    
    
    return 1;
}

