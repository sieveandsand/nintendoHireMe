import numpy as np
import galois

diffusion_array = [
[1,0,0,0,0,0,0,1,0,0,1,0,1,1,0,1,0,0,1,1,0,1,1,0,0,1,0,0,1,1,1,1],
[0,1,0,0,1,0,0,1,0,0,1,1,1,0,1,1,1,0,1,0,0,1,0,1,0,1,1,0,1,0,0,0],
[0,0,1,0,0,1,0,0,1,0,0,1,0,1,0,1,1,1,0,1,1,0,1,0,0,0,1,1,1,1,0,0],
[0,0,0,1,0,0,1,0,0,1,0,0,1,0,1,0,0,1,1,0,1,1,0,1,1,0,0,1,1,1,1,0],
[0,0,0,1,1,0,0,0,1,1,0,1,0,0,1,0,0,1,1,0,0,0,1,1,1,1,1,1,0,1,0,0],
[1,0,0,1,0,1,0,0,1,0,1,1,0,0,1,1,0,1,0,1,1,0,1,0,1,0,0,0,0,1,1,0],
[0,1,0,0,0,0,1,0,0,1,0,1,1,0,0,1,1,0,1,0,1,1,0,1,1,1,0,0,0,0,1,1],
[0,0,1,0,0,0,0,1,1,0,1,0,0,1,0,0,1,1,0,1,0,1,1,0,1,1,1,0,1,0,0,1],
[0,0,1,0,1,1,0,1,1,0,0,0,0,0,0,1,0,1,0,0,1,1,1,1,0,0,1,1,0,1,1,0],
[0,0,1,1,1,0,1,1,0,1,0,0,1,0,0,1,0,1,1,0,1,0,0,0,1,0,1,0,0,1,0,1],
[1,0,0,1,0,1,0,1,0,0,1,0,0,1,0,0,0,0,1,1,1,1,0,0,1,1,0,1,1,0,1,0],
[0,1,0,0,1,0,1,0,0,0,0,1,0,0,1,0,1,0,0,1,1,1,1,0,0,1,1,0,1,1,0,1],
[1,1,0,1,0,0,1,0,0,0,0,1,1,0,0,0,1,1,1,1,0,1,0,0,0,1,1,0,0,0,1,1],
[1,0,1,1,0,0,1,1,1,0,0,1,0,1,0,0,1,0,0,0,0,1,1,0,0,1,0,1,1,0,1,0],
[0,1,0,1,1,0,0,1,0,1,0,0,0,0,1,0,1,1,0,0,0,0,1,1,1,0,1,0,1,1,0,1],
[1,0,1,0,0,1,0,0,0,0,1,0,0,0,0,1,1,1,1,0,1,0,0,1,1,1,0,1,0,1,1,0],
[0,0,1,1,0,1,1,0,0,1,0,0,1,1,1,1,1,0,0,0,0,0,0,1,0,0,1,0,1,1,0,1],
[1,0,1,0,0,1,0,1,0,1,1,0,1,0,0,0,0,1,0,0,1,0,0,1,0,0,1,1,1,0,1,1],
[1,1,0,1,1,0,1,0,0,0,1,1,1,1,0,0,0,0,1,0,0,1,0,0,1,0,0,1,0,1,0,1],
[0,1,1,0,1,1,0,1,1,0,0,1,1,1,1,0,0,0,0,1,0,0,1,0,0,1,0,0,1,0,1,0],
[0,1,1,0,0,0,1,1,1,1,1,1,0,1,0,0,0,0,0,1,1,0,0,0,1,1,0,1,0,0,1,0],
[0,1,0,1,1,0,1,0,1,0,0,0,0,1,1,0,1,0,0,1,0,1,0,0,1,0,1,1,0,0,1,1],
[1,0,1,0,1,1,0,1,1,1,0,0,0,0,1,1,0,1,0,0,0,0,1,0,0,1,0,1,1,0,0,1],
[1,1,0,1,0,1,1,0,1,1,1,0,1,0,0,1,0,0,1,0,0,0,0,1,1,0,1,0,0,1,0,0],
[0,1,0,0,1,1,1,1,0,0,1,1,0,1,1,0,0,0,1,0,1,1,0,1,1,0,0,0,0,0,0,1],
[0,1,1,0,1,0,0,0,1,0,1,0,0,1,0,1,0,0,1,1,1,0,1,1,0,1,0,0,1,0,0,1],
[0,0,1,1,1,1,0,0,1,1,0,1,1,0,1,0,1,0,0,1,0,1,0,1,0,0,1,0,0,1,0,0],
[1,0,0,1,1,1,1,0,0,1,1,0,1,1,0,1,0,1,0,0,1,0,1,0,0,0,0,1,0,0,1,0],
[1,1,1,1,0,1,0,0,0,1,1,0,0,0,1,1,1,1,0,1,0,0,1,0,0,0,0,1,1,0,0,0],
[1,0,0,0,0,1,1,0,0,1,0,1,1,0,1,0,1,0,1,1,0,0,1,1,1,0,0,1,0,1,0,0],
[1,1,0,0,0,0,1,1,1,0,1,0,1,1,0,1,0,1,0,1,1,0,0,1,0,1,0,0,0,0,1,0],
[1,1,1,0,1,0,0,1,1,1,0,1,0,1,1,0,1,0,1,0,0,1,0,0,0,0,1,0,0,0,0,1]
]

