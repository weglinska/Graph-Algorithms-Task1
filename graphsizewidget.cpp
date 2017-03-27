#include "graphsizewidget.h"
#include "ui_graphsizewidget.h"

GraphSizeWidget::GraphSizeWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GraphSizeWidget)
{
    ui->setupUi(this);
    connect(ui->applyButton,SIGNAL(clicked(bool)),this,SLOT(apply()));
}

GraphSizeWidget::~GraphSizeWidget()
{
    delete ui;
}

void GraphSizeWidget::apply(){
    emit changed(ui->count->value());
}


