#include "DLink.h"
#include <typeinfo>
using namespace std;
template <class T>

// Constructors
DList<T>::DList()
{
    sorted = false;
    head = NULL;
    tail = NULL;
    count = 0;
}
template <class T>
DList<T>::DList(bool sorted)
{
    this->sorted = sorted;
    head = NULL;
    tail = NULL;
    count = 0;
}

// Destructor
template <class T>
DList<T>::~DList()
{
    empty();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Insertion
template <class T>
dnode<T> *DList<T>::insertionSlot(T data)
{
    if (!sorted)
        return tail;
    dnode<T> *tempHead = head;
    dnode<T> *prev = NULL;
    while (tempHead != NULL && data > tempHead->data)
    {
        prev = tempHead;
        tempHead = tempHead->next;
    }
    return prev;
}
template <class T>
void DList<T>::insertNode(dnode<T> *p, dnode<T> *prev)
{
    if (head == NULL)
    {
        head = tail = p;
        p->next = NULL;
        p->prev = NULL;
    }
    else if (prev == NULL)
    {
        p->next = head;
        head->prev = p;
        p->prev = NULL;
        head = p;
    }
    else
    {
        p->next = prev->next;
        prev->next = p;
        p->prev = prev;
        if (tail == prev)
            tail = p;
        else
            p->next->prev = p;
    }
}
template <class T>
int DList<T>::insert(T data)
{
    dnode<T> *prev;
    dnode<T> *p = new (nothrow) dnode<T>;
    if (p == NULL)
        return -1;
    p->data = data;
    if (count == 0)
        prev = NULL;
    else
    {
        prev = insertionSlot(p->data);
    }

    insertNode(p, prev);
    count++;
    return 0;
}
template <class T>
void DList<T>::insertFirst(T data)
{
    dnode<T> *p = new (nothrow) dnode<T>;
    if (p == NULL)
        return;
    p->data = data;
    insertNode(p, NULL);
    count++;
}
template <class T>
void DList<T>::insertBack(T data)
{
    dnode<T> *p = new (nothrow) dnode<T>;
    if (p == NULL)
        return;
    p->data = data;
    insertNode(p, tail);
    count++;
}
template <class T>
void DList<T>::insertBefore(T before, T data)
{
    dnode<T> *prev;
    dnode<T> *p = new (nothrow) dnode<T>;
    if (p == NULL)
        return;
    p->data = data;
    if (count == 0)
        prev = NULL;
    else
    {
        prev = find(before)->prev;
    }

    insertNode(p, prev);
    count++;
}
template <class T>
void DList<T>::insertAfter(T after, T data)
{
    dnode<T> *prev;
    dnode<T> *p = new (nothrow) dnode<T>;
    if (p == NULL)
        return;
    p->data = data;
    if (count == 0)
        prev = NULL;
    else
    {
        prev = find(after);
    }

    insertNode(p, prev);
    count++;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Display
template <class T>
void DList<T>::DisplayForward(void (*displayer)(T data))
{
    dnode<T> *tempHead = head;
    while (tempHead != NULL)
    {
        displayer(tempHead->data);
        tempHead = tempHead->next;
    }
}
template <class T>
void DList<T>::DisplayBackward(void (*displayer)(T data))
{
    dnode<T> *tempTail = tail;
    while (tempTail != NULL)
    {
        displayer(tempTail->data);
        tempTail = tempTail->prev;
    }
}

// find
template <class T>
dnode<T> *DList<T>::find(T data)
{
    dnode<T> *tempHead = head;
    while (tempHead != NULL && tempHead->data != data)
    {
        if (sorted && data < tempHead->data)
            return NULL;
        tempHead = tempHead->next;
    }
    return tempHead;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// remove
template <class T>
void DList<T>::deleteNode(dnode<T> *p)
{
    if (head == tail)
    {
        head = tail = NULL;
    }
    else if (p->prev == NULL)
    {
        head = p->next;
        p->next->prev = NULL;
    }
    else
    {
        p->prev->next = p->next;
        if (p == tail)
            tail = p->prev;
        else
            p->next->prev = p->prev;
    }
    delete p;
    count--;
}
template <class T>
int DList<T>::remove(T data)
{
    dnode<T> *elem = find(data);
    if (elem == NULL)
        return -1;
    deleteNode(elem);
    return 0;
}
template <class T>
int DList<T>::removeFirst()
{
    if (head == NULL)
        return -1;
    deleteNode(head);
    return 0;
}
template <class T>
int DList<T>::removeLast()
{
    if (head == NULL)
        return -1;
    deleteNode(tail);
    return 0;
}
template <class T>
void DList<T>::empty()
{
    dnode<T> *p;
    while (head != NULL)
    {
        p = head->next;
        delete head;
        head = p;
    }
    tail = head;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Copy Constructor
template <class T>
DList<T>::DList(DList<T> &L)
{
    // TODO:
    cout << "\ncopy constructor\n";
    DList<T> *temp = (L.copy());
    ;
}
template <class T>
DList<T> DList<T>::copy()
{
    // TODO
    DList<T> *temp = new (nothrow) DList<T>(sorted);
    dnode<T> *tempHead = head;
    while (tempHead != NULL)
    {
        temp->insert(tempHead->data);
        tempHead = tempHead->next;
    }
    cout << "copy function\n";
    cout << "sorted: " << temp->sorted;
    temp->DisplayForward(&DefaultDisplayer);
    return *temp;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// range
template <class T>
void DList<T>::removeRange(T target1, T target2)
{
    dnode<T> *begin = NULL;
    dnode<T> *end = NULL;
    dnode<T> *tempHead = head;
    while (tempHead != NULL)
    {
        if (begin == NULL && tempHead->data == target1)
        {
            begin = tempHead;
        }
        if (begin != NULL && end == NULL && tempHead->data == target2)
        {
            end = tempHead;
        }
        tempHead=tempHead->next;
    }
    if (begin == end || begin == NULL || end == NULL)
    {
        cout << "\nInput data is invalid\n"
             << "Press enter to go back... ";
        cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
        return;
    }
    while(begin!=end){
        tempHead=begin->next;
        deleteNode(begin);
        begin=tempHead;
    }
    deleteNode(begin);//delete final element in the range
    
}
// void insertRangeBefore(T before, DList<T> range);
// void insertRangeAfter(T after, DList<T> range);

/*int main()
{
    DList<int> *a = new DList<int>(false);
    a->insertFirst(2);
    a->insert(9);
    a->insert(4);
    a->insert(44);
    a->insert(1);
    a->insert(18);
    a->insert(7);
    a->insertBefore(2, 12);
    a->DisplayForward(&DefaultDisplayer);
    cout << endl;
    a->removeRange(12,7);
    a->DisplayForward(&DefaultDisplayer);
    cout << endl;
        a->insert(9);
    a->insert(4);
    a->insert(44);
    a->DisplayForward(&DefaultDisplayer);

    // DList<int> *b =new DList<int>(*a);

    // b->DisplayForward(&DefaultDisplayer);
}*/