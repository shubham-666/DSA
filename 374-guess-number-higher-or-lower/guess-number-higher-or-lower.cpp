class Solution {
public:
    int guessNumber(int n) {
        long long left = 1;
        long long right = n;

        while (left <= right) {
            long long mid = left + (right - left) / 2;

            int result = guess(mid);

            if (result == 0) {
                return mid;
            }

            if (result == -1) {
                // mid is higher than the picked number
                right = mid - 1;
            } else {
                // mid is lower than the picked number
                left = mid + 1;
            }
        }

        return -1;
    }
};