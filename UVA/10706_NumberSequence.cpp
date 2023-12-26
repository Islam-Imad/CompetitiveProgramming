#include <bits/stdc++.h>
using namespace std;

#define ll long long int
const int N = 32000;
ll arr[N];
void pre(){
    ll ret = 0,cur=0;
    for(int i=1;i<=32000;++i){
        auto x = [&](int num){ll inc=0;while(num)inc++,num/=10;return inc;};
        cur+=x(i);
        ret+=cur;
        arr[i]=ret;
        if(ret>INT_MAX){
            break;
        }
    }
}
void Solve(){
    ll idx;cin>>idx;
    int l=1,r=31268,m,ans=1;
    while(l<=r){
        m=(l+r)/2;
        arr[m]>=idx?ans=m,r=m-1:l=m+1;
    }

    idx-=arr[ans-1];
    for(int i=1;i<=ans;++i){
        string cur = to_string(i);
        for(int i=0;i<cur.size();++i){
            if(idx==1){
                cout << cur[i] << '\n';
                return;
            }
            --idx;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
    #endif
    pre();
    int tc=1;
    cin>>tc;
    while(tc--)Solve();
}
