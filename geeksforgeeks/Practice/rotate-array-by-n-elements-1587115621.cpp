// Problem: Rotate Array
// Platform: geeksforgeeks
// Language: unknown
// Verdict: Accepted
// URL: https://www.geeksforgeeks.org/problems/rotate-array-by-n-elements-1587115621/1?page=1&sortBy=submissions
// Solved on: 2026-07-28T08:03:26.317Z

class Solution {
public:
    void rotateArr(vector<int>& arr, int d) {
        int n = arr.size();

        d %= n;

        reverse(arr.begin(), arr.begin() + d);
        reverse(arr.begin() + d, arr.end());
        reverse(arr.begin(), arr.end());
    }
};