/**
 * @file main.cpp
 * @author BugiBugi205
 * @date 2022-04-12
 * 
 * @copyright Copyright (c) 2022
 */

#include <iostream>

using namespace std;

void BresenhamLine(char**,const int, const int, const int, const int);

int main()
{
    uint16_t rows = 25, cols = 30, points;
    uint16_t A1=24,A2=0;
    uint16_t B1=24,B2=29;
    char **arr;
    int **points_arr;

    cout<<"How many points: ";
    cin>>points;

    points_arr = new int *[2];
    points_arr[1] = new int [points];   //x
    points_arr[0] = new int [points];   //y
    
    for(int i = 0; i < points; i++)
    {
        cout<<"x"<<i+1<<": ";
        cin>>points_arr[1][i];

        if(points_arr[1][i]>cols) cols = points_arr[1][i];

        cout<<"y"<<i+1<<": ";
        cin>>points_arr[0][i];

        if(points_arr[0][i]>rows) rows = points_arr[0][i];
        
        //arr[points_arr[0][i]][points_arr[1][i]] =(char) 65+i;
    }
    cout<<endl;

    rows+=5;
    cols+=5;

    arr = new char *[rows];
    for(int i=0; i<rows; i++)
    {
        arr[i] = new char [cols];
    }

    //fills background array with '-'
    for(int i=0; i<rows; i++)
    {
        for(int x=0; x<cols; x++)
        {
            arr[i][x] ='-';
        }
    }

    //draws lines between points
    for(int i = 0; i < points; i++)
    {
        if(i+1>=points)
        {
            BresenhamLine(arr,points_arr[0][i],points_arr[1][i],points_arr[0][0],points_arr[1][0]);
            break;
        }
        
        BresenhamLine(arr,points_arr[0][i],points_arr[1][i],points_arr[0][i+1],points_arr[1][i+1]);
    }

    //line of x
    cout<<"  ";
    for (int i = 0; i < 10; i++)
    {
        cout<<" "<<i;
    }
    cout<<endl;

    //draws background array with already connected points
    for(int i=0;i<rows;i++)
    {
        //line of y
        if (i<10)cout<<i<<"  ";
        else cout<<i<<" ";

        for(int x=0;x<cols;x++)
        {
            cout<<arr[i][x]<<" ";
        }
        cout<<""<<endl;
    }

    system("pause");

    //cleans memory from dynamic elements
    for(int i=0; i<cols; i++)
    {
        delete [] arr[i];
    }

    delete [] points_arr;
    delete [] points_arr[0];
    delete [] points_arr[1];

    delete [] arr;
    return 0;
}

//algorithm source https://pl.wikipedia.org/wiki/Algorytm_Bresenhama#Implementacja
void BresenhamLine(char **arr, const int x1, const int y1, const int x2, const int y2)
{
    // auxiliary variables
    int d, dx, dy, ai, bi, xi, yi;
    int x = x1, y = y1;
    // determining the direction of drawing
    if (x1 < x2)
    {
        xi = 1;
        dx = x2 - x1;
    }
    else
    {
        xi = -1;
        dx = x1 - x2;
    }
    // determining the direction of drawing
    if (y1 < y2)
    {
        yi = 1;
        dy = y2 - y1;
    }
    else
    {
        yi = -1;
        dy = y1 - y2;
    }
    // first pixel
    arr[x][y] = '+';
    // leading axis OX
    if (dx > dy)
    {
        ai = (dy - dx) * 2;
        bi = dy * 2;
        d = bi - dx;
        // loop after consecutive x
        while (x != x2)
        {
            // ratio testtest współczynnika
            if (d >= 0)
            {
                x += xi;
                y += yi;
                d += ai;
            }
            else
            {
                d += bi;
                x += xi;
            }
            arr[x][y] = '+';
        }
    }
    // leading axis OY
    else
    {
        ai = ( dx - dy ) * 2;
        bi = dx * 2;
        d = bi - dy;
        // loop after consecutive y
        while (y != y2)
        {
            // ratio test
            if (d >= 0)
            {
                x += xi;
                y += yi;
                d += ai;
            }
            else
            {
                d += bi;
                y += yi;
            }
            arr[x][y] = '+';
        }
    }
}