class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n = arr.size();
        int zeros = 0;

        // Count zeros that can be duplicated
        for (int i = 0; i < n - zeros; i++) {
            if (arr[i] == 0) {
                if (i == n - zeros - 1) {
                    // Zero is at the boundary
                    arr[n - 1] = 0;
                    n--;
                    break;
                }
                zeros++;
            }
        }

        int i = n - zeros - 1;
        int j = n - 1;

        // Fill from right to left
        while (i >= 0 && j >= 0) {
            arr[j] = arr[i];
            j--;

            if (arr[i] == 0 && j >= 0) {
                arr[j] = 0;
                j--;
            }

            i--;
        }
    }
};