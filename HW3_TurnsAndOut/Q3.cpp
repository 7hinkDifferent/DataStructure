#include <iostream>
using namespace std;

struct Node {
    unsigned long tag;
    Node* next;
};

int main (int argc, char* argv[]) {
    unsigned long num;
    unsigned int key;

    cin >> num >> key;

    Node* head;
    Node* current;
    Node* tmp;

    unsigned int counter = 1;

    // empty head 
    head = new Node();
    current = head;

    for (unsigned long i = 0; i < num; i++)
    {
        current->next = new Node();
        current->next->tag = i + 1;
        current = current->next;
    }
    current->next = head->next; // form a loop

    delete head;

    // current->next is what we are going to consider
    while (current->next != current) {
        if (counter == key)
        {
            tmp = current->next;
            current->next = tmp->next;
            delete tmp;

            counter = 1;
        }
        else {
            current = current->next;
            counter++;
        }
    }

    cout << current->tag;
    delete current;

    return 0;
}