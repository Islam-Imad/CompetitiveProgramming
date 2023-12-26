#include <bits/stdc++.h>
using namespace std;

#define ll long long int


const int N = 45;
int dr[]={1,-1,0,0};
int dc[]={0,0,1,-1};
int n,m,D[N][N][N][N],dp[N*N][(1<<15)+9],cnt=0,cnt2=0;
char grid[N][N];

vector<pair<int,int>>boxes,xs;

void bfs(int i,int j){
    queue<pair<int,int>>q;
    q.push({i,j});
    vector<vector<int>> dist(n+2,vector<int>(m+2));
    vector<vector<bool>> vis(n+2,vector<bool>(m+2));
    vis[i][j]=1;
    while(!q.empty()){
        pair<int,int> s = q.front();
        q.pop();
        for(int k=0;k<4;++k){
            int x = s.first+dr[k],y = s.second+dc[k];
            if(x<0||y<0||x>=n||y>=m||vis[x][y]||grid[x][y]=='#')continue;
            q.push({x,y});
            vis[x][y]=1;
            dist[x][y]=dist[s.first][s.second]+1;
            D[i][j][x][y]=dist[x][y];
        }
    }
}

int calc(int idx,int mask){
    if(mask+1==(1<<cnt))return 0;
    if(idx>=cnt2)return 1e9;
    int &ret = dp[idx][mask];
    if(ret!=-1)return ret;
    ret = calc(idx+1,mask);
    
    for(int i=0;i<cnt;++i){
        if(!(mask&(1<<i))){
            pair<int,int> p1 = boxes[i],p2 = xs[idx];
            int cost = D[p1.first][p1.second][p2.first][p2.second];
            if(!cost)continue;
            cost+= calc(idx+1,mask|(1<<i));
            // cout << D[p1.first][p1.second][p2.first][p2.second] <<'\n';
            // cout << p1.first << ' ' << p1.second<< ' ' <<p2.first<< ' ' <<p2.second <<'\n';
            ret = min(ret,cost);
        }
    }
    return ret;
}

void pre(){
    memset(D,0,sizeof(D));
    memset(dp,-1,sizeof(dp));
    boxes=xs=vector<pair<int,int>>(0);
    cnt = cnt2 = 0;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(grid[i][j]=='B'){
                bfs(i,j);
                boxes.push_back({i,j});
                cnt++;
            }
            else if(grid[i][j]=='X'){
                xs.push_back({i,j});
                cnt2++;
            }
        }
    }
    cout << calc(0,0) << '\n';
}

void solve(){
    cin>>n>>m;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            cin>>grid[i][j];
        }
    }
    pre();
}

int main()
{
    ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
    #endif
    int tc=1;
    cin>>tc;
    while(tc--){
        solve();
    }
}