#ifndef CONSISTENTWIDGET_H
#define CONSISTENTWIDGET_H

#include <QWidget>
#include "engine.h"
#include "consistent.h"
namespace Ui {
class ConsistentWidget;
}

class ConsistentWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ConsistentWidget(QWidget *parent = 0);
    ~ConsistentWidget();

private slots:
    void on_apply_clicked();

private:
    Ui::ConsistentWidget *ui;
};

#endif // CONSISTENTWIDGET_H
