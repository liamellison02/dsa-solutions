from collections import defaultdict

def findPairs(numbers):
    arrLen = len(numbers)
    i, j, numPairs = 0, 0, 0
    iArr, jArr = [], []
    
    def digitArr(num: int):
        # function to return digits of an int as an ordered int arr
        retArr = []
        temp = num
        while temp > 0:
            retArr.append(temp % 10)
            temp = temp // 10
        return retArr
        
    def compareDigitArrs(arr1: list, arr2: list):
        # function to compare ordered int arrs
        invalidCount = 0
        invalidIndices = []
        
        if len(arr1) != len(arr2):
            return False
            
        for num in range(len(arr1)):
            if invalidCount > 2:
                return False
            if arr1[num] == arr2[num]:
                continue
            invalidCount += 1
            invalidIndices.append(num)
        
        if (invalidCount == 2 and arr1[invalidIndices[0]] == arr2[invalidIndices[1]] and arr1[invalidIndices[1]] == arr2[invalidIndices[0]]) or invalidCount == 0:
            return True
        else:
            return False
    
    
    while i < arrLen:
        col = i + 1
        iArr = digitArr(numbers[i])
            
        while col < arrLen:
            # check if you can just swap two digits to make same nums
            jArr = digitArr(numbers[j])
            if compareDigitArrs(iArr, jArr):
                numPairs += 1
            col += 1
        i += 1
    
    return numPairs

# find the largest perfect x-figure in a matrix
# given an array of meeting intervals, where arr[i][0] = startHour and 
# arr[i][1] = endHour (not inclusive), return the peak number of meetings in an hour

def peakMeetings(intervals: list):
    times = []
    for i in intervals:
        times.append((i[0], "start"))
        times.append((i[1], "stop"))
    
    times.sort()
    
    maxMeetings = 0
    currMeetings = 0
    latestTime = -1
    
    for time, type in times:
        if time > latestTime:
            if currMeetings > maxMeetings:
                maxMeetings = currMeetings
        latestTime = time
        
        if type == "start":
            currMeetings += 1
        else:
            currMeetings -= 1

    if currMeetings > maxMeetings:
        maxMeetings = currMeetings
    
    return maxMeetings
    

def largestXFigure(matrix):
    # function to find the largest x-figure in a matrix
    m = len(matrix)
    n = len(matrix[0])
    largestX = (0,0)
    largestXLen = 0
    a = [[0 for _ in range(n)] for _ in range(m)]
    b = [[0 for _ in range(n)] for _ in range(m)]
    c = [[0 for _ in range(n)] for _ in range(m)]
    d = [[0 for _ in range(n)] for _ in range(m)]
    
    # fill in botLeftTopRight:
    for row in range(m-1, -1, -1):
        for col in range(n-1, -1, -1):
            val = matrix[row][col]
            if col == 0 or row == m-1 or val == 0:
                a[row][col] = val
            else:
                a[row][col] = val + a[row+1][col-1]
    
    # fill in botRightTopLeft:
    for row in range(m-1, -1, -1):
        for col in range(n):
            val = matrix[row][col]
            if row == m-1 or col == n-1 or val == 0:
                b[row][col] = val
            else:
                b[row][col] = val + b[row+1][col+1]
                
    # fill in topLeftBotRight:
    for row in range(m):
        for col in range(n-1, -1, -1):
            val = matrix[row][col]
            if row == 0 or col == 0 or val == 0:
                c[row][col] = val
            else:
                c[row][col] = val + c[row-1][col-1]
                
    # fill in topRightBotLeft:
    for row in range(m):
        for col in range(n):
            val = matrix[row][col]
            if row == 0 or col == n-1 or val == 0:
                d[row][col] = val
            else:
                d[row][col] = val + d[row-1][col+1]
    
    
    for row in range(m):
        for col in range(n):
            if min(a[row][col], b[row][col], c[row][col], d[row][col]) > largestXLen:
                largestXLen = min(a[row][col], b[row][col], c[row][col], d[row][col])
                largestX = (row, col)
    
    return largestX, largestXLen
                    
            

    # for row in range(m):
    #     for col in range(n):
    #         if matrix[row][col] == 1:

    #             # check for down-diagonal if not already checked
    #             if row - 1 >= 0 and col - 1 >= 0 and matrix[row + 1][col - 1] == 1:
    #                 notDown = (row, col)

    #             # check for up-diagonal if not already checked
    #             if row + 1 < m and col - 1 >= 0 and matrix[row + 1][col - 1] == 1:
    #                 notUp = (row, col)
                
    #             if notUp != (row, col):
    #                 currLen = 1
    #                 while row - currLen >= 0 and col + currLen < n:
    #                     if matrix[row - currLen][col + currLen] == 1:
    #                         currLen += 1
    #                     else:
    #                         break
                    
    #                 maxLen = max(maxLen, currLen)

    #             currLen = 1
    #             while row + currLen < m and  + currLen < n:
    #                 if matrix[row + currLen][col] == 1 and matrix[row][col + currLen] == 1 and matrix[row + currLen][col + currLen] == 1:
    #                     currLen += 1
    #                 else:
    #                     break
    #             maxLen = max(maxLen, currLen)
    
