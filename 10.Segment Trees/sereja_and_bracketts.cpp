// Sereja and brackets
// 2000
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

vvi st;

void buildSegmentTree(int low, int high, string &str, int idx){
    
    if(low == high){
        if(str[low] == '(')
            st[idx] = {0, 1, 0};
        else
            st[idx] = {0, 0, 1};
        return;
    }
    
    
    int mid = (low + high)/2;
    buildSegmentTree(low, mid, str, 2*idx + 1);
    buildSegmentTree(mid + 1, high, str, 2*idx + 2);
    
    st[idx] = {
                st[2*idx + 1][0] + st[2*idx + 2][0] + 2*min(st[2*idx + 1][1] -  (st[2*idx + 1][0]/2), st[2*idx + 2][2] - (st[2*idx + 2][0]/2)),
                st[2*idx + 1][1] + st[2*idx + 2][1],
                st[2*idx + 1][2] + st[2*idx + 2][2]
              };
}

vi query(int low, int high, int left, int right, int idx){
    if(right < low || high < left)
        return {0, 0, 0};
    if(left <= low && right >= high)
        return st[idx];

    int mid = (low + high)/2;
    vi l = query(low, mid, left, right, 2*idx + 1);
    vi r = query(mid + 1, high, left, right, 2*idx + 2);

    return {
        l[0] + r[0] + 2*min(l[1] -  (l[0]/2), r[2] - (r[0]/2)),
        l[1] + r[1],
        l[2] + r[2]
      };
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string str;
    cin >> str;
    st.resize(4*str.size());
    buildSegmentTree(0, str.size()-1, str, 0);
    int q;
    cin >> q;
    while(q--){
        int l, r;
        cin >> l >> r;
        l--, r--;

        cout << query(0, str.size() - 1, l, r, 0)[0] << endl;
    }
}
