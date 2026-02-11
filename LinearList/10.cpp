#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//10. abcdef ghijkl ×îÖÕµÃµ½ghijkl abcdef -> lkjihg fedcba -> abcdefghijkl -> fedcba lkjihg
void reverse(int arr[], int l, int r){
    for(int i = 0; i < (r - l + 1) / 2; i++){
        int temp = arr[l+i];
        arr[l+i] = arr[r-i];
        arr[r-i] = temp;
    }
}

void rev(int arr[], int p, int len){
    reverse(arr, 0, p);
    reverse(arr, p+1, len-1);
    reverse(arr, 0, len-1);
}

int main() {
    int arr[9] = {1,2,3,4,5,6,7,8,9};
    rev(arr, 4, 9);
    for(int i = 0; i < 9; i++){
        cout<<arr[i]<<
    }
    return 0;
}
