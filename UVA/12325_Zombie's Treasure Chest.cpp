#include <bits/stdc++.h>
using namespace std;

#define ll long long int
ll n,s1,v1,s2,v2,szl,szr,lc,test=1,ret=0;
ll answer(){
    ll x=0,ans=0,sub=0,rem;
    while(x*s1<=szr){
        sub=(x*v1);
        rem=(szr-(x*s1));
        sub+=((rem/s2)*v2);
        ans=max(ans,sub);
        x++;
    }
    return ans;
}
void Solve(){
    cin>>n>>s1>>v1>>s2>>v2;
    if(s2>s1)swap(s1,s2),swap(v1,v2);
    lc=__gcd(s1,s2);
    lc=(s1*s2)/lc;
    szl=n/lc;
    szl=(szl-1)*lc,szl=max(0ll,szl);
    szr=(n-szl);
    ret=max((szl/s1)*v1,(szl/s2)*v2);
    ret+=(answer());
    cout << "Case #" << test++ << ": " << ret << "\n";
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
