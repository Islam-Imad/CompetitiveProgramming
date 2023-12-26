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
pair<int,string> dp[1005][1005];
int n,m,cnt;
string x,ans;
pair<int,string>optimal(pair<int,string>a,pair<int,string>b){
    if(a.fi>b.fi){
        return a;
    }
    else if(a.fi<b.fi){
        return b;
    }
    else{
        if(a.se<b.se)return a;
        else return b;
    }
}

pair<int,string> LPS(int i,int j){
    if(i>j)return {0,""};
    pair<int,string>&ret=dp[i][j];
    if(i==j){
        ret.se=x[i];
        ret.fi=1;
    }
    if(ret.fi!=-1)return ret;
    if(x[i]==x[j]){
        return ret={2+LPS(i+1,j-1).fi,x[i]+LPS(i+1,j-1).se+x[j]};
    }
    return ret=optimal(LPS(i+1,j),LPS(i,j-1));
}

int main()
{
    Islam_Imad();
    while(cin>>x)
    {
        ll n=sz(x);
        lp(i,n,0){
            lp(j,n,0){
                dp[i][j].fi=-1;
            }
        }
        cout << LPS(0,n-1).se << "\n";

        if(x=="")cout << "\n";
    }
}
