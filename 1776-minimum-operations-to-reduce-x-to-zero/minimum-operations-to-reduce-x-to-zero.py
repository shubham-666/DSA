class Solution:
    def minOperations(self, nums: list[int], x: int) -> int:
        n = len(nums)
        target = sum(nums) - x

        if target < 0:
            return -1

        if target == 0:
            return n

        left = 0
        cur = 0
        best = -1

        for right in range(n):
            cur += nums[right]

            while cur > target:
                cur -= nums[left]
                left += 1

            if cur == target:
                best = max(best, right - left + 1)

        if best == -1:
            return -1

        return n - best