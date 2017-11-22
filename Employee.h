#pragma once
#include "Person.h"
/*
Implementación de la clase Employee, "hija" de Person.
Su mutador privado es:
salary: el salario del empleado.

*/
class Employee : public Person {
private:
    double salary;
public:
    Employee();
    Employee(string,string,int,char,double);
    ~Employee();
    double getSalary();
    void setSalary(double);
    string toString();
};
