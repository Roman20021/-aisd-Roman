#include <vector>
#include <iostream>
using namespace std;

int y = 0;
vector<int> QuickSort(std::vector<int>& array, int len) {
    if (len == 1) {
        return array;
    }
 
    int mid = len / 2;
    vector<int> le;
    vector<int> mo;
    vector<int> middle;
    for (int i = 0; i < len; i++) {
        if (array[i] < array[mid]) {
            le.push_back(array[i]);
        }
        if (array[i] == array[mid]) {
            middle.push_back(array[i]);
        }
        if (array[i] > array[mid]) {
            mo.push_back(array[i]);
        }
    }
    vector<int> end;
    if (le.size() != 0){
        vector<int> p = QuickSort(le, le.size());
        for (int r = 0; r < p.size(); r++) {
            end.push_back(p[r]);
        }
    }
        
    for (int r = 0; r < middle.size(); r++) {
        end.push_back(middle[r]);
    }

    if (mo.size() != 0) {
        vector<int> k = QuickSort(mo, mo.size());
        for (int r = 0; r < k.size(); r++) {
            end.push_back(k[r]);
        }

    }

    
    
    y++;
    return end;

}

int Max(int arr[], int len) {
    int max = arr[0];
    for (int i = 0; i < len; ++i) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int count_sort(int array[], int len) {
    int max = Max(array, len) + 1;
    int* arr = new int[max];
    for (int r = 0; r < max; r++) {
        arr[r] = 0;
    }
    for (int r = 0; r < len; r++) {
        arr[array[r]] += 1;
    }
    int i = 0;
    for (int j = 0; j < max; j++) {
        while (arr[j] != 0) {
            array[i] = j;
            arr[j]--;
            i++;
        }
    }
    
    return *array;
}

void out(vector<int>& array ,int* arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "- сортировка подсчетом";
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }
    cout << "- быстрая сортировка";

}



int main()
{
    setlocale(LC_ALL, "Russian");
    int number;
    vector<int> arr;
    int len;
    cout << "Введите размер масива";
    cin >> len;
    int* array = new int[len];
    cout << "Заполните массив";
    for (int r = 0; r < len; r++) {
        cin >> number;
        arr.push_back(number);
        array[r] = number;
    }
    arr = QuickSort(arr, arr.size());
    *array = count_sort(array, len);
    out(arr, array, len);
    cout << endl;
    cout << "Кол-во итераций : "<<y;
    y = 0;

    return 0;
}