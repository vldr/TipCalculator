#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_TipCalculator.h"
#include <sstream>

class TipCalculator : public QMainWindow
{
	Q_OBJECT

public:
	TipCalculator(QWidget *parent = Q_NULLPTR);
	QString Calculate();
private:
	Ui::TipCalculatorClass ui;
};
