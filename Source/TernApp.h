
#pragma once

#include <QApplication>
#include <vector>
#include <string>
#include "MainWindow.h"

class TernApp : public QApplication
{
    Q_OBJECT

    friend int main(int argc, char *argv[]);

    TernApp(int argc, char** argv);

public:
    static TernApp* getInstance();
    void saveSettings();
    MainWindow* getMainWindow();

private:
    std::string getSettingsFilename();

    void start();
    void loadStyle();
    void loadSettings();

public:
    //Settings settings;

private:
    std::vector<MainWindow*> windows;
};
