#include <bits/stdc++.h>
using namespace std;

#define ll long long int
const int N=10010;
int dp[N][105],a[N],n,k;
int any_way(int idx,int mod){
    if(idx>=n)return (mod==0);
    int &ret=dp[idx][mod];
    if(ret!=-1)return ret;
    ret=0;
    int c1=any_way(idx+1,(mod-a[idx]+1000000*k)%k),c2=any_way(idx+1,(mod+a[idx]+1000000*k)%k);
    ret|=c1;
    ret|=c2;
    return ret;
}
void Solve(){
    memset(dp,-1,sizeof(dp));
    cin>>n>>k;
    for(int i=0;i<n;++i)cin>>a[i];
    cout << (any_way(1,(a[0]+100*k)%k)?"Divisible":"Not divisible") << "\n";
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
