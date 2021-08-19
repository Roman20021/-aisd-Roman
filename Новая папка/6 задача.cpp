#include <vector>
#include <iostream>
using namespace std;
int k = 0;
bool start = false;
int depth = 0;
struct QuadTreeNode {
    vector<vector<int>> array;
    QuadTreeNode* leftnode = NULL;
    QuadTreeNode* rightnode = NULL;
    QuadTreeNode* upnode = NULL;
    QuadTreeNode* bottomnode = NULL;
};
struct point {
    int x;
    int y;
};
void building(int x, int y, int mindepth, QuadTreeNode*& MyTree) {
    if (k == 0) {
        MyTree = new  QuadTreeNode;
        k++;
        return;
    }
    if (not start) {
        MyTree->array.push_back({ x, y });
    }
    else {
        
        QuadTreeNode* leftnode;
        leftnode = new QuadTreeNode;
        QuadTreeNode* rightnode;
        rightnode = new QuadTreeNode;
        QuadTreeNode* upnode;
        upnode = new QuadTreeNode;
        QuadTreeNode* bottomnode;
        bottomnode = new QuadTreeNode;
        MyTree->leftnode = leftnode;
        MyTree->rightnode = rightnode;
        MyTree->upnode = upnode;
        MyTree->bottomnode = bottomnode;
        if (MyTree->array.size() >= 4) {
            if (MyTree->array.size() % 4 == 0) {

                int size = MyTree->array.size() / 4;
                for (int i = 0; i < size; i++) {
                    leftnode->array.push_back(MyTree->array[i]);
                }
                for (int i = size; i < 2 * size; i++) {
                    rightnode->array.push_back(MyTree->array[i]);
                }
                for (int i = size * 2; i < 3 * size; i++) {
                    upnode->array.push_back(MyTree->array[i]);
                }
                for (int i = size * 3; i < 4 * size; i++) {
                    bottomnode->array.push_back(MyTree->array[i]);
                }
                MyTree->array.clear();
            }
            else {
                int size = MyTree->array.size() / 4;
                for (int i = 0; i < size; i++) {
                    leftnode->array.push_back(MyTree->array[0]);
                    MyTree->array.erase(MyTree->array.begin());
                }
                for (int i = 0; i < size; i++) {
                    rightnode->array.push_back(MyTree->array[0]);
                    MyTree->array.erase(MyTree->array.begin());
                }
                for (int i = 0; i < size; i++) {
                    upnode->array.push_back(MyTree->array[0]);
                    MyTree->array.erase(MyTree->array.begin());
                }
                size = MyTree->array.size();
                for (int i = 0; i < size; i++) {
                    bottomnode->array.push_back(MyTree->array[0]);
                    MyTree->array.erase(MyTree->array.begin());
                }
            }
        }
        else {
            if (MyTree->array.size() == 1) {
                leftnode->array.push_back(MyTree->array[0]);
                QuadTreeNode* rightnode = NULL;
                QuadTreeNode* upnode = NULL;
                QuadTreeNode* bottomnode = NULL;
            }
            if (MyTree->array.size() == 2) {
                leftnode->array.push_back(MyTree->array[0]);
                rightnode->array.push_back(MyTree->array[1]);
                QuadTreeNode* upnode = NULL;
                QuadTreeNode* bottomnode = NULL;

            }
            if (MyTree->array.size() == 3) {
                leftnode->array.push_back(MyTree->array[0]);
                rightnode->array.push_back(MyTree->array[1]);
                upnode->array.push_back(MyTree->array[2]);
                QuadTreeNode* bottomnode = NULL;
            }
            MyTree->array.clear();
        }
        if (leftnode != NULL) {
            depth++;
            if (depth < mindepth -1 ) {
                building(NULL, NULL, mindepth, leftnode);
            }
            else {
                depth--;
                depth--;
                return;
            }
        }
        if (rightnode != NULL) {
            depth++;
            if (depth < mindepth - 1 ) {
                building(NULL, NULL, mindepth, rightnode);
            }
            else {
                depth--;
                depth--;
                return;
            }
        }
        if (upnode != NULL) {
            depth++;
            if (depth < mindepth - 1 ) {
                building(NULL, NULL, mindepth, upnode);
            }
            else {
                depth--;
                depth--;
                return;
            }
          
        }
        if (bottomnode != NULL) {
            depth++;
            if (depth < mindepth -1 ) {
                building(NULL, NULL, mindepth, bottomnode);
            }
            else {
                depth--;
                depth--;
                return;
            }
           
        }

        depth--;
        return;
    }
    
}


int main() {
    setlocale(LC_ALL, "Russian");
    int square_length;
    cout << "Введите длину квадрата";
    cin >> square_length;
    int mindepth;
    cout << "Введите максимальную глубину квадрата";
    cin >> mindepth;
    int N;
    cout << "Введите количество точек";
    cin >> N;
    point* Point;
    Point = new point;
    int number;
    QuadTreeNode* Tree = NULL;
    building(NULL, NULL, mindepth, Tree);
    for (int i = 0; i < N; i++)
    {
        cin >> number;
        Point->x = number;
        cin >> number;
        Point->y = number;
        if (Point->x <= square_length and Point->y <= square_length) {
            building(Point->x, Point->y, mindepth, Tree);
        }
        if (i == N - 1) {
            start = true;
        }
    }
    building(NULL, NULL, mindepth, Tree);
    cout << "Построение закончено";
}