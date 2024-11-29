import numpy as np
import time

def multiplicar_matrices(A, B):
    filas_A, columnas_A = A.shape
    filas_B, columnas_B = B.shape

    if columnas_A != filas_B:
        raise ValueError("Las matrices no se pueden multiplicar")

    C = np.zeros((filas_A, columnas_B))
    for i in range(filas_A):
        for j in range(columnas_B):
            for k in range(columnas_A):
                C[i][j] += A[i][k] * B[k][j]

    return C 


start_time = time.time()
A = np.random.rand(100, 500)
B = np.random.rand(500, 100)

Resultado = multiplicar_matrices(A, B)
end_time = time.time()
print('tiempo: ', str(end_time - start_time))
