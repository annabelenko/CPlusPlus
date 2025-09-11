#include <iostream> // includes input/output stream for cout, cin, etc.
#include <fstream> //includes file stream for file reading/writing
#include <cstdlib> //includes general utilities (like exit())
#include <string> //includes the string class

//this programs reverses an array of integers
using namespace std; //allows use of standard library names without std:: prefix

void reverse(int a[], int n); //reverses array
void print(int a[], int n); //prints out array
int load(string filename, int a[], int capacity); //loads numbers from a file

int main () {
    try {
        const int A1_N = 10; //const is same as final in Java
        int a1[A1_N]; //fixed-size array. declares it 10 ints
        for (int i = 0; i < A1_N; i++)
            a1[i] = i * 100; // 15-18 is how u initialize an array. fill array with multiples of 100
        print(a1, A1_N); //prints array
        cout << endl; //new line
        reverse(a1, A1_N); //reverses array
        print(a1, A1_N); //prints the reversed array
        cout << endl;

        cout << endl;

        int a2[] = {10, 12, 31, 47, 6, 8}; //fixed-size array, declares and initializes second array
        const int A2_N = sizeof(a2) / sizeof(a2[0]); //determines length of array
        print(a2, A2_N); //prints array
        cout << endl; //new line
        reverse(a2, A2_N); //reverses array
        print(a2, A2_N); //prints the reversed array
        cout << endl;

        cout << endl;

        const int A3_CAPACITY = 100; //max size of third array
        int a3[A3_CAPACITY]; //fixed-size array, declares it 100 ints
        int a3_size = load("numbers.data", a3, A3_CAPACITY); //load from file
        print(a3, a3_size); //print loaded array
        cout << endl;
        reverse(a3, a3_size); //reverses it
        print(a3, a3_size); //prints the reversed array
        cout << endl;

        return 0;
    } catch(string message) { //catch exceptions thrown as strings
        cout << "*** Exception ***" << message << endl;
        exit(1);
    }
}

void reverse(int a[], int n) {
    for (int i=0; i<n/2; i++) { //swap first and last, second and second last, etc until middle
        int temp = a[i]; //swap elements from ends
        a[i] = a[n-i-1];
        a[n-i-1] = temp;
    }
}

void print(int a[], int n) {
    for (int i = 0; i < n; i++)
        cout << a[i] << (i < n-1 ? ", " : ""); // print elements, separated by commas
}

int load(string fname, int a[], int capacity) {
    ifstream ifs(fname.c_str()); //
    if (!ifs) throw fname + " not found";
    int size = 0;

    int num;
    ifs >> num;
    while (ifs) {
        if (size == capacity) throw "array capacity exceeded";
        a[size] = num;
        size++;
        ifs >> num;
    }
    return size;
}

/*
    Define a method that accepts an array and is size,
    and reverses the elements of the array, as well as a main
    that tests the function on verious arrays. 
*/