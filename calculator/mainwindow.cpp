/*
Name: Li Xueqi
Number: 20301110
*/
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "myStack.h"
#include "history.h"
#include <cstring>
#include <cmath>
#include <QFile>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(this->ui->history, SIGNAL(clicked()), this, SLOT(openHistory()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_num_0_clicked()
{
    ui -> display -> insert("0");
}

void MainWindow::on_num_1_clicked()
{
    ui -> display -> insert("1");
}

void MainWindow::on_num_2_clicked()
{
    ui -> display -> insert("2");
}

void MainWindow::on_num_3_clicked()
{
    ui -> display -> insert("3");
}

void MainWindow::on_num_4_clicked()
{
    ui -> display -> insert("4");
}

void MainWindow::on_num_5_clicked()
{
    ui -> display -> insert("5");
}

void MainWindow::on_num_6_clicked()
{
    ui -> display -> insert("6");
}

void MainWindow::on_num_7_clicked()
{
    ui -> display -> insert("7");
}

void MainWindow::on_num_8_clicked()
{
    ui -> display -> insert("8");
}

void MainWindow::on_num_9_clicked()
{
    ui -> display -> insert("9");
}

void MainWindow::on_plus_clicked()
{
    ui -> display -> insert("+");
}

void MainWindow::on_subtract_clicked()
{
    ui -> display -> insert("-");
}

void MainWindow::on_multiply_clicked()
{
    ui -> display -> insert("*");
}

void MainWindow::on_devide_clicked()
{
    ui -> display -> insert("/");
}

void MainWindow::on_leftParenthesis_clicked()
{
    ui -> display -> insert("(");
}

void MainWindow::on_rightParenthesis_clicked()
{
    ui -> display -> insert(")");
}

void MainWindow::on_exp_clicked()
{
    ui -> display -> insert("^");
}

void MainWindow::on_A_clicked()
{
    ui -> display -> insert("A");
}

void MainWindow::on_B_clicked()
{
    ui -> display -> insert("B");
}

void MainWindow::on_C_clicked()
{
    ui -> display -> insert("C");
}

void MainWindow::on_D_clicked()
{
    ui -> display -> insert("D");
}

void MainWindow::on_E_clicked()
{
    ui -> display -> insert("E");
}

void MainWindow::on_F_clicked()
{
    ui -> display -> insert("F");
}

void MainWindow::on_dot_clicked()
{
    ui -> display -> insert(".");
}

void MainWindow::on_clear_clicked()
{
    ui -> display -> setText("");
}

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')' || c == '#' || c == '^';
}

int optrcmp(char a, char b) {
    // 1 for a > b, -1 for a < b, 0 for a = b, 2 for illegal comparison
    int cmp[8][8] = {
            {-1, -1, -1, -1, 1, 1, 1, -1},
            {-1, -1, -1, -1, 1, 1, 1, -1},
            {1, 1, -1, -1, 1, 1, 1, -1},
            {1, 1, -1, -1, 1, 1, 1, -1},
            {-1, -1, -1, -1, -1, 0, 2, 1},
            {1, 1, 1, 1, 2, 1, 1, 1},
            {-1, -1, -1, -1, -1, 2, 0, -1},
            {1, 1, 1, 1, 1, 1, 1, -1}
    };
    int op1, op2;
    switch(a) {
        case '+': op1 = 0;break;
        case '-': op1 = 1;break;
        case '*': op1 = 2;break;
        case '/': op1 = 3;break;
        case '(': op1 = 4;break;
        case ')': op1 = 5;break;
        case '#': op1 = 6;break;
        case '^': op1 = 7;break;
        default: op1 = -1;break;
    }
    switch(b) {
        case '+': op2 = 0;break;
        case '-': op2 = 1;break;
        case '*': op2 = 2;break;
        case '/': op2 = 3;break;
        case '(': op2 = 4;break;
        case ')': op2 = 5;break;
        case '#': op2 = 6;break;
        case '^': op2 = 7;break;
        default: op2 = -1;break;
    }
    return cmp[op1][op2];
}

double calc(double a, double b, char optr) {
    switch(optr) {
        case '+': return a + b;
        case '-': return b - a;
        case '*': return a * b;
        case '/': return b / a;
        case '^': {
            double power = pow(b, a);
            return power;
        }
        default: return 0;
    }
}

