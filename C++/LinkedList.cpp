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
    void safeClear() {
        curr = head;
        Link *temp;
        while(curr != tail) {
            temp = curr;
            curr = curr->next;
            delete(temp);
        }
        delete(curr);
    }
    void clear() {
        curr = tail = head = new Link(nullptr);
        cnt = 0;
    }
    void appendBack(E it) {
        tail->next = new Link(it, tail->next);
        tail = tail->next;
        cnt++;
    }
    void removeBack() {
        if(cnt == 0) return;
        Link *temp = head;
        while(temp->next != tail) {
            temp = temp->next;
        }
        temp->next = nullptr;
        tail = temp;
        cnt--;
    }
    void appendFront(E it) {
        head->next = new Link(it, head->next);
        while(tail->next != nullptr) tail = tail->next;
        cnt++;
    }
    void removeFront() {
        if(cnt == 0) return;
        if(curr == head->next) curr = head;
        if(tail == head->next) tail = head;
        head->next = head->next->next;
        cnt--;
    }
    void moveToStart() {
        curr = head;
    }
    void moveToEnd() {
        curr = tail;
    }
    void moveToPos(long long pos) {
        if(pos >= cnt) {
            moveToEnd();
            return;
        }
        curr = head;
        for(long long i = 0; i < pos; i++) {
            curr = curr->next;
        }
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
    bool remove() {
        if(curr->next == nullptr) {
            return false;
        }
        curr->next = curr->next->next;
        return true;
    }
    E getValue() {
        if(cnt == 0) {
            printf("LinkedListk is empty");
            exit(-1);
        }
        if(curr->next == nullptr) {
            return curr->element;
        }    
        return curr->next->element;
    }
    E at(long long it) {
        Link *temp = curr;
        moveToPos(it);
        E val = getValue();
        curr = temp;
        return val;
        
    }
    E operator[](long long it) {
        return at(it);
    }
    void insertAt(long long pos, E it) {
        Link *temp = curr;
        moveToPos(pos);
        insert(it);
        curr = temp;
        cnt++;
    }

    void removeAt(long long pos) {
        Link *temp = curr;
        moveToPos(pos);
        remove();
        curr = temp;
        cnt--;
    }

    int empty() {
        if(cnt > 0) return 1;
        return 0;
    }
    void print() {
        Link *temp = head;
        while(temp->next != nullptr) {
           cout << temp->next->element << " ";
           temp = temp->next;
        }
        cout << endl;
   }
};

int main() {
    LinkedList lista;
    lista.appendFront(1);
    lista.print();
    lista.appendBack(2);
    lista.print();
    lista.appendFront(1);
    lista.print();
    lista.removeFront();
    lista.print();
    lista.removeBack();
    lista.print();
}