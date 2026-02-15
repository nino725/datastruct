#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    
    return 0;
}

int find_main(int A[], int n){
    int cnt[n];
    int max_cnt = 0;
    int val = 0;
    for(int i = 0; i < n; i++){
        cnt[i]++;
        if(cnt[i] > max_cnt){
            max_cnt = cnt[i];
            val = i;
        }
    }

    return max_cnt > n / 2 ? val : -1;
}