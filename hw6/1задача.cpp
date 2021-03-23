using namespace std;
#include <iostream>
struct Heap
{ 
    int* arr;
    int size;
    int maxsize;
   
    int Parent(int i) {
        return (i - 1) / 2;
    }

    void show() {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << ' ';
        }
        cout << endl;

    }

    int LeftChild(int i) {
        return (2 * i) + 1;
    }


    int RightChild(int i) {
        return (2 * i) + 2;
    }


    void SiftUp(int i) {
        while (i > 0 and arr[i] > arr[Parent(i)]) {
            swap(arr[Parent(i)], arr[i]);
            i = Parent(i);
        }

    }


    void SiftDown(int i) {
        int maxindex = i;

        if (arr[LeftChild(maxindex)] > arr[i] and LeftChild(i) < size) {
            maxindex = LeftChild(i);
        }
        if (arr[RightChild(i)] > arr[maxindex] and RightChild(i) < size) {
            maxindex = RightChild(i);
        }
        if (maxindex != i) {
            swap(arr[maxindex], arr[i]);
            SiftDown(maxindex);
        }
    }

    int ExtractMax() {
        int result = arr[0];
        arr[0] = arr[size - 1];
        size -= 1;
        maxsize -= 1;
        SiftDown(0);
        return result;
    }


    int GetMax() {
        return arr[0];
    }

    void insert(int num) {
        if (size < maxsize) {
            arr[size] = num;
            SiftUp(size);

        }
        if (size >= maxsize) {
            cerr << "переполнение памяти" << endl;
            size -= 1;

        }
        size += 1;



    }

    void Headsort() {
        int newsize = size;
        int newmaxsize = maxsize;
        int* newarr = new int[newmaxsize];
        for (int i = 0; i < newmaxsize; i++) {
            newarr[i] = ExtractMax();
        }
        delete[] arr;
        arr = newarr;
        maxsize = newmaxsize;
        size = newsize;
    }
}; 




int main()
{ 
    Heap pt;
    int maxsize;
    maxsize = 12;
    int size;
    setlocale(LC_ALL, "rus");
    size = 0;
    int* arr = new int[maxsize];
    pt.arr = arr;
    pt.size = size;
    pt.maxsize = maxsize;
    pt.insert(3);
    pt.insert(11);
    pt.insert(15);
    pt.insert(9);
    pt.insert(7);
    pt.insert(8);
    pt.insert(3);
    pt.insert(1);
    pt.insert(5);
    pt.insert(12);
    pt.insert(25);
    pt.insert(30);
    pt.insert(35);
    pt.show();
    cout << pt.GetMax() << endl;
    pt.Headsort();
    pt.show();
}