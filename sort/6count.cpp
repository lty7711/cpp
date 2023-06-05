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

// 计数排序,利用哈希思想,使用范围较小
void countSort(vector<int> &cache){
    int value = 1 + *std::max_element(cache.begin(), cache.end()); // 获取的最大值加1
    vector<int> buf(value, 0);
    for(int ele: cache){
        buf[ele]++;
    }
    int index=0;
    for(int i=0; i<buf.size(); i++){
        while(buf[i]--){
            cache[index++] = i;
        }
    }
}

void myCout(const vector<int> &cache){
    for(int ele:cache){
        cout << ele << ' ';
    }
    cout << endl;
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
    countSort(cache);
    myCout(cache);
    return 0;
}