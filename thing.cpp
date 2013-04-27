#include "thing.h"

Thing::Thing(QPixmap* p,int nx,int ny) {
pixMap= p; //Handy to store separate to get image width/height, etc.
setPixmap( *p ); 
x = nx;
y =ny;
setPos( x, y ); 
}

