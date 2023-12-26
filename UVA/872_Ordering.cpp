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
int vis[500];
ll n;
vi state;
bool flag=false;
void print(int idx,vi&indegree,vvi&graph,vi&node){
    if(idx>=n){
        if(sz(state)==n)
        {
        flag=true;
        cout << char(state[0]+'A');
        for(int i=1;i<n;++i){
            cout << " " <<  char(state[i]+'A');
        }
        cout << "\n";
        }
        return;
    }
    for(int i=0;i<n;++i)
    {
        int cur=node[i];
        if((!vis[cur])&&(indegree[cur]==0))
        {
            vis[cur]=1;
                for(auto adj:graph[cur])
                    --indegree[adj];
                        state.pb(cur);
                            print(idx+1,indegree,graph,node);
                        state.P;
                for(auto adj:graph[cur])
                    ++indegree[adj];
            vis[cur]=0;
        }
    }
}
int main()
{
    Islam_Imad();
    int t;cin>>t;
    while(t--){
    flag=false;
    cin.ignore();
    vvi graph(50);
    vi indegree(50);
    vi nodes;
    string x;getline(cin,x);
    if(x=="")getline(cin,x);
    for(int i=0;i<sz(x);i+=2){
        nodes.pb(x[i]-'A');
    }
    sort(all(nodes));
    n=sz(nodes);
    string y;getline(cin,y);
    for(int i=0;i<sz(y);i+=4){
        int from=y[i]-'A';
        int to=y[i+2]-'A';
        indegree[to]++;
        graph[from].pb(to);
    }
    print(0,indegree,graph,nodes);
    if(!flag)cout << "NO" << "\n";
    if(t)
    cout << "\n";
    }
}
