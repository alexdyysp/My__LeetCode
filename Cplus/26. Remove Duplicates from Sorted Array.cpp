#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        int index = 0;
        for(int i=1 ; i < nums.size() ; i++)
        {
            if(nums[i] != nums[index])
                nums[++index] = nums[i];
        }
    return index+1;
    }
};
int main()
{
    Solution so;
    vector<int> nums = {1,1,2,2,3};
    int len = so.removeDuplicates(nums);
    for (int i = 0; i < len; i++)
    {
        cout<<nums[i]<< " " ;
    }
    return 0;
}
