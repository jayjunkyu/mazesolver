// by JJeong

#include "deque.hpp"
#include <exception>

template <typename T>
int Deque<T>::getLength()
{
	return count;
}

template <typename T>
Deque<T>::Deque()
{
	//Set all pointers to null
	head = nullptr;
	tail = nullptr;
	count = 0;
}

template <typename T>
Deque<T>::~Deque()
{
	//pop until empty
	while (!isEmpty())
	{
		popBack();
	}
}

template <typename T>
Deque<T>::Deque(const Deque<T>& original)
{
	//Create temp node and copy head pointer of original object
	Node<T>* temp;
	temp = original.head;

	//Set head and tail of the object being copied into to hull (constructor)
	head = nullptr;
	tail = nullptr;
	count = 0;

	//copy all content from original to created object using pushBack and next
	while (temp != nullptr)
	{
		pushBack(temp->data);
		temp = temp->next;
	}
}

template <typename T>
Deque<T>& Deque<T>::operator=(const Deque<T> &original)
{
	//Checking if both objects are not equal
	if (this != &original)
	{
		while (!isEmpty())
			popFront();

		//Constructor
		head = nullptr;
		tail = nullptr;
		count = 0;

		//Create temp node and copy content
		Node<T>* temp;
		temp = original.head;

		while (temp != nullptr)
		{
			pushBack(temp->data);
			temp = temp->next;
		}
	}

	//returning object
	return *this;
}

/** Returns true if the deque is empty, else false
*/
template <typename T>
bool Deque<T>::isEmpty() const noexcept
{
	//returns true if head and tail is null
	return head == nullptr && tail == nullptr;
}

/** Add item to the front of the deque
* may throw std::bad_alloc
*/
template <typename T>
void Deque<T>::pushFront(const T& item)
{
	//create a node in the "heap", set prev and next to null and data to "item" from function
	Node<T>* newNode = new Node<T>;
	newNode->data = item;
	newNode->prev = nullptr;
	newNode->next = nullptr;

	//base case where list is empty
	if (isEmpty())
	{
		head = newNode;
		tail = newNode;
		count++;
		return;
	}
	//case where list is not empty
	else
	{
		head->prev = newNode;
		newNode->next = head;
		head = newNode;
		count++;
	}
}

/** Remove the item at the front of the deque
* throws std::runtime_error if the deque is empty
*/
template <typename T>
void Deque<T>::popFront()
{
	if (!isEmpty())
	{
		//case where list has only 1 item
		if (count == 1)
		{
			delete head;
			head = nullptr;
			tail = nullptr;
			count--;
			return;
		}

		//create local temp node to delete address of delete node
		Node<T>* temp;
		temp = head;
		head = head->next;
		delete temp;
		temp = nullptr;
		head->prev = nullptr;
		count--;
	}
	else
		throw std::runtime_error("List is empty.");
}

/** Returns the item at the front of the deque
* throws std::runtime_error if the deque is empty
*/
template <typename T>
T Deque<T>::front() const
{
	//return data of head
	if (!isEmpty())
		return head->data;
	else
		throw std::runtime_error("List is empty.");
}

/** Add item to the back of the deque
* may throw std::bad_alloc
*/
template <typename T>
void Deque<T>::pushBack(const T& item)
{
	//same logic as pushFront()
	Node<T>* newNode = new Node<T>;
	newNode->data = item;
	newNode->prev = nullptr;
	newNode->next = nullptr;

	if (isEmpty())
	{
		head = newNode;
		tail = newNode;
		count++;
		return;
	}
	//samel logic as pushFront()
	else
	{
		tail->next = newNode;
		newNode->prev = tail;
		tail = newNode;
		count++;
	}
}


/** Remove the item at the back of the deque
* throws std::runtime_error if the deque is empty
*/
template <typename T>
void Deque<T>::popBack()
{
	//same logic as popFront()
	if (!isEmpty())
	{
		if (count == 1)
		{
			delete head;
			head = nullptr;
			tail = nullptr;
			count--;
			return;
		}

		Node<T>* temp;
		temp = tail;
		tail = tail->prev;
		delete temp;
		temp = nullptr;
		tail->next = nullptr;
		count--;
	}
	else
		throw std::runtime_error("List is empty.");
}

/** Returns the item at the back of the deque
* throws std::runtime_error if the deque is empty
*/
template <typename T>
T Deque<T>::back() const
{
	//return data from tail
	if (!isEmpty())
		return tail->data;
	else
		throw std::runtime_error("List is empty.");
}