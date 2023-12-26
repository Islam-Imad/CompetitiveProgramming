#include <bits/stdc++.h>
using namespace std;

#define ll long long int
const int N = 101;
int dp[N],grid[N][N],n,ans=-127;
int Maxi(){
    int ret = dp[0];
    for(int i=1;i<n;++i){
        dp[i]=max(dp[i],dp[i]+dp[i-1]);
        ret=max(dp[i],ret);
    }
    return ret;
}

void Solve(){
    cin>>n;
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            cin>>grid[i][j];
            ans=max(ans,grid[i][j]);
        }
    }
    for(int i=1;i<n;++i){
        for(int j=0;j<n;++j){
            grid[i][j]+=grid[i-1][j];
        }
    }
    for(int i=0;i<n;++i){
        for(int j=i;j<n;++j){
            for(int k=0;k<n;++k){
                dp[k]=grid[j][k]-(i>0?grid[i-1][k]:0);
            }
            ans=max(ans,Maxi());
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
    // cin>>tc;
    while(tc--)Solve();
}
