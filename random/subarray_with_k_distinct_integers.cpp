// LEETCODE
// HARD
// subarrays with exactly k distinct integers are equal to number of subarrays with atleast k distinct integers - number of subarrays with atleast k+1 distinct integers

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int f(vector<int> nums, int k){
        unordered_map<int, int> f;
        int low = 0, high = 0, cnt = 0, res = 0, n = nums.size();
        while(high <= n){
            if(cnt == k){
                res += (n - high + 1);
                f[nums[low]]--;
                if(f[nums[low]] == 0) cnt--;
                low++;
            }
            else if(high != n){
                if(f[nums[high]] == 0)
                    cnt++;
                f[nums[high++]]++;
            }
            else break;
        }
        return res;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return f(nums, k) - f(nums, k+1);
    }
};