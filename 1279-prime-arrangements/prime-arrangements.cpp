class Solution {
public:
    int numPrimeArrangements(int n) {
        const long long MOD = 1e9 + 7;

        // Count primes from 1 to n
        int k = 0;

        for (int i = 2; i <= n; i++) {
            bool prime = true;

            for (int j = 2; j * j <= i; j++) {
                if (i % j == 0) {
                    prime = false;
                    break;
                }
            }

            if (prime) k++;
        }

        // k! * (n-k)!
        long long ans = 1;

        for (int i = 1; i <= k; i++) {
            ans = (ans * i) % MOD;
        }

        for (int i = 1; i <= n - k; i++) {
            ans = (ans * i) % MOD;
        }

        return ans;
    }
};