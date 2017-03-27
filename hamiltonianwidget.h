#ifndef HAMILTONIANWIDGET_H
#define HAMILTONIANWIDGET_H

#include <QWidget>
#include "engine.h"
#include "hamiltoniancycle.h"
#include <vector>
namespace Ui {
class HamiltonianWidget;
}

class HamiltonianWidget : public QWidget
{
    Q_OBJECT

public:
    explicit HamiltonianWidget(QWidget *parent = 0);
    ~HamiltonianWidget();

private slots:
    void on_search_clicked();
    void on_drawOnCanvas_clicked();

private:
    Ui::HamiltonianWidget *ui;
    bool cycleExist;
    std::vector<int> myCycle;


};

#endif // HAMILTONIANWIDGET_H
