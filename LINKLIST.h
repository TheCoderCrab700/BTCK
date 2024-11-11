 #include <iostream>
using namespace std;
template<typename T>
class LinkList {
private:
    struct Node {
        T data;
        Node* next;
        Node(int value){
            data=value;
            next=nullptr; 
        }
    };
    Node* head;
    Node* tail;
public:
    LinkList() {
        head=nullptr;
        tail=nullptr;
    }    
    LinkList(const LinkList& other){
        head=nullptr;
        tail=nullptr;
        Node* travel = other.head;
        while (travel != nullptr) {
            addLast(travel->data);
            travel = travel->next;
        }
    }
    ~LinkList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void addFirst(T value) {
        try {
            Node* newNode = new Node(value);
            if (head == nullptr) {
                head = tail = newNode;
            } else {
                newNode->next = head;
                head = newNode;
            }
        } catch (const bad_alloc& e) {
            cerr << "Memory allocation failed: " << e.what() << endl;
        }
    }
    void addLast(T value) {
        try {
            Node* newNode = new Node(value);
            if (head == nullptr) {
                head = tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
        } catch (const bad_alloc& e) {
            cerr << "Memory allocation failed: " << e.what() << endl;
        }
    }
    void addAfter(T target, T value) {
        try {
            Node* travel = head;
            while (travel != nullptr && travel->data != target) {
                travel = travel->next;
            }
            if (travel != nullptr) {
                Node* newNode = new Node(value);
                newNode->next = travel->next;
                travel->next = newNode;
                if (travel == tail) {
                    tail = newNode;
                }
            }
        } catch (const bad_alloc& e) {
            cerr << "Memory allocation failed: " << e.what() << endl;
        }
    }

    void deleteFirst() {
        if (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
            if (head == nullptr) {
                tail = nullptr;
            }
        }
    }
    void deleteLast() {
        if (head == nullptr) return;
        if (head == tail) {
            delete head;
            head = tail = nullptr;
        } 
        else {
            Node* travel = head;
            while (travel->next != tail) {
                travel = travel->next;
            }
            delete tail;
            tail = travel;
            tail->next = nullptr;
        }
    }
    void deleteAfter(T target) {
        Node* travel = head;
        while (travel != nullptr && travel->data != target) {
            travel = travel->next;
        }
        if (travel != nullptr && travel->next != nullptr) {
            Node* temp = travel->next;
            travel->next = temp->next;
            if (temp == tail) {
                tail = travel;
            }
            delete temp;
        }
    }
    void addValue(T value) {
        if (!exists(value)) {
            addLast(value);
        }
    }
    void deleteValue(T value) {
        if (head == nullptr) return;
        if (head->data == value) {
            deleteFirst();
            return;
        }
        Node* travel = head;
        while (travel->next != nullptr && travel->next->data != value) {
            travel = travel->next;
        }
        if (travel->next != nullptr) {
            Node* temp = travel->next;
            travel->next = temp->next;
            if (temp == tail) {
                tail = travel;
            }
            delete temp;
        }
    }
    bool exists(T value) const {
        Node* travel = head;
        while (travel != nullptr) {
            if (travel->data == value) {
                return true;
            }
            travel = travel->next;
        }
        return false;
    }
    void sortAscending() {
        if (head == nullptr || head->next == nullptr) return;
        for (Node* i = head; i->next != nullptr; i = i->next) {
            for (Node* j = i->next; j != nullptr; j = j->next) {
                if (i->data > j->data) {
                    swap(i->data, j->data);
                }
            }
        }
    }
    void sortDescending() {
        if (head == nullptr || head->next == nullptr) return;
        for (Node* i = head; i->next != nullptr; i = i->next) {
            for (Node* j = i->next; j != nullptr; j = j->next) {
                if (i->data < j->data) {
                    swap(i->data, j->data);
                }
            }
        }
    }
    friend ostream& operator<<(ostream& out, const LinkList& list) {
        Node* travel = list.head;
        out << "[";
        while (travel != nullptr) {
            out << travel->data;
            if (travel->next != nullptr) {
                out << " -> ";
            }
            travel = travel->next;
        }
        out << "]";
        return out;
    }
};