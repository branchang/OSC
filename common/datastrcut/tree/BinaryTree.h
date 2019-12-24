//
// Created by Bran on 4/5/16.
//

#ifndef TREE_BINARYTREE_H
#define TREE_BINARYTREE_H

//typedef int TElemType;
typedef char TElemType;

typedef struct BiTNode{
    TElemType data;
    struct BiTNode *lchild, *rchild; // 左右孩子
}BiTNode,*BiTree;

int PreOrderTraverse(BiTree T);



int CreateBiTree(BiTree *T);




#endif //TREE_BINARYTREE_H
