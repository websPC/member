#ifndef GROUPACT_H
#define GROUPACT_H

#include <QWidget>

namespace Ui {
class groupAct;
}

class groupAct : public QWidget
{
    Q_OBJECT

public:
    explicit groupAct(QWidget *parent = 0);
    ~groupAct();




private:
    Ui::groupAct *ui;
};

#endif // GROUPACT_H
