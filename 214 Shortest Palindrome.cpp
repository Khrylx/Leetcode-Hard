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
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

string shortestPalindrome(string s)
{
    int N = (int)s.length();
    
    int next[N/2];
    
    next[0] = -1;
    
    for (int i = 1; i < N/2; i++) {
        int j = next[i-1];
        while ( s[j+1] != s[i] && j > -1) {
            j = next[j];
        }
        if (s[j+1] == s[i]) {
            j++;
        }
        next[i] = j;
    }
    
    int j = -1;
    for (int i = N-1; i >= 0; i--) {
        while (s[j+1] != s[i] && j > -1) {
            j = next[j];
        }
        if (s[j+1] == s[i]) {
            j++;
        }
        if (j >= i-1) {
            int index;
            if (j == i) {
                index = 2*j+1;
            }
            else{
                index = 2*j+2;
            }
            if (index == N) {
                return s;
            }
            string newS = s.substr(index);
            reverse(newS.begin(), newS.end());
            return newS+s;
        }
    }
    
    return "";
}



int main()
{
    string s = shortestPalindrome("aabbaa");
    
    return 1;
}
