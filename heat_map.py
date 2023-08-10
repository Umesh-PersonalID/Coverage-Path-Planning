import cv2
import matplotlib.pyplot as plt
import numpy as np

# Load the image
img = cv2.imread('heat_image.jpg')

# Convert the image to HSV color space
hsv_img = cv2.cvtColor(img, cv2.COLOR_BGR2HSV)

# Create a numpy array of the same size as the image
heatmap = np.zeros_like(img[:,:,0], dtype=np.uint8)

# Assign intensity values based on color
heatmap[(hsv_img[:,:,0] > 0) & (hsv_img[:,:,0] < 22.5)] = 3
heatmap[(hsv_img[:,:,0] >= 22.5) & (hsv_img[:,:,0] < 67.5)] = 2
heatmap[(hsv_img[:,:,0] >= 67.5) & (hsv_img[:,:,0] < 135)] = 1


# Define the grid parameters
grid_length = 8# in meters
grid_breadth = 10 # in meters
cell_size = 1 # in meters

# Resize the heatmap to the desired size
heatmap = cv2.resize(heatmap, (int(grid_breadth/cell_size), int(grid_length/cell_size)), interpolation=cv2.INTER_LINEAR)

# Generate the grid
grid = np.zeros((int(grid_length/cell_size), int(grid_breadth/cell_size)), dtype=np.uint8)
for i in range(int(grid_length/cell_size)):
    for j in range(int(grid_breadth/cell_size)):
        cell_heatmap = heatmap[int(i*cell_size/cell_size):int((i+1)*cell_size/cell_size), int(j*cell_size/cell_size):int((j+1)*cell_size/cell_size)]
        grid[i][j] = int(np.mean(cell_heatmap))

# Display the grid
print(grid)
cmap = plt.get_cmap('Blues')

# Plot the matrix as a 2D map
plt.imshow(grid, cmap=cmap)

# Show the plot
plt.show()
