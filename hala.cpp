#include "hala.h"
#include "ui_hala.h"

hala::hala(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::hala)
{
    ui->setupUi(this);
}

hala::~hala()
{
    delete ui;
}
