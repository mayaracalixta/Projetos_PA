#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDateTime>
#include<QLineEdit>
#include<QTextBrowser>
#include<QTimer>
#include<QLabel>
#include<QLCDNumber>
 
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);
    socket = new QTcpSocket(this);
 
    connect(ui->pushButtonPut,
            SIGNAL(clicked(bool)),
            this,
            SLOT(putData()));
    connect(ui->pushButton_connect,
            SIGNAL(clicked(bool)),
            this,
            SLOT(tcpConnect()));
    connect(ui->pushButton_stop,
            SIGNAL(clicked(bool)),
            this,
            SLOT(stopData()));
    connect(ui->pushButton_disconnect,
            SIGNAL (clicked(bool)),
            this,
            SLOT(tcpDisconnect()));
}

/**
 * @brief MainWindow::tcpConnect - Estabelece a conexão com o servidor
 */
void MainWindow::tcpConnect(){ //conectar
    socket->connectToHost(getHost(),1234); //habilita o envio de dados atraves de um servidor TCP na porta 1234
    if(socket->waitForConnected(3000)){ //verifica se a conecção foi feita durante 3 segundos
        qDebug() << "Connected"; //mensagem de conectou
    }
    else{
        qDebug() << "Disconnected"; //mensagem de desconectou
    }
}

/**
 * @brief MainWindow::tcpDisconnect - finaliza a conexão com o servidor
 *
 */
void MainWindow::tcpDisconnect(){ //disconectar
    socket->disconnectFromHost();
}

/**
 * @brief MainWindow::putData - Envia os dados para o servidor usando para isso um temporizador
 */
void MainWindow::putData(){ //ao clicar em start
    QString timeStr;

    timeStr = ui->label_time->text();
    idTimer = startTimer((timeStr.toInt())*1000); //começa o temporizador de envio de dados

}

/**
 * @brief MainWindow::getHost - Captura o ID do servidor contido no campo lineEdit_Host
 * @return  - Retorna o ip que sera usado no tcpConnect()
 */
QString MainWindow::getHost(){ //pega o valor no campo linha edit, no caso o ip do servidor
    QString ip;

    ip = ui->lineEdit_Host->text();

    return ip;

}

/**
 * @brief MainWindow::stopData - "Mata" o temporizador e para o envio de dados
 */
void MainWindow::stopData(){ //ao cliclar em stop
    killTimer(idTimer); //encerra o temporizador de envio
}

/**
 * @brief MainWindow::timerEvent - Repete o putData() de acordo com a quantidade de milissegundos fornecidos pelo usuário
 */
void MainWindow::timerEvent(QTimerEvent *e){
    QString str;
    int max,min;
    qint64 msecdate;

    max = ui->lcdNumber_max->value();
    min = ui->lcdNumber_min->value();

    if(min>max){
        ui->textBrowser->insertPlainText("ERRO! VALOR MÍNIMO MAIOR QUE O MÁXIMO\n"); //caso o numero de cima for maior que o de baixo exibe um erro
        killTimer(idTimer); //encerra o temporizador de envio de dados
    }
    else{
        if(socket->state()== QAbstractSocket::ConnectedState){
            msecdate = QDateTime::currentDateTime().toMSecsSinceEpoch(); //retorna a data do pc em milisegundos a partir do dia 1 de janeiro de 1970

            str = "set "+ QString::number(msecdate) + " " + QString::number(qrand()%(max - min) + min)+"\r\n"; //envia um numero aleatorio entre o min e o max
            ui->textBrowser->append(str); //pula uma linha apos ser enviado o numero

            qDebug() << str;
            qDebug() << socket->write(str.toStdString().c_str()) << " bytes written"; //escreve oque foi enviado no console e a quantidade de bytes enviados
            if(socket->waitForBytesWritten(3000)){
                qDebug() << "wrote";
            }
        }
    }
}

MainWindow::~MainWindow(){
    delete socket;
    delete ui;
}
