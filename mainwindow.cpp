#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Engine::getInstance()->changeGraphSize(5);


    connect(ui->matrix,SIGNAL(changed(QObject *)),Engine::getInstance(),SLOT(updateGraph(QObject*)));
    connect(ui->list,SIGNAL(changed(QObject *)),Engine::getInstance(),SLOT(updateGraph(QObject*)));
    connect(ui->connectionAdd,SIGNAL(changed(QObject *)),Engine::getInstance(),SLOT(updateGraph(QObject*)));

    connect(ui->graphSize,SIGNAL(changed(int)),Engine::getInstance(),SLOT(changeGraphSize(int)));
    connect(ui->generators,SIGNAL(graphGenerated(Graph*)),Engine::getInstance(),SLOT(setGraph(Graph*)));

    connect(Engine::getInstance(),SIGNAL(changedGraph(QObject*)),ui->matrix,SLOT(update(QObject*)));
    connect(Engine::getInstance(),SIGNAL(changedGraph(QObject*)),ui->list,SLOT(update(QObject*)));
    connect(Engine::getInstance(),SIGNAL(changedGraph(QObject*)),ui->graph,SLOT(update(QObject*)));
    connect(Engine::getInstance(),SIGNAL(changedGraph(QObject*)),ui->connectionAdd,SLOT(update(QObject*)));
    connect(Engine::getInstance(),SIGNAL(changedGraph(QObject*)),ui->connectionMatrix,SLOT(update(QObject*)));
}
MainWindow::~MainWindow()
{
    delete ui;
    Engine::getInstance()->removeGraph();
}

