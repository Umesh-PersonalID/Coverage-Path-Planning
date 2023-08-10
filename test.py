import numpy as np
import matplotlib.pyplot as plt

# Example 2D matrix
matrix = np.array([[9, 2, 3], [4, 5, 6], [7, 8, 9]])

# Create a color map
cmap = plt.get_cmap('Blues')

# Plot the matrix as a 2D map
plt.imshow(matrix, cmap=cmap)

# Show the plot
plt.show()