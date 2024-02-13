#include <bits/stdc++.h>
using namespace std;

#define ll long long int
ll a,b,OO=1e10,l,r;
string x;
bool input(){
	a=OO,b=OO;
	string cur = "";
	for(int i=0;i<x.size();++i){
		if(x[i]!=' ')
		cur.push_back(x[i]);
		if(x[i]==' ' or (i+1==x.size())){
			if(a==OO)
			a=stoi(cur);
			else 
			b=stoi(cur);
			cur="";
		}
	}
	return b==OO;
}
void Solve(){
	while(getline(cin,x)&&x!=""){
		if(input()){
			if(a&1){
				l = 1+a,l/=2;
				cout << abs(l) << ' ' << abs(a-l) << '\n';
			}
			else if(a%4==0){
				l = (2+(a/2))/2;
				cout << abs(l) << ' ' << abs((a/2)-l) << '\n';
			}
			else{
				cout << "Bachelor Number.\n";
			}
		}
		else{
			a=abs(a),b=abs(b);
			if(a>b)swap(a,b);
			l = (b/2)-((a-1)/2),r=(b/4-((a-1)/4));
			cout << l-r << '\n';
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
