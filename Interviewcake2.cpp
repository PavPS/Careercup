/*
A crack team of love scientists from OkEros (a hot new dating site) have devised a way to 
represent dating profiles as rectangles on a two-dimensional plane.
They need help writing an algorithm to find the intersection of two users' love rectangles. 
They suspect finding that intersection is the key to a matching algorithm so powerful it 
will cause an immediate acquisition by Google or Facebook or Obama or something.

Write a function to find the rectangular intersection of two given love rectangles.
Love rectangles are defined as hash maps like this:

  my_rectangle = {

    # coordinates of bottom-left corner:
    'x': 1, 
    'y': 5, 

    # width and height
    'width': 10,
    'height': 4,

    }

Your output rectangle should use this format as well.

Gotchas
What if there is no intersection? Does your function do something reasonable in that case?

What if one rectangle is entirely contained in the other? Does your function do something reasonable in that case?

What if the rectangles don't really intersect but share an edge? Does your function do something reasonable in that case?

Do some parts of your function seem very similar? Can they be refactored so you repeat yourself less?
*/

#include "stdafx.h"

#include <string>
#include <vector>
#include <iostream>
#include <assert.h>
#include <iomanip>

using namespace std;

typedef struct TRectangle
{
    int x, y, width, height;
}Rectangle;

void rect_cross(const Rectangle& r1, const Rectangle& r2, Rectangle& cross)
{

}

void testAngleCross()
{
    Rectangle r1;
    r1.x = 10;
    r1.y = 10;
    r1.width = 20;
    r1.height = 20;

    Rectangle r2;
    r2.x = 5;
    r2.y = 5;
    r2.width = 10;
    r2.height = 10;

    Rectangle cross;
    rect_cross(r1, r2, cross);

    assert(cross.width == 5);
    assert(cross.height == 5);
    assert(cross.x == 10);
    assert(cross.y == 10);
}

void testBulletCross()
{
    Rectangle r1;
    r1.x = 10;
    r1.y = 10;
    r1.width = 20;
    r1.height = 20;

    Rectangle r2;
    r2.x = 5;
    r2.y = 15;
    r2.width = 100;
    r2.height = 10;

    Rectangle cross;
    rect_cross(r1, r2, cross);

    assert(cross.width == 20);
    assert(cross.height == 10);
    assert(cross.x == 10);
    assert(cross.y == 15);
}

void testSideCross()
{
    Rectangle r1;
    r1.x = 10;
    r1.y = 10;
    r1.width = 20;
    r1.height = 20;

    Rectangle r2;
    r2.x = 5;
    r2.y = 15;
    r2.width = 10;
    r2.height = 10;

    Rectangle cross;
    rect_cross(r1, r2, cross);

    assert(cross.width == 5);
    assert(cross.height == 10);
    assert(cross.x == 10);
    assert(cross.y == 15);
}

void testInside()
{
    Rectangle r1;
    r1.x = 10;
    r1.y = 10;
    r1.width = 20;
    r1.height = 20;

    Rectangle r2;
    r2.x = 15;
    r2.y = 15;
    r2.width = 5;
    r2.height = 5;

    Rectangle cross;
    rect_cross(r1, r2, cross);

    assert(cross.width == r2.width);
    assert(cross.height == r2.height);
    assert(cross.x == r2.x);
    assert(cross.y == r2.y);
}

void testOnEdge()
{
    Rectangle r1;
    r1.x = 10;
    r1.y = 10;
    r1.width = 20;
    r1.height = 20;

    Rectangle r2;
    r2.x = 10;
    r2.y = 30;
    r2.width = 20;
    r2.height = 20;

    Rectangle cross;
    rect_cross(r1, r2, cross);

    assert(cross.width == 0);
    assert(cross.height == 0);

    r2.x = 30;
    r2.y = 10;
    r2.width = 20;
    r2.height = 20;

    rect_cross(r1, r2, cross);

    assert(cross.width == 0);
    assert(cross.height == 0);
}

void testEqual()
{
    Rectangle r1;
    r1.x = 10;
    r1.y = 10;
    r1.width = 20;
    r1.height = 20;

    Rectangle cross;
    rect_cross(r1, r1, cross);

    assert(cross.width == r1.width);
    assert(cross.height == r1.height);
}

void testNoCross()
{
    Rectangle r1;
    r1.x = 10;
    r1.y = 10;
    r1.width = 20;
    r1.height = 20;

    Rectangle r2;
    r2.x = 100;
    r2.y = 100;
    r2.width = 200;
    r2.height = 200;

    Rectangle cross;
    rect_cross(r1, r2, cross);

    assert(cross.width == 0);
    assert(cross.height == 0);
}

void Interviewcake2()
{
    testEqual();
    testNoCross();
    testOnEdge();
    testInside();
    testSideCross();
    testBulletCross();
    testAngleCross();
}

#if !defined(_MSC_VER)
int main()
{
	Interviewcake2();
	return 0;
}
#endif
