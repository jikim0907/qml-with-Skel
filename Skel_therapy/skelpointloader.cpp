#include "skelpointloader.h"

SkelPointLoader* SkelPointLoader::mInstance = NULL;

SkelPointLoader::SkelPointLoader(QObject *parent):
    QObject(parent)
{
    mInstance = this;
}

SkelPointLoader::~SkelPointLoader(){
}

SkelPointLoader *SkelPointLoader::getInstance()
{
    return mInstance;
}

int SkelPointLoader::loadNSaveSkel(){
    std::ifstream file("C:/Users/User/Downloads/SkelData4.csv"); // 파일을 읽기 모드로 열기
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
//    pullSkelPt("left_shoulder");
    return 0;
}

void SkelPointLoader::pullSkelPt(std::string key){
    if (SkelPtMap.find(key) != SkelPtMap.end()) {
        std::vector<std::vector<double>>& vec = SkelPtMap[key];
        std::cout << "Contents of SkelPtMap["<< key << "] " << std::endl;
        for (const std::vector<double>& row : vec) {
            key_px = row[0];
            key_py = row[1];
            emit send_pos_data(key_px,key_py);
        }
    }

    else {
        std::cout << "Key not found: " << key << std::endl;
    }
}
