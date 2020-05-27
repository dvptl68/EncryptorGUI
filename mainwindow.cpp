#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "DriveSelect.hpp"
#include <vector>
#include <string>
#include <QListWidget>
#include <QPushButton>
#include <QLabel>

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

  //Change size of rows 2 and 3 to fit list
  ui->pageLayout->setRowStretch(1, 50);
  ui->pageLayout->setRowStretch(2, 200);

  //Create new font for title and place in top left
  QFont serifFont("OCR A Extended", 20, QFont::Bold);
  serifFont.kerning();
  QLabel *title = new QLabel(ui->cont1);
  //Set font and new position of title
  title->setFont(serifFont);
  title->setText("Encryptor");
  title->resize(200, 30);
  title->show();

  //Delete old title and start button
  ui->titleLabel->deleteLater();
  ui->startButton->deleteLater();

  //Get list of available drives
  DriveSelect d;
  vector<string> drives = d.getDrives();

  //Create and show list widget in center of screen
  QListWidget *dr = new QListWidget(ui->cont8);
  dr->setGeometry(144, 0, 300, 200);
  dr->show();
  for (int i = 0; i < (int)drives.size(); i++){
    dr->addItem(QString::fromStdString(drives[i].substr(0, 3) + " -> " + drives[i].substr(3)));
  }

  //Create and show next push button
  QPushButton *next = new QPushButton(ui->cont12);
  next->setGeometry(85, 105, 100, 40);
  QFont font1("Seqoe MDL2 Assets", 20);
  font1.kerning();
  next->setFont(font1);
  next->setText("Next");

  //Create and show instruction label
  QLabel *instruct = new QLabel(ui->cont5);
  QFont font2("Seqoe MDL2 Assets", 25);
  instruct->setFont(font2);
  instruct->setText("Select a drive:");
  instruct->move(185, 30);
  instruct->show();

  QObject::connect(dr, &QListWidget::itemSelectionChanged, next, &QPushButton::show);
}
