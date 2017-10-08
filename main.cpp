/*
Earl Clark, Molly Parker, Abdullah M.
P1 - Templated linked list with driver that will be used to test
other programs we write in class.
Due: 10/09/2017
 */

#include <iostream>
using namespace std;

/* updated on Sunday by Abdullah
 * added a copy constructor for Node class
 * added AtCursor() for LinkedList class
 * added isEmpty() for LinkedList class
 */


//Start node header
template <class T>
class Node {
public:

    Node() {}

    Node(const Node &temp);
    
    Node(T theData, Node *theLink) : data(theData), link(theLink) {}

    Node *getLink() const {
        return link;
    }

    T getData() const {
        return data;
    }

    void setData(T theData) {
        data = theData;
    }

    void setLink(Node *pointer) {
        link = pointer;
    }
private:
    T data;
    Node<T> *link;
};

//copy constructor 
template <class T>
Node<T>::Node(const Node &temp) {
    
    Node *node = new Node;
    node->data = temp->data;
    node->link = temp->link;
    temp->link = node; //newly created node will come after old nude (operand)
}

//Start linked list header
template <class T>
class LinkedList {
public:

    LinkedList() {
        head = NULL;
    }
    void displayList(Node<T> *head);
    bool insert(Node<T> *afterMe, T theData);
    void headInsert(Node<T> *&head, T theData);
    void tailInsert(Node<T> *&head);
    void search(Node<T> *head);
    bool deleteNode(Node<T> *&head);
    bool isEmpty(const Node<T> *head);
    LinkedList(const LinkedList&);
    ~LinkedList();
    LinkedList<T> &operator=(const LinkedList<T> &rhs);
    //add cursor function
    Node<T> AtCursor(const Node<T> &temp);
    //move cursor functions
private:
    Node<T> *head;
    Node<T> *cursor;
};

//linked list implementation

//displays list
template <class T>
void LinkedList<T>::displayList(Node<T> *head) {
    Node<T> *temp = head;
    Node<T> *curs = cursor->getLink();
    cout << "Head ";
    while (temp != NULL) {
        cout << " \t ";
        if(temp == curs){
            cout << "[" << temp->getData() << "]";
        }
        cout << temp->getData();
        temp = temp->getLink();
    }
    cout << endl;
}

//inserts item into list
template <class T>
bool LinkedList<T>::insert(Node<T> *afterMe, T theData) {
    /*if(isEmpty(head)){
        return false;
    }
     * */
    //else{
        afterMe->setLink(new Node<T>(theData, afterMe->getLink()));
        //cursor = afterMe->getLink();
        return true;
    }
//}

//inserts item as head
template <class T>
void LinkedList<T>::headInsert(Node<T> *&head, T theData) {
    cout << "Enter your item to place in the linked list" << endl;
    cin >> theData;
    head = new Node<T>(theData, head);
}

//inserts item as tail
template <class T>
void LinkedList<T>::tailInsert(Node<T> *&head) {
    Node<T> *temp;
    Node<T>* next;
    T theData;
    if (head == NULL) {
        cout << "Enter your item to place in the linked list" << endl;
        cin >> theData;
        head = new Node<T>(theData, head);
    } else {
        temp = head;
        next = temp->getLink();
        while (next != NULL) {
            temp = next;
            next = next->getLink();
        }
        cout << "Enter your item to place in the linked list" << endl;
        cin >> theData;
        insert(temp, theData);
    }
}

//search list for item
template <class T>
void LinkedList<T>::search(Node<T> *head) {
    Node<T> *here = head;
    T target;
    cout << "Enter item you wish to search for" << endl;
    cin >> target;
    if (here == NULL) {
        cout << "Item not found" << endl;
    } else {
        while (here->getData() != target && here->getLink() != NULL) {
            here = here->getLink();
        }
        if (here->getData() == target) {
            cout << "Match found" << endl;
        } else {
            cout << "Match not found" << endl;
        }
    }
}

//deletes node
template <class T>
bool LinkedList<T>::deleteNode(Node<T> *&head) {
    T target;
    cout << "Enter the item you wish to delete from the linked list" << endl;
    cin >> target;

    if (head == NULL)
        return false;
    else {
        Node<T> *pred = head;
        Node <T> *temp = head->getLink();
        if (pred->getData() == target) {
            head = temp;
            delete pred;
        } else {
            while (temp->getData() != target && temp->getLink() != NULL) {
                temp = temp->getLink();
                pred = pred->getLink();
            }
            if (temp->getData() == target) {
                pred->setLink(temp->getLink());
                delete temp;
                cout << "Item deleted" << endl;
            } else
                cout << "Item not found" << endl;
        }
        return true;
    }
}

//copy operator
template <class T>
LinkedList<T>::LinkedList(const LinkedList<T> &LL) {
    head = LL.head;
}

//destructor
template <class T>
LinkedList<T>::~LinkedList() {
    
    Node<T> *current = head;
    while (current) {
        Node<T> *next = current->getLink();
        delete current;
        current = next;
    }
}

//assignment operator
template <class T>
LinkedList<T> &LinkedList<T>::operator=(const LinkedList<T> &rhs) {
    
    LinkedList<T> temp(rhs);
    std::swap(head, temp->head);
    return *this;
}

//returns data at cursor 
template <class T>
Node<T> LinkedList<T>::AtCursor(const Node<T> &temp){
    
    return(temp->getData());
}

//tells whether or not list is empty
template <class T>
bool LinkedList<T>::isEmpty(const Node<T> *head){
 
    if(head->getLink()==NULL){
        return(true);
    }
    else{
        return(false);
    }
}
void getChoice(){
	cout << "+ : Insert" << endl;
	cout << "- : Remove" << endl;
	cout << "? : Search" << endl;
	cout << "p : Print" << endl;
	cout << "@ : At Cursor" << endl;
	cout << "b : Go to Beginning" << endl;
	cout << "e : Go to End" << endl;
	cout << "> : Go to Next" << endl;
	cout << "< : Go to Previous" << endl;
	cout << "1 : Test Linked List Constructor" << endl;
	cout << "2 : Test Linked List Copy Constructor" << endl;
	cout << "3 : Test Destructor" << endl;
	cout << "4 : Test Assignment Operator" << endl;
	cout << "5 : Clear List" << endl;
	cout << "6:  Test Empty List" << endl;
	cout << "m : Print Menu" << endl;
	cout << "q : Quit" << endl;
}

int main() {
    LinkedList <string> test;
    Node<string>* head = NULL;
    char choice;
    getChoice();
   
        while (choice != 'q' || choice != 'Q') {
        	cout << "Enter in your choice: " << endl;
        	cin >> choice;
        switch (choice) {
           	case '+': test.tailInsert(head); break;
            case '-': test.deleteNode(head); break;
            case '?': test.search(head); break;
            case 'p': test.displayList(head); break;
            case '@': break;
            case 'b': break;
            case 'e': break;
            case '>': break;
            case '<': break;
            case '1': break;
            case '2': break;
            case '3': break;
            case '4': break;
            case '5': break;
            case '6': break;
            case 'm': getChoice(); break;
            case 'q': ; break;
            default: cout << "shouldn't hit this" << endl; break;
        	}
      	}
    return 0;
}
