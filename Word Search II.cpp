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
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class TrieNode {
public:
    char val;
    bool isWord;
    TrieNode* childs[26];
    TrieNode* parent;
    
    // Initialize your data structure here.
    TrieNode() {
        isWord = false;
        memset(childs, 0, sizeof(childs));
        parent = NULL;
    }
    
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
        itr = root;
    }
    
    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode* node = root;
        int index = 0;
        while (index < word.length()) {
            TrieNode* newNode = node->childs[word[index]-'a'];
            if (newNode) {
                node = newNode;
                index++;
            }
            else
                break;
        }
        
        while (index < word.length()) {
            TrieNode* newNode = new TrieNode();
            newNode->parent = node;
            node->childs[word[index++]-'a'] = newNode;
            node = newNode;
        }
        
        node->isWord = true;
    }
    
    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode* node = root;
        int index = 0;
        while (index < word.length()) {
            TrieNode* newNode = node->childs[word[index]-'a'];
            if (newNode) {
                node = newNode;
                index++;
            }
            else
                return false;
        }
        
        if (index == word.length() && node->isWord) {
            return true;
        }
        
        return false;
    }
    
    bool advance(char c){
        TrieNode* newNode = itr->childs[c-'a'];
        if (newNode) {
            itr = newNode;
            return true;
        }
        return false;
    }
    
    void retreat(){
        itr = itr->parent;
    }
    
    void reset(){
        itr = root;
    }
    
    bool isWord(){
        return itr->isWord;
    }
    void markWord(){
        itr->isWord = false;
    }
    
private:
    TrieNode* root;
    TrieNode* itr;
};

void findWordHelper(vector<vector<char>>& board, int i, int j, Trie& trie, vector<string>& solutions, string& s)
{
    int N = (int)board.size();
    int M = (int)board[0].size();

    char c = board[i][j];

    if (!trie.advance(c)) {
        return;
    }
    
    s.push_back(c);
    board[i][j] = 0;
    if (trie.isWord()) {
        solutions.push_back(s);
        trie.markWord();
    }
    
    if (i > 0 && board[i-1][j]) {
        findWordHelper(board, i-1, j, trie, solutions, s);
    }
    if (i < N-1 && board[i+1][j]) {
        findWordHelper(board, i+1, j, trie, solutions, s);
    }
    if (j > 0 && board[i][j-1]) {
        findWordHelper(board, i, j-1, trie, solutions, s);
    }
    if (j < M-1 && board[i][j+1]) {
        findWordHelper(board, i, j+1, trie, solutions, s);
    }
    
    board[i][j] = c;
    s.pop_back();
    trie.retreat();
}

vector<string> findWords(vector<vector<char>>& board, vector<string>& words)
{
    vector<string> solutions;
    int N = (int)board.size();
    if (N == 0) {
        return solutions;
    }
    int M = (int)board[0].size();
    if (M == 0) {
        return solutions;
    }
    
    Trie trie;
    
    for (int i = 0; i < words.size(); i++) {
        trie.insert(words[i]);
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            string s;
            findWordHelper(board, i, j, trie, solutions, s);
            trie.reset();
        }
    }
    
    return solutions;
}



int main()
{
    int N,M;
    cin >> N >> M;
    vector<vector<char>> board(N,vector<char>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }
    
    vector<string> words;
//    words.push_back("oath");
//    words.push_back("rain");
//    words.push_back("eat");
//    words.push_back("pea");
    words.push_back("a");
    
    vector<string> res = findWords(board, words);
    
    return 1;
}
