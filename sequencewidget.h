#ifndef SEQUENCEWIDGET_H
#define SEQUENCEWIDGET_H

#include <QWidget>
#include "sequence.h"
#include "engine.h"

namespace Ui {
class sequenceWidget;
}

class sequenceWidget : public QWidget
{
    Q_OBJECT

public:
    explicit sequenceWidget(QWidget *parent = 0);
    ~sequenceWidget();

private slots:
    void on_applyButton_clicked();

    void on_applyKButton_clicked();

private:
    Ui::sequenceWidget *ui;
};

#endif // SEQUENCEWIDGET_H
