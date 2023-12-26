#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const int N=15;
int n,test=1,cas=1;
vector<vector<char>>grid,se_grid,G,temp;
string answer[15];
vector<vector<char>> ret(int Size){
    ++Size;
    return vector<vector<char>>(Size,vector<char>(Size));
}
void _rotate(){
    temp=grid;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            grid[j][n-i+1]=temp[i][j];
        }
    }
}
void _reflect(){
    temp=grid;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            grid[n-i+1][j]=temp[i][j];
        }
    }
}
void print(){
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            cout << grid[i][j];
        }
        cout << "\n";
    }
}
void Solve(){
    while(cin>>n){
        cas=1;
    grid = ret(n);
    se_grid = ret(n);
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            cin>>grid[i][j];
        }
        for(int j=1;j<=n;++j){
            cin>>se_grid[i][j];
        }
    }
    if(grid==se_grid){
        cout << "Pattern" << ' ' << test++ << ' ' << answer[cas] << '.';
        cout << "\n";
    continue;
    }
    ++cas;
    _rotate();
    if(grid==se_grid){
        cout << "Pattern" << ' ' << test++ << ' ' << answer[cas] << " degrees.";
        cout << "\n";
    continue;
    }
    ++cas;
    _rotate();
    if(grid==se_grid){
        cout << "Pattern" << ' ' << test++ << ' ' << answer[cas] << " degrees.";
        cout << "\n";
    continue;
    }
    ++cas;
    _rotate();
    if(grid==se_grid){
        cout << "Pattern" << ' ' << test++ << ' ' << answer[cas] << " degrees.";
        cout << "\n";
    continue;
    }
    ++cas;
    _rotate();
    _reflect();
    if(grid==se_grid){
        cout << "Pattern" << ' ' << test++ << ' ' << answer[cas] << '.';
        cout << "\n";
    continue;
    }
    ++cas;
    _rotate();
    if(grid==se_grid){
        cout << "Pattern" << ' ' << test++ << ' ' << answer[cas] << " degrees.";
        cout << "\n";
    continue;
    }
    ++cas;
    _rotate();
    if(grid==se_grid){
        cout << "Pattern" << ' ' << test++ << ' ' << answer[cas] << " degrees.";
        cout << "\n";
    continue;
    }
    ++cas;
    _rotate();
    if(grid==se_grid){
        cout << "Pattern" << ' ' << test++ << ' ' << answer[cas] << " degrees.";
        cout << "\n";
        continue;
    }
    cas++;
    cout << "Pattern" << ' ' << test++ << ' ' << answer[cas] << "\n";
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
    answer[1]="was preserved";
    answer[2]="was rotated 90";
    answer[3]="was rotated 180";
    answer[4]="was rotated 270";
    
    answer[5]="was reflected vertically";
    answer[6]="was reflected vertically and rotated 90";
    answer[7]="was reflected vertically and rotated 180";
    answer[8]="was reflected vertically and rotated 270";

    answer[9]="was improperly transformed.";
    while(tc--){
        Solve();
    }
}
