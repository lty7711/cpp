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

// 插入排序
void insertionSort(vector<int> &cache){
    int size = cache.size();
    for(int i=1; i<size; i++){
        int temp = cache[i];
        // cout << temp << endl;
        int j=i-1;
        while( j>=0){
            if(cache[j] > temp){
                cache[j+1] = cache[j];
            }else{
                break; // 表示已经找到插入位置
            }
            j--;
        }
        cache[j+1] = temp; // 注意要写在这里
        // myCout(cache);
    }
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
    insertionSort(cache);
    myCout(cache);
    return 0;
}