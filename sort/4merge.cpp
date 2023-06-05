#include <iostream>
#include <vector>
#include <random>

using std::vector;
using std::cout;
using std::endl;

// 交换两个数的值
void swap(int &num1, int &num2){
    int temp=num1;
    num1 = num2;
    num2 = temp;
}

void myCout(const vector<int> &cache){
    for(int ele:cache){
        cout << ele << ' ';
    }
    cout << endl;
}

// 合并操作
void merge(vector<int> &cache, int start, int mid, int end){
    vector<int> buf;
    int l = start;
    int r=mid;
    while(l < mid && r<end){
        if(cache[l] > cache[r]){
            buf.push_back(cache[r]); // 入缓冲区
            r++;
        }else{
            buf.push_back(cache[l]);
            l++;
        }
    }
    
    while(r < end){
        buf.push_back(cache[r++]);
    }

    while(l < mid){
        buf.push_back(cache[l++]);
    }
    
    for(int i=start; i<end; i++){
        cache[i] = buf[i - start];
    }
}

// 归并排序
void mergeSort(vector<int> &cache, int start, int end){
    if(start+1 >= end) return;
    int mid = (start+end)/2;
    mergeSort(cache, start, mid);
    mergeSort(cache, mid, end);
    merge(cache, start, mid, end); // 左闭右开区间
    // myCout(cache);
}

int main(){
    
    std::random_device rd;  // 用于获取一个随机种子
    std::mt19937 gen(rd()); // 采用 mt19937 随机数生成器
    std::uniform_int_distribution<> distr(0, 20); // 定义一个从0到20的均匀分布
    std::vector<int> cache(20);
    int i = 0;
    for(; i<cache.size(); i++){
        cache[i] = distr(gen);
    }
    
    cout << "Before Sorting: " << endl;
    myCout(cache);
    cout << "After Sorting: " << endl;
    mergeSort(cache, 0, cache.size());
    myCout(cache);
    return 0;
}