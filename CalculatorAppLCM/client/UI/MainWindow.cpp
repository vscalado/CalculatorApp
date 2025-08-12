#include "MainWindow.h"
#include "../LCM/client.hpp"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QString>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setupUI();

    resultCallback = [this](const messages::Result& msg) {
        QMetaObject::invokeMethod(this, [this, msg] {
            onResultReceived(msg.value, QString::fromStdString(msg.status));
            logMessage("Received result: " + QString::number(msg.value) + " (" + QString::fromStdString(msg.status) + ")");
        }, Qt::QueuedConnection);
    };
}

MainWindow::~MainWindow() {}

void MainWindow::setupUI()
{
    QWidget *central = new QWidget(this);
    QVBoxLayout *mainLayout = new QVBoxLayout;

    inputA = new QLineEdit;
    inputB = new QLineEdit;
    addButton = new QPushButton("Somar");
    subButton = new QPushButton("Subtrair");
    resultDisplay = new QTextEdit;
    resultDisplay->setReadOnly(true);
    monitorDisplay = new QTextEdit;
    monitorDisplay->setReadOnly(true);

    QHBoxLayout *inputLayout = new QHBoxLayout;
    inputLayout->addWidget(inputA);
    inputLayout->addWidget(inputB);

    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(addButton);
    buttonLayout->addWidget(subButton);

    QWidget *calcTab = new QWidget;
    QVBoxLayout *calcLayout = new QVBoxLayout;
    calcLayout->addLayout(inputLayout);
    calcLayout->addLayout(buttonLayout);
    calcLayout->addWidget(resultDisplay);
    calcTab->setLayout(calcLayout);

    QWidget *monitorTab = new QWidget;
    QVBoxLayout *monitorLayout = new QVBoxLayout;
    monitorLayout->addWidget(monitorDisplay);
    monitorTab->setLayout(monitorLayout);

    tabs = new QTabWidget;
    tabs->addTab(calcTab, "Calculadora");
    tabs->addTab(monitorTab, "Monitoramento");

    mainLayout->addWidget(tabs);
    central->setLayout(mainLayout);
    setCentralWidget(central);

    connect(addButton, &QPushButton::clicked, this, &MainWindow::onAddClicked);
    connect(subButton, &QPushButton::clicked, this, &MainWindow::onSubClicked);
}

void MainWindow::onAddClicked()
{
    double a = inputA->text().toDouble();
    double b = inputB->text().toDouble();
    sendOperation("add", a, b);
    logMessage("Sent add: " + QString::number(a) + ", " + QString::number(b));
}

void MainWindow::onSubClicked()
{
    double a = inputA->text().toDouble();
    double b = inputB->text().toDouble();
    sendOperation("sub", a, b);
    logMessage("Sent sub: " + QString::number(a) + ", " + QString::number(b));
}

void MainWindow::onResultReceived(double value, const QString &status)
{
    resultDisplay->setText("Resultado: " + QString::number(value) + " (" + status + ")");
}

void MainWindow::logMessage(const QString &msg)
{
    monitorDisplay->append(msg);
}