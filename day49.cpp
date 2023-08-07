//74. Search a 2D Matrix
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int row = 0, col = matrix[0].size() - 1; // Start from the top right corner
    while (row < matrix.size() && col >= 0) {
        if (matrix[row][col] == target) {
            return true; // Found the target value
        } else if (matrix[row][col] < target) {
            row++; // Eliminate the current row
        } else {
            col--; // Eliminate the current column
        }
    }
    return false; // Target value not found in the matrix
}

};
