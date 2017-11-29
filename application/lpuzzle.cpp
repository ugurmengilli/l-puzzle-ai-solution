#include "lpuzzle.h"

LPuzzle::LPuzzle(int n, QObject *parent) :
	QObject(parent)
{
	setSize(n);
}

LPuzzle::LPuzzle(QList<int> initialState, int n, QObject *parent) :
	LPuzzle(n, parent)
{
	mCurrentState = initialState;
}

LPuzzle::~LPuzzle()
{
}

bool LPuzzle::setCurrentState(QList<int> state)
{
	int tileCount = getSize() * getSize();	// Number of tiles

	for (int tile = 0; tile < tileCount; tile++) {
		// Each and every tile should exist and should occur only once.
		if (state.count(tile) == 1)
			continue;
		else
			return false;	// Otherwise, given state is not obey the game rules.
	}
	mCurrentState = state;
	return true;
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