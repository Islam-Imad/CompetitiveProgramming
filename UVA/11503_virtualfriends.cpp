#include <bits/stdc++.h>
using namespace std;

#define ll long long int

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
map<string,int>mp;
int cur = 1;
int get_id(string x){
    if(mp[x]==0)mp[x]=cur++;
    return mp[x];
}

void Solve(){
    cur =1;
    int m,id1,id2;cin>>m;
    DSU D(2*m);
    for(int i=1;i<=m;++i){
        string x,y;cin>>x>>y;
        id1=get_id(x),id2=get_id(y);
        D.Union(id1,id2);
        cout << D.Get_Size(id1) << '\n';
    }
    // initialization
    mp.clear();
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
