#include <QtWidgets>
#include "dialog.h"

Dialog::Dialog()
{
    // create the dialog box with buttons
    createHorizontalGroupBox();

    // text field: score of player
    QLabel *scoreLabel = new QLabel(tr("Score: "));

    // image of extra items
    QLabel *myimage = new QLabel();

    // TODO: relative path
    QPixmap pix("C:/Arbeit/Projekte/_FHA_Qt_Vorlesung/git_25_11_2015/Qt2D-Shooter/Playground/ShopPreliminary/items/weapons1.jpg");

    // TODO: make the picture dependent of clicked button
    //  QPixmap pix(pic);

    myimage->setPixmap(pix);

    // adds the exit function to OK button
    buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok);
    connect(buttonBox, SIGNAL(accepted()), this, SLOT(accept()));

    QVBoxLayout *mainLayout = new QVBoxLayout;

    // adding horizontal placed buttons
    mainLayout->addWidget(horizontalGroupBox);

    // adding OK and Cancel buttons on bottom right
    mainLayout->addWidget(buttonBox);

    // adding score field
    mainLayout->addWidget(scoreLabel);

    // display item image
    mainLayout->addWidget(myimage);

    setLayout(mainLayout);

    setWindowTitle(tr("EXTRA ITEM SHOP"));
}

void Dialog::createHorizontalGroupBox()
{
    // create the dialog box with buttons
    horizontalGroupBox = new QGroupBox(tr("Extra item choice"));

    QHBoxLayout *layout = new QHBoxLayout;

    buttons[0] = new QPushButton(tr("Double Shot (10 coins)"));
    layout->addWidget(buttons[0]);

    buttons[1] = new QPushButton("Extra Life (5 coins)");
    layout->addWidget(buttons[1]);

    connect(buttons[0], SIGNAL(clicked()), this, SLOT(buttonWeaponClicked()));

    horizontalGroupBox->setLayout(layout);
}

void Dialog::buttonWeaponClicked() {
    // TODO: relative path
    QPixmap pic("C:/Arbeit/Projekte/_FHA_Qt_Vorlesung/basiclayouts_lok/weapons1.jpg");
}


