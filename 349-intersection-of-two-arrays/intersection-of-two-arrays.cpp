class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> seen;
        unordered_set<int> resultSet;

        for (int number : nums1) {
            seen.insert(number);
        }

        for (int number : nums2) {
            if (seen.count(number)) {
                resultSet.insert(number);
            }
        }

        return vector<int>(resultSet.begin(), resultSet.end());
    }
};