// by JJeong

#ifndef DEQUE_HPP
#define DEQUE_HPP

#include "abstract_deque.hpp"
#include <stdlib.h>
#include <stdio.h>
#include <exception>

template<typename T>
struct Node
{
	T data;
	Node* next;
	Node* prev;
};

template <typename T>
class Deque : public AbstractDeque<T> {

	// TODO
private:
	Node<T>* head;
	Node<T>* tail;
	int count;

public:
	Deque();

	~Deque();

	Deque(const Deque<T> &original);

	Deque &operator=(const Deque<T>& original);

	/** Returns true if the deque is empty, else false
	*/
	bool isEmpty() const noexcept;

	/** Add item to the front of the deque
	* may throw std::bad_alloc
	*/
	void pushFront(const T& item);

	/** Remove the item at the front of the deque
	* throws std::runtime_error if the deque is empty
	*/
	void popFront();

	/** Returns the item at the front of the deque
	* throws std::runtime_error if the deque is empty
	*/
	T front() const;

	/** Add item to the back of the deque
	* may throw std::bad_alloc
	*/
	void pushBack(const T& item);


	/** Remove the item at the back of the deque
	* throws std::runtime_error if the deque is empty
	*/
	void popBack();


	/** Returns the item at the back of the deque
	* throws std::runtime_error if the deque is empty
	*/
	T back() const;

	//returns count
	int getLength();
};

#include "deque.tpp"

#endif
