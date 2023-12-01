#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_count_clicked()
{
    //dlugosc klatki
    float x = ui->lineEdit_x->text().toFloat();
    //glebokosc stopnia
    float sx = ui->lineEdit_sx->text().toFloat();
    //roznica wysokosci
    float z = ui->lineEdit_z->text().toFloat();

    //wysokosc stopnia
    float stz = 0;
    //ilość stopni
    float st = 0;


    // Minimalna i maksymalna wysokość stopnia (w centymetrach)
    float minStHeight = 16.0;
    float maxStHeight = 20.0;


    st = x/sx;
    stz = z/st;

    //wysokosc stopnia
    ui->lineEdit_stz->setText(QString::number(stz));
    //stopni
    ui->lineEdit_st->setText(QString::number(st));
}

void MainWindow::on_pushButton_autocount_clicked()
{
    //dlugosc klatki
    float x = ui->lineEdit_x->text().toFloat();
    //glebokosc stopnia
    float sx = ui->lineEdit_sx->text().toFloat();
    //roznica wysokosci
    float z = ui->lineEdit_z->text().toFloat();

    //wysokosc stopnia
    float stz = 0;
    //ilosc stopni
    float st = 0;

    // Minimalna i maksymalna wysokość stopnia (w centymetrach)
    float minStHeight = 16.0;
    float maxStHeight = 20.0;

    sx = sx - 0.01;
    do{
        sx = sx + 0.01;
        st = x/sx;
        st = round(st * 100.0) / 100.0;
        stz = z/st;
        stz = round(stz * 100.0) / 100.0;
        if (sx >=x ) break;
    }while (floor(st) != st);

    //wysokosc stopnia
    ui->lineEdit_stz->setText(QString::number(stz));
    //stopni
    ui->lineEdit_st->setText(QString::number(st));
    //glebokosc stopni
    sx = round(sx * 100.0) / 100.0;
    ui->lineEdit_sx->setText(QString::number(sx));

}
