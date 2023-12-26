#include <bits/stdc++.h>
using namespace std;

#define ll long long int
const int N=1010;
int dp[N][N],n,cur=1;
string x;
int LCS(int l,int r){
    if(r<=l)return 0;
    int &ret=dp[l][r];
    if(ret!=-1)return ret;
    if(x[l]==x[r]){
        return ret=LCS(l+1,r-1);
    }
    return ret=1+min(LCS(l+1,r-1),min(LCS(l,r-1),LCS(l+1,r)));
}
void Solve(){
    memset(dp,-1,sizeof(dp));
    cin>>x;
    n=(int)x.size();
    cout << "Case " << cur << ": ";
    cout << LCS(0,n-1) << "\n";
    cur++;
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
