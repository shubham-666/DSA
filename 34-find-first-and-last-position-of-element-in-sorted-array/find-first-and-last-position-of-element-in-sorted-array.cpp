class Solution {
public:
    int findFirst(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        int ans = -1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (nums[mid] >= target) {
                if (nums[mid] == target)
                    ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return ans;
    }

    int findLast(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        int ans = -1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (nums[mid] <= target) {
                if (nums[mid] == target)
                    ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int first = findFirst(nums, target);

        if (first == -1)
            return {-1, -1};

        int last = findLast(nums, target);

        return {first, last};
    }
};