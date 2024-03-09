// FINDING THE INVERSION COUNT 

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

    void update(int i, int diff){
        while(i < arr.size()){
            arr[i] += diff;
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
        return (rangeSumUpto(high) - rangeSumUpto(low));
    }
};


class Solution{
  public:
    long long int inversionCount(long long arr[], long long N)
    {
        // this will store the frequency of the elements of arr
        // a[i] <= 1e5
        fenwickTree frequency(1e5);   
        long long inversions = 0;
        for(int i = 0; i < N; i++){
            frequency.update(arr[i], 1);
    
            inversions += frequency.rangeSum(arr[i], 1e5);
        }
        return inversions;
    }
};