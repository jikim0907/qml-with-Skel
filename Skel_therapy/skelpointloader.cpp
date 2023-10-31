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
    /*this method is for loading csv file to parsing Skeleton data.*/

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
    m_timer->start(70);
}

double SkelPointLoader::calSlope(double x1, double y1, double x2, double y2) {
    if (x1 == x2) { return 0.0; }
    return (y2 - y1) / (x2 - x1);
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
    double upperArmSlope_R = calSlope(m_posPtStruct[2].x,m_posPtStruct[2].y,m_posPtStruct[4].x,m_posPtStruct[4].y)*(-1);
    double foreArmSlope_R = calSlope(m_posPtStruct[4].x,m_posPtStruct[4].y,m_posPtStruct[6].x,m_posPtStruct[6].y)*(-1);

    double upperArmSlope_L = calSlope(m_posPtStruct[1].x,m_posPtStruct[1].y,m_posPtStruct[3].x,m_posPtStruct[3].y)*(-1);
    double foreArmSlope_L = calSlope(m_posPtStruct[3].x,m_posPtStruct[3].y,m_posPtStruct[5].x,m_posPtStruct[5].y)*(-1);

    emit headPosition(m_posPtStruct[0].x, m_posPtStruct[0].y);
    emit leftShoulderPosition(m_posPtStruct[1].x, m_posPtStruct[1].y,upperArmSlope_L);
    emit rightShoulderPosition(m_posPtStruct[2].x, m_posPtStruct[2].y,upperArmSlope_R);
    emit leftElbowPosition(m_posPtStruct[3].x, m_posPtStruct[3].y,upperArmSlope_L);
    emit rightElbowPosition(m_posPtStruct[4].x, m_posPtStruct[4].y,upperArmSlope_R);
    emit leftWristPosition(m_posPtStruct[5].x, m_posPtStruct[5].y,foreArmSlope_L);
    emit rightWristPosition(m_posPtStruct[6].x, m_posPtStruct[6].y,foreArmSlope_R);
    emit leftHipPosition(m_posPtStruct[7].x, m_posPtStruct[7].y);
    emit rightHipPosition(m_posPtStruct[8].x, m_posPtStruct[8].y);
    emit leftKneePosition(m_posPtStruct[9].x, m_posPtStruct[9].y);
    emit rightKneePosition(m_posPtStruct[10].x, m_posPtStruct[10].y);
    emit leftAnklePosition(m_posPtStruct[11].x, m_posPtStruct[11].y);
    emit rightAnklePosition(m_posPtStruct[12].x, m_posPtStruct[12].y);

    return 0;
}
