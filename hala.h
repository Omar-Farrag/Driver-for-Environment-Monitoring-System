#ifndef HALA_H
#define HALA_H

#include <QMainWindow>

namespace Ui {
class hala;
}

class hala : public QMainWindow
{
    Q_OBJECT

public:
    explicit hala(QWidget *parent = nullptr);
    ~hala();

private:
    Ui::hala *ui;
};

#endif // HALA_H
