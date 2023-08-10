import matplotlib.pyplot as plt


def flood_fill(cluster, threshold):
    selected_regions = []
    visited = set()

    def explore(x, y):
        if (x, y) in visited:
            return
        visited.add((x, y))

        if cluster[x][y] >= threshold:
            selected_regions.append((x, y))

            if x > 0:
                explore(x - 1, y)
            if y > 0:
                explore(x, y - 1)
            if x < len(cluster) - 1:
                explore(x + 1, y)
            if y < len(cluster[0]) - 1:
                explore(x, y + 1)

    for x in range(len(cluster)):
        for y in range(len(cluster[0])):
            if (x, y) not in visited:
                explore(x, y)

    return selected_regions


# Example usage of flood_fill function

# Define a sample cluster of regions (represented as a 2D list of stress levels)
cluster = [
    [0.1, 0.2, 0.3, 0.4, 0.5],
    [0.6, 0.7, 0.8, 0.9, 1.0],
    [0.4, 0.3, 0.2, 0.1, 0.0],
    [0.5, 0.6, 0.7, 0.8, 0.9],
    [0.0, 0.1, 0.2, 0.3, 0.4]
]

# Choose a threshold value for identifying stressed regions
threshold = 0.8

# Call the flood_fill function to select stressed regions
selected_regions = flood_fill(cluster, threshold)

# Print the selected regions
print("Selected regions:")
print(type(selected_regions))
for region in selected_regions:
    print(region)


# Define list of coordinates
coords = selected_regions

# Create figure and axis objects
fig, ax = plt.subplots()

# Loop through coordinates and plot circles at each position
for coord in coords:
    circle = plt.Circle(coord, radius=0.1, color='r')
    ax.add_patch(circle)

# Set axis limits and labels
ax.set_xlim(0, 5)
ax.set_ylim(0, 5)
ax.set_xlabel('X Axis')
ax.set_ylabel('Y Axis')

# Show plot
plt.show()