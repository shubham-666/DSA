#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        int n = (int)nums.size();
        vector<long long> result(k, 0);          // final answer
        vector<long long> dp(k, 0), ndp(k, 0);   // dp for subarrays ending at previous / current index

        for (int j = 0; j < n; ++j) {
            fill(ndp.begin(), ndp.end(), 0);
            int val = nums[j] % k;               // remainder of the single element

            // subarray consisting only of nums[j]
            ndp[val] += 1;

            // extend all previous subarrays
            for (int r = 0; r < k; ++r) {
                if (dp[r] != 0) {
                    int nr = (r * val) % k;
                    ndp[nr] += dp[r];
                }
            }

            dp.swap(ndp);                         // now dp holds counts for subarrays ending at j

            // add these subarrays to the global answer
            for (int r = 0; r < k; ++r) {
                result[r] += dp[r];
            }
        }
        return result;
    }
};