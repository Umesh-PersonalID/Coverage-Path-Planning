import itertools
import sys
import math

def tsp(cities):
    # Generate all possible orderings of cities
    permutations = list(itertools.permutations(cities))
    
    # Calculate the total distance of each possible path
    shortest_distance = sys.maxsize
    shortest_path = None
    for path in permutations:
        distance = sum(distance_between_cities(path[i], path[i+1]) for i in range(len(path)-1))
        if distance < shortest_distance:
            shortest_distance = distance
            shortest_path = path
    
    return shortest_distance, shortest_path

def distance_between_cities(city1, city2):
    # Calculate the Euclidean distance between two cities
    x1, y1 = city1
    x2, y2 = city2
    return math.sqrt((x2-x1)**2 + (y2-y1)**2)

# Example usage
cities = [(0, 0), (10, 1), (2, 5), (23, 3)]
shortest_distance, shortest_path = tsp(cities)
print("Shortest distance:", shortest_distance)
print("Shortest path:", shortest_path)
