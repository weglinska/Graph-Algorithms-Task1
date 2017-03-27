#include "euleriancircuitwidget.h"
#include "ui_euleriancircuitwidget.h"

EulerianCircuitWidget::EulerianCircuitWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EulerianCircuitWidget)
{
    ui->setupUi(this);
    circuitExist=false;
}

EulerianCircuitWidget::~EulerianCircuitWidget()
{
    delete ui;
}

void EulerianCircuitWidget::on_checkAndDraw_clicked()
{

    on_checkIfEulerian_clicked();
    if(circuitExist){
        Engine::getInstance()->setPath(circuit);
    }
}

void EulerianCircuitWidget::on_checkIfEulerian_clicked()
{

    Graph * myGraph=Engine::getInstance()->getGraph();


    circuit=EulerianCircuit::getEulerianCircuit(myGraph);
    if(circuit.size()>1){
        circuitExist=true;
        QString result="Cykl eulera to: ";
        for(int index=0;index<circuit.size();index++){
            result=result+" "+QString::number(circuit[index]);
        }
        ui->feedbackLabel->setText(result);
    }
    else{
        circuitExist=false;
        ui->feedbackLabel->setText(QString("Nie wykryto cyklu Eulera"));

    }

}

void EulerianCircuitWidget::on_generatorApply_clicked()
{
    int vertexCount=ui->generatorVertexNumber->value();
    if(vertexCount>2){
        Engine::getInstance()->setGraph(EulerianCircuit::getEulerianGraph(vertexCount));
    }
}
