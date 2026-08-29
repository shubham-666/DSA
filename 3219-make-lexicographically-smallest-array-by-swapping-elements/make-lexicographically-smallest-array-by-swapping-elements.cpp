class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();

        vector<pair<int, int>> values;
        for (int i = 0; i < n; i++) {
            values.push_back({nums[i], i});
        }

        sort(values.begin(), values.end());

        vector<int> answer = nums;
        int start = 0;

        while (start < n) {
            int end = start;

            while (end + 1 < n &&
                   (long long)values[end + 1].first - values[end].first <= limit) {
                end++;
            }

            vector<int> indices;
            vector<int> sortedValues;

            for (int i = start; i <= end; i++) {
                sortedValues.push_back(values[i].first);
                indices.push_back(values[i].second);
            }

            sort(indices.begin(), indices.end());

            for (int i = 0; i < indices.size(); i++) {
                answer[indices[i]] = sortedValues[i];
            }

            start = end + 1;
        }

        return answer;
    }
};