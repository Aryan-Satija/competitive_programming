#include <bits/stdc++.h>
using namespace std;

#define mod 100000000

#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vpii vector<pair<int, int>>
#define vb vector<bool>
#define vvi vector<vector<int>>
#define vvpii vector<vector<pair<int, int>>>
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

void solve()
{
    ll n;
    cin >> n;

    vvll twos(n, vll(n, 0));
    vvll fives(n, vll(n, 0));

    ll z_i = -1, z_j = -1;
    rep(i, 0, n - 1)
    {
        rep(j, 0, n - 1)
        {
            ll num;
            cin >> num;
            if(num == 0){
                z_i = i, z_j = j;
                twos[i][j] = 1, fives[i][j] = 1;
                continue; 
            }
            while ((num % 2) == 0)
                twos[i][j] += 1, num /= 2;
            while ((num % 5) == 0)
                fives[i][j] += 1, num /= 5;
        }
    }

    vvpii dp_2(n, vpii(n));
    vvpii dp_5(n, vpii(n));
    
    ren(i, n - 1, 0)
    {
        ren(j, n - 1, 0)
        {
            if (i == n - 1 and j == n - 1)
            {
                dp_2[i][j] = {twos[i][j], fives[i][j]};
                dp_5[i][j] = {twos[i][j], fives[i][j]};
                continue;
            }
            if (i == n - 1)
            {
                dp_2[i][j].first = twos[i][j] + dp_2[i][j + 1].first;
                dp_2[i][j].second = fives[i][j] + dp_2[i][j + 1].second;
                dp_5[i][j].first = twos[i][j] + dp_5[i][j + 1].first;
                dp_5[i][j].second = fives[i][j] + dp_5[i][j + 1].second;
                continue;
            }
            if (j == n - 1)
            {
                dp_2[i][j].first = twos[i][j] + dp_2[i + 1][j].first;
                dp_2[i][j].second = fives[i][j] + dp_2[i + 1][j].second;
                dp_5[i][j].first = twos[i][j] + dp_5[i + 1][j].first;
                dp_5[i][j].second = fives[i][j] + dp_5[i + 1][j].second;
                continue;
            }

            ll r_2 = dp_2[i][j + 1].first, d_2 = dp_2[i + 1][j].first; 
            ll r_5 = dp_2[i][j + 1].second, d_5 = dp_2[i + 1][j].second;

            if (r_2 < d_2)
            {
                dp_2[i][j] = {
                    twos[i][j] + r_2,
                    fives[i][j] + r_5
                };
            }
            else if(r_2 == d_2)
            {
                dp_2[i][j] = {
                    twos[i][j] + r_2,
                    fives[i][j] + min(r_5, d_5)
                };
            }
            else{
                dp_2[i][j] = {
                    twos[i][j] + d_2,
                    fives[i][j] + d_5
                };
            }

            r_2 = dp_5[i][j + 1].first, d_2 = dp_5[i + 1][j].first; 
            r_5 = dp_5[i][j + 1].second, d_5 = dp_5[i + 1][j].second;

            if (r_5 < d_5)
            {
                dp_5[i][j] = {
                    twos[i][j] + r_2,
                    fives[i][j] + r_5
                };
            }
            else if(r_5 == d_5)
            {
                dp_5[i][j] = {
                    twos[i][j] + min(r_2, d_2),
                    fives[i][j] + r_5
                };
            }
            else{
                dp_5[i][j] = {
                    twos[i][j] + d_2,
                    fives[i][j] + d_5
                };
            }
        }
    }

    ll option1 = min(dp_2[0][0].first, dp_2[0][0].second), option2 = min(dp_5[0][0].first, dp_5[0][0].second);
    ll ans = min(option1, option2);
    if(z_i != -1){
        if(ans != 0){
            cout << 1 << "\n";

            string path = "";
            int i = 0, j = 0;
            while(i != z_i){
                i += 1;
                path += 'D';
            }
            while(j != z_j){
                j += 1;
                path += 'R';
            }
            while(i != n-1){
                i += 1;
                path += 'D';
            }
            while(j != n-1){
                j += 1;
                path += 'R';
            }
            cout << path << "\n";
            return;
        }
    }

    cout << min(option1, option2) << "\n";
    
    string path = "";
    if (option1 < option2)
    {
        int i = 0, j = 0;
        while (i != n - 1 or j != n - 1)
        {
            if (i == n - 1)
            {
                j += 1;
                path += 'R';
            }
            else if (j == n - 1)
            {
                i += 1;
                path += 'D';
            }
            else
            {
                if (dp_2[i + 1][j].first < dp_2[i][j + 1].first)
                {
                    i += 1;
                    path += 'D';
                }
                else if (dp_2[i + 1][j].first > dp_2[i][j + 1].first)
                {
                    j += 1;
                    path += 'R';
                }
                else
                {
                    if (dp_2[i + 1][j].second < dp_2[i][j + 1].second)
                    {
                        i += 1;
                        path += 'D';
                    }
                    else
                    {
                        j += 1;
                        path += 'R';
                    }
                }
            }
        }
    }
    else
    {
        int i = 0, j = 0;
        while (i != n - 1 or j != n - 1)
        {
            if (i == n - 1)
            {
                j += 1;
                path += 'R';
            }
            else if (j == n - 1)
            {
                i += 1;
                path += 'D';
            }
            else
            {
                if (dp_5[i + 1][j].second < dp_5[i][j + 1].second)
                {
                    i += 1;
                    path += 'D';
                }
                else if (dp_5[i + 1][j].second > dp_5[i][j + 1].second)
                {
                    j += 1;
                    path += 'R';
                }
                else
                {
                    if (dp_5[i + 1][j].first < dp_5[i][j + 1].first)
                    {
                        i += 1;
                        path += 'D';
                    }
                    else
                    {
                        j += 1;
                        path += 'R';
                    }
                }
            }
        }
    }
    cout << path << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}