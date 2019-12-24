#include<iostream>
using namespace std;

// 朴素搜索方法
int native_search(char *s, char *t){

    int m = strlen(s);
    int n = strlen(t);

    for (int i=0;i<=n-m;i++){
        int j;
        for (j =0;j<m; j++){
            if(t[i+j] != s[j])
                break;
        }
        if (j==m){
            cout<<"Pattern found at index " << i <<endl;
            return i;
        }
    }
    return -1;
}
