#include "generatorswidget.h"
#include "ui_generatorswidget.h"

GeneratorsWidget::GeneratorsWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GeneratorsWidget)
{
    ui->setupUi(this);
    connect(ui->pointSideTrigget,SIGNAL(clicked(bool)),this,SLOT(generatePointSide()));
    connect(ui->pointProbabilityTrigget,SIGNAL(clicked(bool)),this,SLOT(generatePointProbability()));
}

GeneratorsWidget::~GeneratorsWidget()
{
    delete ui;
}

void GeneratorsWidget::generatePointProbability(){
    Graph * g=Graph::pointProbabilityGenerator(ui->vertexCount->value(),ui->probability->value());
    if(g){
        emit graphGenerated(g);
    }
}

void GeneratorsWidget::generatePointSide(){
    Graph * g=Graph::pointSideGenerator(ui->vertexCount->value(),ui->connections->value());
    if(g){
        emit graphGenerated(g);
    }
}
