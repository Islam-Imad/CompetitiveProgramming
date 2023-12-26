#include <bits/stdc++.h>
using namespace std;

#define ll long long int
const int N=12+9;
int a[N]={0,31,28,31,30,31,30,31,31,30,31,30,31},d1,d2,m1,m2,ye1,ye2,n,c1,c2,sub;
ll ans=0;
bool is_leap(int y){
    if((y%4==0)&&(y%100!=0))
        return true;
    return ((y%400)==0);
}
bool is_consecutive(){
    if(ye1==ye2){
        if(m1==m2){
            return d2-d1==1;
        }
        else{
            return (d1==a[m1]+(is_leap(ye1)&&m1==2))&&(d2==1&&m2-m1==1);
        }
    }
    else{
        return (d1==31&&m1==12&&d2==1&&m2==1&&(ye2-ye1==1));
    }
}
void Solve(){
    while(cin>>n&&n){
    for(int i=1;i<=n;++i){
        cin>>d2>>m2>>ye2>>c2;
        if(is_consecutive())
        ans+=(c2-c1),sub++;
        d1=d2,m1=m2,ye1=ye2,c1=c2;
    }
    cout << sub << ' ' << ans << "\n";
    d1=0,m1=0,ye1=0,ans=0,sub=0;
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
