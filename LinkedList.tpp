#include "LinkedList.hpp"

template <typename T>
LinkedList<T>::LinkedList()
: head(nullptr), length(0) { }

template <typename T>
LinkedList<T>::LinkedList(LinkedList<T>& copyObj) {
    copy(copyObj);
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& copyObj) {
    copy(copyObj);
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>* copyObj) {
    copy(*copyObj);
}

template <typename T>
LinkedList<T>::~LinkedList() {
    if (this->head != nullptr) {
        clear();
    }
    
}

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& rightObj) {
    if (this != &rightObj) {
        copy(rightObj);
    }
    return *this;
}

template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::getNode(int position) {
    if ((position >= this->length) || (position < 0)) {
        throw string("getNode(): Node out of range");
    }
    Node* outNode = this->head;
    for (int i = 0; i < position; i++) {
        outNode = outNode->next;
    }
    return outNode;
}

template <typename T>
void LinkedList<T>::copy(const LinkedList<T>& copyObj) {
    if (this->head != nullptr) {
        clear();
    }
    for (int i = 0; i < copyObj.length; i++) {
        T elem = copyObj.getElement(i);
        if (isEmpty()) {
            this->head = new Node(elem);
        } else {
            Node* lastNode = getNode(this->length - 1);
            lastNode->next = new Node(elem);
        }
        this->length++;
    }
}

template <typename T>
T LinkedList<T>::getElement(int pos) {
    if ((pos >= this->length) || (pos < 0)) {
        throw string("getElement(): Element out of range");
    }
    return getNode(pos)->data;
}

template <typename T>
T LinkedList<T>::getElement(int pos) const {
    if ((pos >= this->length) || (pos < 0)) {
        throw string("getElement(): Element out of range");
    }
    Node* currNode = this->head;
    for (int i = 0; i < pos; i++) {
        currNode = currNode->next;
    }
    return currNode->data;
}

template <typename T>
int LinkedList<T>::getLength() {
    return this->length;
}

template <typename T>
bool LinkedList<T>::isEmpty() {
    return !this->length;
}

template <typename T>
void LinkedList<T>::append(T& elem) {
    if (isEmpty()) {
        this->head = new Node(elem);
    } else {
        Node* lastNode = getNode(this->length - 1);
        lastNode->next = new Node(elem);
    }
    this->length++;
}

template <typename T>
void LinkedList<T>::insert(T& elem, int pos) {
    if ((pos >= this->length) || (pos < 0)) {
        throw string("insert(): Element out of range");
    }
    Node* curr = getNode(pos);
    if (curr == this->head) {
        this->head = new Node(elem, curr);
    } else {
        Node* prev = getNode(pos - 1);
        prev->next = new Node(elem, curr);
    }
    this->length++;
}

template <typename T>
void LinkedList<T>::replace(T& elem, int pos) {
    if ((pos >= this->length) || (pos < 0)) {
        throw string("replace(): Element out of range");
    }
    getNode(pos)->data = elem;
}

template <typename T>
void LinkedList<T>::remove(int pos) {
    if ((pos >= this->length) || (pos < 0)) {
        throw string("remove(): Element out of range");
    }
    Node* curr = getNode(pos);
    if (curr == this->head) {
        this->head = curr->next;
    } else {
        Node* prev = getNode(pos - 1);
        prev->next = curr->next;
    }
    delete curr;
    this->length--;
}

template <typename T>
void LinkedList<T>::clear() {
    Node* prev = nullptr;
    while (this->head != nullptr) {
        if (this->head == nullptr) {break;}
        prev = this->head;
        this->head = this->head->next;
        delete prev;
    }
    this->length = 0;
}

template <typename T>
shared_ptr<LinkedList<T>> LinkedList<T>::getCopy() const {
    return make_shared<LinkedList<T>>(this);
}

template <typename T>
ostream& operator<<(ostream& outStream, const LinkedList<T>& myObj) {
    if (myObj.isEmpty()) {
        outStream << "List is empty, no elements to display." << endl;
    }
    else {
        typename LinkedList<T>::Node* curr = myObj.head;
        while (curr != nullptr) {
            outStream << curr->value;
            if (curr->next != nullptr) {
                outStream << " -> ";
            }
            curr = curr->next;
        }
        outStream << endl;
    }

    return outStream;
}