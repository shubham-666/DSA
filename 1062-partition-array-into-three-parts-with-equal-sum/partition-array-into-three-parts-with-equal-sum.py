class Solution:
    def canThreePartsEqualSum(self, arr: List[int]) -> bool:
        total = sum(arr)

        if total % 3 != 0:
            return False

        target = total // 3
        curr = 0
        parts = 0

        for i in range(len(arr) - 1):
            curr += arr[i]

            if curr == target:
                parts += 1
                curr = 0

                if parts == 2:
                    return True

        return False