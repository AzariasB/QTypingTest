/********************************************************************************
** Form generated from reading UI file 'homepage.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOMEPAGE_H
#define UI_HOMEPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionChange_user;
    QAction *actionOnline_competitoin;
    QAction *actionOthers;
    QAction *actionText_practice;
    QAction *actionMap_keyboard;
    QAction *actionLanguage;
    QAction *actionPreferences;
    QAction *actionChange_user_2;
    QAction *actionHomepage;
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *button_home;
    QPushButton *button_learn;
    QPushButton *button_practice;
    QPushButton *button_stats;
    QPushButton *button_games;
    QGridLayout *gridLayout_2;
    QStackedWidget *stack_main;
    QWidget *page_learn;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_7;
    QLabel *label;
    QLabel *label_5;
    QLabel *label_14;
    QLabel *label_6;
    QLabel *label_11;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_13;
    QLabel *label_12;
    QLabel *label_8;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_17;
    QWidget *page_home;
    QWidget *page_practice;
    QLabel *label_2;
    QWidget *page_stats;
    QLabel *label_3;
    QWidget *page_games;
    QLabel *label_4;
    QMenuBar *menubar;
    QMenu *menuUser;
    QMenu *menuOptions;
    QMenu *menuAbout;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 600);
        actionChange_user = new QAction(MainWindow);
        actionChange_user->setObjectName(QStringLiteral("actionChange_user"));
        actionOnline_competitoin = new QAction(MainWindow);
        actionOnline_competitoin->setObjectName(QStringLiteral("actionOnline_competitoin"));
        actionOthers = new QAction(MainWindow);
        actionOthers->setObjectName(QStringLiteral("actionOthers"));
        actionText_practice = new QAction(MainWindow);
        actionText_practice->setObjectName(QStringLiteral("actionText_practice"));
        actionMap_keyboard = new QAction(MainWindow);
        actionMap_keyboard->setObjectName(QStringLiteral("actionMap_keyboard"));
        actionLanguage = new QAction(MainWindow);
        actionLanguage->setObjectName(QStringLiteral("actionLanguage"));
        actionPreferences = new QAction(MainWindow);
        actionPreferences->setObjectName(QStringLiteral("actionPreferences"));
        actionChange_user_2 = new QAction(MainWindow);
        actionChange_user_2->setObjectName(QStringLiteral("actionChange_user_2"));
        actionHomepage = new QAction(MainWindow);
        actionHomepage->setObjectName(QStringLiteral("actionHomepage"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 0, 801, 551));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        button_home = new QPushButton(verticalLayoutWidget);
        button_home->setObjectName(QStringLiteral("button_home"));

        horizontalLayout_2->addWidget(button_home);

        button_learn = new QPushButton(verticalLayoutWidget);
        button_learn->setObjectName(QStringLiteral("button_learn"));

        horizontalLayout_2->addWidget(button_learn);

        button_practice = new QPushButton(verticalLayoutWidget);
        button_practice->setObjectName(QStringLiteral("button_practice"));

        horizontalLayout_2->addWidget(button_practice);

        button_stats = new QPushButton(verticalLayoutWidget);
        button_stats->setObjectName(QStringLiteral("button_stats"));

        horizontalLayout_2->addWidget(button_stats);

        button_games = new QPushButton(verticalLayoutWidget);
        button_games->setObjectName(QStringLiteral("button_games"));

        horizontalLayout_2->addWidget(button_games);


        verticalLayout->addLayout(horizontalLayout_2);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        stack_main = new QStackedWidget(verticalLayoutWidget);
        stack_main->setObjectName(QStringLiteral("stack_main"));
        page_learn = new QWidget();
        page_learn->setObjectName(QStringLiteral("page_learn"));
        horizontalLayoutWidget = new QWidget(page_learn);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(0, 0, 801, 511));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        scrollArea = new QScrollArea(horizontalLayoutWidget);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 797, 507));
        gridLayoutWidget = new QWidget(scrollAreaWidgetContents);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(0, 0, 791, 511));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(gridLayoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout->addWidget(label_7, 0, 1, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 2, 0, 1, 1);

        label_5 = new QLabel(gridLayoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 3, 0, 1, 1);

        label_14 = new QLabel(gridLayoutWidget);
        label_14->setObjectName(QStringLiteral("label_14"));

        gridLayout->addWidget(label_14, 0, 3, 1, 1);

        label_6 = new QLabel(gridLayoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 0, 0, 1, 1);

        label_11 = new QLabel(gridLayoutWidget);
        label_11->setObjectName(QStringLiteral("label_11"));

        gridLayout->addWidget(label_11, 1, 4, 1, 1);

        label_9 = new QLabel(gridLayoutWidget);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout->addWidget(label_9, 1, 2, 1, 1);

        label_10 = new QLabel(gridLayoutWidget);
        label_10->setObjectName(QStringLiteral("label_10"));

        gridLayout->addWidget(label_10, 1, 3, 1, 1);

        label_13 = new QLabel(gridLayoutWidget);
        label_13->setObjectName(QStringLiteral("label_13"));

        gridLayout->addWidget(label_13, 1, 0, 1, 1);

        label_12 = new QLabel(gridLayoutWidget);
        label_12->setObjectName(QStringLiteral("label_12"));

        gridLayout->addWidget(label_12, 1, 1, 1, 1);

        label_8 = new QLabel(gridLayoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout->addWidget(label_8, 0, 2, 1, 1);

        label_15 = new QLabel(gridLayoutWidget);
        label_15->setObjectName(QStringLiteral("label_15"));

        gridLayout->addWidget(label_15, 0, 4, 1, 1);

        label_16 = new QLabel(gridLayoutWidget);
        label_16->setObjectName(QStringLiteral("label_16"));

        gridLayout->addWidget(label_16, 0, 5, 1, 1);

        label_17 = new QLabel(gridLayoutWidget);
        label_17->setObjectName(QStringLiteral("label_17"));

        gridLayout->addWidget(label_17, 0, 6, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        horizontalLayout->addWidget(scrollArea);

        stack_main->addWidget(page_learn);
        page_home = new QWidget();
        page_home->setObjectName(QStringLiteral("page_home"));
        stack_main->addWidget(page_home);
        page_practice = new QWidget();
        page_practice->setObjectName(QStringLiteral("page_practice"));
        label_2 = new QLabel(page_practice);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(220, 180, 211, 151));
        stack_main->addWidget(page_practice);
        page_stats = new QWidget();
        page_stats->setObjectName(QStringLiteral("page_stats"));
        label_3 = new QLabel(page_stats);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(230, 220, 67, 17));
        stack_main->addWidget(page_stats);
        page_games = new QWidget();
        page_games->setObjectName(QStringLiteral("page_games"));
        label_4 = new QLabel(page_games);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(210, 260, 67, 17));
        stack_main->addWidget(page_games);

        gridLayout_2->addWidget(stack_main, 0, 0, 1, 1);


        verticalLayout->addLayout(gridLayout_2);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 25));
        menuUser = new QMenu(menubar);
        menuUser->setObjectName(QStringLiteral("menuUser"));
        menuOptions = new QMenu(menubar);
        menuOptions->setObjectName(QStringLiteral("menuOptions"));
        menuAbout = new QMenu(menubar);
        menuAbout->setObjectName(QStringLiteral("menuAbout"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuUser->menuAction());
        menubar->addAction(menuOptions->menuAction());
        menubar->addAction(menuAbout->menuAction());
        menuUser->addAction(actionChange_user_2);
        menuUser->addAction(actionHomepage);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionChange_user->setText(QApplication::translate("MainWindow", "Change user", 0));
        actionOnline_competitoin->setText(QApplication::translate("MainWindow", "Online Competition", 0));
        actionOthers->setText(QApplication::translate("MainWindow", "Others", 0));
        actionText_practice->setText(QApplication::translate("MainWindow", "Text practice", 0));
        actionMap_keyboard->setText(QApplication::translate("MainWindow", "Map keyboard", 0));
        actionLanguage->setText(QApplication::translate("MainWindow", "Language", 0));
        actionPreferences->setText(QApplication::translate("MainWindow", "Preferences", 0));
        actionChange_user_2->setText(QApplication::translate("MainWindow", "Change user", 0));
        actionHomepage->setText(QApplication::translate("MainWindow", "Homepage", 0));
        button_home->setText(QApplication::translate("MainWindow", "Home", 0));
        button_learn->setText(QApplication::translate("MainWindow", "Learn", 0));
        button_practice->setText(QApplication::translate("MainWindow", "Practice", 0));
        button_stats->setText(QApplication::translate("MainWindow", "Statistics", 0));
        button_games->setText(QApplication::translate("MainWindow", "Games", 0));
        label_7->setText(QApplication::translate("MainWindow", "fj", 0));
        label->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        label_5->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        label_14->setText(QApplication::translate("MainWindow", "dk", 0));
        label_6->setText(QApplication::translate("MainWindow", "The basics", 0));
        label_11->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        label_9->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        label_10->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        label_13->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        label_12->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        label_8->setText(QApplication::translate("MainWindow", "dk", 0));
        label_15->setText(QApplication::translate("MainWindow", "dk", 0));
        label_16->setText(QApplication::translate("MainWindow", "dk", 0));
        label_17->setText(QApplication::translate("MainWindow", "dk", 0));
        label_2->setText(QApplication::translate("MainWindow", "Practice", 0));
        label_3->setText(QApplication::translate("MainWindow", "Statistics", 0));
        label_4->setText(QApplication::translate("MainWindow", "games", 0));
        menuUser->setTitle(QApplication::translate("MainWindow", "User", 0));
        menuOptions->setTitle(QApplication::translate("MainWindow", "Options", 0));
        menuAbout->setTitle(QApplication::translate("MainWindow", "About", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOMEPAGE_H
