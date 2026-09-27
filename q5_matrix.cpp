//Eman Siddiqui CT-25072
#include <iostream>
#include <vector>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    // Edge case: check if the matrix is empty
    if (matrix.empty() || matrix[0].empty()) {
        return false;
    }

    int rows = matrix.size();
    int cols = matrix[0].size();

    
    int left = 0;
    int right = (rows * cols) - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;


        int midRow = mid / cols;
        int midCol = mid % cols;

        int midValue = matrix[midRow][midCol];

        if (midValue == target) {
            return true; // Target found
        } 
        else if (midValue < target) {
            left = mid + 1; // Search the right half
        } 
        else {
            right = mid - 1; // Search the left half
        }
    }

    return false; // Target not found
}

int main() {
    
    vector<vector<int>> matrix = {
        {1,  3,  5,  7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };

    int target1 = 3;
    int target2 = 13;

    cout << "Search 3: " << (searchMatrix(matrix, target1) ? "true" : "false") << endl;
    cout << "Search 13: " << (searchMatrix(matrix, target2) ? "true" : "false") << endl;

    return 0;
}
