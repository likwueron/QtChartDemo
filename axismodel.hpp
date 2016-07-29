#ifndef AXISMODEL_HPP
#define AXISMODEL_HPP

#include <QAbstractTableModel>

class AxisModel : QAbstractTableModel
{
public:
    AxisModel(QObject *parent = 0x0);


    QModelIndex index(int row, int column, const QModelIndex &parent) const;
    QModelIndex parent(const QModelIndex &child) const;

    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role);
    //bool setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role);
    Qt::ItemFlags flags(const QModelIndex &index) const;

    bool insertRows(int row, int count, const QModelIndex &parent);
    bool removeRows(int row, int count, const QModelIndex &parent);

    //drag & drop will be implenment in further version
};

#endif // AXISMODEL_HPP
