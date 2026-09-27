//Eman Siddiqui CT-25072
#include <iostream>
#include <vector>
using namespace std;


int search(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;

    
    while(left <= right) {
        // Find middle index
        int mid = left + (right - left) / 2;

        // Check if target is found
        if(nums[mid] == target) {
            return mid;
        }
        // If target is smaller, search left half
        else if(nums[mid] > target) {
            right = mid - 1;
        }
        // If target is larger, search right half
        else {
            left = mid + 1;
        }
    }

    
    return -1;
}

int main() {
    // Test case 1
    vector<int> nums1 = {-1, 0, 3, 5, 9, 12};
    int target1 = 9;
    cout << "Array: [-1, 0, 3, 5, 9, 12]" << endl;
    cout << "Target: " << target1 << endl;
    cout << "Index: " << search(nums1, target1) << endl << endl;

    // Test case 2
    vector<int> nums2 = {-1, 0, 3, 5, 9, 12};
    int target2 = 2;
    cout << "Array: [-1, 0, 3, 5, 9, 12]" << endl;
    cout << "Target: " << target2 << endl;
    cout << "Index: " << search(nums2, target2) << endl;

    return 0;
    
}
