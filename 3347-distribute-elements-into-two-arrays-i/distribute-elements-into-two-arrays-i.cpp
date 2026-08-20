class Solution {
public:
    std::vector<int> resultArray(std::vector<int>& nums) {
        std::vector<int> arr1;
        std::vector<int> arr2;

        if (nums.size() < 2) {
            // If there are less than 2 elements, we cannot follow the rules
            return {};
        }

        // Append first element to arr1 and second element to arr2
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);

        // Iterate through the rest of the elements
        for (size_t i = 2; i < nums.size(); i++) {
            if (arr1.back() > arr2.back()) {
                arr1.push_back(nums[i]);
            } else {
                arr2.push_back(nums[i]);
            }
        }

        // Concatenate arr1 and arr2
        arr1.insert(arr1.end(), arr2.begin(), arr2.end());
        return arr1;
    }
};