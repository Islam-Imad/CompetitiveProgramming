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

const int Max=200+5;
ll cnt[Max][Max];

ll n,m;

void counting(){
    lp(k,n,0){
        lp(i,n,0){
            lp(j,n,0){
                    cnt[i][j]+=(cnt[i][k]*cnt[k][j]);
            }
        }
    }
    lp(k,n,0){
        if(cnt[k][k])
        lp(i,n,0){
            lp(j,n,0){
                if(cnt[i][k]&&cnt[k][j])
                    cnt[i][j]=-1;
            }
        }
    }
}
int main()
{
    Islam_Imad();
    int t=0;
    int p;
    while(cin>>p&&p!=EOF)
    {
    n=0;
    mem(cnt,0);
    lp(i,p,0){
        ll from,to;
        cin>>from>>to;
        n=max(n,max(from,to));
        cnt[from][to]++;
    }
    n++;
    counting();
    cout << "matrix for city " << t << "\n";
    lp(i,n,0){
        lp(j,n,0){
            cout << cnt[i][j] << (j!=n-1?" " :"");
        }
        cout << "\n";
    }
    t++;
    }
}
/*
    1-> if the graph is dag we can find the longest path.
*/