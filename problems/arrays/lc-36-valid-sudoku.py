"""
platform: lc
id: 36
name: valid sudoku
pattern: arrays_hashing
tags: matrix
complexity:
notes: 
"""

class Solution:
    def isValidSudoku(self, board: list) -> bool:
        # check rows for 1-9
        # check columns for 1-9
        # check boxes for 1-9

        # for box in board:
        #   check if num in row or col
        #   check if num in boxes

        rows, cols, boxes = [set()]*9, [set()]*9, [set()]*9

        first, second, third = set([0,1,2]), set([3,4,5]), set([6,7,8])


        for row in range(len(board)):
            for col in range(len(board[0])):
                if board[row][col] == ".":
                    continue
                box = 0
                if col in first:
                    box = 0
                elif col in second:
                    box = 1
                elif col in third:
                    box = 2

                if row in second:
                    box += 3
                elif row in third:
                    box += 6

                if (
                    board[row][col] in rows[row]
                    or board[row][col] in cols[col]
                    or board[row][col] in boxes[box]
                ):
                    return False

                rows[row].add(board[row][col])
                cols[col].add(board[row][col])
                boxes[box].add(board[row][col])

        return True

