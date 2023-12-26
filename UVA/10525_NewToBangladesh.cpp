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
#define ld long double
#define rall(v) v.rbegin(), v.rend()
#define all(v) v.begin(), v.end()
#define sz(v) ((int)(v.size()))
#define mem(arr,val) memset(arr,val,sizeof(arr));
#define MOD 1'000'000'007
#define PI acos(-1)
#define OO 10000000000ll
#define EPS 1e-9
#define e 2.71828182845904523536
#define pb push_back
#define fi first
#define se second
#define P pop_back()
#define lp(i, n, v) for (int i = v; i < n; ++i)
#define rlp(i, n, v) for (int i = n-1; i >= v; --i)
typedef map<ll,ll>omap;
typedef unordered_map<ll,ll>umap;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll, ll> ii;
typedef vector<vector<ii>> vvii;

void Floyd(vvii&adj){
    int n=sz(adj);
    lp(k,n,0){
        lp(i,n,0){
            lp(j,n,0){
                if(adj[i][j].se>adj[i][k].se+adj[k][j].se){
                    adj[i][j].se=adj[i][k].se+adj[k][j].se;
                    adj[i][j].fi=adj[i][k].fi+adj[k][j].fi;
                }
                if(adj[i][j].se==adj[i][k].se+adj[k][j].se){
                    adj[i][j].fi=min(adj[i][j].fi,adj[i][k].fi+adj[k][j].fi);
                }
            }
        }
    }
}
int main()
{
    Islam_Imad();
    int t;cin>>t;
    while(t--){
        int n,m;cin>>n>>m;
        vvii adj(n,vector<ii>(n));
        lp(i,n,0){
            lp(j,n,0){
                adj[i][j].first=OO;
                adj[i][j].second=OO;
            }
            adj[i][i].fi=0;
            adj[i][i].se=0;
        }
        lp(i,m,0){
            ll a,b,Time,len;cin>>a>>b>>Time>>len;
            --a,--b;
            if(Time<adj[a][b].se){
            adj[a][b].fi=len;
            adj[a][b].se=Time;
            adj[b][a].fi=len;
            adj[b][a].se=Time;
            }
            else if(Time==adj[a][b].se){
            adj[a][b].fi=min(adj[a][b].fi,len);
            adj[b][a].fi=min(adj[b][a].fi,len);
            }
        }
        
        Floyd(adj);
        
        int q;cin>>q;
        lp(i,q,0){
            ll a,b;cin>>a>>b;
            --a,--b;
            if(adj[a][b].se>=OO)cout << "No Path.\n";
            else {
            cout << "Distance and time to reach destination is " << adj[a][b].fi << " & " << adj[a][b].se << "." << "\n";
            }
        }
        if(t)cout << "\n";
    }
}
