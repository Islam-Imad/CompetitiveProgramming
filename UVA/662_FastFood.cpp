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

ll dp[205][205][35];
int n,k,cnt;
vi v,pre;
ll calc(int i,int j,int mid){
    if(i==j)return 0;
    if(j-i==1){
        return abs(v[i]-v[j]);
    }
    ll pre1,pre2,n1,n2;
    pre1=pre[mid-1];if(i>0)pre1-=pre[i-1];
    pre2=pre[j]-pre[mid];
    n1=mid-i;
    n2=j-mid;
    return ((n1*v[mid]-pre1)+(pre2-n2*v[mid]));
}
ll Min_Cost(int i,int j,int rem){
    ++cnt;
    if(j>=n||rem==0)return 0;
    ll &ret=dp[i][j][rem];
    if(ret!=-1)return ret;
    ll leave=OO,re=n-j;
    if(re>rem){
        leave=Min_Cost(i,j+1,rem);
    }
    ll pick=OO;
    ll sub=min(calc(i,j,(i+j)/2),calc(i,j,(i+j+1)/2));
    if(rem==1&&re==1){
        pick = sub + Min_Cost(j+1,j+1,rem-1);
    }
    else if(rem!=1){
        pick = sub + Min_Cost(j+1,j+1,rem-1);
    }

    return ret=min(leave,pick);
}
void print(int i,int j,int rem){
    if(j>=n||rem==0)return;
    ll &ret=dp[i][j][rem];
    ll id=(i+j)/2;
    ll leave=OO,re=n-j;
    if(re>rem){
        leave=Min_Cost(i,j+1,rem);
    }
    ll pick=OO;
    ll sub=calc(i,j,(i+j)/2);
    if(calc(i,j,(i+j+1)/2)<sub){
        id=(i+j+1)/2;
    }
    if(rem==1&&re==1){
        pick = sub + Min_Cost(j+1,j+1,rem-1);
    }
    else if(rem!=1){
        pick = sub + Min_Cost(j+1,j+1,rem-1);
    }
    if(pick==ret){
        if(j>i)
        cout << "Depot " << k-rem+1 << " at restaurant " << id+1 << " serves restaurants " << i+1 << " to " << j+1 << "\n";
        else
        cout << "Depot " << k-rem+1 << " at restaurant " << id+1 << " serves restaurant " << i+1 << "\n";
        print(j+1,j+1,rem-1);
    }
    else{
        print(i,j+1,rem);
    }
}

int main()
{
    Islam_Imad();
    int t=1;
    while(cin>>n>>k&&n&&k){
    mem(dp,-1);

    v.resize(n);
    pre.resize(n);

    cin>>v;
    pre[0]=v[0];
    lp(i,n,1){
        pre[i]=v[i];
        pre[i]+=pre[i-1];
    }
    cout << "Chain " << t++ << "\n";
    ll ans=Min_Cost(0,0,k);
    print(0,0,k);
    cout << "Total distance sum = " << ans << "\n";
    cout << "\n";
    }
}
