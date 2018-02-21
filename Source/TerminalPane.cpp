
#include "TerminalPane.h"
#include <QTextEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>

#include "sstream"
#include "iostream"
#include "stdio.h"
#include "Process.h"

TerminalPane::TerminalPane()
    : QDockWidget("Output", 0, 0)
    //, stdoutPipe(stdout)
{
    setObjectName("Output");

    auto layout = new QVBoxLayout();
    {
        layout->setMargin(0);

        auto hLayout = new QHBoxLayout();
        {
            hLayout->setMargin(0);

            auto runButton = new QPushButton("Run");
            runButton->setIcon(QIcon());
            runButton->setMaximumSize(100, 30);
            hLayout->addWidget(runButton);
            connect(runButton, SIGNAL(clicked()), this, SLOT(run()));

            auto clearButton = new QPushButton("Clear");
            clearButton->setIcon(QIcon());
            clearButton->setMaximumSize(100, 30);
            hLayout->addWidget(clearButton);
            connect(clearButton, SIGNAL(clicked()), this, SLOT(clear()));

            //button = new QPushButton("Clear");
            //button->setMaximumSize(100, 30);
            //hLayout->addWidget(button);

            hLayout->addWidget(new QWidget);
        }
        layout->addLayout(hLayout);

        edit = new QTextEdit(nullptr);
        edit->setReadOnly(true);
        layout->addWidget(edit);
    }

    auto widget = new QWidget();
    widget->setLayout(layout);
    setWidget(widget);

    connect(&timer, SIGNAL(timeout()), this, SLOT(work()));
    timer.start(100);
}

void TerminalPane::run()
{
    auto p = Process::create();

    auto path = "C:/Program Files/Git/cmd/git.exe";
    auto commandLine = "status";
    auto directory = "C:/GitTern";

    p->run(path, commandLine, directory);

    printf("start\n");
    if (p->isRunning())
    {
        printf("running...\n");
    }
    int i = 0;
    while (p->isRunning())
    {
        i++;
    }
    printf("end\n");

    auto outputText = p->readOutput();

    printf("== %s ==\n", outputText.c_str());
    fflush(stdout);
}

void TerminalPane::clear()
{
    edit->setPlainText(tr(""));
}

void TerminalPane::work()
{
    /*fflush(stdout);

    auto text = stdoutPipe.readText();
    if (text.size() > 0)
    {
        edit->moveCursor(QTextCursor::End);
        edit->insertPlainText(text.c_str());
    }*/
}

TerminalPane::~TerminalPane()
{
}

