#include"C2DDrawWidget.h"
#include<qvector.h>
#include<qapplication.h>
#include<QColorDialog>
C2DDrawWidget::C2DDrawWidget()
{
	PntColor = Qt::black;
	CurveFlag = false;
	LineFlag = false;

}

void C2DDrawWidget::paintEvent(QPaintEvent* event)
{
	QPainter painter(this);
	painter.setPen(QPen(PntColor, 5));
	for (int i = 0; i < points.size(); i++)
	{
		painter.drawPoint(points[i]);
	}

	painter.setPen(QPen(QColor(18, 46, 85), 5));
	for (int i = 0; i < curves.size(); i++)
	{
		painter.drawLine(curves[i]);
	}

	for (int i = 0; i < lines.size(); i++)
	{
		painter.drawLine(lines[i]);
	}

	for (int i = 0; i < ellipse.size(); i++)
	{
		painter.drawEllipse(ellipse[i]);
	}

	painter.drawEllipse(EllipseT);
	painter.drawLine(LineT);
}

void C2DDrawWidget::mousePressEvent(QMouseEvent* event)
{
	lastPos = event->pos();
	update();
}


void C2DDrawWidget::mouseDoubleClickEvent(QMouseEvent* event)
{
	QPoint curPos = event->pos();
	points.append(curPos);
	update();
}

void C2DDrawWidget::mouseMoveEvent(QMouseEvent* event)
{
	QPoint curPos = event->pos();
	QLine t(lastPos, curPos);
	QRect t1(lastPos.x(), lastPos.y(), event->x() - lastPos.x(), event->y() - lastPos.y());


	if (CurveFlag)
	{
		curves.push_back(t);
		lastPos = curPos;
	}

	else if (LineFlag && event->buttons() & Qt::LeftButton)
	{
		LineT = t;
	}

	else if (EllipseFlag)
	{
		EllipseT = t1;
	}
	update();
}

void C2DDrawWidget::mouseReleaseEvent(QMouseEvent* event)
{
	QLine temp(lastPos, event->pos());
	QRect temp1(lastPos.x(), lastPos.y(), event->x() - lastPos.x(), event->y() - lastPos.y());
	if (LineFlag)
	{
		lines.push_back(temp);
	}

	else if (EllipseFlag)
	{
		ellipse.push_back(temp1);
	}
	update();
}

C2DDrawWidget::~C2DDrawWidget()
{

}