#include "interview.h"
#include "utilities/BinaryTree.h"
#include<exception>


CMyString::CMyString(char* pData){

    if(pData == nullptr){
        m_pData = new char[1];
        m_pData[0] = '\n';
    }else{
        int length = strlen(pData);
        m_pData = new char[length + 1];
        strcpy(m_pData, pData);
    }
}

CMyString::CMyString(const CMyString &str){
    int length = strlen(str.m_pData);
    m_pData = new char[length + 1];
    strcpy(m_pData, str.m_pData);
}

CMyString::~CMyString(){
    delete [] m_pData;
}

CMyString& CMyString::operator=(const CMyString& str){
    if (this != &str){
        CMyString strTemp(str);
        char* pTemp = strTemp.m_pData;
        strTemp.m_pData = m_pData;
        m_pData = pTemp;
    }
    return *this;
}

void CMyString::Print(){
    printf("%s,%p\n",m_pData,m_pData);
}

void Test1(){
    printf("Test1 begins:\n");

    char* text = "hello world!";
    CMyString str1(text);
    CMyString str2,str3;
    str3 = str2 = str1;

    printf("The expected result is:%s.\n", text);
    printf("The actual resultis :");
    str2.Print();
    str1.Print();
    str3.Print();
    printf(".\n");
}

Singleton* Singleton::p = nullptr;
Singleton* Singleton::instance(){
    if (p==nullptr){
        p = new Singleton();
    }
    return p;
}
pthread_mutex_t SingletonSafe::mutex;
SingletonSafe* SingletonSafe::p = nullptr;
SingletonSafe* SingletonSafe::instance(){
    if(p == nullptr){
        pthread_mutex_lock(&mutex);
        if (p == nullptr){
            p = new SingletonSafe();
        }
        pthread_mutex_unlock(&mutex);
    }
    return p;
};
// 饿汉, 空间换时间
SingletonHungry* SingletonHungry::p = new SingletonHungry();
SingletonHungry* SingletonHungry::instance(){
    return p;
};
// 二维数组查找
bool Find(int* matrix, int rows, int columns, int numbers){
    bool found = false;
    if (matrix == nullptr or rows <=0 or columns <=0)
        return false;

    int row =0 ;
    int column = columns - 1;
    while (row<rows && column>=0){
        int r = matrix[row*column+column];
        if (r == numbers){
            found = true;
            break;
        }else if(r < numbers)
            --column;
        else
            ++row;
    }
}

// 在合并两个数组（包括字符串）时，如果从前往后复制每个数字（或字符串）需要重复移动的数字（或字符串）较多，那么我们可以考虑从后往前复制，这样就可以减少移动的次数，从而提高效率
// TODO 第五题
// 第六题，递归逆序输出链表
// 还可以用栈的方式，先进后出存储
void t(ListNode* pHead){
    if (pHead != nullptr){
        if (pHead->m_pNext != nullptr){
            t(pHead->m_pNext);
        }
        printf("%d\t",pHead->m_nKey);
    }
}
// 二叉树，3种遍历，6中实现方式要掌握
// 前序 根,左,右
// 中序 左,根,右
// 后序 左,右,根

// 7重建二叉树
// 题目：输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输
// 入的前序遍历和中序遍历的结果中都不含重复的数字。例如输入前序遍历序列
// {1, 2, 4, 7, 3, 5, 6, 8}和中序遍历序列{4, 7, 2, 1, 5, 3, 8, 6}，则重建出
BinaryTreeNode* ConstructCore(int* startPreorder, int* endPreorder, int* startInorder, int* endInorder);

BinaryTreeNode* Construct(int* preorder, int* inorder, int length){
    if(preorder == nullptr || inorder == nullptr || length<=0)
        return nullptr;

    return ConstructCore(preorder, preorder+length-1, inorder, inorder+length-1);
}

