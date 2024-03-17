// 3075. Maximize Happiness of Selected Children
// https://leetcode.com/contest/weekly-contest-388/problems/maximize-happiness-of-selected-children/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long maximumHappinessSum(vector<int>& h, int k) {
        long long mx = 0;
        sort(h.begin(), h.end(), greater<int>());
        int cnt = 0;
        for(int i = 0; i < k; i++) {
            if(h[i]-cnt > 0) {
                mx += h[i]-cnt;
                cnt++;
            }
        }
        return mx;
    }
};
int main() {
    vector<int> happiness = {1,2,3};
    int k = 2;
    Solution s;
    cout<<s.maximumHappinessSum(happiness, k);
}