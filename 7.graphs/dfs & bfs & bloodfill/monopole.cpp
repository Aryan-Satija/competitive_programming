// 2000
// https://codeforces.com/contest/1345/problem/D
#include <bits/stdc++.h>
using namespace std;
 
#define mod 1000000007
 
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vb vector<bool>
#define vvi vector<vector<int>>
#define vvb vector<vector<bool>>
#define vvc vector<vector<char>>
#define vvll vector<vector<long long int>>
#define vc vector<char>
#define vll vector<long long>
#define mii map<int, int>
#define umii unordered_map<int, int>
#define si set<int>
#define rep(i, s, e) for(ll i = s; i <= e; i++)
#define ren(i, s, e) for(ll i = s; i >= e; i--)
 
int n, m;
 
void dfs(int i, int j, vvb &vis, vvc &mat){
    vis[i][j] = false;
    if(i-1 >= 0 and mat[i-1][j] == '#' and vis[i-1][j]){
        dfs(i-1, j, vis, mat);
    }
    if(i+1 < n and mat[i+1][j] == '#' and vis[i+1][j]){
        dfs(i+1, j, vis, mat);
    }
    if(j-1 >= 0 and mat[i][j-1] == '#' and vis[i][j-1]){
        dfs(i, j-1, vis, mat);
    }
    if(j+1 < m and mat[i][j+1] == '#' and vis[i][j+1]){
        dfs(i, j+1, vis, mat);
    }
}
 
int solve(){
    cin >> n >> m;
    vvc mat(n, vc(m));
    rep(i, 0, n-1){
        rep(j, 0, m-1){
            cin >>  mat[i][j];
        }
    }
    
    
    // row[i] ---> is there any # in the ith row
    // col[i] ---> is there any # in the ith col
 
    vb row(n, false), col(m, false);
    
    rep(i, 0, n-1){
        rep(j, 0, m-1){
            if(mat[i][j] == '#'){
                row[i] = true;
                col[j] = true;
            }
        }
    }
 
    // there should we atleast one cell in each row and in each column where we can place south monopole
    bool south = true;
    
    rep(i, 0, m-1){
        south = (south & col[i]);
    }
 
    if(south){
        rep(i, 0, n-1){
            if(!row[i])
                return -1;
        }
    }
    
    south = true;
    
    rep(i, 0, n-1){
        south = (south & row[i]);
    }
 
    if(south){
        rep(i, 0, m-1){
            if(!col[i])
                return -1;
        }
    }
 
 
    // there should be only one segment on #s in each row and column
    rep(i, 0, n-1){
        bool flag_hashtag = false;
        int seg = 0;
        rep(j, 0, m-1){
            if(mat[i][j] == '#'){
                if(!flag_hashtag){
                    seg++;
                    flag_hashtag = true;
                }
            }
            else
                flag_hashtag = false;
        }
        if(seg > 1) return -1;
    }
 
    rep(i, 0, m-1){
        bool flag_hashtag = false;
        int seg = 0;
        rep(j, 0, n-1){
            if(mat[j][i] == '#'){
                if(!flag_hashtag){
                    seg++;
                    flag_hashtag = true;
                }
            }
            else
                flag_hashtag = false;
        }
        if(seg > 1) return -1;
    }
    
    int north = 0;
 
    vvb vis(n, vb(m, true));
    rep(i, 0, n-1){
        rep(j, 0, m-1){
            if(mat[i][j] == '#' and vis[i][j]){
                dfs(i, j, vis, mat);
                north++;
            }
        }
    }
 
    return north;
}
 
 
int main(){
    int t = 1;
    while(t--){
        cout << solve() <<endl;
    }
}