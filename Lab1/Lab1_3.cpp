#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    const int CAPACITY = 50;
    string names[CAPACITY];
    int ids[CAPACITY];
    int count = 0;
    int startID = 1001;

    ifstream fin("names.data");
    if (!fin) {
        cerr << "*** Exception *** input file names.data not found" << endl;
        return 1;
    }
    while (fin >> names[count]) {
        if (count >= CAPACITY) {
            cerr << "*** Exception *** array capacity exceeded" << endl;
            return 1;
        }
        ids[count] = startID + count;
        count++;
    }
    fin.close();

    for (int i = 0; i < count - 1; i++){
        for (int j = i + 1; j < count; j++){
            if (names[j] < names[i]) {
                swap(names[i], names[j]);
                swap(ids[i], ids[j]);
            }
        }
    }
    ofstream fout("results.data");
    for (int i = 0; i < count; i++){
        fout << names[i] << " " << ids[i] << endl;
    }
    fout.close();

    cout << count << " records processed" << endl;
    return 0;
}