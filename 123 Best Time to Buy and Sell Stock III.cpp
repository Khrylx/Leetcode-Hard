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

int maxProfit(vector<int>& prices)
{
    int N = (int)prices.size();
    if (N <= 1) {
        return 0;
    }
    
    vector<int> P(N+1,0);
    vector<int> Q(N+1,0);
    int low = prices[0];
    int high = prices.back();
    
    for (int i = 2; i <= N ; i++) {
        if(prices[i-1] > low){
            P[i] = max(P[i-1],prices[i-1]-low);
        }
        else{
            P[i] = P[i-1];
            low = prices[i-1];
        }
    }
    
    for (int i = N-2; i >= 0; i--) {
        if (prices[i] < high) {
            Q[i] = max(Q[i+1],high-prices[i]);
        }
        else{
            Q[i] = Q[i+1];
            high = prices[i];
        }
    }
    
    int maxP = 0;
    for (int i = 0; i <= N; i++) {
        maxP = max(maxP,P[i]+Q[i]);
    }
    
    return maxP;

    
    
}

int main(){
    
    int N;
    cin >> N;
    
    vector<int> prices(N);
    
    for (int i = 0; i < N; i++) {
        cin >> prices[i];
    }
    
    cout << maxProfit(prices) <<endl;
    
    return 1;
}
