#include <iostream>
#include <stack>
#include <assert.h>
#include <cstdio>


// 29 顺时针打印矩阵
void printNumber(int number){
    ;
}

void PrintMatrixInCircle(int** numbers, int columns, int rows, int start)
{
    int endX = columns-1-start;
    int endY = rows-1-start;

    // 从左到右打印一行
    for (int i=start;i<=endX;++i)
    {
        int number= numbers[start][i];
        printNumber(number);
    }

    // 从上到下打印一行
    if (start < endY){
        for(int i=start+1;i<=endY;++i)
        {
           int number = numbers[i][endX];
           printNumber(number);
        }
    }

    // 从右到左打印一行
    if(start<endX && start <endY)
    {
        for (int i=endX-1;i>=start; --i){
            int number = numbers[endY][i];
            printNumber(number);
        }
    }

    // 从下到上打印一列
    if(start<endX && start<endY-1)
    {
        for(int i=endY-1;i>=start+1;--i)
        {
            int number = numbers[i][start];
            printNumber(number);
        }
    }
}

void PrintMatrixClockwisely(int** numbers, int columns, int rows){
    if(numbers==nullptr||columns<=0||rows<=0)
    {
        return;
    }
    int start = 0;
    while (columns>start*2 &&rows> start*2)
    {
        PrintMatrixInCircle(numbers, columns, rows, start);
        ++start;
    }
    
}

// 30 包含min函数的栈
template<typename T> class StackWithMin
{
    public:
        StackWithMin(){}
        virtual ~StackWithMin(){}

        T& top();
        const T& top() const;
        void push(const T& value);
        void pop();

        const T& min() const;
        bool empty() const;
        size_t size() const;
    private:
        std::stack<T> m_data;
        std::stack<T> m_min;

};
template <typename T> void StackWithMin<T>::push(const T& value)
{

    // 把新元素添加到辅助栈
    m_data.push(value);
    // 当新元素比之前的最小元素小时，把新元素插入辅助栈里；
    // 否则把之前的最小元素重复插入辅助栈里
    if(m_min.size() == 0||value < m_min.top())
        m_min.push(value);
    else
    {
        m_min.push(m_min.top());
    }
    
}

template <typename T> void StackWithMin<T>::pop()
{
    assert(m_data.size()>0 && m_min.size()>0);
    m_data.pop();
    m_min.pop();
}

template <typename T> const T& StackWithMin<T>::min() const
{
    assert(m_data.size()>0&&m_min.size()>0);
    return m_min.top();
}

template <typename T>T& StackWithMin<T>::top()
{
    return m_data.top();
}
template <typename T>const T& StackWithMin<T>::top() const 
{
    return m_data.top();
}

template <typename T> bool StackWithMin<T>::empty() const
{
    return m_data.empty();
}

template <typename T> size_t StackWithMin<T>::size() const
{
    return m_data.size();
}

// 31
bool IsPopOrder(const int* pPush, const int* pPop, int nLength)
{
    bool bPossible = false;
    if (pPush!=nullptr && pPop != nullptr && nLength > 0)
    {
        const int* pNextPush = pPush;
        const int* pNextPop = pPop;
        std::stack<int> stackData;

        while(pNextPop - pPop < nLength)
        {
            // 当辅助栈的栈顶元素不是要弹出的元素
            // 先压入一些数字入栈
            while(stackData.empty() || stackData.top()!=*pNextPop){

                if (pNextPush - pPush == nLength)
                    break;

                stackData.push(*pNextPush);
                pNextPush++;
            }

            if(stackData.top()!=*pNextPop)
                break;
            stackData.pop();
            pNextPop++;
        }

        if(stackData.empty() && pNextPop-pPop == nLength)
            bPossible = true;

    }

    return bPossible;
}

// 35
struct ComplexListNode
{
    int m_nValue;
    ComplexListNode* m_pNext;
    ComplexListNode* m_pSibling;
};

ComplexListNode* Clone(ComplexListNode* pHead){
    ;
}
