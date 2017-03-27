#include "consistentwidget.h"
#include "ui_consistentwidget.h"

ConsistentWidget::ConsistentWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ConsistentWidget)
{
    ui->setupUi(this);
}

ConsistentWidget::~ConsistentWidget()
{
    delete ui;
}

void ConsistentWidget::on_apply_clicked()
{
    Graph * myGraph=Engine::getInstance()->getGraph();
    std::vector<int> list;
    list=Consistent::getMaxConsistent(myGraph->getAdjacencyMatrix(),myGraph->getVerticesNumber());
    QString text="Największa spójna składowa zawiera wierzchołki: ";
    for(int index=0;index<list.size();index++){
        text=text+" "+QString::number(list[index]);
        list[index]--;
    }
    ui->feedbackLabel->setText(text);
    Engine::getInstance()->setPath(list);
}