final_state = [
    141, 194, 225, 81, 171, 85, 151, 180,
    244, 122, 195, 83, 170, 216, 243, 148,
    177, 66, 72, 50, 248, 43, 248, 163,
    217, 236, 69, 183, 193, 72, 27, 6
]

# Define the GF(2) field
GF2 = galois.GF(2)

# Convert A to a GF(2) matrix
A = GF2(diffusion_array)

# Convert final_state to a GF(2) vector
final_state = GF2(final_state)

# Solve the system of equations
B = GF2.solve(A, final_state)

# Convert B back to a regular list for display
B_list = B.tolist()

print("B =", B_list)

# Verify the solution
result = A @ B
print("AxB =", result.tolist())
print("final_state =", final_state.tolist())
print("AxB == final_state:", (result == final_state).all())


# def gauss_elimination_gf2(A, b):
#     n = len(b)
#     # Augment A with b
#     M = np.column_stack((A, b))
    
#     for i in range(n):
#         # Find pivot
#         pivot = i
#         for j in range(i, n):
#             if M[j, i] == 1:
#                 pivot = j
#                 break
        
#         # Swap rows
#         M[i], M[pivot] = M[pivot].copy(), M[i].copy()
        
#         # Eliminate
#         for j in range(i+1, n):
#             if M[j, i] == 1:
#                 M[j] = M[j] ^ M[i]
    
#     # Back substitution
#     x = np.zeros(n, dtype=int)
#     for i in range(n-1, -1, -1):
#         x[i] = M[i, -1]
#         for j in range(i+1, n):
#             x[i] ^= (M[i, j] & x[j])
    
#     return x

# # Create the diffusion matrix A from your table
# A = np.zeros((32, 32), dtype=int)
# # Fill A based on your diffusion table
# # For example, A[0, 0] = A[0, 7] = A[0, 10] = ... = 1

