//
// Created by Malip on 10.01.2022.
//

#ifndef GUICALCULATOR_CALLERMAINWINDOW_H
#define GUICALCULATOR_CALLERMAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QPalette>
#include <iostream>
#include "Calculator.h"


class CallerMainWindow : public  QMainWindow{
    Q_OBJECT
private:
    bool isReadOnly = true;
    void check(QChar newSymbol, QChar oldSymbol){
         if(newSymbol == oldSymbol || !oldSymbol.isDigit()){
             lineEdit->setStyleSheet("QLineEdit { background-color: red }");
         }
    }

    void showError(){
        lineEdit->setText("Error!");
        lineEdit->setStyleSheet("QLineEdit { background-color: red }");
        isReadOnly = false;
    }
public:
    CallerMainWindow(QWidget* parent = nullptr) : QMainWindow(parent){};
    QLineEdit* lineEdit = nullptr;
public slots:
    void btn0(){
        lineEdit->setText(lineEdit->text() + "0");
    };
    void btn1(){
        lineEdit->setText(lineEdit->text() + "1");
    };
    void btn2(){
        lineEdit->setText(lineEdit->text() + "2");
    };
    void btn3(){
        if(isReadOnly) lineEdit->setText(lineEdit->text() + "3");
    };
    void btn4(){
        if(isReadOnly) lineEdit->setText(lineEdit->text() + "4");
    };
    void btn5(){
        if(isReadOnly) lineEdit->setText(lineEdit->text() + "5");
    };
    void btn6(){
        if(isReadOnly) lineEdit->setText(lineEdit->text() + "6");
    };
    void btn7(){
        if(isReadOnly) lineEdit->setText(lineEdit->text() + "7");
    };
    void btn8(){
        if(isReadOnly) lineEdit->setText(lineEdit->text() + "8");
    };
    void btn9(){
        if(isReadOnly) lineEdit->setText(lineEdit->text() + "9");
    };
    void btn_div() {
        if(lineEdit->text().size() == 0) {
            showError();
        } else{
            check('/', lineEdit->text().at(lineEdit->text().size() - 1));
        }
        if(isReadOnly) lineEdit->setText(lineEdit->text() + "/");
    };
    void btn_clear() {
        lineEdit->setStyleSheet("QLineEdit { background-color: white }");
        lineEdit->setText("");
    };
    void btn_plus(){
        if(lineEdit->text().size() == 0){
           showError();
        } else{
            check( '+', lineEdit->text().at(lineEdit->text().size() - 1));
        }
        if(isReadOnly) lineEdit->setText(lineEdit->text() + "+");
    };
    void btn_minus() {
        if (lineEdit->text().size() == 0) {
            showError();
        } else {
            check('-', lineEdit->text().at(lineEdit->text().size() - 1));
        }
        if(isReadOnly) lineEdit->setText(lineEdit->text() + "-");
    };
    void btn_res(){
        if(isReadOnly && lineEdit->text().size() > 0){
            if(lineEdit->text().at(lineEdit->text().size()-1).isDigit()){
                try {
                    Calculator calculator(lineEdit->text());
                    lineEdit->setText(calculator.calculate_expression());
                }catch (std::invalid_argument except){
                    showError();
                }
            }
        }
        else lineEdit->setText("");
    };
    void btn_point(){
        if(lineEdit->text().size() == 0) {
            showError();
        }else {
            check('.', lineEdit->text().at(lineEdit->text().size() - 1));
        }
        if(isReadOnly) lineEdit->setText(lineEdit->text() + ".");
    };
    void delSymbol(){
        if(lineEdit->text().size() > 0){
            lineEdit->setText(lineEdit->text().left(lineEdit->text().size()-1));
        }
    }
    void btn_multiply() {
        if (lineEdit->text().size() == 0) {
            showError();
        } else {
            check('*', lineEdit->text().at(lineEdit->text().size() - 1));
        }
        if(isReadOnly) lineEdit->setText(lineEdit->text() + "*");
    };
};


#endif //GUICALCULATOR_CALLERMAINWINDOW_H
