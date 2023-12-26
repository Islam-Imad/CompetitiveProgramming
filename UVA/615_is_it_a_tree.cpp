#include <bits/stdc++.h>
using namespace std;

// #define ll long long int
#define int long long
vector<pair<int,int>>v;
vector<vector<int>>adj;
int root=-1,test=1,max_size=0;
void pre(){
    map<int,int>mp;
    int nxt=1;
    root=-1,max_size=0;
    for(int i=0;i<v.size();++i){
        if(mp.count(v[i].first)==0){
            mp[v[i].first]=nxt++;
        }
        if(mp.count(v[i].second)==0){
            mp[v[i].second]=nxt++;
        }
    }
    for(int i=0;i<v.size();++i){
        v[i].first=mp[v[i].first];
        v[i].second=mp[v[i].second];
    }
    max_size=nxt+5;
    vector<int>indegree(nxt+5);
    adj = vector<vector<int>>(nxt+5);
    for(int i=0;i<v.size();++i){
        indegree[v[i].second]++;
        adj[v[i].first].push_back(v[i].second);
    }
    for(int i=1;i<nxt;++i){
        if(indegree[i]==0){
            if(root==-1)
                root = i;
            else{
                root =-1;
                return;
            }
        }
        else if(indegree[i]!=1){
            root =-1;
            return;
        }
    }
}

void dfs(int node,vector<bool>&vis){
    if(root==-1)return;
    vis[node] = 1;
    for(int u:adj[node]){
        if(vis[u]){
            root=-1;
            return;
        }
        dfs(u,vis);
    }
}

void Solve(){
    int a,b,it=1;
    while(cin>>a>>b){
        if(a<=-1&&b<=-1)return;
        v.push_back({a,b});
        if(a==0&&b==0){
            v.pop_back();
            pre();
            vector<bool>vis(max_size,0);
            dfs(root,vis);
            if(root!=-1 ){
                for(int i=1;i<max_size-5;++i)if(!vis[i])root=-1;
            }
            if(root!=-1 or max_size == 6){
                cout << "Case" << ' ' << test << ' ' << "is a tree.\n";
            }
            else{
                cout << "Case" << ' ' << test << ' ' << "is not a tree.\n";
            }
            v.clear();
            test++;
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
    #endif
    int tc=1;
    // cin>>tc;
    while(tc--)Solve();
}
