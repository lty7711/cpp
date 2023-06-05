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

// 选择排序
void slection(vector<int> &cache){
    int size = cache.size();
    for(int i=0; i<size-1; i++){
        int cur_min = i; // 当前最小值的位置
        for(int j=i+1; j<size; j++){
            if(cache[j] < cache[cur_min]){
                cur_min = j;
            }
        }
        swap(cache[i], cache[cur_min]);
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
    slection(cache);
    myCout(cache);
    return 0;
}