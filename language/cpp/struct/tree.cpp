#include "tree.h"


void Node::showNode(){
    std::cout<<iData<<dData<<std::endl;

}
Node::Node(int i, double d){
    iData = i;
    dData = d;
    leftNode = nullptr;
    rightNode = nullptr;
}

bool Node::insert(int iData, double dData){
    Node *newNode = new Node(iData, dData);
    if (root == nullptr){
        root = newNode;
    }else{
        Node *current = root;
        Node *parent;
        while(true){
            parent = current;
            if (iData< current->iData){
                current = current->leftNode;
                if (current == nullptr){
                    parent->leftNode = newNode;
                    return true; 
                }
            }else{
                current = current->rightNode;
                if (current == nullptr){
                    parent->rightNode = newNode;
                    return true;
                }
            }
        }
    }
}


Node* Node::find(int key){
    if (root == nullptr)
        return nullptr;
    Node* current = root;    
    while(true) {
        if (current == nullptr or current->iData == key)
            return current;
            
        if (key < root->iData){
            current = root->leftNode;
        }else{
            current = root->leftNode;
        }
    }
}