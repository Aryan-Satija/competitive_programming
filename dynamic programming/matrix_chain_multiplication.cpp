// Matrix Chain Multiplication
// Geeks For Geeks
// Hard
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    long long f(int low, int high, vector<int> &arr, vector<vector<int>> &dp){
        if(high == low + 1) return 0;
        if(dp[low][high] != -1) return dp[low][high];
        long long res = 1e12;
        for(int i = low + 1; i < high; i++){
            long long op1 = f(low, i, arr, dp), op2 = f(i, high, arr, dp);
            res = min(res, op1 + op2 + arr[low]*arr[i]*arr[high]);
        }
        return dp[low][high] = res;
    }
    int matrixMultiplication(int n, int arr[])
    {
        vector<int> mat(n);
        for(int i = 0; i < n; i++) mat[i] = arr[i];
        
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return f(0, n-1, mat, dp);
    }
};