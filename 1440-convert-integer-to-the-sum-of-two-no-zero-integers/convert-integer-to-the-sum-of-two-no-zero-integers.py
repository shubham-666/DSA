class Solution:
    def getNoZeroIntegers(self, n: int) -> List[int]:
        def valid(x):
            return '0' not in str(x)

        for a in range(1, n):
            b = n - a
            if valid(a) and valid(b):
                return [a, b]

        return []