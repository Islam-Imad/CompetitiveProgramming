#include <bits/stdc++.h>
using namespace std;

#define ll long long int
bool com(char cur,char b){
    if(cur=='-' || cur =='+'){
        return b == '-' or b=='+' or b=='/' or b=='*';
    }
    else if(cur=='*' || cur =='/'){
        return b=='/' or b=='*';
    }
    return false;
}

void Solve(){
    vector<char>v;
    v.push_back('(');
    string ret = "",stc;
    while(getline(cin,stc)&&stc!=""){
        if(isdigit(stc[0]))ret.push_back(stc[0]);
        else{
            if(stc[0]==')'){
            while(v.back()!='('){
            ret.push_back(v.back());
            v.pop_back();
            }
            v.pop_back();
            }
            else if(stc[0]=='('){
                v.push_back(stc[0]);
            }
            else{
            while(com(stc[0],v.back())){
                ret.push_back(v.back());
                v.pop_back();
            }
            v.push_back(stc[0]);
            }
        }
    }
    while(v.back()!='('){
        ret.push_back(v.back());
        v.pop_back();
    }
    v.pop_back();
    cout << ret << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
    #endif
    string x;
    int tc=1;
    cin>>tc;
    cin.ignore();
    getline(cin,x);
    while(tc--){
        Solve();
        if(tc)cout << '\n';
    }
}
