#include "form.h"
#include "ui_form.h"

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);


}
void Form::paintEvent(QPaintEvent *event){
    Q_UNUSED(event)

    QPainter painter(this);
    painter.setPen(Qt::darkGreen);

    QPoint point;
   for (int i=0;i<10;i++){
        point=QPoint(this->width()/2,this->height()/2)+QPoint(sin(i*18.0*0.0174532925)*this->width()/3,cos(i*18.0*0.0174532925)*this->width()/3);
        painter.drawEllipse(QRect(point,point+QPoint(3,3)));
    }


    painter.drawLine(2, 7, 6, 1);

}

Form::~Form()
{
    delete ui;
}
