#include<iostream>
using namespace std;

class Exam {
    int* marks;
    int qty;
public:
    Exam(int qty) {
        this->qty = qty;
        marks = new int[qty];

        for(int i=0;i<qty;i++) {
            marks[i] = 0;
        }
    }

    ~Exam() {
        delete[] marks;
    }

    void assignMarks(int index,int val) {
        if(index >= 0 && index < qty) {
            marks[index] = val;
        }
    }

    void displayMarks() {
        for(int i=0;i<qty;i++) {
            cout<<marks[i]<<" ";
        }
        cout<<endl;
    }
};

int main() {
    Exam E1(4);
    E1.assignMarks(0,74);
    E1.assignMarks(1,85);
    E1.assignMarks(2,92);
    E1.assignMarks(3,71);
    cout<<"Actual marks:(E1)"<<endl;
    E1.displayMarks();

    cout<<"Copied marks of actual marks (E2 = E1)"<<endl;
    Exam E2 = E1;
    E2.displayMarks();

    E2.assignMarks(2,69);
    cout<<"After modefying (E2) then E1 marks:"<<endl;
    E1.displayMarks();
    cout<<"After modefying (E2) then E2 marks:"<<endl;
    E2.displayMarks();
}
