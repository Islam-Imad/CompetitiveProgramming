#include <bits/stdc++.h>
using namespace std;

#define ll long long int
const int N = 130 ;
const char ch='A';
string cur;
struct Trie{
    Trie* child[N];
    bool is_leaf;
    Trie(){
        memset(child,0,sizeof(child));
        is_leaf=0;
    }
    void insert(char *str){
        if(*str=='\0')is_leaf=1;
        else{
            int idx=(int)(*str);
            if(child[idx]==0)child[idx]=new Trie();
            child[idx]->insert(++str);
        }
    }
    bool wordExist(char *str){
        if(*str=='\0')return (is_leaf);
        else{
            int idx=(int)(*str);
            if(child[idx]==0)return false;
            return child[idx]->wordExist(++str);
        }
    }
    bool prefixExist(char *str){
        if(*str=='\0') return true;
        else{
            int idx=(int)(*str);
            if(child[idx]==0)return false;
            return child[idx]->prefixExist(++str);
        }
    }
    void print(int sp,string s){
        if(child[92]||is_leaf){
            for(int i=0;i<sp;++i)cout << ' ';
            cout << s << "\n";
            if(child[92])child[92]->print(sp+1,"");
        }
        for(int i=0;i<130;++i){
            if(child[i]&&i!=92){
                child[i]->print(sp,s+char(i));
            }
        }
    }
};
void Solve(){
    int n;
    while(cin>>n){
        string x;
        Trie root;
        for(int i=1;i<=n;++i){
            cin>>x;
            root.insert(&x[0]);
        }
        root.print(0,"");
        cout << "\n";
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
