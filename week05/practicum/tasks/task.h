#ifndef __TASK_H__
#define __TASK_H__

#include <cstddef>
#include <cstring>
#include <iostream>

class Task {
public:
    Task(const char* name, int priority, const char* desc);
    ~Task();

    Task(const Task& other);
    Task& operator= (const Task& other);

    const char* getName() const;
    int getPriority() const;
    const char* getDesc() const;

private:
    void create(const char* name, int priority, const char* desc);
    void destroy();

    char* name;
    char* desc;
    int priority;
};

std::ostream& operator<< (std::ostream& os, const Task& task);

#endif
