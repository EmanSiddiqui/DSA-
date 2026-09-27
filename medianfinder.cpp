//Eman Siddiqui CT-25072
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class MedianFinder{
private:
    vector<int> nums;  

public:
    MedianFinder(){
    }

    void addNum(int num) {
        nums.push_back(num);
    }

    double findMedian() {
        
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());

        int n = sorted.size();

        // If odd size, return middle element
        if(n % 2 == 1) {
            return sorted[n / 2];
        }
        // If even size, return average of two middle elements
        else {
            int mid1 = sorted[(n / 2) - 1];
            int mid2 = sorted[n / 2];
            return (mid1 + mid2) / 2.0;
        }
    }
};

int main() {
    MedianFinder medianFinder;

    medianFinder.addNum(1);
    medianFinder.addNum(2);
    cout << "Median after adding 1, 2: " << medianFinder.findMedian() << endl;

    medianFinder.addNum(3);
    cout << "Median after adding 3: " << medianFinder.findMedian() << endl;

    return 0;
}
