class Solution:
    def maxScore(self, s: str) -> int:
        right_one = s.count('1')
        left_zero = 0
        ans = 0

        for i in range(len(s) - 1):
            if s[i] == '0':
                left_zero += 1
            else:
                right_one -= 1

            ans = max(ans, left_zero + right_one)

        return ans