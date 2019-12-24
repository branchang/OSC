
// http://www.cnblogs.com/maybe2030/p/4715035.html
//顺序查找
int sequence_search(int a[], int value, int n){
    int i;
    for (i=0;i<n;i++){
        if(a[i]==value)
            return i;
    }
    return -1;
}
 
int binary_search(int a[], int value, int n){
    int start = 0;
    int end = n;
    while(end < start){
        int mid = (end+start)/2;
        if (a[mid]<value)
            start = mid + 1;
        else if (a[mid]>value)
            end = mid-1;
        else
            return mid;
    }
    return -1;
}
