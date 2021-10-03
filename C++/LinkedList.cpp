#include <iostream>

using namespace std;
typedef int E;

class LinkedList {
    class Link {
        public:
        E element;
        Link *next;
        Link(E it, Link *nextval) {
            this->element = it;
            this->next = nextval;
        }
        Link(Link *nextval) {
            this->element = 0;
            this->next = nextval;
        }
    };
    Link *head;
    Link *tail;
    Link *curr;
    long long cnt;
    public:
    LinkedList() {
        head = tail = curr = new Link(nullptr);
        cnt = 0;
    }
    long long size() {
        return cnt;
    }
    void clear() {
        curr = head;
        Link *temp;
        while(curr != tail) {
            temp = curr;
            curr = curr->next;
            delete(temp);
        }
        delete(curr);
        curr = tail = head;
        cnt = 0;
    }
    void appendBack(E it) {
        tail->next = new Link(it, tail->next);
        tail = tail->next;
        cnt++;
    }
    void appendFront(E it) {
        head->next = new Link(it, head->next);
        cnt++;
    }
    void moveToStart() {
        curr = head;
    }
    void moveToEnd() {
        curr = tail;
    }
    bool moveToPos(long long pos) {
        if(pos < 0 || pos >= cnt) return false;
        curr = head;
        for(long long i = 0; i < pos; i++) {
            curr = curr->next;
        }
        return true;
    }
    void prev() {
        if(curr == head) return;
        Link *temp = head;
        while(temp->next != curr)
            temp = temp->next;
        curr = temp;
    }
    void next() {
        if(curr == tail) return;
        curr = curr->next;
    }
    long long currPos() {
        Link *temp = head;
        long long i = 0;
        while(temp != curr) {
            temp = temp->next;
            i++;
        }
        return i;
    }
    void insert(E it) {
        curr->next = new Link(it, curr->next);
        if(tail == curr) tail = curr->next;
        cnt++;
    }
    E remove() {
        if(curr->next == nullptr) {
            printf("LinkedList is already empty\n");
            return -1;
        }
        E it = curr->next->element;
        curr->next = curr->next->next;
        return it;
    }
    
    
    
    
    
    E getValue() {
        if(curr->next != nullptr) {
            return curr->next->element;
        }
        printf("invalid curr pointer\n");
        return -1;

    }
    E at(E it) {
        Link *temp = curr;
        if(moveToPos(it)) {
            E val = getValue();
            curr = temp;
            return val;
        } else {
            printf("position out of bound\n");
            return -1;
        }
    }
    E operator[]() {

    }
};

int main() {
    LinkedList lista;

    //a = "dale";
}