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

ll dp[1005][1005];
ll n,m,cnt;
string x,l,r;

ll Min_Insert(int i,int j){
    if(i>j)return 0;
    ll &ret=dp[i][j];
    if(ret!=-1)return ret;
    ret=0;
    if(x[i]==x[j]){
        return ret=Min_Insert(i+1,j-1);
    }
    ll c1= 1+Min_Insert(i+1,j);
    ll c2= 1+Min_Insert(i,j-1);
    return ret=min(c1,c2);
}
void print(int i,int j){
    if(i>j)return;
    ll &ret=dp[i][j];
    if(x[i]==x[j]){
        l+=x[i];
        if(i!=j)
        r=x[j]+r;
        print(i+1,j-1);
        return;
    }
    ll c1= 1 + Min_Insert(i+1,j);
    ll c2= 1 + Min_Insert(i,j-1);
    if(c1<c2){
        r=x[i]+r;
        l+=x[i];
        print(i+1,j);
    }
    else{
        l+=x[j];
        r=x[j]+r;
        print(i,j-1);
    }
}
int main()
{
    Islam_Imad();
    while(cin>>x){
        mem(dp,-1);
        l="",r="";

        cout << Min_Insert(0,sz(x)-1) << " ";
        print(0,sz(x)-1);
        cout << l << "" <<  r  << "\n";
    }
}
