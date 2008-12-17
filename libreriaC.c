/* EJEMPLO DE CÓMO SE HACEN LAS LIBRERÍAS EN C */

/* Also, you'll almost universally see the typedef as shown */
/* above for every struct in a C library. This is done so you can treat */
/* the struct as if it were a new type and define variables of that struct */
/* like this: */
/* CStash A, B, C; */



typedef struct CStashTag {
  int size;      // Size of each space
  int quantity; // Number of storage spaces
  int next;      // Next empty space
  // Dynamically allocated array of bytes:
  unsigned char* storage;
} CStash;

void initialize(CStash* s, int size);
void cleanup(CStash* s);
int add(CStash* s, const void* element);
void* fetch(CStash* s, int index);
int count(CStash* s);
void inflate(CStash* s, int increase);


int main(){
  CStash A, B, C;
}
