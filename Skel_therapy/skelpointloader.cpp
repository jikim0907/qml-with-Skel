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
    struct posPtStruct m_posPtStruct[13];

    while(std::getline(str_line, token, ',')){
            std::istringstream via_str(token);
            via_str >> m_posPtStruct[body_idx].y >> m_posPtStruct[body_idx].x;

            //normalization
            m_posPtStruct[body_idx].x = m_posPtStruct[body_idx].x*ori_img_w;
            m_posPtStruct[body_idx].y = m_posPtStruct[body_idx].y*ori_img_h;

            body_idx++;

            if(body_idx == sizeof(m_posPtStruct)/sizeof(*m_posPtStruct)){
                body_idx = 0;
            }
        }

    emit headPosition(m_posPtStruct[0].x, m_posPtStruct[0].y);

    emit leftShoulderPosition(m_posPtStruct[1].x, m_posPtStruct[1].y);
    emit rightShoulderPosition(m_posPtStruct[2].x, m_posPtStruct[2].y);

    emit leftElbowPosition(m_posPtStruct[3].x, m_posPtStruct[3].y);
    emit rightElbowPosition(m_posPtStruct[4].x, m_posPtStruct[4].y);

    emit leftWristPosition(m_posPtStruct[5].x, m_posPtStruct[5].y);
    emit rightWristPosition(m_posPtStruct[6].x, m_posPtStruct[6].y);

    emit leftHipPosition(m_posPtStruct[7].x, m_posPtStruct[7].y);
    emit rightHipPosition(m_posPtStruct[8].x, m_posPtStruct[8].y);

    emit leftKneePosition(m_posPtStruct[9].x, m_posPtStruct[9].y);
    emit rightKneePosition(m_posPtStruct[10].x, m_posPtStruct[10].y);

    emit leftAnklePosition(m_posPtStruct[11].x, m_posPtStruct[11].y);
    emit rightAnklePosition(m_posPtStruct[12].x, m_posPtStruct[12].y);

    return 0;
}
