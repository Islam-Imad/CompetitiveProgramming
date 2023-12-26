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

int nums[200];
void Prime(ll n){
    for(ll i=1;i<=n;++i){
        ll cur=i;
        for(ll d=2;d*d<=i;++d){
            while(cur%d==0){
                nums[d]++;
                cur/=d;
            }
        }
        if(cur>1){
            nums[cur]++;
        }
    }
}
umap factors(ll n){
    umap f;
    for(ll d=2;d*d<=n;++d){
        while(n%d==0){
            f[d]++;
            n/=d;
        }
    }
    if(n>1)f[n]++;
    return f;
}

int main()
{
    Islam_Imad();
    ll n,d;
    while(cin>>n>>d){
        if(n==0&&d==0)break;
        n=abs(n),d=abs(d);
        mem(nums,0);
        umap f=factors(d);
        Prime(n);
        ll ans=1;
        for(auto &div:f){
            if(div.fi<=n&&nums[div.fi]>=div.se){
                nums[div.fi]-=div.se;
                div.se=0;
            }
            if(div.se!=0)ans=-1;
        }
        if(ans!=-1){
            lp(i,n+1,1){
                ans*=(nums[i]+1);
            }
        }
        else ans=0;
        cout << ans << "\n";
    }
}