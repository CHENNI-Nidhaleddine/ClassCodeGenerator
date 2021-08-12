#ifndef WINDOW_H
#define WINDOW_H
#include "codefiles.h"

class Window : public QWidget
{
    Q_OBJECT
public:
    Window();
public slots:
    void showCode();
private:

    QVBoxLayout *wBox;


    QGroupBox *classDefG1;
    QFormLayout *classDef;
    QLineEdit *className;
    QLineEdit *classParents;

     QGroupBox *classOptionsG;
    QVBoxLayout *classOptions;
    QCheckBox *cb1;
    QCheckBox *cb2;
    QCheckBox *cb3;


    QGroupBox *classCommentsG;
     QLineEdit *author;
     QTextEdit *classRole;
     QDateEdit *date;

    QFormLayout *classComments;

    QHBoxLayout *buttons;
    QPushButton *generateButton;
    QPushButton *quitButton;

    CodeFiles *codeSrc;
};


#endif // WINDOW_H
