#include "groupact.h"
#include "ui_groupact.h"

groupAct::groupAct(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::groupAct)
{
    ui->setupUi(this);
}

groupAct::~groupAct()
{
    delete ui;
}

