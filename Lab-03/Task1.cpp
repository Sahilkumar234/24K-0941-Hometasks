#include <iostream>
using namespace std;

class Node {
public:
    string data;
    int price;
    Node* next;

    Node(string data, int price) : data(data), price(price) {
        next = NULL;
    }
};

class LinkList {
    Node* head;

public:
    LinkList() {
        head = NULL;
    }
    void assignItems(string item, int price) {
        Node* newNode = new Node(item, price);

        if (head == NULL) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void addItem_atFront(string item, int price) {
        Node* newNode = new Node(item, price);
        newNode->next = head;
        head = newNode;
    }

    void addItem_atEnd(string item, int price) {
        Node* newNode = new Node(item, price);
        if (head == NULL) {
            head = newNode;
        } else {
            Node* tmp = head;
            while (tmp->next != NULL) {
                tmp = tmp->next;
            }
            tmp->next = newNode;
        }
    }

    void addItem_after_pos(string item, string pos, int price) {
        Node* tmp = head;

        while (tmp != NULL && tmp->data != pos) {
            tmp = tmp->next;
        }

        if (tmp == NULL) {
            cout << "Item " << pos << " not found. Cannot insert after it"<<endl;
            return;
        }

        Node* newNode = new Node(item, price);
        newNode->next = tmp->next;
        tmp->next = newNode;
    }

    void search_Item(string searchItem) {
        Node* tmp = head;
        while (tmp != NULL) {
            if (tmp->data == searchItem) {
                cout << "Item " << searchItem << " is found and the price is: " << tmp->price << endl;
                return;
            }
            tmp = tmp->next;
        }
        cout << "Item " << searchItem << " not found." << endl;
    }

    void display() {
        Node* tmp = head;
        if (head == NULL) {
            cout << "Cart is empty." << endl;
        } else {
            while (tmp != NULL) {
                cout << "Item Name: " << tmp->data << " ; Price: $" << tmp->price << endl;
                tmp = tmp->next;
            }
            cout << endl;
        }
    }
};

int main() {
    LinkList L1;

    L1.assignItems("Laptop", 1000);
    L1.assignItems("Phone", 700);
    L1.assignItems("Tablet", 400);
    L1.assignItems("Headphones", 150);
    L1.display();

    cout<<"<<--Insert Smartwatch at front and Keyboard at end-->>"<<endl;
    L1.addItem_atFront("Smartwatch", 200);
    L1.addItem_atEnd("Keyboard", 80);
    L1.display();

    cout<<"<<--Insert Monitor after Phone-->>"<<endl;
    L1.addItem_after_pos("Monitor", "Phone", 300);
    L1.display();

    cout<<"<<--Search for Tablet-->>"<<endl;
    L1.search_Item("Tablet");
    return 0;
}
