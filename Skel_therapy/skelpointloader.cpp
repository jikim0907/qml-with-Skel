#include "skelpointloader.h"

skelpointloader* skelpointloader::mInstance = NULL;

skelpointloader::skelpointloader(QObject *parent):
    QObject(parent)
{
    mInstance = this;
}

//skelpointloader::~skelpointloader(){
//}

skelpointloader *skelpointloader::getInstance()
{

    return mInstance;
}

int skelpointloader::loadNSaveSkel(){
//    std::cout << "method loadNSaveSkel() "<<std::endl;
    std::ifstream file("/mnt/hgfs/share/SkelData.csv"); // 파일을 읽기 모드로 열기
    if (!file.is_open()) {
        std::cerr << "Failed to open data.csv" << std::endl;
        return 1;
    }
    while (std::getline(file, line)) {
        std::istringstream str_line(line);
        row.clear();

        while(std::getline(str_line, token, ',')){
            std::istringstream via_str(token);
            via_str >> pos_y >> pos_x;
            row.push_back(pos_x); row.push_back(pos_y);
            key_idx++;
            switch(key_idx){
                case 1:
                SkelPtMap["left_shoulder"].push_back(row);
                    break;
                case 2:
                    SkelPtMap["left_elbow"].push_back(row);
                    break;
                case 3:
                    SkelPtMap["left_wrist"].push_back(row);
                    key_idx = 0;
                    break;
            }
        }
    }
    pullSkelPt("left_shoulder");
    return 0;
}

void skelpointloader::pullSkelPt(std::string key){
    if (SkelPtMap.find(key) != SkelPtMap.end()) {
        std::vector<std::vector<double>>& vec = SkelPtMap[key];
        std::cout << "Contents of SkelPtMap["<< key << "] " << std::endl;
        for (const std::vector<double>& row : vec) {
            key_px = row[0];
            key_py = row[1];
//            std::cout << "Sd" <<std::endl;
            emit sendPosData(key_px,key_py);
//            emit sendposdata();

        }

    }

    else {
        std::cout << "Key not found: " << key << std::endl;
    }
}
