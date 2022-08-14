#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <secondwindow.h>
#include <QMainWindow>
#include <loginwindow.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();



    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_label_Pic_linkActivated(const QString &link);

    void on_actionNew_triggered();

    void on_actionAdd_triggered();

    void on_actionQuit_triggered();

    void on_pushButton_write_clicked();

    void on_pushButton_read_clicked();

    void on_label_time_linkActivated(const QString &link);

private:
    Ui::MainWindow *ui;
    QDialog *secdialog;
    QDialog *login;
};
#endif // MAINWINDOW_H
