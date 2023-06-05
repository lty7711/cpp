#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <cmath>

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


// 希尔排序 左闭右闭区间,是插入排序的一种改进吧
void shellSort(vector<int> &cache){
    int size = cache.size();
    int gap = size / 2; // 将所有数分为4组

    while(gap > 0){
        for(int i=gap; i<size; i++){
            int cur_value = cache[i]; // 保存当前值
            int j = i;
            while(j >= gap){
                if(cache[j-gap] > cache[j]){
                    cache[j] = cache[j-gap];
                    j = j -gap;
                }
                else{
                    break;
                }
            }
            cache[j] = cur_value;
        }
        gap = gap/2;
    }
}


int main(){
    
    std::random_device rd;  // 用于获取一个随机种子
    std::mt19937 gen(rd()); // 采用 mt19937 随机数生成器
    std::uniform_int_distribution<> distr(0, 1000); // 定义一个从0到20的均匀分布
    std::vector<int> cache(20);
    int i = 0;
    for(; i<cache.size(); i++){
        cache[i] = distr(gen);
    }
    
    cout << "Before Sorting: " << endl;
    myCout(cache);
    cout << "After Sorting: " << endl;
    shellSort(cache);
    myCout(cache);
    return 0;
}