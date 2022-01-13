//
// Created by Malip on 11.01.2022.
//

#ifndef GUICALCULATOR_CALCULATOR_H
#define GUICALCULATOR_CALCULATOR_H


#include <QChar>
#include <QVector>
#include <QString>


class Calculator {
private:
    QVector<float> numbers;
    QVector<QChar> operation;
public:
    explicit Calculator(QString line);
    QString calculate_expression();
};


#endif //GUICALCULATOR_CALCULATOR_H
