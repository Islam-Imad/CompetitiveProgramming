#include <bits/stdc++.h>
using namespace std;

#define ll long long int
const int N=10100;
ll a[N],L[N],R[N],n,ans=0,sub=0,fl=0;
vector<ll>v;
void LI_DS(){
    v.clear();
    v.push_back(a[0]);
    (fl?R[n-1]=1:L[0]=1);
    for(int i=1;i<n;++i){
        if(a[i]>v.back())v.push_back(a[i]),(fl?R[n-i-1]:L[i])=v.size();
        else{
            int idx=lower_bound(v.begin(),v.end(),a[i])-v.begin();
            v[idx]=a[i];
            (fl?R[n-i-1]:L[i])=idx+1;
        }
    }
}
void Solve(){
    while(cin>>n){
    for(int i=0;i<n;++i)cin>>a[i],L[i]=0,R[i]=0;
    ans=0,sub=0,fl=0;
    LI_DS();
    fl=1;
    reverse(a,a+n);
    LI_DS();
    for(int i=0;i<n;++i){
        sub=(min(L[i],R[i])*2)-1;
        ans=max(ans,sub);
    }
    cout << ans << "\n";
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
