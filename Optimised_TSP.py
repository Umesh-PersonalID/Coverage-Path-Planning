import networkx as nx

# Create a complete graph with weights
graph = nx.complete_graph(4)
graph[0][1]['weight'] = 1
graph[0][2]['weight'] = 2
graph[0][3]['weight'] = 3
graph[1][2]['weight'] = 4
graph[1][3]['weight'] = 5
graph[2][3]['weight'] = 6

# Find the approximate TSP using the Christofides algorithm
tsp_graph = nx.algorithms.approximation.traveling_salesman_problem.christofides(graph)
path = list(tsp_graph.nodes)

# Print the path
print(" -> ".join(str(node) for node in path))
