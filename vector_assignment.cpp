#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Student
{
private:
    int age;
    string name;
    double grade;

public:

    // Setters
    void setAge(int a)
    {
        age = a;
    }

    void setName(string n)
    {
        name = n;
    }

    void setGrade(double g)
    {
        grade = g;
    }

    // Getters
    int getAge() const
    {
        return age;
    }

    string getName() const
    {
        return name;
    }

    double getGrade() const
    {
        return grade;
    }
};


// Add Student
void addStudent(vector<Student>& students)
{
    Student s;

    int age;
    string name;
    double grade;

    cout << "Enter name: ";
    cin >> name;

    cout << "Enter age: ";
    cin >> age;

    cout << "Enter grade: ";
    cin >> grade;

    s.setName(name);
    s.setAge(age);
    s.setGrade(grade);

    students.push_back(s);

    cout << "Student added successfully!\n";
}


// Print All Students
void printStudents(const vector<Student>& students)
{
    if (students.empty())
    {
        cout << "No students available.\n";
        return;
    }

    cout << "\n===== Students =====\n";

    for (int i = 0; i < students.size(); i++)
    {
        cout << "Student #" << i + 1 << endl;
        cout << "Name: " << students[i].getName() << endl;
        cout << "Age: " << students[i].getAge() << endl;
        cout << "Grade: " << students[i].getGrade() << endl;
        cout << "-------------------\n";
    }
}


// Print Top 5
void printTopFive(vector<Student> students)
{
    if (students.empty())
    {
        cout << "No students available.\n";
        return;
    }

    for (int i = 0; i < students.size(); i++)
    {
        for (int j = i + 1; j < students.size(); j++)
        {
            if (students[i].getGrade() < students[j].getGrade())
            {
                swap(students[i], students[j]);
            }
        }
    }

    int top = min(5, (int)students.size());

    cout << "\n===== Top " << top << " Students =====\n";

    for (int i = 0; i < top; i++)
    {
        cout << i + 1 << ". "
             << students[i].getName()
             << " - Grade: "
             << students[i].getGrade()
             << endl;
    }
}


// Main
int main()
{
    vector<Student> students;

    int choice;

    do
    {
        cout << "\n========== MENU ==========\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Display Top 5 Students\n";
        cout << "4. Exit\n";
        cout << "===========================\n";

        cout << "Choose: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addStudent(students);
            break;

        case 2:
            printStudents(students);
            break;

        case 3:
            printTopFive(students);
            break;

        case 4:
            cout << "Goodbye!\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 4);

    return 0;
}