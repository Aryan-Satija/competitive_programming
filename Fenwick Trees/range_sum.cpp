// LEETCODE
// Range Sum Query - Mutable

#include <bits/stdc++.h>
using namespace std;

class fenwickTree{
public:
    vector<int> arr;
    fenwickTree(int n){
        arr.resize(n+1, 0);
    }

    int lowestSetBit(int x){
        // brian keringham theorem to unset the rightmost set bit
        int y = (x&(x-1));
        return (x^y);
    }

    void update(int i, int val, int prev_val){
        i += 1;
        while(i < arr.size()){
            arr[i] += (val - prev_val);
            i += lowestSetBit(i);
        }
    }

    int rangeSumUpto(int idx){
        int sum = 0;
        while(idx >= 1){
            sum += arr[idx];
            idx = (idx&(idx-1));
        }
        return sum;
    }

    int rangeSum(int low, int high){
        return (rangeSumUpto(high+1) - rangeSumUpto(low));
    }
};
class NumArray {
public:
    fenwickTree fkTree;
    NumArray(vector<int>& nums) : fkTree(nums.size()) {
        for(int i = 0; i < nums.size(); i++){
            fkTree.update(i, nums[i], 0);
        }    
    }
    
    void update(int index, int val) {
        int prevVal = fkTree.rangeSum(index, index);
        fkTree.update(index, val, prevVal);
    }
    
    int sumRange(int left, int right) {
        return fkTree.rangeSum(left, right);
    }
};
