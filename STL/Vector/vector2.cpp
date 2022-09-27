#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 这里使用了自动类型推断
void myprint(auto data){
    for(auto i=data.begin(); i != data.end(); i++){
        for(auto j=(*i).begin(); j != (*i).end(); j++){
            cout << *j << ' ';
        }
        cout << endl;
    }
}

int main(int argc, char *argv[]){
    /*
        初始化二维数组
        参考博客：https://blog.csdn.net/qq_35987777/article/details/105905452
    */

    // 初始化一个 二维的matrix, 行M,列N,且值为0
    int M=2, N=3;
    // vector<vector<int>> matrix(M,vector<int>(N));

    //等价于下面的
    // vector<vector<int> > matrix(M);
    // for(int i=0;i<M;i++) {
    //     matrix[i].resize(N);
    // }

    // //等价于下面的
    // vector< vector<int> > matrix;
    // matrix.resize(M);//M行
    // for(int i=0;i<matrix.size();i++){
    //     matrix[i].resize(N);//每一行都是N列
    // }
        
    // 初始化一个 二维的matrix, 行M,列N,且值自定义为data;
    int data = 1;
    vector<vector<int>> matrix(M,vector<int>(N,data));
    // myprint(matrix);

    /********************初始化方法差别****************************/
    // matrix1.size() = 0
    vector<vector<int>> matrix1{};
    // matrix2.size() = 1
    vector<vector<int>> matrix2{{}};

    //初始化列表
    vector<vector<int>> matrix3{ {1},{1,1} };//学会用大括号初始化二维数组
    myprint(matrix3);
    return 0;
}