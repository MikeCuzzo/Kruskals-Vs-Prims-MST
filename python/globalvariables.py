# Imports
import matplotlib.pyplot as plt
import networkx as nx
import sys
import os

class global_variables:
    def __init__(self):

        # Declaring the list that will store the values for nodes and edges
        self.nodes = list()
        self.densities = list()

        # Getting the location of the current python file
        # This is useful for Relative-Pathing later
        current_absolute_path = os.path.dirname(__file__)

        # This is the relative path from the python file to the global variable file
        global_variable_relative_path = "../data/graph/rsc/generation-rules.txt"

        # This is the absolute path from the python file to the global variable file
        global_variable_absolute_path = os.path.join(current_absolute_path, global_variable_relative_path)

        # Reading the global variables into a variable called data and splitting it into an array by line
        with open(global_variable_absolute_path, 'r') as file:
            data = file.read().split('\n')

        # Looping through all the variables in the global variables
        for variable in data:

            # If this data pertains to Graph-
            if 'Graph-' in variable:
                
                # If the data is a Graph-Node we will append its value to the node list
                if '-Nodes' in variable:
                    self.nodes.append(int(variable[variable.index(' '): len(variable)]))
                
                # If the data is a Graph-Node we will append its value to the node list
                if '-Density' in variable:
                    self.densities.append(int(variable[variable.index(' '): len(variable)]))

    def get_list_of_nodes(self):
        return self.nodes

    def get_list_of_densities(self): 
        return self.densities
