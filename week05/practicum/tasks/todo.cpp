#include "todo.h"

bool Todo::add(const Task& task) {
    return this->incompleteTasks.add(task);
}

bool Todo::complete(const char* taskName) {
    Task* ptr = this->incompleteTasks.get(taskName);
    if (ptr == NULL) {
        return false;
    }

    // Създаваме си локалко копие на задачата.
    // Това се налага, защото знаем че указателя, върнат от `get`, ще стане
    // невалиден когато извикаме функцията `remove`.
    Task task = *ptr;

    this->incompleteTasks.remove(taskName);
    this->completeTasks.remove(taskName);
    this->completeTasks.add(task);
    return true;
}

const TaskList& Todo::getCompleted() const {
    return this->completeTasks;
}

const TaskList& Todo::getIncomplete() const {
    return this->incompleteTasks;
}
