#include "LinkedList.h"
#include "ADTList.h"
#include "Object.h"
#include "Person.h"
#include "Employee.h"
#include <string>
#include <iostream>

int menu();
void mayorSalario(LinkedList*);
void menorSalario(LinkedList*);
void Inflacion(LinkedList*);
void print(LinkedList*);
double SalarioPromedio(LinkedList*);

int main(int argc, char const *argv[]) {

    LinkedList* lista = new LinkedList();


    //Lineas comentadas en caso de que se quiera probar el programa con estos
    //registros.

    cout << lista->insert(new Employee("Juan","Lopez",20,'m',5000),0) << '\n';
    cout << lista->insert(new Employee("Pan","Queque",22,'m',402312),0) << '\n';
    cout << lista->insert(new Employee("Pasa","Montañas",20,'f',51),0) << '\n';
    cout << lista->insert(new Employee("Pepe","Grillo",232,'m',700),0) << '\n';
    cout << lista->insert(new Employee("Ese","Tipo",20,'m',897),0) << '\n';
    cout << lista->insert(new Employee("Esa","Chava",18,'f',1000),0) << '\n';


    int opcion = 0;
    while(opcion != -1){
        std::cout << "Tamaño actual de la lista: "<< lista->Size() << '\n'<<'\n';
        opcion = menu();

        if (opcion == 1 ) {
            string nombre = "";
            string apellido = "";
            int edad = 0;
            double salario = 0.0;
            char genero = ' ';
            string gender= "";
            int posicion=0;
            cout << "En esta opción se agregan empleados." << '\n';
            cout << "Ingrese los datos de su nuevo registro:" << '\n';
            cout << "Nombre:" << '\n';
            cin >> nombre;
            cout << "Apellido:" << '\n';
            cin >> apellido;

            while(edad <= 0){
                 cout << "Edad:" << '\n';
                cin>> edad;

                if(edad <= 0)
                    cout << "La edad debe ser mayor a cero (0)." << '\n';
            }

            while(salario <= 0.0){
                 cout << "Salario:" << '\n';
                cin>> salario;
                if(salario <= 0)
                    cout << "El salario debe ser mayor a cero (0)." << '\n';
            }

            int selected = 0;
            while(selected <= 0 || selected > 2){
                 cout << "Genero:" << '\n';
                 cout << "1) Femenino" << '\n';
                 cout << "2) Masculino" << '\n';
                cin >> selected;

                if (selected == 1) {
                    genero = 'f';
                }else if (selected == 2) {
                    genero = 'm';
                }else{
                     cout << "Ingrese una opción válida." << '\n';
                }

            }

            if (genero == 'f') {
                gender = "Femenino";
            }

            if (genero == 'm') {
                gender = "Masculino";
            }

            if(lista->Size()>0){
                int pos = -1;
                while (pos< 0 || pos> lista->Size()) {

                    cout << "¿En qué posición insertará el registro?" << '\n';
                    cin>> pos;
                    posicion = pos;
                }
            }else{
                cout << "Es su primer registro, entonces, se insertará por defecto en la posición cero (0)" << '\n';
            }
            cout << "Se insertaran los siguientes datos en la posición " << posicion <<": "<< '\n';
            cout << "Nombre: "<< nombre
                      << " Apellido: " << apellido
                      << " Edad: " << edad
                      <<" Género: "<< gender
                      <<" Salario: "<<salario<<'\n';

            lista->insert(new Employee(nombre,apellido,edad,genero,salario),posicion);
            cout << "¡Registro agregado con éxito!" << "\n\n" ;

        }
        if (opcion == 2 ) {
            if(lista->Size()==0){
                cout << "No hay registro(s) exitente(s) para eliminar." << '\n';
            }else{
                print(lista);
                int a_eliminar ;
                cout << "Eliga registro a eliminar: " << '\n';
                cin>> a_eliminar;

                cout << lista->remove(a_eliminar) << '\n';
                cout << "¡Registro eliminado con éxito!" << "\n\n" ;
            }
        }
        if (opcion == 3 ) {
            print(lista);
        }
        if (opcion == 4 ) {
            if(lista->Size()>0){
                cout << "El salario promedio es: " << SalarioPromedio(lista) << '\n';
            }else{
                cout << "No hay registros existentes para realizar esta operación." << '\n';
            }
        }
        if (opcion == 7 ) {
            Inflacion(lista);
        }
        if (opcion == 5 ) {
            mayorSalario(lista);
        }
        if (opcion == 6 ) {
            menorSalario(lista);
        }
    }
    lista->clear();
    cout <<  '\n' <<  '\n' << "Adiós :)"<< '\n' ;

    return 0;
}

void Inflacion(LinkedList* lista){
    int inf_ratio = 0;

    while(inf_ratio <=0){
        cout << "Ingrese el porcentaje de inflacion: (ingrese un entero mayor a cero (0) )" << '\n';
        cin >>inf_ratio;

        if (inf_ratio <=0) {
             cout << "Ingrese una cifra mayor a cero (0)." << '\n';
        }
    }
    double inflacion = double(inf_ratio)/100;
    if(lista->Size()>0){
        //Se hace el calculo respectivo en toda la lista.
        for (int i = 0; i < lista->Size(); i++) {
            dynamic_cast<Employee*>(lista->get(i))->setSalary(
                    (dynamic_cast<Employee*>(lista->get(i))->getSalary()*inflacion) +
                        (dynamic_cast<Employee*>(lista->get(i))->getSalary()));
        }
    }else{
         cout << "No hay registros existentes para realizar esta operación." << '\n';
    }
}

