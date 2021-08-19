#include <vector>
#include <iostream>
using namespace std;

vector<int> Delete(vector<int>& tree) {
    for (int i = 0; i < tree.size(); i++) {
        if (2 * i + 2 > tree.size() - 1) {
            tree[i] = tree[tree.size() - 1];
            break;

        }
    }
    tree.pop_back();
    return tree;
}



int main()
{
    setlocale(LC_ALL, "Russian");
    int len;
    int number;
    cout << "Введите количество чисел в дереве";
    cin >> len;
    vector<int> tree;
    cout << "Заполните дерево";
    for (int r = 0; r < len; r++) {
        cin >> number;
        tree.push_back(number);
    }
    if (tree.size() % 2 == 0) {
        tree = Delete(tree);
    }
    for (int i = 0; i < tree.size(); i++) {
        cout << tree[i] << ' ';
    }
}
