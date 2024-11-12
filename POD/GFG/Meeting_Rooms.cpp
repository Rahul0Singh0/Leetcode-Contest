// https://www.geeksforgeeks.org/problems/attend-all-meetings/1
#include <bits/stdc++.h>
using namespace std;
// Greedy + sorting
class Solution {
  public:
    // sort based on starting time
    static bool cmp(vector<int> a, vector<int> b) {
        return a[0] < b[0];
    }
    bool canAttend(vector<vector<int>> &arr) {
        sort(arr.begin(), arr.end(), cmp);
        // Your Code Here
        for(int i = 1; i < arr.size(); i++) {
            if(arr[i][0] < arr[i-1][1]) {
                return false;
            }
        }
        return true;
    }
};