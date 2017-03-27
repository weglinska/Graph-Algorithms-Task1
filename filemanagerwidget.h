#ifndef FILEMANAGERWIDGET_H
#define FILEMANAGERWIDGET_H

#include <QWidget>
#include <QFileDialog>
namespace Ui {
class FileManagerWidget;
}

class FileManagerWidget : public QWidget
{
    Q_OBJECT

public:
    explicit FileManagerWidget(QWidget *parent = 0);
    ~FileManagerWidget();

private slots:
    void on_openButton_clicked();

    void on_saveButton_clicked();

private:
    Ui::FileManagerWidget *ui;
};

#endif // FILEMANAGERWIDGET_H
