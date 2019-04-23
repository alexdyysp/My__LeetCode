#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        if(nums.size()==0)
            return result;
        if(nums.size()==1) {
            result.push_back(dopath(nums, 0, 0));
            return result;
        }
        int l=0;
        int temp = nums[0];
        for(int i=1; i<nums.size(); i++){
            if(nums[i]!=temp+1){
                result.push_back(dopath(nums, l, i-1));
                l = i;
            }
            temp = nums[i];
            if(i == nums.size()-1){
                result.push_back(dopath(nums, l, i));
            }
        }
        return result;
    }

    string dopath(vector<int>& nums, int l, int r){
        string p;
        if(l == r) {
            p.append(to_string(nums[l]));
            return p;
        }
        p.append(to_string(nums[l])+"->"+to_string(nums[r]));
        return p;
    }
};
int main(){
    vector<int> s = {0,1,2,6,9};
    Solution so;
    vector<string> ss = so.summaryRanges(s);
    for(auto i:ss)
        cout<<i<< " ";
    string ll = so.dopath(s,2,3);
    cout<<ll<<endl;
    return 0;
}
