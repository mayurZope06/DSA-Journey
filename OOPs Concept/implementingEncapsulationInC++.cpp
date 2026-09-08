#include <iostream>
using namespace std;

class Student
{
    private:
        int id;
        int age;
        string name;
        int nos;
        float *gpa;
        string gf;
    public:
        void setGpa(float a)
        {
            //layer of authetication
            *this -> gpa = a;
        }
        float getGpa() const
        {
            return *this -> gpa;
        }
        float getAge() const
        {
            return this -> age;
        }

        //Default Constructor
        Student()
        {
            cout << "Student Default Constructor called." << endl;
        }

        //Parameterised Constructor
        Student(int id, int age, string name, int nos , float gpa, string gf)
        {
            cout << "Student Parameterised Constructor called. " <<endl;
            this -> id = id;
            this -> age = age;
            this -> name = name;
            this -> nos = nos;
            this -> gpa = new float (gpa);
            this -> gf = gf;
        }

    private:
        void gfChatting()
        {
            cout << this -> name << " chatting wiht gf" << endl;
        }

};
int main()
{
    Student A(1, 12, "Ranu", 5, 7.8, "Menu");
    cout << A.getGpa() << endl;
    A.setGpa(6.7);
    cout << A.getGpa() << endl;
    cout << A.getAge() << endl;
    return 0;
}