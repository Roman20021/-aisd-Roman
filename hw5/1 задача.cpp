using namespace std;
#include <iostream>

class List {
public:
	void show(int*& arr, int& size) {
		for (int i = 0; i < size; i++) {
			cout << arr[i] << ' ';
		}
		cout << endl;

	}

	int get(int id, int*& arr) {
		return arr[id];
	}
	void remove(int*& arr, int& size, int number) {
		int k = 0;
		int v = 0;
		int* newarr = new int[size];
		for (int i = 0; i < size; i++) {
			if (number == arr[i] and v == 0) {
				v++;
				i++;

			}
			newarr[k] = arr[i];
			k++;
		}
		size--;
		delete[] arr;
		arr = newarr;

	}
	void fill(int *arr,int size ){
		for (int i = 0; i < size; i++) {
			arr[i] = rand() % 10;
		}
	}
	void append(int number, int*& arr, int& size) {

		int v = 0;
		int* newarr = new int[size + 1];
		for (int i = 0; i < size; i++) {
			newarr[i] = arr[i];
		}
		if (number < arr[size - 1]) {
			for (int i = 0; i <= size; i++) {
				if (number < newarr[i] and v == 0) {
					v++;
					newarr[i] = number;
					i++;

				}
				if (v == 1) {
					newarr[i] = arr[i - 1];
				}
			}
		}
		if (number > arr[size - 1]) {
			newarr[size] = number;
		}
		 size++;
		 delete[] arr;
		 arr = newarr;

	}

	void sort(int*& arr, int size) {
		for (int i = 0; i < size - 1; i++) {
			for (int j = 0; j < size - i - 1; j++) {
				if (arr[j] > arr[j + 1]) {
					int с = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = с;
				}
			}
		}
	}
};

int main()
{
	List list;
	int size = 3;
	int* pt = &size;
	int* arr = new int[size];
	list.fill(arr, size);
	list.show(arr, size);
	list.sort(arr, size);
	list.show(arr, size);
	list.append(99, arr, size);
	list.show(arr, size);
	list.remove(arr, size,1);
	list.show(arr, size);
	
	delete[] arr;
}