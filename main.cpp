#include <iostream>
#include <sortlib.h>

using namespace std;

int main() {
    vector<int> input {6, 5, 3, 1, 8, 7, 2, 4};
    quicksort(input, 0, input.size() - 1);
    for ( const auto& index : input )
	cout << index << " ";
    cout << endl;
}
