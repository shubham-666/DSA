class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> frequency;
        vector<int> result;

        // Count elements in nums1
        for (int number : nums1) {
            frequency[number]++;
        }

        // Find common elements
        for (int number : nums2) {
            if (frequency[number] > 0) {
                result.push_back(number);
                frequency[number]--;
            }
        }

        return result;
    }
};