BinaryTreeNode* ConstructCore(int* startPreorder, int* endPreorder,
int* startInorder, int* endInorder){
    int rootValue = startPreorder[0];
    printf("->[%d,%d],[%d,%d], %d<-\n", *startPreorder, *endPreorder, *startInorder, *endInorder, rootValue);
    BinaryTreeNode* root = new BinaryTreeNode();
    root->m_nValue = rootValue;
    root->m_pLeft=root->m_pRight=nullptr;

    if (startPreorder == endPreorder){
        if(startInorder == endInorder && *startPreorder == *startInorder)
        {
            printf("return %d ,%d\n",root->m_nValue, *startPreorder);
            return root;
        }
        else
        {
            std::logic_error ex("Invalid input.");
            throw std::exception(ex);
        }
    }

    // 在中序遍历中找到根节点的值
    int *rootInorder = startInorder;
    while(rootInorder<=endInorder && *rootInorder != rootValue)
        ++rootInorder;

    if(rootInorder == endInorder && *rootInorder != rootValue)
    {
            std::logic_error ex("Invalid input.");
            throw std::exception(ex);
    }

    int leftLength = rootInorder - startInorder;
    int* leftPreorderEnd = startPreorder + leftLength;
    printf("^%d,%d,%d,%d,%d^\n", *startPreorder, *leftPreorderEnd, *startInorder, *rootInorder, leftLength);
    if(leftLength>0)
    {
        // 构建左子树
        root->m_pLeft = ConstructCore(startPreorder+1, leftPreorderEnd,
                                           startInorder, rootInorder-1);
        printf("~~~%d,%d,%d left %d\n", *endPreorder, *startPreorder, leftLength, root->m_pLeft->m_nValue);
    }
    if (leftLength< endPreorder-startPreorder)
    {
        // 构建右子树
        root->m_pRight = ConstructCore(leftPreorderEnd+1, endPreorder,
                                    rootInorder+1, endInorder);
        printf("~~~%d,%d,%d right %d\n", *endPreorder, *startPreorder, leftLength, root->m_pRight->m_nValue);
    }
    printf("end return %d\n",root->m_nValue);
    return root;
}

void test_7(char* testName, int* preorder, int* inorder, int length)
{
    if(testName != nullptr)
        printf("%s begins:\n", testName);
    printf("The preorder sequence is:");
    for (int i = 0; i <length; ++i)
        printf("%d ", preorder[i]);
    printf("\n");

    printf("The inorder  sequence is:");
    for(int i = 0; i < length; ++ i)
        printf("%d ", inorder[i]);
    printf("\n");

    try
    {
        BinaryTreeNode* root = Construct(preorder, inorder, length);
        PrintTree(root);

        // DestroyTree(root);
    }
    catch(std::exception& exception)
    {
        printf("Invalid Input.\n");
    }
}

void Test7_1()
{
    const int length = 8;
    int preorder[length] = {1, 2, 4, 7, 3, 5, 6, 8};
    int inorder[length] = {4, 7, 2, 1, 5, 3, 8, 6};

    test_7("Test1", preorder, inorder, length);
}
// 完全二叉树
void Test7_5()
{
    const int length = 7;
    int preorder[length] = {1, 2, 4, 5, 3, 6, 7};
    int inorder[length] = {4, 2, 5, 1, 6, 3, 7};

    test_7("Test5", preorder, inorder, length);
}


// 8：二叉树的下一个结点
// 题目：给定一棵二叉树和其中的一个结点，如何找出中序遍历顺序的下一个结点

BinaryTreeNode* GetNext(BinaryTreeNode *pNode){
    if (pNode == nullptr)
        return nullptr;
    BinaryTreeNode* pNext = nullptr;
    if (pNode->m_pRight!=nullptr){
        BinaryTreeNode* pRight = pNode->m_pRight;
        while(pRight->m_pLeft != nullptr)
            pRight = pRight->m_pLeft;
        pNext = pRight;
    }else if (pNode->m_pParent!=nullptr){

        BinaryTreeNode* pCurrent = pNode;
        BinaryTreeNode* pParent = pNode->m_pParent;
        while(pParent!=nullptr && pCurrent == pParent->m_pRight)
        {
                // printf("pCurrent:%d\n", pCurrent->m_nValue);
                pCurrent = pParent;
                pParent = pParent->m_pParent;
        }
        // printf("end %d,%d\n",pCurrent->m_nValue, pParent->m_nValue);
        // if (pNode != pParent)
        pNext = pParent;
    }
    return pNext;
}
void Test_8(char* testName, BinaryTreeNode* pNode, BinaryTreeNode* expected)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    BinaryTreeNode* pNext = GetNext(pNode);
    if(pNext == expected)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

