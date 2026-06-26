#include <iostream>
#include <vector>
using namespace std;

vector<int> findPeakGrid(vector<vector<int>>& mat) {
    int n = mat.size();
    int m = mat[0].size();

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int curr = mat[i][j];
            bool isPeak = true;

            // check top
            if (i > 0 && mat[i - 1][j] > curr)
                isPeak = false;

            // check bottom
            if (i + 1 < n && mat[i + 1][j] > curr)
                isPeak = false;

            // check left
            if (j > 0 && mat[i][j - 1] > curr)
                isPeak = false;

            // check right
            if (j + 1 < m  && mat[i][j + 1] > curr)
                isPeak = false;

            if (isPeak)
                return {i, j};
        }
    }

    return {-1, -1};
}


int main() {
    vector<vector<int>> mat = {
        {10, 20, 15},
        {21, 30, 14},
        {7, 16, 32}
    };

    vector<int> peak = findPeakGrid(mat);
    cout << peak[0] << " " << peak[1] << endl;
    return 0;
}