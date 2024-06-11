def rotate_2d_matrix(matrix):
    """ Rotate 2D Matrix
    Args:
        matrix - list of list with length sys.argv[1]
    """
    n = len(matrix)
    for i in range(n):
        for j in range(i, n):
            matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]

    for i in range(n):
        matrix[i].reverse()
    
    return matrix,
