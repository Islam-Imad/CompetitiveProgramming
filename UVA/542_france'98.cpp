#include <bits/stdc++.h>
using namespace std;

#define ll long long int
double dp[20][6],P[20][20];
string arr[20];
int r=1;
void calc(int l1,int r1,int l2,int r2){
    for(int i=l1;i<=r1;++i){
        double sum=0.0;
        for(int j=l2;j<=r2;++j){
            sum+=(P[i][j]*dp[j][r-1]);
        }
        dp[i][r]=(sum*dp[i][r-1]);
    }
}
void Solve(){
    cout << fixed << setprecision(2);
    for(int i=1;i<=16;++i){
        dp[i][0]=1;
        cin >> arr[i];
    }
    for(int i=1;i<=16;++i){
        for(int j=1;j<=16;++j){
            cin>>P[i][j];
            P[i][j]/=100.0;
        }
    }
    for(int i=2;i<=16;i*=2){
        for(int j=1;j<=16;j+=i){
            calc(j,j+(i/2)-1,j+(i/2),j+i-1);
            calc(j+(i/2),j+i-1,j,j+(i/2)-1);
        }
        r++;
    }
    string x=string(10,' ');
    for(int i=1;i<=16;++i){
        dp[i][r-1]*=100.0;
        for(int j=0;j<arr[i].size();++j)x[j]=arr[i][j];
        cout << x << " p="<<dp[i][r-1]<<"%\n";
        x=string(10,' ');
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
    while(tc--)Solve();
}
