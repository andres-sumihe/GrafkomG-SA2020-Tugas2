## Author Information
* Name       : Andres Freixa Sumihe <Br />
* NIM (SID)  : 672018136

## Getting Started

This is simple Solar System Animation (2D)
in this solar system have some planets and Natural Satelits, they are :
* Sun
* Mercury
* Venus
* Earth
* Mars

Natural Satelites :
* Month 
* Phobos
* Deimos

the output is include the orbit lines and lines from planets to sun (also from natural satelites to their planets)

This project is only for fulfilling campus assignments (Project was writting in indonesian language (variabel name and many things))
Hope this project cant help other people

## Prerequisites
To run this project, you'll need
```
glut.h (x86)
```
if you use freeglut.h just uncomment code below on main.cpp
```c++
#include <iostream>
#include <GL/glut.h>
//#include <GL/freeglut.h>
```

## Algorithm
[n-Gon Algorithm](https://github.com/andres-sumihe/GrafkomG-SA2020-Tugas2/blob/master/n-Gon%20Algorithm.PNG)

this is the Math Algorthm for draw Circle that i use in this project code
you can find that code in function 
```c++

void planet(double r, double xx, double yy, int n,  bool orbit) {
    double count = (double)n;
    glBegin((orbit) ? GL_LINE_LOOP : GL_POLYGON );
    for (int i = 0; i < n; i++) {
        double x = r * cos(2 * M_PI * i / count);
        double y = r * sin(2 * M_PI * i / count);
        glVertex2d(xx+x, yy+y);
    }
    glEnd();
}
```
Hope You can understand what i write :D


## Contact
* [Instagram](https://Instagram.com/andres_sumihe)
* [Facebook](https://Facebook.com/andres.sumihe.1)
* [My Website](https://codemaster.my.id)
* [Whatsapp](https://https://api.whatsapp.com/send?phone=6285145814955)
