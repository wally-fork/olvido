#include <cstdlib> 		
#include <cstring>
// de esta forma se pueden cargar las librerias de C
// de hacerlo de otra forma podrían haber errores, como los vimos en el projekt
#include <iostream>
using namespace std;
// se supone que es para poder usar el namespace que se trae iostream. Es sólo 
// para que que las cosas salgan rápido no se debe de usar mucho.

// este es el header donde se DECLARAN las funciones que se usan
struct Y;
struct X;

struct Y{
  void f(X*);	
  // es la declaracion de una funcion que recibe una struct X
  // como la struct X dice que es un su miembro es un friend de la struct X,
  // se debe e declarar antes
};

// no se pueden usar structs adentro de las class

// class Obj{
struct X{			
private: 
  int x;
public:
  void contar(int);
  void sayHello();		// decir Hola
  void inicializar();	//  inicializar la private x que HAY EN OTRO NAMESPACE
  friend void Y::f(X*);
  int w;
};

// una vez que se DECLARAN DENTRO DEL STRUCT, se DEFINEN.

void X::inicializar(){
  x = 9;
  w = x;
}
void X::contar(int w){
  w++;
}
void X::sayHello(){
  cout << "Salut!!!" << endl;
}

// tiene que ser declarado después de la struct X

// toma la direccion de un objeto de tipo X
void Y::f(X* a){
  // estas tres lineas no van a funcionar porque se hizo de esta forma X* a
  // a.inicializar();
  // cout << a.w << endl;
  // a.sayHello();
  // HACER QUE UN MIEMBRO PRIVADO DE A CAMBIE DE VALOR con friend.!!!
  a->x = 100;
  a->sayHello();
  cout << "lo que haga yo acá también se vale " <<endl;
}
// }; no se porque no funciona de esta forma con una class y structs

/////////////////////////////////////////////////////////////
// Entonces el programa quedó de esta forma: 		   //
// struct Y tiene un miembro f que es friend de struct X,  //
// por lo que se DECLARA primero struct Y.		   //
// 							   //
// Después se declara struct X, e indica que 		   //
// friend void Y::f(X*); al declararla en su PUBLIC	   //
// 							   //
// Después se todo, se define X::______() y Y::(X* a)	   //
/////////////////////////////////////////////////////////////
	  
int main(){
  X Objeto1;
  cout << "inicializando" << endl;
  Objeto1.inicializar();	
  cout << Objeto1.w << endl;
  Objeto1.sayHello();
  Y ObjetoFriend;

  // el objeto friend recibe un objeto X
  // al pasarle este objeto a una funcionfriend del objeto Y (friend)
  // se va a ejecutar el código de se definió en el namespace de Y
  ObjetoFriend.f(&Objeto1);	

  // Obj* obj = (Obj*)malloc(sizeof(Obj));
  // obj->inicializar();
  // cout << "inicializandooooooooo" << endl;
  // cout << obj->w << endl;
}
// estoy leyendo la 303
// voy por la 601
