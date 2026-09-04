class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        

        int n = nums.size();
        vector<long long> suf(n);

        suf[n - 1] = nums[n - 1];

        for (int i = n - 2; i >= 0; i--)
            suf[i] = min(suf[i + 1], (long long)nums[i]);

        long long mx = 0;

        for (int i = 0; i < n; i++) {
            mx = max(mx, (long long)nums[i]);

            if (mx - suf[i] <= k)
                return i;
        }

        return -1;
    }
};