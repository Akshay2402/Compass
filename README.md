The C program gives the direction from the raw data of IMU sensor.

Only x and y co-ordinates are used to calculate the angle. The z co-ordinate gives the tilt and tilt won't matter much while changing the angle and hence direction.

The jpg file contains the reference of the compass which I used to calculate angle from raw data.

The program gives current direction of the vehical and not the path followed.

The next version, the file DirectionWithTilt.c will give better results as it will give the tilt compensation, i.e. it will give better results even if there is a tilt in the device or IMU sensor.


To Compile:
===========
````
gcc -Wall  direction.c -lm -o direction
gcc -Wall  DirectionWithTilt.c -lm -o DirectionWithTilt
````
