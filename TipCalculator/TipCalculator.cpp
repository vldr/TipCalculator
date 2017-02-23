#include "TipCalculator.h"

#include <QtPlugin>
Q_IMPORT_PLUGIN(QWindowsIntegrationPlugin)

TipCalculator::TipCalculator(QWidget *parent)
	: QMainWindow(parent)
{
	// Setup ui.
	ui.setupUi(this);

	// Initalize QIcon variable
	QIcon icon(":/TipCalculator/Resources/TipCalculator.png");

	// Set the icon of the window.
	setWindowIcon(icon);

	// Set custom title.
	setWindowTitle("Tip Calculator (" + QString(__DATE__) + ")");

	// Make the window not resizable.
	setWindowFlags(Qt::Window | Qt::MSWindowsFixedSizeDialogHint | Qt::WindowCloseButtonHint);

	// Bind the button click to the function.
	connect(ui.calculateButton, &QPushButton::clicked, [this] {
		// Set the info label text to the calculated text.
		ui.infoLabel->setText(Calculate());
	}); 
}

QString TipCalculator::Calculate() {
	// Initalize string variables, and get the LineEdit value;
	QString billInput = ui.billInput->text();
	QString percentageInput = ui.percentInput->text();

	// Initalize double variables, and parse the string counterpart to a double.
	double billInputDouble = billInput.toDouble();
	double percentageInputDouble = percentageInput.toDouble(); 
	 
	// Check if it's zero or a negative number.
	if (percentageInputDouble <= 0 || billInputDouble <= 0)
		return "Error!";

	// Calculate the total tip and the total bill.
	double totalTip = billInputDouble * (percentageInputDouble / 100);
	double totalBill = billInputDouble + totalTip;

	// Input all the numbers and text together.
	QString finalResponse = "Your total tip: <b>$" + QString::number(totalTip, 'g', 14) + "</b><br>"
		+ "Your total bill with the tip: <b>$" + QString::number(totalBill, 'g', 14) + "</b>";

	// Return the final string.
	return finalResponse;
}