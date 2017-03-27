#ifndef EULERIANCIRCUITWIDGET_H
#define EULERIANCIRCUITWIDGET_H

#include <QWidget>
#include "euleriancircuit.h"
#include "engine.h"
namespace Ui {
class EulerianCircuitWidget;
}

class EulerianCircuitWidget : public QWidget
{
    Q_OBJECT

public:
    explicit EulerianCircuitWidget(QWidget *parent = 0);
    ~EulerianCircuitWidget();

private slots:
    void on_checkAndDraw_clicked();

    void on_checkIfEulerian_clicked();

    void on_generatorApply_clicked();

private:
    Ui::EulerianCircuitWidget *ui;
    std::vector<int> circuit;
    bool circuitExist;
};

#endif // EULERIANCIRCUITWIDGET_H
