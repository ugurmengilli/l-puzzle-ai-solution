#pragma once

#include <QObject>
#include <QList>
#include <QVector>
#include "aiproblem.h"

class LPuzzle : public AiProblem, public QObject
{
	Q_OBJECT

	enum MoveDirection {
		Up,
		Right,
		Down,
		Left
	};

public:
	typedef AiState State;
	
	LPuzzle(int n = 3, QObject *parent = 0);
	LPuzzle(State initialState, int n = 3, QObject *parent = 0);
	~LPuzzle();

	/// <summary> Gets current puzzle state.</summary>
	/// <return> Representation of the puzzle state. </return>
	State getCurrentState();
	/// <summary> Gets the successors of the current state </summary>
	/// <param name='successors'> successors of the current state of the puzzle. </param name>
	void getSuccessors(QVector<State>& successors) const override;
	/// <summary> Checks if puzzle is currently initialized to a valid state. </summary>
	/// <return> True if initialized, false otherwise.</return>
	bool initialized() const;
	/// <summary> Moves the empty tile in the given direction if possible.</summary>
	/// <param name='dir'> Tile move direction.</param name>
	/// <param name='emptyTileIndex'> Position of the empty tile in the puzzle state.</param name>
	/// <return> moved state if possible, empty state otherwise.</return>
	State moveTile(MoveDirection dir, int emptyTileIndex = -1);
	static State moveTile(const State currentState, MoveDirection dir, int emptyTileIndex = -1);
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
};

