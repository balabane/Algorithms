#include <iostream>

using namespace std;

int main(){

    int a[] = {34, 32, 54, 14, 96, 45, 76, 31, 5, 97, 39, 4, 1, 190};
    const int size_a = sizeof (a)/sizeof (a[0]);

// print unsorted array
    cout << "unsorted: ";
    for (int i = 0; i < size_a; ++i)
        cout << a[i] << '\t';

// sort array by using selection sort
    for (int i = 0; i < size_a; ++i){
        int smallest_index = i;
        for (int j = i + 1; j < size_a; ++j) {
            if(a[j] < a[smallest_index])
                smallest_index = j;
        }
        int temp = a[i];
        a[i] = a[smallest_index];
        a[smallest_index] = temp;
    }

// print sorted array
    cout << endl << "sorted: ";
    for (int i = 0; i < size_a; ++i)
        cout << a[i] << '\t';

    cout << endl;
    return 0;
}
