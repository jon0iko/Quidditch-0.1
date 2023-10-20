#pragma once

#include "./globals.h"
#include <math.h>

double sinD(int degree){
    double ret,val;
    val = PI / 180;
    ret = sin(degree*val);
    return ret;
}

double cosD(int degree){
    double ret,val;
    val = PI / 180;
    ret = cos(degree*val);
    return ret;
}

void movePlayerUD(int speed){
   
   harry.DX = harry.DX + (speed*sinD(harry.Angle))*-1; 
   harry.DY = harry.DY + (speed*cosD(harry.Angle)); 
   harry.X = round(harry.DX);
   harry.Y = round(harry.DY);
}

void movePlayerLR(int speed){
   
   harry.DX = harry.DX + (speed*sinD(harry.Angle+90))*-1; 
   harry.DY = harry.DY + (speed*cosD(harry.Angle+90)); 
   harry.X = round(harry.DX);
   harry.Y = round(harry.DY);
}

void rotateBy(OBJECT *Object, float D){
   float temp;
   
   if(fabs(Object->Angle + D) < 181) {
     temp = Object->Angle + D;
     Object->Angle = round(temp);
   } else{
      Object->Angle = Object->Angle * -1;  
    }
}