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

int SkelPointLoader::loadPtData(int img_width,int img_height){
    /*it method to load data.csv file for parsing Skeleton data.
      And create SkelPtMap with Skeleton datas those are normalized */
    ori_img_w = img_width; ori_img_h = img_height;
    std::cout << "method loadNSaveSkel() "<<std::endl;
    posCsvData.open("/mnt/hgfs/share/SkelData.csv");

    if (!posCsvData.is_open()) {
        std::cerr << "Failed to open data.csv" << std::endl;
        return 1;
    }
    return 0;
}

void SkelPointLoader::mth_clicked(){
    m_timer = new QTimer();
    connect(m_timer, SIGNAL(timeout()), this, SLOT(loadPositionbyTimer()));
    m_timer->start(107);
}

int SkelPointLoader::loadPositionbyTimer(){
    /*a frame data parsing and position point data streame to qml per a seccond */
    std::getline(posCsvData, line);
    std::istringstream str_line(line);
    posPtStruct m_posPtStruct[3];

    while(std::getline(str_line, token, ',')){
            std::istringstream via_str(token);
            key_idx++;
            via_str >> m_posPtStruct[key_idx].y >> m_posPtStruct[key_idx].x;

            switch(key_idx){
                case 1:
                    m_posPtStruct[0].x = m_posPtStruct[0].x*ori_img_w;
                    m_posPtStruct[0].y = m_posPtStruct[0].y*ori_img_h;
                    break;
                case 2:
                    m_posPtStruct[1].x = m_posPtStruct[1].x*ori_img_w;
                    m_posPtStruct[1].y = m_posPtStruct[1].y*ori_img_h;
                    break;
                case 3:
                    m_posPtStruct[2].x = m_posPtStruct[2].x*ori_img_w;
                    m_posPtStruct[2].y = m_posPtStruct[2].y*ori_img_h;
                    key_idx = 0;
                    break;
            }
        }
        emit changePosSig(m_posPtStruct);
    return 0;
}
