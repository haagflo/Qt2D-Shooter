#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

QT_BEGIN_NAMESPACE
class QDialogButtonBox;
class QGroupBox;
class QLabel;
class QPushButton;
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog();

private:
    void createHorizontalGroupBox();

    QGroupBox *horizontalGroupBox;
    QPushButton *buttons[2];
    QDialogButtonBox *buttonBox;
    QPixmap pic;
    QAction *exitAction;

private slots:
    void buttonWeaponClicked();
};

#endif // DIALOG_H
