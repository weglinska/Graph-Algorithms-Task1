#include "graphpainter.h"

GraphPainter::GraphPainter(QWidget *parent) : QWidget(parent)
{
    pointerToGraphMatrix=NULL;
    pointColor=QColor(Qt::red);
    lineColor=QColor(Qt::gray);
    pathColor=QColor(Qt::green);
    showLabels=true;
}

void GraphPainter::update(QObject * sender){
    Q_UNUSED (sender);
    pointerToGraphMatrix=Engine::getInstance()->getGraph();
    repaint();
}

void GraphPainter::paintEvent(QPaintEvent * event){
    Q_UNUSED(event);
    if(pointerToGraphMatrix==NULL) return;

    QPoint widgetCenter(this->width()/2,this->height()/2);

    QVector<QPoint> pointsCordinates;
    int numberOfElements=pointerToGraphMatrix->getVerticesNumber();

    float angleStep=2.0*PI/numberOfElements;
    float radius=width()>height()?height():width();

    for(int index=0;index<numberOfElements;index++){
        QPoint point;

        point.setX(sin(angleStep*index)*radius/2.5);
        point.setY(cos(angleStep*index)*radius/2.5);
        pointsCordinates.push_back(point+widgetCenter);
    }

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(QPen(lineColor,2));


    for(int index=0;index<numberOfElements;index++){
        // idzie po górnym trójkącie
        for(int index2=index;index2<numberOfElements;index2++){
            if((*pointerToGraphMatrix)[index][index2]){
                painter.drawLine(pointsCordinates[index],pointsCordinates[index2]);

            }
        }
    }

    painter.setPen(QPen(pathColor,2));
    std::vector<int> path=Engine::getInstance()->path;
    for(int indexOfFirst=0;indexOfFirst+1<path.size();indexOfFirst++){
        if(path[indexOfFirst]>=0 && path[indexOfFirst]<pointsCordinates.length()
                && path[indexOfFirst+1]>=0 && path[indexOfFirst+1]<pointsCordinates.length()){
            QPoint A=pointsCordinates[path[indexOfFirst]];
            QPoint B=pointsCordinates[path[indexOfFirst+1]];

            painter.drawLine(A,B);
        }
        else{
            break;
        }
    }

    painter.setPen(QPen(pointColor,2));
    int ID=1;
    for(int index=0;index<numberOfElements;index++){
        // idzie po górnym trójkącie
        for(int index2=index;index2<numberOfElements;index2++){
            if((*pointerToGraphMatrix)[index][index2]){
                QPoint textCord((pointsCordinates[index].x()+pointsCordinates[index2].x())/2,(pointsCordinates[index].y()+pointsCordinates[index2].y())/2);
                painter.drawText(textCord,QString::number(ID));
                ID++;
            }
        }
    }
    for(int index=0;index<numberOfElements;index++){
        QPoint point=pointsCordinates[index];

        painter.setPen(QPen(pointColor,2));
        painter.drawEllipse(point,3,3);

        if(showLabels){
            painter.setPen(Qt::black);
            painter.drawText(point+QPoint(4,-4),QString::number(index+1));
        }
    }




}

void GraphPainter::setPointColor(QColor pointC){
    pointColor=pointC;
}

void GraphPainter::setLineColor(QColor lineC){
    lineColor=lineC;
}
