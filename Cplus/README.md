Include C++ useful methods and functions
================================
# Some alogrithm:
---------------
递归算法

分治算法
二分查找

### 贪心算法：
- 双端搜索：int left,right; while(left < right)

DFS: 算法走到底部才能判断解是否合法
BFS:

增量构造
位向量法

### 动态规划
递归计算/递推计算/记忆化搜索
#### 定义
- 本质：递归 
- 原问题（N）->子问题（N-1）->原问题（N）
- 最优子结构 
  + 子问题最优决策可导出原问题最优决策  
  + 无后效性 
- 重叠子问题 
  + 去冗余 
  + 空间换时间（注意分析时空复杂度）

  
  
# Some methods:
-------------
1.Binary Tree
--------------
*Mirrors Traversol*<br>
- Time=O(n), Space=O(1)<br>
- 1.find left subtree<br>
- 2.find the rightest treenode<br>
- 3.clue the node in step 2 with current root<br>
- Mirror is a method of tree traversal, so it can nest a lot of operations on the binary tree<br>

2.求集合幂集合<br>
每个集合元素都有选择和不选择两种置入方法<br>
Some functions:
---------------
Array
-----
1. 将有序重复数列1，1，2，2，3，去除occur位重复成1，2，3：
```C++
int index = occur;                      //起始从occur位判断
    for(int i = 2 ; i < nums.size() ; i++)
        if(nums[i]!=nums[index-occur])  //往前判断occur位，则可以接受occur位重复
            nums[index++] = nums[i];    //有重复则往前移一位
```



vector
-------
1. 拷贝一个多维vector结构:
```C++
        int n = triangle.size()-1;
        vector<vector<int>> temp;
        for(int i=0; i<=n; i++){
            vector<int> temp_sub(i+1,-1);
            temp.push_back(temp_sub);
        }
```
定义空二维vector，再赋值
```C++
vector<vector <int> > ivec(m ,vector<int>(n)); //m*n的二维vector，注意两个 "> "之间要有空格！
```
定义并初始化二维数组
```C++
vector<vector <int> > ivec(m ,vector<int>(n,0)); //m*n的二维vector，所有元素初始化为0
```

String
------
1. 我们可以使用在指定string串中查找有无匹配字符，判断提取str是否为我们想要的字符串:
```C++
bool is_opera(string str){
    return str.size()==1 && string("+-*/").find(str) != string::npos;
}
```

Tree
----
*基础*:
1. 前中后序遍历二叉树,和Morris遍历<br>
2. 计算二叉树深度<br>
