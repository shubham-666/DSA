class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();

        // If k == n, there is only one subarray
        if (k == n) {
            return *max_element(nums.begin(), nums.end());
        }

        // If k == 1, every occurrence is its own subarray,
        // so the number must appear exactly once in nums.
        if (k == 1) {
            unordered_map<int, int> freq;

            for (int x : nums) {
                freq[x]++;
            }

            int ans = -1;

            for (int x : nums) {
                if (freq[x] == 1) {
                    ans = max(ans, x);
                }
            }

            return ans;
        }

        // For 1 < k < n, only nums[0] and nums[n-1]
        // can appear in exactly one subarray of size k.
        int ans = -1;

        if (count(nums.begin(), nums.end(), nums[0]) == 1) {
            ans = max(ans, nums[0]);
        }

        if (count(nums.begin(), nums.end(), nums[n - 1]) == 1) {
            ans = max(ans, nums[n - 1]);
        }

        return ans;
    }
};