#include <utility>
#include <limits>
#include "taskList.h"

// Дефинираме си константата `NOT_FOUND` за помощната ни функция.
// Понеже константата се използва само вътрешно от имплементацията,
// добро място да бъде дефинирана е в cpp файла. Така никой от външния
// свят не може да я види.
//
// Използваме най-голямата стойност на `size_t`, защото `size_t` e
// unsinged тип, т.е. не може да приема отрицателни стойностти като -1.
const size_t NOT_FOUND = std::numeric_limits<size_t>::max();

bool TaskList::add(const Task& task) {
    if (this->findIndex(task.getName()) != NOT_FOUND) {
        return false;
    }

    this->list.push_back(task);
    return true;
}

bool TaskList::remove(const char* taskName) {
    size_t index = this->findIndex(taskName);
    if (index == NOT_FOUND) {
        return false;
    }

    std::swap(this->list[index], this->list.back());
    this->list.pop_back();
    return true;
}

const Task* TaskList::get(const char* taskName) const {
    size_t index = this->findIndex(taskName);
    if (index == NOT_FOUND) {
        return NULL;
    }
    else {
        return &this->list[index];
    }
}

Task* TaskList::get(const char* taskName) {
    size_t index = this->findIndex(taskName);
    if (index == NOT_FOUND) {
        return NULL;
    }
    else {
        return &this->list[index];
    }
}

// Помощна функция, която намира индекса на задача със дадено заглавие
// или връща `NOT_FOUND` ако няма такава.
size_t TaskList::findIndex(const char* taskName) const {
    for (size_t i = 0; i < this->list.size(); i++) {
        const Task& curr = this->list[i];
        if (strcmp(curr.getName(), taskName) == 0) {
            return i;
        }
    }

    return NOT_FOUND;
}

// Отбелязали сме функцията `print` с `const`, защото е логично функцията
// за принтиране да не трябва да модифицира обекта. Но от нас се очаква да
// принтираме задачите подредени по приоритет, а те са записани разбъркани.
// Също така не можем да сортираме масива, защото функцията ни е `const`.
//
// Един вариант е да обходим с цикъл масива N пути и на всяко обхождане да намираме
// следващият по големина елемент. Понеже може да има няколко задачи с еднакъм
// приоритет ще ги сравняваме по наредената двойка (приоритет, индекс).
//
// За улеснение ще използваме класа `pair` от стандартната библиотека, който представлява
// наредена двойка (T1, T2). Изглежда подобно на:
//
// template <typename T1, typename T2> struct pair {
//      T1 first;
//      T2 second;
//  };
//
// За наше удобство има и много предефинирани оператори, като например оператори за
// сравнение (които работят както бихме очаквали за наредена двойка, първо сравняват
// first, ако са равни сравняват и second).
//
// П.С. Сортираме във възходящ ред.
void TaskList::print(std::ostream& os) const {
    os << "TaskList {\n";

    // най-големият елемент намерен до сега
    std::pair<int, size_t> prev = std::make_pair(std::numeric_limits<int>::min(), 0);

    for (size_t count = 0; count < this->list.size(); count++) {
        // най-малкият от всички оставащи, т.е. следващият след `prev`
        std::pair<int, size_t> min = prev;

        for (size_t i = 0; i < this->list.size(); i++) {
            // ключовата дума `auto` ни позволява да не пишем типа на променливата
            // и да оставим компилатора да отгатне какъв е.
            auto curr = std::make_pair(this->list[i].getPriority(), i);

            // Търсим само елементи които са след `prev`, т.е. `curr > prev`.
            // Текущият ни минимум е `min`. Ако намерим по-малъм обновяваме `min`.
            // Проверката `prev == min` е за граничният случай когато все още не сме намерили
            // елемент след `prev` в текущото обхождане, защото във външния цикъл задаваме `min = prev;`
            if ((curr > prev && prev == min) || (curr > prev && curr < min)) {
                min = curr;
            }
        }

        os << "\t" << this->list[min.second] << "\n";
        prev = min;
    }

    os << "}\n";
}
