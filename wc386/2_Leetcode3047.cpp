#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    static long long isect(pair<int,int> &a, pair<int,int> &b) {
        int d = max(a.first, b.first);
        int d1 = min(a.second, b.second);
        if(d1 < d) {
            return 0;
        }
        else {
            return d1-d;
        }
    }
    long long largestSquareArea(vector<vector<int>>& a, vector<vector<int>>& b) {
        int n = a.size();
        long long ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i != j) {
                    pair<int,int> d1 = {a[i][0],b[i][0]};
                    pair<int,int> d2 = {a[i][1],b[i][1]};
                    pair<int,int> d3 = {a[j][0],b[j][0]};
                    pair<int,int> d4 = {a[j][1],b[j][1]};
                    long long diff = isect(d1, d3);
                    diff = min(diff, isect(d2,d4));
                    ans  = max(ans, diff*diff);
                }
            }
        }
        return ans;
    }
};
int main() {
    vector<vector<int>> bottomLeft={{1,1},{2,2},{3,1}};
    vector<vector<int>> topRight={{3,3},{4,4},{6,6}};
    Solution s;
    cout<<s.largestSquareArea(bottomLeft,topRight);

}