
#include "LogPane.h"
#include <QTableWidgetItem>
#include <QHeaderView>
#include <Commit.h>
#include <PrettyFormatter.h>
#include <PrettyField.h>

LogPane::LogPane()
    : QDockWidget("Log", nullptr, nullptr)
{
    setObjectName("Log");

    table = new QTableWidget(nullptr);
    table->setSelectionBehavior(QAbstractItemView::SelectRows);

    table->setColumnCount(4);
    table->setRowCount(10);
    table->setShowGrid(false);



    auto verticalHeader = table->verticalHeader();
    verticalHeader->setDefaultSectionSize(verticalHeader->minimumSectionSize());
    verticalHeader->setVisible(false);


    table->setRowHeight(2, table->minimumHeight());

    auto item = new QTableWidgetItem("Hello");
    item->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
    table->setItem(0, 1, item);

    setWidget(table);

    //git log -n 3 --decorate=short --pretty="%H%n%P%n%an (%ae)%n%at%n%s%n%N%n%D%n---%n"
    refresh();
}

LogPane::~LogPane()
{
}

void LogPane::refresh()
{
    PrettyFormatter<Commit> formatter;
    formatter.addField<std::string>(&Commit::guid, "%H");
    formatter.addField<std::string>(&Commit::author, "an (%ae)");
    formatter.addField<std::string>(&Commit::title, "%s");
}