void Test8_15()
{
    BinaryTreeNode* pNode2 = CreateBinaryTreeNode(2);
    BinaryTreeNode* pNode3 = CreateBinaryTreeNode(3);
    BinaryTreeNode* pNode4 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);

    ConnectTreeNodes(pNode2, nullptr, pNode3);
    ConnectTreeNodes(pNode3, nullptr, pNode4);
    ConnectTreeNodes(pNode4, nullptr, pNode5);

    Test_8("Test12", pNode5, nullptr);
    Test_8("Test13", pNode4, pNode5);
    Test_8("Test14", pNode3, pNode4);
    Test_8("Test15", pNode2, pNode3);

    DestroyTree(pNode2);
}
//            8
//        6      10
//       5 7    9  11
void Test8_7()
{
    BinaryTreeNode* pNode8 = CreateBinaryTreeNode(8);
    BinaryTreeNode* pNode6 = CreateBinaryTreeNode(6);
    BinaryTreeNode* pNode10 = CreateBinaryTreeNode(10);
    BinaryTreeNode* pNode5 = CreateBinaryTreeNode(5);
    BinaryTreeNode* pNode7 = CreateBinaryTreeNode(7);
    BinaryTreeNode* pNode9 = CreateBinaryTreeNode(9);
    BinaryTreeNode* pNode11 = CreateBinaryTreeNode(11);

    ConnectTreeNodes(pNode8, pNode6, pNode10);
    ConnectTreeNodes(pNode6, pNode5, pNode7);
    ConnectTreeNodes(pNode10, pNode9, pNode11);

    Test_8("Test1", pNode8, pNode9);
    Test_8("Test2", pNode6, pNode7);
    Test_8("Test3", pNode10, pNode11);
    Test_8("Test4", pNode5, pNode6);
    Test_8("Test5", pNode7, pNode8);
    Test_8("Test6", pNode9, pNode10);
    Test_8("Test7", pNode11, nullptr);

    DestroyTree(pNode8);
}

// TODO 9：用两个栈实现队列
// 题目：用两个栈实现一个队列。队列的声明如下，请实现它的两个函数appendTail
// 和deleteHead，分别完成在队列尾部插入结点和在队列头部删除结点的功能。

// 算法
// 重点二分查找,归并排序，快速排序, 回溯法
// 用栈模拟递归
// 如果面试题是求某个问题的最优解，并且该问题可以分为多个字问题，可以尝试用动态规划,
// 如果分解字问题的时候存在某个特殊的选择，可以考虑适用贪婪算法


// 递归
// 递归由于是函数调用自身，而函数调用是有时间和空间的消耗，效率不如循环
// 递归调用的层级太多时，就会超出栈的容量，每个进程栈的容量有限
int AddFrom1ToN_recursive(int n){
    return n<=0?0:n+AddFrom1ToN_recursive(n-1);
}
// 10 fibonacci 第n项
//  递归的效率太慢了，n=100就已经特别慢了
int get_fib(int n){
    if (n == 0)
        return 0;
    else if (n==1)
        return 1;
    else
        return get_fib(n-1) + get_fib(n-2);
}
// TODO 实现一版循环处理的方式，小青蛙跳台阶


// 查找排序
// 顺序查找，二分查找，哈希表查找，二叉排序树查找
//  如果题目要求是在排序的数组中查找一个数字或者统计某个数字出现的次数，都可以尝试用二分查找算法

// 回溯法 ，动态规划，贪心算法


// 位运算
int NumberOf1(int n)
{
    // 这种方法没办法解决负数问题
    int count = 0;
    while(n){
        if(n&1)
            count++;
        n=n>>1;
    }
    return count;
}

int NumberOf_1(int n){
    int count =0;
    unsigned int k = 1;
    while(k){
        if (n&k)
            count++;
        k = k<<1;
    }
    return count;
}

// 17，输入数字n，按顺序打印出从1到最大的n位十进制数

bool Increment(char* number)
{
    bool isOverFlow = false;
    int nTakeOver = 0;
    int nLength = strlen(number);
    for (int i=nLength-1;i>=0;i--)
    {
        int nSum = number[i] - '0' + nTakeOver;
        if (i == nLength-1)
            nSum++;
        if (nSum >= 10)
        {
            if (i==0)
                isOverFlow = true;
            else{
                nSum -= 10;
                nTakeOver = 1;
                number[i] = '0' + nSum;
            }
        }else{
            number[i] = '0' + nSum;
            break;
        }
    }
    return isOverFlow;
}

// 19 匹配正则表达式


bool matchCore(char* str, char* pattern)
{
    if(*str=='\0' && *pattern =='\0')
        return true;
    if(*str!='\0' && *pattern == '\0')
        return false;

    if(*(pattern+1) == '*')
    {
        if(*pattern==*str || (*pattern=='.'&&*str!='\0'))
            // move on the next state
            return matchCore(str+1,pattern+2)
                    // stay on the crrent state
                    ||matchCore(str+1, pattern)
                    // ignore a '*'
                    || matchCore(str, pattern+2);
        else
        {
            return matchCore(str+1, pattern+1);
        }

    }
    if(*str==*pattern || (*pattern =='.'&&*str!='\0'))
        return matchCore(str+1, pattern+1);

    return false;
}

bool match(char* str, char* pattern)
{
    if (str==nullptr || pattern == nullptr)
        return false;

}

