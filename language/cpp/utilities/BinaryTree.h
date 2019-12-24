#include<cstdio>
#pragma once

struct BinaryTreeNode{
    int m_nValue;
    BinaryTreeNode* m_pLeft;
    BinaryTreeNode* m_pRight;
    BinaryTreeNode* m_pParent;
};

#define max(x,y) ((x)>(y)) ? (x):(y)


void PrintTreeNodes(const BinaryTreeNode*  pnode);
void PrintTree(const BinaryTreeNode* pNode);

void DestroyTree(BinaryTreeNode* pRoot);
BinaryTreeNode* CreateBinaryTreeNode(int value);
void ConnectTreeNodes(BinaryTreeNode* pParent, BinaryTreeNode* pLeft, BinaryTreeNode* pRight);
