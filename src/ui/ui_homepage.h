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
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(page_learn->sizePolicy().hasHeightForWidth());
        page_learn->setSizePolicy(sizePolicy);
        page_learn->setAutoFillBackground(false);
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
        QWidget::setTabOrder(button_home, button_learn);
        QWidget::setTabOrder(button_learn, button_games);
        QWidget::setTabOrder(button_games, button_practice);
        QWidget::setTabOrder(button_practice, button_stats);

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
