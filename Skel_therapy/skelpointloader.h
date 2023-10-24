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

class SkelPointLoader : public QObject {
    Q_OBJECT


public:
    SkelPointLoader(QObject *parent = 0);
//    ~skelpointloader();
    static SkelPointLoader *getInstance();
    static SkelPointLoader *mInstance;

    int loadNSaveSkel();

    int key_idx = 0;

    std::string line;
    std::vector<double> row;
    std::string token;

    double pos_y, pos_x;
    double key_px , key_py ;
    std::map<std::string, std::vector<std::vector<double>>> SkelPtMap;

signals:
    void sendPosData(double x, double y);
public slots:
    void pullSkelPt(std::string key);
//    void sendposdata();
//public slots:
//    void updateImagePosition();
};
#endif // SKELPOINTLOADER_H
