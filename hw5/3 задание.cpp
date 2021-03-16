
using namespace std;
#include <iostream>

void Union(int *&arr1, int *&arr2, int& size1, int& size2){
    bool flag = true;
    for (int i = 0; i < size2; i++) {
        for (int b = 0; b < size1; b++) {
            if (arr1[b] == arr2[i]) {
                flag = false;
            }
            }
        if (flag) {
            arr1[size1] = arr2[i];
            size1++;

        }
        flag = true;
        }

}

void Crossing(int*& arr1, int*& arr2, int& size1, int& size2) {
    int k = 0;
    int* newarr1 = new int(k);
    for (int i = 0; i < size2; i++) {
        for (int b = 0; b < size1; b++) {
            if (arr1[b] == arr2[i]) {
                arr1[k] = arr2[i];
        
            }

        }
        
    }

 

    
}
void Difference(int*& arr1, int*& arr2, int& size1, int& size2) {
    int k = 0;
    int* newarr1 = new int(size1);
    bool flag = true;
    for (int i = 0; i < size1; i++) {
        for (int b = 0; b < size1; b++) {
            if (arr1[i] == arr2[b]) {
                flag = false;
            }
        }
        if (flag) {
            newarr1[k] = arr1[i];
            k++;
        }
    
    }
    size1 = k;
    arr1 = newarr1;

}

int main()
{
    int size1;
    int size2;
    cout << "the number of digits in the first array";
    cin >> size1;
    cout << "the number of digits in the  second array";
    cin >> size2;
    cout << "fill the first array";
    int* arr1 = new int(size1);
    int* arr2 = new int(size2);
    for (int i = 0; i < size1; i++) {
        cin >> arr1[i];
    }
    cout << "fill the second array";
    for (int i = 0; i < size2; i++) {
        cin >> arr2[i];
    }

 
    Union(arr1, arr2, size1, size2);
 
 
    for (int i = 0; i < size1; i++) {
        cout << arr1[i] << ' ';
    }


    delete arr1;
    delete arr2;

}