#include <iostream>
int a[100], b[100], match[100];
void print_array(int * a, int n);
bool is_same(int * a, int n);
void sink(int k, int n);
void swap(int i, int j);
bool comp(int i, int j);
using namespace std;

int main(void) {
    int n, i, j;
   
    cin >> n;
    for (i = 0; i < n; i++) {	//the source array
        cin >> a[i];
        b[i] = a[i];
    }
    for (i = 0; i < n; i++)		//the array to match
        cin >> match[i];
    
    //insertion sort
    bool is_insert = false;
    for (i = 1; i < n; i++) {
        if (is_insert && !is_same(a, n)) {
            break;
        }
        if (is_same(a, n))   is_insert = true;

        int k = a[i];
        for (j = i; j > 0 && k < a[j-1]; j--) {
            a[j] = a[j-1];
        }
        a[j] = k;
    }
    if (is_insert) {
        cout << "Insertion Sort\n";
        print_array(a, n);
        return 0;
    }
    
    //heap sort
    for (i = n/2; i >= 1; i--)
        sink(i, n);
    int end = n;
    bool is_heap = false;
    while (end > 1) {
        if (is_heap && !is_same(b, n))
            break;
        if (is_same(b, n))   is_heap = true;

        swap(1, end--);
        sink(1, end);
    }
    if (is_heap) {
        cout << "Heap Sort\n";
        print_array(b, n);
    }

    return 0;
}

void print_array(int * a, int n) {
    for (int i = 0; i < n-1; i++)
        cout <<  a[i] << " ";
    cout << a[i] << endl;
}
bool is_same(int * a, int n) {
    for (int i = 0; i < n; i++) {
        if (a[i] != match[i])
            return false;
    }
    return true;
}

/* functions of heap sort */
void sink(int k, int n) {
    while (2 * k <= n) {
        int v = 2 * k;
        if (2*k+1 <= n && comp(2*k, 2*k+1))	//find the bigger of the two
            v++;
        if (comp(k, v))
            swap(k, v);
        k = v;
    }
}
void swap(int i, int j) {
    int temp;

    temp = b[i-1];
    b[i-1] = b[j-1];
    b[j-1] = temp;
}
bool comp(int i, int j) {
    return b[i-1] < b[j-1];
}



