#include <bits/stdc++.h>
using namespace std;

#define ll long long int
pair<double,double>p1,p2,p3,p4;
void Solve(){
    cout << fixed << setprecision(3);
    while(cin>>p1.first>>p1.second>>p2.first>>p2.second>>p3.first>>p3.second>>p4.first>>p4.second)
    {
    if(p3!=p1 and p3!=p2)swap(p4,p3);
    if(p2==p3)swap(p1,p2);

    cout << p2.first+p4.first-p1.first << ' ' << p2.second+p4.second-p1.second << '\n';
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
