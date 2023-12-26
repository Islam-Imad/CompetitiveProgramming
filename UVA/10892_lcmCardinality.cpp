#include <bits/stdc++.h>
using namespace std;

#define ll long long int

void Solve(){
	int n;
	while(cin>>n&&n!=0){
		int ret = 0, N = 0;
		vector<ll>v;
		for(int i=1;i*i<=n;++i){
			if(n%i==0){
				v.push_back(i);
				if(i*i!=n)v.push_back(n/i);
			}
		}
		sort(v.begin(),v.end());
		N = v.size();
		for(int i=0;i<N;++i){
			for(int j=i;j<N;++j){
				ret += ((v[i]/__gcd(v[i],v[j])*v[j])==n);
			}
		}
		cout << n << ' ' << ret << "\n";
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
