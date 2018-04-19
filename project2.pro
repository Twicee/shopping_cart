#-------------------------------------------------
#
# Project created by QtCreator 2018-04-08T16:54:41
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = project2
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    shoppingcart.cpp \
    showbutton.cpp \
    addbutton.cpp \
    carttable.cpp \
    deletebutton.cpp

HEADERS += \
        mainwindow.h \
    shoppingcart.h \
    BinarySearch.h \
    Bird.h \
    BubbleSort.h \
    BubbleSortDecreasing.h \
    BubbleSortIncreasing.h \
    Cat.h \
    Dog.h \
    Fish.h \
    Pet.h \
    PetDatabase.h \
    PetDatabaseSearchable.h \
    PetDatabaseSearchableByName.h \
    PetDatabaseSearchableByPrice.h \
    PetDatabaseSearchableByType.h \
    PetDatabaseSearchableByWeight.h \
    PetDatabaseSortable.h \
    PetDatabaseSortableByName.h \
    PetDatabaseSortableByPrice.h \
    PetDatabaseSortableByType.h \
    PetDatabaseSortableByWeight.h \
    SearchableVector.h \
    SortableVector.h \
    builder.h \
    builder.h \
    databasebuilder.h \
    databaseparser.h \
    visitor.h \
    nonstackbasedsumvisitor.h \
    showbutton.h \
    addbutton.h \
    carttable.h \
    deletebutton.h

FORMS += \
        mainwindow.ui \
    shoppingcart.ui

DISTFILES += \
    Project 2 Description.docx \
    Bundles.csv \
    Pets.csv
