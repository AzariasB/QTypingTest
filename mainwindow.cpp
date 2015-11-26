#include "mainwindow.h"
#include "Tline.h"

MainWindow::MainWindow(QWidget *parent) :
QMainWindow(parent) {
    //Create array of tlineEdit

    //Set stylesheet
    QFile File("style/style.qss");
    File.open(QFile::ReadOnly);
    QString StyleSheet = QLatin1String(File.readAll());
    qApp->setStyleSheet(StyleSheet);


    //Create app
    QWidget *centralW = new QWidget();
    TWindowTest *test = new TWindowTest(QString("Ok so now you have a very long text to copy , ") +
            "first I want to wish you good luck then I have to say faster " +
            "and if the developpers had the time you may know your precision , " +
            "your speed and a score at the end of this rush", centralW);


    connect(test, SIGNAL(endOfExercice(TResult*)), this, SLOT(showEndMessage(TResult*)));

    this->setCentralWidget(centralW);
    this->centralWidget();
    this->setFixedSize(500, 400);
}

void MainWindow::showEndMessage(TResult *finalRes) {
    QString text = QString("The exercice is finished.\n "
            "Number of total keystrokes : %1\n"
            "Number of correct keystrokes : %2\n"
            "Number of wrong keystrokes : %3\n"
            "Number of words per minute : %4")
            .arg(finalRes->getTotalKeysStokres())
            .arg(finalRes->getCorrectKeysStrokes())
            .arg(finalRes->getWrongKeysStrokes())
            .arg(finalRes->getWPM());
    QMessageBox::information(this, "Finished", text);
    qApp->quit();
}

MainWindow::~MainWindow() {
}