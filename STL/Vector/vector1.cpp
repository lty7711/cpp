#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(int argv, char *argc[]){
    /*
        一维数组示例。。。。。。。。。。。。。。
        Vector长度是动态的,在C++一般用于替代数组,可以使用类似于数组的形式访问
    */

    // vec1初始化为空的vector，此时不能进行访问，若在空时进行访问会出现段错误
    vector<int> vec1;
    vec1.push_back(2); // 在末尾添加元素
    cout << "*****************vec1使用数组一样的访问方式*****************" << endl;
    for(int i=0; i<vec1.size(); i++){
        cout << "vec1[" << i << ']' << " = " << vec1[i] << endl;
    }
    cout << "*****************vec1使用迭代器的访问方式*****************" << endl;
    auto p1 = vec1.begin(); //自己判断p1是什么类型
    /* vector<int>::iterator p1 = vec1.begin(); */ // 使用迭代器进行访问
    for(; p1 != vec1.end(); p1++){
        cout << *p1 << endl;
    }

    cout << endl;

    cout << "*****************vec2使用数组一样的访问方式*****************" << endl;
	vector<float> vec2(3); // 初始化长度设定为3，采用编译器默认初始化值
    vec2.push_back(100); // 可进行动态添加
    for(int i=0; i<vec2.size(); i++){
        cout << "vec2[" << i << ']' << " = " << vec2[i] << endl;
    }
    cout << "*****************vec2使用迭代器的访问方式*****************" << endl;
    auto p2 = vec2.begin(); //自己判断p2是什么类型
    /* vector<int>::iterator p2 = vec2.begin(); */ // 使用迭代器进行访问
    for(; p2 != vec2.end(); p2++){
        cout << *p2 << endl;
    }

    cout << endl;

	vector<char> vec3(3,'a'); // 数据类型为char类型，初始化为‘a’
	for(int i=0; i<vec3.size(); i++){
        cout << "vec3[" << i << ']' << " = " << vec3[i] << endl;
    }

    cout << endl;

    vector<string> vec4(3, "ABC"); // 数据类型为string类型，初始化为‘ABC’
    for(int i=0; i<vec4.size(); i++){
        cout << "vec4[" << i << ']' << " = " << vec4[i] << endl;
    }

    cout << endl;

    vector<string> vec5(vec4); // 使用vec4来初始化vec5，即两者元素内容一模一样
    for(int i=0; i<vec5.size(); i++){
        cout << "vec5[" << i << ']' << " = " << vec5[i] << endl;
    }
    return 0;
}