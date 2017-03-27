#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include "graph.h"
#include "engine.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    std::vector<std::vector<bool> >tmp;

private slots:

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
