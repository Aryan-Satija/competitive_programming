// Turtle vs. Rabbit Race: Optimal Trainings

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

void solve(){
    //* Write code here
    ll n;
    cin >> n;
    vll arr(n+1);
    
    rep(i, 1, n) cin >> arr[i];

    vll prefix(n+1, 0);

    rep(i, 1, n) prefix[i] = prefix[i-1] + arr[i];

    int q;
    cin >> q;

    ll low, high, mid, sections, r, p_r, p_r_1;
    while(q--){
        ll l, u;
        cin >> l >> u;
        low = l, high = n, r = l;
        while(low <= high){
            mid = (low + high)/2;
            sections = prefix[mid] - prefix[l-1];
            if(sections <= u) {
                r = mid;
                low = mid+1;
            }
            else high = mid-1;
        }

        if(r == n){
            cout << n << " ";
            continue;
        }

        // r or r+1
        sections = prefix[r] - prefix[l-1];
        p_r = sections;
        sections = prefix[r+1] - prefix[l-1];
        p_r_1 = ((2*u) + 1 - sections);

        if(p_r >= p_r_1) cout << r << " ";
        else cout << r+1 << " ";
    }
    cout << endl;
}
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);   
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}