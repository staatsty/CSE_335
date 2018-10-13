//Author: Tyler Staats,Samuel Batali
#include "mainwindow.h"
#include <QApplication>
#include <iostream>     // std::cout
#include <fstream>
#include <QDebug>
#include <QFile>
#include "pet.h"
#include "bird.h"
#include "cat.h"
#include "fish.h"
#include "dog.h"
#include "databuilder.h"
#include "dataparser.h"
#include <QDir>
#include "BubbleSortDecreasing.h"
#include "PetDatabaseSortableByName.h"



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
