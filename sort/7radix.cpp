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


// 基数排序,本质思想跟桶排序很像
void radixSort(vector<int> &cache){
    using std::pow;
    int max_value = *std::max_element(cache.begin(), cache.end()); // 获取最大值
    
    int base = 1;
    cout << "max_value = " << max_value << endl;
    // while取数里面的循环是取个 十 百位上的数
    while(max_value/(int)pow(10, base-1) > 0){ // 最大值在某一位数都为0了,表明就排序好了
        cout << "max_value = " << max_value % (int)pow(10, base) / (int)pow(10, base-1) << endl;
        vector<vector<int>> buf(10); // 10行
        for(int i=0; i<cache.size(); i++){
            int index = cache[i] % (int)pow(10, base) / (int)pow(10, base-1);
            buf[index].push_back(cache[i]);
        }
        int index = 0;
        // cout << "12131" << endl;
        for(vector<int> buf1 : buf){
            for(int ele : buf1){
                cache[index++] = ele;
            }
        }
        // myCout(cache);
        base++;
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
    radixSort(cache);
    myCout(cache);
    return 0;
}