// transfer decimal number to binary
int decToBin(int x, int* bin) {
    int digit = 0;
    for(int i = 0; i < 64; i++) {
        long long temp = pow(2, i) + 0.5;
        if((long long) x < temp) {
            digit = i;
            break;
        }
    }
    for(int i = digit - 1; i >= 0; i--) {
        if(x & (1 << i)) {
            bin[digit - i] = 1;
        } else {
            bin[digit - i] = 0;
        }
    }
    return digit;
}

// transfer different base numbers to decimal number
int toDec(int* num, int digit, int base) {
    int dec = 0;
    for(int i = digit; i >= 1; i--) {
        if(num[i] >= base) {
            printf("ERROR\n");
            return -1;
        }
        int temp = pow(base, digit - i) + 0.5;
        dec += temp * num[i];
    }
    return dec;
}

double reciprocal(double x) {
    return x == 0 ? -1 : 1.0 / x;
}

double getNum(char expression[], int cnt, int disp){
    int di = 0, dp = 0, s[100], k = 1;
    bool dec = false;
    for(int j = cnt + disp; ; j++) {
        fflush(stdout);
        if(expression[j] == ')') break;
        if(expression[j] == '.') {
            s[k++] = -1;
            dec = true;
            continue;
        }
        s[k++] = expression[j] - 48;
        !dec ? di++ : dp++;
        cnt = j;
    }
    cnt++;
    if(dp != 0) {
        double num = 0;
        for(int i = k - 1, j = dp; i > k - 1 - dp; i--, j--) {
            double t = 1;
            for(int k = 1; k <= j; k++) t *= 0.1;
            num += s[i] * t;
        }
        for(int i = k - 1 - dp - 1, j = 1; i >= 1; i--, j++) {
            int t = 1;
            for(int k = 2; k <= j; k++) t *= 10;
            num += (double) s[i] * t;
        }
        return num;
    } else {
        int num = 0;
        for(int i = k - 1, j = 1; i >= 1; i--, j++) {
            int t = 1;
            for(int k = 2; k <= j; k++) t *= 10;
            num += s[i] * t;
        }
        return num;
    }
}

