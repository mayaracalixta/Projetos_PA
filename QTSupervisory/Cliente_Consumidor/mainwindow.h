#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QDebug>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();
  
public slots:

  void tcpConnect(void);

  void tcpDisconnect(void);

  void getData(void);

  void stopData(void);
  /** @brief Atualiza lista de clientes produtores conectados
  **/
  void updateIp(void);
  /** @brief Time event
   * @details função que faz o getData(void) ser chamado no tempo determinado pelo usuário
  **/
  void timerEvent(QTimerEvent *e);

private:
  Ui::MainWindow *ui;
  QTcpSocket *socket;
  int idTimer;
};

#endif // MAINWINDOW_H
