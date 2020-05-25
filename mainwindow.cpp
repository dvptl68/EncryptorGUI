#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "DriveSelect.hpp"
#include <map>
#include <string>

using namespace std;

//Constructor for main window
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) , ui(new Ui::MainWindow) {
    //Create main window
    ui->setupUi(this);

}

//Destructor for main window
MainWindow::~MainWindow() {
    //Delete main window
    delete ui;
}

//Function to execute when start is clicked
void MainWindow::on_startButton_clicked() {
    //Create new font for title
    QFont serifFont("OCR A Extended", 20, QFont::Bold);
    serifFont.kerning();
    //Set font and position of title
    ui->titleLabel->setFont(serifFont);
    ui->titleLabel->setGeometry(8, 0, 200, 45);
    //Delete start button
//    ui->startButton->deleteLater();
    DriveSelect d;
    QString t = "";
    t.setNum(d.getDrives().size());
    ui->startButton->setText(t);
}
