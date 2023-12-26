#include <bits/stdc++.h>
using namespace std;

#define ll long long int
const int N = 1<<16 + 9;
int dp[N],n,m,test=1;
pair<int,int> arr[N];

bool is_valid(int i,int j,int k){
    return (((arr[k].second-arr[j].second)*(arr[j].first-arr[i].first)) == ((arr[k].first-arr[j].first)*(arr[j].second-arr[i].second)));
}

int Minimum(int num){
    int &ret=dp[num];
    if(ret!=-1)return ret;
    bitset<16> s = num;
    if(s.count()>=m)return ret=0;
    ret = n - (int)s.count();
    for(int i=0;i<n;++i){
        for(int j=i+1;j<n;++j){
            if(s[i]==1||s[j]==1)continue;
            bitset<16> Mask = num;
            for(int k=0;k<n;++k){
                if(s[k]==0 and is_valid(i,j,k)){
                    Mask[k]=1;
                }
            }
            ret = min(ret,1+Minimum(Mask.to_ulong()));
        }
    }
    return ret;
}
void Solve(){
    memset(dp,-1,sizeof(dp));
    cin>>n>>m;
    for(int i=0;i<n;++i)cin>>arr[i].first>>arr[i].second;
    cout << "Case #" << test++ <<":\n";
    cout << Minimum(0) << "\n";
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
        Solve();
        if(tc)cout << '\n';
    }
}
/*
#include <bits/stdc++.h>
using namespace std;

#define ll long long int
const int N = 1<<16 + 9;
int dp[N],pre[17][17],n,m,test=1;
pair<int,int> arr[N];

bool is_valid(int i,int j,int k){
    return (((arr[k].second-arr[j].second)*(arr[j].first-arr[i].first)) == ((arr[k].first-arr[j].first)*(arr[j].second-arr[i].second)));
}
void preprocess(){
    for(int i=0;i<n;++i){
        for(int j=i+1;j<n;++j){
            bitset<16>s;

            for(int k=0;k<n;++k){
                s[k]=is_valid(i,j,k);
            }
            pre[i][j] = s.to_ulong();
        }
    }
}
int Minimum(int num){
    int &ret=dp[num];
    if(ret!=-1)return ret;
    bitset<16> s = num;
    if(s.count()>=m)return ret=0;
    ret = n - (int)s.count();
    for(int i=0;i<n;++i){
        for(int j=i+1;j<n;++j){
            if(s[i]==1||s[j]==1)continue;
            bitset<16> Mask = pre[i][j];
            Mask|=((int)(s.to_ulong()));
            ret = min(ret,1+Minimum(Mask.to_ulong()));
        }
    }
    return ret;
}
void Solve(){
    memset(dp,-1,sizeof(dp));
    cin>>n>>m;
    for(int i=0;i<n;++i)cin>>arr[i].first>>arr[i].second;
    preprocess();
    cout << "Case #" << test++ <<":\n";
    cout << Minimum(0) << "\n";
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
        Solve();
        if(tc)cout << '\n';
    }
}

*/