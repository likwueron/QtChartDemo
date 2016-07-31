#ifndef AXISMODEL_HPP
#define AXISMODEL_HPP

#include <QAbstractTableModel>
#include <QList>

class AxisModel : public QAbstractTableModel
{
public:
    AxisModel(QObject *parent = 0x0);
    virtual ~AxisModel();

    QModelIndex index(int row, int column, const QModelIndex &parent) const;
    QModelIndex parent(const QModelIndex &child) const;

    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role);
    bool setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role);
    Qt::ItemFlags flags(const QModelIndex &index) const;

    bool insertRows(int row, int count, const QModelIndex &parent);
    bool removeRows(int row, int count, const QModelIndex &parent);
    bool insertColumns(int column, int count, const QModelIndex &parent);
    bool removeColumns(int column, int count, const QModelIndex &parent);
    //drag & drop will be implenment in further version

public slots:
    void when_seriesAdded(const QString& legendName, int row);
    void when_seriesRemoved(int row);
    void when_seriesExtended(int column);
    void when_seriesShrink(int column);

protected:
    inline int rowNum() const;
    inline int colNum() const;

    QList<double> m_xLegends;
    QList<QString> m_yLegends;

    QList< QList<double> > m_yValues;
};

int AxisModel::rowNum() const
{
    return m_yLegends.count();
}

int AxisModel::colNum() const
{
    return m_xLegends.count();
}

#endif // AXISMODEL_HPP
