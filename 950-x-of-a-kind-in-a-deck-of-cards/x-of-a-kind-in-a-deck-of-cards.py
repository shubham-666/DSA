from math import gcd

class Solution:
    def hasGroupsSizeX(self, deck: List[int]) -> bool:
        count = {}

        for num in deck:
            count[num] = count.get(num, 0) + 1

        g = 0

        for freq in count.values():
            g = gcd(g, freq)

        return g >= 2