# C++ useful methods and functions
```C++
#include <bits/stdc++.h>
using namespace std;
```
## Some functions:

### Array
----------
1. 将有序重复数列1，1，2，2，3，去除occur位重复成1，2，3：
```C++
int index = occur;                      //起始从occur位判断
    for(int i = 2 ; i < nums.size() ; i++)
        if(nums[i]!=nums[index-occur])  //往前判断occur位，则可以接受occur位重复
            nums[index++] = nums[i];    //有重复则往前移一位
```
2. 数组排序
```C++
// sort using a standard library compare function object
std::sort(s.begin(), s.end(), std::greater<int>());

// sort using a lambda expression 
std::sort(s.begin(), s.end(), [](int a, int b) {
    return a > b;   
});
```

### vector
---------
1. 拷贝一个多维vector结构:
```C++
int n = triangle.size()-1;
vector<vector<int>> temp;
for(int i=0; i<=n; i++){
    vector<int> temp_sub(i+1,-1);
    temp.push_back(temp_sub);
}
```
定义一维vector:
```C++
vector <int> ivec(m, value);
```
定义空二维vector，再赋值
```C++
vector<vector <int> > ivec(m ,vector<int>(n)); //m*n的二维vector，注意两个 "> "之间要有空格！
```
定义并初始化二维数组
```C++
vector<vector <int> > ivec(m ,vector<int>(n,0)); //m*n的二维vector，所有元素初始化为0
```
- 求vector的最大值
```C++
vector<int>::iterator max=max_element(dist.begin(),dist.end());
cout<<"最大值是："<<*max<<endl;
//相应的还有min_element()
```
- 打印二维数组
```C++
for(int i=0; i<v.size(); i++){
    for(int j=0; j<v[0].size(); j++) cout<<v[i][j]<<" ";
    cout<<endl;
}
```
### 哈希表HashMap
- 初始化Map
```C++
    map<string, vector<string>> StrMap;
```
- C++中，若一个Map里没有该键，则会自动创建一个
```C++
    // 可以直接对Map存储vector添加元素
    StrMap[tmp].push_back(s);
```

- 如果只想确认有无键，不想创建这个键
```C++
    HashMap.count(key);
```

- 使用迭代器打印哈希表resTree,哈希表默认key从小到大排序
```C++
for(auto it=resTree.begin(); it!=resTree.end(); it++)
    cout<<it->first->val<<" "<<it->second->val<<endl;
```

- 智能指针遍历HashMap
```C++
    for(auto &m:StrMap)
        result.push_back(m.second);
```
### 链表
---------
0. Definition for singly-linked list.
```C++ 
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
```


1. 断链操作。将链表 l 切掉前 n 个节点，并返回后半部分的链表头。
```C++
ListNode* cut(ListNode* head, int n){ 
  ListNode* p = head; 
  while (--n && p) p = p->next;  
  if (!p) return nullptr; 
  ListNode* tmp = p->next; // 有必要保存中间节点，因为下一步需要断链!
  p->next = nullptr; 
  return tmp; 
} 
```
2. 按顺序合并L1与L2链表
```C++
ListNode* merge(ListNode* L1, ListNode* L2) { 
  ListNode dummyHead(0); 
  ListNode* p = &dummyHead; 
  while (L1 && L2) {
    if (L1->val < L2->val) {
      p->next = L1; 
      p = L1; 
      L1 = L1->next; 
    } else {
      p->next = L2; 
      p = L2; 
      L2 = L2->next; 
    }
  }
  p->next = L1 ? L1 : L2; 
  return dummyHead.next; 
}

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* pre = dummy;
        while(l1 && l2){
            if(l1->val < l2->val) {pre->next = l1; l1=l1->next;}
            else {pre->next = l2; l2=l2->next;}
            pre = pre->next;
        }
        if(l1==nullptr && l2!=nullptr) pre->next = l2;
        if(l1!=nullptr && l2==nullptr) pre->next = l1;
        return dummy->next;
    }
```

### String
-----------
1. 我们可以使用在指定string串中查找有无匹配字符，判断提取str是否为我们想要的字符串:
```C++
bool is_opera(string str){
    return str.size()==1 && string("+-*/").find(str) != string::npos;
}
```
2. 分割字符串，并将分割后的字段保存进vector
```C++
void StrSplit(const string& src, const string& sep, vector<string>& dst){
    string s;
    for (string::const_iterator it = src.begin(); it != src.end(); it++){
        if (sep.find(*it) != string::npos){
            if (s.length()) dst.push_back(s);
            s.clear();
        }
        else
            s += *it;
    }

    if (s.length())
        dst.push_back(s);
    }
```
3. streamstring来分割字符串
```C++
        stringstream is(path);
        string tmp = "";
        while(getline(is, tmp, '/')) {
            cout<<tmp<<endl;
        }
        /*
        input: "/a//b////c/d//././/.."
        output: 
                a
                b
                c
                d
                .
                .
                ..
          此方法，严格按tmp字符分割
        */
```
```C++
    string s = "the sky is blue";
    string str;
    vector<string> tmp;
    stringstream ss(s);
    while (ss >> str) tmp.push_back(str);
    /* tmp = ['the', 'sky', 'is', 'blue'] 
      此方法可跳过开头末尾的空格
    */
```
Tree
----
0. 定义树结构
```C++
 //Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
// 赋值
TreeNode* root = new TreeNode(3);
root->left = new TreeNode(5);
 ```
- 计算树的结点个数
```C++
int nodecount(TreeNode* root){
    if (!root) return 0;
    return nodecount(root->left) + nodecount(root->right) + 1;
}
```
*基础*:
1. 前中后序遍历二叉树,和Morris遍历<br>
2. 计算二叉树深度<br>
3. Mirrors Traversol
- Time=O(n), Space=O(1)<br>
- 1.find left subtree<br>
- 2.find the rightest treenode<br>
- 3.clue the node in step 2 with current root<br>
- Mirror is a method of tree traversal, so it can nest a lot of operations on the binary tree<br>
