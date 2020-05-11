#include "headers/normalize.h"
using namespace std;

vector< vector<float> > normalize(vector< vector <float> > &grid) {
	float total = 0.0;
	int i, j;

	for (i = 0; i < grid.size(); i++) {
		for (j=0; j< grid[0].size(); j++) {
			total += grid[i][j];
		}
	}

	for (i = 0; i < grid.size(); i++) {
		for (j=0; j< grid[0].size(); j++) {
          	grid[i][j] = grid[i][j] / total;
		}
	}

	return grid;
}
