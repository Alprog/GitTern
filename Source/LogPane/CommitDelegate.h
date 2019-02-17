
#pragma once

#include <QStyledItemDelegate>

class CommitDelegate : public QStyledItemDelegate
{
protected:
    void paint(QPainter* painter, const QStyleOptionViewItem& opt, const QModelIndex& index) const;
};
