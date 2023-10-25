#include "skelpointloader.h"

SkelPointLoader* SkelPointLoader::mInstance = NULL;

SkelPointLoader::SkelPointLoader(QObject *parent)
    :QObject(parent)
{
    mInstance = this;
}

//skelpointloader::~skelpointloader(){
//}

SkelPointLoader *SkelPointLoader::getInstance()
{
    return mInstance;
}

int SkelPointLoader::loadNSaveSkel(int ori_img_w,int ori_img_h){
    std::cout << "method loadNSaveSkel() "<<std::endl;
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
            row.push_back(pos_x*ori_img_w); row.push_back(pos_y*ori_img_h);
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
    pullSkelPt("left_wrist");
    return 0;
}

void SkelPointLoader::pullSkelPt(std::string key){
    std::cout << "method pullSkelPt() : "<< key <<std::endl;
    if (SkelPtMap.find(key) != SkelPtMap.end()) {
        std::vector<std::vector<double>>& vec = SkelPtMap[key];
        std::cout << "Contents of SkelPtMap["<< key << "] " << std::endl;
        for (const std::vector<double>& row : vec) {
//            std::cout << "method FOR of pullSkelPt "<<std::endl;
            m_key_px = row[0];
            m_key_py = row[1];
            emit sendPosData(m_key_px,m_key_py);
//            emit key_pxChanged();
//            emit key_pyChanged();
        }
    }
    else {
        std::cout << "Key not found: " << key << std::endl;
    }
}
