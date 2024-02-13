#include <bits/stdc++.h>
using namespace std;

#define ll long long int

const int N = 12;
pair<pair<double,double>,pair<double,double>> arr[N];
int n = 1;
bool is_inside(int i,double x,double y){
    return x>arr[i].first.first&&x<arr[i].first.second&&y>arr[i].second.first&&y<arr[i].second.second;
}
void Solve(){
    char ch;
    double x1,y1,x2,y2;
    while(cin>>ch){
        if(ch=='*'){
            int idx = 1;
            while(cin>>x1>>y1){
            if(x1 == 9999.9 && y1 == 9999.9)return;
            bool flag = 1;
            for(int i=1;i<=n;++i){
                if(is_inside(i,x1,y1)){
                    cout << "Point " << idx <<" is contained in figure " <<  i << '\n';
                    flag = 0;
                }
            }
            if(flag)
            cout << "Point "  << idx << " is not contained in any figure\n";
            idx++;
            }
        }
        else{
            cin>>x1>>y1>>x2>>y2;
            if(x2<x1)swap(x1,x2);
            if(y2<y1)swap(y1,y2);
            arr[n] = {{x1,x2},{y1,y2}}; 
            n++;
        }
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
