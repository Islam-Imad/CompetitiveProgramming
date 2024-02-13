#include <bits/stdc++.h>
using namespace std;

#define ll long long int

void Solve(){
	int a,b,c,n,m,ans=0;
	cin>>a>>b>>c>>m>>n;
	vector<int>v(n),fre(m);
	v[0]=a,fre[0]=1;
	for(int i=1;i<n;++i){
		v[i]=((v[i-1]*b)+c)%m,v[i]+=1;
	}
	v[0]%=m,ans+=fre[v[0]],fre[v[0]]++;
	for(int i=1;i<n;++i){
		v[i]=((v[i]%m)+(v[i-1]%m))%m,ans+=fre[v[i]],fre[v[i]]++;
	}
	cout << ans << '\n';
}

int main()
{
	ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
	#endif
	int tc=1,tt=1;
	cin>>tc;
	while(tc--){
		cout << "Case " << tt++ << ": ";
		Solve();
	}
}
