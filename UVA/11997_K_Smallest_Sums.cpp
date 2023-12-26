#include <bits/stdc++.h>
using namespace std;

#define ll long long int

void Solve(){
    int n,sum=0;
    while(cin>>n&&n){
        sum=0;
    vector<vector<int>>v1(n+5,vector<int>(n)),v2(n+5);
    vector<int>gv;
    vector<pair<int,int>>arr;
    for(int i=1;i<=n;++i){
        for(int j=0;j<n;++j){
            cin>>v1[i][j];
        }
        sort(v1[i].begin(),v1[i].end());
        sum+=v1[i][0];
        for(int k=1;k<n;++k)arr.push_back({v1[i][k]-v1[i][0],i});
    }
    sort(arr.begin(),arr.end());
    for(int i=0;i<n;++i){
        v2[arr[i].second].push_back(arr[i].first);
    }

    gv.push_back(0);
    for(int i=1;i<=n;++i){
        vector<int>ret = gv;
        int cur = gv.size();
        for(int j=0;j<v2[i].size();++j){
            for(int k=0;k<cur;++k){
                ret.push_back(gv[k]+v2[i][j]);
            }
        }
        sort(ret.begin(),ret.end());
        while(ret.size()>n)ret.pop_back();
        gv.swap(ret);
    }

    cout << sum << ' ' ;
    for(int i=1;i<n;++i)cout << sum + gv[i] << " \n"[i==n-1];
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
