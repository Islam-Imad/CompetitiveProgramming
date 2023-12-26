#include <bits/stdc++.h>
using namespace std;

#define ll long long int
const int N=20000+5;
int a[N],cur=1,ans=-1,start,End,sub,n,ans_l=-1,ans_r=-1;
void Solve(){
    start=0,End=0,sub=0,ans=-1,ans_l=-1,ans_r=-1;
    cin>>n;
    for(int i=0;i<n-1;++i)cin>>a[i];
    for(int i=0;i<n-1;++i){
        sub+=a[i];
        if(sub<0)sub=0,start=i+1,End=i+1;
        else{
            if(sub>ans){
                End=i;
                ans_l=start,ans_r=End;
                ans=sub;
            }
            else if(sub==ans){
                End=i;
                if(start==ans_l){
                    ans_r=End;
                }
                else if(End-start>ans_r-ans_l){
                    ans_l=start,ans_r=End;
                }
            }
        }
    }
    if(ans<=0)
    {
        cout << "Route " << cur << " has no nice parts" << "\n";
    }
    else
    {
        cout << "The nicest part of route "<<  cur << " is between stops " <<  ans_l+1 <<" and " << ans_r+2 << "\n";
    }
    cur++;
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
