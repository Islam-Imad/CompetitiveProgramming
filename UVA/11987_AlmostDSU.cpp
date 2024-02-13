#include <bits/stdc++.h>
using namespace std;

#define ll long long int

struct DSU{
    public:
    vector<ll>sums;
    vector<int>Leader,Rank,Gsize;
    int forests;
    DSU(int n){
        forests=n;
        Leader = Rank  = vector<int>(n);
        Gsize=vector<int>(n,1);
        sums = vector<ll>(n);
        for(int i=0;i<n;++i)Leader[i]=i;
    }
    void Union(int u,int v){
        u=Get_Leader(u),v=Get_Leader(v);
        if(u==v)return;
        if(Rank[u]<Rank[v])swap(u,v);
        Leader[v] = u;
        Gsize[u]+=Gsize[v];
        sums[u]+=sums[v];
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
    ll Get_Size(int u){
        return Gsize[Get_Leader(u)];
    }
    ll Get_Sum(int u){
        return sums[Get_Leader(u)];
    }
    int CC(){return forests;}
};

void solve(){
    int n,m,nxt,temp;
    while(cin>>n>>m){
    nxt=n+1;
    DSU D(n+m+5);
    vector<int>id(n+5);
    for(int i=1;i<=n;++i)id[i]=i,D.sums[i]=i;// iota
    
    for(int i=1;i<=m;++i){
        int t,a,b;cin>>t;
        if(t==1){
            cin>>a>>b;
            a = id[a],b=id[b];
            D.Union(a,b);
        }
        else if(t==2){
            cin>>a>>b;
            temp = a;
            a=id[a],b=id[b];
            int leader = D.Get_Leader(a);
            
            D.Gsize[leader]--;
            D.sums[leader]-=temp;
            D.sums[nxt]=temp;
            
            id[temp]=nxt;
            D.Union(nxt,b);
            nxt++;
        }
        else{
            cin>>a;
            a = id[a];
            cout << D.Get_Size(a) << ' ' << D.Get_Sum(a) << '\n';
        }

    }
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