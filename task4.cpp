#include <iostream>
#include <vector>
#include <string>

struct Employee {
    int id;
    std::string name;
    std::string position;
};

std::vector<Employee> employees;

// Функция добавления нового сотрудника
void addEmployee() {
    Employee newEmp;
    std::cout << "Введите ID: ";
    std::cin >> newEmp.id;
    std::cin.ignore(); // Очистка потока ввода
    std::cout << "Введите имя: ";
    getline(std::cin, newEmp.name);
    std::cout << "Введите должность: ";
    getline(std::cin, newEmp.position);

    employees.push_back(newEmp);
}

// Функция удаления сотрудника
void deleteEmployee() {
    int id;
    std::cout << "Введите ID удаляемого сотрудника: ";
    std::cin >> id;

    for (auto it = employees.begin(); it != employees.end(); ++it) {
        if (it->id == id) {
            employees.erase(it);
            return; // Прекращаем поиск после успешного удаления
        }
    }
    std::cout << "Сотрудник с таким ID не найден." << std::endl;
}

// Функция обновления информации о сотруднике
void updateEmployee() {
    int id;
    std::cout << "Введите ID сотрудника для обновления: ";
    std::cin >> id;

    for (auto &employee : employees) {
        if (employee.id == id) {
            std::cout << "Введите новое имя: ";
            std::cin.ignore(); // Очистка потока ввода
            getline(std::cin, employee.name);
            std::cout << "Введите новую должность: ";
            getline(std::cin, employee.position);
            return; // Завершаем функцию после успешного обновления
        }
    }
    std::cout << "Сотрудник с таким ID не найден." << std::endl;
}

// Функция вывода информации о всех сотрудниках
void printEmployees() {
    if(employees.empty()) {
        std::cout << "Список сотрудников пуст." << std::endl;
        return;
    }

    for (const auto& employee : employees) {
        std::cout << "ID: "     << employee.id
                  << ", Имя: "  << employee.name
                  << ", Должность: "<< employee.position
                  << "."            << std::endl;
    }
}

// Указатель на функцию для выбранной операции
typedef void (*OperationFunction)();
OperationFunction operations[] = {addEmployee, deleteEmployee, updateEmployee, printEmployees};

int main() {
    int choice;

    while (true) {
        std::cout <<"Выберите действие:\n"
                 <<"1. Добавить нового сотрудника\n"
                 <<"2. Удалить существующего сотрудника\n"
                 <<"3. Обновить информацию о сотруднике\n"
                 <<"4. Вывести информацию о всех сотрудниках\n"
                 <<"5. Выход\n";

        std::cin >> choice;

        if(choice < 1 || choice > 5){
            std::cerr<<"Неверный выбор! Попробуйте еще раз.\n";
            continue;
        }

        if(choice == 5) break;

       // Вызов соответствующей функции через указатель на функцию из массива operations,
       // отнимаем 1 для корректной индексации массива.
       (*operations[choice - 1])();

       //Добавляем пространство межу выборами пользователя для лучшей читаемости.
        std :: cout<<"\n";
    }

    return 0;
}