#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

//记录查找次数
int cnt;
/*创建数组*/
void NumberData(vector<int>& arr);
void myNumberData(vector<int>& arr);

/*顺序查找*/
int Sequentialsearch(vector<int>& arr, int target);
/*二分查找*/
int BinarySearch(vector<int>& arr, int target);
/*
分块查找 总体二分，局部顺序
*/
struct IndexItem{
    int maxNum;
    int start;
};

int main() {
    cout<<"您想要自己输入数据还是系统生成？"<<endl;
    cout<<"自己输入请打1"<<endl;
    cout<<"系统生成请打2"<<endl;
    vector<int> arr(20);
    int mode = 0;
    cin>>mode;
    if(mode){
        myNumberData(arr);
    }else{
        NumberData(arr);
    }
    cout<<"请输入你要查找的元素:"<<endl;
    int val;
    cin>>val;
    int res = (Sequentialsearch(arr,val);
    if(res == -1){
        cout<<"您查找的元素不存在"<<endl;
    }else{
        cout<<"您查找的元素的位置为:"<<res + 1<<endl;
        cout<<"查找次数为:"<<cnt<<endl;
    }
    return 0;
}

void NumberData(vector<int>& arr) {
    cout<<"已创建20个数字的有序的数组!"<<endl;
    arr = {2, 3, 7, 8, 15, 20, 21, 22, 30, 45, 47, 50, 52, 60, 88, 90, 101, 110, 115, 150};
}

void myNumberData(vector<int>& arr){
    int len = 0;
    cout<<"您要创建的数组元素的个数!"<<endl;
    cin>>len;
    arr.resize(len);
    cout<<"请输入您创建数组中的元素!"<<endl;
    for(int i = 0; i < len; i++){
        cin>>arr[i];
    }
}

int Sequentialsearch(vector<int>& arr, int target) {
    cnt = 0;
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] == target) {
            return i;
        }
        cnt++;
    }
    return -1; 
}

int BinarySearch(vector<int>& arr, int target){
    int left = 0, right = arr.size() - 1;
    cnt = 0;
    while(right >= left){
        int mid = left + (right - left) / 2;
        if(arr[mid] < target){
            left = mid + 1;
        }else if(arr[mid] > target){
            right = mid - 1;
        }else{
            return mid;
        }
        cnt++;
    }
    return -1;
}

IndexItem* createIndexTable(vector<int> arr, int n, int &b){
    int s = ceil(sqrt(n)); //向上取整  

    b = ceil((double)n / s);

    
}