QString getExpression(char expression[]) {
    myStack<double> operandStack;
    myStack<char> operatorStack;
    operatorStack.push('#');
    int length = strlen(expression);
    expression[length] = '#';
    length++;

    int digitInt = 0, digitPnt = 0, temp[100], m = 1;
    bool decimal = false;
    for(int cnt = 0; cnt < length; cnt++) {
        if(expression[cnt] == 's' && expression[cnt + 1] == 'i') {
            double num = getNum(expression, cnt, 4);
            for(int j = cnt + 4; ; j++) {
                if(expression[j] == ')') break;
                cnt = j;
            }
            cnt++;
            num = sin(num);
            operandStack.push(num);
            continue;
        } else if(expression[cnt] == 'c') {
            double num = getNum(expression, cnt, 4);
            for(int j = cnt + 4; ; j++) {
                if(expression[j] == ')') break;
                cnt = j;
            }
            cnt++;
            num = cos(num);
            operandStack.push(num);
            continue;
        } else if(expression[cnt] == 's' && expression[cnt + 1] == 'q') {
            double num = getNum(expression, cnt, 5);
            for(int j = cnt + 5; ; j++) {
                if(expression[j] == ')') break;
                cnt = j;
            }
            cnt++;
            if(num < 0) {
                break;
            }
            num = sqrt(num);
            operandStack.push(num);
            continue;
        }
        // duplicate decimal point
        if(decimal && expression[cnt] == '.') {
            continue;
        }
        if(expression[cnt] >= '0' && expression[cnt] <= '9') {
            temp[m++] = expression[cnt] - 48;
            !decimal ? digitInt++ : digitPnt++;
            continue;
        } else if(expression[cnt] == '.') {
            temp[m++] = -1; // -1 for point
            decimal = true;
            continue;
        } else {
            // has decimal part
            if(digitPnt != 0) {
                double num = 0;
                for(int i = m - 1, j = digitPnt; i > m - 1 - digitPnt; i--, j--) {
                    double t = 1;
                    for(int k = 1; k <= j; k++) t *= 0.1;
                    num += temp[i] * t;
                }
                for(int i = m - 1 - digitPnt - 1, j = 1; i >= 1; i--, j++) {
                    int t = 1;
                    for(int k = 2; k <= j; k++) t *= 10;
                    num += (double) temp[i] * t;
                }
                operandStack.push(num);
            } else if(digitInt != 0){
                int num = 0;
                for(int i = m - 1, j = 1; i >= 1; i--, j++) {
                    int t = 1;
                    for(int k = 2; k <= j; k++) t *= 10;
                    num += temp[i] * t;
                }
                operandStack.push((double) num);
            }
            decimal = false;
            digitPnt = 0;
            digitInt = 0;
            m = 1;

            if(expression[cnt] == '(') {
                if(expression[cnt - 1] == ')') {
                    operatorStack.push('*');
                } else if(expression[cnt + 1] == '-') {
                    operandStack.push(0);
                }
                operatorStack.push('(');
                continue;
            } else if(expression[cnt] == ')') {
                char optr = operatorStack.top();
                if(optr == '(') {
                    break;
                }
                operatorStack.pop();

                while(optr != '(') {
                    if(operandStack.isEmpty()) {
                        break;
                    }
                    double a = operandStack.top();
                    operandStack.pop();
                    double b = operandStack.top();
                    operandStack.pop();
                    operandStack.push(calc(a, b, optr));
                    optr = operatorStack.top();
                    if(optr == '#') {
                        operatorStack.push('#');
                        break;
                    }
                    operatorStack.pop();
                }
                continue;
            }

            if((expression[cnt - 1] < '0' || expression[cnt - 1] > '9')
                    && expression[cnt - 1] != ')' && expression[cnt - 1] != '(') {
                operatorStack.pop();
            }
            int cmp = optrcmp(expression[cnt], operatorStack.top());
            // 1 for a > b, -1 for a < b, 0 for a = b, 2 for illegal comparison
            if(cmp == 1) {
                operatorStack.push(expression[cnt]);
            } else if(cmp == -1) {
                if(operatorStack.top() == '(') {
                    operatorStack.push(expression[cnt]);
                    continue;
                }
                while(cmp == -1) {
                    if(operandStack.isEmpty()) {
                        operatorStack.push('#');
                        break;
                    }
                    double a = operandStack.top();
                    operandStack.pop();
                    double b = operandStack.top();
                    operandStack.pop();
                    char optr = operatorStack.top();
                    if(optr == '(' || optr == ')') {
                        break;
                    }
                    operatorStack.pop();
                    if(a == 0 && optr == '/') {
                        break;
                    }
                    operandStack.push(calc(a, b, optr));
                    cmp = optrcmp(expression[cnt], operatorStack.top());
                }
                operatorStack.push(expression[cnt]);
                if(expression[cnt] == '#') {
                    operatorStack.pop();
                    operatorStack.pop();
                }
            } else if(cmp == 0) {
                if(operandStack.size() != 1) {
                    QString str = "ERROR\n";
                    return str;
                    break;
                }
                operatorStack.pop();
            } else {
                QString str = "ERROR\n";
                return str;
                break;
            }
        }
    }
    if(operandStack.size() != 1 || !operatorStack.isEmpty()) {
        QString str = "Error\n";
        return str;
    } else {
        int integer = (int) operandStack.top();
        if(abs(integer - operandStack.top()) <= 0.0000001) {
            QString str = QString::number(integer, 10);
            return str;
        } else {
            QString str = QString::number(operandStack.top(), 'f', 6);
            return str;
        }
    }
}

void record(QString history, int symbol) {
    QFile file("C://Users//lenovo//Desktop//AlgoandDSPractice//calculator//history.txt");
    if(!file.open(QIODevice::WriteOnly | QIODevice::Append)) {
        qDebug() << file.errorString();
    }
    QTextStream output(&file);
    output << history;
    if(symbol == 1) {
        output << "\n";
    }
    file.close();
}

void MainWindow::on_equal_clicked()
{
    QString str = ui -> display -> text();
    QByteArray s = str.toLatin1();
    char* expression = s.data();

    record(expression, 0);

    ui -> display -> setText("");
    QString answer = getExpression(expression);
    ui -> display -> setText(answer);
    QString temp = "=";
    record(temp + answer, 1);
}

void MainWindow::on_delete_2_clicked()
{
    QString str = ui -> display -> text();
    ui -> display -> setText("");
    int length = str.size();
    for(int i = 0; i < length - 1; i++) {
        ui -> display -> insert(str[i]);
    }
}

void MainWindow::on_rcp_clicked()
{
    ui -> display -> insert("(1/");
}

