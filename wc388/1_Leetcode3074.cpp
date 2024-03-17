// 3074. Apple Redistribution into Boxes
// https://leetcode.com/contest/weekly-contest-388/problems/apple-redistribution-into-boxes/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int n = apple.size();    
        int totalApple = 0;
        for(int i = 0; i < n; i++) totalApple += apple[i];
        sort(capacity.begin(), capacity.end());
        int m = capacity.size();
        int sum = capacity[m-1];
        int cnt = 1;
        for(int i = m-2; i >= 0; i--) {
            if(sum >= totalApple) break;
            cnt++;
            sum += capacity[i];
        }
        return cnt;
    }
};
int main() {
    Solution s;
    vector<int> apple ={1,3,2};
    vector<int> capacity = {4,3,1,5,2};
    cout<<s.minimumBoxes(apple,capacity);
}