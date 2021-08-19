#include <vector>
#include <iostream>
using namespace std;
int X0;
int X1;
int Y1;
int Y0;
int i = 0;
int mindist;
void getmindist(int x0, int y0, int x1, int y1) {
	int x = x1 - x0;
	int y = y1 - y0;
	int p = x * x + y * y;
	int dist = sqrt(p);
	if (i == 0) {
		X0 = x0;
		X1 = x1;
		Y0 = y0;
		Y1 = y1;
		mindist = dist;
	}
	i++;
	if (dist < mindist) {
		X0 = x0;
		X1 = x1;
		Y0 = y0;
		Y1 = y1;
		mindist = dist;
	}
}
void GetSmallestDistanceBetweenFields(int space[10][2]) {
	int m = 10 / 2;
	int midPoint = space[m][0];
	int spacepoint[10][2];
	int j = 0;
	for (int i = 0; i < 10; i++) {
		if (abs(space[i][0] - midPoint) < mindist) {
			spacepoint[j][0] = space[i][0];
			spacepoint[j][1] = space[i][1];
			j++;
		}
	}

	for (int i = 0; i < j - 1; i++) {
		for (int c = 0; c < j - i - 1; c++) {
			if (spacepoint[c][1] > spacepoint[c + 1][1]) {
				swap(spacepoint[c], spacepoint[c + 1]);
			}
		}
	}
	for (int i = 0; i < j; ++i) {
		for (int c = i + 1; c < j && (spacepoint[i][1] - spacepoint[i][1]) < mindist; ++c) {
			getmindist(spacepoint[i][0], spacepoint[i][1], spacepoint[c][0], spacepoint[c][1]);
		}
	}
}
void GetGestGmallestDistance(int space[10][2], int l, int r) {
	if (r - l <= 3) {
		for (int i = l; i <= r; ++i) {
			for (int j = i + 1; j <= r; ++j) {
				getmindist(space[i][0], space[i][1], space[j][0], space[j][1]);
			}
		}
		return;
	}
	int m = (l + r) / 2;
	int midx = space[m][0];
	GetGestGmallestDistance(space, l, m);
	GetGestGmallestDistance(space, m + 1, r);
}

int main() {
	int number;
	const unsigned int DIM1 = 10;
	const unsigned int DIM2 = 2;
	int space[DIM1][DIM2];
	for (int i = 0; i < DIM1; i++) {
		for (int j = 0; j < DIM2; j++) {
			cin >> number;
			space[i][j] = number;
		}
	}

	for (int i = 0; i < DIM1 - 1; i++) {
		for (int j = 0; j < DIM1 - i - 1; j++) {
			if (space[j][0] > space[j + 1][0]) {
				swap(space[j], space[j + 1]);
			}
		}
	}

	GetGestGmallestDistance(space, 0, 9);
	GetSmallestDistanceBetweenFields(space);
	cout << "X0, Y0:";
	cout << X0 << " " << Y0;
	cout << endl;
	cout << "X1, Y1:";
	cout << X1 <<" "<< Y1;
	cout << endl;
	cout << "dist:"<<mindist;
}
