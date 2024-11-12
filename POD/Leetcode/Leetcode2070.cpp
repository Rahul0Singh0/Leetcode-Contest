#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    // Bruteforce : Time : O(n*q)
    vector<int> maximumBeauty1(vector<vector<int>>& items, vector<int>& queries) {
        vector<int> ans;
        for(int i = 0; i < queries.size(); i++) {
            int mx = 0;
            for(int j = 0; j < items.size(); j++) {
                if(queries[i] >= items[j][0]) {
                    mx = max(mx, items[j][1]);
                }
            }
            ans.push_back(mx);
        }
        return ans;
    }
    int bin_search(vector<vector<int>> &items, int qu) {
        int mx = 0;
        int lo = 0, hi = items.size()-1;
        while(lo <= hi) {
            int mid = lo + (hi-lo)/2;
            vector<int> t = items[mid];
            if(t[0] <= qu) {
                mx = max(mx, t[1]);
                lo = mid+1;
            } else {
                hi = mid-1;
            }
        }
        return mx;
    }
    // Time : O(q*log(n) + n*log(n))
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& qu) {
        // sorting based on price
        int qn = qu.size(), n = items.size();
        sort(items.begin(), items.end());
        int mx = items[0][1]; // first beauty
        // precompute max beauty from curr to all prev items
        for(int i = 0; i < n; i++) {
            items[i][1] = max(mx, items[i][1]);
            mx = items[i][1];
        }

        vector<int> ans;
        for(int i = 0; i < qn; i++) {
            ans.push_back(bin_search(items, qu[i]));            
        }

        return ans;
    }
};