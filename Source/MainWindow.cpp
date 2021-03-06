
#include "MainWindow.h"

#include <QAction>
#include <QMenuBar>
#include <QToolBar>
#include <QDockWidget>
#include <QFileDialog>
#include <QEvent>
#include <QCloseEvent>
#include <iostream>
#include "Menu/FileMenu.h"
#include "Menu/TrayMenu.h"
#include "TernApp.h"
#include "TerminalPane.h"
#include "DocumentsPane.h"
#include "LogPane.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , modificationChecking(false)
{
    setWindowTitle("GitTern");
    setWindowIcon(QIcon(":/images/icon.png"));
    setWindowOpacity(1);
    createActions();
    this->installEventFilter(this);

    this->setAnimated(true);
    this->setDockNestingEnabled(true);

    addDockWidget(Qt::LeftDockWidgetArea, new LogPane());
    addDockWidget(Qt::RightDockWidgetArea, new TerminalPane());

    setCentralWidget(new DocumentsPane());
}

MainWindow::~MainWindow()
{
}

void MainWindow::createToolBar(QMenu* menu)
{
    auto toolBar = addToolBar(menu->title());
    toolBar->setObjectName(menu->title() + "ToolBar");
    toolBar->setIconSize(QSize(20, 20));
    for (auto& action : menu->actions())
    {
        if (!action->icon().isNull())
        {
            toolBar->addAction(action);
        }
    }
}

void MainWindow::createActions()
{
    fileMenu = new FileMenu(this);
    menuBar()->addMenu(fileMenu);
    createToolBar(fileMenu);
}

bool MainWindow::eventFilter(QObject* obj, QEvent* event)
{
    if (event->type() == QEvent::WindowActivate)
    {
        if (!modificationChecking)
        {
            modificationChecking = true;
            //documents->checkOutsideModification();
            modificationChecking = false;
        }
    }

    return QMainWindow::eventFilter(obj, event);
}

void MainWindow::closeEvent(QCloseEvent* event)
{
    if (TernApp::getInstance()->isTrayIconVisible())
    {
        hide();
        event->ignore();
    }
}
