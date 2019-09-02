#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main() {
    int arr[7] = {1,2,2,2,1,3,5};
    vector<int> result;
    map<int,int> dict;
    for(int i=0; i<7; i++){
        if(dict.count(arr[i])){
            dict[arr[i]]++;
            //cout<<dict[arr[i]]<<endl;
        }else{
            dict[arr[i]]=1;
        }
    }
    for (map<int,int>::reverse_iterator it = dict.rbegin(); it != dict.rend(); it++){
        //cout << it->first << ':' << it->second << '\n';
        cout<<it->first<<it->second<<endl;
    }
    for(int i=0;i<7;i++){
       if(dict[arr[i]]==1)
           result.push_back(arr[i]);
    }
    for(int i=0;i<result.size();i++)
        cout << result[i] <<",";
}

/*
很简单的一道题，居然因为map查询的api失误挂了，一面就挂，很伤心
*/
