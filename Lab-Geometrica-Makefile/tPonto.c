
#include "tPonto.h"

tPonto criaPonto(float x, float y)
{
  tPonto  t = {x,y};
  
  return t;
}



float distancia (tPonto p1, tPonto p2){
  return sqrt ((p2.x-p1.x)*(p2.x-p1.x) + (p2.y-p1.y)*(p2.y-p1.y));
  
}

void imprime (tPonto p){

	printf ("Coordenada x: %.2f, Coordenada y: %.2f \n", p.x, p.y);

}

