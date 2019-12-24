//
// Created by Bran on 4/5/16.
//

//二叉树
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "BinaryTree.h"

int CreateBiTree(BiTree *T){
    char ch = 'A';
    printf("please input char:\n");
    scanf("%c", &ch);
    getchar();
//    char chs[128] = "ksidfksisldifj";
////    printf("[ss %s]\n", chs);
////    printf("[%d]\n", ch);
    printf("[%c]\n", ch);

    if(ch == ' '){

        *T = NULL;
    }
    else{
        if (!(*T=(BiTNode *)malloc(sizeof(BiTNode)))){
            printf("end\n");
            return -1;
        }
        (*T)->data = ch;
        CreateBiTree(&(*T)->lchild);
        CreateBiTree(&(*T)->rchild);
    }
    return 0;
}

int PreOrderTraverse(BiTree T){
   if (T){
       printf("%c\n", T->data);
       if (PreOrderTraverse(T->lchild) == 0)
           if(PreOrderTraverse(T->rchild) == 0)
               return 0;
//       PreOrderTraverse(T->lchild);
//       PreOrderTraverse(T->rchild);

       return 1;
   }else
       return 0;
}
