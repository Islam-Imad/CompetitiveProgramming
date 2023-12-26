#include <bits/stdc++.h>
using namespace std;

#define ll long long int


void solve(){
    int n,m;
    while(cin>>n>>m){
    vector<bool>dp(n+5);
    vector<int>v(m);
    for(int i=0;i<m;++i)cin>>v[i];
    
    for(int i=1;i<=n;++i){
        for(int j=0;j<m;++j){
            if(i-v[j]>=0){
                if((dp[i-v[j]]==0)){
                    dp[i]=1;
                    break;
                }
            }
        }
    }    
    cout << (dp[n]?"Stan wins":"Ollie wins") << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
    #endif
    int tc=1;
    // cin>>tc;
    while(tc--){
        solve();
    }
}