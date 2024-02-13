#include <bits/stdc++.h>
using namespace std;

#define ll long long int

const int N = 1000+9;
pair<int,ll> dp[N][505];
int n,l,c,arr[N];

ll calc_rem(ll t){
    if(!t)return 0;
    if(t<=10)
        return -c;
    return (t-10)*(t-10);
}

pair<int,ll> calc(int idx,int rem_time){
    if(idx>=n){
        rem_time%=l;
        return {0,calc_rem(rem_time)};
    }
    pair<int,ll>&ret = dp[idx][rem_time];
    if(ret.first!=-1)return ret;
    // choice one
    ret = {1,calc_rem(rem_time)};
    pair<int,ll> c1 = calc(idx+1,l-arr[idx]),c2;
    ret.first+=c1.first,ret.second+=c1.second;

    // choice two
    if(rem_time>=arr[idx]){
        c2 = calc(idx+1,rem_time-arr[idx]);
        ret = min(ret,c2);
    }
    
    return ret;
}
void solve(){
    int it = 1;
    while(cin>>n&&n){
        if(it!=1)cout << '\n';
        cin>>l>>c;
        for(int i=0;i<n;++i){
            for(int j=0;j<=l;++j){
                dp[i][j].first=-1;
            }
        }
        for(int i=0;i<n;++i){
            cin>>arr[i];
        }
        pair<int,ll> ans = calc(0,0);
        cout << "Case " << it << ":\n";
        cout << "Minimum number of lectures: " << ans.first << '\n';
        cout << "Total dissatisfaction index: " << ans.second << '\n';
        it++;
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