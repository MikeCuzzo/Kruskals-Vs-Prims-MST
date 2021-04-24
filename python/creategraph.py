# Imports
import globalvariables
import matplotlib.pyplot as plt
import networkx as nx
from itertools import combinations, permutations
import random
import sys
import os

class create_graphs:
    def __init__(self):

        # Creating the Global Variables Item
        self.Global = globalvariables.global_variables()

        # Creating the list to hold the graphs
        self.Graphs = list()

        for i in range(0, len(self.Global.get_nodes())):
            self.Graphs.append(self.generate_graph(self.Global.get_nodes()[i], self.Global.get_densities()[i]))

        i = 0
        for graph in self.Graphs:
            nx.draw(graph)
            plt.savefig("../Data/graph" + str(i) + ".png")
            i += 1
        
        self.generate_graph_data()


    def generate_graph(self, number_of_nodes, density):
        # Creating the list of nodes
        nodes = list(range(0, number_of_nodes))

        # Creates a list of all the possible edges or 100% Density
        possible_edges = list(combinations(nodes, 2))
        total_possible_edges = len(possible_edges)
        
        # Creating the list iterator
        i = 0

        # Creating the Graph object to return
        G = self.create_least_connected_graph(nodes)

        # This is a loop to remove all the edges until the density is correct
        while True:

            # Calculating the density using number of current edges/total
            achieved_density = float(G.number_of_edges()/total_possible_edges)
            
            # Checking if the graph is at the proper density
            if achieved_density >= float(density/100):
                print("Total possible Edges: " + str(total_possible_edges) + 
                      "\nNumber of Edges: " + str(G.number_of_edges()) + 
                      "\nActual Density: " + str(float(100*(G.number_of_edges())/total_possible_edges)) + "\n" )
                return G

            if i == len(possible_edges)-1:
                i = 0

            # Generating the random chance of the edge being added to get proper density
            r = random.randint(0, 100)

            # Check if this edge is added
            if r < density:
                G.add_edge(possible_edges[i][0], possible_edges[i][1])
                possible_edges.remove(possible_edges[i])
                i-=1
            
            i+=1        
        return G

    def create_least_connected_graph(self, nodes):
        G = nx.Graph()
        i = 0
        while i != len(nodes)-1:
            print(str(i) + ", " + str(i+1))
            G.add_edge(i, i+1)
            i+=1
        
        return G
    

    def generate_graph_data(self):
        i = 0
        for graph in self.Graphs:
            with open("../data/graph" + str(i) + ".txt", "w") as file:
                output = str(graph.edges())
                output = output.replace(", (", "\n(")
                output = output.replace('[', '')
                output = output.replace(']', '')
                file.write(str(graph.number_of_edges())+ "\n")
                file.write(output)
            i+=1


if __name__ == "__main__":
    c = create_graphs()










