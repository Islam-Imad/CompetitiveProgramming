#include <bits/stdc++.h>
using namespace std;

#define ll long long int
template <typename T=int>
class DSU{
private:
    vector<T>Leader,Rank;
    vector<long long>Gsize;
    int forests;
public:
    DSU(T n){
        forests=n;
        Leader=vector<T>(n),Rank=vector<T>(n),Gsize=vector<long long>(n,1ll);
        for(int i=0;i<n;++i)Leader[i]=i;
    }
    void Union(T u,T v){
        u=Get_Leader(u),v=Get_Leader(v);
        if(u==v)return;
        if(Rank[u]<Rank[v])swap(u,v);
        Leader[v] = u;
        Gsize[u]+=Gsize[v];
        Rank[u]+=(Rank[u]==Rank[v]);
        --forests;
    }
    bool SameSet(T u,T v){
        return (Get_Leader(v)==Get_Leader(u));
    }
    T Get_Leader(T u){
        return Leader[u]=(Leader[u]==u ? u : Get_Leader(Leader[u]));
    }
    ll Get_Size(T u){
        return Gsize[Get_Leader(u)];
    }
    int CC(){return forests;}
};

void Solve(){
    int n,m;
    while(cin>>n>>m){
        DSU<int>D(n+5);
        map<char,int>mp;
        int it = 1 , cnt = 1;
        for(int i=1;i<=m;++i){
            char a,b;cin>>a>>b;
            if(mp.count(a)==0)mp[a] = it++;
            if(mp.count(b)==0)mp[b] = it++;
            cnt+=(D.SameSet(mp[a],mp[b]));
            D.Union(mp[a],mp[b]);
        }
        cout << cnt << "\n";
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
