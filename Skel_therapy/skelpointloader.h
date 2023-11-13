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
//    Q_PROPERTY(QString formattedIdx READ getformattedIdx)

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
//    int i=0;
    QTimer *m_timer;
    int loadPtData(int img_width, int img_height);
    Q_INVOKABLE void mth_clicked();

    double calSlope(double x1, double y1, double x2, double y2);

//    QString formattedIdx;
//    QString getformattedIdx() const{ return formattedIdx; }

signals:
//    void changePosSig(int x, int y);
    void headPosition(int x, int y);

    void leftShoulderPosition(int x, int y,double rot);
    void rightShoulderPosition(int x, int y, double rot);

    void leftElbowPosition(int x, int y,double rot);
    void rightElbowPosition(int x, int y,double rot);

    void leftWristPosition(int x, int y,double rot);
    void rightWristPosition(int x, int y,double rot);

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
