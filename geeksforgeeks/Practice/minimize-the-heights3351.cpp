// Problem: Minimize the Heights II
// Platform: geeksforgeeks
// Language: unknown
// Verdict: Accepted
// URL: https://www.geeksforgeeks.org/problems/minimize-the-heights3351/1?page=1&sortBy=submissions
// Solved on: 2026-07-28T08:00:53.911Z

class Solution {
public:
    int getMinDiff(vector<int> &arr, int k) {
        int n = arr.size();
        sort(arr.begin(), arr.end());

        int ans = arr[n - 1] - arr[0];

        for (int i = 1; i < n; i++) {
            if (arr[i] - k < 0)
                continue;

            int mn = min(arr[0] + k, arr[i] - k);
            int mx = max(arr[n - 1] - k, arr[i - 1] + k);

            ans = min(ans, mx - mn);
        }

        return ans;
    }
};