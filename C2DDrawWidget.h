#pragma once
#include<QPainter>
#include<QPaintEvent>
#include<QWidget>
#include<QWheelEvent>
#include<QColor>
#include<QPoint>
#include<QLine>


class C2DDrawWidget :public QWidget
{
	Q_OBJECT;
public:
	C2DDrawWidget();
	~C2DDrawWidget();

private:
	QVector<QPoint> points;
	QVector<QLine> curves;
	QVector<QLine> lines;
	QVector<QRect> ellipse;

	QPoint lastPos;
	QLine LineT;
	QRect EllipseT;

	bool CurveFlag;
	bool LineFlag;
	bool EllipseFlag;

protected:
	void mousePressEvent(QMouseEvent* event);
	void mouseDoubleClickEvent(QMouseEvent* event);
	void paintEvent(QPaintEvent*);
	void mouseMoveEvent(QMouseEvent* event);
	void mouseReleaseEvent(QMouseEvent* event);
	
	QColor PntColor;
public slots:
	void slotChangePntColor();
	void slotClearPoint();
	void slotDrawCurve();
	void slotDrawLine();
	void slotDrawEllipse();
};