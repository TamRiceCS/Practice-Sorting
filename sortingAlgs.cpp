#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
    Selection Sort
        start from the front of the array and find the min val
        switch min value with start
        increment start
        repeat until start = size-1
*/

void selection(vector<int> nums) {
    cout << "\nSelection sort (n^2): " << endl;

    int min = 0;
    for(int i = 0; i < nums.size()-1; i++) {
        for(int j = i; j < nums.size(); j++) {
            if(nums[j] <= nums[min]) {
                min = j;
            }
        }

        swap(nums[min], nums[i]);
        int min = i;
    }

    for(auto elem : nums) {
        cout << elem << " ";
    }
}

/*
    Bubble Sort
        // starting from the front traveling to the end
        // swap the bigger number "forward"
        // decrement the end, the last pos is sorted
*/

void bubble(vector<int> nums){

    cout << "\nBubble sort (n^2): " << endl;

    for(int i = 0; i < nums.size(); i++) {
        for(int j = i+1; j < nums.size(); j++) {
            if(nums[i] > nums[j]) {
                swap(nums[i], nums[j]);
            }
        }
    }

    for(auto elem : nums) {
        cout << elem << " ";
    }
}

/*
    Insertion Sort
        Iter through elems, compare it w/ the prior val
        Swap down curr index until it is no longer the smallest val or reaches start
          compare starts at i and will decrement by 1 for every swap, also have curr index follow the value you swapped down.
*/
void insertion(vector<int> nums) {
    cout << "\nInsertion sort (n^2): " << endl;


    for(int i = 0; i < nums.size(); i++) {
        int compare = i;
        for(int j = i - 1; j > -1; j--) {
            if(nums[compare] < nums[j]) {
                swap(nums[compare], nums[j]);
                compare--;
            }
        }
    }

    for(auto elem : nums) {
        cout << elem << " ";
    }
}


/*
    Merge Sort
        Based on a partition split the array into halves until it can no longer be split
        Sort each half
        merge sorted halves
*/


vector<int> merge(vector<int>& leftSide, vector<int>& rightSide, vector<int>& nums) {
    
    // get where legt and right side of original is
    int left = nums.size()/2;
    int right = nums.size() - left;

    // indexes to keep track of in each vector
    int orig = 0;
    int l = 0;
    int r = 0;

    // go through picking the lesser of evils
    while(l < left && r < right) {
        if(leftSide[l] < rightSide[r]) {
            nums[orig] = leftSide[l];
            l++;
        }
        else{
            nums[orig] = rightSide[r];
            r++;
        }
        orig++;
    }

    // in cases where there are leftovers
    while(l < left) {
        nums[orig] = leftSide[l];
        l++;
        orig++;
    }
    while(r < right) {
        nums[orig] = rightSide[r];
        r++;
        orig++;
    }

    return nums;

}

void mergeSort(vector<int>& nums) {

    if(nums.size() <= 1) {
        return;
    }

    int mid = nums.size()/2; // find mid

    // create our left and right vectors
    vector<int> leftSide;
    vector<int> rightSide;

    for(int i = 0; i < mid; i++ ) {
        leftSide.push_back(nums[i]);
    }

    for(int i = mid; i < nums.size(); i++) {
        rightSide.push_back(nums[i]);
    }

    mergeSort(leftSide); // go down left side
    mergeSort(rightSide); // go down right side
    nums = merge(leftSide, rightSide, nums);
}

int main() {

    cout << "Let's practice coding sorting algorithms..." << endl;

    cout << "Built in sort (n log n): " << endl;

    vector<int> nums = {10, 8 , 7, 6, 3, 4, 2, 1, 5, 9};
    sort(nums.begin(), nums.end());

    for(auto elem : nums) {
        cout << elem << " ";
    }

    nums = {10, 8 , 7, 6, 3, 4, 2, 1, 5, 9};

    selection(nums);
    bubble(nums);
    insertion(nums);

    mergeSort(nums);
    cout << "\nMerge sort (n log n): " << endl;

    for(auto elem : nums) {
        cout << elem << " ";
    }
}