
#include "csort.h"

// 直接插入排序算法
template<typename T>
void InsertSort(vector<T> array, int lenght)
{
    if (array.size() == 0 ||lenght<0)
        return ;
    int i,j;
    for(i=1;i<lenght;i++){
        if (array[i]< array[i-1]){
            T temp = array[i];
            for (j=i-1;array[j]>temp;j--){
                array[j+1] = array[j];
            }
            array[j+1] = temp;
        }
    }
}

// 二分查找插入排序
template <typename T>
int BinarySearch(T array[], int start, int end, T k){
    while (start <= end){
        int middle = (start + end)/2;
        T middleData = array[middle];
        if (middleData < k){
            start = middle + 1;
        }else
            end = middle - 1;
    }
    return start;
}

// 直接插入排序算法
template<typename T>
void BinaryInsertSort(T array[], int lenght)
{
    if (array==nullptr||lenght<0)
        return ;
    int i,j;
    for(i=1;i<lenght;i++){
        if (array[i]< array[i-1]){
            T temp = array[i];
            int insert_index = BinarySearch(array, 0, i, array[i]);
            for (j=i-1;j>=insert_index;j--){
                array[j+1] = array[j];
            }
            array[insert_index] = temp;
        }
    }
}

vector<int> numbers;
// 希尔排序
void shell_sort(const int start, const int end) {
    int increment = end - start + 1;    //初始化划分增量
    int temp{ 0 };
    do {    //每次减小增量，直到increment = 1
        increment = increment / 3 + 1;
        for (int i = start + increment; i <= end; ++i) {    //对每个划分进行直接插入排序
            if (numbers[i - increment] > numbers[i]) {
                temp = numbers[i];
                int j = i - increment;
                do {    //移动元素并寻找位置
                    numbers[j + increment] = numbers[j];
                    j -= increment;
                } while (j >= start && numbers[j] > temp);
                numbers[j + increment] = temp;  //插入元素
            }
        }
    } while (increment > 1);
}

void produceRandomNumbers(const int start, const int end, const int amount) {
    srand((unsigned)time(NULL));
    for (int cnt = 1; cnt <= amount; ++cnt) {
        numbers.push_back(start + (rand() % (end - start)));
    }
}

int csort_test()
{
    time_t c_start, c_end;
    produceRandomNumbers(1, 100000, 100000);

    c_start = clock();
    //dinsert_sort(0, 999);
    //binsert_sort(0, 999);
    InsertSort(numbers, numbers.size());
    // shell_sort(0, 99999);
    c_end = clock();

    cout << "当前排序算法花费时间为:" << difftime(c_end, c_start) << "ms" << endl;
    for (auto iter = numbers.cbegin(); iter != numbers.cend(); ++iter) {
        cout << *iter << " ";
    }

    // system("pause");
    return 0;
}