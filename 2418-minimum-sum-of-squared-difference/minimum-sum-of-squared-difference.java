class Solution {
    public long minSumSquareDiff(int[] nums1, int[] nums2, int k1, int k2) {
        long operations = (long) k1 + k2;
        int n = nums1.length;
        int[] diff = new int[n];

        long total = 0;
        int max = 0;

        for (int i = 0; i < n; i++) {
            diff[i] = Math.abs(nums1[i] - nums2[i]);
            total += diff[i];
            max = Math.max(max, diff[i]);
        }

        // No difference remains possible to reduce
        if (operations >= total) {
            return 0;
        }

        int low = 0, high = max;

        // Find the minimum maximum difference achievable
        while (low < high) {
            int mid = low + (high - low) / 2;
            long needed = 0;

            for (int d : diff) {
                if (d > mid) {
                    needed += d - mid;
                }
            }

            if (needed <= operations) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        int limit = low;
        long remaining = operations;
        long ans = 0;

        // Reduce all differences greater than limit
        for (int d : diff) {
            if (d > limit) {
                remaining -= d - limit;
                d = limit;
            }
            ans += (long) d * d;
        }

        // Distribute leftover operations one level at a time
        // among differences equal to limit.
        for (int d : diff) {
            if (remaining == 0) break;

            if (d >= limit && limit > 0) {
                ans -= (long) limit * limit;
                ans += (long) (limit - 1) * (limit - 1);
                remaining--;
            }
        }

        return ans;
    }
}