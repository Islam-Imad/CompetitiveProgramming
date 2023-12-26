#include <bits/stdc++.h>
using namespace std;

void Islam_Imad()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#endif
}

template <class t>
ostream &operator<<(ostream &out, vector<t> &a)
{
    for (auto &i : a)
        out << i << " ";
    out << "\n";
    return out;
}
template <class t>
istream &operator>>(istream &in, vector<t> &a)
{
    for (auto &i : a)
        in >> i;
    return in;
}

#define debug(x) cout << #x << ": " << (x) << "\n"
#define no cout << "Impossible"
#define yes cout << "Possible"
#define ll long long int
#define ull unsigned long long int
#define ld long double
#define allr(v) v.rbegin(), v.rend()
#define all(v) v.begin(), v.end()
#define sz(v) ((int)(v.size()))
#define mem(arr,val) memset(arr,val,sizeof(arr));
#define MOD 1'000'000'007
#define PI acos(-1)
#define OO 1e9
#define EPS 1e-9
#define pb push_back
#define fi first
#define se second
#define P pop_back()
#define lp(i, n, v) for (int i = v; i < n; ++i)
#define rlp(i, n, v) for (int i = n-1; i >= v; --i)
typedef map<int,int>omap;
typedef unordered_map<int,int>umap;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef pair<int, int> ii;
typedef vector<vector<ii>> vvii;

/*
-->Dicliplinses
.Read Carefully
.Boundaries(overflow,time limit,big and small values)
.Tricky test cases
.Extract constraints focus on special ones and avoid assumption
.play words
.Trace
.i/o format
*/

int vis[5];
int nums[5];

bool BackTrack(int value,int len){
    if(len==0){
        return (value==23);
    }
    lp(i,5,0){
        if(vis[i]==0){
            vis[i]=1;
            bool c1=0,c2=0,c3=0,c4=0;
            if(len==5){
                c1=BackTrack(nums[i],len-1);
            }
            else{
                c2=BackTrack(value*nums[i],len-1);
                c3=BackTrack(value+nums[i],len-1);
                c4=BackTrack(value-nums[i],len-1);
            }
            vis[i]=0;
            if(c1||c2||c3||c4)return true;
        }
    }
    return false;
}
int main()
{
    Islam_Imad();
    while(true){
    int mini=INT_MAX;
    int maxi=INT_MIN;
    lp(i,5,0){
        cin>>nums[i];
        mini=min(mini,nums[i]);
        maxi=max(maxi,nums[i]);
    }
    if(mini==0&&maxi==0)break;
    (BackTrack(0,5)?yes:no);
    cout << "\n";
    }
}
