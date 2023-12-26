#include <bits/stdc++.h>
using namespace std;

#define ll long long int

double dp[55][55],p;
int n;

double calc(int r,int w){
    if(w==n)return 1.0;
    if(2*n-r+w<n)return 0.0;
    double &ret=dp[r][w];
    if(ret!=-1)return ret;
    ret=0;
    ret=(p*(calc(r+1,w+1)))+((1.0-p)*calc(r+1,w));

    return ret;
}
void Solve(){
    cout << fixed << setprecision(2);
    cin>>n>>p;
    for(int i=0;i<=2*n;++i){
        for(int j=0;j<=2*n;++j){
            dp[i][j]=-1.0;
        }
    }
    cout << calc(1,0) << "\n";
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
