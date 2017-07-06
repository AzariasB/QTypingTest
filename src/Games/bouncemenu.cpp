

#include "bouncemenu.h"
#include "recttext.h"

#include <QVBoxLayout>

BounceMenu::BounceMenu(QWidget *parent):
QWidget(parent){


	QPushButton *playButton = new QPushButton("Play");
	connect(playButton, SIGNAL(clicked(bool)), this, SIGNAL(playSelected()) );

	QPushButton *helpButton = new QPushButton("Help");
	connect(helpButton, SIGNAL(clicked(bool)), this, SIGNAL(helpSelected()) );

	QPushButton *quitButton = new QPushButton("Quit");
	connect(quitButton, SIGNAL(clicked(bool)) , this, SIGNAL(quitSelected()));

	QVBoxLayout *mainLayout = new QVBoxLayout(this);

	mainLayout->addWidget(new QLabel("Bounce game"));
	mainLayout->addWidget(playButton);
	mainLayout->addWidget(helpButton);
	mainLayout->addWidget(quitButton);
}
