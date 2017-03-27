#include "sequencewidget.h"
#include "ui_sequencewidget.h"

sequenceWidget::sequenceWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::sequenceWidget)
{
    ui->setupUi(this);
}

sequenceWidget::~sequenceWidget()
{
    delete ui;
}

void sequenceWidget::on_applyButton_clicked()
{
    QString textToParse=ui->sequence->text();
    QStringList listOfElements=textToParse.split(",");

    std::vector<int> sequence;

    bool valid=true;
    foreach (QString element, listOfElements) {
        int value=element.toInt(&valid);
        if(!valid){
            break;
        }
        sequence.push_back(value);
    }

    if(valid){
        if(Sequence::IsGraphical(sequence)){
            Engine::getInstance()->setGraph(Sequence::SequenceMatrix(sequence));
            ui->feedbackLabel->setText(QString("Sekwencja jest graficzna"));
        }
        else{
            ui->feedbackLabel->setText(QString("Sekwencja nie jest graficzna"));
        }
    }
    else{
        ui->feedbackLabel->setText(QString("Format sekwencji nieprawidłowy"));
    }
}

void sequenceWidget::on_applyKButton_clicked()
{
    std::vector<int> sequence=std::vector<int>(ui->kVertex->value(),ui->kRate->value());
    if(Sequence::IsGraphical(sequence)){
        Engine::getInstance()->setGraph(Sequence::SequenceMatrix(sequence));
        ui->feedbackLabel->setText(QString("Generowanie grafu k-krotnego udało się."));
    }
    else{
        ui->feedbackLabel->setText(QString("Nie można stworzyć grafu k-krotnego o takich parametrach."));
    }
}
