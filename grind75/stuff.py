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

if __name__ == "__main__":
    print(peakMeetings([[1, 5], [2, 4], [4, 5], [4, 6], [2, 7], [6,9]])) # 4
    print(largestXFigure([[1, 0, 1, 0, 1], 
                          [0, 1, 0, 1, 0], 
                          [1, 0, 1, 0, 1],
                          [0, 1, 0, 1, 0], 
                          [1, 0, 1, 0, 1]])) # ((2, 2), 3)