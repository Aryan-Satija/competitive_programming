// HARD 
// LEETCODE
// Number of Submatrices That Sum to Target
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int r = matrix.size(), c = matrix[0].size();
        vector<vector<int>> prefix(r, vector<int>(c+1, 0));

        for(int i = 0; i < r; i++){
            for(int j = 1; j <= c; j++)
                prefix[i][j] = prefix[i][j-1] + matrix[i][j-1];
        }

        long long int sum = 0, res = 0; 
        
        for(int i = 0; i < c; i++){
            for(int j = i; j < c; j++){
                unordered_map<int, int> cnt;
                cnt[0]++;
                sum = 0;
                for(int k = 0; k < r; k++){
                    sum += (prefix[k][j+1] - prefix[k][i]);
                    res += (cnt[sum - target]);
                    cnt[sum]++;
                }
            }
        }

        return res;
    }
};