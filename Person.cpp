#include "Person.h"

Person::Person(){
 }

Person::Person(string nombre,string apellido,int edad,char genero){
    //se asignan los respectivos valores a cada uno de los mutadores.
    name = nombre;
    last_name=apellido;
    age = edad;
    gender = genero;

}
Person::~Person(){
}

string Person::getName(){
    return name;
}

void Person::setName(string nombre){
    name = nombre;
}

string Person::getLastName(){
    return last_name;
}

void Person::setLastName(string apellido){
    last_name = apellido;
}

int Person::getAge(){
    return age;
}

void Person::setAge(int edad){
    if (edad > 0) {
        age = edad;
    }
}

char Person::getGender(){
    return gender;
}

void Person::setGender(char genero){
    gender= genero;
}

string Person::toString(){
    stringstream ss;
    string genero;
    if(gender == 'f'){
        genero = "Femenino";
    }else{
        genero = "Masculino";
    }

    ss<<"Nombre: "<<name << " " <<last_name << " | Edad: " <<age <<" | Género: "<<genero ;
    return ss.str();

};
