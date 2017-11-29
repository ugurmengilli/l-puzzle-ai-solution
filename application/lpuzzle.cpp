#include "lpuzzle.h"

LPuzzle::LPuzzle(int n, QObject *parent) :
	QObject(parent)
{
	setSize(n);
}

LPuzzle::~LPuzzle()
{
}

void LPuzzle::setSize(int n)
{
	// Set the limits
	int minSize = 3;
	int maxSize = 10;
	int defaultSize = minSize;

	if (n >= minSize && n <= maxSize)
		mSize = n;				// Set the size only if it is valid.
	else if (mSize <= minSize || minSize >= maxSize)
		mSize = defaultSize;	// Otherwise check if the size were previously set to a valid value. If not, it is the first time to attempt to set the size, which is not valid: set to default.
}

int LPuzzle::getSize()
{
	return mSize;
}