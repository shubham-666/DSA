class Solution:
    def maxPower(self, s: str) -> int:
        max_len = 1
        curr = 1

        for i in range(1, len(s)):
            if s[i] == s[i - 1]:
                curr += 1
            else:
                curr = 1

            max_len = max(max_len, curr)

        return max_len