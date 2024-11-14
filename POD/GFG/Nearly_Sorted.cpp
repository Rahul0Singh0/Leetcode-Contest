// https://www.geeksforgeeks.org/problems/nearly-sorted-1587115620/1
#include <bits/stdc++.h>
using namespace std;
#define meanHeap priority_queue<int, vector<int>, greater<int>>
class Solution {
  public:
    void nearlySorted(vector<int>& arr, int k) {
        meanHeap pq;
        for(int i = 0; i <= k; i++) pq.push(arr[i]);
        int idx = 0;
        for(int i = k+1; i < arr.size(); i++) arr[idx++] = pq.top(), pq.pop(), pq.push(arr[i]);
        // rest of elements in heap
        while(not pq.empty()) {
            arr[idx++] = pq.top();
            pq.pop();
        }
    }
};