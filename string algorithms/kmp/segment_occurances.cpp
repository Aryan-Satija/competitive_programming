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
int count_occurances(string &haystack, string &needle, vector<int> &piTable, int l, int r){
    int needle_ptr = 0, haystack_ptr = l;
    int cnt = 0;
    while(haystack_ptr <= r){
        if(needle[needle_ptr] == haystack[haystack_ptr]){
            needle_ptr++; haystack_ptr++;
            if(needle_ptr == needle.size()){
                cnt++;
                needle_ptr = piTable[needle_ptr-1];
            }
        }
        else{
            if(needle_ptr == 0) haystack_ptr++;
            else needle_ptr = piTable[needle_ptr-1];
        }
    }
    return cnt;
}
int main(){
    int n, m, q;
    cin >> n >> m >> q;
    string haystack, needle;
    cin >> haystack >> needle;
    vector<int> piTable = generatePiTable(needle);
    for(int i = 0; i < q; i++){
        int l, r;
        cin >> l >> r;
        // as we need 0 based indexing
        l--;
        r--;
        cout << (count_occurances(haystack, needle, piTable, l, r)) << endl;
    }
}