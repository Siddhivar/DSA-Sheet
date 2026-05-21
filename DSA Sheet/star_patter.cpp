#include <bits/stdc++.h>

using namespace std;

void SolidRectangle(int num)
{

    for (int i = 1; i <= num; i++)
    {

        for (int j = 1; j <= num; j++)
        {

            cout << "*" << " ";
        }

        cout << endl;
    }
}

void RightHandTriangle(int num)
{

    for (int i = 1; i <= num; i++)
    {

        for (int j = 1; j <= i; j++)
        {

            cout << "*" << " ";
        }

        cout << endl;
    }
}

void RightHandNumberedTriangle(int num)
{

    for (int i = 1; i <= num; i++)
    {

        for (int j = 1; j <= i; j++)
        {

            cout << j << " ";
        }

        cout << endl;
    }
}

void RightHandNumberedRepeatedTriangle(int num)
{

    for (int i = 1; i <= num; i++)
    {

        for (int j = 1; j <= i; j++)
        {

            cout << i << " ";
        }

        cout << endl;
    }
}

void RightHandTriangleUpsideDown(int num)
{

    for (int i = num; i >= 1; i--)
    {

        for (int j = 1; j <= i; j++)
        {

            cout << "*" << " ";
        }

        cout << endl;
    }
}

void RightHandNumberedTriangleUpsideDown(int num)
{

    for (int i = num; i >= 1; i--)
    {

        for (int j = 1; j <= i; j++)
        {

            cout << j << " ";
        }

        cout << endl;
    }
}

// void triangle(int num)
// {

//     for (int i =)
// }

int main()
{

    int num = 5;

    // SolidRectangle(num);

    // RightHandTriangle(num);

    // RightHandNumberedTriangle(num);

    // RightHandNumberedRepeatedTriangle(num);

    RightHandTriangleUpsideDown(num);

    RightHandNumberedTriangleUpsideDown(num);

    return 0;
}