def convert(string,numRows):
    matrix = [['']*7 for _ in range(numRows)]
    count = 0
    zigzag_idx = numRows - 1
    last_full_col = 1
    for col in range(0,7):
        # print(zigzag_idx)
        for row in range(0,numRows):
            if count >= len(string):
                break
            if col  == 0 or col == numRows - 1 or col - last_full_col == numRows - 1:
                matrix[row][col] = string[count]
                count = count + 1
                zigzag_idx = row
                if row == numRows - 1:
                    last_full_col = col
                # print("col:",col)
                # print(count)
            else:
                if row == zigzag_idx - 1:
                    zigzag_idx = zigzag_idx - 1
                    matrix[zigzag_idx][col] = string[count]
                    count = count + 1
    print(matrix)
    res = ''
    for row in matrix:
        res = res + ''.join(row)
    return res
print(convert("AB",2))