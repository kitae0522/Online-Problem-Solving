import numpy as np

def adjoint(matrix_size, matrix_input):
    matrix = matrix_input.copy()
    adj = np.zeros((matrix_size, matrix_size))
    
    for row in range(matrix_size):
        for col in range(matrix_size):
            partial = np.delete(matrix, row, axis=0)
            partial = np.delete(partial, col, axis=1)
            C = np.linalg.det(partial) * (-1)**(row+col)
            adj[col][row] = C
    
    return adj

N = int(input())
A = np.array([list(map(int, input().split())) for i in range(N)])

try:
    print(adjoint(N, A) / np.linalg.det(A))
except:
    print('no inverse')
