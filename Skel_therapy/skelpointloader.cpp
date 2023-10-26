#include "skelpointloader.h"

SkelPointLoader* SkelPointLoader::mInstance = NULL;

SkelPointLoader::SkelPointLoader(QObject *parent)
    :QObject(parent)
{
    mInstance = this;
}

SkelPointLoader::~SkelPointLoader(){
    delete this;
}

SkelPointLoader *SkelPointLoader::getInstance()
{
    return mInstance;
}

int SkelPointLoader::loadNSaveSkel(int ori_img_w,int ori_img_h){
    /*it method to load data.csv file for parsing Skeleton data.
      And create SkelPtMap with Skeleton datas those are normalized */

    std::cout << "method loadNSaveSkel() "<<std::endl;
    std::ifstream file("/mnt/hgfs/share/SkelData.csv"); // 파일을 읽기 모드로 열기
    if (!file.is_open()) {
        std::cerr << "Failed to open data.csv" << std::endl;
        return 1;
    }
    while (std::getline(file, line)) {
        std::istringstream str_line(line);
        while(std::getline(str_line, token, ',')){
            row.clear();
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
    /* specially body points(by input parameter) data what comes from "SkelPtMap" put in "vec"*/
    std::cout << "method pullSkelPt() : "<< key <<std::endl;
    if (SkelPtMap.find(key) != SkelPtMap.end()) {
        vec = SkelPtMap[key];
    }
    else {
        std::cout << "Key not found: " << key << std::endl;
    }
}

void SkelPointLoader::mth_clicked(){
    m_timer = new QTimer();
    connect(m_timer, SIGNAL(timeout()), this, SLOT(segPosChange()));
    m_timer->start(107);
}

void SkelPointLoader::segPosChange(){
    std::vector<double>& spBodyPtRow  = vec[i];
    spBodyPtRow_px = spBodyPtRow[0];
    spBodyPtRow_py = spBodyPtRow[1];
    emit sendPosData(spBodyPtRow_px,spBodyPtRow_py);
    i++;
    if(vec[i] == vec.back()){
        i = 0;
    }
}
