#include <iostream>   
#include <math.h>

using namespace std;       

int main()                        
{          
    int x;
    int y;
    int c;
    for (int i = 0; i++) {
        y = pow(x, i);
            if (y > x) {
                c = i;
                break
        }
    }
    cout << pow(x, c - 1);
}                              
