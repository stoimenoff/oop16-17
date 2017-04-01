#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__

#include <cstddef> // - за size_t

struct Node
{
	int data;
	Node* next;
	Node(int data, Node* next = nullptr) : data(data), next(next) {}
};

class LinkedList
{
	Node* start;
	size_t elements_count;

	// Рекурсивен и итеративен вариант на функцията за копиране
	Node* copy_list_iterative(Node* start) const;
	Node* copy_list_recursive(Node* start) const;
	Node* copy_list(Node* start) const; // просто извиква една от горните две

	// Рекурсивен и итеративен вариант на функцията за намиране на последен елемент
	Node* get_last_iterative(Node* start) const;
	Node* get_last_recursive(Node* start) const;
	Node* get_last(Node* start) const; // просто извиква една от горните две

	Node* get_node_at(size_t position) const;
public:
	LinkedList();
	LinkedList(const LinkedList& other);
	LinkedList& operator=(const LinkedList& other);
	~LinkedList();

	size_t size() const;
	bool empty() const;
	bool member(int element) const;
	void print() const;
	int operator[] (size_t position) const;
	LinkedList operator+ (const LinkedList& other) const;

	void clear();
	void push_front(int new_element);
	void pop_front();
	void push_back(int new_element);
	void pop_back();
	void insert_before(size_t position, int new_element);
	void remove_before(size_t position);
	void insert_after(size_t position, int new_element);
	void remove_after(size_t position);
	void reverse();
};

#endif
