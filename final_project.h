#ifndef FINAL_PROJECT_H
#define FINAL_PROJECT_H

#include <QMainWindow>

namespace Ui {
class Final_project;
}

class Final_project : public QMainWindow
{
    Q_OBJECT

public:
    explicit Final_project(QWidget *parent = 0);
    ~Final_project();

private:
    Ui::Final_project *ui;
};

#endif // FINAL_PROJECT_H
