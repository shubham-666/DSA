class Solution:
    def decodeCiphertext(self, encodedText: str, rows: int) -> str:
        if rows == 1:
            return encodedText

        cols = len(encodedText) // rows

        matrix = []
        index = 0

        for _ in range(rows):
            matrix.append(encodedText[index:index + cols])
            index += cols

        result = []

        for start_col in range(cols):
            r = 0
            c = start_col

            while r < rows and c < cols:
                result.append(matrix[r][c])
                r += 1
                c += 1

        return ''.join(result).rstrip()