#include <stdio.h>
#include <string.h>

int glis(const int *arr, int length)
{
    int lis[length];
    memset(lis, 0, sizeof(lis));

    int i = 0, j = 0;
    lis[0] = 1;
    int ret = 0;

    for(i = 1; i < length; i ++) {
        for(j = i - 1; j >= 0; j--) {
            if(arr[i] >= arr[j] && lis[j] >= lis[i]) {
                lis[i] = lis[j] + 1;
                ret = lis[i] > ret ? lis[i] : ret;
            }
        }
    }


    return ret;
}

int binary_search(const int *arr, int size, int value)
{
    if(arr[size-1] <= value) {
        return size - 1;
    }

    if(arr[0] > value) {
        return -1;
    }

    int start = 0, end = size - 1;

    while(start < end - 1){
        int mid = (start + end) / 2;
        if(arr[mid] <= value)
            start = mid;
        else
            end   = mid;
    }
    return start;
}

int lnglis(const int *arr, int length)
{
    int list[length];
    int min[length + 1];

    memset(list, 0, sizeof(list));
    memset(min, 0, sizeof(list));
    
    int i = 0,  mlen = 1;
    list[0] = 1;
    min [1] = arr[0]; 

    for(i = 1; i < length; i ++) {
        int idx = binary_search(min, mlen, arr[i]);
        if(idx == mlen - 1) 
           min[mlen++] = arr[i]; 
        else if (min[idx+1] > arr[i])
            min[idx+1] = arr[i];
    }
    return mlen;
}

int main(int argc, char *argv[])
{
    int arr[] = {2, 3, 4, 2, 7, 8, 4, 9, 0};
    printf("lis of arr is %d \n", lnglis(arr, sizeof(arr)/sizeof(int)));

    return 0;
}