def isValidSudoku(board: list) -> bool:
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
    
def longestDiverseString(a: int, b: int, c: int) -> str:
    # while we have chars left:
        # if last two values in stack are consecutive:
            # check if we can add a diff char
            # if not, return stack as a string
        # if not consecutive chars previously, then we add the char
        # with the highest remaining usages left
    ret, usages = [], {"a": a, "b": b, "c": c}

    while usages["a"] > 0 or usages["b"] > 0 or usages["c"] > 0:

        if len(ret) > 1 and ret[len(ret)-1] == ret[len(ret)-2]:
            chars = {"a", "b", "c"}
            chars.remove(ret[len(ret)-1])
            temp, counter = {}, 0
            for char in chars:
                if usages[char] == 0:
                    counter += 1
                temp[char] = usages[char]
            if counter == 2:
                return "".join(ret)
            curr = max(temp)

        else:
            curr = max(usages)
        
        ret.append(curr)
        usages[curr] -= 1

    return "".join(ret)

if __name__ == "__main__":
    # x,y = "abcd", "abcde"

    # dp = [[0]*(len(x)+1)]*(len(y)+1)

    # for row in dp:
    #     print(row)


    # print("\n")
    # i = 1
    # for lwc in range(1, len(dp)):
    #     for swc in range(1, len(dp[0])):
    #         print(f'Iteration #{i}: lwc={lwc},swc={swc}\n')
    #         i += 1

    # print(f'Longest subsequence = {dp[len(y)][len(x)]}')
    # print(peakMeetings([[1, 5], [2, 4], [4, 5], [4, 6], [2, 7], [6,9]])) # 4
    # print(largestXFigure([[1, 0, 1, 0, 1], 
    #                       [0, 1, 0, 1, 0], 
    #                       [1, 0, 1, 0, 1],
    #                       [0, 1, 0, 1, 0], 
    #                       [1, 0, 1, 0, 1]])) # ((2, 2), 3)
    # board=[["1","2",".",".","3",".",".",".","."],["4",".",".","5",".",".",".",".","."],[".","9","8",".",".",".",".",".","3"],["5",".",".",".","6",".",".",".","4"],[".",".",".","8",".","3",".",".","5"],["7",".",".",".","2",".",".",".","6"],[".",".",".",".",".",".","2",".","."],[".",".",".","4","1","9",".",".","8"],[".",".",".",".","8",".",".","7","9"]]
    # print(isValidSudoku(board)) 
    print(longestDiverseString(1, 1, 7)) # "ccbccacc"