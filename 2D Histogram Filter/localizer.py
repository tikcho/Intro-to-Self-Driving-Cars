import pdb
from helpers import normalize, blur

def initialize_beliefs(grid):
    height = len(grid)
    width = len(grid[0])
    area = height * width
    belief_per_cell = 1.0 / area
    beliefs = []
    for i in range(height):
        row = []
        for j in range(width):
            row.append(belief_per_cell)
        beliefs.append(row)
    return beliefs

def sense(color, grid, beliefs, p_hit, p_miss):
    new_beliefs = []
    new_beliefs_line = []
    s = 0
    #
    # TODO - implement this in part 2
    #
    for i in range(len(beliefs)):
        for ii in range(len(beliefs[0])):
            hit = (color == grid[i][ii])
            new_beliefs_line.append(beliefs[i][ii] * (hit * p_hit + (1-hit) * p_miss))
        s += sum(new_beliefs_line) 
        new_beliefs.append(new_beliefs_line)
        new_beliefs_line = []
    
    for j in range(len(new_beliefs)):
        for jj in range(len(new_beliefs[j])):
            new_beliefs[j][jj] = new_beliefs[j][jj] / s

    return new_beliefs

def move(dy, dx, beliefs, blurring):
    height = len(beliefs)
    width = len(beliefs[0])
    new_G = [[0.0 for i in range(width)] for j in range(height)]
    for i, row in enumerate(beliefs):
        for j, cell in enumerate(row):
            new_i = (i + dy ) % width
            new_j = (j + dx ) % height
#             pdb.set_trace()
            new_G[int(new_j)][int(new_i)] = cell
    return blur(new_G, blurring)