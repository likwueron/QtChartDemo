#ifndef WIDGET_HPP
#define WIDGET_HPP

#include <QWidget>

namespace Ui {
class Widget;
}

class AxisModel;

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

protected:
    AxisModel *mp_model;

private:
    Ui::Widget *ui;
};

#endif // WIDGET_HPP
