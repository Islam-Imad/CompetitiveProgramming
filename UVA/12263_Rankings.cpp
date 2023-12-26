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
typedef vector<vector<pair<int,ld>>> vvid;

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

int n,m,cnt;

int grid[505][505];
vvi graph;
vi indegree,last,cur;
void topo_sort(){
    lp(i,n,0){
        for(auto &x:graph[i]){
            indegree[x]++;
        }
    }
    queue<int>q;
    lp(i,n,0){
        if(indegree[i]==0)
            q.push(i);
    }
    while(!q.empty()){
        int f=q.front();
        cur.push_back(f+1);
        q.pop();
        for(auto &x:graph[f]){
            if((--indegree[x])==0)
                q.push(x);
        }
    }
}
int main()
{
    Islam_Imad();
    int t;cin>>t;
    while(t--){
        cin>>n;
        last.resize(n);cin>>last;
        graph.resize(n);
        indegree.resize(n);
        mem(grid,0);
        lp(i,n,0){
            --last[i];
        }
        lp(i,n,0){
            lp(j,n,i+1){
                grid[last[j]][last[i]]=1;
            }
        }
        cin>>m;
        lp(i,m,0){
            int a,b;cin>>a>>b;
            --a;--b;
            if(grid[a][b]){
                grid[a][b]=0;
                grid[b][a]=1;}
            else if(grid[b][a]){
                grid[a][b]=1;
                grid[b][a]=0;
                }
        }
        lp(i,n,0){
            lp(j,n,0){
                if(grid[i][j]){
                    graph[i].pb(j);
                }
            }
        }
        topo_sort();
        if(sz(cur)==n||m==0){
            if(sz(cur)==n)
            {rlp(i,n,0)cout << cur[i] << " ";cout << "\n";}
            else
            {lp(i,n,0)cout << last[i]+1 << " ";cout << "\n";}
        }
        else cout << "IMPOSSIBLE\n";
        cur.clear();
        graph.clear();
        last.clear();
    }
}
