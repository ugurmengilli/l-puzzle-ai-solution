#include "me586th1ugurmengilli.h"

me586th1ugurmengilli::me586th1ugurmengilli(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	// Setup the L-puzzle according to GUI
	puzzle = new LPuzzle(ui.boardSize->value(), this);
	// Update the GUI if there is a change
	ui.boardSize->setValue(puzzle->getSize());
}

me586th1ugurmengilli::~me586th1ugurmengilli()
{

}