void mayorSalario(LinkedList* lista){
    //Condicion inicia para poder comenzar
    if(lista->Size() > 0 ){
        //Se crea un arreglo tipado de apuntador a Objeto.

        Object * array[lista->Size()];
        //Se llena el arreglo con los datos de nuestra lista.
        for (int i = 0; i < lista->Size(); i++) {
            cout << "holis" << '\n';
            array[i] = lista->get(i);
        }

        for (size_t i = 0; i < lista->Size(); i++) {
            cout << array[i]->toString() << '\n';
        }

        //Ciclo for anidado para ordenar los elementos segun su salario, en orden descendente
        for (int i = 0; i < lista->Size(); i++) {
            for (int j = 0; j < lista->Size()-1; j++) {
                if( dynamic_cast<Employee*>(array[j])->getSalary() < dynamic_cast<Employee*>(array[j+1])->getSalary()) {
      	             Object* temp = array[j];
      	             array[j] = array[j+1];
      	             array[j+1] = temp;
                   }
               }
           }


        if (lista->Size() > 2) {
            //instruccion: Se deben mostrar en los primeros 3 datos del arreglo.
            for (int i = 0; i < 3 ; i++) {
                cout << dynamic_cast<Employee*>(array[i])->toString() << '\n';
            }
            //En caso de que el tamaño de nuestro arreglo sea menor a 3,
            //se imprimen todos los datos existentes en la lista.
        }else if (lista->Size() < 3){
             cout << "Los salarios mas altos pertenecen a: " << '\n';

            for (int i = 0; i < lista->Size(); i++) {
                cout << dynamic_cast<Employee*>(array[i])->toString() << '\n';
            }
        }
        //se limpia el arreglo;
        for (int i = 0; i < lista->Size(); i++) {
             array[i] = NULL;
        }

      }
      else{
          cout << "La lista está vacia, intenta agregar algun empleado antes de ingresar aquí." << '\n';
      }
}

void menorSalario(LinkedList* lista){
    //Condicion inicia para poder comenzar
    if(lista->Size() > 0){
        //Se crea un arreglo tipado de apuntador a Objeto.

        Object* array[lista->Size()];

        //Se llena el arreglo con los datos de nuestra lista.
        for (int i = 0; i < lista->Size(); i++) {
            array[i] = lista->get(i);
        }

        for (size_t i = 0; i < lista->Size(); i++) {
            cout << array[i]->toString() << '\n';
        }


        //Ciclo for anidado para ordenar los elementos segun su salario, en orden ascendente
        for (int i = 0; i < lista->Size(); i++) {
            for (int j = 0; j < lista->Size()-1; j++) {
                if( dynamic_cast<Employee*>(array[j])->getSalary() > dynamic_cast<Employee*>(array[j+1])->getSalary()) {
                     Object* temp = array[j];
                     array[j] = array[j+1];
                     array[j+1] = temp;
                   }
               }
           }
           //instruccion: Se deben mostrar en los primeros 3 datos del arreglo.

        if (lista->Size() > 2) {
            for (int i = 0; i < 3 ; i++) {
                cout << dynamic_cast<Employee*>(array[i])->toString() << '\n';
            }
            //En caso de que el tamaño de nuestro arreglo sea menor a 3,
            //se imprimen todos los datos existentes en la lista.
        }else if (lista->Size() < 3){
             cout << "Los salarios mas bajos pertenecen a: " << '\n';
            for (int i = 0; i < lista->Size(); i++) {
                cout << dynamic_cast<Employee*>(array[i])->toString() << '\n';
            }
        }
        //se limpia el arreglo;
        for (int i = 0; i < lista->Size(); i++) {
             array[i] = NULL;
        }

      }
      else{
          cout << "La lista está vacia, intenta agregar algun empleado antes de ingresar aquí." << '\n';
      }
}

void print(LinkedList* lista){
    //Se imprimen los datos solo sí el tamaño de la lista es mayor a cero (0).
    if(lista->Size() > 0){
        for (int i = 0; i < lista->Size(); i++) {
            cout <<i<<".- "<< dynamic_cast<Employee*>(lista->get(i))->toString() << '\n';
        }
    }else{
        cout << "La lista está vacia, intenta agregar algun empleado antes de ingresar aquí." << '\n' <<  '\n';
    }
}

int menu(){
    cout << "   MENÚ " << '\n';
    cout << "1. Insertar"  << '\n';
    cout << "2. Eliminar"  << '\n';
    cout << "3. Listar" << '\n';
    cout << "4. Calcular Salario Promedio" << '\n';
    cout << "5. Ver Salario Máximo " << '\n';
    cout << "6. Ver Salario Mínimo " << '\n';
    cout << "7. Dar Incremento por Inflación" << '\n';

    cout << "-1. Salir " << '\n';
    cout <<"¿Qué hará?" << '\n';
    int opcion;
    cin >> opcion;
    return opcion;

}


double SalarioPromedio(LinkedList* lista){
    double acum = 0.0;
    //Ciclo for para sumar todos los salarios existentes en la lista enlazada
    for (int i = 0; i < lista->Size(); i++) {
        acum+= dynamic_cast<Employee*>(lista->get(i))->getSalary();
    }

    return (acum)/lista->Size();
}
