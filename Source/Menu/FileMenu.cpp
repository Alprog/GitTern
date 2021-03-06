
#include "FileMenu.h"
#include <QFileDialog>
#include "TernApp.h"

FileMenu::FileMenu(MainWindow* window)
    : BaseMenu{"File", window}
{
    QList<QAction*> actions
    {
        createAction("New", "new", SLOT(newFile()), QKeySequence::New),
        createAction("Open", "open", SLOT(openFile()), QKeySequence::Open),
        createAction("Save", "save", SLOT(saveFile()), QKeySequence::Save),
        createAction("Exit", "", SLOT(closeApp()))
    };
    addActions(actions);
}

void FileMenu::newFile()
{
}

void FileMenu::openFile()
{
}

void FileMenu::saveFile()
{
}

void FileMenu::closeApp()
{
    TernApp::getInstance()->quit();
}
