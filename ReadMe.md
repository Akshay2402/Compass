The C program gives the direction from the raw data of IMU sensor.

Only x and y co-ordinates are used to calculate the angle. The z co-ordinate gives the tilt and tilt won't matter much while changing the angle and hence direction.

The jpg file contains the reference of the compass which I used to calculate angle from raw data.

The program gives current direction of the vehical and not the path followed.


To Compile:
===========
````
gcc -Wall  direction.c -lm -o direction
````
