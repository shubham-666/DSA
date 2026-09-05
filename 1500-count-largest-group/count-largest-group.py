class Solution:
    def countLargestGroup(self, n: int) -> int:
        freq = [0] * 37

        for x in range(1, n + 1):
            s = 0
            num = x

            while num:
                s += num % 10
                num //= 10

            freq[s] += 1

        mx = max(freq)
        return freq.count(mx)