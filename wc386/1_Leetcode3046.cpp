// Split the Array
// https://leetcode.com/problems/split-the-array/description/

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    // Time Complexity : O(n*logn)
    // Space Complexity : O(n/2 + n/2) = O(n)
    bool isPossibleToSplit(vector<int>& nums) {
        vector<int> num1,num2;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; i++) {
            if(i%2) num1.push_back(nums[i]); 
            else num2.push_back(nums[i]);
        }
        for(int i = 1; i < num1.size(); i++) {
            if(num1[i-1] == num1[i]) return false;
        }
        for(int i = 1; i < num2.size(); i++) {
            if(num2[i-1] == num2[i]) return false;
        }
        return true;
    }
    // Time : O(n)
    // Space : O(n)
    bool isPossibleToSplit(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;
        for(int i = 0; i < n; i++) {
            mp[nums[i]]++;
            if(mp[nums[i]] > 2) return false;
        }
        return true;
    }
};
int main()
{
    vector<int> arr={1,1,2,2,3,4};
    Solution s; // object declaration
    cout<<s.isPossibleToSplit(arr);
}


/*
You are given an integer array nums of even length. You have to split the array into two parts nums1 and nums2 such that:
nums1.length == nums2.length == nums.length / 2.
nums1 should contain distinct elements.
nums2 should also contain distinct elements.
Return true if it is possible to split the array, and false otherwise.

Example 1:
Input: nums = [1,1,2,2,3,4]
Output: true
Explanation: One of the possible ways to split nums is nums1 = [1,2,3] and nums2 = [1,2,4].

Example 2:
Input: nums = [1,1,1,1]
Output: false
Explanation: The only possible way to split nums is nums1 = [1,1] and nums2 = [1,1]. Both nums1 and nums2 do not contain distinct elements.

Constraints:
1 <= nums.length <= 100
nums.length % 2 == 0
1 <= nums[i] <= 100
*/