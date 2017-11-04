#ifndef __SORTLIB_H_
#define __SORTLIB_H_

#include <vector>
using std::vector;

template <class T>
void swapXor(T& a, T& b) {
    if (a != b)
	a ^= b ^= a ^= b;
}

template <class T>
void quicksort(vector<T>& input, int start, int end);

#endif /* __SORTLIB_H_ */
