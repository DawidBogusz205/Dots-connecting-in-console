#include <iostream>

using namespace std;

void BresenhamLine(char**,const int, const int, const int, const int);

int main()
{
    int rows = 25, cols = 30,  points;
    int A1=24,A2=0;
    int B1=24,B2=29;
    int a;

    cout<<"x1: ";
    cin>>A1;
    cout<<"y1: ";
    cin>>A2;
    cout<<"x2: ";
    cin>>B1;
    cout<<"y2: ";
    cin>>B2;
    cout<<endl;

    if(A1>B1) rows = A1+5;
    else rows = B1+5;

    if(A2>B2) cols = A2+5;
    else cols = B2+5;

    char **ary = new char *[rows];

    for(int i=0; i<rows; i++)
    {
        ary[i] = new char [cols];
    }

    for(int i=0; i<rows; i++)
    {
        for(int x=0; x<cols; x++)
        {
            ary[i][x] ='-';
        }
    }

    BresenhamLine(ary,A1,A2,B1,B2);

    //point A
    ary[A1][A2] = 'A';
    //point B
    ary[B1][B2] = 'B';

    for(int i=0;i<rows;i++)
    {
        if (i<10)cout<<i<<"  ";
        else cout<<i<<" ";

        for(int x=0;x<cols;x++)
        {
            cout<<ary[i][x]<<" ";
        }
        cout<<""<<endl;
    }

    system("pause");

    for(int i=0; i<cols; i++)
    {
        delete [] ary[i];
    }

    delete [] ary;
    return 0;
}

void BresenhamLine(char **ary, const int x1, const int y1, const int x2, const int y2)
{
    // zmienne pomocnicze
    int d, dx, dy, ai, bi, xi, yi;
    int x = x1, y = y1;
    // ustalenie kierunku rysowania
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
    // ustalenie kierunku rysowania
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
    // pierwszy piksel
    ary[x][y] = '+';
    // oś wiodąca OX
    if (dx > dy)
    {
        ai = (dy - dx) * 2;
        bi = dy * 2;
        d = bi - dx;
        // pętla po kolejnych x
        while (x != x2)
        {
            // test współczynnika
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
            ary[x][y] = '+';
        }
    }
    // oś wiodąca OY
    else
    {
        ai = ( dx - dy ) * 2;
        bi = dx * 2;
        d = bi - dy;
        // pętla po kolejnych y
        while (y != y2)
        {
            // test współczynnika
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
            ary[x][y] = '+';
        }
    }
}