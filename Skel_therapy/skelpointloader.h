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

class SkelPointLoader : public QObject {
    Q_OBJECT
    Q_PROPERTY(int key_px READ getKey_px NOTIFY key_pxChanged)
    Q_PROPERTY(int key_py READ getKey_py NOTIFY key_pyChanged)
public:
    SkelPointLoader(QObject *parent = nullptr);
    ~SkelPointLoader();
    static SkelPointLoader *getInstance();
    static SkelPointLoader *mInstance;

    std::string line;
    std::vector<double> row;
    std::map<std::string, std::vector<std::vector<double>>> SkelPtMap;
    std::vector<std::vector<double>> vec;
    std::string token;

    int ori_img_w,ori_img_h;
    double pos_y, pos_x;
    int key_idx = 0;
    int i = 0;

    int getKey_px() const {return spBodyPtRow_px;}
    int getKey_py() const {return spBodyPtRow_py;}

    QTimer *m_timer;
    int loadNSaveSkel(int ori_img_w, int ori_img_h);
    void pullSkelPt(std::string key);

    Q_INVOKABLE void mth_clicked();

private:
    int spBodyPtRow_px, spBodyPtRow_py;
signals:
    void sendPosData(double x, double y);
    void key_pxChanged();
    void key_pyChanged();
    void sigClicked();
public slots:
    void segPosChange();

};
#endif // SKELPOINTLOADER_H
