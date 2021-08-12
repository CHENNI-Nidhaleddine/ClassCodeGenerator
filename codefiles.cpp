#include "codefiles.h"


CodeFiles::CodeFiles(QString codeH,QString codeC,QString className):QDialog()
{
   m_className=new QString(className);
   m_codeH=new QString(codeH);
   m_codeC=new QString(codeC);
   setFont(QFont("Courier",14));
   setModal(true);
   mainBox=new QVBoxLayout(this);
   setMinimumSize(400,400);
   buttonsBox=new QHBoxLayout();
   tabs=new QTabWidget();

   mainBox->addWidget(tabs);

   header=new QTextEdit();
   header->setPlainText(codeH);
   cpp=new QTextEdit();
   cpp->setPlainText(codeC);
   closeButton=new QPushButton("Close");
   downloadButton=new QPushButton("Download");
   buttonsBox->addWidget(closeButton);
   buttonsBox->addWidget(downloadButton);
   mainBox->addLayout(buttonsBox);
   tabs->addTab(header,m_className->toUtf8()+".h");
   tabs->addTab(cpp,m_className->toUtf8()+".c");



     connect(closeButton,SIGNAL(clicked()),this,SLOT(close()));
     connect(downloadButton,SIGNAL(clicked()),this,SLOT(downloadFiles()));

}
void CodeFiles::downloadFiles(){
    QString path = QFileDialog::getExistingDirectory(this);

     QFile Hfile(path+ "/"+m_className->toUtf8()+".h");
     Hfile.open(QIODevice::WriteOnly);
     Hfile.write(m_codeH->toUtf8());
     QFile Cfile(path+ "/"+m_className->toUtf8()+".cpp");
     Cfile.open(QIODevice::WriteOnly);
     Cfile.write(m_codeC->toUtf8());
     Hfile.close();
     Cfile.close();
     this->close();

     QMessageBox::information(this,"Sucess","Your files has been added to "+path);

}


