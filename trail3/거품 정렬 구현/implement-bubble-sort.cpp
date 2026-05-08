#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int* elements = new int[n];
	for (int i{ 0 }; i < n; i++) {
		cin >> elements[i];
	}
	bool sorted= true;
	do {
		sorted= true;
		for (int i{ 0 }; i < n - 1; i++) {
			if (elements[i] > elements[i + 1]) {
				int tmp{ elements[i] };
				elements[i] = elements[i + 1];
				elements[i + 1] = tmp;
				sorted = false;
			}
		}

	} while (sorted == false);

	for (int i{ 0 }; i < n;i++) {
			cout << elements[i] << " ";
	}

    delete[] elements;
	return 0;
}