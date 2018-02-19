
#include "TernApp.h"
#include <QFile>
#include <QTextStream>
#include "MainWindow.h"
#include "Platform.h"

TernApp::TernApp(int argc, char** argv)
    : QApplication(argc, argv)
{
    if (fileno(stdout) <= 0)
    {
        freopen("log.txt", "w", stdout);
    }

    loadStyle();
    loadSettings();
    start();
}

TernApp* TernApp::getInstance()
{
    return static_cast<TernApp*>(QApplication::instance());
}

void TernApp::loadStyle()
{
    QFile file("style.css");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream stream(&file);
        QString sheet = stream.readAll();
        setStyleSheet(sheet);
    }
    file.close();
}

std::string TernApp::getSettingsFilename()
{
    return "settings." + getPlatformName() + ".lua";
}

void TernApp::loadSettings()
{
    /*auto fileName = getSettingsFilename();
    QFile file(QString::fromStdString(fileName));
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream stream(&file);
        auto text = stream.readAll().toStdString();
        settings = serializer.deserialize(text);
        file.close();
    }*/
}

void TernApp::saveSettings()
{
    /*auto fileName = getSettingsFilename();
    QFile file(QString::fromStdString(fileName));
    file.open(QIODevice::WriteOnly);
    QTextStream stream(&file);
    auto text = serializer.serialize(settings);
    stream << tr(text.c_str());
    file.close();*/
}

void TernApp::start()
{
    auto mainWindow = new MainWindow();
    mainWindow->showMaximized();
    windows.push_back(mainWindow);
}

MainWindow* TernApp::getMainWindow()
{
    return windows[0];
}
