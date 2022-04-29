#include "MainWindow.h"
#include<qmenubar.h>
#include<qcoreapplication.h>
#include"C2DDrawWindow.h"

MainWindow::MainWindow()
{
    this->setGeometry(100, 100, 800, 600);
    setWindowTitle(tr("Main Window"));
    
    QMenu* file = menuBar()->addMenu(tr("&File"));
    QMenu* view = menuBar()->addMenu(tr("&View"));

    QAction* m_2d_draw = new QAction(tr("2DDrawWindow"), this);
    m_2d_draw->setStatusTip(tr(" window"));
    view->addAction(m_2d_draw);
    connect(m_2d_draw, SIGNAL(triggered()), this, SLOT(slot2DDraw()));
    
    m_mdiarea = new QMdiArea;
    setCentralWidget(m_mdiarea);
}

MainWindow::~MainWindow()
{

}

void MainWindow::slot2DDraw()
{
    C2DDrawWindow* c2ddrawwindow = new C2DDrawWindow;
    m_mdiarea->addSubWindow(c2ddrawwindow)->setGeometry(0, 0, 1000, 800);
    c2ddrawwindow->show();
}


