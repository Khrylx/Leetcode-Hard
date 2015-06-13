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

int numDistinct(string s, string t)
{
    int sLen = (int)s.length();
    int tLen = (int)t.length();
    vector<vector<int>> nums(sLen+1,vector<int>(tLen+1,0));
    
    for (int i = 0; i <= sLen; i++) {
        nums[i][0] = 1;
    }
    
    for (int i = 1; i <= sLen; i++) {
        int tLen1 = min(i,tLen);
        for (int j = 1; j <= tLen1; j++) {
            if (s[i-1] != t[j-1]) {
                nums[i][j] = nums[i-1][j];
            }
            else{
                nums[i][j] = nums[i-1][j-1]+nums[i-1][j];
            }
        }
    }
    
    return nums[sLen][tLen];
}

int main(){
    
    cout << numDistinct("aaaaaaaaaaaaa", "aa") <<endl;
    
    return 1;
}
