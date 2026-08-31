class Solution:
    def isAlienSorted(self, words: List[str], order: str) -> bool:
        rank = {ch: i for i, ch in enumerate(order)}

        for i in range(len(words) - 1):
            w1 = words[i]
            w2 = words[i + 1]

            j = 0

            while j < len(w1) and j < len(w2):
                if w1[j] != w2[j]:
                    if rank[w1[j]] > rank[w2[j]]:
                        return False
                    break

                j += 1

            # Same prefix, but first word is longer
            if j == len(w2) and len(w1) > len(w2):
                return False

        return True