#include <bits/stdc++.h>
using namespace std;

#define ll long long int

int n,m,q,test=1;
ll sum = 0;

ll bfs(int src,vector<vector<int>>&adj,vector<int>cost){
    ll ret = 0;
    vector<int>vis(n+1);
    queue<int>q;
    q.push(src);
    vis[src] = 1;
    while(!q.empty()){
        src = q.front();
        q.pop();
        for(int u:adj[src]){
            if(!vis[u]){
                vis[u] = 1;
                q.push(u);
                ret+=cost[u];
            }
        }
    }
    return ret;
}

void Solve(){
    while(cin>>n>>m and n!=0){

    sum = 0;
    vector<int>cost(n+1);
    vector<vector<int>>adj1(n+1),adj2(n+1);
    for(int i=1;i<=n;++i)cin>>cost[i],sum+=cost[i];
    for(int i=1;i<=m;++i){
        int a,b;cin>>a>>b;
        adj1[a].push_back(b);
        adj2[b].push_back(a);
    }
    cin>>q;
    cout << "Case #" << test++ << ":\n";
    for(int i=1;i<=q;++i){
        int vert;cin>>vert;
        ll Min = bfs(vert,adj1,cost) , Max = sum - (bfs(vert,adj2,cost)+cost[vert]);
        cout << Max - Min << '\n';
    }
    cout << '\n';

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
