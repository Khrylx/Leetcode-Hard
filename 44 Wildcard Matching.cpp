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

using namespace std;

/*bool isMatch(string s, string p)
{
    vector<vector<bool>> match;
    match.resize(s.length()+1,vector<bool>(p.length()+1,false));
    
    match[0][0] = true;
    
    for (int i = 1; i <= p.length(); i++) {
        if (p[i-1] != '*') {
            match[0][i] = false;
        }
        else{
            match[0][i] = match[0][i-1];
        }
    }
    
    bool pureDigit = true;
    for (int j = 1; j <= p.length(); j++) {
        if (p[j-1] =='*' || p[j-1] =='?') {
            pureDigit = false;
        }
        
        bool flag = false;
        for (int i = 1; i <= s.length(); i++) {
            if (flag) {
                match[i][j] = true;
            }
            else if (p[j-1] == '*')
            {
                for (int k = i; k >= 0 ; k--) {
                    if (match[k][j-1]) {
                        match[i][j] = true;
                        flag = true;
                        break;
                    }
                }
            }
            else if(p[j-1] == '?' || s[i-1] == p[j-1])
            {
                match[i][j] = match[i-1][j-1];
            }
            
            if (pureDigit && i == j && match[i][j] == false) {
                return false;
            }
        }

    }
    
    return match[s.length()][p.length()];
}*/

bool isMatch(string s, string p)
{
    int sIndex = -1;
    int pIndex = -1;
    int i = 0;
    int j = 0;
    while (1) {
        bool valid = true;
        
        if (i == s.length() && j == p.length()) {
            return true;
        }
        else if (i == s.length() && j < p.length())
        {
            while (j < p.length() && p[j] == '*') {
                j++;
            }
            if (j == p.length()) {
                return true;
            }
            else
                return false;
        }
        else if (i < s.length() && j == p.length())
        {
            valid = false;
        }
        
        if (valid) {
            if (p[j] == '*') {
                sIndex = i;
                pIndex = j;
                while (pIndex < p.length() && p[pIndex] == '*') {
                    pIndex++;
                }
                if (pIndex == p.length()) {
                    return true;
                }
                i--;
                j = pIndex-1;
            }
            else if(p[j] != '?' && p[j] != s[i]){
                valid = false;
                if (pIndex == -1) {
                    return false;
                }
            }
        }
        if (valid) {
            i++;
            j++;
        }
        else{
            sIndex++;
            if (sIndex == s.length()) {
                return false;
            }
            i = sIndex;
            j = pIndex;
        }
        
    }
    
    return true;

}

int main()
{
    string s1 = "aa";
    string s2 = "*aa*";
    cout << isMatch(s1, s2) <<endl;
    return 1;
}

