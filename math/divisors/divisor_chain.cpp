// 1300
// https://codeforces.com/problemset/problem/1864/C


// now, if we assume that x is a power of 2
// so to reduce to 1
// we can divide it by 2
// 16 ---> 8 ---> 4 ---> 2 ---> 1
//     -8     -4    -2      -1 

// if x is not a power of 2
// we will try to make it a power of 2

// x = 37 
// 100101
// ==> 2^5 + 2^2 + 2^0
// ==> 2^0(2^5 + 2^2 + 2^0)
// hence 2^0 will be a factor of 37
// hence we will subtract it
// 2^5 + 2^2

// ==> 2^2(2^3 + 2^0)
// hence 2^2 will be a factor of 36
// hence we will subtract it

// 2^5
// (power of 2)

#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int num; cin >> num;
        int bit = 0;
        vector<int> st;
        while((num&(num-1))){
            if(num & (1 << bit)){
                st.push_back(num);
                num -= (1 << bit);
            }
            bit++;
        }
        while(num != 1){
            st.push_back(num);
            num /= 2;
        }
        st.push_back(1);
        
        cout << st.size() << endl;
        for(auto itr : st) cout << (itr) << " ";
        cout << endl;
    }
}