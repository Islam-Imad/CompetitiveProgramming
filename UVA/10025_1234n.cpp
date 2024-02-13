// Hint 1
// find the smallest number that hold this condition sigma(1+2+3+...+n)>=sum
// if you can remove some numbers what will be the answer to the question , Think
// but you subtract it twice isn't it ?
// odd,even -0.0-
#include <bits/stdc++.h>
using namespace std;

#define ll long long int

void solve(){
    ll sum;cin>>sum,sum=abs(sum);
    ll l = 1,r = 1e6 , m,ans = 0;
    while(l<=r){
        m=(l+r)>>1;
        ((m*(m+1)/2)>=sum)?ans=m,r=m-1:l=m+1;
    }
    while(true){
        if((ans*(ans+1)/2 - sum)%2==0)break;
        ans++;
    }   
    cout << ans << '\n';
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
        solve();
        if(tc)cout << '\n';
    }
}