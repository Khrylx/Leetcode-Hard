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

void connectHelper(TreeLinkNode *n1, TreeLinkNode *n2)
{
    if(!n2) {
        TreeLinkNode* l = NULL;
        if(n1->left){
            l = n1->left;
        }
        if (n1->right) {
            l = n1->right;
        }
        if (l) {
            connectHelper(l, NULL);
        }
        if (n1->left && n1->right) {
            connectHelper(n1->left, n1->right);
        }
        return;
    }
    
    
    n1->next = n2;
    
    TreeLinkNode* l1 = NULL;
    TreeLinkNode* l2 = NULL;
    
    if (n1->left) {
        l1 = n1->left;
    }
    if (n1->right) {
        l1 = n1->right;
    }
    if (n2->right) {
        l2 = n2->right;
    }
    if (n2->left) {
        l2 = n2->left;
    }

    if (n2->left && n2->right) {
        connectHelper(n2->left, n2->right);
    }
    
    if (l1) {
        if (l2) {
            connectHelper(l1, l2);
        }
        else{
            TreeLinkNode* cur = n2->next;
            while (cur) {
                if (cur->left) {
                    cur = cur->left;
                    break;
                }
                else if(cur->right) {
                    cur = cur->right;
                    break;
                }
                cur = cur->next;
            }
            connectHelper(l1, cur);
        }
    }
    
    if (n1->left && n1->right) {
        connectHelper(n1->left, n1->right);
    }
    
    
}

void connect(TreeLinkNode *root)
{
    if (!root) {
        return;
    }
    
    connectHelper(root, NULL);
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
