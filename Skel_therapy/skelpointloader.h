#ifndef SKELPOINTLOADER_H
#define SKELPOINTLOADER_H

#include <QObject>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <map>

class SkelPointLoader : public QObject {
    Q_OBJECT
public:

    SkelPointLoader(QObject *parent = nullptr);
    ~SkelPointLoader();
    static SkelPointLoader *getInstance();
    static SkelPointLoader *mInstance;

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
    void send_pos_data(double x, double y);
//public slots:
//    void updateImagePosition();
};
#endif // SKELPOINTLOADER_H
