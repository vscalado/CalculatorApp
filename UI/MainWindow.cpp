
#include "MainWindow.h"
#include <QWidget>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), input1(new QLineEdit), input2(new QLineEdit), result(new QLineEdit) {
    QWidget *central = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout;

    QPushButton *addButton = new QPushButton("Somar");
    QPushButton *subButton = new QPushButton("Subtrair");

    layout->addWidget(new QLabel("Valor 1:"));
    layout->addWidget(input1);
    layout->addWidget(new QLabel("Valor 2:"));
    layout->addWidget(input2);
    layout->addWidget(addButton);
    layout->addWidget(subButton);
    layout->addWidget(new QLabel("Resultado:"));
    layout->addWidget(result);

    connect(addButton, &QPushButton::clicked, this, &MainWindow::onAddClicked);
    connect(subButton, &QPushButton::clicked, this, &MainWindow::onSubtractClicked);

    central->setLayout(layout);
    setCentralWidget(central);
    setWindowTitle("Calculadora Simples");
}

MainWindow::~MainWindow() {
    db.saveToFile("operations.yaml");
}

void MainWindow::onAddClicked() {
    double a = input1->text().toDouble();
    double b = input2->text().toDouble();
    double r = calculator.add(a, b);
    result->setText(QString::number(r));
    db.addOperation("soma", a, b, r);
}

void MainWindow::onSubtractClicked() {
    double a = input1->text().toDouble();
    double b = input2->text().toDouble();
    double r = calculator.subtract(a, b);
    result->setText(QString::number(r));
    db.addOperation("subtracao", a, b, r);
}
