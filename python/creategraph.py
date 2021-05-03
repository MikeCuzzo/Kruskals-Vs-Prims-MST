# Imports
import globalvariables
import matplotlib.pyplot as plt
import networkx as nx
from itertools import combinations, permutations
import random
import sys
import shutil
import os

class create_graphs:
    def __init__(self):

        # Creating the Global Variables Item
        self.Global = globalvariables.global_variables()

        # Creating the list to hold the graphs
        self.Graphs = list()

        # Creating nodes and density from the global variables class
        self.nodes = self.Global.get_list_of_nodes()
        self.density = self.Global.get_list_of_densities()

        self.graph_stats_iterator = 1

        # Fills the graph lists with data from all the graph
        for i in range(0, min(len(self.nodes), len(self.density))):
            self.Graphs.append(self.generate_graph(self.nodes[i], self.density[i]))

        # Generate the text file and image files for each graph
        self.generate_graph_data()
        self.generate_graph_visualization()


    # Creates the graph, ensuring that it is fully connected and as close to the density as possible
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

                # Creating the stats string to be added to a file
                output = ("Total possible Edges: " + str(total_possible_edges) +
                         "\nNumber of Edges: " + str(G.number_of_edges()) + 
                         "\nActual Density: " + str(float(100*(G.number_of_edges())/total_possible_edges)) + "%\n")

                # Printing the stats about the completed graph
                with open("../output/graph-stats/generated-graph-stats-" + str(self.graph_stats_iterator) + ".txt", "w+") as file:
                    file.write(output)
                
                # Incrementing the graph stats iterator
                self.graph_stats_iterator += 1
                

                # Returning the completed graph
                return G

            if i == len(possible_edges)-1:
                i = 0

            # Generating the random chance of the edge being added to get proper density
            r = random.randint(0, 100)

            # Check if this edge is added
            if r < density:
                G.add_edge(possible_edges[i][0], possible_edges[i][1], weight=random.randint(0, 999999))
                possible_edges.remove(possible_edges[i])
                i-=1
            
            i+=1        
        return G

    def create_least_connected_graph(self, nodes):
        G = nx.Graph()
        i = 0
        while i != len(nodes)-1:
            G.add_edge(i, i+1, weight=random.randint(0, 999999))       
            i+=1
        
        return G
    

    def generate_graph_data(self):
        i = 0
        for graph in self.Graphs:
            with open("../data/graph/text/graph" + str(i) + ".txt", "w+") as file:
                for u,v,data in graph.edges(data=True):
                    file.write(str(u) + " " + str(v)+ " " + str(data).replace('{\'weight\': ', '').replace('}', '') + "\n")
            i+=1
    
    def generate_graph_visualization(self):
        i = 0
        for root, dirs, files in os.walk('../output/graph-images/'):
                for f in files:
                    os.unlink(os.path.join(root, f))
                for d in dirs:
                    shutil.rmtree(os.path.join(root, d))
                    
        for graph in self.Graphs:
            nx.draw(graph, with_labels=True)
            plt.savefig("../output/graph-images/graph_visualization" + str(i) + ".png")
            plt.close()
            i += 1


if __name__ == "__main__":
    c = create_graphs()

