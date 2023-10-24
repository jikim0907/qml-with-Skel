#ifndef SKELPOINTLOADER_H
#define SKELPOINTLOADER_H

#include <QObject>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <map>

class skelpointloader : public QObject {
    Q_OBJECT


public:
    skelpointloader(QObject *parent = 0);
//    ~skelpointloader();
    static skelpointloader *getInstance();
    static skelpointloader *mInstance;

    int loadNSaveSkel();

    int key_idx = 0;
    void pullSkelPt(std::string key);
    std::string line;
    std::vector<double> row;
    std::string token;

    double pos_y, pos_x;
    double key_px , key_py ;
    std::map<std::string, std::vector<std::vector<double>>> SkelPtMap;
signals:
    void sendPosData(double key_x, double key_y);
//    void sendposdata();
//public slots:
//    void updateImagePosition();
};
#endif // SKELPOINTLOADER_H
