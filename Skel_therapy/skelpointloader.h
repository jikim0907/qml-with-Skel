#ifndef SKELPOINTLOADER_H
#define SKELPOINTLOADER_H

#include <QObject>

class SkelPointLoader
{
public:
    SkelPointLoader();
    ~SkelPointLoader();
    int loadNSaveSkel();
    void pullSkelPt(std::string key);
    double key_px , key_py ;
    std::map<std::string, std::vector<std::vector<double>>> SkelPtMap;

};

#endif // SKELPOINTLOADER_H
