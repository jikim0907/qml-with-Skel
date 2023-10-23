#ifndef SKELPOINTLOADER_H
#define SKELPOINTLOADER_H

#include <QObject>

class SkelPointLoader
{
public:
    SkelPointLoader();
    ~SkelPointLoader();
    int loadNSaveSkel();

    int key_idx = 0;
    void pullSkelPt(std::string key);
    std::string line;
    std::vector<double> row;
    std::string token;

    double pos_y, pos_x;
    double key_px , key_py ;
    std::map<std::string, std::vector<std::vector<double>>> SkelPtMap;

};

#endif // SKELPOINTLOADER_H
