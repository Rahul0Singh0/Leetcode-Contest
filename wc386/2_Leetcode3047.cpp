// Find the Largest Area of Square Inside Two Rectangles
// https://leetcode.com/problems/find-the-largest-area-of-square-inside-two-rectangles/description/
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
/*
There exist n rectangles in a 2D plane. You are given two 0-indexed 2D integer arrays bottomLeft and topRight, both of size n x 2, where bottomLeft[i] and topRight[i] represent the bottom-left and top-right coordinates of the ith rectangle respectively.
You can select a region formed from the intersection of two of the given rectangles. You need to find the largest area of a square that can fit inside this region if you select the region optimally.
Return the largest possible area of a square, or 0 if there do not exist any intersecting regions between the rectangles.

Input: bottomLeft = [[1,1],[2,2],[3,1]], topRight = [[3,3],[4,4],[6,6]]
Output: 1
Explanation: A square with side length 1 can fit inside either the intersecting region of rectangle 0 and rectangle 1, or the intersecting region of rectangle 1 and rectangle 2. Hence the largest area is side * side which is 1 * 1 == 1.
It can be shown that a square with a greater side length can not fit inside any intersecting region.
*/