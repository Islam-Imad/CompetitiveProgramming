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
#define OO 1e9
#define EPS 1e-9
#define pb push_back
#define P pop_back()
#define fi first
#define se second
#define lp(i, n, v) for (int i = v; i < n; ++i)
#define rlp(i, n, v) for (int i = n-1; i >= v; --i)
typedef map<ll,ll>omap;
typedef unordered_map<ll,ll>umap;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll, ll> ii;
typedef vector<vector<ii>> vvii;

vi Get_Sieve(ll n){
    vi sieve(n+1),pre(n+1);
    sieve[0]=sieve[1]=0;
    for(int d=2;d<=n;++d){
        if(sieve[d]==0){
            for(int u=d*2;u<=n;u+=d){
                sieve[u]=d;
                int co=u,cnt=0;
                while(co%d==0){
                    ++cnt;
                    co/=d;
                }
                pre[u]+=cnt;
            }
            pre[d]+=1;
        }
    }
    for(int i=2;i<=1000000;++i)pre[i]+=pre[i-1];
    return pre;
}
int main()
{
    Islam_Imad();
    vi sieve=Get_Sieve(1000000);
    int Test_Cases=1;
    // cin>>Test_Cases;
    for(int iteration=1;iteration<=Test_Cases;++iteration){
        ll n,ans=0;
        while(cin>>n){
        cout << sieve[n] << "\n";
        }
    }
}
