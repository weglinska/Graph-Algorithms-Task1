#include "matrixview.h"

MatrixView::MatrixView(QWidget *parent) : QWidget(parent)
{
    myLayout=NULL;
}



void MatrixView::update(QObject * sender){
    if(sender==this){
        return;
    }
    dataPointer=Engine::getInstance()->getGraph();
    if(myLayout!=NULL){
        for(int i=0;i<myLayout->columnCount();i++){
            for(int j=0;j<myLayout->rowCount();j++){
                if(!myLayout->itemAtPosition(j,i)->isEmpty()){
                    delete myLayout->itemAtPosition(j,i)->widget();
                }
                delete myLayout->itemAtPosition(j,i);
            }
        }
        delete myLayout;
    }

    myLayout=new QGridLayout();
    this->setLayout(myLayout);

    for (int index=0;index<dataPointer->getVerticesNumber();index++){
        // change if new container
        for (int index2=0;index2<(*dataPointer).getVerticesNumber();index2++){
            MatrixVievCell * mv=new MatrixVievCell(QPoint(index2,index),(*dataPointer)[index][index2]);
            connect(mv,SIGNAL(changed(QPoint,int)),this,SLOT(cellChanged(QPoint,int)));
            myLayout->addWidget(mv,index,index2);
        }
    }
    setMaximumSize(((*dataPointer).getVerticesNumber())*27,((*dataPointer).getVerticesNumber())*27);
}

void MatrixView::cellChanged(QPoint coordinates, int value){
    if(value){
        dataPointer->connectVertices(coordinates.y(),coordinates.x());
    }
    else{
        dataPointer->disconnectVertices(coordinates.y(),coordinates.x());
    }

    QLayoutItem * item=myLayout->itemAtPosition(coordinates.x(),coordinates.y());
    QLineEdit * opositeCell=dynamic_cast<QLineEdit *>(item->widget());
    opositeCell->blockSignals(true);
    opositeCell->setText(QString::number(value));
    opositeCell->blockSignals(false);

    emit changed(this);
}
