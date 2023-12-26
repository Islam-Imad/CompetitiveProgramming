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
#define OO 1e12
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
ll dp[15][105];
ll grid[15][105];
ll n,m;
ll Mini(int i,int j){
    if(j>=m)return 0;
    ll&ret=dp[i][j];
    if(ret!=-1)return ret;
    ll c1=OO,c2=OO,c3=OO;
    int id=i-1,jd=i+1;
    if(id==-1)id=n-1;
    if(jd==n)jd=0;
    c1=grid[i][j]+Mini(id,j+1);
    c2=grid[i][j]+Mini(i,j+1);
    c3=grid[i][j]+Mini(jd,j+1);
    return ret=min(c1,min(c2,c3));
}
void print(int i,int j){
    if(j==m)return;
    ll c1=OO,c2=OO,c3=OO;int r=1000;
    int id=i-1,jd=i+1;
    if(id==-1)id=n-1;
    if(jd==n)jd=0;
    c1=grid[i][j]+Mini(id,j+1);
    c2=grid[i][j]+Mini(i,j+1);
    c3=grid[i][j]+Mini(jd,j+1);
    ll optimal=Mini(i,j);
    if(c1==optimal)r=min(r,id);
    if(c2==optimal)r=min(r,i);
    if(c3==optimal)r=min(r,jd);

    cout << i+1 << (j==m-1?"":" ");
    if(r==id)print(id,j+1);
    else if(r==i)print(i,j+1);
    else if(r==jd)print(jd,j+1);
}
int main()
{
 
    Islam_Imad();
    while(cin>>n>>m){
    mem(dp,-1);
    lp(i,n,0){
        lp(j,m,0){
            cin>>grid[i][j];
        }
    }
    ll ans=OO;
    int r=1000;
    for(int i=0;i<n;++i){
        ll sub=Mini(i,0);
        if(sub<ans){
            ans=sub;
            r=i;
        }
    }
    print(r,0);
    cout << "\n" << ans <<"\n";
    }

}
