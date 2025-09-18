#include<iostream>
using namespace std;

class Node {
public:
    int ticketID;
    string custName;
    string rideName;
    Node* next;
    Node* prev;

    Node(int id,string CN,string RN) : ticketID(id),custName(CN),rideName(RN) {
        next = NULL;
        prev = NULL;
    }
};
class CircularList {
    Node* head;
    Node* tail;
    int count;
public:
    CircularList() {
        head = NULL;
        tail = NULL;
        count = 0;
    }
    void issueTickett_at_end(int ticketID,string custName,string rideName) {
        Node* newNode = new Node(ticketID,custName,rideName);
        if(tail == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
            newNode->next = head;
            count++;
        }
    }
    void issueTickett_at_front(int ticketID,string custName,string rideName) {
        Node* newNode = new Node(ticketID,custName,rideName);
        if(tail == NULL) {
            head = tail = newNode;
        } else {
            head->prev = newNode;
            newNode->next = head;
            head = newNode;
            tail->next = head;
            count++;
        }
    }
    void cancelTicket_by_ID(int ID) {
        if(head == NULL) {
            cout<<"list is empty"<<endl;
        } else {
            Node* tmp = head;
            while(tmp != head) {
                if(tmp->ticketID == ID) {
                    cout<<"canceled ticket of ID ("<<ID<<") "<<endl;
                    break;
                }
                tmp = tmp->next;
            }
            count--;
            cout<<"Ticked not found of ID("<<ID<<") for cancellation"<<endl;
        }
    }
    void cancelFirst_ticket() {
        if(head == NULL) {
            cout<<"do not cancel the List is empty "<<endl;
        } else {
            head = head->next;
            tail->next = NULL;
            head->prev = NULL;
            count--;
        }
    }
    Node* search_ID(int ID) {
        if(head == NULL) {
            cout<<"do not cancel the List is empty "<<endl;
        } else {
            Node* tmp = head;
            while(tmp != head) {
                if(tmp->ticketID == ID) {
                    return tmp;
                }
                tmp = tmp->next;
            }
        }
    }
    void display() {
        Node* curr = head;
        while(curr != NULL) {
            cout<<"Ticket ID: "<<curr->ticketID<<" Customer Name: "<<curr->custName<<" Ride name: "<<curr->rideName<<endl;
            curr = curr->next;
        }
    }
    int totalTickets() {
        return count++;
    }
    void findticket_after_pos(int id) {
        if(head == NULL) {
            cout<<"List is empty"<<endl;
        } else {
            Node* tmp = head;
            while(tmp->next->ticketID != id) {
                tmp = tmp->next;
            }
            cout<<"Customer after id ("<<id<<") is: "<<tmp->custName<<" of ID ("<<tmp->ticketID<<") and ride Name: "<<tmp->rideName<<endl;
        }
    }
};

int main() {
    CircularList cl;
    cl.issueTickett_at_end(1, "Ali", "Roller Coaster");
    cl.issueTickett_at_end(2, "Sana", "Ferris Wheel");
    cl.issueTickett_at_front(3, "Ahmed", "Bumper Cars");
    cl.display();
    cout << "Total Tickets: " << cl.totalTickets() << endl;

    cl.cancelTicket_by_ID(2);
    cl.display();

    cl.findticket_after_pos(1);

    Node* s = cl.search_ID(3);
    if (s != NULL) {
        cout << "Found Ticket ID: " << s->ticketID << " Customer: " << s->custName << endl;
    }

    cl.cancelFirst_ticket();
    cl.display();

    return 0;
}
