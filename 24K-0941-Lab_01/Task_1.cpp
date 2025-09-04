#include <iostream>
using namespace std;

class ResearchPaper {
    string* author_name;
    int capacity;

public:
    ResearchPaper(int c) : capacity(c) {
        author_name = new string[capacity];
    }

    ~ResearchPaper() {
        delete[] author_name;
    }

    ResearchPaper(const ResearchPaper& newobj) {
        capacity = newobj.capacity;
        author_name = new string[capacity];
        for (int i = 0; i < capacity; i++) {
            author_name[i] = newobj.author_name[i];
        }
    }

    ResearchPaper& operator=(const ResearchPaper& assign) {
        if (this != &assign) {
            delete[] author_name;

            capacity = assign.capacity;
            author_name = new string[capacity];
            for (int i = 0; i < capacity; i++) {
                author_name[i] = assign.author_name[i];
            }
        }
        return *this;
    }

    void assignAuthor(int size, const string& name) {
        if (size >= 0 && size < capacity)
            author_name[size] = name;
    }

    void displayAuthor() const {
        for (int i = 0; i < capacity; i++) {
            cout << "Author " << i + 1 << ": " << author_name[i] << endl;
        }
    }
};

int main() {
    ResearchPaper R1(3);
    R1.assignAuthor(0, "Sahil");
    R1.assignAuthor(1, "Ali");
    R1.assignAuthor(2, "Dev");

    cout << "ResearchPaper R1:" << endl;
    R1.displayAuthor();

    ResearchPaper R2 = R1;
    cout << "Copied ResearchPaper R2:" << endl;
    R2.displayAuthor();

    R2.assignAuthor(1, "Gotam");

    cout << "After modifying R2 / R1 is:" << endl;
    R1.displayAuthor();
    cout << "R2:" << endl;
    R2.displayAuthor();

    ResearchPaper R3(3);
    R3 = R1;

    cout << "Assigned ResearchPaper R3 = R1:" << endl;
    R3.displayAuthor();

    return 0;
}
