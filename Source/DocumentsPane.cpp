
#include <QTabBar>
#include "DocumentsPane.h"

DocumentsPane::DocumentsPane()
{
    setTabsClosable(true);
    setMovable(true);
    setUsesScrollButtons(true);
    setObjectName("documentsTabs");
    tabBar()->setObjectName("documentsTabs");
}
