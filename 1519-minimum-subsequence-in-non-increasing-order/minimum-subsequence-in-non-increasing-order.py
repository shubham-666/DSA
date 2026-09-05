class Solution:
    def minSubsequence(self, nums: List[int]) -> List[int]:
        nums.sort(reverse=True)

        total = sum(nums)
        cur = 0
        ans = []

        for x in nums:
            cur += x
            ans.append(x)

            if cur > total - cur:
                break

        return ans