#ifndef __TODO_H__
#define __TODO_H__

#include "task.h"
#include "taskList.h"

class Todo {
public:
    /// Add a new incomplete task to the Todo list.
    /// If a task with the same name exists in the list, nothing is done and `false` is returned.
    bool add(const Task& task);

    /// Mark a task as completed.
    /// If no incomplete tasks with the given name exists, nothing is done and `false` is returned.
    bool complete(const char* taskName);

    /// Returns the list of all completed tasks
    const TaskList& getCompleted() const;

    /// Returns the list of all incomplete tasks
    const TaskList& getIncomplete() const;

private:
    TaskList completeTasks;
    TaskList incompleteTasks;
};

#endif
