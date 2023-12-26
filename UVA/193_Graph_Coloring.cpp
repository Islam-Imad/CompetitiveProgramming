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

vi col,vis,op,last;
int ans,cn;

void add_undirected_edge(vvi&graph,int from,int to){
    graph[from].pb(to);
    graph[to].pb(from);
}
bool can_black(vvi&graph,int node){
    for(auto &x:graph[node]){
        if(col[x]==1)return false;
    }
    return true;
}
void Max_Black(vvi &graph,int u,int cnt){
    ++cn;
    if(u==sz(graph))
    {
        if(cnt>ans)// Optimization Step
        {
            ans=cnt;
            last=op;
        }
        return;
    }
    // Try White
    col[u]=0; // do
        Max_Black(graph,u+1,cnt);// rec
    col[u]=-1; // undo
    // Try Black With Condition
    if(can_black(graph,u))
    {
        col[u]=1;// do 
            op.pb(u+1);// do 
                Max_Black(graph,u+1,cnt+1);// rec
            op.P;// undo
        col[u]=-1;// undo
    }
}
int main()
{
    Islam_Imad();
    int t;cin>>t;
    while(t--){

    int n,m;cin>>n>>m;
    vvi graph(n);
    vis.resize(n);
    col.resize(n,-1);

    lp(i,m,0){
        int from,to;cin>>from>>to;
        --from,--to;
        add_undirected_edge(graph,from,to);
    }
    Max_Black(graph,0,0);
    cout << ans << "\n";

    sort(all(last));
    cout << last[0];
    lp(i,sz(last),1)cout << " " << last[i];
    cout << '\n';

    // Debugging --> NOTE: You can get rid of sum of them
    vis.clear();
    col.clear();
    last.clear();
    ans=0;
    }
}
/*
Pruning;
1-> if you are in a curent node and the cur_optimal answer in x and the max_pos ans for you is n_black and n-node less than the optimal return;
2-> Backtrack on black first and then white Pruning condition will occur many times;
3-> you can reduce the depth of your function by simply try pos black with the help of iteration(loop)
4-> another trick is random order
5-> you can order the node base on indegree

6-> Later you can use bits and dp here
*/