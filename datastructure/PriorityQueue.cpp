#include <iostream>
#include <vector>

int heap[500], heapsize;

void init() {
	heapsize = 0;
}

void push(int item) {
	heap[heapsize++] = item;

	int tmp, ptr = heapsize-1;
	while (ptr != 0 && heap[(ptr - 1) / 2] > heap[ptr]) {
		tmp = heap[(ptr - 1) / 2];
		heap[(ptr - 1) / 2] = heap[ptr];
		heap[ptr] = tmp;
		ptr = (ptr - 1) / 2;
	}
}

int pop() {
	int item = heap[0];
	heap[0] = heap[--heapsize];

	int tmp, child, ptr = 0;
	while (ptr * 2 + 1 < heapsize) {
		if (ptr * 2 + 2 == heapsize)
			child = ptr * 2 + 1;
		else
			child = (heap[ptr * 2 + 1] < heap[ptr * 2 + 2]) ? (ptr * 2 + 1) : (ptr * 2 + 2);

		if (heap[ptr] < heap[child])
			break;

		tmp = heap[ptr];
		heap[ptr] = heap[child];
		heap[child] = tmp;
		ptr = child;
	}
	return item;
}

std::vector<int> v = { 1,8,2,6754,24,3,5687,41,8697,3,-1234,-123,123,-123,463,5,7,1231,312 };

int main()
{
	while (v.size()) {
		push(v.back());
		v.pop_back();
	}
	while (heapsize) {
		std::cout << pop() << ' ';
	}
	std::cout << std::endl;
}

