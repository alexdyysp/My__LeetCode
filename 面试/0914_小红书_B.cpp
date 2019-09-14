#include <bits/stdc++.h>
#include <sstream>

using namespace std;

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

string format(string line, int M){
    string result;
    int k = (M-line.length())/2;
    while(k--)
        result += " ";
    result += line;
    return result;
}

int main(){
    // input
    int M;
    cin>>M;
    cin.ignore();

    string input;
    getline(cin, input);

    vector<string> dst;

    StrSplit(input, " ", dst);
    //for(size_t  i=0; i<dst.size(); i++)
    //    cout<<dst[i]<<", ";
    //cout<<endl;
    // progress
    int tmplen = dst[0].length();
    string line = dst[0];
    /*
    if(tmplen==M) {
        cout<<dst[0]<<endl;
        tmplen = 0;
        line.clear();
    }
*/
    for(int i=1; i<dst.size(); i++){
        cout<<"scan: "<<dst[i]<<" "<<"tmplen: "<<tmplen<<endl;

        if((tmplen+dst[i].length()+1)<=M){
            line +=" " + dst[i];
            tmplen += dst[i].length()+1;
        }else{
            cout<<format(line, M)<<endl;
            line.clear();
            line += dst[i];
            tmplen = dst[i].length();
        }

        if(i==dst.size()-1){
            cout<<format(line, M)<<endl;
        }
    }

    if(dst.size()==1)
        cout<<format(dst[0], M)<<endl;


}
