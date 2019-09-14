#include <bits/stdc++.h>
using namespace std;

bool pairbracket(int qele, int sele){
    // qele: stack.top(); sele: string[i]
    bool flag = false;
    if (sele == '}' && qele == '{')
        flag = true;
    if (sele == ']' && qele == '[')
        flag = true;
    if (sele == ')' && qele == '(')
        flag = true;
    return flag;
}
int isValid(string s) {
    stack<char> q;
    if(!s.length()) return true;
    for (int i=0; i<s.length(); i++){
        // if no element means insert
        if (!q.size()) {
            q.push(s[i]);
            continue;
        }
        // match the pair
        if ( pairbracket(q.top(), s[i]) )
            q.pop();
        else
            q.push(s[i]);
    }
    // if all pair is matched the stack should be 0 size
    return q.size();

}

int main(){
    string input;
    cin>>input;

    int result = isValid(input);
    cout<<result<<endl;

    return 0;
}
