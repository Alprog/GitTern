
#pragma once

#include "BaseMenu.h"

class TrayMenu : public BaseMenu
{
    Q_OBJECT

public:
    TrayMenu(MainWindow* window);

public slots:
    void showMainWindow();
    void closeApp();
};
