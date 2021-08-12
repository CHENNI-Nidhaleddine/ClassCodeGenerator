#include "window.h"

Window::Window(): QWidget()
{
    //main Box
    wBox=new QVBoxLayout(this);
    setFont(QFont("Times",12));



   //Class Definition:

   classDefG1=new  QGroupBox("Class Definition :",this);

   //Defining the form rows input fields
   className=new QLineEdit();
   classParents=new QLineEdit();

   //Add input fields to the form
   classDef=new  QFormLayout(classDefG1);
   classDef->addRow("Class's &Name",className);
   classDef->addRow("Class &Parents :",classParents);

   classDefG1->setLayout(classDef);


   //Class Options :

    classOptionsG=new  QGroupBox("Options :",this);

    //Definning the options
    cb1= new QCheckBox("Protect Header from multiple inclusion",classOptionsG);
    cb2= new QCheckBox("Create default constructor",classOptionsG);
    cb3= new QCheckBox("Create defalut destructor",classOptionsG);

    //Add options to Vertical Box Layout
     classOptions=new QVBoxLayout();
     classOptions->addWidget(cb1);
     classOptions->addWidget(cb2);
     classOptions->addWidget(cb3);


     classOptionsG->setLayout(classOptions);


    //Class Comments :

    classCommentsG=new QGroupBox("Add comments",this);


    //Definning the comments input fields:
    author=new QLineEdit();
    classRole=new QTextEdit();
    date=new QDateEdit(QDate::currentDate());

    //Add input fields to the Layout Form
    classComments=new QFormLayout(classCommentsG);
    classComments->addRow("Author",author);
    classComments->addRow("Date",date);
    classComments->addRow("Class Role",classRole);


    classCommentsG->setCheckable(true);
    classCommentsG->setChecked(false);


    generateButton=new QPushButton("Generate");
    quitButton=new QPushButton("Quit");
    buttons=new QHBoxLayout();
    buttons->addWidget(generateButton);
    buttons->addWidget(quitButton);
    //Add all Group Sections to main Box
    wBox->addWidget(classDefG1);
    wBox->addWidget(classOptionsG);
    wBox->addWidget(classCommentsG);
    wBox->addLayout(buttons);

    setLayout(wBox);


    //Connexion:
    connect(quitButton,SIGNAL(clicked()),qApp,SLOT(quit()));
    connect(generateButton,SIGNAL(clicked()),this,SLOT(showCode()));

}
void Window::showCode(){
    QString code="";
    QString codeC="";
    if(className->text().isEmpty()){
     QMessageBox::critical(this,"Error","Class Name Field is Empty!!");
     return;
    }
    code+="class "+className->text();
    if(!classParents->text().isEmpty()){
        code+=":"+classParents->text();
//        QVector<QString> parents=classParents->text().split(",");
//        for(int i=0;i<parents.size();i++){
//            if(parents[i].contains(".h")){
//            codeC+="#include \""+parents[i]+"\"\n";
//            }else{
              codeC+="#include <"+classParents->text()+">\n";
//            }
//        }
    }
    code+=" {\n\n";
    codeC+="\n";
    if(cb2->isChecked()){
        code+="public:\n\t"+className->text()+"();\n";
        codeC+=className->text()+"::"+className->text();
        codeC+= classParents->text().isEmpty()? "{}\n" :":"+classParents->text()+"() {}\n";
    }
    if(cb3->isChecked()){
        code+="\t~"+className->text()+"();\n";
        codeC+=className->text()+"::~"+className->text()+"() {}\n";
    }


    code+="\n}\n";
    if(cb1->isChecked()){
        code="#ifndef "+className->text()+"_H\n#define "+className->text()+"_H\n"+code+"#endif";
    }
    if(classCommentsG->isChecked()){
        code="/**\n\tAuthor: "+author->text()+"\n\tDate: "+date->text()+"\n\tFunction: "+classRole->toMarkdown()+"\n*/\n\n"+code;
    }


    codeSrc=new CodeFiles(code,codeC,className->text());

    codeSrc->show();





}
