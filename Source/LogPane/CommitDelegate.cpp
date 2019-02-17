
#include <CommitDelegate.h>
#include <QPainter>

void CommitDelegate::paint(QPainter* painter, const QStyleOptionViewItem& opt, const QModelIndex& index) const
{
    (void)index;

    if (opt.state & QStyle::State_Selected)
    {
        painter->setBrush(Qt::green);
    }
    else
    {
        painter->setBrush(Qt::blue);
    }

    painter->drawEllipse(opt.rect.center(), 5, 5);
}
