#include <bits/stdc++.h>
using namespace std;

#define ll long long int
const ll OO = 1e18;
const int N=1e5+5;
int test=1,n,q,m=0;
ll a[N],val;
string x;
vector<int>ve;
template<typename T=int>
struct Segment_Tree{
    int N;
    vector<T>seg_tree,tree;
    Segment_Tree(int N):N(N){seg_tree=tree=vector<T>(4*N);};
    T Q(T a,T b){
        return min(a,b);
    }
    void Build(int node,int left,int right){
        if(left==right){seg_tree[node]=a[left];return;}
        Build(2*node,left,(left+right)/2),Build(2*node+1,((left+right)/2)+1,right);
        seg_tree[node]=Q(seg_tree[2*node],seg_tree[2*node+1]);
    }
    void Update(int node,int left,int right,int x,T val){
        if(left==right){seg_tree[node]=val;return;}
		(x>=left&&x<=((left+right)/2))?Update(2*node,left,(left+right)/2,x,val):Update(2*node+1,((left+right)/2)+1,right,x,val);
        seg_tree[node]=Q(seg_tree[2*node],seg_tree[2*node+1]);
    }
    T Query(int node,int left,int right,int x,int y){
        if(right<x||left>y)return OO;
        if(left>=x&&right<=y)return seg_tree[node];
        return Q(Query(2*node,left,(left+right)/2,x,y),Query(2*node+1,((left+right)/2)+1,right,x,y));
    }
};
vector<int> nums(string x){
	string cur="";
	vector<int>ret;
	m=x.size();
	for(int i=1;i<m;++i){
		if(x[i]==',' or x[i]==')'){
			if(cur!="")
			ret.push_back(stoi(cur));
			cur="";
		}
		else cur.push_back(x[i]);
	}
	return ret;
}

void Solve(){
    cin>>n>>q;
	Segment_Tree<ll>seg(n);
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	seg.Build(1,1,n);
	for(int i=1;i<=q;++i){
		cin>>x;
		ve=nums(x.substr(5));
		// for(auto &pr:ve)cout << pr << ' ';
		// cout << "\n";
		if(x.front()=='q'){
			cout << seg.Query(1,1,n,ve[0],ve[1]) << "\n";
		}
		else {
			val=seg.Query(1,1,n,ve[0],ve[0]);
			for(int i=1;i<ve.size();++i){
				seg.Update(1,1,n,ve[i-1],seg.Query(1,1,n,ve[i],ve[i]));
			}
			seg.Update(1,1,n,ve.back(),val);
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

