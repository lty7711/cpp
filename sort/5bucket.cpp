#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

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
    int l=start, r=mid+1;
    while(l<=mid && r <= end){
        if(cache[l] > cache[r]){
            buf.push_back(cache[r]);
            r++;
        }else{
            buf.push_back(cache[l]);
            l++;
        }
    }
    while(l <= mid){
        buf.push_back(cache[l++]);
    }
    while(r <= end){
        buf.push_back(cache[r++]);
    }

    for(int i=start; i<=end; i++){
        cache[i] = buf[i-start];
    }

}

// 归并排序,左闭右闭区间
void mergeSort(vector<int> &cache, int start, int end){
    if(start >= end) {
        return;
    }
    int mid = (start+end)/2;
    mergeSort(cache, start, mid);
    mergeSort(cache, mid+1, end);
    merge(cache, start, mid, end);
}

void bucketSort(vector<int> &cache){
    int max_value = *std::max_element(cache.begin(), cache.end());
    cout << "max_value = " << max_value << endl;
    int min_value = *std::min_element(cache.begin(), cache.end());
    cout << "min_value = " << min_value << endl;

    int size = cache.size(); // 数据总个数
    // 分区间[min_value, min_value+bucket_size) [min_value+bucket_size, min_value+2*bucket_size)......
    int bucket_size = (max_value - min_value)/size + 1; // 计算出的bucket装入的数据范围
    int bucket_num = (max_value - min_value)/bucket_size + 1; // 计算需要多少个桶

    vector<vector<int>> buf(bucket_num);
    cout << "bucket_num = " << buf.size() << endl;
    for(int ele: cache){ // 将元素放入桶中
        buf[(ele-min_value)/bucket_size].push_back(ele);
    }
    cout << "123" << endl;
    for(vector<int> &ele: buf){ // 注意这里要加引用,否则不是在原来的的顺序上排序
        mergeSort(ele, 0, ele.size()-1);
        myCout(ele);
    }
    
    int index=0;
    for(vector<int> bucket: buf){
        for(int num: bucket){
            cache[index++] = num;
        }
    }
}

int main(){
    
    std::random_device rd;  // 用于获取一个随机种子
    std::mt19937 gen(rd()); // 采用 mt19937 随机数生成器
    std::uniform_int_distribution<> distr(0, 50); // 定义一个从0到20的均匀分布
    std::vector<int> cache = {45, 34, 40, 21, 23, 16, 31, 15, 13, 20, 24, 26, 46, 42, 6, 31, 13, 3, 5, 14};
    int i = 0;
    // for(; i<cache.size(); i++){
    //     cache[i] = distr(gen);
    // }
    
    cout << "Before Sorting: " << endl;
    myCout(cache);
    
    cout << "After Sorting: " << endl;
    // mergeSort(cache, 0, cache.size()-1);
    bucketSort(cache);
    myCout(cache);
    return 0;
}