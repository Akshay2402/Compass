/* TILT COMPENSATION */

/* we need accXnorm, accYnorm and pitch of accelerometer
here we need to calculate the tilt compensation where even if the chip tilts inside the car
it will give approximately good results so we use accelerometer along with magnetometer(compass)

lets see how we calculate it and then find the direction*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI  3.14159;

int main()
{
  FILE *fx, *fy, * fz, *fmx, *fmy, *fmz;
  float x, y, z, mx, my, mz;
  float magXcomp, magYcomp;
  float accXnorm;
  float accYnorm;
  float pitch;
  int index = 1;
  char *dir;
  dir = malloc(sizeof(char)*15);
  int heading;

  /* READING FROM ACCELEROMETER X Y AND Z READINGS */
  fx = fopen("accX.txt", "r");
  if(fx == NULL){
    printf("ACCELEROMETER File X cannot be opened");
    exit(1);
  }

  fy = fopen("accY.txt", "r");
  if(fy == NULL){
    printf("ACCELEROMETER File Y cannot be opened");
    exit(2);
  }

  fz = fopen("accZ.txt", "r");
  if(fz == NULL){
    printf("ACCELEROMETER File Z cannot be opened");
    exit(3);
  }

  /*READING FROM MAGNETOMETER X, Y AND Z READINGS*/
  fmx = fopen("delcolx.txt","r");
  if(fmx == NULL){
    printf("Compass File X cannot be opened");
    exit(4);
  }

  fmy = fopen("delcoly.txt","r");
  if(fmy == NULL){
    printf("Compass File Y cannot be opened");
    exit(5);
  }

  fmz = fopen("delcolz.txt","r");
  if(fmz == NULL){
    printf("Compass File Z cannot be opened");
    exit(6);
  }


  /* calculating accXnorm, accYnorm and pitch and magx, magy and magz*/
  while(fscanf(fx,"%f",&x) != EOF && fscanf(fy,"%f",&y) != EOF && fscanf(fz,"%f",&z) != EOF
      && fscanf(fmx,"%f",&mx) != EOF && fscanf(fmy,"%f",&my) != EOF && fscanf(fmz,"%f",&my) != EOF){

    accXnorm = x/sqrt(x*x + y*y + z*z);
    accYnorm = y/sqrt(x*x + y*y + z*z);
    pitch = asin(accXnorm);

    magXcomp = mx*cos(asin(accXnorm)) + mz*sin(pitch);
    magYcomp = mx*sin(asin(accYnorm/cos(pitch)))*sin(asin(accXnorm))
          +my*cos(asin(accYnorm/cos(pitch)))- z*sin(asin(accYnorm/cos(pitch)))*cos(asin(accXnorm));

    /* calculating Heading using new x and y cordinates */

    heading = (atan2(magYcomp,magXcomp) * 180) / PI;

      if(heading < 0)
        heading += 360;

      if(heading > 68 && heading <113)  dir = "East";
      if(heading > 248 && heading <293) dir = "West";
      if(heading > 338 && heading <23) dir = "North";
      if(heading > 158 && heading <203) dir = "South";
      if(heading > 23 && heading < 68 ) dir = "North-East";
      if(heading > 112 && heading < 158 ) dir = "South-East";
      if(heading > 203 && heading < 248 ) dir = "South-West";
      if(heading > 293 && heading < 338 ) dir = "North-West";
    printf("%d\tx=%f\tY=%f\tangle=%d\tDir = %s\n",index++, magXcomp, magYcomp, heading,dir);
  }

  fclose(fx);
  fclose(fy);
  fclose(fz);
  fclose(fmx);
  fclose(fmy);
  fclose(fmz);

  return 0;
}
