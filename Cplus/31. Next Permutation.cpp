#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        vector<int>::iterator i;
        vector<int>::iterator j=nums.end()-1;
        //step1:从右往左找j=max{i|pi<pi+1}
        for(i=nums.end()-1;i != nums.begin();i--){
            if( *i > *(i-1) )
                break;
        }
        if(i!=nums.begin()){
            //step2:找到k=max{i|pi>pj}
            while(j!=i-1 && *j<=*(i-1)){
                j--;
            }
            //step3:swap(pk,pj)
            swap(*(i-1),*j);
        }
        //step4: 倒置所有j后的序列
        reverse(i,nums.end());
    }
    /*
    template <class BidirectionalIterator>
    void reverse (BidirectionalIterator first, BidirectionalIterator last)
    {
      while ((first!=last)&&(first!=--last)) {
        iter_swap (first,last);
        ++first;
      }
    }
    template<class T>
    void swap(T& a,T& b)
    {
        T c(a);
        a=b;
        b=c;
    }
    */
};
int main()
{
    Solution so;
    vector<int> arr = {1,2,4,3,5};
    for(vector<int>::iterator i=arr.begin();i!= arr.end();i++)
    {
        cout<<*i<<" ";
    }
    cout<<endl;
    so.nextPermutation(arr);
    for(vector<int>::iterator i=arr.begin();i!= arr.end();i++)
    {
        cout<<*i<<" ";
    }
    cout<<endl;
    return 0;
}
