class Solution:
    def solveSudoku(self, board: List[List[str]]) -> None:
        rows = [set() for _ in range(9)]
        cols = [set() for _ in range(9)]
        boxes = [set() for _ in range(9)]

        # Store existing numbers
        for r in range(9):
            for c in range(9):
                if board[r][c] != '.':
                    num = board[r][c]
                    rows[r].add(num)
                    cols[c].add(num)
                    boxes[(r // 3) * 3 + (c // 3)].add(num)

        def backtrack():
            # Find the empty cell with the fewest possible choices
            best_r = -1
            best_c = -1
            best_options = None

            for r in range(9):
                for c in range(9):
                    if board[r][c] == '.':
                        box = (r // 3) * 3 + (c // 3)

                        options = [
                            num for num in "123456789"
                            if num not in rows[r]
                            and num not in cols[c]
                            and num not in boxes[box]
                        ]

                        if not options:
                            return False

                        if best_options is None or len(options) < len(best_options):
                            best_options = options
                            best_r = r
                            best_c = c

                            # Can't do better than one choice
                            if len(options) == 1:
                                break

                if best_options is not None and len(best_options) == 1:
                    break

            # No empty cells -> solved
            if best_options is None:
                return True

            box = (best_r // 3) * 3 + (best_c // 3)

            for num in best_options:
                board[best_r][best_c] = num
                rows[best_r].add(num)
                cols[best_c].add(num)
                boxes[box].add(num)

                if backtrack():
                    return True

                # Undo
                board[best_r][best_c] = '.'
                rows[best_r].remove(num)
                cols[best_c].remove(num)
                boxes[box].remove(num)

            return False

        backtrack()