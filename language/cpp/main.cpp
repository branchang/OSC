#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "NumSeq.h"
#include "generic_proc.h"
#include "containers.h"
#include "algo.h"
#include "tpoco/TestPoco.h"
#include "stack.h"
#include "sequence.h"
#include "basic.h"
#include "interview.h"
#include "algorithm_t/csort.h"
#include "design_patterns/w_bridge.hpp"
#include "book/test_co.hpp"
#include "book/cpprimer.h"

int wfile(){
    ofstream outfile("seq_data.txt", ios_base::app);
    if (!outfile){
        cerr << "Oops! unable to save session data1\n";
    }else {
        outfile << "zhangran" << ' '
                << "3" <<' '
                << "3" <<endl;
    }
    return 0;
}

int rfile(){
    string usr_name;
    int num_tries = 0;
    int num_cor = 0;
    cout << "please input user name:";
    cin >> usr_name;
    string ss = "this is string.";


    ifstream infile("seq_data.txt");
    if (! infile) {
        cerr << "read file error !!";
    }else{
        string name ;
        int nt;
        int nc;
        while(infile>>name){
            cout << "name:"<< name;
            infile>>nt>>nc;
            if (name == usr_name){
                cout << "welcome back, " << usr_name
                     << "\n Your current score is " << nc
                     << " out of " <<nt<<"\n Good Luck!\n";
                num_tries = nt;
                num_cor= nc;
            }
        }
    }
}

int hello_world(){
    std::string first_name;
    std::string last_name;
    std::cout << "!!Please enter your first name: ";
    std::cin >> first_name;
    std::cout << "Please enter your last name: ";
    std::cin >> last_name;
    std::cout << '\n';
    cout << "Hello, ";
    std::cout << first_name
              << '\t'
              <<last_name;
    std::cout << "... and goodbye!\n";

}

int fib(){
    string user_name;
    int num_tries = 0;
    int num_right = 0;
    double usr_score = 0.0;
    char usr_more;
    cout << "try another sequence? Y/N? ";
    cin >> usr_more;
    bool go_for_it = true;
    bool next_seq = true;

    const int max_tries = 3;
    const double pi = 3.14159;

    while (next_seq == true){
        while ((true)){
            int usr_val;
            cin >> usr_val;
            num_tries++;
        }
        cout << "try another sequence? Y/N? ";
        cin >> usr_more;
        if (usr_more == 'N' || usr_more == 'n'){
            next_seq = false;
        }
    }

}

bool fibon_elem(int pos, int &elem){
    if (pos <=0 || pos > 1024){
        elem = 0;
        return false;
    }

    elem = 1;
    int n_2 = 1, n_1 =1;
    for (int ix = 3;ix <= pos; ++ix){
        elem = n_2 + n_1;
        cout << elem << endl;
        n_2 = n_1;
        n_1 = elem;
    }

    return true;
}

bool fibon_elem2(int pos, int &elem){

    const vector<int> *pseq = fibon_seq(pos);

    if (!pseq){
        elem = 0;
        return false;
    }
    elem = (*pseq)[pos-1];
    return true;
}

bool print_sequence(int pos) {
    if (pos <= 0 || pos > 1024){
        cerr << "invalid position: " << pos
             <<"-- cannot handle request!\n";
        return false;
    }
    cout << "The Fibonacci Sequence for "
         << pos << "positions: \n\t";
    switch  (pos){
        default:
        case 2:
            cout << "1 ";
        case 1:
            cout << "1 ";
            break;
    }

    int elem;
    int n_2 = 1,n_1 = 1;
    for (int ix=3; ix <= pos; ++ix){
        elem = n_2 + n_1;
        n_2 = n_1;
        n_1 = elem;
        cout << elem << (!(ix%10)? "\n\t":" ");
    }
    cout << endl;
    return true;
}


void use_fibon(){

    while (true){
        int pos = 0;
        cout << "please enter a position:";
        cin >> pos;
        if (pos == 0){
            break;
        }

        int elem;
//    if (fibon_elem2(pos, elem)){
        if (fibon_elem2(pos, elem)){
            cout << "element # " << pos
                 << " is " << elem << endl;
            print_sequence(pos);
        }else {
            cout << "Sorry. Could not calculate element # "
                 << pos << endl;
        }

    }
}

void display(vector<int> vec){
    for (int ix = 0; ix  < vec.size(); ++ix){
        cout << vec[ix]<<' ';
    }
    cout << endl;
}

void swap (int &val1, int &val2){
    int temp = val1;
    val1 = val2;
    val2 = temp;
}

void bubble_sort(vector<int> &vec)
{
    for (int ix = 0;ix < vec.size(); ++ix)
        for(int jx = ix+ 1; jx < vec.size(); ++jx)
            if(vec[ix] > vec[jx])
                swap(vec[ix], vec[jx]);
}

int test_bubble(){
    int ia[8] = {8, 34, 3, 13, 1, 21, 5, 2};
    vector<int> vec(ia, ia + 8);
    vector<int> vec2(ia, ia+8);
    cout << "vector before sort: ";
    display(vec);
    bubble_sort(vec);
    cout << "vector after sort: ";
    display(vec);
}

