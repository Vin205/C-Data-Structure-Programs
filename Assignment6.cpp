#include <iostream>
#include <string>
#include <ctime>

using namespace std;

struct Student {
    string name;
    string birthday;
    Student* next;
};

Student* head = nullptr;

// Function to insert a new student into the linked list
void insertStudent() {
    Student* newStudent = new Student;
    cout << "Enter student name: ";
    cin >> newStudent->name;
    cout << "Enter student birthday (dd/mm/yyyy): ";
    cin >> newStudent->birthday;
    newStudent->next = head;
    head = newStudent;
    cout << "Student added successfully." << endl;
}

// Function to delete a student entry
void deleteStudent() {
    if (head == nullptr) {
        cout << "The list is empty." << endl;
        return;
    }

    string targetName;
    cout << "Enter the name of the student to delete: ";
    cin >> targetName;

    if (head->name == targetName) {
        Student* temp = head;
        head = head->next;
        delete temp;
        cout << "Student deleted successfully." << endl;
        return;
    }

    Student* current = head;
    while (current->next != nullptr && current->next->name != targetName) {
        current = current->next;
    }

    if (current->next == nullptr) {
        cout << "Student not found." << endl;
    } else {
        Student* temp = current->next;
        current->next = current->next->next;
        delete temp;
        cout << "Student deleted successfully." << endl;
    }
}

// Function to display a happy birthday message for today's birthdays
void displayBirthdayMessage() {
    time_t now = time(0);
    tm* today = localtime(&now);
    string todayDate = to_string(today->tm_mday) + "/" + to_string(today->tm_mon + 1) + "/" + to_string(today->tm_year + 1900);

    Student* current = head;
    while (current != nullptr) {
        if (current->birthday == todayDate) {
            cout << "Happy birthday, " << current->name << "!" << endl;
        }
        current = current->next;
    }
}

// Function to display the list of students with their birthdays
void displayStudentList() {
    Student* current = head;
    while (current != nullptr) {
        cout << "Name: " << current->name << ", Birthday: " << current->birthday << endl;
        current = current->next;
    }
}

int main() {
    int choice;
    while (true) {
        cout << "Menu:" << endl;
        cout << "1. Insert new student" << endl;
        cout << "2. Delete student entry" << endl;
        cout << "3. Display birthday message" << endl;
        cout << "4. Display student list" << endl;
        cout << "5. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                insertStudent();
                break;
            case 2:
                deleteStudent();
                break;
            case 3:
                displayBirthdayMessage();
                break;
            case 4:
                displayStudentList();
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
