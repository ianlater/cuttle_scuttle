#include "thing.h"

/** default constructor for thing out of 
  *@param p = pixmap of Thing
  *@param nx =x loc
  *@param ny =y loc
  */
Thing::Thing(QPixmap* p,int nx,int ny) {
pixMap= p; //Handy to store separate to get image width/height, etc.
setPixmap( *p ); 
x_ = nx;
y_ =ny;
setPos( x_, y_ );
death=0;
}


