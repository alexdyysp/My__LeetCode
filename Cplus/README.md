# C++ useful methods and functions

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
Tree
----
0. 定义树结构
```C++
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
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
