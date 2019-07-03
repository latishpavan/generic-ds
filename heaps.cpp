#include "heaps.h"
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	float arr[] = {2.1, -5.2, -1.5, 10.1, 11.2};
	MinHeap<float> *heap = new MinHeap<float>(5, arr);
	heap->decrease_key(2, -10.2);
	for(int i=0;i<5;i++)
		cout << heap->extract_min() << endl;
}