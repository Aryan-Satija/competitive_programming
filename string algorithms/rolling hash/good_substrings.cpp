// 1800
// CODEFORCES

#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vvll vector<vector<long long int>>
#define vc vector<char>
#define vll vector<long long>
#define mii map<int, int>
#define umii unordered_map<int, int>
#define si set<int>
#define rep(i, st, end) for(ll i = st; i < end; i++)
#define ren(i, st, end) for(ll i = (end-1); i >= st; i--)

const int prime1 = 31;
const int prime2 = 27;

#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vvll vector<vector<long long int>>
#define vc vector<char>
#define vll vector<long long>
#define mii map<int, int>
#define umii unordered_map<int, int>
#define si set<int>
#define rep(i, st, end) for(ll i = st; i < end; i++)
#define ren(i, st, end) for(ll i = (end-1); i >= st; i--)

const int prime1 = 31;
const int prime2 = 29;

int main(){
    int k;
    string str, isbad;
    cin >> str >> isbad >> k;
    set<pair<int, int>> hash;
    rep(i, 0, str.size()){
        ll hash1 = 0LL, hash2 = 0LL;
        int badCount = 0;
        rep(j, i, str.size()){
            badCount = (isbad[int(str[j] - 'a')] == '0' ? badCount + 1 : badCount);
            if(badCount > k) break;
            hash1 = (hash1*prime1)%MOD;
            hash2 = (hash2*prime2)%MOD;
            hash1 = (hash1 + int(str[j] -'a') + 1)%MOD;
            hash2 = (hash2 + int(str[j] -'a') + 1)%MOD;
            hash.insert({hash1, hash2});
        }
    }
    cout << (hash.size()) << endl;
}