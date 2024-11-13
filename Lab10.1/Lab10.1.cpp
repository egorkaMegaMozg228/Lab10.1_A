#include <iostream>
#include <iomanip>
#include <string>
#include <locale>
using namespace std;

// Перелік для представлення спеціальності
enum Specialization { COMPUTER_SCIENCE, MATHEMATICS, PHYSICS, ENGINEERING, ECONOMICS };

// Структура для зберігання даних про студента
struct Student {
    string surname;
    int course;
    Specialization spec;
    double physics;
    double math;
    double informatics;
};

// Функція для виведення спеціальності у вигляді тексту
string getSpecializationName(Specialization spec) {
    switch (spec) {
    case COMPUTER_SCIENCE: return "Computer Science";
    case MATHEMATICS: return "Mathematics";
    case PHYSICS: return "Physics";
    case ENGINEERING: return "Engineering";
    case ECONOMICS: return "Economics";
    default: return "Unknown";
    }
}

// Функція для заповнення даних студента
void inputStudentData(Student& student) {
    cout << "Введiть прiзвище студента: ";
    cin >> student.surname;
    cout << "Введiть курс (цiле число): ";
    cin >> student.course;

    int specChoice;
    cout << "Оберiть спецiальнiсть (0 - Computer Science, 1 - Mathematics, 2 - Physics, 3 - Engineering, 4 - Economics): ";
    cin >> specChoice;
    student.spec = static_cast<Specialization>(specChoice);

    cout << "Введiть оцiнку з фiзики: ";
    cin >> student.physics;
    cout << "Введiть оцiнку з математики: ";
    cin >> student.math;
    cout << "Введiть оцiнку з iнформатики: ";
    cin >> student.informatics;
    cout << endl;
}

// Функція для формування масиву студентів
void createStudentsArray(Student students[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Студент №" << i + 1 << ":\n";
        inputStudentData(students[i]);
    }
}

// Функція для виведення таблиці з даними студентів
void printStudentsTable(const Student students[], int n) {
    cout << left << setw(5) << "№"
        << setw(15) << "Прiзвище"
        << setw(10) << "Курс"
        << setw(20) << "Спецiальнiсть"
        << setw(10) << "Фiзика"
        << setw(10) << "Математика"
        << setw(15) << "Iнформатика" << endl;

    cout << string(85, '-') << endl;

    for (int i = 0; i < n; i++) {
        cout << left << setw(5) << (i + 1)
            << setw(15) << students[i].surname
            << setw(10) << students[i].course
            << setw(20) << getSpecializationName(students[i].spec)
            << setw(10) << students[i].physics
            << setw(10) << students[i].math
            << setw(15) << students[i].informatics << endl;
    }
}

void Surnames(Student students[], int n) {

    for (int i = 0; i < n; i++) {
        if (students[i].physics == 5) {
            cout << students[i].surname << endl;
        }
    }
}

double countExcellentGrades(const Student students[], int n) {
    double exellentCount = 0, percent;

    for (int i = 0; i < n; i++) {
        if (students[i].physics == 5
            && students[i].math == 5 &&
            students[i].informatics == 5)
            exellentCount++;
    }
    percent = exellentCount / n;
    return percent;
}



int main() {
    setlocale(LC_CTYPE, "ukr");
    int n;
    cout << "Введiть кiлькiсть студентiв: ";
    cin >> n;

    Student* students = new Student[n];

    createStudentsArray(students, n);
    

    cout << "\nТаблиця студентiв:\n";
    printStudentsTable(students, n);

    cout << "\nвiдсоток вiдмiнникiв: " << countExcellentGrades(students, n) * 100 << "%" << endl;
    cout << "Прiзвища студентiв, що отримали 5 з фiзики:" << endl;
    Surnames(students, n);


    delete[] students;
    return 0;
}