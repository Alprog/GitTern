
#pragma once

#include <QApplication>
#include <vector>
#include <string>
#include <QSystemTrayIcon>
#include "MainWindow.h"
#include "Menu/TrayMenu.h"

class TernApp : public QApplication
{
    Q_OBJECT

    friend int main(int argc, char *argv[]);

    TernApp(int argc, char** argv);

public:
    static TernApp* getInstance();

public:
    void saveSettings();
    MainWindow* getMainWindow();
    bool isTrayIconVisible();
    void quit();

private slots:
    void onTrayIconActivated(QSystemTrayIcon::ActivationReason reason);

private:
    std::string getSettingsFilename();

    void loadStyle();
    void loadSettings();
    void initTray();
    void start();

private:
    TrayMenu* trayMenu;
    QSystemTrayIcon *trayIcon;
    //Settings settings;
    std::vector<MainWindow*> windows;
};
