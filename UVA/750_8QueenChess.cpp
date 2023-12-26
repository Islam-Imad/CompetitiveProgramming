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
#define no cout << "NO"
#define yes cout << "YES"
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
int row[20],col[20],diagonal[20],anti[20];
int r,c;
vi cur_state(8);
vvi all_path;
bool is_valid(int i,int j){
    return row[i]==0&&col[j]==0&&diagonal[i+j+1]==0&&anti[(8-j)+i]==0;
}
void mark(int i,int j,int m){
    row[i]+=m;
    col[j]+=m;
    diagonal[i+j+1]+=m;
    anti[(8-j)+i]+=m;
}

void N_Queen(int i)
{
    if(i==8)
    {
        all_path.pb(cur_state);
        return;
    }
    if(i==r)
    {
        cur_state[c]=i+1;
            N_Queen(i+1);
        cur_state[c]=0;
        return;
    }
    for(int j=0;j<8;++j)
    {
        if(is_valid(i,j))
        {
            mark(i,j,1);
                cur_state[j]=i+1;
                    N_Queen(i+1);
                cur_state[j]=0;
            mark(i,j,-1);
        }
    }
}
int main()
{
    Islam_Imad();
    int t;cin>>t;
    while(t--){
        mem(row,0);mem(col,0);mem(diagonal,0);mem(anti,0);
        cin>>r>>c;
        --r,--c;
        mark(r,c,1);
        N_Queen(0);
        int size=sz(all_path);
        cout << "SOLN" << "       " << "COLUMN" << "\n";
        cout << " #"   << "      " << "1 2 3 4 5 6 7 8" << "\n"; 
        cout << "\n";
        sort(all(all_path));
        lp(i,size,0){
            cout <<setw(2)<< i+1;cout<<fixed<<setw(7); 
            cout << all_path[i][0];
            lp(j,sz(all_path[i]),1){
                cout << " " << all_path[i][j];
            }
            cout << "\n";
        }
        if(t)
        cout << "\n";
        all_path.clear();
    }
}
