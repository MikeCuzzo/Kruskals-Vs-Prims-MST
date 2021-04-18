import matplotlib.pyplot as plt
import networkx as nx
import sys

# records command line arguments
nodes = int(sys.argv[1])
edges = int(sys.argv[2])

G = nx.grid_2d_graph(nodes, edges)  # 5x5 grid

# print the adjacency list
for line in nx.generate_adjlist(G):
    print(line)
# write edgelist to input file
nx.write_edgelist(G, path="../data/input.txt", delimiter=":")
# read edgelist from input file
H = nx.read_edgelist(path="../data/input.txt", delimiter=":")