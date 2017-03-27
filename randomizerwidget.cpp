#include "randomizerwidget.h"
#include "ui_randomizerwidget.h"

RandomizerWidget::RandomizerWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RandomizerWidget)
{
    ui->setupUi(this);
}

RandomizerWidget::~RandomizerWidget()
{
    delete ui;
}

void RandomizerWidget::on_applyButton_clicked()
{

    ui->feedBackLabel->setText(QString("Operacja w toku."));
    Graph * graph=Engine::getInstance()->getGraph();
    int numberOfRandomization=ui->numberOfRandomizations->value();

    if(Randomizer::Randomize(graph,numberOfRandomization)){
        ui->feedBackLabel->setText(QString("Operacja zakończona sukcesem."));
    }
    else{
        ui->feedBackLabel->setText(QString("Operacja niepowiodła się."));
    }
    Engine::getInstance()->updateGraph();

}
