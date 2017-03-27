#ifndef GENERATORSWIDGET_H
#define GENERATORSWIDGET_H

#include <QWidget>
#include "graph.h"

namespace Ui {
class GeneratorsWidget;
}

class GeneratorsWidget : public QWidget
{
    Q_OBJECT

public:
    explicit GeneratorsWidget(QWidget *parent = 0);
    ~GeneratorsWidget();

private:
    Ui::GeneratorsWidget *ui;
private slots:
    void generatePointSide();
    void generatePointProbability();
signals:
    void graphGenerated(Graph * graph);

};

#endif // GENERATORSWIDGET_H
