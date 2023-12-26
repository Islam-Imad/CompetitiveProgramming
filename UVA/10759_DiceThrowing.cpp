#include <bits/stdc++.h>
using namespace std;

#define ll long long int

ll dp[26][149],nums[26],ans,g;
int n,x;

ll calc(int it,int sum){
    if(it>n){
        return (sum>=x);
    }
    ll &ret=dp[it][sum];
    if(ret!=-1)return ret;
    ret=0;
    for(int i=1;i<=6;++i){
        ret+=calc(it+1,sum+i);
    }
    return ret;
}

void Solve(){
    while(cin>>n>>x){
        if(n==0&&x==0)break;
        memset(dp,-1,sizeof(dp));
        ans = calc(1 , 0);
        if(ans==0)cout << "0\n";
        else if(ans==nums[n])cout << "1\n";
        else{
            g=__gcd(ans,nums[n]);
            cout << ans/g << '/' << nums[n]/g << "\n";
        }
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
    nums[1]=6;
    for(int i=2;i<=25;++i)nums[i]=(nums[i-1]*6ll);
    while(tc--)Solve();
}
