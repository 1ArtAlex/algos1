#include <iostream>
using namespace std;

class Node {
public:
    int value;
    Node* next; 
    Node(int val) {
        value = val;
        next = nullptr;
    }
};


class LinkedList {
public:
    Node* head; 
    LinkedList() {
        head = nullptr;
    }

    void append(int val) {
        Node* newNode = new Node(val);

        if (head == nullptr) { 
            head = newNode;
            return;
        }

        Node* current = head;

        while (current->next != nullptr) {
            current = current->next;
        }

        current->next = newNode; 
    }

        void prepend(int val) {
        Node* newNode = new Node(val);

        if (head == nullptr) { 
            head = newNode;
            return;
        }

        newNode->next = head;
        head = newNode;
    }

    void insert(int val, int pos) {
        Node* newNode = new Node(val);

        if (head == nullptr) {
            head = newNode;
            return;
        }

        if (pos == 0) { 
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* current = head;
        int index = 0;

        while (current->next != nullptr && index < pos - 1) { 
            current = current->next;
            index++;
        }

        newNode->next = current->next;
        current->next = newNode;
    }

    void remove(int val) {
        if (head == nullptr) { 
            return;
        }

        if (head->value == val) {
            Node* nodeToDelete = head;
            head = head->next;
            delete nodeToDelete;
            return;
        }

        Node* current = head;

        while (current->next != nullptr && current->next->value != val) {
            current = current->next;
        }

        if (current->next == nullptr) {
            return;
        }

        Node* nodeToDelete = current->next;
        current->next = current->next->next; 
        delete nodeToDelete;
    }

    void removeAt(int pos) {
        if (head == nullptr) { 
            return;
        }

        if (pos == 0) { 
            Node* nodeToDelete = head;
            head = head->next;
            delete nodeToDelete;
            return;
        }

        Node* current = head;
        int index = 0;

        while (current->next != nullptr && index < pos - 1) {
            current = current->next;
            index++;
        }

        if (current->next == nullptr) { 
            return;
        }

        Node* nodeToDelete = current->next;
        current->next = current->next->next; 
        delete nodeToDelete;
    }

    Node* search(int val) {
        if (head == nullptr) { 
            return nullptr;
        }

        Node* current = head;

        while (current != nullptr) { 
            if (current->value == val) {
                return current;
            }
            current = current->next;
        }

        return nullptr;
    }

    Node* searchAt(int pos) {
        if (head == nullptr) { 
            return nullptr;
        }

        Node* current = head;
        int index = 0;

        while (current != nullptr && index < pos) {
            if (index == pos) {
                return current;
            }
            current = current->next;
            index++;
        }

        return nullptr;
    }

    void display() {
        if (head == nullptr) { 
            cout << "List is empty" << endl;
            return;
        }

        Node* current = head;

        while (current != nullptr) { 
            cout << current->value << " ";
            current = current->next;
        }

        cout << endl;
    }
};

int main() {
    LinkedList list;
    int choice = 0;

    while (true) {
        cout << endl;
        cout << "Select an operation:" << endl;
        cout << "1. Add element to the end of the list" << endl;
        cout << "2. Add element to the beginning of the list" << endl;
        cout << "3. Add element to a specific position in the list" << endl;
        cout << "4. Remove element by value" << endl;
        cout << "5. Remove element by position" << endl;
        cout << "6. Search for an element by value" << endl;
        cout << "7. Search for an element by position" << endl;
        cout << "8. Display all elements in the list" << endl;
        cout << "9. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            int value;
            cout << "Enter the value to add: ";
            while (!(cin >> value)){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input" << endl;
            }
            list.append(value);
        } else if (choice == 2) {
            int value;
            cout << "Enter the value to add: ";
            while (!(cin >> value)){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input" << endl;
            }
            list.prepend(value);
        } else if (choice == 3) {
            int value, pos;
            cout << "Enter the value to add: ";
            while (!(cin >> value)){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input" << endl;
            }
            cout << "Enter the position to add: ";
            while (!(cin >> pos)){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input" << endl;
            }
            list.insert(value, pos);
        } else if (choice == 4) {
            int value;
            cout << "Enter the value to remove: ";
            while (!(cin >> value)){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input" << endl;
            }
            list.remove(value);
        } else if (choice == 5) {
            int pos;
            cout << "Enter the position to remove: ";
            while (!(cin >> pos)){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input" << endl;
            }
            list.removeAt(pos);
        } else if (choice == 6) {
            int value;
            cout << "Enter the value to search: ";
            while (!(cin >> value)){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input" << endl;
            }
            Node* node = list.search(value);
            if (node != nullptr) {
                cout << "Element found: " << node->value << endl;
            } else {
                cout << "Element not found" << endl;
            }
        } else if (choice == 7) {
            int pos;
            cout << "Enter the position to search: ";
            while (!(cin >> pos)){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input" << endl;
            }
            Node* node = list.searchAt(pos);
            if (node != nullptr) {
                cout << "Element found: " << node->value << endl;
            } else {
                cout << "Element not found" << endl;
            }
        } else if (choice == 8) {
            cout << "List: ";
            list.display();
        } else if (choice == 9) {
            break; 
        } else {
            cout << "Invalid choice" << endl;
        }
    }

    return 0;
}