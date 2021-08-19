#include <vector>
#include <iostream>
using namespace std;
int tabs = 0;
struct TreeNode {
    int val = 0;
    TreeNode* left = NULL;
    TreeNode* right = NULL;
};


void show(TreeNode* Tree)
{
    if (!Tree) return;
    tabs++;
    show(Tree->left);
    for (int i = 0; i < tabs; i++) {
        cout << " ";
    }
    cout << Tree->val << endl;
    show(Tree->right);
    tabs--;
    return;
}

TreeNode building(vector<int>& array) {
    if (array.size() == 1) {
        TreeNode* root = NULL;
        root = new TreeNode;
        root->val = array[0];
        root->left = NULL;
        root->right = NULL;
        return *root;
    }
    if (array.size() == 0) {
        TreeNode* root = NULL;
        root = new TreeNode;
        return *root;
    }
    int centerIdx = array.size() / 2;
    TreeNode* root;
    root = new TreeNode;
    root->val = array[centerIdx];
    root->left = new TreeNode;
    vector<int> le;
    for (int i = 0; i < centerIdx; i++)
    {
        le.push_back(array[i]);
    }
    *root->left = building(le);
    vector<int> mo;
    for (int i = centerIdx + 1; i <= array.size() - 1; i++)
    {
        mo.push_back(array[i]);
    }
    root->right = new TreeNode;
    *root->right = building(mo);
    return *root;
}

int main() {
    setlocale(LC_ALL, "Russian");
    int len;
    int number;
    cout << "Введите размер масива";
    cin >> len;
    vector<int> array;
    cout << "Заполните массив";
    for (int r = 0; r < len; r++) {
        cin >> number;
        array.push_back(number);
    }
    TreeNode* root;
    root = new TreeNode;
    *root = building(array);
    show(root);
}