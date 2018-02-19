
#pragma once

#include <QDockWidget>
#include <QTimer>
//#include "Pipe.h"

class QTextEdit;

class TerminalPane : public QDockWidget
{
    Q_OBJECT

public:
    TerminalPane();
    ~TerminalPane();

private slots:
    void run();
    void clear();
    void work();

private:
    QTextEdit* edit;
    //Pipe stdoutPipe;
    QTimer timer;
};
