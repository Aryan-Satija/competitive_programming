// https://codeforces.com/contest/1935/problem/C
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

// pls note
// let us assume the we have selected b1, b2, b4, and b5
// let us say b1 > b2 > b5 > b4

// then it would be most optimum to choose
// bi in increasing or decreasing order
// as,
// b1 - b2 + b2 - b5 + b5 - b4
// b1 - b4
// max(bi) - min(bi)

// ----------------------------------

// if the user can read x messages, then they can also read 1, 2, .... x-1 messages
// hence we can apply binary search

bool f(int m, int l, vector<pii> &a){
    int n = a.size();
    rep(i, 0, n-1){
        // we will find m messages starting from i
        // we will store messages with lesser a
        ll sum = 0;
        if(i + m - 1 >= n) break;
        priority_queue<int> pq;
        rep(j, i, i + m - 1){
            if(j != i){
                // we have fixed i, we will not remove it
                // hence not adding it in the priority queue
                pq.push(a[j].second);
            }
            sum += a[j].second;
        }
        sum += (a[i+m-1].first - a[i].first);
        if(sum <= l) return true;
        rep(j, i + m, n-1){
            // from i to j ∑b = bj - bi
            // which is fixed
            // so we will take those m messages which have least a
            sum += (a[j].first - a[j-1].first); 
            if(pq.size() > 0 and pq.top() > a[j].second){
                sum -= pq.top();
                pq.pop();
                pq.push(a[j].second);
                sum += a[j].second;
            }

            if(sum <= l) return true;
        }
    }
    return false;
}

int solve(){
    //* Write code here
    int n, l;
    cin >> n >> l;
    vector<pii> a(n);
    rep(i, 0, n-1){
        cin >> a[i].second >> a[i].first; // bcoz we will be sorting in increasing order of bi
    }

    sort(a.begin(), a.end());

    int low = 1, high = n;
    int res = 0;
    while(low <= high){
        int mid = (low + high)/2;
        // now we will check whether we can find a sequence of mid messages which the user can read in less than l time
        
        if(f(mid, l, a)){
            res = mid;
            low = mid + 1;
        }
        else high = mid-1;
        // cout << low << "------" << high << endl;
    }
    cout << res << endl;
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