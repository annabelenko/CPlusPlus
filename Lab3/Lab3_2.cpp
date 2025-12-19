#include <iostream>
#include <fstream>

int min(int x, int y) {
    return (x < y) ? x:y;
}
bool min(int x, int y, int &m){
    if (x == y) return false;
    m = (x < y) ? x : y;
    return true;
}
int min(int x, int y, bool &ok){
    ok = (x != y);
    return (x<y) ? x : y;
}