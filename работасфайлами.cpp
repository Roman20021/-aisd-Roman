#include <fstream>
#include <vector>
#include <iostream>
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <windows.h>

int k = 0;
int y = 0;
using namespace std;
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
    if (le.size() != 0) {
        vector<int> p = QuickSort(le, le.size());
        y++;
        for (int r = 0; r < p.size(); r++) {
            end.push_back(p[r]);
        }
    }

    for (int r = 0; r < middle.size(); r++) {
        end.push_back(middle[r]);
    }

    if (mo.size() != 0) {
        vector<int> k = QuickSort(mo, mo.size());
        y++;
        for (int r = 0; r < k.size(); r++) {
            end.push_back(k[r]);
        }

    }



   
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
        k++;
        arr[array[r]] += 1;
    }
    int i = 0;
    for (int j = 0; j < max; j++) {
        k++;
        while (arr[j] != 0) {
            array[i] = j;
            arr[j]--;
            i++;
        }
    }

    return *array;
}

void out(vector<int>& array, int* arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }
}

int* Reading(int* arrayNumb, int size, string path)
{
    int count = 0;
    string line;
    string text;
    ifstream in(path);

    if (in.is_open())
    {
        while (getline(in, line))
        {
            long int number = stoi(line);
            arrayNumb[count] = number;
            count++;
        }
    }
    in.close();
    return arrayNumb;
}


int main()
{
    setlocale(LC_ALL, "Russian");
    vector<int> arr;
    int len;
    cout << "введите количества чисел в файле";
    cin >> len;
    int* array = new int[len];
    int number = 0;
    string path = "C:\\HW с++\\txt.txt";
    setlocale(LC_ALL, "Russian");
    array = Reading(array, len, path);
    for (int i = 0; i < len; i++)
    {
        arr.push_back(array[i]);
    }
    float start_time = clock();
    arr = QuickSort(arr, arr.size());
    float end_time = clock();
    cout << end_time - start_time <<" - время работы QuickSort"<< endl;
    start_time = clock();
    *array = count_sort(array, len);
    end_time = clock();
    cout << end_time - start_time << " - время работы count_sort" << endl;

    cout << endl;
    cout << "Кол-во итераций в  QuickSort: " << y;
    y = 0;
    cout << endl;
    cout << "Кол-во итераций в сортировке подсчетом: " << k;
    k = 0;
    return 0;
}