#include <bits/stdc++.h>
using namespace std;

#define ll long long int

void Solve(){
    cout << fixed << setprecision(0);
    string st,base="",ret="";int k;
    ll num,c;
    long double L = 0, R = 0 , cur = 1;
    cin>>k>>st>>num,base = string (k,'0'),c=num;
    num=abs(num);
    for(int i=k-1;i>=0;--i){
        if(st[i]=='p')R+=cur;
        else L+=cur;
        cur*=2ll;
        if(num%2==1)base[i]='1';
        num/=2ll;
    }
    L*=-1ll;

    if(c<L||c>R)cout << "Impossible";
    else{
        if(c<0){
            for(int i=0;i<k;++i){
                if(st[i]=='p')st[i]='n';
                else st[i]='p';
            }
        }
        bool flag = false;
        for(int i=k-1;i>=0;--i){
            if(flag==0){
            if(base[i]=='1'&&st[i]=='n'){
                ret.push_back('1');
                flag=1;
            }
            else{
                ret.push_back(base[i]);
            }
            }
            else{
                if(base[i]=='0'&&st[i]=='p'){
                    ret.push_back('1');
                    flag=0;
                }
                else{
                    if(base[i]=='0')ret.push_back('1');
                    else ret.push_back('0');
                }
            }
        }
        reverse(ret.begin(),ret.end());
        cout << ret ;
    }
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
    #endif
    int tc=1;
    cin>>tc;
    while(tc--)Solve();
}
