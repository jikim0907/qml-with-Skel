#ifndef SKELPOINTLOADER_H
#define SKELPOINTLOADER_H

#include <QObject>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <QThread>
#include <QQuickItem>
#include <QQuickPaintedItem>
#include <QPainter>
#include <QTimer>

class SkelPointLoader : public QObject {
    Q_OBJECT
    Q_PROPERTY(int key_px READ getKey_px NOTIFY key_pxChanged)
    Q_PROPERTY(int key_py READ getKey_py NOTIFY key_pyChanged)
public:
    SkelPointLoader(QObject *parent = nullptr);
//    ~skelpointloader();
    static SkelPointLoader *getInstance();
    static SkelPointLoader *mInstance;

    int loadNSaveSkel(int ori_img_w, int ori_img_h);
    int key_idx = 0;

    std::string line;
    std::vector<double> row;
    std::string token;
    int ori_img_w,ori_img_h;
    double pos_y, pos_x;
    int getKey_px() const {return m_key_px;}
    int getKey_py() const {return m_key_py;}

    std::map<std::string, std::vector<std::vector<double>>> SkelPtMap;
    void emitSignals();
private:
    int m_key_px, m_key_py;
signals:
    void sendPosData(double x, double y);
    void key_pxChanged();
    void key_pyChanged();
public slots:
    void pullSkelPt(std::string key);

};
#endif // SKELPOINTLOADER_H
