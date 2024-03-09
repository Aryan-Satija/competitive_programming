// 1600
// https://codeforces.com/contest/1138/problem/D
#include <bits/stdc++.h>
using namespace std;
vector<int> generatePiTable(string needle){
    int n = needle.size();
    vector<int> piTable(n, 0);
    for(int i = 1; i < n; i++){
        int ll = piTable[i-1];
        while(ll > 0 && needle[ll] != needle[i]) ll = piTable[ll-1]; 
        if(ll == 0)
            piTable[i] = (needle[i] == needle[0] ? 1 : 0);
        else piTable[i] = ll +1;
    }
    return piTable;
}
int main(){
    string bin1, bin2;
    cin >> bin1 >> bin2;
    vector<int> pi = generatePiTable(bin2);
    int ones = 0, zeroes = 0;
    for(auto ch : bin1){
        if(ch == '0') zeroes++;
        else ones++;
    }
    string res = "";
    int idx = 0;
    while(ones > 0 and zeroes > 0){
        if(bin2[idx] == '0'){
            if(zeroes > 0){
                res += '0';
                zeroes--;
            }
            else break;
        }
        else {
            if(ones > 0){
                res += '1';
                ones--;
            }
            else break;
        }
        idx = idx + 1 == bin2.size() ? pi[idx] : idx + 1; 
    }
    while(ones > 0){
        res += '1';
        ones--;
    }
    while(zeroes > 0){
        res += '0';
        zeroes--;
    }
    cout << res << endl;
}