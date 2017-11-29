#include <qgridlayout.h>
#include "me586th1ugurmengilli.h"

me586th1ugurmengilli::me586th1ugurmengilli(QWidget *parent)
	: QMainWindow(parent),
	board(nullptr)
{
	ui.setupUi(this);

	// Setup the L-puzzle according to GUI
	puzzle = new LPuzzle(ui.boardSize->value(), this);
	// Update the GUI if there is a change
	ui.boardSize->setValue(puzzle->getSize());
}

me586th1ugurmengilli::~me586th1ugurmengilli()
{
	if (board)
		delete board;
}

void me586th1ugurmengilli::clearBoard()
{
	delete board;		// Reclaim the memory from heap.
	board = nullptr;	// Set the address of the pointer to null since all checks are done using this property.
}

void me586th1ugurmengilli::displayBoardState(const QList<int> state)
{
	if (!board)		// Don't attempt to display if board is not generated.
		return;

	for (size_t i = 0; i < state.count(); i++)
	{
		// Get the i-th tile on the board. Since the board does not know the type of the tile, cast the general QWidget* to QPushButton*.
		QPushButton* tile = static_cast<QPushButton*>(board->layout()->itemAt(i)->widget());
		// Take the i-th element of the tile list.
		int tileNumber = state[i];
		if (tileNumber == 0) {	// Then leave text of this tile empty
			tile->setText(" ");
			continue;
		}
		// Set the text of the tile to the random number.
		tile->setText(QString::number(tileNumber));
	}
}

void me586th1ugurmengilli::generateBoard(int n)
{
	// If there is board already, clear the board then generate a new board.
	if (board != nullptr)
		clearBoard();
	// Create an empty widget to contain tiles of the board so that when the widget is deleted, all the board can be cleared. Setting the parent as displayBox puts the board into 'Display' group.
	board = new QWidget(ui.displayBox);
	// Move to board to the just beneath a label.
	board->move(ui.generateLabel->x(),
		ui.generateLabel->y() + ui.generateLabel->height() + 5);
	// We want all tiles to be generated in a 2D matrix form. Qt provides such layout via following. By setting the board as parent, the grid is automatically deleted from the memory.
	QGridLayout* boardLayout = new QGridLayout(board);
	// Fill the board with tiles.
	for (size_t i = 0; i < n*n; i++)
	{
		QPushButton* tile = new QPushButton(board);	// Tiles are implemented as buttons.
		boardLayout->addWidget(tile, i % n, i / n);		// Add tiles to the board in given x-y indices.
	}
	board->setLayout(boardLayout);
	board->show();
}

void me586th1ugurmengilli::on_boardSize_valueChanged(int value)
{
	// Whenever board size is changed, valueChanged signal is emitted. When the size is changed, let the function of the button switch to generate the new board.
	ui.generateBoardButton->setText("Generate Board");
	ui.fillRandomButton->setEnabled(false);
}

void me586th1ugurmengilli::on_fillRandomButton_clicked()
{
	int tileCount = powf(ui.boardSize->value(), 2);	// The number of tiles on the board.
													// Generate a list containing all required numbers to set the text of the tiles.
	QList<int> numbers;
	for (size_t i = 0; i < tileCount; i++)
		numbers.append(i);
	// Shuffle the list so that the numbers are distributed randomly.
	std::random_shuffle(numbers.begin(), numbers.end());
	// Display the random state
	displayBoardState(numbers);
}

void me586th1ugurmengilli::on_generateBoardButton_clicked()
{
	// This button can be used for two functionality: generate a board and clear the board. The correct functionality is determined by the text on the button.
	if (ui.generateBoardButton->text() == "Generate Board") {
		generateBoard(ui.boardSize->value());
		ui.generateBoardButton->setText("Clear Board");
		ui.fillRandomButton->setEnabled(true);
	}
	else if (ui.generateBoardButton->text() == "Clear Board") {
		clearBoard();
		ui.generateBoardButton->setText("Generate Board");
	}
}
