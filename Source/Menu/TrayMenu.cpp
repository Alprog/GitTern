
#include "TrayMenu.h"
#include <QFileDialog>
#include "../TernApp.h"

TrayMenu::TrayMenu(MainWindow* window)
    : BaseMenu{"Tray", window}
{
    QList<QAction*> actions
    {
        createAction("Show", "", SLOT(showMainWindow())),
        createAction("Quit", "", SLOT(closeApp())),
    };
    addActions(actions);
}

void TrayMenu::showMainWindow()
{
    TernApp::getInstance()->getMainWindow()->show();
}

void TrayMenu::closeApp()
{
    TernApp::getInstance()->quit();
}
