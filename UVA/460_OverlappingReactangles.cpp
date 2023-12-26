#include <bits/stdc++.h>
using namespace std;

#define ll long long int

const int N = 10;
int a[N],b[N],c[N];
void Solve(){
    cin>>a[1]>>a[2]>>a[3]>>a[4]>>b[1]>>b[2]>>b[3]>>b[4];
    c[1]= max(a[1],b[1]);
    c[2]= max(a[2],b[2]);
    c[3]= min(a[3],b[3]);
    c[4]= min(a[4],b[4]);
    if(c[1]<c[3]&&c[2]<c[4]){
        cout << c[1] << ' ' << c[2] << ' ' << c[3] << ' ' << c[4] << '\n';
    }
    else cout << "No Overlap\n";
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
