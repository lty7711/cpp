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

// 左闭右闭区间
int internalQuickSort(vector<int> &cache, int start, int end){
    /*
        算法改进,避免最差情况,随机生成基准位置
        index = randint(start. end);
        swap(cache[start], cache[index]); 
    */
    int i, flag=start+1;
    // 以start位置作为基准, flag前面的数据小于等于cache[start]
    for(i=start+1; i<=end; i++){
        if(cache[i] <= cache[start]){
            swap(cache[i], cache[flag]);
            flag++;
        }
    }
    swap(cache[flag-1], cache[start]);
    // myCout(cache);
    return flag-1;
}

// 快速排序 左闭右闭区间
void quickSort(vector<int> &cache, int start, int end){
    if(start >= end) return;
    
    int pri = internalQuickSort(cache, start, end);

    // pri已经找到位置,不需要再次参加排序
    quickSort(cache, start, pri-1);
    quickSort(cache, pri+1, end);
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
    quickSort(cache, 0, cache.size()-1);
    myCout(cache);
    return 0;
}