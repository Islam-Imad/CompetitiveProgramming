#include <bits/stdc++.h>
using namespace std;

#define ll long long int

int const N = 200;
ll arr[N],n,len,cnt=0;
string x;

ll nCr(int n,int k){
	ll nom=1,den=1;
	for(ll i=0;i<k;++i){
		nom*=(n-i),den*=(i+1);
	}
	return (nom/den);
}

ll calc(char ch,int len){
	if(arr[ch]==0)return 0;
	ll ret = 1;
	for(char c='a';c<='z';++c){
		ret*=nCr(len,arr[c]-(c==ch));
		len-=(arr[c]-(c==ch));
	}
	return ret;
}

void Solve(){
	while(cin>>x&&x!="#"){
		n = x.size(),len=n;
		for(auto &i:x)arr[i]++;
		for(int i=0;i<n;++i){
			for(char c='a';c<='z';++c){
				if(c==x[i]){
					arr[c]--;
					break;
				}
				else{
					cnt+=calc(c,n-i-1);
				}
			}
		}
		int i = 9;
		++cnt;
		string ret = string(10,' ');
		while(cnt){
			ret[i]=(char('0'+(cnt%10)));
			cnt/=10;
			--i;
		}
		cout << ret << '\n';
		n = len = cnt = 0;
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
