QT       += core gui
#使用core和gui库 其实这个也是Qt的默认设置 可以省略
#如果需要使用其他的库，例如使用数据库应该加上 QT   +=sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
##这是针对Qt5的变化，Qt5的application是在QtWidgets中的，因此要包含这个库
#使用C++11的标准进行编译
CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
#定义编译选项
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
#工程中包含的源文件
SOURCES += \
    main.cpp \
    mainwindow.cpp
#工程中包含的头文件
HEADERS += \
    mainwindow.h \
    work.h
#工程中包含的.ui设计文件
FORMS += \
    mainwindow.ui

# Default rules for deployment.添加部署命令：
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
