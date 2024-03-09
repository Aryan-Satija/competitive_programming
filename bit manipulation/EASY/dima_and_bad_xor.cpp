// 1600
// CODEFORCES
// https://codeforces.com/problemset/problem/1151/B

#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)
            cin >> mat[i][j];
    }

    bool flag = false;

    for(int k = 0; k < 10; k++){
        int cnt_1 = 0;
        for(int i = 0; i < n; i++){
            bool one = false, zero = false;
            for(int j = 0; j < m; j++){
                if(mat[i][j] & (1 << k)) one = true;
                else zero = true;
            }
            if(zero && one)
                flag = true;
            else if(one) cnt_1++;
        }
        if(flag){
            cout << "TAK" << endl;
            if(cnt_1&1){
                for(int i = 0; i < n; i++){
                    bool choice = false;
                    for(int j = 0; j < m; j++){
                        if(!(mat[i][j] & (1 << k))){
                            cout << j + 1 << " ";
                            choice = true;
                            break;
                        }
                    }
                    if(!choice) cout << 1 << " ";
                }
                cout << endl;
            }
            else {
                bool choose = true;
                for(int i = 0; i < n; i++){
                    int one = -1, zero = -1;
                    for(int j = 0; j < m; j++){
                        if(mat[i][j] & (1 << k)) one = j+1;
                        else zero = j+1;
                    }
                    if(zero != -1 && one != -1){
                        cout << (choose ? one : zero) << endl;
                        choose = false;
                    }
                    else{
                        cout << 1 << " ";
                    }
                }
                cout << endl;
            }
            break;
        }
        else if(cnt_1&1){
            flag = true; 
            cout << "TAK" << endl;
            for(int i = 0; i < n; i++) cout << 1 << " ";
                cout << endl;
            break;
        }
    }
    if(!flag) cout << "NIE" << endl;
}