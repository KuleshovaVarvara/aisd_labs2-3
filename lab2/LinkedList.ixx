export module LinkedList;
import std;

template <typename T>
struct Node {
    T data;
    Node* prev;
    Node* next;

    Node(const T& value) : data(value), prev(nullptr), next(nullptr) {}
};

export template <typename T>
class LinkedList {
private:
    Node<T>* head; 
    Node<T>* tail; 
    int size;      

public:
    LinkedList() : head(nullptr), tail(nullptr), size(0) {}

    ~LinkedList() {}


};