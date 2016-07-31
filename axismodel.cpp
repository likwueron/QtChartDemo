#include "axismodel.hpp"

AxisModel::AxisModel(QObject *parent)
    : QAbstractTableModel(parent)
{
    //init data
    m_xLegends.append(0.0);
}

AxisModel::~AxisModel()
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
    Q_UNUSED(parent)
    return m_yValues.count();
}

int AxisModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return m_xLegends.count();
}

QVariant AxisModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid()) return QVariant(0.0);
    //for row need
    //Qt::DisplayRole, Qt::ToolTipRole, Qt::AccessibleTextRole, Qt::AccessibleDescriptionRole

    //for cell only Qt::DisplayRole
    if(Qt::DisplayRole == role) {
        auto row = index.row();
        auto col = index.column();
        if(row < rowNum() && col < colNum()) return QVariant(m_yValues.at(row).at(col));
        else return QVariant(0.0);
    }
    return QVariant("");
}

QVariant AxisModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    switch(orientation) {
    case Qt::Horizontal://col
        if(section < colNum()) return m_xLegends.at(section);
        break;
    case Qt::Vertical://row
        if(section < rowNum()) return m_yLegends.at(section);
        break;
    default:
        break;
    }
    return QVariant("");
}

bool AxisModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(!index.isValid()) return false;
    switch(role) {
    case Qt::DisplayRole: {
        auto row = index.row();
        auto col = index.column();
        if(row < rowNum() && col < colNum()) {
            bool ok;
            auto number = value.toDouble(&ok);
            if(ok) {
                m_yValues[row][col] = number;
                return true;
            }
        }
        return false;
        break;
    }
    default:
        return false;
        break;
    };
}

bool AxisModel::setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role)
{
    //on setting new xlegend increase all list length
    return false;
}

Qt::ItemFlags AxisModel::flags(const QModelIndex &index) const
{
    return Qt::ItemIsSelectable | Qt::ItemIsEditable | Qt::ItemIsEnabled;
}

bool AxisModel::insertRows(int row, int count, const QModelIndex &parent)
{
    return false;
}

bool AxisModel::removeRows(int row, int count, const QModelIndex &parent)
{
    return false;
}

bool AxisModel::insertColumns(int column, int count, const QModelIndex &parent)
{
    return false;
}

bool AxisModel::removeColumns(int column, int count, const QModelIndex &parent)
{
    return false;
}

void AxisModel::when_seriesAdded(const QString &legendName, int row)
{
    row = qMin(rowNum(), row);
    beginInsertRows(QModelIndex(), row, row+1);
    m_yLegends.append(legendName);
    m_yValues.append(QList<double>());
    endInsertRows();
}

void AxisModel::when_seriesRemoved(int row)
{
    row = qMin(rowNum(), row);
    beginRemoveRows(QModelIndex(), row, row+1);
    m_yLegends.removeAt(row);
    m_yValues.removeAt(row);
    endRemoveRows();
}

void AxisModel::when_seriesExtended(int column)
{
    column = qMin(colNum(), column);
    beginInsertColumns(QModelIndex(), column, column+1);
    m_xLegends.append(0.0f);

    int valuesC = m_yValues.count();
    for(int i = 0; i < valuesC; i++) {
        auto y = m_yValues.at(i);
        for(int j = y.count(); j < column; j++) {
            y.append(0.0f);
        }
    }
    endInsertColumns();
}

void AxisModel::when_seriesShrink(int column)
{
    column = qMin(colNum(), column);
    beginRemoveColumns(QModelIndex(), column, column+1);
    endRemoveColumns();
}
