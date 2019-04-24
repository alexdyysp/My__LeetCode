#include <iostream>
#include <vector>
#include <numeric>
#include <limits>
#include <bits/stdc++.h>
using namespace std;


/*请完成下面这个函数，实现题目要求的功能
当然，你也可以不按照下面这个模板来作答，完全按照自己的想法来 ^-^
******************************开始写代码******************************/
int string2int(string str) {
        if (str == "") return 0;
        int num=0;
        int flag=1;
        if (str.find_first_not_of("+-1234567890.") < str.size())  return 0;//如果存在不合法字符
        if (str.find('.') != std::string::npos){
            if(str.find('.')!=str.rfind('.')) return 0;
            std::string::size_type n;
            //n = str.find(".");
            str.erase(str.find('.'));
        }
        char temp = str[0];
        int i;
        if (temp == '-'){
            flag = 0;
            i = 1;
        }
        else if (temp == '+'){
            flag = 1;
            i = 1;
        }
        else
            i = 0;
        while (i<str.size())
        {
            int a = str[i]-48;
            num = num * 10 + a;
            i++;
        }
        if (flag == 0) num = num * (-1);
        return num;
}
/******************************结束写代码******************************/


int main() {
    int res;

    string _str;
    getline(cin, _str);

    res = string2int(_str);
    cout << res << endl;

    return 0;

}
