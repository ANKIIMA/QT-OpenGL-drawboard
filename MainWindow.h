#pragma once
#include <QtWidgets/QMainWindow>
#include<qmainwindow.h>
#include<qmdiarea.h>
#include<qmdisubwindow.h>

class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
    MainWindow();
    ~MainWindow();

    QMdiArea* m_mdiarea;

public slots:
    void slot2DDraw();
};
