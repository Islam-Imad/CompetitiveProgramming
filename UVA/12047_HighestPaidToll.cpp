#include <bits/stdc++.h>
using namespace std;

#define ll long long int

struct edge{
    int to,w;
    edge(int to,int w):to(to),w(w){}
    bool operator<(const edge&a)const{
        return w > a.w;
    }
};

vector<int> Dijkstra(int source,vector<vector<pair<int,int>>>&adj,int &n){
    vector<int>vis(n+5),dist(n+5,1000000000);
    dist[source]=0;
    priority_queue<edge>q;
    q.push({source,0});
    while(!q.empty()){
        edge ed=q.top();
        q.pop();
        if(vis[ed.to])continue;
        for(pair<int,int>p:adj[ed.to]){
            if(dist[p.first]>p.second+ed.w){
                dist[p.first]=p.second+ed.w;
                q.push({p.first,dist[p.first]});
            }
        }
        vis[ed.to]=1;
    }
    return dist;
}
void Solve(){
    int n,m,s,t,p,ans=-1;
    cin>>n>>m>>s>>t>>p;

    vector<pair<int,pair<int,int>>>ret(m);
    vector<int> v1,v2;
    vector<vector<pair<int,int>>>adj1(n+5),adj2(n+5);

    for(int i=0;i<m;++i){
        int a,b,c;cin>>a>>b>>c;
        ret[i].first=c,ret[i].second={a,b};
        adj1[a].push_back({b,c});
        adj2[b].push_back({a,c});
    }

    sort(ret.rbegin(),ret.rend());
    v1 = Dijkstra(s,adj1,n),v2=Dijkstra(t,adj2,n);

    for(int i=0;i<m;++i){
        int a,b,c;
        c = ret[i].first,a=ret[i].second.first,b=ret[i].second.second;
        if(v1[a]+c+v2[b]<=p){
            ans=c;
            break;
        }
    }
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
    #endif
    int tc=1;
    cin>>tc;
    while(tc--)Solve();
}
