
#pragma once

#include <QDockWidget>
#include <QTableWidget>

class QTextEdit;

class LogPane : public QDockWidget
{
    Q_OBJECT

public:
    LogPane();
    ~LogPane();

private slots:
    void refresh();

private:
    QTableWidget* table;
};
