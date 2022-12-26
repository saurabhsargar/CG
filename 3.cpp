/*Write C++ program to draw the following pattern. Use DDA and Bresenham‘s Line
drawing algorithm*/

# include <iostream>
# include <graphics.h>
# include <math.h>
using namespace std;

void DDALine(int x1 , int y1 , int x2 , int y2 , int color);

int main ()
{
    int x1 , y1 , x2 , y2 , r , r1 , color ;
    int a1 , a2 , a3 , a4 , b1 , b2 , b3 , b4 ,  c1 , c2 , c3 , c4 ;
    int gd , gm=DETECT;  //Initialize the variables for the graphics driver and graphics mode
                         // gm is Graphics mode which is a computer display mode that generates image using pixels.
                         // DETECT is a macro defined in "graphics.h" header file
    initgraph(&gd , &gm , NULL);  //initgraph initializes the graphics system by loading a graphics driver from disk
    
    cleardevice(); //Clears device and set position to (0,0)

    cout << "Enter value for inner circle : " << endl;
    cin >> a1 >> a2 >> a3 >> a4; 
    DDALine(a1 , a2 , a3 , a4 , 4);  //x1,y1,x2,y2,Value of color

    cout << "Enter values for outer circle : " << endl;
    cin >> b1 >> b2 >> b3 >> b4;
    DDALine(b1 , b2 , b3 , b4 , 4);

    cout << "Enter the values for triangle : " << endl;
    cin >> c1 >> c2 >> c3 >> c4;
    DDALine(c1 , c2 , c3 , c4 , 4);

    r = 50/sqrt(3);  //To find radius of small circle
    x1 = (a1+b1+c1)/3;
    y1 = (a2+b2+c2)/3;
    circle (x1 , y1 , r);  //Draw small circle 

    r1 = 100/sqrt(3);  //To find radius of outer circle 
    circle (x1 , y1 , r1);  //Draw outer circle

    //delay(10000); //delay() function is used to hold the program for given milliseconds
    getch();
    return 0;
}

void DDALine(int x1 , int y1 , int x2 , int y2 , int color)
{
    float dX , dY , Steps;
    float xInc , yInc , i , x , y;

    dX = x2 - x1;
    dY = y2 - y1;

    if(abs(dX) > abs(dY))
    {
        Steps = abs(dX);
    }
    else
    {
        Steps = abs(dY);
    }

    xInc = dX/Steps;
    yInc = dY/Steps;

    x = x1;
    y = y1;

    for (i=1 ; i<=Steps ; i++)
    {
        putpixel(x , y , color);  //The header file graphics. h contains putpixel() function which plots a pixel at location (x, y)of specified color
        x = x+xInc;
        y = y+yInc;
    }
}