#include <iostream>
#include <string>
#include <limits>
template <class T>
struct dnode
{
	T data;
	dnode<T> *prev;
	dnode<T> *next;
};
template <class T>
void DefaultDisplayer(T data)
{
	std::cout << data << " ";
}
template <class T>
class DList
{
public:
	DList();				  // default constructor
	DList(bool sorted);		  // other constructor
	DList( DList<T> &L); // copy constructor. it is used when you create a new object from existing DList object
	virtual ~DList();		  // destructor
	bool isEmpty(){return head==NULL;}
	void insertFirst(T data);	 // insert first
	void insertBack(T data);	 // insert last
	void insertBefore(T before, T data); // insert before first occurrence of some data
	void insertAfter(T after, T data);	 // insert before last occurrence of some data
	int insert(T data);			 // insert at last for unsorted, insert at appropriate position
	void insertRangeBefore(T before, DList<T> range);
	void insertRangeAfter(T after, DList<T> range);
	int removeFirst(); // remove first
	int removeLast();  // remove last
	int remove(T data);
	void removeRange(T target1, T target2);
	dnode<T> *find(T data); // search first occurrence
	void empty();			// destroy the linked list
	DList<T> copy();		// copy and return linked list
	void DisplayForward(void (*displayer)(T data));
	void DisplayBackward(void (*displayer)(T data));

protected:
	dnode<T> *head;
	dnode<T> *tail;
	int count;

private:
	void insertNode(dnode<T> *p, dnode<T> *prev);
	void deleteNode(dnode<T> *p);	 // p is the node to be deleted
	dnode<T> *insertionSlot(T data); // finds insertion position
	bool sorted;					 // whether the list is sorted or not
};