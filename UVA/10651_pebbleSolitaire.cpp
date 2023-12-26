#include <bits/stdc++.h>
using namespace std;

#define ll long long int
const int N = 1<<12 + 9;
int dp[N];
int Minimum(int num){
    bitset<12>s = num;
    int &ret=dp[num];
    if(ret!=-1)return ret;
    ret=s.count();
    for(int i=0;i<12-2;++i){
        s=num;
        if(s[i]&&s[i+1]&&s[i+2]==0){
            s[i]=s[i+1]=0,s[i+2]=1;
            ret = min(ret,Minimum(s.to_ulong()));
        }
        s=num;
        if(s[i]==0&&s[i+1]&&s[i+2]){
            s[i+1]=s[i+2]=0,s[i]=1;
            ret=min(ret,Minimum(s.to_ulong()));
        }
    }
    return ret;
}
void Solve(){
    memset(dp,-1,sizeof(dp));
    string x;cin>>x;
    for(int i=0;i<x.size();++i){
        if(x[i]=='-')x[i]='0';
        else x[i]='1';
    }
    bitset<12> s {x};
    cout << Minimum(s.to_ulong()) << "\n";
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
