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


private:
	LPuzzle *puzzle;
	Ui::me586th1ugurmengilliClass ui;
};

#endif // ME586TH1UGURMENGILLI_H
