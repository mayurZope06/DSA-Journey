#include <iostream>
using namespace std;

class Student
{
    public:
        //Attributes
        int id;
        int age;
        string name;
        int nos;
        int *gpa;

        //Default Constructor
        Student()
        {
            cout << "Student Default Constructor called." << endl;
        }

        //Parameterised Constructor
        Student(int id, int age, string name, int nos , float gpa)
        {
            cout << "Student Parameterised Constructor called. " <<endl;
            this -> id = id;
            this -> age = age;
            this -> name = name;
            this -> nos = nos;
            this -> gpa = new int (gpa);
        }

        //Copy Constructor
        Student(const Student &srcObj) // srcObj => A
        {
            cout << "Student Copy Constructor called. " <<endl;
            this -> id = srcObj.id;
            this -> age = srcObj.age;
            this -> name = srcObj.name;
            this -> nos = srcObj.nos;
        }

        //Behaviour / Methods / Functions
        void study()
        {
            cout << this -> name << " studying " << endl;
        }
        void sleep()
        {
            cout << this -> name << " sleeping " << endl;
        }
        void bunk()
        {
            cout << this -> name << " bunking " << endl;
        }

        //Destructor
        ~Student()
        {
             cout << "Student Default destructor called. " <<endl;
        }
};
int main()
{
    // Student A;
    // A.id = 1;
    // A.age = 15;
    // A.name = "Ranu";
    // A.nos = 6;
    // A.study();

    // Student B;
    // B.id = 2;
    // B.age = 15;
    // B.name = "Rahul";
    // B.nos = 5;
    // B.bunk();

    //Student A(1, 15, "Ranu", 6); // stack
    // Student B(2, 13, "Rahul", 4); 
    // Student C(1, 11, "Rena", 6); 
    // Student D(1, 43, "Ronaldo", 6); 
    // A.bunk();
    // B.sleep();

    //Copy Constructor
    // Student C = A; // or Student C(A);
    // cout << C.name << " " << A.name << endl;

    //Dynamic allocation or student pointer;
    Student *A = new Student(6, 18, "Mayur", 7, 9.86);
    cout << A -> name << endl;
    cout << A -> age << endl;
    A -> study();
    delete A;
    
    return 0;
}