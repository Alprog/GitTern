
# Platform defines

win32|win64:CONFIG += win
unix:!macx:CONFIG += linux
macx:CONFIG += mac

win:DEFINES += WIN
linux:DEFINES += LINUX
mac:DEFINES += MAC

# Default settings

CONFIG -= qt
CONFIG -= debug_and_release debug_and_release_target
CONFIG += c++11

win|mac {
    QMAKE_CXXFLAGS += /wd4250 /wd4800 /wd5030
}

linux {
    QMAKE_CXXFLAGS += -std=c++0x -fpermissive -Wno-attribute
}

# GitTern

TEMPLATE = app

CONFIG += qt
QT += widgets

subdirs = Source Source/Menu

for(subdir, subdirs) {
    dirs += $$subdir

    win:   dirs += $$subdir/Win
    linux: dirs += $$subdir/Linux $$subdir/Unix
    mac:   dirs += $$subdir/Mac $$subdir/Unix
}

for(dir, dirs) {
    INCLUDEPATH += $$dir
    HEADERS += $$files($$dir/*.h)
    HEADERS += $$files($$dir/*.tpp)
    SOURCES += $$files($$dir/*.cpp)
    SOURCES += $$files($$dir/*.mm)
}

RESOURCES = ide.qrc
