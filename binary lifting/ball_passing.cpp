// LEETCODE
// HARD 
// Maximize Value of Function in a Ball Passing Game

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long getMaxFunctionValue(vector<int>& receiver, long long k) {
        int n = receiver.size();
        int K = log2(k) + 1;
        vector<vector<int>> dest(K, vector<int>(n, 0));
        vector<vector<long long>> cost(K, vector<long long>(n, 0));
        for(int i = 0; i < n; i++){
            dest[0][i] = receiver[i];
            cost[0][i] = receiver[i];
        }

        // dest[i][j] represents what would be the destination node from j after 2^i moves
        
        for(int i = 1; i < K; i++){
            for(int j = 0; j < n; j++){
                // binary lifting
                int mid = dest[i-1][j];
                dest[i][j] = dest[i-1][mid];
                cost[i][j] = cost[i-1][j] + cost[i-1][mid];
            }
        }

        long long res = 0;
        
        for(int i = 0; i < n; i++){
            // making every node as the source node
            int source = i;
            long long power = 0;
            long long tmp = k;
            long long curr = i;
            while(tmp != 0){
                if(tmp&1){
                    curr += cost[power][source];
                    source = dest[power][source];
                }
                tmp /= 2;
                power += 1;
            }
            cout << i << " " << curr << endl;
            res = max(res, curr);
        }
        return res;
    }
};