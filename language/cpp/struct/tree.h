#include <stdio.h>
#include <iostream>

class Node{
    public:
        int iData;
        double dData;
        Node *leftNode;
        Node *rightNode;
        void showNode();
        bool insert(int iData, double dDate);
        Node *find(int key);
        // 构造函数
        Node(int iData, double dData);
};

Node *root = nullptr;