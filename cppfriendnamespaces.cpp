#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

// este es el header donde se declaran las funciones que se usan
struct Y;
struct DINNER;

struct Y{
  void f(DINNER*);		// que hace esto??? 
  // es la declaracion de una funcion que recibe una struct DINNER
};

// class Obj{
struct DINNER{			// definir a el struct
private: 
  int x;
public:
  void contar(int);
  void sayHello();		// decir Hola
  void inicializar();	//  inicializar la private x 
  friend void Y::f(DINNER*);
  int w;
};



void DINNER::inicializar(){
  x = 9;
  w = x;
}
void DINNER::contar(int w){
  w++;
}
void DINNER::sayHello(){
  cout << "Salut!!!" << endl;
}

void Y::f(DINNER* a){
  // a.inicializar();
  // cout << a.w << endl;
  // a.sayHello();
  // HACER QUE UN MIEMBRO PRIVADO DE A CAMBIE DE VALOR con friend.!!!
  a->x = 100;
  
}
// }; no se porque no funciona de esta forma
  
int main(){
  DINNER probando;
  cout << "inicializando" << endl;
  probando.inicializar();
  cout << probando.w << endl;
  probando.sayHello();
  // Obj* obj = (Obj*)malloc(sizeof(Obj));
  // obj->inicializar();
  // cout << "inicializandooooooooo" << endl;
  // cout << obj->w << endl;

}
// estoy leyendo la 303
// voy por la 601
