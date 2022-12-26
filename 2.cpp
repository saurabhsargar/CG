/*Write C++ program to implement Cohen Southerland line clipping algorithm*/

# include <iostream>
# include <graphics.h>
using namespace std;

static int LEFT=1 , RIGHT=2 , BOTTOM=4 , TOP=8 , xmin , ymin ,xmax , ymax; //Getcode fun to find out code of end points of line 
int getcode (int x , int y) //x,y coordinates of first endpoint of line
{
    int code = 0;
    //Perform Bitwise OR to get outcode
    if (y > ymax ) code |= TOP;
    if (y < ymin ) code |= BOTTOM;
    if (x < xmin ) code |= LEFT;
    if (x > xmax ) code |= RIGHT;
    return code;
}

int main()
{
    int gd = DETECT , gm;  //Initialize the variables for the graphics driver and graphics mode
                           //gm is Graphics mode which is a computer display mode that generates image using pixels
                           //DETECT is a macro defined in "graphics.h" header file
    cout << "Enter the window's minimum and maximum values : ";
    cin >>  xmin >> ymin >> xmin >> ymax;

    int x1 , y1 , x2 , y2;
    cout << "Enter the endpoints of the line : ";
    cin >> x1 >>  y1 >> x2 >> y2;

    initgraph (&gd , &gm , NULL); // initgraph initializes the graphics system by loading a graphics driver from disk

    rectangle (xmin , ymin , xmax , ymax); //Draw rectangular window

    setcolor (BLUE);
    line (x1 , y1 , x2 , y2);  //Draw line to be clipped

    int outcode1 = getcode (x1,y1) , outcode2 = getcode (x2,y2);
    int accept = 0;  //Decides if line is to be drawn
    while(1)
    {
        float m = (float) (y2-y1)/(x2-x1);
        //Both points inside.Accept line

        if(outcode1 == 0 && outcode2 == 0) //The logical AND operator (&&) returns true if both operands are true and returns false otherwise.
        {
            accept = 1;
            break;
        }
        else if((outcode1 & outcode2)!=0) //bitwise AND of both codes != 0.Line is outside. Reject line
        {
            break;
        }
        else
        {
            int x , y , temp;  //Decide if point1 is inside, if not, calculate intersection
            if(outcode1 == 0)
                temp = outcode2;
            else
                temp = outcode1; 

            //Line clips two edge
            if(temp & TOP)  //if bitwise of temp and top is true
            {
                x = x1+(ymax-y1)/m;  //using this formula perform intersection with top boundry
                y = ymax;
            }
            else if(temp & BOTTOM)  //Line clips bottom edge
            {
                x = x1+(ymin-y1)/m;
                y = ymin;
            }
            else if(temp & LEFT) //Line clips left edge
            {
                x = xmin;
                y = y1+m*(xmin-x1);
            }
            else if(temp & RIGHT)  //Line clips right edge
            {
                x = xmax;
                y = y1+m*(xmax-x1);
            }

            //Check which point we had selected earlier as temp, and replace its co-ordinates
            if(temp == outcode1)
            {
                x1 = x;
                y1 = y;
                outcode1 = getcode(x1 , y1);
            }
            else
            {
                x2 = x;
                y2 = y;
                outcode2 = getcode(x2 , y2);
            }
        }
    }

    cout << "After Clipping : ";
    if(accept)
        cleardevice();
        setcolor(GREEN);
        rectangle(xmin , ymin , xmax , ymax);
        setcolor(BLUE);
    line(x1 , y1 , x2 , y2);

    getch();
    closegraph();
    return 0;
}