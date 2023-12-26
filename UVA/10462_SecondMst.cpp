#include <bits/stdc++.h>
using namespace std;

void Islam_Imad()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#endif
}

template <class t>
ostream &operator<<(ostream &out, vector<t> &a)
{
    for (auto &i : a)
        out << i << " ";
    out << "\n";
    return out;
}
template <class t>
istream &operator>>(istream &in, vector<t> &a)
{
    for (auto &i : a)
        in >> i;
    return in;
}

#define debug(x) cout << #x << ": " << (x) << "\n"
#define no cout << "NO"
#define yes cout << "YES"
#define ll long long int
#define ull unsigned long long int
#define ld long double
#define rall(v) v.rbegin(), v.rend()
#define all(v) v.begin(), v.end()
#define sz(v) ((int)(v.size()))
#define mem(arr,val) memset(arr,val,sizeof(arr));
#define MOD 1'000'000'007
#define PI acos(-1)
#define OO 1e9
#define EPS 1e-9
#define e 2.71828182845904523536
#define pb push_back
#define fi first
#define se second
#define P pop_back()
#define lp(i, n, v) for (int i = v; i < n; ++i)
#define rlp(i, n, v) for (int i = n-1; i >= v; --i)
typedef map<int,int>omap;
typedef unordered_map<int,int>umap;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef pair<int, int> ii;
typedef vector<vector<ii>> vvii;

struct edge{
    int from,to;long long w;
    edge(int from,int to, long long w):from(from),to(to),w(w){}
    bool operator<(const edge&com)const{
        return w<com.w;
    }
};

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

int main()
{
    Islam_Imad();
    int t;cin>>t;
    lp(it,t+1,1){
        int n,m;cin>>n>>m;
        DSU<int> MD(n);
        vector<edge>v;
        lp(i,m,0){
            ll a,b,w;
            cin>>a>>b>>w;
            --a,--b;
            v.pb(edge(a,b,w));
        }
        sort(all(v));
        // lp(i,m,0){
        //     cout << v[i].from << " " << v[i].to << " " << v[i].w << "\n";
        // }
        vi id;
        ll Mst=0,SM=OO;
        lp(i,m,0){
            if(!MD.SameSet(v[i].from,v[i].to)){
                id.pb(i);
                MD.Union(v[i].from,v[i].to);
                Mst+=v[i].w;
            }
        }
        cout << "Case #" << it << " : ";
        if(MD.CC()>=2)Mst=OO;
        if(Mst>=OO)cout << "No way";
        else{
            for(int j=0;j<sz(id);++j){
                DSU<int> D(n);
                ll sub=0;
                for(int i=0;i<m;++i){
                    if(i!=id[j]){
                        if(!D.SameSet(v[i].from,v[i].to)){
                        D.Union(v[i].from,v[i].to);
                        sub+=v[i].w;
                        }
                    }
                }
                // cout << D.CC() << " " << sub << "\n";
                if(D.CC()==1&&sub>=Mst)SM=min(SM,sub);
            }
            if(SM>=OO)cout << "No second way";
            else cout << SM ;
        }
        cout << "\n";
    }
}
