#include <bits/stdc++.h>
using namespace std;
//树结点，结点间最短路径距离，求出其中最大值
//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
// 先序遍历输出
void preorder(TreeNode* root){
    if(!root) return;
    cout<<root->val<<" ";
    preorder(root->left);
    preorder(root->right);
}

int maxdepth(TreeNode* root){
    if(!root) return 0;
    return max(maxdepth(root->left), maxdepth(root->right))+1;
}

void maxdist(TreeNode* root, vector<int>& dist){
    if(!root) return;
    int d = maxdepth(root->left)+maxdepth(root->right);
    cout<<root->val<<": "<<d<<endl;
    dist.push_back(d);
    maxdist(root->left, dist);
    maxdist(root->right, dist);
}

int main(){
    // Creat Tree
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);
    // Print Tree
    preorder(root);
    cout<<endl;
    // cal
    vector<int> dist;
    cout<<"Depth of Tree: "<<maxdepth(root)<<endl;
    maxdist(root, dist);
    vector<int>::iterator max=max_element(dist.begin(),dist.end());
    cout<<"最长距离是："<<*max<<endl;
    return 0;
}
