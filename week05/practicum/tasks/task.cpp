#include "task.h"

Task::Task(const char* name, int priority, const char* desc) {
    this->create(name, priority, desc);
}

Task::~Task() {
    this->destroy();
}

Task::Task(const Task& other) {
    this->create(other.name, other.priority, other.desc);
}

Task& Task::operator= (const Task& other) {
    if (this != &other) {
        this->destroy();
        this->create(other.name, other.priority, other.desc);
    }
    return *this;
}

const char* Task::getName() const {
    return this->name;
}

int Task::getPriority() const {
    return this->priority;
}

const char* Task::getDesc() const {
    return this->desc;
}

// Когато обекта ни се инициализи с масив или низ трябва да си направим лично копие на данните.
// Това е защото оригиналните данни могат да бъдат изтрити или променени и не бихме искали това
// да се отразява на нашия обект.
void Task::create(const char* name, int priority, const char* desc) {
    size_t nameLen = strlen(name) + 1;
    this->name = new char[nameLen];
    strncpy(this->name, name, nameLen);

    size_t descLen = strlen(desc) + 1;
    this->desc = new char[descLen];
    strncpy(this->desc, desc, descLen);

    this->priority = priority;
}

void Task::destroy() {
    delete[] this->name;
    delete[] this->desc;
}

std::ostream& operator<< (std::ostream& os, const Task& task) {
    os << "Task { ";
    os << "\"" << task.getName() << "\", ";
    os << task.getPriority() << ", ";
    os << "\"" << task.getDesc() << "\" ";
    os << "}";

    return os;
}
