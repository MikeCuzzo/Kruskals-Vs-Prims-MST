import networkx as nx

G = nx.grid_2d_graph(5, 5)  # 5x5 grid

# print the adjacency list
for line in nx.generate_adjlist(G):
    print(line)
# write edgelist to input file
nx.write_edgelist(G, path="../data/input.txt", delimiter=":")
# read edgelist from input file
H = nx.read_edgelist(path="../data/input.txt", delimiter=":")