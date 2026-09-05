class Solution:
    def reformat(self, s: str) -> str:
        letters = []
        digits = []

        for ch in s:
            if ch.isalpha():
                letters.append(ch)
            else:
                digits.append(ch)

        if abs(len(letters) - len(digits)) > 1:
            return ""

        # Start with the type having more characters
        if len(letters) < len(digits):
            letters, digits = digits, letters

        ans = []

        for i in range(len(letters)):
            ans.append(letters[i])
            if i < len(digits):
                ans.append(digits[i])

        return ''.join(ans)