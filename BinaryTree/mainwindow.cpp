#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <stack>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString str = ui->lineEdit->text();
    ui->lineEdit->clear();
    cout << str.toStdString() << endl;
    char* c;
    const char* tmp = str.toStdString().c_str();

    c = new char[str.size()+1];
    strcpy(c, tmp);
    LinkedBiTree<char>* lbt = new LinkedBiTree<char>();
    lbt->create(c);

    string preOrder = lbt->NonRecursiveTraverse(lbt->PREORDER);
    ui->label_6->setText(QString::fromStdString(preOrder));
    string inOrder = lbt->NonRecursiveTraverse(lbt->INORDER);
    ui->label_7->setText(QString::fromStdString(inOrder));
    string posOrder = lbt->NonRecursiveTraverse(lbt->POSTORDER);
    ui->label_8->setText(QString::fromStdString(posOrder));
    free(c);
    delete lbt;
}


