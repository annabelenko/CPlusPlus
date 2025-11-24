#include <string>
using namespace std;

class Name {
public:
    Name(string first, string last) {
        this->first = first;
        this->last = last;
    }
private:
    string first, last;
};