class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int l = 0;
        int ans =0;

        for (int right =0; right< nums.size(); right++){
            freq[nums[right]]++;
            while(freq[nums[right]]> k) {
                freq[nums[l]]--;
                l++;
            }
            ans = max(ans, right -l +1);
        }
        return ans;
    }
};