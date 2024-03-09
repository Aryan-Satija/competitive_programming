// 2000
// CODEFORCES


// _ _ | _ _
// _ _ | _ _
// ----------
// _ _ | _ _ 
// _ _ | _ _

// every 4x4 submatrix can be formed by 4 2X2 disjoint sub_submatrices....each having odd ones

// odd1 + odd2 + odd3 + odd4 will always be even

// hence answer will be 0 for n > 3 and m > 3


// for n = 3

// the start can be
// odd   0 1 0   -->  even
// odd   1 0 1   -->  even

// even  0 0 1   --> odd
// odd   1 1 0   --> even

// odd   1 0 0   --> even
// even  0 1 1   --> odd

// even  1 1 1   --> odd 
// even  0 0 0   --> odd 

// min({option1, option2, option3, option4})
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat(n, vector<int>(m, -1));
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> mat[i][j];
        }
    }

    if(n > 3 and m > 3){
        cout << -1 << endl;
        return 0;
    }
    
    if(n == 1 || m == 1) { 
        cout << 0 << endl;
        return 0;
    }

    if(n == 2){
        int cnt_odd = 0, cnt_even = 0;
        for(int i = 0; i < m; i++){
            if((mat[0][i] + mat[1][i])&1){
                if(i&1) cnt_odd++;
                else cnt_even++;
            }
            else{
                if(i&1) cnt_even++;
                else cnt_odd++;
            }
        }
        cout << min(cnt_even, cnt_odd) << endl;
        return 0;
    }

    if(m == 2){
        int cnt_odd = 0, cnt_even = 0;
        for(int i = 0; i < n; i++){
            if((mat[i][0] + mat[i][1])&1){
                if(i&1) cnt_odd++;
                else cnt_even++;
            }
            else{
                if(i&1) cnt_even++;
                else cnt_odd++;
            }
        }
        cout << min(cnt_even, cnt_odd) << endl;
        return 0;
    }

    if(n == 3){
        // DIY...
    }

    if(m == 3){
        // DIY...
    }
}