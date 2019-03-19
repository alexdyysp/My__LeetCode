头文件
=====
```C++
#include <bits/stdc++.h>
using namespace std;
```  
即可载入所有类型函数

输入与输出
=========
1. 输入一些数
```C++
while(scanf("%d %d",&x,&y)==2)
		cout<<x<<' '<<y;
```

输入完毕之后先按Enter，再按ctrl+Z，最后再按Enter键，即可结束输入。Linux下，输入完毕后按ctrl+D即可结束输

```C++
int main()
{
    int a, b;
    while (cin >> a >> b)
        cout << a + b << "\n";
    return 0;
}
```

2.文件读取与写入
头文件iostream中包含着对输入输出流的定义。
第2种方法也可以修改成文件输入输出流的方法。当然也可以用freopen对文件进行重定向，不过更正统的方法如下：

复制代码
```C++
ifstream fin("aplusb.in");
ofstream fout("aplusb.out");
int main()
{
    int a, b;
    while (fin >> a >> b)
        fout << a + b << "\n";
    return 0;
}
```
