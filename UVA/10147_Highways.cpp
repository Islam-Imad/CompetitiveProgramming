#include <bits/stdc++.h>
using namespace std;

#define ll long long int
struct edge{
    int x,y,w;
    edge(int x,int y,int w):x(x),y(y),w(w){}
    bool operator < (const edge&a)const{
        return w < a.w;
    }
};
struct DSU{
    public:
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
    int n;cin>>n;
    DSU D(n);
    vector<pair<ll,ll>>v(n);
    vector<edge>edges;
    for(int i=0;i<n;++i)cin>>v[i].first>>v[i].second;
    for(int i=0;i<n;++i){
        for(int j=i+1;j<n;++j){
            ll cost = ((v[i].first-v[j].first) * (v[i].first-v[j].first));
            cost += ((v[i].second-v[j].second) * (v[i].second-v[j].second));
            edges.push_back(edge(i,j,cost));
        }
    }
    sort(edges.begin(),edges.end());
    
    int m;cin>>m;
    for(int i=1;i<=m;++i){
        int a,b;cin>>a>>b;
        --a,--b;
        D.Union(a,b);
    }
    vector<pair<int,int>>ret;
    for(int i=0;i<edges.size();++i){
        if(D.SameSet(edges[i].x,edges[i].y)==0){
            D.Union(edges[i].x,edges[i].y);
            ret.push_back({edges[i].x,edges[i].y});
        }
    }
    if(ret.empty()){
        cout << "No new highways need\n";
    }
    else{
        for(int i=0;i<ret.size();++i)cout << ret[i].first+1 << ' '<< ret[i].second+1 << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
    #endif
    int tc=1;
    cin>>tc;
    while(tc--){
        Solve();
        if(tc)cout << '\n';
    }
}
