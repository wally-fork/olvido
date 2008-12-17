#include <iostream>
using namespace std;

// al hacer DEBUG se pueden definir macros para imprimir rápido
#define P(x) cout << "Esto es " << #x << "  : "<< x << "\n";

int main(int argc, char *argv[])
{
  int a = 1;
  int b = 1;
  int c = 1;
  P(a + b + c );
  return 0;
}

