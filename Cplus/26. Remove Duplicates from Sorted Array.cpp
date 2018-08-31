#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        int index = 1;
        for(int i=1 ; i < nums.size() ; i++)
        {
            if(nums[i] != nums[index-1])
                nums[index++] = nums[i];
                for (int j = 0; j < nums.size() ; j++)
                    cout<<nums[j]<< " " ;
                    cout<<endl;
            cout<<"index="<<index<<endl;
        }
    return index+1;
    }
};
int main()
{
    Solution so;
    vector<int> nums = {1,1,1,2,2,3,4,4,4,4,5,5};
    int len = so.removeDuplicates(nums);
    /***
    for (int i = 0; i < len; i++)
        cout<<nums[i]<< " " ;
    ***/
    return 0;
}
