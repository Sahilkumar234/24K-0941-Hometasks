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

    void deleteItem_at_Front() {
        Node* tmp = head;
        if(head == NULL) {
            cout<<"List is already empty"<<endl;
        } else {
            tmp->next = head->next;
            head = tmp->next;
            cout<<"Deleted item "<<tmp->data<<" $"<<tmp->price<<endl;
            delete tmp;
        }
    }

    void search_Item(string searchItem) {
        Node* tmp = head;
        while (tmp != NULL) {
            if (tmp->data == searchItem) {
                cout << "Item \"" << searchItem << "\" is found and the price is: $" << tmp->price << endl;
                return;
            }
            tmp = tmp->next;
        }
        cout << "Item \"" << searchItem << "\" not found." << endl;
    }

        void searchByPosition(int position) {
        if (position <= 0) {
            cout << "Invalid position "<<endl;
            return;
        }

        Node* temp = head;
        int count = 1;
        while (temp != nullptr) {
            if (count == position) {
                cout << "Item at position " << position << ": " << temp->data << " $" << temp->price << endl;
                return;
            }
            count++;
            temp = temp->next;
        }
        cout << "Position " << position << " exceeds cart size."<<endl;
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
