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

void solveNQueensHelper(vector<bool>& lineOccupied,vector<bool>& axisOccupied, vector<int>& lineIndex, int curI, int& solution)
{
    int n = (int)lineOccupied.size();
    if (curI == n) {
        solution++;
    }
    
    for (int i = 0; i < n; i++) {
        int axisID1 = curI + i;
        int axisID2 = 2*n-1 + curI-i+7;
        
        if (lineOccupied[i] || axisOccupied[axisID1] || axisOccupied[axisID2]) {
            continue;
        }
        
        lineIndex[curI] = i;
        lineOccupied[i] = true;
        axisOccupied[axisID1] = true;
        axisOccupied[axisID2] = true;
        solveNQueensHelper(lineOccupied, axisOccupied, lineIndex, curI+1, solution);
        lineOccupied[i] = false;
        axisOccupied[axisID1] = false;
        axisOccupied[axisID2] = false;
    }
    
}

int totalNQueens(int n)
{
    int solution = 0;
    vector<vector<string>> solutions;
    vector<bool> lineOccupied(n,false);
    vector<bool> axisOccupied(4*n-2,false);
    vector<int> lineIndex(n,0);
    int curI = 0;
    
    solveNQueensHelper(lineOccupied, axisOccupied, lineIndex, curI, solution);
    
    return solution;
}

int main()
{
    cout<<totalNQueens(8)<<endl;
    
    return 1;
}

