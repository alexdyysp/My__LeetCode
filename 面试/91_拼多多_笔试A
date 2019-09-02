#include <bits/stdc++.h>
using namespace std;
/*
给一连串数字，按要求给出TopN的数字：
- 偶数比奇书要考前
- 大数比小数考前
*/

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
int main(){
    vector<string> str;
    vector<string> str_1;
    vector<int> odd;
    vector<int> even;
    vector<int> result;
    string input;
    int TopN;
    cin>>input;
    StrSplit(input, ",", str);
    for(int i=0;i<str.size();i++){
        if(i==str.size()-1){
            StrSplit(str[i],";",str_1);
            str[i]=str_1[0];
            TopN = atoi(str_1[1].c_str());
        }
        int num = atoi(str[i].c_str());
        if (num%2)
            odd.push_back(num);
        else
            even.push_back(num);

    }
    cout<<TopN<<endl;
    cout<<"odd"<<endl;
    for(int i=0;i<odd.size();i++)
        cout<<odd[i]<<"|";
    cout<<endl;
    cout<<"even"<<endl;
    for(int i=0;i<even.size();i++)
        cout<<even[i]<<"|";
    sort(odd.begin(), odd.end(), greater<int>());
    sort(even.begin(), even.end(), greater<int>());
    int even_end = even.size();
    int even_start = 0;
    int odd_end = odd.size();
    int odd_start = 0;
    while(TopN){
        if(even_end){
            result.push_back(even[even_start]);
            even_start++;
            even_end--;
        }else if(odd_end){
            result.push_back(odd[odd_start]);
            odd_start++;
            odd_end--;
        }

        TopN--;
    }
    cout<<"topn"<<endl;
    for(int i=0;i<result.size();i++){
        if(i!=result.size()-1)
            cout<<result[i]<<",";
        else
            cout<<result[i]<<endl;

    }
    return 0;
}
