#ifndef CONNECTIONMATRIXVIEW_H
#define CONNECTIONMATRIXVIEW_H

#include <QWidget>
#include <QVBoxLayout>
#include "graph.h"
#include <QLabel>
#include "engine.h"
class ConnectionMatrixView : public QWidget
{
    Q_OBJECT
    Graph * source;
    QVBoxLayout * myLayout;
public:
    explicit ConnectionMatrixView(QWidget *parent = 0);
signals:

public slots:
    void update(QObject * sender=NULL);
};

#endif // CONNECTIONMATRIXVIEW_H
