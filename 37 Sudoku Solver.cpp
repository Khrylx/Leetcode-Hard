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
#include <unordered_set>

using namespace std;



struct digitPair{
    int digit;
    int num;
    digitPair(int _digit,int _num) : digit(_digit),num(_num){};
};

bool myCompare(digitPair& pair1,digitPair& pair2)
{
    return pair1.num < pair2.num;
}

bool solveSudokuHelper(vector<vector<char>>& board,
                       vector<unordered_set<int>>& hSet,
                       vector<unordered_set<int>>& vSet,
                       vector<unordered_set<int>>& nSet,
                       vector<digitPair>& digitNums)
{
    sort(digitNums.begin(), digitNums.end(), myCompare);
    vector<digitPair> tmpDigitNums;
    for (int i = 0; i < digitNums.size(); i++) {
        if (digitNums[i].num==0) {
            continue;
        }
        tmpDigitNums.push_back(digitNums[i]);
    }
    digitNums = tmpDigitNums;
    
    int count;
    int lastCount = -1;
    
    while (!digitNums.empty()) {
        count = 0;
        for (int k = 0; k < digitNums.size() ; k++) {
            int digit = digitNums[k].digit;
            for (int i = 0; i < 9; i++) {
                if (hSet[i].find(digit) != hSet[i].end())
                    continue;
                
                vector<int> solVec;
                bool filled = true;
                for (int j = 0; j < 9 ; j++) {
                    if (board[i][j]=='.') {
                        filled = false;
                        if (vSet[j].find(digit) == vSet[j].end()
                            && nSet[i/3*3+j/3].find(digit) == nSet[i/3*3+j/3].end())
                            solVec.push_back(j);
                    }
                }
                if (solVec.size()==0) {
                    return false;
                }
                else if (solVec.size() == 1) {
                    int j = solVec[0];
                    board[i][j] = '0'+digit;
                    hSet[i].insert(digit);
                    vSet[j].insert(digit);
                    nSet[i/3*3+j/3].insert(digit);
                    digitNums[k].num--;
                    count++;
                }
                else if (lastCount == 0)
                {
                    for (int p = 0; p < solVec.size(); p++) {
                        vector<vector<char>> newBoard = board;
                        vector<unordered_set<int>> newHSet = hSet;
                        vector<unordered_set<int>> newVSet = vSet;
                        vector<unordered_set<int>> newNSet = nSet;
                        vector<digitPair> newDigitNums = digitNums;
                        int j = solVec[p];
                        newBoard[i][j] = '0'+digit;
                        newHSet[i].insert(digit);
                        newVSet[j].insert(digit);
                        newNSet[i/3*3+j/3].insert(digit);
                        newDigitNums[k].num--;
                        bool res = solveSudokuHelper(newBoard, newHSet, newVSet, newNSet, newDigitNums);
                        if (res) {
                            board = newBoard;
                            return true;
                        }
                    }
                    return false;
                }
            }
            
        }
        
        lastCount = count;
        
        sort(digitNums.begin(), digitNums.end(), myCompare);
        vector<digitPair> tmpDigitNums;
        for (int i = 0; i < digitNums.size(); i++) {
            if (digitNums[i].num==0) {
                continue;
            }
            tmpDigitNums.push_back(digitNums[i]);
        }
        digitNums = tmpDigitNums;
    }

    return true;
    
}

void solveSudoku(vector<vector<char>>& board)
{
    vector<unordered_set<int>> hSet(9);
    vector<unordered_set<int>> vSet(9);
    vector<unordered_set<int>> nSet(9);
    vector<digitPair> digitNums;
    
    for (int i = 1; i < 10; i++) {
        digitNums.push_back(digitPair(i,9));
    }
    
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9 ; j++) {
            if (board[i][j]=='.') {
                continue;
            }
            int num = board[i][j] - '0';
            digitNums[num-1].num--;
            hSet[i].insert(num);
            vSet[j].insert(num);
            nSet[i/3*3+j/3].insert(num);
        }
    }
    
    solveSudokuHelper(board,hSet, vSet, nSet,digitNums);
    
}

void InitSudoKuFromFile(const char* filename, vector<vector<char>>& board)
{
    board.resize(9, vector<char>(9));
    
    FILE* fp = fopen(filename, "r");
    
    char c = fgetc(fp);
    int i = 0;
    while (!feof(fp)) {
        if (c == '\n') {
            c = fgetc(fp);
        }
        board[i/9][i%9] = c;
        i++;
        if(i>=81)
            break;
        c = fgetc(fp);
    }
    
    fclose(fp);
    
}

void PrintSudoKu(vector<vector<char>>& board)
{
    for (int i=0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    vector<vector<char>> board;
    InitSudoKuFromFile("/Users/eric/Documents/project/Leetcode/Leetcode/File1.txt", board);
    solveSudoku(board);
    PrintSudoKu(board);
    
    return 1;
}

