#ifndef ME586TH1UGURMENGILLI_H
#define ME586TH1UGURMENGILLI_H

#include <QtWidgets/QMainWindow>
#include "lpuzzle.h"
#include "ui_me586th1ugurmengilli.h"

class me586th1ugurmengilli : public QMainWindow
{
	Q_OBJECT

public:
	me586th1ugurmengilli(QWidget *parent = 0);
	~me586th1ugurmengilli();

public slots:
	void clearBoard();
	void displayBoardState(const QList<int> state);
	void generateBoard(int n);

	void on_boardSize_valueChanged(int value);
	void on_fillRandomButton_clicked();
	void on_generateBoardButton_clicked();

private:
	LPuzzle* puzzle;
	QWidget* board;
	Ui::me586th1ugurmengilliClass ui;
};

#endif // ME586TH1UGURMENGILLI_H
