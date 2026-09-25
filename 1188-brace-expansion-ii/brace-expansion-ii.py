class Solution:
    def braceExpansionII(self, expression: str) -> list[str]:
        stack = []
        cur = {""}
        union = None

        for ch in expression:
            if ch == '{':
                stack.append((cur, union))
                cur = {""}
                union = set()

            elif ch == ',':
                if union is not None:
                    union |= cur
                cur = {""}

            elif ch == '}':
                union |= cur
                cur = union

                prev, prev_union = stack.pop()

                # Concatenate with expression before '{'
                nxt = set()
                for a in prev:
                    for b in cur:
                        nxt.add(a + b)

                cur = nxt
                union = prev_union

            else:
                # Normal lowercase letter: concatenate it
                cur = {s + ch for s in cur}

        return sorted(cur)