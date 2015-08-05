//
//  main.c
//  prism.c
//
//  Created by Haaris Mirza on 1/22/15.
//  Copyright (c) 2015 Haaris Mirza. All rights reserved.
//

//
//  main.c
//  prism.c
//
//  Created by Haaris Mirza on 1/22/15.
//  Copyright (c) 2015 Haaris Mirza. All rights reserved.
//

//
// This progarm will find the Volume and Surface Area of a rectangular prism in 3-D space given the coordinates inputted by the user

#include <stdio.h>
#include <math.h>


double get_dist(double a, double b, double c, double a0, double b0, double c0) { //This function gets the distance between two coordinates that the user will enter
  double distance2points = 0.0;
  distance2points = sqrt(((a - a0)*(a - a0)) + ((b - b0)*(b - b0)) + ((c - c0)*(c - c0))); //Distance formula between points in a X Y Z coordinate plane
  
  return distance2points; //Return formula to use in get_rect_area function
}


double get_rect_area(double a, double b, double c, double a0, double b0, double c0, double dist, double dist2) { //This functions finds the area of each rectangle of the prism
  double area = 0;

  dist = get_dist(a, b, c, a0, b0 ,c0); //Call back get_dist function to use in later step to solve for area
  dist2 = get_dist(a, b, c, a0, b0, c0);
  area = dist * dist2; //Formula for function to solve for the rectangle's area. Use both dist and dist2 as distances to multiply with each other
  
  return area; //Return formula to use in main function
}

double get_surface_area(double length, double width, double height) { //This function will find the surface area of the prism. The function accepts 3 arguments, Length, Width, and Height
  double area1 = 0;
  
  area1 = (2 * (length * width)) + (2 * (length * height)) + (2 * (width * height)); //Formula for function to solve for the prism's surface area.
  
  return area1; //Return formula to use in main function
}

double get_volume(double length, double width, double height) { //This function will find the volume of the prism. The function accepts 3 arguments, Length, Width, and Height
  double volume = 0;
  
  volume = length * width * height; //Formula for function to solve for prism's volume
  
  return volume; //Return formula to use in main function
  
}

int main() {
  double a1 = 0; //Here each variable is initialized that is used throughout the function
  double a2 = 0;
  double a3 = 0;
  double b1 = 0; //b1 to b3 will be the coordinates of one point in the XYZ plane
  double b2 = 0;
  double b3 = 0;
  double c1 = 0; //c1 to c3 will be the coordinates of another point in the XYZ plane
  double c2 = 0;
  double c3 = 0;
  double d1 = 0; //d1 to d3 will be the coordinates of another point in the XYZ plane
  double d2 = 0;
  double d3 = 0;
  double e1 = 0; //e1 to e3 will be the coordinates of another point in the XYZ plane
  double e2 = 0;
  double e3 = 0;
  double f1 = 0; //f1 to f3 will be the coordinates of another point in the XYZ plane
  double f2 = 0;
  double f3 = 0;
  double g1 = 0; //g1 to g3 will be the coordinates of another point in the XYZ plane
  double g2 = 0;
  double g3 = 0;
  double h1 = 0; //h1 to h3 will be the coordinates of another point in the XYZ plane
  double h2 = 0;
  double h3 = 0;
  double dist1 = 0; //dist1 throught dist9 are used to find the distances between two points throughout the function
  double dist2 = 0;
  double dist3 = 0;
  double dist4 = 0;
  double dist5 = 0;
  double dist6 = 0;
  double dist7 = 0;
  double dist8 = 0;
  double dist9 = 0;

  double surfaceA = 0; //used to find surface area later in function
  double volume = 0; //used to find volume later in function
  
  printf("Enter the first coordinate in the form x y z: "); //These messages will appear when program is ran. Message will ask user to input coordinates to the rectangular prism
  scanf("%lf %lf %lf", &a1, &a2, &a3);                      //The inputted coordinates are read in and then assigned to their variables
  
  printf("Enter the second coordinate in the form x y z: ");
  scanf("%lf %lf %lf", &b1, &b2, &b3);
  
  printf("Enter the third coordinate in the form x y z: ");
  scanf("%lf %lf %lf", &c1, &c2, &c3);
  
  printf("Enter the fourth coordinate in the form x y z: ");
  scanf("%lf %lf %lf", &d1, &d2, &d3);
  
  printf("Enter the fifth coordinate in the form x y z: ");
  scanf("%lf %lf %lf", &e1, &e2, &e3);
  
  printf("Enter the sixth coordinate in the form x y z: ");
  scanf("%lf %lf %lf", &f1, &f2, &f3);
  
  printf("Enter the seventh coordinate in the form x y z: ");
  scanf("%lf %lf %lf", &g1, &g2, &g3);
  
  printf("Enter the eighth coordinate in the form x y z: ");
  scanf("%lf %lf %lf", &h1, &h2, &h3);
  
  dist1 = get_dist(a1, a2, a3, b1, b2 ,b3); //Gets the distance from vertices [a to b] [0 to 1]
  dist2 = get_dist(b1, b2, b3, c1, c2, c3); //Gets the distance from vertices [b to c] [1 to 2]
  dist3 = get_dist(c1, c2, c3, d1, d2, d3); //Gets the distance from vertices [c to d] [2 to 3]
  dist4 = get_dist(d1, d2, d3, e1, e2, e3); //Gets the distance from vertices [d to e] [3 to 4]
  dist5 = get_dist(e1, e2, e3, f1, f2, f3); //Gets the distance from vertices [e to f] [4 to 5]
  dist6 = get_dist(f1, f2, f3, g1, g2, g3); //Gets the distance from vertices [f to g] [5 to 6]
  dist7 = get_dist(g1, g2, g3, b1, b2, b3); //Gets the distance from vertices [g to b] [6 to 2]
  dist8 = get_dist(h1, h2, h3, a1, a2, a3); //Gets the distance from vertices [h to a] [7 to 0]
  dist9 = get_dist(b1, b2, b3, g1, g2, g3); //Gets the distance from vertices [b to g] [1 to 6]
  
  
  
  surfaceA = get_surface_area(dist1, dist2, dist9); //Call back get_surface_area function and use dist1(Length), dist2(Width), and dist9(Height) to calculate surface area
  printf("The surface area of the prism is %.2lf\n", surfaceA); //Prints calculated surface area in function
  
  volume = get_volume(dist1, dist2, dist4); //Call back get_volume function and use dist1(Length), dist2(Width), and dist9(Height) to calculate volume
  printf("The volume of the prism is %.2lf\n", volume); //Prints calculated volume in program
  
  //67.71 68.77 22.89
  //64.28 59.84 25.81
  //51.38 69.66 40.69
  //54.81 78.59 37.77
  //35.72 80.16 20.19
  //48.62 70.34 5.31
  //45.19 61.41 8.23
  //32.29 71.23 23.11
  
  
  
  
  return 0;
}
