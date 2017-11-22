#pragma once
#include "Object.h"
#include <string>

using namespace std;
/*
Implementacion de la clase Person, "hija" de Object.
Sus respectivos mutadores son:
name: nombre de la persona.
last_name: apellido de la persona.
age : Edad de la persona:
gender: Género de la persona:

Nota: en vez de usar un char para el genero, sería mejor utilizar un
      "bool" (ya que solo existen 2 opciones).
*/
class Person : public Object {

protected:
    string name;
    string last_name;
    int age;
    char gender;
public:
    Person();
    Person(string,string,int,char);
    ~Person();
    string getName();
    void setName(string);
    string getLastName();
    void setLastName(string);
    int getAge();
    void setAge(int);
    char getGender();
    void setGender(char);
    string toString();
};
