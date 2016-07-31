#include "widget.hpp"
#include "ui_widget.h"
#if QT_VERSION >= 0x050700
#include "qchartpresent.hpp"
#endif
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
    delete mp_model;
}

void Widget::on_axisChartTableView_clicked(const QModelIndex &index)
{

}
