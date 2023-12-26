#include <bits/stdc++.h>
using namespace std;
#define ll long long int

const int OO = (1e9);
const int N=2e6+5;
int End=2000002;
int start=0,t[4*N],vis[N];
int Insert_myval(int v,int l,int r,int val){
    t[v]++;
    if(r==l)return t[v];
    int mid=(l+r)/2;
    if(val<=mid)
        return Insert_myval(2*v,l,mid,val);
    return t[2*v]+Insert_myval(2*v+1,mid+1,r,val);
}
int Delete_Kth(int v,int l,int r,int k){
    t[v]--;
    if(l==r)return l;
    if(t[2*v]>=k)
        return Delete_Kth(2*v,l,(r+l)/2,k);
    return Delete_Kth(2*v+1,((l+r)/2)+1,r,k-t[2*v]);
}
int get_Kth(int v,int l,int r,int k){
    if(l==r)return l;
    if(t[2*v]>=k)return get_Kth(2*v,l,(l+r)/2,k);
    return get_Kth(2*v+1,((l+r)/2)+1,r,k-t[2*v]);
}
void Solve(){

    for(int i=1;i<=End;i+=2)Insert_myval(1,start,End,i);
    int val=2,inc=val,k=2,it=1,num;
    while(get_Kth(1,start,End,val)!=End){
        inc=get_Kth(1,start,End,val),it=1;
        k=inc;
        while(Delete_Kth(1,start,End,k)!=End){
            it++;
            k=(it*inc)-it+1;
        }
        val++;
    }
    it=1;
    while(get_Kth(1,start,End,it)!=End){
        vis[get_Kth(1,start,End,it)]=1;
        // cout << get_Kth(1,start,End,it) << "\n";
        ++it;
    }
    // cout << it << "\n";
    while(cin>>num){
        it=0;
        if(num%2==0){
        int mid=num/2;
        for(int k=mid;k>=0;--k){
            if(vis[k]&&vis[num-k]){
                cout << num << " is the sum of " << k << " and " << num-k << ".\n";
                it=1;
                break;
            }
        }
        }
        if(it!=1)
        cout << num << " is not the sum of two luckies!\n";
    }
}


int main()
{
    ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    // freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
    int tc=1;
    // cin>>tc;
    while(tc--)Solve();
}
