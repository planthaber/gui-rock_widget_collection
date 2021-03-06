/* 
 * File:   ArrowItem.cc
 * Author: blueck
 * 
 * Created on 30. Juni 2010, 10:41
 */

#include "ArrowItem.h"

ArrowItem::ArrowItem(int posX, int posY, int groupNr, const QColor &color, int endX, int endY)
      :FillItem(posX, posY, groupNr, color),endX(endX),endY(endY)
{

}

ArrowItem::~ArrowItem()
{
}

void ArrowItem::draw(QPainter* painter,QRectF &source,QRectF &target)
{
    FillItem::draw(painter,source,target);
    QPen pen = painter->pen();
    painter->drawLine(posX, posY, endX, endY);
    double arrowWidth = 10 + (2*lineWidth);
    double deltaX = endX - posX;
    double deltaY = endY - posY;
    double xLength = pow(deltaX, 2);
    double yLength = pow(deltaY, 2);
    double total = sqrt(xLength + yLength);
    double sumX = arrowWidth*(-deltaY/total);
    double sumY = arrowWidth*(deltaX/total);
    QPoint* points = new QPoint[3];
    points[0] = QPoint(endX - sumX, endY - sumY);
    points[1] = QPoint(endX + sumX, endY + sumY);
    points[2] = QPoint(endX + arrowWidth*(deltaX/total), endY + arrowWidth*(deltaY/total));
    painter->drawPolygon(points, 3);
}

