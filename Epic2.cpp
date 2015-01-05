#include "stdafx.h"

/*
Edge Detection:
Two-dimensional array representation of an image can also be represented by a one-dimensional 
array of W*H size, where W represent row and H represent column size and each cell represent 
pixel value of that image. you are also given a threshold X. 
For edge detection, you have to compute difference of a pixel value with each of it's 
adjacent pixel and find maximum of all differences. And finally compare if that maximum 
difference is greater than threshold X. if so, then that pixel is a edge pixel and have to display it.
*/

#include <iostream>
#include <algorithm>
#include <assert.h>

using namespace std;

typedef struct {
	unsigned char r, g, b, a;
}ARGB;

typedef union {
	ARGB color;
	unsigned raw;
}PixelType;

static_assert( sizeof(unsigned) == 4 * sizeof(unsigned char), "type size is wrong" );

static const PixelType PixelWhite { {0xFF, 0xFF, 0xFF, 0xFF} };

const unsigned img_rgba_width = 16;
const unsigned img_rgba_height = 16;
const unsigned char img_rgba[] = {
  0xcc, 0x1f, 0x36, 0xff, 0xcc, 0x1f, 0x36, 0xff, 0xcc, 0x1f, 0x36, 0xff,
  0xcc, 0x1f, 0x36, 0xff, 0xcc, 0x1f, 0x36, 0xff, 0xcc, 0x1f, 0x36, 0xff,
  0xcc, 0x1f, 0x36, 0xff, 0xcc, 0x1f, 0x36, 0xff, 0xcc, 0x1f, 0x36, 0xff,
  0xcc, 0x1f, 0x36, 0xff, 0xcc, 0x1f, 0x36, 0xff, 0xcc, 0x1f, 0x36, 0xff,
  0xcc, 0x1f, 0x36, 0xff, 0xcc, 0x1f, 0x36, 0xff, 0xcc, 0x1f, 0x36, 0xff,
  0xcc, 0xcc, 0xcc, 0xff, 0xcc, 0x1f, 0x36, 0xff, 0xfd, 0x5c, 0x5c, 0xff,
  0xfd, 0x5c, 0x5c, 0xff, 0xfd, 0x5c, 0x5c, 0xff, 0xfd, 0x5c, 0x5c, 0xff,
  0xfd, 0x5c, 0x5c, 0xff, 0xfd, 0x5c, 0x5c, 0xff, 0xfd, 0x5c, 0x5c, 0xff,
  0xfd, 0x5c, 0x5c, 0xff, 0xfd, 0x5c, 0x5c, 0xff, 0xfd, 0x5c, 0x5c, 0xff,
  0xfd, 0x5c, 0x5c, 0xff, 0xfd, 0x5c, 0x5c, 0xff, 0xfd, 0x5c, 0x5c, 0xff,
  0xcc, 0x1f, 0x36, 0xff, 0x72, 0x72, 0x72, 0xff, 0xcc, 0x1f, 0x36, 0xff,
  0xfe, 0x43, 0x43, 0xff, 0xfe, 0x43, 0x43, 0xff, 0xfe, 0x43, 0x43, 0xff,
  0xfe, 0x43, 0x43, 0xff, 0xfe, 0x43, 0x43, 0xff, 0xfe, 0x43, 0x43, 0xff,
  0xfe, 0x43, 0x43, 0xff, 0xfe, 0x43, 0x43, 0xff, 0xfe, 0x43, 0x43, 0xff,
  0xfe, 0x43, 0x43, 0xff, 0xfe, 0x43, 0x43, 0xff, 0xfe, 0x43, 0x43, 0xff,
  0xfe, 0x43, 0x43, 0xff, 0xcc, 0x1f, 0x36, 0xff, 0x75, 0x75, 0x75, 0xff,
  0xcc, 0x1f, 0x36, 0xff, 0xf6, 0x40, 0x40, 0xff, 0xf6, 0x40, 0x40, 0xff,
  0xf6, 0x40, 0x40, 0xff, 0xf6, 0x40, 0x40, 0xff, 0xf6, 0x40, 0x40, 0xff,
  0xf6, 0x40, 0x40, 0xff, 0xf6, 0x40, 0x40, 0xff, 0xf6, 0x40, 0x40, 0xff,
  0xf6, 0x40, 0x40, 0xff, 0xf6, 0x40, 0x40, 0xff, 0xf6, 0x40, 0x40, 0xff,
  0xf6, 0x40, 0x40, 0xff, 0xf6, 0x40, 0x40, 0xff, 0xcc, 0x1f, 0x36, 0xff,
  0x75, 0x75, 0x75, 0xff, 0xcc, 0x1f, 0x36, 0xff, 0xf1, 0x3e, 0x3e, 0xff,
  0xf1, 0x3e, 0x3e, 0xff, 0xf1, 0x3e, 0x3e, 0xff, 0xf1, 0x3e, 0x3e, 0xff,
  0xf1, 0x3e, 0x3e, 0xff, 0xf1, 0x3e, 0x3e, 0xff, 0xf1, 0x3e, 0x3e, 0xff,
  0xf1, 0x3e, 0x3e, 0xff, 0xf1, 0x3e, 0x3e, 0xff, 0xf1, 0x3e, 0x3e, 0xff,
  0xf1, 0x3e, 0x3e, 0xff, 0xf1, 0x3e, 0x3e, 0xff, 0xf1, 0x3e, 0x3e, 0xff,
  0xcc, 0x1f, 0x36, 0xff, 0x75, 0x75, 0x75, 0xff, 0xcc, 0x1f, 0x36, 0xff,
  0xea, 0x3c, 0x3c, 0xff, 0xea, 0x3c, 0x3c, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xea, 0x3c, 0x3c, 0xff,
  0xf9, 0x67, 0x67, 0xff, 0xea, 0x3c, 0x3c, 0xff, 0xea, 0x3c, 0x3c, 0xff,
  0xea, 0x3c, 0x3c, 0xff, 0xf9, 0x67, 0x67, 0xff, 0xea, 0x3c, 0x3c, 0xff,
  0xea, 0x3c, 0x3c, 0xff, 0xcc, 0x1f, 0x36, 0xff, 0x75, 0x75, 0x75, 0xff,
  0xcc, 0x1f, 0x36, 0xff, 0xe3, 0x39, 0x39, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xe3, 0x39, 0x39, 0xff, 0xe3, 0x39, 0x39, 0xff, 0xe3, 0x39, 0x39, 0xff,
  0xe3, 0x39, 0x39, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe3, 0x39, 0x39, 0xff,
  0xe3, 0x39, 0x39, 0xff, 0xe3, 0x39, 0x39, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xe3, 0x39, 0x39, 0xff, 0xe3, 0x39, 0x39, 0xff, 0xcc, 0x1f, 0x36, 0xff,
  0x75, 0x75, 0x75, 0xff, 0xcc, 0x1f, 0x36, 0xff, 0xdb, 0x37, 0x37, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xdb, 0x37, 0x37, 0xff, 0xdb, 0x37, 0x37, 0xff,
  0xf9, 0x67, 0x67, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xf9, 0x67, 0x67, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf9, 0x67, 0x67, 0xff,
  0xcc, 0x1f, 0x36, 0xff, 0x75, 0x75, 0x75, 0xff, 0xcc, 0x1f, 0x36, 0xff,
  0xd2, 0x35, 0x35, 0xff, 0xff, 0xff, 0xff, 0xff, 0xd2, 0x35, 0x35, 0xff,
  0xd2, 0x35, 0x35, 0xff, 0xd2, 0x35, 0x35, 0xff, 0xd2, 0x35, 0x35, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xd2, 0x35, 0x35, 0xff, 0xd2, 0x35, 0x35, 0xff,
  0xd2, 0x35, 0x35, 0xff, 0xff, 0xff, 0xff, 0xff, 0xd2, 0x35, 0x35, 0xff,
  0xd2, 0x35, 0x35, 0xff, 0xcc, 0x1f, 0x36, 0xff, 0x75, 0x75, 0x75, 0xff,
  0xcc, 0x1f, 0x36, 0xff, 0xcc, 0x1f, 0x36, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xcc, 0x1f, 0x36, 0xff, 0xcc, 0x1f, 0x36, 0xff, 0xcc, 0x1f, 0x36, 0xff,
  0xcc, 0x1f, 0x36, 0xff, 0xf9, 0x67, 0x67, 0xff, 0xcc, 0x1f, 0x36, 0xff,
  0xcc, 0x1f, 0x36, 0xff, 0xcc, 0x1f, 0x36, 0xff, 0xf9, 0x67, 0x67, 0xff,
  0xcc, 0x1f, 0x36, 0xff, 0xcc, 0x1f, 0x36, 0xff, 0xcc, 0x1f, 0x36, 0xff,
  0x75, 0x75, 0x75, 0xff, 0xcc, 0x1f, 0x36, 0xff, 0xcc, 0x1f, 0x36, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xcc, 0x1f, 0x36, 0xff, 0xcc, 0x1f, 0x36, 0xff,
  0xcc, 0x1f, 0x36, 0xff, 0xcc, 0x1f, 0x36, 0xff, 0xcc, 0x1f, 0x36, 0xff,
  0xcc, 0x1f, 0x36, 0xff, 0xcc, 0x1f, 0x36, 0xff, 0xcc, 0x1f, 0x36, 0xff,
  0xcc, 0x1f, 0x36, 0xff, 0xcc, 0x1f, 0x36, 0xff, 0xcc, 0x1f, 0x36, 0xff,
  0xcc, 0x1f, 0x36, 0xff, 0x75, 0x75, 0x75, 0xff, 0xcc, 0x1f, 0x36, 0xff,
  0xcc, 0x1f, 0x36, 0xff, 0xcc, 0x1f, 0x36, 0xff, 0xff, 0xff, 0xff, 0xff,
  0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xcc, 0x1f, 0x36, 0xff,
  0xcc, 0x1f, 0x36, 0xff, 0xcc, 0x1f, 0x36, 0xff, 0xcc, 0x1f, 0x36, 0xff,
  0xcc, 0x1f, 0x36, 0xff, 0xcc, 0x1f, 0x36, 0xff, 0xcc, 0x1f, 0x36, 0xff,
  0xcc, 0x1f, 0x36, 0xff, 0xcc, 0x1f, 0x36, 0xff, 0x75, 0x75, 0x75, 0xff,
  0xcc, 0x1f, 0x36, 0xff, 0xcc, 0x1f, 0x36, 0xff, 0xcc, 0x1f, 0x36, 0xff,
  0xcc, 0x1f, 0x36, 0xff, 0xcc, 0x1f, 0x36, 0xff, 0xcc, 0x1f, 0x36, 0xff,
  0xcc, 0x1f, 0x36, 0xff, 0xcc, 0x1f, 0x36, 0xff, 0xcc, 0x1f, 0x36, 0xff,
  0xcc, 0x1f, 0x36, 0xff, 0xcc, 0x1f, 0x36, 0xff, 0xcc, 0x1f, 0x36, 0xff,
  0xcc, 0x1f, 0x36, 0xff, 0xcc, 0x1f, 0x36, 0xff, 0xcc, 0x1f, 0x36, 0xff,
  0x75, 0x75, 0x75, 0xff, 0xcc, 0x1f, 0x36, 0xff, 0xcc, 0x1f, 0x36, 0xff,
  0xcc, 0x1f, 0x36, 0xff, 0xcc, 0x1f, 0x36, 0xff, 0xcc, 0x1f, 0x36, 0xff,
  0xcc, 0x1f, 0x36, 0xff, 0xcc, 0x1f, 0x36, 0xff, 0xcc, 0x1f, 0x36, 0xff,
  0xcc, 0x1f, 0x36, 0xff, 0xcc, 0x1f, 0x36, 0xff, 0xcc, 0x1f, 0x36, 0xff,
  0xcc, 0x1f, 0x36, 0xff, 0xcc, 0x1f, 0x36, 0xff, 0xcc, 0x1f, 0x36, 0xff,
  0xcc, 0x1f, 0x36, 0xff, 0x75, 0x75, 0x75, 0xff, 0xcc, 0x1f, 0x36, 0xff,
  0xcc, 0x1f, 0x36, 0xff, 0xcc, 0x1f, 0x36, 0xff, 0xcc, 0x1f, 0x36, 0xff,
  0xcc, 0x1f, 0x36, 0xff, 0xcc, 0x1f, 0x36, 0xff, 0xcc, 0x1f, 0x36, 0xff,
  0xcc, 0x1f, 0x36, 0xff, 0xcc, 0x1f, 0x36, 0xff, 0xcc, 0x1f, 0x36, 0xff,
  0xcc, 0x1f, 0x36, 0xff, 0xcc, 0x1f, 0x36, 0xff, 0xcc, 0x1f, 0x36, 0xff,
  0xcc, 0x1f, 0x36, 0xff, 0xcc, 0x1f, 0x36, 0xff, 0x75, 0x75, 0x75, 0xff,
  0xcc, 0xcc, 0xcc, 0xff, 0x75, 0x75, 0x75, 0xff, 0x75, 0x75, 0x75, 0xff,
  0x75, 0x75, 0x75, 0xff, 0x75, 0x75, 0x75, 0xff, 0x75, 0x75, 0x75, 0xff,
  0x75, 0x75, 0x75, 0xff, 0x75, 0x75, 0x75, 0xff, 0x75, 0x75, 0x75, 0xff,
  0x75, 0x75, 0x75, 0xff, 0x75, 0x75, 0x75, 0xff, 0x75, 0x75, 0x75, 0xff,
  0x75, 0x75, 0x75, 0xff, 0x75, 0x75, 0x75, 0xff, 0x75, 0x75, 0x75, 0xff,
  0x75, 0x75, 0x75, 0xff
};

