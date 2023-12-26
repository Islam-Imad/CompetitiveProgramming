#include <bits/stdc++.h>
using namespace std;

#define ll long long int
struct DSU{
    vector<int>Leader,Rank,Gsize;
    int forests;
    DSU(int n){
        forests=n;
        Leader = Rank  = vector<int>(n);
        Gsize=vector<int>(n,1);
        for(int i=0;i<n;++i)Leader[i]=i;
    }
    void Union(int u,int v){
        u=Get_Leader(u),v=Get_Leader(v);
        if(u==v)return;
        if(Rank[u]<Rank[v])swap(u,v);
        Leader[v] = u;
        Gsize[u]+=Gsize[v];
        Rank[u]+=(Rank[u]==Rank[v]);
        --forests;
    }
    bool SameSet(int u,int v){
        return (Get_Leader(v)==Get_Leader(u));
    }
    int Get_Leader(int u){
        return Leader[u]=(Leader[u]==u ? u : Get_Leader(Leader[u]));
    }
    // overflow?!
    int Get_Size(int u){
        return Gsize[Get_Leader(u)];
    }
    int CC(){return forests;}
};

void Solve(){
    int n,m,ret1=0,ret2=1000000000;
    cin>>n>>m;
    vector<bool>vis(m);
    vector<pair<int,pair<int,int>>>edges(m);
    DSU D(n);
    for(int i=0;i<m;++i){
        cin>>edges[i].second.first;
        cin>>edges[i].second.second;
        cin>>edges[i].first;
        edges[i].second.first--;
        edges[i].second.second--;
    }
    sort(edges.begin(),edges.end());
    for(int i=0;i<m;++i){
        if(D.SameSet(edges[i].second.first,edges[i].second.second)==0){
            vis[i]=1;
            D.Union(edges[i].second.first,edges[i].second.second);
            ret1 += edges[i].first;
        }
    }
    for(int j=0;j<m;++j){
        if(vis[j]){
        DSU D2(n);
        int cur = 0;
        for(int i=0;i<m;++i){
            if(i==j)continue;
            if(D2.SameSet(edges[i].second.first,edges[i].second.second)==0){
            D2.Union(edges[i].second.first,edges[i].second.second);
            cur += edges[i].first;
            }
        }
        if(D2.CC()==1)ret2=min(ret2,cur);
        }
    }
    cout << ret1 << ' ' << ret2 << "\n";
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