void MainWindow::on_sqrt_clicked()
{
    ui -> display -> insert("sqrt(");
}

void MainWindow::on_sin_clicked()
{
    ui -> display -> insert("sin");
}

void MainWindow::on_cos_clicked()
{
    ui -> display -> insert("cos");
}

void MainWindow::on_bin_clicked()
{
    QString str = ui -> display -> text();
    record("BIN"+str, 0);
    int bin[100], x = str.toInt();
    int digit = 0;
    for(int i = 0; i < 64; i++) {
        long long temp = pow(2, i) + 0.5;
        if((long long) x < temp) {
            digit = i;
            break;
        }
    }
    for(int i = digit - 1; i >= 0; i--) {
        if(x & (1 << i)) {
            bin[digit - i] = 1;
        } else {
            bin[digit - i] = 0;
        }
    }
    ui -> display ->setText("");
    record("=", 0);
    for(int i = 1; i <= digit; i++) {
        ui -> display -> insert(QString::number(bin[i]));
        record(QString::number(bin[i]), 0);
    }
    record("", 1);
}

void MainWindow::on_oct_clicked()
{
    QString str = ui -> display -> text();
    record("OCT" + str, 0);
    int x = str.toInt();
    int bin[64], digit, oct[64], m = 1;
    memset(oct, 0, sizeof(oct));
    digit = decToBin(x, bin);
    for(int i = digit, cnt = 0; i >= 1; i--) {
        int temp = pow(2, cnt++) + 0.5;
        oct[m] += temp * bin[i];
        if(cnt == 3) {
            cnt = 0;
            m++;
        }
    }
    digit % 3 == 0 ? m-- : m;
    ui -> display -> setText("");
    record("=", 0);
    for(int i = m; i >= 1; i--) {
        ui -> display -> insert(QString::number(oct[i]));
        record(QString::number(oct[i]), 0);
    }
    record("", 1);
}

void MainWindow::on_hex_clicked()
{
    QString str = ui -> display -> text();
    record(str, 0);
    int x = str.toInt();
    int bin[64], digit, hex[64], m = 1;
    memset(hex, 0, sizeof(hex));
    digit = decToBin(x, bin);
    for(int i = digit, cnt = 0; i >= 1; i--) {
        int temp = pow(2, cnt++) + 0.5;
        hex[m] += temp * bin[i];
        if(cnt == 4) {
            cnt = 0;
            m++;
        }
    }
    digit % 4 == 0 ? m-- : m;
    ui -> display -> setText("");
    record("=", 0);
    for(int i = m; i >= 1; i--) {
        if(hex[i] < 10) {
            ui -> display -> insert(QString::number(hex[i]));
            record(QString::number(hex[i]), 0);
        }
        else {
            switch(hex[i]) {
                case 10: ui -> display -> insert("A"); record("A", 0); break;
                case 11: ui -> display -> insert("B"); record("B", 0); break;
                case 12: ui -> display -> insert("C"); record("C", 0); break;
                case 13: ui -> display -> insert("D"); record("D", 0); break;
                case 14: ui -> display -> insert("E"); record("E", 0); break;
                case 15: ui -> display -> insert("F"); record("F", 0); break;
            }
        }
    }
    record("", 1);
}

void MainWindow::on_dec_clicked()
{
    QString str = ui -> display -> text();
    int length = str.length();
    str[length - 1] = str[length - 1].toLower();
    int num[100];
    for(int i = 0; i < length - 1; i++) {
        if(str[i] >= 'A' && str[i] <= 'F') {
            num[i + 1] = str[i].toLatin1() - 'A' + 10;
        } else {
            num[i + 1] = str[i].toLatin1() - '0';
        }
    }
    ui -> display -> setText("");
    int x;
    if(str[length - 1] == 'b') {
        x = toDec(num, length - 1, 2);
    } else if(str[length - 1] == 'o') {
        x = toDec(num, length - 1, 8);
    } else if(str[length - 1] == 'h') {
        x = toDec(num, length - 1, 16);
    } else {
        ui -> display -> insert("ERROR");
        return ;
    }
    x == -1 ? ui -> display -> insert("ERROR") : ui -> display -> insert(QString::number(x));
}

void MainWindow::openHistory() {
    History* his = new History();
    his -> show();
}

// 6*(2+3)/5+7
// 11.2+3*(5.1-0.5)
// 1.5.5
// 1++2
// 1/0
// 1+(-2)(2+3)
