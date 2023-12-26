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
#define allr(v) v.rbegin(), v.rend()
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

int MAX=1000+1;
char grid[1001][1001];
int cost[1001][1001];
int n,m,cnt;
int dr[]={-1,-1,0,1,1,1,0,-1};
int dc[]={0,1,1,1,0,-1,-1,-1};
bool valid(int i,int j){return i>=0&&j>=0&&i<n&&j<m;}
void z_one(int ir,int ic,int der,int dec){
    lp(i,n,0){
        lp(j,m,0){
            cost[i][j]=1e9;
        }
    }
    deque<ii>q;
    q.push_front(make_pair(ir,ic));
    cost[ir][ic]=0;
    while(!q.empty()){
        ii p=q.front();
        int r=p.fi,c=p.se;
        q.pop_front();
        if(r==der&&c==dec){
            cout << cost[r][c] << "\n";
            return;
        }
        lp(i,8,0){
            int nr=r+dr[i];
            int nc=c+dc[i];
            if(!valid(nr,nc))continue;
            int not_same=0;
            if(i!=(grid[r][c]-'0'))
                not_same=1;
            int cur_cost=cost[r][c]+not_same;
            if(cur_cost<cost[nr][nc]){
                cost[nr][nc]=cur_cost;
                if(not_same)
                    q.push_back({nr,nc});
                else
                    q.push_front({nr,nc});
            }
        }
    }
}
int main()
{
    Islam_Imad();
    cin>>n>>m;
    lp(i,n,0){
        lp(j,m,0){
            cin>>grid[i][j];
        }
    }
    int t;cin>>t;
    while(t--){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        --a,--b,--c,--d;
        z_one(a,b,c,d);
    }
}
