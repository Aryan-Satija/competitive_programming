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
#define rep(i, s, e) for (ll i = s; i <= e; i++)
#define ren(i, s, e) for (ll i = s; i >= e; i--)

void solve(){
    //* write your code here
    ll n, q;
    cin >> n >> q;
    vll a(n);
    rep(i, 0, n-1) cin >> a[i];
    
    vll k(q);
    rep(i, 0, q-1) cin >> k[i];
    
    
    vll ans;
    
    ans.push_back(a[0]);
    
    if(n > 1){
        priority_queue<ll> pq_min;
        priority_queue<ll, vector<ll>, greater<ll>> pq_max;
    
        ll diff = 0, sum = 0;
        
        vll help = {a[0], a[1], a[2]};
        
        sort(help.begin(), help.end());
        
        sum = help[1] + help[2];
        diff = help[0];
        
        pq_min.push(help[0]);
        pq_max.push(help[1]);
        pq_max.push(help[2]);
        
        ans.push_back(-1);
        ans.push_back(sum - diff);
        
        rep(i, 4, n-1){
            ll n1 = a[i], n2 = a[i-1];
            
            if(n1 >= pq_max.top() and n2 >= pq_max.top()){
                ll top = pq_max.top();
                pq_max.pop();
                pq_min.push(top);
                pq_max.push(n1);
                pq_max.push(n2);
                sum = sum - top + n1 + n2;
                diff = diff + top;
            }
            else if(n1 >= pq_max.top() or n2 >= pq_max.top()){
                pq_max.push(max(n1, n2));
                pq_min.push(min(n1, n2));
                
                sum = sum + max(n1, n2);
                diff = diff + min(n1, n2);
            }
            else{
                ll top = pq_min.top();
                if(top > n1 and top > n2){
                    pq_min.pop();
                    pq_min.push(n1);
                    pq_min.push(n2);
                    pq_max.push(top);
                    sum += top;
                    diff = diff - top + n1 + n2;
                }
                else{
                    pq_max.push(max(n1, n2));
                    pq_min.push(min(n1, n2));
                    
                    sum = sum + max(n1, n2);
                    diff = diff + min(n1, n2);
                }
            }
            ans.push_back(-1);
            ans.push_back(sum - diff);
            i++;
        }
    }
    
    rep(i, 0, q-1){
        ll ki = k[i];
        cout << ans[ki - 1] << " ";
    }
    
    cout << endl;
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}