class Solution:
    def findTheDistanceValue(self, arr1: List[int], arr2: List[int], d: int) -> int:
        ans = 0

        for x in arr1:
            valid = True

            for y in arr2:
                if abs(x - y) <= d:
                    valid = False
                    break

            if valid:
                ans += 1

        return ans