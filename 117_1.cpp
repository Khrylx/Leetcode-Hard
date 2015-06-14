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

struct TreeLinkNode {
    int val;
    TreeLinkNode *left;
    TreeLinkNode *right;
    TreeLinkNode *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

TreeLinkNode* initTreeRoot(int val)
{
    return new TreeLinkNode(val);
}

TreeLinkNode* addLeftChild(TreeLinkNode* node, int val)
{
    TreeLinkNode* lChild = new TreeLinkNode(val);
    node->left = lChild;
    return lChild;
}

TreeLinkNode* addRightChild(TreeLinkNode* node, int val)
{
    TreeLinkNode* rChild = new TreeLinkNode(val);
    node->right = rChild;
    return rChild;
}

void destroyTree(TreeLinkNode* root)
{
    if (root->left) {
        destroyTree(root->left);
    }
    if (root->right) {
        destroyTree(root->right);
    }
    
    delete root;
    
}

void inorderPrint(TreeLinkNode* root)
{
    if (root->left) {
        inorderPrint(root->left);
    }
    
    cout << root->val <<" ";
    
    if (root->right) {
        inorderPrint(root->right);
    }
}

void connect(TreeLinkNode *root)
{
    if (!root) {
        return;
    }
    
    TreeLinkNode *begin = NULL;
    TreeLinkNode **p = NULL;
    
    while (root) {
        if (root->left) {
            if (!begin) {
                begin = root->left;
            }
            if (p) {
                (*p)->next = root->left;
            }
            p = &(root->left);
        }
        
        if (root->right) {
            if (!begin) {
                begin = root->right;
            }
            if (p) {
                (*p)->next = root->right;
            }
            p = &(root->right);
        }
        
        root = root->next;
    }
    
    connect(begin);
}


int main(){
    
    TreeLinkNode* root = initTreeRoot(1);
    TreeLinkNode* n1 = addLeftChild(root, 2);
    TreeLinkNode* n2 = addRightChild(root, 3);
    TreeLinkNode* n3 = addLeftChild(n1, 4);
    addRightChild(n1, 5);
    TreeLinkNode* n4 = addRightChild(n2, 6);
    addLeftChild(n3, 7);
    addRightChild(n4, 8);
    connect(root);
    
    return 1;
}
