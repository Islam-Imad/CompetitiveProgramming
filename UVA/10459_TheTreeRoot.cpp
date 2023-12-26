#include <bits/stdc++.h>
using namespace std;

#define ll long long int

const int N = 5000+5;

int dp[N],vis[N],n;
vector<int>adj[N];
vector<pair<int,int>>M2;

void dfs(int node){
    vis[node]=1;
    for(auto &u:adj[node]){
        if(vis[u])continue;
        dfs(u);
        
        dp[node]=max(1+dp[u],dp[node]);

        if(dp[u]+1>M2[node].first){
            M2[node].second = M2[node].first;
            M2[node].first=dp[u]+1;
        }
        else if(dp[u]+1>M2[node].second){
            M2[node].second=dp[u]+1;
        }
    }
}

void calc(int node){
    vis[node]=1;
    for(auto &u:adj[node]){
        if(vis[u])continue;

        if(M2[node].first!=1+dp[u]){
            dp[u]=max(dp[u] , M2[node].first+1);
            if(M2[node].first+1>M2[u].first){
                M2[u].second=M2[u].first,M2[u].first=1+M2[node].first;
            }
            else M2[u].second=max(M2[u].second,1+M2[node].first);
        }
        else {
            dp[u]=max(dp[u] , M2[node].second+1);
            if(M2[node].second+1>M2[u].first){
                M2[u].second=M2[u].first,M2[u].first=1+M2[node].second;
            }
            else M2[u].second=max(M2[u].second,1+M2[node].second);

        }
        
        calc(u);
    }
}

void solve(){
    while(cin>>n&&n){
    M2 = vector<pair<int,int>>(n+5);
    for(int i=1;i<=n;++i){
        int m;cin>>m;
        for(int j=1;j<=m;++j){
            int a;cin>>a;
            adj[i].push_back(a);
        }
    }
    
    dfs(1);
    for(int i=1;i<=n;++i)vis[i]=0;
    calc(1);



    int Min = INT_MAX,Max=INT_MIN;
    for(int i=1;i<=n;++i){
        Min=min(Min,dp[i]),Max=max(Max,dp[i]);
    }
    vector<int>good,bad;
    for(int i=1;i<=n;++i){
        if(dp[i]==Min&&dp[i]!=Max)good.push_back(i);
        if(dp[i]==Max&&dp[i])bad.push_back(i);
    }

    cout << "Best Roots  : ";
    for(int j=0;j<good.size();++j)cout << good[j] << " \n"[j+1==good.size()];
    cout << "Worst Roots : ";
    for(int j=0;j<bad.size();++j)cout << bad[j] << " \n"[j+1==bad.size()];
    // clear
    for(int i=1;i<=n;++i)adj[i].clear(),vis[i]=0,dp[i]=0;
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
    while(tc--){
        solve();
    }
}