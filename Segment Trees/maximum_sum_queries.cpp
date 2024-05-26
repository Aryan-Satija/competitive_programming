//LEETCODE
// HARD
// https://leetcode.com/problems/maximum-sum-queries/description/

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
#define rep(i, s, e) for (ll i = s; i <= e; i++)
#define ren(i, s, e) for (ll i = s; i >= e; i--)

class Solution {
public:
    vi segmentTree;

    int query_maximum(int low, int high, int left, int right, int idx) {
        if (left > high || right < low) return INT_MIN;
        if (left <= low && high <= right) return segmentTree[idx];
        int mid = (low + high) / 2;
        return max(query_maximum(low, mid, left, right, 2 * idx + 1), 
                   query_maximum(mid + 1, high, left, right, 2 * idx + 2));
    }

    void buildSegmentTree(vi &arr, int low, int high, int idx) {
        if (low == high) {
            segmentTree[idx] = arr[low];
        } else {
            int mid = (low + high) / 2;
            buildSegmentTree(arr, low, mid, 2 * idx + 1);
            buildSegmentTree(arr, mid + 1, high, 2 * idx + 2);
            segmentTree[idx] = max(segmentTree[2 * idx + 1], segmentTree[2 * idx + 2]);
        }
    }

    vi maximumSumQueries(vi &nums1, vi &nums2, vvi &queries) {
        // forming convex hull of the given points
        // answer always lies on the convex hull
        // lpp

        vector<pii> coor;
        int n = nums1.size();
        rep(i, 0, n - 1) coor.push_back({nums1[i], nums2[i]});

        sort(coor.begin(), coor.end());

        // using monotonic stack's concept to find all the points on the convex hull
        stack<pii> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty()) {
                int topx = st.top().first, topy = st.top().second;
                if (coor[i].first >= topx && coor[i].second >= topy) st.pop();
                else break;
            }
            st.push(coor[i]);
        }

        vector<pii> convex_hull_points;
        vi sum;

        while (!st.empty()) {
            auto t = st.top();
            cout << t.first << " " << t.second << endl;
            convex_hull_points.push_back(t);
            sum.push_back(t.first + t.second);
            st.pop();
        }

        reverse(convex_hull_points.begin(), convex_hull_points.end());
        reverse(sum.begin(), sum.end());

        int m = sum.size();
        segmentTree.resize(4 * m);
        buildSegmentTree(sum, 0, m - 1, 0);

        vi res;
        int q = queries.size();
        rep(i, 0, q - 1) {
            int x_min = queries[i][0], y_min = queries[i][1];
            int left = -1, right = -1;
            int low = 0, high = m - 1;

            // Finding the left boundary
            while (low <= high) {
                int mid = (low + high) / 2;
                if (convex_hull_points[mid].first >= x_min) {
                    left = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }

            if (left == -1) {
                res.push_back(-1);
                continue;
            }

            // Finding the right boundary
            low = 0, high = m - 1;
            while (low <= high) {
                int mid = (low + high) / 2;
                if (convex_hull_points[mid].second >= y_min) {
                    right = mid;
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }

            if (right == -1 || right < left) {
                res.push_back(-1);
                continue;
            }

            res.push_back(query_maximum(0, m - 1, left, right, 0));
        }

        return res;
    }
};
