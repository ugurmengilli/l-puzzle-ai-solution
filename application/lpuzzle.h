#pragma once

#include <QObject>
#include <QList>
#include <QVector>

class LPuzzle :	public QObject
{
	Q_OBJECT

	typedef QList<int> State;

public:
	LPuzzle(int n = 3, QObject *parent = 0);
	LPuzzle(State initialState, int n = 3, QObject *parent = 0);
	~LPuzzle();

	/// <summary> Gets current puzzle state.</summary>
	/// <return> Representation of the puzzle state. </return>
	State getCurrentState();
	/// <summary> Sets the state of the puzzle checking the validity of the state. Validity is determined regardles of previous state (if previously set to a state); that is the empty tile can jump into a place that it wouldn't in a sequence.</summary>
	/// <param name='state'> Any allowable puzzle state concerning the game rules.</param name>
	/// <return> True if given state is allowable; False, otherwise. </return>
	bool setCurrentState(State state);
	/// <summary> Sets the size of n x n game </summary>
	/// <param name='n'> Number of tiles in one edge </param name>
	void setSize(int n);
	/// <summary> Gets the size of n x n game </summary>
	/// <return> Number of tiles in one edge <return>
	int getSize();

private:
	int mSize;
	State mCurrentState;
};

