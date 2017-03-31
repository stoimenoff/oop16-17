#include <iostream>
#include "task.h"
#include "taskList.h"
#include "todo.h"

int main() {
    Todo todo;
    todo.add(Task("foo", 6, "Lorem ipsum dolor sit amet, consectetur adipiscing elit."));
    todo.add(Task("bar", 11, "Morbi luctus ac tortor vel condimentum."));
    todo.add(Task("buz", 4, "Aliquam erat volutpat."));
    todo.add(Task("quiz", 20, "Morbi bibendum nisl velit, non ornare nisl semper sit amet."));
    todo.complete("buz");
    todo.complete("bar");
    todo.add(Task("alg", 900, "Find a use for Algebra II in real life."));

    std::cout << "Completed tasks:\n";
    todo.getCompleted().print(std::cout);

    std::cout << "Incomplete tasks:\n";
    todo.getIncomplete().print(std::cout);
}
