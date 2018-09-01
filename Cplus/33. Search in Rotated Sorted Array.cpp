#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int first = 0 , last = nums.size()-1;
        while(first != last){
            const int mid = first + (last - first)/ 2;
            //cout<<"1 : "<<first<<" "<<mid<<" "<<last<<" "<<endl;
            if(nums[mid] == target) return mid;
            if(nums[first] <= nums[mid])
            {
                if(nums[first] <= target && target < nums[mid])
                    last = mid;
                else
                    first = mid + 1;
            }
            else
            {
                if(nums[mid] < target && target <= nums[last])
                    first = mid + 1;
                else
                    last = mid;
            }
            //cout<<"2 : "<<first<<" "<<mid<<" "<<last<<" "<<endl;
            if(nums[first] == target) return first;
        }
        return - 1;
    }
};
int main()
{
    int target;
    vector<int> nums = {5,6,0,1,2,3,4};
    target =5;
    Solution so;
    cout<< so.search(nums,target)<<endl;
    return 0;
}
