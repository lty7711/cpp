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

// 构造大顶堆, 左闭右闭区间
void maxHeap(vector<int> &cache, int start, int end){
    int son = start * 2 +1; // 左孩子
    while(son <= end){
        // 判断左右孩子哪一个更大
        if(son+1 <= end && cache[son+1] > cache[son]){
            son++;
        }
        if(cache[son] > cache[start]){
            swap(cache[son], cache[start]); // 若孩子节点值大于父亲节点,则交换两者值
             // 要维持大顶堆,换下来的父亲节点的值不一定大于其之前孩子节点的左右孩子节点的值
            start = son;
            son = son*2+1;
        }else{
            break; // 否则直接break
        }
    }
}

// 堆排序
void heapSort(vector<int> &cache){
    int size = cache.size();
    // 变为大顶堆
    for(int i=size/2; i>=0; i--){
        maxHeap(cache, i, size-1);
    }
    
    // 交换之后,只有根节点不符合大顶堆的要求,因此后续只要调节根节点即可
    for(int i=size-1; i>0; i--){
        swap(cache[0], cache[i]);
        maxHeap(cache, 0, i-1);
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
    heapSort(cache);
    myCout(cache);
    return 0;
}