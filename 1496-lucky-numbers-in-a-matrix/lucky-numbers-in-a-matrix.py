class Solution:
    def luckyNumbers(self, matrix: List[List[int]]) -> List[int]:
        ans = []

        for i in range(len(matrix)):
            row_min = min(matrix[i])

            for j in range(len(matrix[0])):
                if matrix[i][j] == row_min:
                    col_max = max(matrix[x][j] for x in range(len(matrix)))
                    
                    if matrix[i][j] == col_max:
                        ans.append(matrix[i][j])

        return ans