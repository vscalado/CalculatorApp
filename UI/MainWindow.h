
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include "../Logic/Calculator.h"
#include "../Persistence/Database.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onAddClicked();
    void onSubtractClicked();

private:
    QLineEdit *input1;
    QLineEdit *input2;
    QLineEdit *result;
    Calculator calculator;
    Database db;
};

#endif // MAINWINDOW_H
