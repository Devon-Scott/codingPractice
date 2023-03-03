#include <stdexcept>

template <typename T>
class MyLinkedList{
public: 
    MyLinkedList<T>();
    void push(const T &element);
    void pop();
    T& top();
    int size();
    bool empty();
private:
    class Node{
        T& value;
        Node* next;
        Node(T& element){
            value = element;
            next = nullptr;
        }
    };
    Node* head;
    Node* tail;
    int numOfElements;
};

template <typename T>
MyLinkedList<T>::MyLinkedList(){
    this.head = nullptr;
    this.tail = nullptr;
    this->numOfElements = 0;
}

template <typename T>
void MyLinkedList<T>::push(const T& element){
    Node* val = new Node(element);
    if (this.head != nullptr){
        val.next = this->head;
        this->tail = val;
        this->numOfElements++;
    }
    this->head = val;
}

template <typename T>
void MyLinkedList<T>::pop(){
    if (this->numOfElements != 0){
        this->numOfElements--;
        Node* temp = this->head;
        if (this->numOfElements == 0){
            this->head == nullptr;
            this->tail == nullptr;
        } else {
            this->head = this->head->next;
        }
        delete temp;
    } else {
        throw std::out_of_range("Can't pop an empty list");
    }
}

template <typename T>
T& MyLinkedList<T>::top(){
    if (this->numOfElements != 0){
        return this->head;
    } else {
        throw std::out_of_range("Nothing to return");
    }
}

template <typename T>
int MyLinkedList<T>::size(){
    return this->numOfElements;
}

template <typename T>
bool MyLinkedList<T>::empty(){
    return this->numOfElements == 0;
}