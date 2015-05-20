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
#include <unordered_set>

using namespace std;

string getPermutation(int n, int k)
{
    if (n == 1) {
        return "1";
    }
    
    string s;
    k--;
    int i = 2;
    vector<int> fac;
    vector<int> digit;
    fac.push_back(1);
    digit.push_back(1);
    
    while (1) {
        int tmp = fac[0]*i;
        if (tmp > k) {
            break;
        }
        fac.insert(fac.begin(), tmp);
        digit.push_back(i);
        i++;
    }
    digit.push_back(i);
    
    int m = (int)digit.size();
    
    for (int i = 1; i <= n-m; i++) {
        s.push_back('0' + i);
    }
    
    for (int i = 0; i < m-1 ; i++) {
        int index = k / fac[i];
        s.push_back('0'+digit[index]+n-m);
        digit.erase(digit.begin()+index);
        k = k % fac[i];
    }
    s.push_back('0'+digit[0]+n-m);
   

    
    return s;
}

int main()
{
    string s = getPermutation(3, 6);
    return 1;
}

