
#include <vector>
#include <iostream>
#include <string>
#include <stack>
#include <unordered_set>

using namespace std;

void solveNQueensHelper(vector<bool>& lineOccupied,vector<bool>& axisOccupied, vector<int>& lineIndex, int curI, vector<vector<string>>& solutions)
{
    int n = (int)lineOccupied.size();
    if (curI == n) {
        vector<string> tmpVec;
        for (int i = 0; i < n; i++) {
            string s(n,'.');
            s[lineIndex[i]] = 'Q';
            tmpVec.push_back(s);
        }
        solutions.push_back(tmpVec);
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
        solveNQueensHelper(lineOccupied, axisOccupied, lineIndex, curI+1, solutions);
        lineOccupied[i] = false;
        axisOccupied[axisID1] = false;
        axisOccupied[axisID2] = false;
    }
    
}

vector<vector<string> > solveNQueens(int n)
{
    vector<vector<string>> solutions;
    vector<bool> lineOccupied(n,false);
    vector<bool> axisOccupied(4*n-2,false);
    vector<int> lineIndex(n,0);
    int curI = 0;
    
    solveNQueensHelper(lineOccupied, axisOccupied, lineIndex, curI, solutions);
    
    return solutions;
}

int main()
{
    vector<vector<string>> solutions = solveNQueens(8);
    
    return 1;
}