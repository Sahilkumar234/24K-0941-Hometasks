#include<iostream>
using namespace std;

class Box {
    int* volume;

    public:

    Box() {
        volume = new int(0);
    }
    Box(int val) {
        volume = new int(val);
    }
    Box(const Box& newObj) {
        volume = new int(*newObj.volume);
    }
    ~Box() {
        delete volume;
    }
    void setVolume(int vol) {
        *volume = vol;
    }
    int getVolume() {
        return *volume;
    }
};

int main() {
    Box B1;
    cout<<"Default B1 volume: "<<B1.getVolume()<<endl;
    Box B2(3);
    cout<<"Parametrized B2 volume: "<<B2.getVolume()<<endl;
    Box B3 = B2;
    cout<<"Copy B3 volume: "<<B3.getVolume()<<endl;
    B2.setVolume(5);
    B3.setVolume(12);
    cout<<"Modified volume(B2): "<<B2.getVolume()<<endl;
    cout<<"Modified volume(B3): "<<B3.getVolume()<<endl;
}
