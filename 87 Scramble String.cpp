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


#define P(a,b,c) *(*(*(V+a)+b)+c)
/*bool isScrambleHelper(string s1, string s2)
{
    
    int N = (int)s1.length();
    if (N == 1) {
        if (s1[0] == s2[0])
            return true;
        else
            return false;
    }
    
    for (int i = 1; i <= N-1; i++) {
       bool res = (isScrambleHelper(s1.substr(0,i), s2.substr(0,i)) && isScrambleHelper(s1.substr(i), s2.substr(i)))
                   ||(isScrambleHelper(s1.substr(0,i), s2.substr(N-i)) && isScrambleHelper(s1.substr(N-i), s2.substr(0,i)));
        if (res) {
            return true;
        }
    }
    
    return false;
}*/


bool isScramble(string s1, string s2)
{
    string s3 = s1;
    string s4 = s2;
    sort(s3.begin(), s3.end());
    sort(s4.begin(), s4.end());
    
    if (s3 != s4) {
        return false;
    }
    
    int N = (int)s1.length();
    
    bool*** V;
    V = new bool**[N];
    for (int i = 0; i < N; i++) {
        V[i] = new bool*[N];
        for (int j = 0; j < N; j++) {
            V[i][j] = new bool[N];
            memset(V[i][j], false, N*sizeof(bool));
        }
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (s1[i] == s2[j]) {
                P(0, i, j) = true;
            }
        }
    }
    
    for (int len = 2; len <= N; len++) {
        for (int i = 0; i <= N-len; i++) {
            for (int j = 0; j <= N-len; j++) {
                for (int k = 1; k < len; k++) {
                    if ( ( P(k-1, i, j) && P(len-k-1,i+k,j+k))|| (P(k-1,i,j+len-k) && P(len-k-1,i+k,j))) {
                        P(len-1,i,j) = true;
                        break;
                    }
                }
            }
        }
    }
    bool res = V[N-1][0][0];
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            delete []V[i][j];
        }
        delete []V[i];
    }
    delete []V;
    
    return res;
}

int main(){
    
    cout<< isScramble("vfldiodffghyq", "vdgyhfqfdliof") <<endl;
    
    return 1;
}