template<typename T, bool signed_type = numeric_limits<T>::is_signed>
class numeric_overflow {
public:
	static bool is_overflow(const T& a, const T& b);
};

//template<>
template<typename T>
class numeric_overflow<T, false> {
public:
	static bool is_overflow(const T& a, const T& b)
	{
		if ( !a || !b )
			return false;

		return a > numeric_limits<T>::max() / b;
	}
};

//template<>
template<typename T>
class numeric_overflow<T, true> {
public:
	static bool is_overflow(const T& a, const T& b)
	{
		if ( !a || !b )
			return false;

		if (a > 0) {  /* a is positive */
		if (b > 0) {  /* a and b are positive */
		  if (a > (numeric_limits<T>::max() / b)) {
		    return true;
		  }
		} else { /* a positive, b nonpositive */
		  if (b < (numeric_limits<T>::min() / a)) {
		    return true;
		  }
		} /* a positive, b nonpositive */
		} else { /* a is nonpositive */
		if (b > 0) { /* a is nonpositive, b is positive */
		  if (a < (numeric_limits<T>::min() / b)) {
		    return true;
		  }
		} else { /* a and b are nonpositive */
		  if ( (a != 0) && (b < (numeric_limits<T>::max() / a))) {
		    return true;
		  }
		} /* End if a and b are nonpositive */
		} /* End if a is nonpositive */

		return false;
	}
};

