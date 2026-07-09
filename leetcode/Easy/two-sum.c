// Problem: Two Sum
// Platform: leetcode
// Rating/Difficulty: Easy
// Language: cpp
// URL: https://leetcode.com/problems/two-sum/
// Solved on: 2026-07-09T07:36:34.638Z

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numMap;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            numMap[nums[i]] = i;
        }
        for (int i = 0; i < n; i++) {
            int complement = target - nums[i];
            if (numMap.count(complement) && numMap[complement] != i) {
                return {i, numMap[complement]};
            }
        }

        return {}; 
    }
};