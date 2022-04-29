#include"C2DDrawWindow.h"
#include"C2DDrawWidget.h"
#include<QHBoxLayout>
#include<qaction.h>
#include<qtoolbar.h>
#include<qstatusbar.h>
#include<qcolordialog.h>
C2DDrawWindow::C2DDrawWindow()
{
	this->setWindowTitle("2DDrawWindow");//标题

	QIcon icon1("color.jpg");//创建图标
	QIcon icon2("delete.jpg");
	QIcon icon3("CurveLine.jpg");
	QIcon icon4("Lines.jpg");
	QIcon icon5("Ellipse.jpg");

	C2DDrawWidget* mywidget = new C2DDrawWidget;//实例化

	QToolBar* m_tool_bar = new QToolBar();//创建工具栏
	addToolBar(Qt::TopToolBarArea, m_tool_bar);

	QAction* toolbar1 = new QAction(icon1, tr("colorChange"), this);//添加按钮
	QAction* toolbar2 = new QAction(icon2, tr("delete"), this);
	QAction* toolbar3 = new QAction(icon3, tr("curveLine"), this);
	QAction* toolbar4 = new QAction(icon4, tr("Lines"), this);
	QAction* toolbar5 = new QAction(icon5, tr("Ellipse"), this);
	m_tool_bar->addAction(toolbar1);
	m_tool_bar->addAction(toolbar2);
	m_tool_bar->addAction(toolbar3);
	m_tool_bar->addAction(toolbar4);
	m_tool_bar->addAction(toolbar5);


	connect(toolbar1, SIGNAL(triggered()), mywidget, SLOT(slotChangePntColor()));//连接按钮功能
	connect(toolbar2, SIGNAL(triggered()), mywidget, SLOT(slotClearPoint()));
	connect(toolbar3, SIGNAL(triggered()), mywidget, SLOT(slotDrawCurve()));
	connect(toolbar4, SIGNAL(triggered()), mywidget, SLOT(slotDrawLine()));
	connect(toolbar5, SIGNAL(triggered()), mywidget, SLOT(slotDrawEllipse()));

	this->setCentralWidget(mywidget);
}

void C2DDrawWidget::slotChangePntColor()
{
	QColor t_color = QColorDialog::getColor(Qt::white, this);
	if (t_color.isValid())
	{
		PntColor = t_color;
		update();
	}
	else return;
}

void C2DDrawWidget::slotDrawCurve()
{
	CurveFlag = !CurveFlag;
	update();
}

void C2DDrawWidget::slotClearPoint()
{
	LineT.setLine(-100, -100, -100, -100);
	EllipseT.setRect(-100, -100, 0, 0);
	ellipse.clear();
	curves.clear();
	lines.clear();
	points.clear();
	update();
}

void C2DDrawWidget::slotDrawLine()
{
	LineFlag = !LineFlag;
	update();
}

void C2DDrawWidget::slotDrawEllipse()
{
	EllipseFlag = !EllipseFlag;
	update();
}

C2DDrawWindow::~C2DDrawWindow()
{

}