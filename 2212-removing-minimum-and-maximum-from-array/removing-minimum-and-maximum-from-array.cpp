class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int mn = 0, mx = 0;

        // Find indices of minimum and maximum
        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[mn])
                mn = i;

            if (nums[i] > nums[mx])
                mx = i;
        }

        // Make mn the smaller index and mx the larger index
        if (mn > mx)
            swap(mn, mx);

        // 1. Remove both from the front
        int fromFront = mx + 1;

        // 2. Remove both from the back
        int fromBack = n - mn;

        // 3. Remove min from front and max from back
        int mixed = (mn + 1) + (n - mx);

        return min({fromFront, fromBack, mixed});
    }
};