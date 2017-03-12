#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159;

int main(){
  FILE *fx, *fy;

  float x;
  float y;
  float heading;

  char *dir;

  int index = 1;
  
  fx = fopen("delcolx.txt","r");
  if(fx == NULL){
    printf("File X cannot be opened");
    exit(1);
  }
  
  fy = fopen("delcoly.txt","r");
  if(fy == NULL){
    printf("File Y cannot be opened");
    exit(2);
  }  

  printf("id\t\tx\t\ty\t  Heading\t\tDirection\n\n");
  while(fscanf(fx,"%f",&x) != EOF && fscanf(fy,"%f",&y) != EOF ){
        
    heading = (atan2(y,x) * 180) / PI;
      
    if(heading < 0) 
      heading += 360;
      
    if(heading > 68 && heading >113)  dir = "East";
    if(heading > 248 && heading <293) dir = "West";
    if(heading > 338 || heading <23) dir = "North";
    if(heading > 158 && heading <203) dir = "South";
    if(heading > 23 && heading < 68 ) dir = "North-East";
    if(heading > 112 && heading < 158 ) dir = "South-East";
    if(heading > 203 && heading < 248 ) dir = "South-West";
    if(heading > 293 && heading < 338 ) dir = "North-West";      
      
    printf("%d\tx = %f\ty =%f\tHeading = %f\tDirection = %s\n",index++, x, y,heading,dir);

  }  
  
  fclose(fx);
  fclose(fy);

  return 0;
}
