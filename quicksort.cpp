#include <iostream>
#include <vector>
#include <sortlib.h>

using std::vector;
using std::cout;
using std::endl;

template <class T>
void quicksort(vector<T>& input, int start, int end) {
    if (start >= end) return;
    int pivot = end, left = start, right = end - 1;

    while (true) {
	while (left < end && input.at(left) < input.at(pivot)) {
	    ++left;
	}
	while (right > start && input.at(right) >= input.at(pivot)) {
	    --right;
	}
	if (left >= right)
	    break;
	swapXor(input.at(left), input.at(right));
    }
    swapXor(input.at(left), input.at(pivot));
    quicksort(input, start, left - 1);
    quicksort(input, left + 1 , end);
    return;
}

template
void quicksort<int>(vector<int>& input, int start, int end);
