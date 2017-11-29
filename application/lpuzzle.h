#pragma once

#include <QObject>

class LPuzzle :	public QObject
{
	Q_OBJECT

public:
	LPuzzle(int n = 3, QObject *parent = 0);
	~LPuzzle();

	/// <summary> Sets the size of n x n game </summary>
	/// <param name='n'> Number of tiles in one edge </param name>
	void setSize(int n);
	/// <summary> Gets the size of n x n game </summary>
	/// <return> Number of tiles in one edge <return>
	int getSize();

private:
	int mSize;
};

