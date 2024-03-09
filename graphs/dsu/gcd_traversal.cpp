// Greatest Common Divisor Traversal
// LEETCODE
// HARD

#include <bits/stdc++.h>
using namespace std;

class disjointSet{
private:
    vector<int> rank, parent;
public:
    disjointSet(int v){
        rank.resize(v, 0); 
        parent.resize(v);
        for(int i = 0; i < v; i++)
            parent[i] = i;
    }
    int UltimateParent(int n){
        if(parent[n] == n)
            return n;
        // path compression
        return parent[n] = UltimateParent(parent[n]);
    }
    void Union(int u, int v){
        int up_u = UltimateParent(u); 
        int up_v = UltimateParent(v);
        if(up_u == up_v)
            return;
        if(rank[up_u] < rank[up_v])
            parent[up_u] = up_v;
        else if(rank[up_v] < rank[up_u])
            parent[up_v] = up_u;
        else{
            parent[up_u] = up_v;
            rank[up_v]++;
        }
    }
    int componentCount(vector<int> &arr){
        set<int> st;
        for(auto &num : arr)
            st.insert(UltimateParent(num));
        return st.size();
    }
};
class Solution {
public:
    int maxN = 1;
    
    vector<bool> sieve;
    unordered_map<int, bool> present;

    void calculateSieve(disjointSet &dsu){
        sieve.resize(maxN+1, true); 
        // O(nlog(logn))
        for(int i = 2; i <= maxN; i++){
            if(sieve[i]){
                for(int j = 2*i; j <= maxN; j += i){
                    sieve[j] = false;
                    if(present[j]){
                        dsu.Union(i, j);
                    }
                }
            }
        }
    }

    bool canTraverseAllPairs(vector<int>& nums) {
        if(nums.size() == 1) return true;
        for(auto &num : nums)
        { 
            present[num] = true;
            maxN = max(maxN, num);
        }
        if(present[1]) return false;
        disjointSet dsu(maxN+1); 
        calculateSieve(dsu);
        return (dsu.componentCount(nums) == 1);
    }
};