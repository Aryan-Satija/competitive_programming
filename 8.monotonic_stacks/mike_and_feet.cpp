// https://codeforces.com/contest/547/problem/B
// mike and feet
// 1900

#include <bits/stdc++.h>
using namespace std;

vector<int> nse(vector<int>& arr) {
    vector<int> result(arr.size(), arr.size()); 
    stack<int> st;
    for (int i = arr.size() - 1; i >= 0 ; i--) {
        while (!st.empty() && arr[i] <= arr[st.top()]) 
            st.pop();
        if(st.size() > 0) result[i] = st.top();
        st.push(i);
    }
    return result;
}

vector<int> pse(vector<int>& arr) {
    vector<int> result(arr.size(), -1);
    stack<int> st;
    for (int i = 0; i < arr.size(); i++) {
        while (!st.empty() && arr[i] <= arr[st.top()]) 
            st.pop();
        if(st.size() > 0)
            result[i] = st.top(); 

        st.push(i);
    }
    return result;
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    vector<int> next = nse(arr), prev = pse(arr);
    vector<int> res(n+1, 0);
    for(int i = 0; i < n; i++){
        int len = (next[i] - prev[i] - 1);
        // s1 ..... arri ..... s2
        // where s1 and s2 are smaller than arri and are closest to arri behind it and in front of it respectively.
        // now the length of the subarray so formed is len
        // so we need to do,
        // res[len] = max(res[len], arr[i]) 
        // res[len-1] = max(res[len-1], arr[i]) 
        // .... 
        // res[1] = max(res[1], arr[i]) 


        // but this would be an O(n^2) solution
        // we can do that in the last altogether !!!!!!!!!

        res[len] = max(res[len], arr[i]); 
    }

    for(int i = n-1; i >= 1; i--){
        res[i] = max(res[i], res[i+1]);
    }

    for(int i = 1; i <= n; i++) cout << res[i] << " ";
    cout << endl;
}