inline bool is_size_ok(int size){
    const int max_size = 1024;
    if (size <= 0 || size > max_size){
        cerr << "Oops: requested size is not supported : "
             << size << " --can't fulfill request.\n";
        return false;
    }
    return true;
}

const vector<int>* fibon_seq(int size){
    const int max_size =1024;
    static vector<int> elems;
    if (!is_size_ok(size))
        return 0;

    for (int ix=elems.size(); ix<size; ++ix){
        if(ix==0 || ix==1)
            elems.push_back(1);
        else
            elems.push_back(elems[ix-1] + elems[ix-2]);
    }
    return &elems;
}

template <typename elemType> void display_message(const string &msg, const vector<elemType> &vec){
    cout << msg;
    for(int ix=0; ix< vec.size(); ++ix){
        elemType t =vec[ix];
        cout<<t<<'a';
    }
}

int test_string(){
     std::string lang = "";
     if(lang.empty()){

         std::cout<<"is empty()onon;"<<std::endl;
     }else {
         std::cout<<"is not empty();"<<std::endl;

     }
     return 0;
}

int test_sequence(){
    char ch;
    bool more = true;
    while (more){
        cout<<"Enter value: ";
        int ival;
        cin>>ival;
        bool is_elem = Triangular::is_elem(ival);
        cout << ival
            <<(is_elem ? " is ": " is not ")
            <<"an element in the Triangular series.\n"
            <<" Another value?(y/n)";
        cin >> ch;
        if (ch == 'n' || ch == 'N')
            more = false;
    }
}

// int count_less_than(const vector<int> &vec, int comp){
//     LessThan lt(comp);
//     int count = 0;
//     for (int ix = 0;ix < vec.size(); ++ix)
//         if(lt(vec[ix]))
//             ++count;
//     return count;
// }

// void print_less_than(const vector<int> &vec,
//                         int comp, ostream &os=cout)
//                         {
//                             // 通常我们会把function object 当做参数传给泛型算法
//                             LessThan lt(comp);
//                             vector<int>::const_iterator iter = vec.begin();
//                             vector<int>::const_iterator it_end = vec.end();

//                             os<<"elements less than "<<lt.comp_val() << endl;
//                             while((iter=find_if(iter, it_end, lt)) != it_end)
//                                 os<<*iter<<' ';
//                                 ++iter;

//                         }




int test_stack()
{
    Stack st = Stack();
    st.test();
    st.push("123");
    st.push("456");
    st.push("789");
    st.push("001");
    st.push("001");
    cout<<st.size()<<"@@@";
    bool b = st.find("001");
    cout<<b<<"###";
    int c = st.count("001");
    cout<<c<<";;;";

}


#include<vector>

using namespace std;
// @lc code=start
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums;
        int i = 0;
        int j = 0;
        int l1 = nums1.size();
        int l2 = nums2.size();
        while (i < l1 || j < l2){
            if (i>=l1){
                nums.push_back(nums2[j]);
                j++;
                continue;
            }
            if (j>=l2){
                nums.push_back(nums1[i]);
                i++;
                continue;
            }
            if (nums1[i]<=nums2[j]){
                nums.push_back(nums1[i]);
                i++;
                continue;
            }
            if (nums2[j]<=nums1[i]){
                nums.push_back(nums2[j]);
                j++;
                continue;
            }
        }
        int lenght = nums.size();
        int mid = lenght/2;
        int mod = lenght%2;
        std::cout<<"lenght"<<lenght<<std::endl<<"mid:"<<mid<<std::endl;
        if (mod==0){
            double result = (double)(nums[mid-1]+nums[mid])/2;
            return result;
        }else{
            return (double)nums[mid];
        }
    }
};

int test_leetcode(){
    Solution s = Solution();
    vector<int> nums1;
    vector<int> nums2;
    nums1.push_back(1);
    nums1.push_back(3);
    // nums2.push_back(2);
    double res = s.findMedianSortedArrays(nums1, nums2);
    std::cout<<"results:"<<res<<std::endl;
    return 0;
}

int main() {
    std::cout << "Hello, World! CPP zhr haha" << std::endl;
//    test_string();
//    rfile();
//    use_fibon();
//    test_bubble();
//    cout << "hello world!"<<endl;
//    find_test();
//    containers_test();
//    TestPoco *tp = new TestPoco();
//    tp->run();
//    test_insert();
    // test_filter();
    // test_m();
    // test_sequence();
    // t_random();
    // t_const();
    // Test1();
    // Test8_7();
    // int t = AddFrom1ToN_recursive(15000);
    // int t = get_fib(100);
    // printf("%d\n", t);

    // test_textblock();
    // csort_test();
    // test_leetcode();
    // test_string2();
    // test_string_3();
    // test_string_4();

    // test_virtual_func();
    // destructor_virtual_test();
    // test_const_var();
    cpp_primer_test();
    return 0;

}
