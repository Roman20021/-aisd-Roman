#include <vector>
#include <iostream>
using namespace std;
int tabs = 0;
struct TreeNode {
    int val = 0;
    TreeNode* left = NULL;
    TreeNode* right = NULL;
    TreeNode* array = NULL;
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

void finding_way(TreeNode*& root, int x, vector<int>& array) {
   
    if (root == NULL) {
       
        return;
    }
    if (root->val == x) {
        array.push_back(root->val);
        while (root->array != NULL) {
            root = root->array;
            array.push_back(root->val);
        }
        
        return;
    }
    finding_way(root->left, x, array);
    finding_way(root->right, x, array);
}


int main()
{
    setlocale(LC_ALL, "Russian");
    TreeNode* root;
    root = new TreeNode;
    root->val = 0;
    root->left = new TreeNode;
    root->left->array = new TreeNode;
    root->left->val = 1;
    root->left->array = root;
    root->right = new TreeNode;
    root->right->array = new TreeNode;
    root->right->val = 4;
    root->right->array = root;
    root->left->left = new TreeNode;
    root->left->left->array = new TreeNode;
    root->left->left->val = 2;
    root->left->left->array = root->left;
    root->left->right = new TreeNode;
    root->left->right->array = new TreeNode;
    root->left->right->array = root->left;
    root->left->right->val = 3;
    root->right->left = new TreeNode;
    root->right->left->array = new TreeNode;
    root->right->left->array = root->right;
    root->right->left->val = 1;
    root->right->right = new TreeNode;
    root->right->right->array = new TreeNode;
    root->right->right->val = 8;
    root->right->right->array = root->right;
    vector<int> array;
    int number;
    show(root);
    cout << "Какое число хотите найти?";
    cin >> number;
    finding_way(root, number, array);
    if(array.size() == 0){
        cout << "Такого нет числа";
    }
    else {
        for (int i = array.size() - 1; i >= 0; i--)
        {
            cout << array[i] << ' ';
        }
        cout << endl;
    }

}
