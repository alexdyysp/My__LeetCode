Include C++ useful methods and functions
================================
Some alogrithm:
---------------
递归算法

分治算法
二分查找

贪心算法
DFS: 算法走到底部才能判断解是否合法

增量构造
位向量法

动态规划
递归计算/递推计算/记忆化搜索

  
  
Some methods:
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
```
int index = occur;                      //起始从occur位判断
    for(int i = 2 ; i < nums.size() ; i++)
        if(nums[i]!=nums[index-occur])  //往前判断occur位，则可以接受occur位重复
            nums[index++] = nums[i];    //有重复则往前移一位
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
