#include "Employee.h"

Employee::Employee(){ }

Employee::Employee(string nombre,string apellido,int edad,char genero,double salario) : Person (nombre,apellido, edad,genero){
    //se asignan los respectivos valores a cada uno de los mutadores.
    this->salary = salario;
}

Employee::~Employee(){ }

double Employee::getSalary(){
    return this->salary;
}

void Employee::setSalary(double salario){
    this->salary = salario;
}

string Employee::toString(){
    stringstream ss;
    ss << Person::toString() << " | Salario: " <<this->salary<< endl;
    return ss.str();
}
