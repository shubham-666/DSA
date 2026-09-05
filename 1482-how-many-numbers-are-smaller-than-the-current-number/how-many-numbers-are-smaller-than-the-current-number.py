class Solution:
    def smallerNumbersThanCurrent(self, nums: List[int]) -> List[int]:
        freq = [0] * 101

        for x in nums:
            freq[x] += 1

        for i in range(1, 101):
            freq[i] += freq[i - 1]

        ans = []

        for x in nums:
            ans.append(freq[x - 1] if x > 0 else 0)

        return ans