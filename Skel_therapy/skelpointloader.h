#ifndef SKELPOINTLOADER_H
#define SKELPOINTLOADER_H

#include <QObject>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <QTimer>
#include <QDebug>


struct posPtStruct{
    double x;
    double y;
};

class SkelPointLoader : public QObject {
    Q_OBJECT
//    Q_PROPERTY(int key_px READ getKey_px NOTIFY key_pxChanged)
//    Q_PROPERTY(int key_py READ getKey_py NOTIFY key_pyChanged)
public:
    SkelPointLoader(QObject *parent = nullptr);
    ~SkelPointLoader();
    static SkelPointLoader *getInstance();
    static SkelPointLoader *mInstance;

    std::string line;
    std::vector<double> row;
    std::ifstream posCsvData; //it'll may delete later... if position data streams come in real time
    std::string token;

    int ori_img_w,ori_img_h;
    int body_idx = 0;
    QTimer *m_timer;
    int loadPtData(int img_width, int img_height);
    Q_INVOKABLE void mth_clicked();
signals:
//    void changePosSig(int x, int y);
    void headPosition(int x, int y);

    void leftShoulderPosition(int x, int y);
    void rightShoulderPosition(int x, int y);

    void leftElbowPosition(int x, int y);
    void rightElbowPosition(int x, int y);

    void leftWristPosition(int x, int y);
    void rightWristPosition(int x, int y);

    void leftHipPosition(int x, int y);
    void rightHipPosition(int x, int y);

    void leftKneePosition(int x, int y);
    void rightKneePosition(int x, int y);

    void leftAnklePosition(int x, int y);
    void rightAnklePosition(int x, int y);

public slots:
    int loadPositionbyTimer();

};
#endif // SKELPOINTLOADER_H
