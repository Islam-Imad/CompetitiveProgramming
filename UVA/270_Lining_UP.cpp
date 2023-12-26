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

int main()
{
    Islam_Imad();
    string hand;
    int Test_Cases=1;
    cin>>Test_Cases;
    cin.ignore();
    getline(cin,hand);
    for(int iteration=1;iteration<=Test_Cases;++iteration){
        string x,y;
        int n=0,ans=-1000;
        vector<ii>v;
        while(getline(cin,x)&&x!=""){
            // cout << x << "\n";
            int i=0,si=sz(x);
            lp(j,si,0){
                i=j;
                if(x[j]==' ')break;
            }
            y=x.substr(i+1);
            x=x.substr(0,i);
            int l=stoi(x),r=stoi(y);
            n++;
            v.pb({l,r});
        }
        // debug(n);
        for(int i=0;i<n;++i){
            int sub=0,cnt1=0,cnt2=0;
            map<pair<int,int>,int>mp;
            for(int j=0;j<n;++j){
                if(i!=j){
                    ll y=v[i].se-v[j].se;
                    ll x=v[i].fi-v[j].fi;
                    bool flag=false;
                    if(x<0||y<0)flag=true;
                    if(x<0&&y<0)flag=false;
                    if(x==0)
                    {
                        cnt1++;
                        sub=max(sub,cnt1);
                    }
                    else if(y==0)
                    {
                        cnt2++;
                        sub=max(sub,cnt2);
                    }
                    else
                    {
                        ll g=__gcd(abs(x),abs(y));
                        if(flag)y=(-1*abs(y)),x=abs(x);
                        else y=abs(y),x=abs(x);
                        x/=g,y/=g;
                        mp[{y,x}]++;
                        sub=max(sub,mp[{y,x}]);
                    }
                }
            }
            ans=max(ans,sub+1);
        }
        cout << ans << "\n";
        if(iteration!=Test_Cases)cout << "\n";
    }
}
