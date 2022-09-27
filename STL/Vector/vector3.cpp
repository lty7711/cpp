#include <iostream>
#include <vector>
#include <string>

using namespace std;

void myprint(auto data){
    for(auto i=data.begin(); i != data.end(); i++){
        cout << *i << ' ';
    }
    cout << endl;
}

int main(int argc, char *argv[]){
    /************************vector赋值操作************************/
    vector<string> buf1{"A1", "A2", "A3", "A4"};
    buf1.push_back("A5"); // 尾部添加字符串“A5”
    myprint(buf1);

    vector<string> buf2;
    buf2 = buf1;  //将buf1元素拷贝到buf2中,两者没有指向同一地址
    buf1.push_back("A6");
    myprint(buf2);
    myprint(buf1);

    vector<string> buf3;
    buf3.assign(buf1.begin(), buf1.end()); // 将buf1的值赋给buf3
    myprint(buf3);
    buf3.assign(10, "AA");  // 赋值为10个“AA”
    myprint(buf3);

    buf1.erase(buf1.begin(), buf1.begin()+1); // 擦除第一个元素
    myprint(buf1);
    return 0;
}