#ifndef CODEFILES_H
#define CODEFILES_H
#include <QApplication>
#include <QWidget>
#include <QFormLayout>
#include <QLineEdit>
#include <QGroupBox>
#include <QCheckBox>
#include <QVBoxLayout>
#include <QTextEdit>
#include <QDateEdit>
#include <QPushButton>
#include <QMessageBox>
#include <QTabWidget>
#include <QFile>
#include <QFileDialog>

class CodeFiles:public QDialog
{
    Q_OBJECT
public:
    CodeFiles();
    CodeFiles(QString,QString,QString);
public slots:
    void downloadFiles();
private:
    QString *m_className;
    QString *m_codeH;
    QString *m_codeC;
    QTabWidget *tabs;
    QVBoxLayout *mainBox;
    QHBoxLayout *buttonsBox;
    QTextEdit *header;
    QTextEdit *cpp;
    QPushButton *closeButton;
    QPushButton *downloadButton;
};

#endif // CODEFILES_H
