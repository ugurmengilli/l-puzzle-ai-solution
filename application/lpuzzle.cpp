#include <QList>
#include <QVector>
#include "lpuzzle.h"

LPuzzle::LPuzzle(int n, QObject *parent) :
	QObject(parent)
{
	setSize(n);
}

LPuzzle::LPuzzle(State initialState, int n, QObject *parent) :
	LPuzzle(n, parent)
{
	mCurrentState = initialState;
}

LPuzzle::~LPuzzle()
{
}

LPuzzle::State LPuzzle::getCurrentState()
{
	return mCurrentState;
}

void LPuzzle::getSuccessors(QVector<State>& successors)
{
	if (!initialized())		// If puzzle is not initialized, return.
		return;
	
	int emptyTileIndex = mCurrentState.indexOf(0);	// Index of the empty tile.

	for (size_t i = 0; i < 4; i++) {
		// If empty tile can move to in i-th direction, then that state is a successor
		State successor = moveTile(mCurrentState, static_cast<MoveDirection>(i), emptyTileIndex);
		if (!successor.isEmpty())
			successors.append(successor);
	}
	return;
}

bool LPuzzle::initialized()
{
	if (mCurrentState.count())	// Current state is greater than zero.
		return true;
	return false;
}

LPuzzle::State LPuzzle::moveTile(MoveDirection dir, int emptyTileIndex)
{
	if (!initialized())		// Current state is not initialized.
		return State();		// return immediately.

	return moveTile(mCurrentState, dir, emptyTileIndex);
}

LPuzzle::State LPuzzle::moveTile(const State currentState, MoveDirection dir, int emptyTileIndex)
{
	State state = currentState;
	if (emptyTileIndex == -1)
		emptyTileIndex = state.indexOf(0);	// Index of the empty tile.
	int size = sqrt(state.count());

	int newTileIndex = emptyTileIndex;
	switch (dir) {
	case LPuzzle::Up:
		if ((emptyTileIndex % size) > 0)			// Top edge test
			newTileIndex -= 1;
		break;
	case LPuzzle::Right:
		if ((emptyTileIndex / size) < (size - 1))	// Right edge test
			newTileIndex += size;
		break;
	case LPuzzle::Down:
		if ((emptyTileIndex % size) < (size - 1))	// Bottom edge test
			newTileIndex += 1;
		break;
	case LPuzzle::Left:
		if ((emptyTileIndex / size) > 0)			// Left edge test
			newTileIndex -= size;
		break;
	default:
		break;
	}
	if (newTileIndex == emptyTileIndex)
		state.clear();
	else
		state.swap(emptyTileIndex, newTileIndex);
	return state;
}

bool LPuzzle::setCurrentState(State state)
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