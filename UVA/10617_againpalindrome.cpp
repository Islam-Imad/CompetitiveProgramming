#include <bits/stdc++.h>
using namespace std;

#define ll long long int
const int N=60+5;
ll dp[N][N],n,ans=0;

string x;
ll Palindrome(int l,int r){
    if(r<l)return 0;
    ll &ret=dp[l][r];
    if(ret!=-1)return ret;
    ret=0;
    if(x[l]==x[r]){
        ret=r-l;
        for(int i=l;i<=r;++i){
            for(int j=i+1;j<=r;++j){
                if(i!=l&&j!=r)
                ret+=Palindrome(i,j);
            }
        }
    }
    return ret;
}
void Solve(){
    memset(dp,-1,sizeof(dp));
    ans=0;
    cin>>x;
    n=x.size();
    for(int i=0;i<n;++i){
        for(int j=i+1;j<n;++j){
            ans+=Palindrome(i,j);
        }
    }
    cout << ans+n << "\n";
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
/*
#include <bits/stdc++.h>
using namespace std;

#define ll long long int
const int N=60+5;
ll dp[N][N],n,ans=0;
string x;
ll DP(int l,int r){
    if(r<l)return 0;
    ll &ret=dp[l][r];
    if(ret!=-1)return ret;
    ret=DP(l+1,r)+DP(l,r-1)-DP(l+1,r-1);
    if(x[l]==x[r]){
        ret+=1+DP(l+1,r-1);
    }
    return ret;
}
void Solve(){
    memset(dp,-1,sizeof(dp));
    cin>>x;
    n=x.size();
    cout << DP(0,n-1) << "\n";
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

*/