#include <bits/stdc++.h>
using namespace std;

#define ll long long int
int n,m,idx,jdx;
string cur="";

vector<pair<vector<string>,int>>db;
bool com(pair<vector<string>,int>&a,pair<vector<string>,int>&b){
    if(a.first[idx]!=b.first[idx])
        return a.first[idx]<b.first[idx];
    return a.first[jdx]<b.first[jdx];
}

void Solve(){
    while(cin>>n>>m&&n){
    cur="";
    cin.ignore();
    for(int i=1;i<=n;++i){
        string t;
        getline(cin,t);
        t.push_back(',');
        vector<string>v;
        for(int i=0;i<t.size();++i){
            if(t[i]==','){
                v.push_back(cur);
                cur="";
            }
            else cur.push_back(t[i]);
        }
        db.push_back({v,i});
    }
    bool flag=1;
    for(int i=0;i<m&&flag;++i){
        for(int j=i+1;j<m&&flag;++j){
            idx=i,jdx=j;
            sort(db.begin(),db.end(),com);
            for(int k=1;k<n;++k){
                if(db[k].first[i]==db[k-1].first[i]){
                    if(db[k].first[j]==db[k-1].first[j]){
                        cout << "NO\n";
                        cout << min(db[k].second,db[k-1].second) << ' ' << max(db[k-1].second,db[k].second) << "\n";
                        cout << i+1 << ' ' << j+1 << "\n";
                        flag=0;
                        break;
                    }
                }
            }
    
        }
    }
    if(flag)
    cout << "YES" << "\n";
    db.clear();
    n=0,m=0;
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
