from mpl_toolkits.mplot3d import Axes3D
import matplotlib.patches as mpatches
from math import comb
import matplotlib.pyplot as plt
import numpy
import csv
import os


def transform_data(path):

    current_absolute_path = os.path.dirname(__file__)

    # This is the relative path from the python file to the global variable file
    pystats_relative = "../data/timing/stats-density.csv"

    # This is the absolute path from the python file to the global variable file
    pystats_absolute = os.path.join(current_absolute_path, pystats_relative)

    with open(path, 'r') as read_obj:
        with open(pystats_absolute, 'w', newline='') as write_obj:
            # Create a csv.reader object from the input file object
            csv_reader = csv.reader(read_obj)
            # Create a csv.writer object from the output file object
            csv_writer = csv.writer(write_obj)
            
            next(csv_reader)
            next(csv_reader)

            


            # Read each row of the input csv file as list
            for row in csv_reader:
                # Density
                density = int(row[1]) / comb(int(row[0]), 2)

                # Append the default text in the row / list
                row.append(density*100)
                # Add the updated row / list to the output file
                csv_writer.writerow(row)
            
            

if __name__ == "__main__":

    # This is the absolute path of the current path
    current_absolute_path = os.path.dirname(__file__)

    # This is the relative path that the stats are there
    stats_relative = "../data/timing/stats.csv"

    # This is the relative path for the python stats
    pystats_relative = "../data/timing/stats-density.csv"

    pic_relative = "../data/timing/kruskal-vs-prim.png"

    # This is the absolute path for the stats file
    stats_absolute = os.path.join(current_absolute_path, stats_relative)

    # This is the absolute path for the pystats file
    pystats_absolute = os.path.join(current_absolute_path, pystats_relative)

    # This is the absolute path for the pic_relative
    pic_absolute = os.path.join(current_absolute_path, pic_relative)

    transform_data(stats_absolute)


    
    fig = plt.figure()
    ax = fig.add_subplot(111, projection='3d')


    nodes_x = list()
    density_y = list()
    kruskal_z = list()
    prim_z = list()

    with open(pystats_absolute,'r') as csvfile:
        plots = csv.reader(csvfile, delimiter=',')
        for row in plots:
            nodes_x.append(int(row[0]))
            density_y.append(int(float(row[4])))
            kruskal_z.append(int(row[2]))
            prim_z.append(int(row[3]))

    # Data for a three-dimensional line
    ax.scatter(nodes_x, density_y, kruskal_z, c='b', label="Kruskal")
    ax.scatter(nodes_x, density_y, prim_z, c='r', label="Prim")

    # Setting labels
    ax.set_xlabel('Number of Nodes')
    ax.set_ylabel('Density (%)')
    ax.set_zlabel('Time (ms)')

    red_patch = mpatches.Patch(color='red', label='Kruskal')
    blue_patch = mpatches.Patch(color='blue', label='Prim')

    plt.legend(handles=[red_patch, blue_patch])
    
    # Saving pic
    plt.savefig(pic_absolute)