unsigned getPixelIndex(unsigned row, unsigned column, unsigned width)
{
	return row * width + column;
}

PixelType const*generateImage(unsigned/* width*/, unsigned/* height*/)
{
	return reinterpret_cast<PixelType const*>(img_rgba);
}

unsigned getPixelDifference(const PixelType& a, const PixelType& b)
{
	const auto sum1 = a.color.r + a.color.g + a.color.b;
	const auto sum2 = b.color.r + b.color.g + b.color.b;

	return abs(sum1 - sum2);
}

PixelType *findEdges(unsigned width, unsigned height, PixelType const* original, unsigned threashold)
{
	PixelType *result = new PixelType[ width * height];

	for (unsigned r = 0; r < height; ++r)
		for (unsigned c = 0; c < width; ++c)
		{
			const auto& pt = original[getPixelIndex(r, c, width)];
			unsigned diff = 0;

			if (c > 0) diff = max(diff, getPixelDifference(pt, original[getPixelIndex(r, c - 1, width)]) );
			if (c < width-1) diff = max(diff, getPixelDifference(pt, original[getPixelIndex(r, c + 1, width)]) );
			if (r > 0) diff = max(diff, getPixelDifference(pt, original[getPixelIndex(r - 1, c, width)]) );
			if (r < height-1) diff = max(diff, getPixelDifference(pt, original[getPixelIndex(r + 1, c, width)]) );

			if (diff > threashold)
				result[getPixelIndex(r, c, width)].raw = PixelWhite.raw;
		}

	return result;
}

void displayEdgeImage(unsigned width, unsigned height, PixelType const* edges, bool (*predicate)(const PixelType& pixel))
{
	for (unsigned r = 0; r < height; ++r)
	{
		for (unsigned c = 0; c < width; ++c)
			if ( predicate(edges[getPixelIndex(r, c, width)]) )
				cout << "* ";
			else
				cout << "  ";

		cout << endl;
	}
}

void Epic2()
{
	assert( !numeric_overflow<unsigned>::is_overflow(img_rgba_width, img_rgba_height) );

	PixelType const*original = generateImage(img_rgba_width, img_rgba_height);

	const auto lambda = [](const PixelType& pixel)->bool {return pixel.color.r > 200 && pixel.color.g > 200 && pixel.color.b > 200;};

	displayEdgeImage(img_rgba_width, img_rgba_height, original, lambda);
	PixelType *edges = findEdges(img_rgba_width, img_rgba_height, original, 200);
	displayEdgeImage(img_rgba_width, img_rgba_height, edges, lambda);
}

#if !defined(_MSC_VER)
int main()
{
	Epic2();
	return 0;
}
#endif
