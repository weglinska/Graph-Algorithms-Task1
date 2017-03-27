#include "filemanagerwidget.h"
#include "ui_filemanagerwidget.h"
#include "filemanager.h"
#include "engine.h"

FileManagerWidget::FileManagerWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FileManagerWidget)
{
    ui->setupUi(this);
}

FileManagerWidget::~FileManagerWidget()
{
    delete ui;
}

void FileManagerWidget::on_openButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                    "/home",
                                                    tr("Graph (*.graph *.txt)"));
    Graph * loaded=FileManager::readFromFile(fileName.toStdString());
    if(loaded!=NULL){
        Engine::getInstance()->setGraph(loaded);
    }
}

void FileManagerWidget::on_saveButton_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"),
                               "/home",
                               tr("Graph (*.graph *.txt)"));

    if(fileName.indexOf(".")==-1){
        fileName+=".graph";
    }

    FileManager::writeToFile(Engine::getInstance()->getGraph(),fileName.toStdString());
}
