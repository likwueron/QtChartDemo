#include "widget.hpp"
#include "ui_widget.h"
#include "qchartpresent.hpp"
#include "axismodel.hpp"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    mp_model = new AxisModel();
    ui->axisChartTableView->setModel(mp_model);
}

Widget::~Widget()
{
    delete ui;
}
