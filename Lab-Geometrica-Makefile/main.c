/**#include "tPonto.h"
#include "tCirculo.h"
#include "tTriangulo.h"
#include "tRetangulo.h"
*/

#include "tGeometrica.h"
int main()
{ 
   tPonto centro = criaPonto(10.0, 20.5);
   tCirculo c = criaCirculo(centro, 5.0);
   

 imprimeCirculo(c);

  printf("Area: %.2f\n", calcularArea(c));

  tPonto p1 = criaPonto(5.0, 6.7);

  tPonto p2 = criaPonto(15.0, 16.7);
  
  tPonto p3 = criaPonto(51.0, 61.7);

   tTriangulo tri = criaTri(p1, p2, p3);

   tRetangulo ret = criaRetangulo(p1,p2);
  
   return 0;
}
