#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "DriveSelect.hpp"
#include <vector>
#include <string>
#include <QListWidget>
#include <QPushButton>

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
    //Set font and new position of title
    ui->titleLabel->setFont(serifFont);
    ui->titleLabel->setGeometry(8, 0, 200, 45);
    //Delete start button
    ui->startButton->deleteLater();
    //Get list of available drives
    DriveSelect d;
    vector<string> drives = d.getDrives();
    //Create and show list widget in center of screen
    QListWidget *dr = new QListWidget(ui->centralwidget);
    dr->setGeometry(350, 200, 300, 300);
    dr->show();
    //Create and show next push button
    QPushButton *next = new QPushButton(ui->centralwidget);
    next->setGeometry(886, 651, 104, 39);
    QFont font("Seqoe MDL2 Assets", 20);
    font.kerning();
    next->setFont(font);
    next->setText("Next");
    next->show();
}
