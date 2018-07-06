#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>



namespace Ui {

class MainWindow;

}



class MainWindow : public QMainWindow

{

    Q_OBJECT



public:

    explicit MainWindow(QWidget *parent = 0);

    ~MainWindow();



private slots:

    void on_pushButton_clicked();

    void myslot();

    void lcdnumberDisplay();


private:

    Ui::MainWindow *ui;

    QTimer *timer;
    QTimer *timerrrr;

};



#endif // MAINWINDOW_H
