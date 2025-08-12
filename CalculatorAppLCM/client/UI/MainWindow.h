#pragma once

#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QTextEdit>
#include <QTabWidget>

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onAddClicked();
    void onSubClicked();
    void onResultReceived(double value, const QString& status);

private:
    QLineEdit *inputA;
    QLineEdit *inputB;
    QPushButton *addButton;
    QPushButton *subButton;
    QTextEdit *resultDisplay;
    QTextEdit *monitorDisplay;
    QTabWidget *tabs;

    void setupUI();
    void logMessage(const QString& msg);
};