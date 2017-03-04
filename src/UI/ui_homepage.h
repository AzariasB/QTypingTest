/********************************************************************************
** Form generated from reading UI file 'homepage.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "Pages/gamepage.h"
#include "Pages/homepage.h"
#include "Pages/learnpage.h"
#include "Pages/practicepage.h"
#include "Pages/tstatistics.h"

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
    QAction *action_change_user;
    QAction *action_homepage;
    QAction *action_about;
    QAction *action_option;
    QAction *action_aboutQt;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *button_home;
    QPushButton *button_learn;
    QPushButton *button_practice;
    QPushButton *button_stats;
    QPushButton *button_games;
    QGridLayout *gridLayout_2;
    QStackedWidget *stack_main;
    LearnPage *page_learn;
    HomePage *page_home;
    PracticePage *page_practice;
    TStatistics *page_stats;
    GamePage *page_games;
    QStatusBar *statusbar;
    QMenuBar *menubar;
    QMenu *menuUser;
    QMenu *menuHelp;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(629, 464);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMouseTracking(false);
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
        action_change_user = new QAction(MainWindow);
        action_change_user->setObjectName(QStringLiteral("action_change_user"));
        action_change_user->setEnabled(false);
        action_homepage = new QAction(MainWindow);
        action_homepage->setObjectName(QStringLiteral("action_homepage"));
        action_homepage->setEnabled(false);
        action_about = new QAction(MainWindow);
        action_about->setObjectName(QStringLiteral("action_about"));
        action_option = new QAction(MainWindow);
        action_option->setObjectName(QStringLiteral("action_option"));
        action_option->setEnabled(false);
        action_aboutQt = new QAction(MainWindow);
        action_aboutQt->setObjectName(QStringLiteral("action_aboutQt"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        centralwidget->setMouseTracking(false);
        centralwidget->setAcceptDrops(false);
        centralwidget->setToolTipDuration(-1);
        centralwidget->setAutoFillBackground(false);
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setSizeConstraint(QLayout::SetMaximumSize);
        horizontalLayout_2->setContentsMargins(-1, -1, 0, -1);
        button_home = new QPushButton(centralwidget);
        button_home->setObjectName(QStringLiteral("button_home"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(button_home->sizePolicy().hasHeightForWidth());
        button_home->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(button_home);

        button_learn = new QPushButton(centralwidget);
        button_learn->setObjectName(QStringLiteral("button_learn"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(button_learn->sizePolicy().hasHeightForWidth());
        button_learn->setSizePolicy(sizePolicy2);

        horizontalLayout_2->addWidget(button_learn);

        button_practice = new QPushButton(centralwidget);
        button_practice->setObjectName(QStringLiteral("button_practice"));
        sizePolicy2.setHeightForWidth(button_practice->sizePolicy().hasHeightForWidth());
        button_practice->setSizePolicy(sizePolicy2);

        horizontalLayout_2->addWidget(button_practice);

        button_stats = new QPushButton(centralwidget);
        button_stats->setObjectName(QStringLiteral("button_stats"));
        sizePolicy2.setHeightForWidth(button_stats->sizePolicy().hasHeightForWidth());
        button_stats->setSizePolicy(sizePolicy2);

        horizontalLayout_2->addWidget(button_stats);

        button_games = new QPushButton(centralwidget);
        button_games->setObjectName(QStringLiteral("button_games"));
        sizePolicy2.setHeightForWidth(button_games->sizePolicy().hasHeightForWidth());
        button_games->setSizePolicy(sizePolicy2);

        horizontalLayout_2->addWidget(button_games);


        verticalLayout->addLayout(horizontalLayout_2);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        stack_main = new QStackedWidget(centralwidget);
        stack_main->setObjectName(QStringLiteral("stack_main"));
        sizePolicy.setHeightForWidth(stack_main->sizePolicy().hasHeightForWidth());
        stack_main->setSizePolicy(sizePolicy);
        page_learn = new LearnPage();
        page_learn->setObjectName(QStringLiteral("page_learn"));
        sizePolicy.setHeightForWidth(page_learn->sizePolicy().hasHeightForWidth());
        page_learn->setSizePolicy(sizePolicy);
        page_learn->setLayoutDirection(Qt::LeftToRight);
        page_learn->setAutoFillBackground(false);
        stack_main->addWidget(page_learn);
        page_home = new HomePage();
        page_home->setObjectName(QStringLiteral("page_home"));
        sizePolicy.setHeightForWidth(page_home->sizePolicy().hasHeightForWidth());
        page_home->setSizePolicy(sizePolicy);
        stack_main->addWidget(page_home);
        page_practice = new PracticePage();
        page_practice->setObjectName(QStringLiteral("page_practice"));
        sizePolicy.setHeightForWidth(page_practice->sizePolicy().hasHeightForWidth());
        page_practice->setSizePolicy(sizePolicy);
        stack_main->addWidget(page_practice);
        page_stats = new TStatistics();
        page_stats->setObjectName(QStringLiteral("page_stats"));
        sizePolicy.setHeightForWidth(page_stats->sizePolicy().hasHeightForWidth());
        page_stats->setSizePolicy(sizePolicy);
        stack_main->addWidget(page_stats);
        page_games = new GamePage();
        page_games->setObjectName(QStringLiteral("page_games"));
        sizePolicy.setHeightForWidth(page_games->sizePolicy().hasHeightForWidth());
        page_games->setSizePolicy(sizePolicy);
        stack_main->addWidget(page_games);

        gridLayout_2->addWidget(stack_main, 0, 0, 1, 1);


        verticalLayout->addLayout(gridLayout_2);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 629, 19));
        menuUser = new QMenu(menubar);
        menuUser->setObjectName(QStringLiteral("menuUser"));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        MainWindow->setMenuBar(menubar);
        QWidget::setTabOrder(button_home, button_learn);
        QWidget::setTabOrder(button_learn, button_practice);
        QWidget::setTabOrder(button_practice, button_stats);
        QWidget::setTabOrder(button_stats, button_games);

        menubar->addAction(menuUser->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuUser->addAction(action_change_user);
        menuUser->addAction(action_homepage);
        menuUser->addAction(action_option);
        menuHelp->addAction(action_about);
        menuHelp->addAction(action_aboutQt);

        retranslateUi(MainWindow);

        stack_main->setCurrentIndex(3);


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
        action_change_user->setText(QApplication::translate("MainWindow", "Change user", 0));
        action_homepage->setText(QApplication::translate("MainWindow", "Homepage", 0));
        action_about->setText(QApplication::translate("MainWindow", "About", 0));
        action_option->setText(QApplication::translate("MainWindow", "Option", 0));
        action_aboutQt->setText(QApplication::translate("MainWindow", "About Qt", 0));
        button_home->setText(QApplication::translate("MainWindow", "Home", 0));
        button_learn->setText(QApplication::translate("MainWindow", "Learn", 0));
        button_practice->setText(QApplication::translate("MainWindow", "Practice", 0));
        button_stats->setText(QApplication::translate("MainWindow", "Statistics", 0));
        button_games->setText(QApplication::translate("MainWindow", "Games", 0));
        menuUser->setTitle(QApplication::translate("MainWindow", "User", 0));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOMEPAGE_H
