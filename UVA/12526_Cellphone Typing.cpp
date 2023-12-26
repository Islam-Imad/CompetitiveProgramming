#include <bits/stdc++.h>
using namespace std;

#define ll long long int

const int N = 26 ;
char ch='a';
string cur,pre;
set<string>s;
struct Trie{
    Trie* child[N];
    bool is_leaf;
    int cnt,W;
    Trie(){
        memset(child,0,sizeof(child));
        is_leaf=0;
        cnt=W=0;
    }
    void insert(char *str){
        W++;
        if(*str=='\0')is_leaf=1;
        else{
            int idx=*str-ch;
            if(child[idx]==0)child[idx]=new Trie(),cnt++;
            child[idx]->insert(++str);
        }
    }
    bool wordExist(char *str){
        if(*str=='\0')return (is_leaf);
        else{
            int idx=*str-ch;
            if(child[idx]==0)return false;
            return child[idx]->wordExist(++str);
        }
    }
    bool prefixExist(char *str){
        if(*str=='\0') return true;
        else{
            int idx=*str-ch;
            if(child[idx]==0)return false;
            return child[idx]->prefixExist(++str);
        }
    }
    int ai(){
        int ret=0;
        if(cnt>=2)ret+=W-is_leaf;
        else if(cnt==1&&is_leaf)ret+=W-is_leaf;
        for(int i=0;i<26;++i){
            if(child[i]!=0){
                ret+=child[i]->ai();
            }
        }
        return ret;
    }
};

void Solve(){
    cout << fixed << setprecision(2);
    int n,inc=0;
    while(cin>>n){
    inc=n;
    Trie root;
    string x,y;
    for(int i=1;i<=n;++i){
        cin>>x,y.push_back(x[0]);
        root.insert(&x[0]);
    }
    for(int i=1;i<n;++i)if(y[i]!=y[i-1])inc=0;
    cout << (double)(root.ai()+inc)/(double)(n) << "\n";
    y.clear();
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
/*
stucture 4
stuctures  5
stess 3
solstice 2
re 2
rers 3
riculous 2
*/