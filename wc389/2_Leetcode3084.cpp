// 3084. Count Substrings Starting and Ending with Given Character
// https://leetcode.com/contest/weekly-contest-389/problems/count-substrings-starting-and-ending-with-given-character/
#include<iostream>
#include<string>
using namespace std;
class Solution {
public:
    long long countSubstrings(string s, char c) {
        long long cnt = 0;
        long long k = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == c) {
                k++;
                cnt+=k;
            }
        }
        return cnt;
    }
};
int main() {
    string s = "abada";
    char c = 'a';
    Solution st;
    cout<<st.countSubstrings(s,c);
}