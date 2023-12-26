#include <bits/stdc++.h>
using namespace std;

#define ll long long int
double const EPS=5e-6;

void Solve(){
    cout << fixed <<  setprecision(2);
    int n;
    double h;
    while(scanf("%d",&n)!=EOF){
    scanf("%lf",&h);
    double low=0.0,high=h-(1e-5),mid,ans;
    for(int i=1;i<=200;++i){
        mid=(low+high)/2;
        bool flag=0;
        double a=2,b=2,c=1,inc=4,res;
        for(int j=3;j<=n;++j){
            res=(a*mid+b-(c*h));
            if(res+(1e-9)<0)flag=1;
            a++,c++,b+=inc,inc+=2;
        }
        if(flag)low=mid;
        else{
            ans=res;
            high=mid;
        }
    }
    cout << fabs(ans) << "\n";
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
