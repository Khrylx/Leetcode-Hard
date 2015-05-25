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

bool isNumber(string s)
{
    int index1 = (int)s.find_first_not_of(' ');
    if (index1 == string::npos)
        return false;
    
    int index2 = (int)s.find_last_not_of(' ');
    s = s.substr(index1,index2-index1+1);
    
    bool numberRead = false;
    bool expRead = false;
    bool signRead = false;
    bool dotRead = false;
    bool finishable = false;
    
    for (int i = 0 ; i < (int)s.length(); i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            numberRead = true;
            finishable = true;
        }
        else if(s[i] == 'e' || s[i] == 'E'){
            if (expRead || !numberRead)
                return false;
            
            expRead = true;
            finishable = false;
            numberRead = false;
            dotRead = false;
            signRead = false;
        }
        else if (s[i] == '.'){
            if(dotRead || expRead)
                return false;
            
            dotRead = true;
            if (numberRead)
                finishable = true;
        }
        else if (s[i] == '+' || s[i] == '-'){
            if(signRead || dotRead || numberRead)
                return false;
            
            signRead = true;
        }
        else{
            return false;
        }
    }
    
    return finishable;
}

int main(){

    cout << isNumber(" 32.-e80123   ")<<endl;
    return 1;
}

