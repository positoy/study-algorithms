#include <iostream>

int arr[] = {10,9,5,2,3,5,6,123,76,2134,13,6,123,123,124,531,312},len=17;

int binarySearch(int arr[], int left, int right, int target) {
    if (left > right)
        return -1;

    int half = (left+right)/2;
    if (arr[half] < target)
        return binarySearch(arr, half+1, right, target);
    else if (arr[half] > target)
        return binarySearch(arr, left, half-1, target);
    else
        return half;
}


int main()
{
    int temp;
    
    // sort!
    for (int i=0; i<17; i++)
    for (int j=16; j>i; j--)
    if (arr[j] < arr[j-1]) {
        temp = arr[j];
        arr[j] = arr[j-1];
        arr[j-1] = temp;
    }
    
    for (int i=0; i<len; i++) std::cout << i << ":" << arr[i] << ' ';
    std::cout << std::endl;

    // search!
    int idx = binarySearch(arr, 0, 16, 123);
    std::cout << idx << std::endl;
}