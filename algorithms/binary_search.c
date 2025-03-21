#include <stdio.h>

#define n sizeof(arr) / sizeof(arr[0])

int binary_search(int *arr, int n, int target) {
    int l=0, r=n-1, mid;

    while (l<=r) {
        mid = (l+r) / 2;

        if (arr[mid]==target) { return mid; }
        
        else if (arr[mid] < target) { l = r; }
        
        else { r = l; }
        
        return -1;
    }
}
