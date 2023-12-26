#include <bits/stdc++.h>
using namespace std;

#define ll long long int
const int N = 10009;
int n,m,c=1,vis[N],cur;
vector<int>adj[N];
void dfs(int node,int depth){
    vis[node]=1;
    if(depth>cur){
        cur=depth,c=node;
    }
    for(auto &pr:adj[node]){
        if(vis[pr])continue;
        dfs(pr,depth+1);
    }
}
void Solve(){
    cin>>n;
    for(int i=1;i<=n;++i){
        int t;cin>>t;
        for(int k=1;k<=t;++k){
            int b;cin>>b;
            adj[i].push_back(b);
            adj[b].push_back(i);
        }
    }
    dfs(1,0);

    cur=0;
    memset(vis,0,sizeof(vis));

    dfs(c,0);

    cout << (2*(n-1)-cur) << '\n';

    memset(vis,0,sizeof(vis));
    cur = 0;
    
    for(int i=1;i<=n;++i)adj[i].clear();
}

int main()
{
    ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
    #endif
    int tc=1;
    cin>>tc;
    while(tc--)Solve();
}
