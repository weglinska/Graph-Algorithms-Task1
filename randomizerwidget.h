#ifndef RANDOMIZERWIDGET_H
#define RANDOMIZERWIDGET_H

#include <QWidget>
#include "randomizer.h"
#include "engine.h"

namespace Ui {
class RandomizerWidget;
}

class RandomizerWidget : public QWidget
{
    Q_OBJECT

public:
    explicit RandomizerWidget(QWidget *parent = 0);
    ~RandomizerWidget();

private slots:
    void on_applyButton_clicked();

private:
    Ui::RandomizerWidget *ui;
};

#endif // RANDOMIZERWIDGET_H
