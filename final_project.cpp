#include "final_project.h"
#include "ui_final_project.h"

Final_project::Final_project(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Final_project)
{
    ui->setupUi(this);
}

Final_project::~Final_project()
{
    delete ui;
}
