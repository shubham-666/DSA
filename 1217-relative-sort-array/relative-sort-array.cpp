class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> freq;

        // Count frequency of arr1 elements
        for (int x : arr1) {
            freq[x]++;
        }

        vector<int> ans;

        // Add elements according to arr2 order
        for (int x : arr2) {
            while (freq[x] > 0) {
                ans.push_back(x);
                freq[x]--;
            }
        }

        // Collect remaining elements
        vector<int> remaining;

        for (auto& [x, count] : freq) {
            while (count-- > 0) {
                remaining.push_back(x);
            }
        }

        // Sort remaining elements
        sort(remaining.begin(), remaining.end());

        // Append remaining elements
        ans.insert(ans.end(), remaining.begin(), remaining.end());

        return ans;
    }
};