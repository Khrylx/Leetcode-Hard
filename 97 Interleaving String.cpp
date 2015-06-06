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

/*bool isInterleave(string s1, string s2, string s3)
{
    int len1 = (int)s1.length();
    int len2 = (int)s2.length();
    int len = (int)s3.length();
    int index1 = 0;
    int index2 = 0;
    int index = 0;
    
    while (index < len) {
        if (index1 < len1 && index2 < len2 && s1[index1] == s3[index] && s2[index2] == s3[index]) {
            bool res = isInterleave(s1.substr(index1+1), s2.substr(index2), s3.substr(index+1));
            if (res)
                return true;
            res = isInterleave(s1.substr(index1), s2.substr(index2+1), s3.substr(index+1));
            if (res)
                return true;
            else
                return false;
        }
        if (index1 < len1 && s1[index1] == s3[index]) {
            index1++;
            index++;
        }
        else if(index2 < len2 && s2[index2] == s3[index]){
            index2++;
            index++;
        }
        else
            return false;
        
    }
    
    return true;
}*/

bool isInterleave(string s1, string s2, string s3)
{
    int len1 = (int)s1.length();
    int len2 = (int)s2.length();
    int len = (int)s3.length();
    
    if (len1 + len2 != len) {
        return false;
    }
    
    vector<vector<bool>> match(len1+1,vector<bool>(len2+1,false));
    
    match[0][0] = true;
    
    for (int i = 1; i <= len1; i++) {
        if (s1[i-1] == s3[i-1])
            match[i][0] = true;
        else
            break;
    }
    for (int i = 1; i <= len2; i++) {
        if (s2[i-1] == s3[i-1])
            match[0][i] = true;
        else
            break;
    }
    
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (s1[i-1] == s3[i+j-1]) {
                match[i][j] = match[i][j] || match[i-1][j];
            }
            if (s2[j-1] == s3[i+j-1]) {
                match[i][j] = match[i][j] || match[i][j-1];
            }
        }
    }
    
    return match[len1][len2];
}

int main(){

    cout << isInterleave("aabcc", "dbbca", "aadbbcbcac") <<endl;
    
    return 1;
}