# diffusion_array = [
# [1,0,0,0,0,0,0,1,0,0,1,0,1,1,0,1,0,0,1,1,0,1,1,0,0,1,0,0,1,1,1,1],
# [0,1,0,0,1,0,0,1,0,0,1,1,1,0,1,1,1,0,1,0,0,1,0,1,0,1,1,0,1,0,0,0],
# [0,0,1,0,0,1,0,0,1,0,0,1,0,1,0,1,1,1,0,1,1,0,1,0,0,0,1,1,1,1,0,0],
# [0,0,0,1,0,0,1,0,0,1,0,0,1,0,1,0,0,1,1,0,1,1,0,1,1,0,0,1,1,1,1,0],
# [0,0,0,1,1,0,0,0,1,1,0,1,0,0,1,0,0,1,1,0,0,0,1,1,1,1,1,1,0,1,0,0],
# [1,0,0,1,0,1,0,0,1,0,1,1,0,0,1,1,0,1,0,1,1,0,1,0,1,0,0,0,0,1,1,0],
# [0,1,0,0,0,0,1,0,0,1,0,1,1,0,0,1,1,0,1,0,1,1,0,1,1,1,0,0,0,0,1,1],
# [0,0,1,0,0,0,0,1,1,0,1,0,0,1,0,0,1,1,0,1,0,1,1,0,1,1,1,0,1,0,0,1],
# [0,0,1,0,1,1,0,1,1,0,0,0,0,0,0,1,0,1,0,0,1,1,1,1,0,0,1,1,0,1,1,0],
# [0,0,1,1,1,0,1,1,0,1,0,0,1,0,0,1,0,1,1,0,1,0,0,0,1,0,1,0,0,1,0,1],
# [1,0,0,1,0,1,0,1,0,0,1,0,0,1,0,0,0,0,1,1,1,1,0,0,1,1,0,1,1,0,1,0],
# [0,1,0,0,1,0,1,0,0,0,0,1,0,0,1,0,1,0,0,1,1,1,1,0,0,1,1,0,1,1,0,1],
# [1,1,0,1,0,0,1,0,0,0,0,1,1,0,0,0,1,1,1,1,0,1,0,0,0,1,1,0,0,0,1,1],
# [1,0,1,1,0,0,1,1,1,0,0,1,0,1,0,0,1,0,0,0,0,1,1,0,0,1,0,1,1,0,1,0],
# [0,1,0,1,1,0,0,1,0,1,0,0,0,0,1,0,1,1,0,0,0,0,1,1,1,0,1,0,1,1,0,1],
# [1,0,1,0,0,1,0,0,0,0,1,0,0,0,0,1,1,1,1,0,1,0,0,1,1,1,0,1,0,1,1,0],
# [0,0,1,1,0,1,1,0,0,1,0,0,1,1,1,1,1,0,0,0,0,0,0,1,0,0,1,0,1,1,0,1],
# [1,0,1,0,0,1,0,1,0,1,1,0,1,0,0,0,0,1,0,0,1,0,0,1,0,0,1,1,1,0,1,1],
# [1,1,0,1,1,0,1,0,0,0,1,1,1,1,0,0,0,0,1,0,0,1,0,0,1,0,0,1,0,1,0,1],
# [0,1,1,0,1,1,0,1,1,0,0,1,1,1,1,0,0,0,0,1,0,0,1,0,0,1,0,0,1,0,1,0],
# [0,1,1,0,0,0,1,1,1,1,1,1,0,1,0,0,0,0,0,1,1,0,0,0,1,1,0,1,0,0,1,0],
# [0,1,0,1,1,0,1,0,1,0,0,0,0,1,1,0,1,0,0,1,0,1,0,0,1,0,1,1,0,0,1,1],
# [1,0,1,0,1,1,0,1,1,1,0,0,0,0,1,1,0,1,0,0,0,0,1,0,0,1,0,1,1,0,0,1],
# [1,1,0,1,0,1,1,0,1,1,1,0,1,0,0,1,0,0,1,0,0,0,0,1,1,0,1,0,0,1,0,0],
# [0,1,0,0,1,1,1,1,0,0,1,1,0,1,1,0,0,0,1,0,1,1,0,1,1,0,0,0,0,0,0,1],
# [0,1,1,0,1,0,0,0,1,0,1,0,0,1,0,1,0,0,1,1,1,0,1,1,0,1,0,0,1,0,0,1],
# [0,0,1,1,1,1,0,0,1,1,0,1,1,0,1,0,1,0,0,1,0,1,0,1,0,0,1,0,0,1,0,0],
# [1,0,0,1,1,1,1,0,0,1,1,0,1,1,0,1,0,1,0,0,1,0,1,0,0,0,0,1,0,0,1,0],
# [1,1,1,1,0,1,0,0,0,1,1,0,0,0,1,1,1,1,0,1,0,0,1,0,0,0,0,1,1,0,0,0],
# [1,0,0,0,0,1,1,0,0,1,0,1,1,0,1,0,1,0,1,1,0,0,1,1,1,0,0,1,0,1,0,0],
# [1,1,0,0,0,0,1,1,1,0,1,0,1,1,0,1,0,1,0,1,1,0,0,1,0,1,0,0,0,0,1,0],
# [1,1,1,0,1,0,0,1,1,1,0,1,0,1,1,0,1,0,1,0,0,1,0,0,0,0,1,0,0,0,0,1]
# ]

# final_state = [
#     141, 194, 225, 81, 171, 85, 151, 180,
#     244, 122, 195, 83, 170, 216, 243, 148,
#     177, 66, 72, 50, 248, 43, 248, 163,
#     217, 236, 69, 183, 193, 72, 27, 6
# ]

# np_diffusion_array = np.array(diffusion_array)
# np_final_state = np.array(final_state)

# # Given the final state b
# # b = np.array([/* your final state here */], dtype=int)

# # Solve
# x = gauss_elimination_gf2(np_diffusion_array, np_final_state)

# print("Original elements:", x)