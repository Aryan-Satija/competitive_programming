// LEETCODE
// MEDIUM
// https://leetcode.com/problems/remove-k-digits/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        stack<int> st;
        vector<int> nsi(n, n); // next smaller element's index


        for(int i = n-1; i >= 0; i--){
            while(!st.empty()){
                if(num[st.top()] < num[i])  break;
                st.pop();
            }
            if(!st.empty()) nsi[i] = st.top();
            st.push(i);
        }

        string res = "";
        int idx = 0;

        while(idx < n){
            if(num[idx] == '0'){
                if(res.size() != 0){
                    // ensuring that we don't add any leading zeroes....
                    res += '0';
                }
                idx++;
            }
            else{
                if(k >= (nsi[idx] - idx)){
                    k -= (nsi[idx] - idx);
                    idx = nsi[idx];
                } 
                else{
                    res += num[idx];
                    idx++;
                }
            }
        }

        return (res.size() == 0 ? "0" : res);
    }
};