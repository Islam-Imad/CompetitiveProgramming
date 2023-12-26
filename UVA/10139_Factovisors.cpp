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
#define pb push_back
#define fi first
#define se second
#define pop pop_back()
#define lp(i, n, v) for (int i = v; i < n; i++)
#define rlp(i, n, v) for (int i = n-1; i >= v; i--)
typedef map<int,int>mmap;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef pair<int, int> ii;
typedef vector<vector<ii>> vvii;

/*
-->Dicliplinses
.Read Carefully
.Boundaries(overflow,time limit,big and small values)
.Tricky test cases
.Extract constraints focus on special ones and avoid assumption
.play words
.Trace
.i/o format
*/
mmap factor(ll m){
    mmap ans;
    for(ll d=2;d*d<=m;d++){
        while(m%d==0){
            m/=d;
            ans[d]++;
        }
    }
    if(m>1)ans[m]++;
    return ans;
}
int main()
{
    Islam_Imad();
    ll n,m;
    while(cin>>n>>m)
    {
        mmap f,div=factor(m);
            for(auto &x:div)
            {
                int count=0;
                ll num=x.fi;
                while(n/num)
                {
                    count+=(n/num);
                    num*=x.first;
                }
                f[x.fi]=count;
            }
        bool ans=true;
            for(auto x:div)
            {
                if(x.se>f[x.fi]){ans=false;break;}
            }
        if(ans)
            cout << m << " divides " << n << "!";
        else
            cout << m << " does not divide " << n << "!";
        cout << "\n";
    }
}
