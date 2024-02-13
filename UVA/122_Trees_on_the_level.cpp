#include <bits/stdc++.h>
using namespace std;

#define ll long long int

vector<pair<ll,string>>v;
int n,fl=1;

bool get_input(string x){
    string cur = "";
    int ret=0;
    pair<ll,string>p;
    
    for(int i=0;i<x.size();++i){
        if(x[i]=='('){
            for(int j=i+1;j<x.size();++j){
                if(x[j]==','){
                    fl &= (cur.empty()==0);
                    p.first=stoll(cur);
                    cur = "";
                }
                else if(x[j]==')'){
                    if(x[j-1]=='(')ret=1;
                    else{
                        p.second=cur;
                        cur="";
                        v.push_back(p);
                    }
                    i = j;
                    break;
                }
                else cur+=x[j];
            }
        }
    }
    return ret;
}

void Solve(){
    while(true){
        fl = 1;
        string x = "";
        map<string,ll>mp;

        while(getline(cin,x)&&x!=""){
            if(get_input(x)){
                break;
            }
        }
        if(x=="")return;

    for(int i=0;i<v.size();++i){
        if(mp.count(v[i].second)==0){
            mp[v[i].second]=v[i].first;
        }
        else fl&=(mp[v[i].second]==v[i].first);
    }

    if(fl==0 or mp.count("")==0){
        cout << "not complete\n";
    }
    else{
        string src = "",dir;
        queue<string>q;
        q.push(src);
        vector<int>ret;
        while(!q.empty()){
            src = q.front();
            q.pop();
            ret.push_back(mp[src]);
            
            dir = src + 'L';
            if(mp.count(dir))q.push(dir);
            
            dir = src + 'R';
            if(mp.count(dir))q.push(dir);
        }
        if(ret.size()!=v.size())cout << "not complete\n";
        else
        for(int i=0;i<ret.size();++i)cout << ret[i] << " \n"[i+1==ret.size()];
    }
    fl = 1,v.clear();
    }
}

int main()
{
    ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
    #endif
    int tc=1;
    // cin>>tc;
    while(tc--)Solve();
}
