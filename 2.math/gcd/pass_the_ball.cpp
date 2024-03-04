// https://codeforces.com/gym/348180/problem/D
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

// ----------------------------------------------------------------------------------------------------------------------

    // first of all, the ball will reach back 1 after at most n moves
    // proof:
    // let us say, 1 passes the ball to x, then x passes it to y and so on.

    // notice, ball can't reach x not untill it reaches back 1...
    // similarly, ball can't reach y before it reaches x ...

    // and so on.

    // since there are only n unique persons in the circle..... therefore the ball will reach back to 1 after at most n passes

// ----------------------------------------------------------------------------------------------------------------------


    // let us say for simplicity,
    // the numbering was 0, 1, 2, 3, ... (n - 1)
    // hence, for some k, the ball can be at any position (m*k)%n
    // all the positions will be divisible by gcd(k, n) (let us say, g)

    // as (m*k)%n = m*k - x*n = m*n1*g - x*n2*g = (m*n1 - x*n2)*g

// ---------------------------------------------------------------------------------------------------------------------


int solve(){
    //* Write code here
    int n; cin >> n;
    set<ll> st;

    st.insert(1); // for k = n
    st.insert((n*(n+1))/2); // for k = 1


    // TC : O((sqrt(n) * (logn + logn) ))
    for(ll i = 2; i*i <= n; i++){
        if((n%i) == 0){

            ll  fac1 = i, fac2 = n/i;
            ll g = __gcd(n, fac1);
            ll cnt = n/g; // number of people that touched it
            ll fun = (cnt*( (cnt - 1)*g ))/2; // 0 + g + 2*g + ... (cnt-1)*g
            fun += cnt; // one based indexing // (1 + 0) + (1 + g) + (1 + 2*g) + ....

            st.insert(fun);

            g = __gcd(n, fac2);
            cnt = n/g; 
            fun = (cnt*( (cnt - 1)*g ))/2; 
            fun += cnt; 

            st.insert(fun);
        }
    }

    for(auto itr : st) cout << itr << " " ;
    cout << endl;
}
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);   
    cout.tie(NULL);
    int t;
    t = 1;
    while(t--){
        solve(); 
    }
} 