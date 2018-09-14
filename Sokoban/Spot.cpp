#include "Spot.h"



Spot::Spot()
{
  setRect(0, 0, UNIT, UNIT);
  QBrush brush_Spot(QImage(":/photos/Spot"));
  setBrush(brush_Spot);
}


Spot::~Spot()
{
}
