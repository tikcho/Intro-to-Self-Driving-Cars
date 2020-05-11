#include "headers/sense.h"

using namespace std;

vector< vector <float> > sense(char color, vector< vector <char> > &grid, vector< vector <float> > &beliefs,  float p_hit, float p_miss) 
{
	int i, j, height, width;
	height = grid.size();
	width = grid[0].size();

	for (i=0; i<height; i++) {
		for (j=0; j<width; j++) {
			if (grid[i][j] == color) {
				beliefs[i][j]  = beliefs[i][j] * p_hit;
			}
			else {
				beliefs[i][j]  = beliefs[i][j] * p_miss;
			}
		}
	}
	return beliefs;
}
