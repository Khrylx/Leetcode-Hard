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

int mySqrt(int x)
{
    const int max = 0x7fffffff;
    int res = 1;
    
    while (1) {
        int tmpRes = x / res;
        int minRes = min(tmpRes,res);
        int newRes = tmpRes > max-res ? max/2 : (res+tmpRes)/2;
        if (minRes == newRes) {
            return minRes;
        }

        res = newRes;
    }
    
    return res;
}

int main(){
    cout << sqrt((int)0x7fffffff)<<endl;
    cout << mySqrt(0x7fffffff) <<endl;
    return 1;
}

