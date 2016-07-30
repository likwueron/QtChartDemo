#include "axismodel.hpp"

AxisModel::AxisModel(QObject *parent)
    : QAbstractTableModel(parent)
{

}

QModelIndex AxisModel::index(int row, int column, const QModelIndex &parent) const
{
    return QAbstractTableModel::index(row, column, parent);
}

QModelIndex AxisModel::parent(const QModelIndex &child) const
{
    Q_UNUSED(child)
    return QModelIndex();
}

int AxisModel::rowCount(const QModelIndex &parent) const
{

}

int AxisModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return 3;
}

QVariant AxisModel::data(const QModelIndex &index, int role) const
{
    //for row need
    //Qt::DisplayRole, Qt::ToolTipRole, Qt::AccessibleTextRole, Qt::AccessibleDescriptionRole

    //for cell only Qt::DisplayRole
    if(Qt::DisplayRole == role) {

    }
}

QVariant AxisModel::headerData(int section, Qt::Orientation orientation, int role) const
{

}

bool AxisModel::setData(const QModelIndex &index, const QVariant &value, int role)
{

}

bool AxisModel::setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role)
{

}

Qt::ItemFlags AxisModel::flags(const QModelIndex &index) const
{
    //for row
//    Qt::ItemIsSelectable | Qt::ItemIsEnabled;

    //for cell
    return Qt::ItemIsSelectable | Qt::ItemIsEditable | Qt::ItemIsEnabled;
}

bool AxisModel::insertRows(int row, int count, const QModelIndex &parent)
{
    beginInsertRows(parent, row, row+1);
    endInsertRows();
}

bool AxisModel::removeRows(int row, int count, const QModelIndex &parent)
{
    beginRemoveRows(parent, row, row+1);
    endRemoveRows();
}
