#include "headers/blur.h"

using namespace std;

vector < vector <float> > blur(vector < vector < float> > &grid, float blurring) {

	float center = 1.0 - blurring;
	float corner = blurring / 12.0;
	float adjacent = blurring / 6.0;
  
  	vector < vector <float> > window = {{corner, adjacent, corner},
                                        {adjacent, center, adjacent},
                                        {corner, adjacent, corner}};

	static vector <int> DX = {-1, 0, 1};
	static vector <int> DY = {-1, 0, 1};

	int i, j, ii, jj, new_i, new_j;
  	int height = grid.size();
	int width = grid[0].size();

	// OPTIMIZATION: Use your improved zeros function
	vector < vector <float> > newGrid(height, vector <float> (width, 0.0));

	for (i=0; i< height; i++ ) {
		for (j=0; j<width; j++ ) {

			for (ii=0; ii<3; ii++) {
				for (jj=0; jj<3; jj++) {
					new_i = (i + DY[ii] + height) % height;
					new_j = (j + DX[jj] + width) % width;

					newGrid[new_i][new_j] += grid[i][j] * window[ii][jj];
				}
			}
		}
	}

	return newGrid;
}
