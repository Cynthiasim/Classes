//  Cynthia Simon
//  csimon2@leomail.tamuc.edu
//  Assignment #2
//  Program to create Person and Employee Class
#include <iostream>
#include <string>

using namespace std;

class Person
{
protected:
    string name;
    int age;
    
public:
    string getName();
    int getAge();
    
    void setName(string name);
    void setAge(int age);
    
    Person(int age, string name);
    
    bool operator>=(const Person &other);    // overload the greater than or equal to operator
    bool operator<(const Person &other);    // overload the less than operator
    bool operator==(const Person &other);  // overload the equal operator
    
    friend istream& operator>>(istream &in, Person &p); // overload the insertion operator
    friend ostream& operator<<(ostream &out, Person &p); //overload the extraction operator
};

Person::Person(int age, string name) : name(name), age (age){} //constructor

void Person::setName(string name)  // mutator
{
    this->name = name;
}

void Person::setAge(int age) // mutator
{
    this->age = age;
}

string Person:: getName() //get the name
{
    return name;
}

int Person::getAge() //get the age
{
    return age;
}

//operator overloading
bool Person::operator>=(const Person &other)
{
    return(age >= other.age);
}

bool Person::operator==(const Person &other)
{
    return(age == other.age);
}

bool Person::operator<(const Person &other)
{
    return(age < other.age);
}

istream& operator>>(istream &in, Person &p)
{
    in>>p.age>>p.name;
    return in;
}

ostream& operator<<(ostream &out, Person &p)
{
    out<<"Name: " <<p.name<<endl;
    out<<"Age: " <<p.age<<endl;
    
    return out;
}

class Employee: public Person
{
private:
    string address;
    int id;
    
public:
    
    string getAddress();
    int getId();
    
    void setAddress(string address);
    void setId(int id);
    
    bool operator==(const Employee &other);
    friend istream& operator>>(istream &in,Employee&p);
    friend ostream& operator<<(ostream &out, Employee &p);
    
     Employee(int age, string name, string address, int id);
};

Employee::Employee(int age, string name, string address, int id): Person(age, name), address(address), id(id){} // constructor

void Employee::setAddress(string address) // mutator
{
    this -> address = address;
}

void Employee::setId(int id)
{
    this -> id = id;
}

// get
string Employee::getAddress()
{
    return address;
}

int Employee::getId()

{
    return id;
}

// operator overloading
bool Employee::operator==(const Employee &other)
{
    return(address==other.address);
}

istream& operator>>(istream &in, Employee &p)
{
    in>>p.age>>p.name>>p.address>>p.id;
    return in;
}

ostream& operator<<(ostream &out, Employee &p)
{
    out<<"Name: "<<p.name<<endl;
    out<<"Id: "<<p.id<<endl;
    out<<"Age: "<<p.age<<endl;
    out<<"Address: "<<p.address<<endl;
    return out;
}

int main()
{
    Person p1(23, "Jim J"), p2(23, "Jane J"), p3(32, "Ali A");
    Employee e1(34, "Tim T", "123 Main St", 1), e2(28, "Alex T", "123 Main St", 2);
    cout<<(p3<p3)<<endl;
    cout<<(p3>=p1)<<endl;
    cout<<(p1==p2)<<endl;
    cout<<p3<<e1<<endl;
    cout<<(e2==e1)<<endl;
    cout<<(e1==e2)<<endl;
    return 0;
}
