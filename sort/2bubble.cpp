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

// 冒泡排序
void bubble(vector<int> &cache){
    int size = cache.size();
    for(int i=0; i<size-1; i++){
        for(int j=1; j<size-i; j++){
            if(cache[j-1] > cache[j]){
                swap(cache[j-1], cache[j]);
            }
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
    bubble(cache);
    myCout(cache);
    return 0;
}