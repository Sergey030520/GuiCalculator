//
// Created by Malip on 11.01.2022.
//

#include "Calculator.h"

Calculator::Calculator(QString line) {
    QString number;
    for (QChar symbol : line) {
        if(symbol.isDigit() || symbol == '.'){
            number.push_back(symbol);
        }else{
            numbers.push_back(number.toFloat());
            operation.push_back(symbol);
            number.clear();
        }
    }
    numbers.push_back(number.toFloat());
}//parsing an expression

QString Calculator::calculate_expression() {
    for (int i = 0; i < operation.count(); ++i) {
        if(operation.at(i) == '*'){
            numbers[i] = numbers.at(i) * numbers.at(i+1);
            numbers[i+1] = 0;
            operation[i] = '+';
        }else if(operation.at(i) == '/'){
            if(numbers[i+1] == 0){
                throw std::invalid_argument("Сannot be divided by zero!");
            } else {
                numbers[i] = numbers.at(i) / numbers.at(i + 1);
                numbers[i + 1] = 0;
                operation[i] = '+';
            }
        }
    }//calculating complex operations
    float res = numbers.at(0);
    for (int i = 0; i < operation.count(); ++i) {
        if(operation.at(i) == '-'){
            res -= numbers.at(i+1);
        }else{
            res += numbers.at(i+1);
        }
    }//calculation of simple operations
    return QString::number(res);
}
