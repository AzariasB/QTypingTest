/*
 * QTypingTest by Pierre and Azarias - https://azariasb.github.io/QTypingTest/
 * License : GNU - GPL 2
 */

/*
 * File:   bouncehelp.h
 * Author: azarias
 *
 */

#include "bouncehelp.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>

BounceHelp::BounceHelp(QWidget *parent) : QWidget(parent)
{
	QVBoxLayout *vLayout = new QVBoxLayout;

	QLabel *mainHelp = new QLabel();
	mainHelp->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
	mainHelp->setFont(QFont("Arial", 24));

	mainHelp->setText("To play this game, you only need your keyboard.\n"
					  "There is a bullet aiming toward a letter,\n"
					  "Your goal is type the letter before the bullet\n"
					  "reaches the wall. If you type the correct letter\n"
					  "The bullet will bounce back to another letter\n"
					  "The bullet goes faster with time, so do you :)\n\n"
					  " - Press any key to go back to the menu - ");


	vLayout->addWidget(mainHelp);

	QPushButton *backButton = new QPushButton("Menu");
	connect(backButton, SIGNAL(clicked(bool)), this, SIGNAL(backToMenu()));
	vLayout->setContentsMargins(100,2,100,2);
	vLayout->addWidget(backButton);

	setLayout(vLayout);
}

void BounceHelp::keyPressEvent(QKeyEvent *event)
{
	Q_UNUSED(event);
	emit backToMenu();
}
