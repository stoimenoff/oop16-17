#include "LinkedList.h"

#include <iostream>
#include <cassert>

Node* LinkedList::copy_list_iterative(Node* start) const
{
	if (start == nullptr)
		return nullptr;
	Node* new_list_start = new Node(start->data);
	Node* new_list_end = new_list_start;
	for (Node* current = start->next; current != nullptr; current = current->next)
	{
		new_list_end->next = new Node(current->data);
		new_list_end = new_list_end->next;
	}
	return new_list_start;
}

Node* LinkedList::copy_list_recursive(Node* start) const
{
	if (start == nullptr)
		return nullptr;
	return new Node(start->data, copy_list_recursive(start->next));
}

Node* LinkedList::copy_list(Node* start) const
{
	return copy_list_iterative(start);
}

Node* LinkedList::get_last_iterative(Node* start) const
{
	if (start == nullptr)
		return nullptr;
	Node* last = start;
	while (last->next != nullptr)
	{
		last = last->next;
	}
	return last;
}

Node* LinkedList::get_last_recursive(Node* start) const
{
	if (start == nullptr)
		return nullptr;
	if (start->next == nullptr)
		return start;
	return get_last_recursive(start->next);
}

Node* LinkedList::get_last(Node* start) const
{
	return get_last_iterative(start);
}

Node* LinkedList::get_node_at(size_t position) const
{
	assert(position < size());
	Node* current = start;
	for (int i = 0; i < position; ++i)
		current = current->next;
	return current;
}

LinkedList::LinkedList() : start(nullptr), elements_count(0) {}

LinkedList::LinkedList(const LinkedList& other)
{
	start = copy_list(other.start);
	elements_count = other.elements_count;
}

LinkedList& LinkedList::operator=(const LinkedList& other)
{
	if (this != &other)
	{
		clear();
		start = copy_list(other.start);
		elements_count = other.elements_count;
	}
	return *this;
}

LinkedList::~LinkedList()
{
	clear();
}

size_t LinkedList::size() const
{
	return elements_count;
}

bool LinkedList::empty() const
{
	return size() == 0;
}

bool LinkedList::member(int element) const
{
	for (Node* current = start; current != nullptr; current = current->next)
		if (current->data == element)
			return true;
	return false;
}

void LinkedList::print() const
{
	std::cout << "[";
	for (Node* current = start; current != nullptr; current = current->next)
	{
		std::cout << current->data;
		if (current->next != nullptr)
			std::cout << ", ";
	}
	std::cout << "]" << std::endl;
}

int LinkedList::operator[] (size_t position) const
{
	return get_node_at(position)->data;
}

LinkedList LinkedList::operator+ (const LinkedList& other) const
{
	if (start == nullptr)
		return other; // ще върне копие!
	Node* concatenation_start = copy_list(start);
	Node* concatenation_last = get_last(concatenation_start);
	concatenation_last->next = copy_list(other.start);

	LinkedList concatenation;
	concatenation.start = concatenation_start;
	return concatenation;
}

void LinkedList::clear()
{
	while (!empty())
		pop_front();
}

void LinkedList::push_front(int new_element)
{
	start = new Node(new_element, start);
	++elements_count;
}

void LinkedList::pop_front()
{
	assert(!empty());
	Node* node_to_delete = start;
	start = start->next;
	delete node_to_delete;
	--elements_count;
}

void LinkedList::push_back(int new_element)
{
	if (empty())
	{
		push_front(new_element);
	}
	else
	{
		Node* last = get_last(start);
		last->next = new Node(new_element);
		++elements_count;
	}

}

void LinkedList::pop_back()
{
	assert(!empty());
	if (size() == 1)
	{
		pop_front();
	}
	else
	{
		Node* before_last = get_node_at(size() - 2);
		delete before_last->next;
		before_last->next = nullptr;
		--elements_count;
	}
}

void LinkedList::insert_before(size_t position, int new_element)
{
	assert(position < size());
	if (position == 0)
	{
		push_front(new_element);
	}
	else
	{
		Node* node_before_position = get_node_at(position - 1);
		Node* node_at_position = node_before_position->next;
		node_before_position->next = new Node(new_element, node_at_position);
		++elements_count;
	}
}

void LinkedList::remove_before(size_t position)
{
	assert(position > 0 && position < size());
	if (position == 1)
	{
		pop_front();
	}
	else
	{
		Node* node_before_deleted = get_node_at(position - 2);
		Node* node_to_delete = node_before_deleted->next;
		node_before_deleted->next = node_to_delete->next;
		// можеше и node_before_deleted->next = node_before_deleted->next->next;
		delete node_to_delete;
		--elements_count;
	}
}

void LinkedList::insert_after(size_t position, int new_element)
{
	assert(position < size());
	Node* node_at_position = get_node_at(position);
	node_at_position->next = new Node(new_element, node_at_position->next);
	++elements_count;
}

void LinkedList::remove_after(size_t position)
{
	assert(position < size() - 1);
	Node* node_at_position = get_node_at(position);
	Node* node_to_delete = node_at_position->next;
	node_at_position->next = node_to_delete->next;
	delete node_to_delete;
	--elements_count;
}

void LinkedList::reverse()
{
	/* Функцията работи in-place - не заделя нова памет, а само пренасочва
		указателите във вече съществуващите възли на свързания списък. */
	Node *before = nullptr, *current = start, *after = nullptr;
	while (current != nullptr)
	{
		after = current->next;
		current->next = before;

		before = current;
		current = after;
	}
	start = before;
}
