#ifndef GRAPHSIZEWIDGET_H
#define GRAPHSIZEWIDGET_H

#include <QWidget>

namespace Ui {
class GraphSizeWidget;
}

class GraphSizeWidget : public QWidget
{
    Q_OBJECT

public:
    explicit GraphSizeWidget(QWidget *parent = 0);
    ~GraphSizeWidget();
private:
    Ui::GraphSizeWidget *ui;
    QWidget * matrixElement;
private slots:
    void apply();

signals:
    void changed(int newSize);
};

#endif // GRAPHSIZEWIDGET_H
