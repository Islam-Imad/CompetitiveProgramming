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
#define ld long double
#define rall(v) v.rbegin(), v.rend()
#define all(v) v.begin(), v.end()
#define sz(v) ((int)(v.size()))
#define mem(arr,val) memset(arr,val,sizeof(arr));
#define MOD 1'000'000'007
#define PI acos(-1)
#define OO 1e9
#define EPS 1e-9
#define e 2.71828182845904523536
#define pb push_back
#define fi first
#define se second
#define P pop_back()
#define lp(i, n, v) for (int i = v; i < n; ++i)
#define rlp(i, n, v) for (int i = n-1; i >= v; --i)
typedef map<ll,ll>omap;
typedef unordered_map<ll,ll>umap;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<ll, ll> ii;
typedef vector<vector<ii>> vvii;

unordered_map<int,string>mp;
ll len[1005][1005]={};
vi out[1005][1005]={};
vi vec;
ll BFS(ll a,ll b,ll c){
    queue<ii>q;
    q.push({0,0});
    len[0][0]=1;
    ll ans=0,cnt=0;
    while(!q.empty())
    {
        ++cnt;
        ii p=q.front();
        ii s=p;
        int save=len[p.fi][p.se];
        q.pop();

        if(p.se==c)
        {
            ans=len[p.fi][p.se]-1;
            vec=out[p.fi][p.se];
            // cout << out[p.fi][p.se];
            // cout << p.fi << " " << p.se << "\n";
            break;
        }

        if(p.fi<a){
            if(!len[a][p.se]){
            out[a][p.se]={s.fi,s.se,1};
            q.push({a,p.se});
            len[a][p.se]=1+save;
            }
        }

        if(p.se<b){
            if(!len[p.fi][b]){
            out[p.fi][b]={s.fi,s.se,2};
            q.push({p.fi,b});
            len[p.fi][b]=1+save;
            }
        }

        if(p.fi&&p.se<b){
            ll rem=b-p.se;
            rem=min(rem,p.fi);
            p.fi-=rem;
            p.se+=rem;
            if(!len[p.fi][p.se]){
            out[p.fi][p.se]={s.fi,s.se,3};
            q.push({p.fi,p.se});
            len[p.fi][p.se]=1+save;
            // cout << "ONE" << "\n";
            // cout << s.fi << " " << s.se << "\n";
            // cout << p.fi << " " <<  p.se << "\n";
            }
        }
        p.fi=s.fi,p.se=s.se;
        if(p.se&&p.fi<a){
            ll rem=a-p.fi;
            rem=min(rem,p.se);
            p.se-=rem;
            p.fi+=rem;
            if(!len[p.fi][p.se]){
            out[p.fi][p.se]={s.fi,s.se,4};
            q.push({p.fi,p.se});
            len[p.fi][p.se]=1+save;
            // cout << "TWO" << "\n";
            // cout << s.fi << " " << s.se << "\n";
            // cout << p.fi << " " <<  p.se << "\n";
            }
        }

        p.fi=s.fi,p.se=s.se;

        if(p.fi){
            if(!len[0][p.se]){
            out[0][p.se]={s.fi,s.se,5};
                q.push({0,p.se});
                len[0][p.se]=1+save;
            }
        }
        if(p.se){
            if(!len[p.fi][0]){
            out[p.fi][0]={s.fi,s.se,6};
                q.push({p.fi,0});
                len[p.fi][0]=1+save;
            }
        }
    }
    return ans;
}
void print(vi vec){
    if(sz(vec)==0)return;
    print(out[vec[0]][vec[1]]);
    cout << mp[vec.back()] << "\n";
}
int main()
{
    Islam_Imad();
    mp[1]="fill A";
    mp[2]="fill B";
    mp[3]="pour A B";
    mp[4]="pour B A";
    mp[5]="empty A";
    mp[6]="empty B";
    ll a,b,c;
    while(cin>>a>>b>>c&&a!=EOF){
    mem(len,0);
    BFS(a,b,c);
    print(vec);
    cout << "success"<<"\n";
    }
}
