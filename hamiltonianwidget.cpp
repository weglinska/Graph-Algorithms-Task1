#include "hamiltonianwidget.h"
#include "ui_hamiltonianwidget.h"

HamiltonianWidget::HamiltonianWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HamiltonianWidget),cycleExist(false)
{
    ui->setupUi(this);
}

HamiltonianWidget::~HamiltonianWidget()
{
    delete ui;
}

void HamiltonianWidget::on_search_clicked()
{
    Graph * myGraph=Engine::getInstance()->getGraph();
    std::vector<int> cycle=HamiltonianCycle::hamiltonianCycle(myGraph);
    if(cycle.size()>1){
        QString result="Przykładowy cykl: ";
        for(int index=0;index<cycle.size();index++){
            result=result+" "+QString::number(cycle[index]+1);
        }
        ui->feedbackLabel->setText(result);
        cycleExist=true;
        cycle.push_back(cycle[0]);
        myCycle=cycle;
    }
    else{
        ui->feedbackLabel->setText(QString("Nie wykryto cyklu."));
        cycleExist=false;
    }
}

void HamiltonianWidget::on_drawOnCanvas_clicked()
{
    on_search_clicked();
    if(cycleExist){
        Engine::getInstance()->setPath(myCycle);
    }
}
