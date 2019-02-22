#include <iostream>
#include <algorithm>

using namespace std;

void print_array(int *A, int len){
    for(int i = 0; i< len; ++i)
        cout << A[i] << '\t';
}

void insert(int *A, int len){
    int key = A[len-1];
    int i = len - 2;
    while (i != -1 && A[i] > key) {
        A[i+1] = A[i];
        --i;
    }
    A[i+1] = key;
}

/*We can express insertion sort as a recursive procedure as follows. In order to sort A[0..n],
 * we recursively sort A[0..n-1] and then insert A[n] into the sorted array A[1..n-1]. Write
 * a recurrence for the running time of this recursive version of insertion sort.*/

void insert_sort(int *A, int len){
    if(len > 1){
        insert_sort(A, len-1);
        insert(A, len);
    }
}


int main()
{
    int ta[] = {-34, 233, -4, 23, 16, 45, 92, 8, 123, 0, 76, 34, 123, -2, 56};  // test array
    int arr_size = sizeof (ta)/sizeof (int); // compute the size of array

    int *tb = new int[arr_size];
    copy(ta, ta+arr_size, tb);   // make a copy of the array to compare

    // unsorted array
    print_array(ta, arr_size);
    cout << endl;
    insert_sort(ta, arr_size);
    // sorted array
    print_array(ta, arr_size);
    cout << endl;
    // sort using lib facilities
    sort(tb, tb+arr_size);
    print_array(tb, arr_size);
    cout << endl;

    delete [] tb;
    return 0;
}
