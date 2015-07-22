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

int maxProfit(int k, vector<int>& prices)
{
    int N = (int)prices.size();
    int count = 0;
    int profit = 0;
    bool rise = false;
    
    for (int i = 1; i < N; i++) {
        if (prices[i] > prices[i-1]) {
            profit += prices[i] - prices[i-1];
            if (!rise) {
                count++;
            }
            rise = true;
        }
        else
            rise = false;
    }
    
    if (k >= count) {
        return profit;
    }
 
    int hold[k];
    int sell[k];
    
    for (int i = 0; i < k; i++) {
        hold[i] = INT_MIN;
    }
    memset((int*)sell, 0, k * sizeof(int));
    
    for (int i = 0; i < N; i++) {
        int curP = prices[i];
        for (int j = k; j >= 0; j--) {
            sell[j] = max(sell[j],hold[j]+curP);
            hold[j] = max(hold[j],(j>0 ? sell[j-1]:0) - curP);
        }
        
    }
    
    return sell[k-1];
    
}

int main(){
    int N;
    cin >> N;
    vector<int> nums(N);
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }
    
    int res = maxProfit(2, nums);
    
    return 1;
}
