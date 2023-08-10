def change_matrix(matrix, traversal):
    # Base case: check if all elements are zero
    if all(val == 0 for row in matrix for val in row):
        return [traversal]
    
    # Initialize list to store all possible traversals
    traversals = []
    
    # Check top and bottom rows
    for j in range(len(matrix[0])):
        if matrix[0][j] != 0:
            new_matrix = [row[:] for row in matrix]
            new_matrix[0][j] -= 1
            traversals += change_matrix(new_matrix, traversal + f'{j},0-')
        if matrix[-1][j] != 0:
            new_matrix = [row[:] for row in matrix]
            new_matrix[-1][j] -= 1
            traversals += change_matrix(new_matrix, traversal + f'{j},{len(matrix)-1}-')
    
    # Check left and right columns
    for i in range(len(matrix)):
        if matrix[i][0] != 0:
            new_matrix = [row[:] for row in matrix]
            new_matrix[i][0] -= 1
            traversals += change_matrix(new_matrix, traversal + f'0,{i}-')
        if matrix[i][-1] != 0:
            new_matrix = [row[:] for row in matrix]
            new_matrix[i][-1] -= 1
            traversals += change_matrix(new_matrix, traversal + f'{len(matrix[0])-1},{i}-')
    
    return traversals


matrix = [[0, 2], [3, 4]]
traversals = change_matrix(matrix, '')
print(traversals)


