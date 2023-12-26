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
#define ld double
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
typedef vector<ld> vi;
typedef vector<vi> vvi;
typedef pair<ld, ld> ii;
typedef vector<vector<ii>> vvii;

void Floyed(vvi&adjmatrix){
    int n=sz(adjmatrix);
    lp(k,n,0){
        lp(i,n,0){
            lp(j,n,0){
                adjmatrix[i][j]=min(adjmatrix[i][j],max(adjmatrix[i][k],adjmatrix[k][j]));
            }
        }
    }
}

void Initialization(vvi&adjmatrix){
    int n=sz(adjmatrix);
    lp(i,n,0){
        lp(j,n,0){
            adjmatrix[i][j]=OO;
        }
        adjmatrix[i][i]=0;
    }
}

void print(vvi&adjmatrix){
    int n=sz(adjmatrix);
    lp(i,n,0){
        lp(j,n,0){
            if(adjmatrix[i][j]==OO)cout << "OO ";
            else cout << adjmatrix[i][j] << " ";
        }
        cout << "\n";
    }
}

int main()
{
    Islam_Imad();
    int n,t=0;
    while(cin>>n&&n){
    ++t;
    vvi adjmatrix(n,vi(n));
    vector<ii>v(n);
    lp(i,n,0){
        cin>>v[i].fi>>v[i].se;
    }
    lp(i,n,0){
        lp(j,n,0){
            double dist=pow((v[i].fi-v[j].fi),2)+pow(v[i].se-v[j].se,2);
            adjmatrix[i][j]=dist;
        }
    }
    Floyed(adjmatrix);
    cout << "Scenario #" << t << "\n";
    cout << "Frog Distance = " << setprecision(3) << fixed <<sqrt(adjmatrix[0][1]) << "\n";
    cout << "\n";
    }

}
