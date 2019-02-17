#include <iostream>
#include <limits>       // std::numeric_limits

using namespace std;

void merge(int *A, int p, int q, int r){
    int n1 = q-p+1;
    int n2 = r-q;
    int *L = new int[n1+1];
    int *R = new int[n2+1];

    for (int i = 0; i<n1; ++i)
        L[i] = A[p+i];
    for (int j = 0; j<n2; ++j)
        R[j] = A[q+j+1];

    L[n1] = std::numeric_limits<int>::max();
    R[n2] = std::numeric_limits<int>::max();
    int i = 0;
    int j = 0;

    for (int k = p; k <= r ;++k) {
        if(L[i] <= R[j]){
            A[k] = L[i];
            ++i;
        } else{
            A[k] = R[j];
            ++j;
        }
    }

    delete [] L;
    delete [] R;
}

void merge_sort(int *A, int p, int r){
    if(p < r){
        int q = (p+r)/2;
        merge_sort(A, p, q);
        merge_sort(A, q+1, r);
        merge(A, p, q, r);
    }
}

int main()
{
    int ta[] = {12, 2, 56, 3, 7, 9, 20, 5, 12, 17, 29, 0, 89, 27, 34, -21, 98, 11, 5, 28};
    int ta_size = sizeof (ta)/sizeof (int);

    for(int i = 0; i< ta_size; ++i)
        cout << ta[i] << '\t';
    cout << endl;

    merge_sort(ta, 0,  ta_size-1);

    for(int i = 0; i< ta_size; ++i)
        cout << ta[i] << '\t';
    cout << endl;

    return 0;
}
