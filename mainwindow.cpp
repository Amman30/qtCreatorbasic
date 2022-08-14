#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>
#include <QPixmap>
#include <QFile>
#include <QTextStream>
#include <QDir>
#include <QFileDialog>
#include <QDateTime>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/amzma/Downloads/1631973172862.jpg");
    ui->label_Pic->setPixmap(pix);
     connect(ui->horizontalSlider,SIGNAL(valueChanged(int)),ui->progressBar,SLOT(setValue(int)));
     time=new QTimer(this);
}

MainWindow::~MainWindow()
{
    delete ui;

}


void MainWindow::on_pushButton_clicked()
{
    ui->label->setText("Amman");
}


void MainWindow::on_pushButton_2_clicked()
{

}


void MainWindow::on_pushButton_3_clicked()
{
   QMessageBox::StandardButton reply=
           QMessageBox::question(this,"Title","Is Your religion ISLAM",QMessageBox::Yes | QMessageBox::No);
   if(reply==QMessageBox::Yes){
       QApplication::quit();
   }
   else
//qDebug()<<"Ur a loser";
       QMessageBox::warning(this,"hie","Sorry ur a loser");

}




void MainWindow::on_pushButton_4_clicked()
{
//QDialog secDialog;
//secDialog.setModal(true);
//secDialog.exec();
hide();
    secdialog = new QDialog(this);
    secdialog->show();

}


void MainWindow::on_pushButton_5_clicked()

{

    QString username=ui->lineEdit_username->text();
        QString password=ui->lineEdit_password->text();

        if(username == "Amman" && password == "test"){
            QMessageBox::information(this,"Login","Login Success");
hide();
login=new QDialog(this);
login->show();


        }
        else

        {

            QMessageBox::warning(this,"worng","Worng Password");
        }
}


void MainWindow::on_label_Pic_linkActivated(const QString &link)
{

}

void MainWindow::on_actionNew_triggered()
{
    QMessageBox::information(this,"New","New Called");
}


void MainWindow::on_actionAdd_triggered()
{
     QMessageBox::information(this,"Add","Add Called");
}


void MainWindow::on_actionQuit_triggered()
{
//    QMessageBox::warning(this,"Quit","Quit Clcked");
}


void MainWindow::on_pushButton_write_clicked()
{
    QString file_name=QFileDialog::getOpenFileName(this,"",QDir::homePath());
    QFile file(file_name);
    if(!file.open(QFile::WriteOnly | QFile::Text)){
        QMessageBox::warning(this,"error","File not opend");
    }
    QTextStream out(&file);
    QString text=ui->plainTextEdit->toPlainText();
    out<<text;
    file.flush();
    file.close();

}

void MainWindow::on_pushButton_read_clicked()

{
    QString Filter="All file (*.*);; JavaScript File(*.js);; pythonFile(*.py)";
      QString file_name=QFileDialog::getOpenFileName(this,"",QDir::homePath(),Filter);
    QFile file(file_name);
    if(!file.open(QFile::ReadOnly | QFile::Text)){
        QMessageBox::warning(this,"error","File not opend");
    }
    QTextStream in(&file);
    QString text=in.readAll();
    ui->plainTextEdit->setPlainText(text);
    file.close();
}


void MainWindow::on_label_time_linkActivated(const QString &link)
{
    QTime time=QTime::currentTime();
    QString time_Text=time.toString("hh:mm:ss");
    ui->label_time->setText(time_Text);


}

