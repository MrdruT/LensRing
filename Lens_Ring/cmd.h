#ifndef CMD_H
#define CMD_H


#include <QDialog>
#include <QSettings>
#include <QList>
#include <QDebug>
#include <QFileDialog>
#include <QMessageBox>
#include <QMouseEvent>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <string>
#include <stdio.h>
#include <iostream>

#include "HalconCpp.h"
#include "Dmc1000.h"
#include "ic_capture.h"

using namespace std;
using namespace HalconCpp;
namespace Ui {
class CMD;
}

class CMD : public QDialog
{
    Q_OBJECT

public:
    explicit CMD(QWidget *parent = 0);
    ~CMD();

    //Halcon variable
    HObject ho_Image1,ho_Image2;
    HObject ho_Region,standard_image;
    HTuple hv_WindowHandle, hv_WindowHandle1, hv_WindowHandle2;
    HTuple hv_ModelID;

    QSettings *configFile;
    IC_Capture *cap;
    QSerialPort *light;

    char send_data[4];
    int bright_value=0;

    bool first_open1=true;
    bool first_open2=true;

    long StrVel=0;
    long MaxVel=0;
    double Tacc=0;

    int mouse_x;
    int mouse_y;

    void disp_parameters();
    void lock_tool_buttons(bool);
    void create_model(int);
    QString select_path();

protected:
    void mouseMoveEvent(QMouseEvent *event);
//    void mousePressEvent(QMouseEvent *event);

signals:
//    void signal_cap_image1();
//    void signal_cap_image2();

public slots:
    void slot_disp_image1(HObject);
    void slot_disp_image2(HObject);

private slots:

    void on_HIGH_SPEED_SET_editingFinished();

    void on_LOW_SPEED_SET_editingFinished();

    void on_High_Speed_Initial_editingFinished();

    void on_High_Speed_Acceleration_editingFinished();

    void on_Low_Speed_Initial_editingFinished();

    void on_Low_Speed_Acceleration_editingFinished();

    void on_HIGH_SPEED_clicked();

    void on_LOW_SPEED_clicked();

    void on_Create_Model1_clicked();

    void on_Create_Model2_clicked();

    void on_cap_image1_clicked();

    void on_cap_image2_clicked();

    void on_circle_tool_clicked();

    void on_ellipse_tool_clicked();

    void on_rectangle1_tool_clicked();

    void on_rectangle2_tool_clicked();

    void on_free_tool_clicked();

    void on_brightness_editingFinished();

    void on_Brightness_add_clicked();

    void on_Brightness_decrease_clicked();

    void on_Camera1_up_pressed();

    void on_Camera1_down_released();

    void on_Camera2_up_2_pressed();

    void on_Camera2_down_2_released();

    void on_Camera2_up_2_released();

    void on_Camera2_down_2_pressed();

    void on_Camera1_up_released();

    void on_Camera1_down_pressed();

    void on_Anticlockwise_pressed();

    void on_Anticlockwise_released();

    void on_Clockwise_pressed();

    void on_Clockwise_released();

private:
    Ui::CMD *ui;
};
#endif // CMD_H
