# include<bits/stdc++.h>
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
/*
* 一开始想把每个数拿出来，太复杂了，其实有原地加的方法
*/
class Solution1 {
public:
    int sumNumbers(TreeNode* root) {
        vector<vector<int> > result;
        vector<int> path;
        searchtree(root, result, path);
        int sum = 0;
        for(int i=0;i<result.size();i++){
            int ps = result[i].size();
            int temp = 0;
            for(int j=ps-1; j>=0; j--){
                sum += result[i][j] * (int)(pow(10,temp++)+0.5);

            }
        }
        return sum;
    }
//private:
    void searchtree(TreeNode* root, vector<vector<int> >& result, vector<int>& path){
        if(root == NULL) return;
        path.push_back(root->val);
        if(root->left==NULL && root->right==NULL){
            result.push_back(path);
            return;
        }
        TreeNode* rl = root->left;
        if(rl != NULL){
            searchtree(rl, result, path);
            path.pop_back();
        }
        TreeNode* rr = root->right;
        if(rr != NULL){
            searchtree(rr, result, path);
            path.pop_back();
        }
    }
};

class Solution2 {
public:
    int sumNumbers(TreeNode* root) {
        if(root==NULL) return 0;
        int sum;
        getsum(root, sum, 0);
        return sum;
    }
private:
    void getsum(TreeNode* root, int &sum, long asf)
    {
        if(root==NULL)
            return ;
        asf=asf*10 + root->val;
        if(root->left==NULL && root->right==NULL)
        {
            sum += asf;
            return;
        }
        getsum(root->left, sum, asf);
        getsum(root->right, sum, asf);
    }
};
int main(){
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(9);
    root->right = new TreeNode(0);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(1);
    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(3);
    root2->right->left = new TreeNode(5);
    root2->right->right = new TreeNode(4);
    Solution so;
    vector<vector<int> > result;
    vector<int> path;
    TreeNode* test = root;
    so.searchtree(test, result, path);
    cout<<"result.size() = "<<result.size()<<endl;
    for(int i=0;i<result.size();i++){
        int ps = result[i].size();
        for(int j=0;j<ps;j++){
                cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    int r = so.sumNumbers(test);
    cout<<"result:"<<r<<endl;
}
