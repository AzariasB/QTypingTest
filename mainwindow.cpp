#include "mainwindow.h"
#include "Tline.h"

MainWindow::MainWindow(QWidget *parent) :
QMainWindow(parent){
    //Create array of tlineEdit
    
    //Set stylesheet
    QFile File("style/style.qss");
    File.open(QFile::ReadOnly);
    QString StyleSheet = QLatin1String(File.readAll());
    qApp->setStyleSheet(StyleSheet);
    
    
    //Create app
    QWidget *centralW = new QWidget();
    TWindowTest *test = new TWindowTest(QString("Ok so know you have a very long text to copy ") +
            "first I want to wish you good luck then I have to say faster " +
            "and if the developper had the time you may know your precison " +
            "your speed and a score at the end of this rush",centralW);
    
    
    connect(test,SIGNAL(endOfExercice()),this,SLOT(showEndMessage()));

    this->setCentralWidget(centralW);
    this->centralWidget();
    this->setFixedSize(500,400);
}

void MainWindow::showEndMessage() {
    QMessageBox::information(this,"Finished","The exercice is finished");
    qApp->quit();
}


MainWindow::~MainWindow() {}