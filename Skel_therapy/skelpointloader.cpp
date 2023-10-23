#include "skelpointloader.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <map>

SkelPointLoader::SkelPointLoader()
{
    loadNSaveSkel();
}

SkelPointLoader::~SkelPointLoader()
{
}

int SkelPointLoader::loadNSaveSkel(){

    std::ifstream file("C:/Users/User/Downloads/SkelData4.csv"); // 파일을 읽기 모드로 열기

    if (!file.is_open()) {
        std::cerr << "Failed to open data.csv" << std::endl;
        return 1;
    }

    std::string line;
    std::vector<double> row;

    while (std::getline(file, line)) {
        std::cout<<"line: "<<line<<std::endl;
        std::istringstream str_line(line);
        std::string token;
        int i = 0;

        row.clear();

        while(std::getline(str_line, token, ',')){
            std::istringstream via_str(token);
            double pos_y, pos_x;
            via_str >> pos_y >> pos_x;
            row.push_back(pos_x);
            row.push_back(pos_y);

            i++;
            switch(i){
                case 1:
                SkelPtMap["left_shoulder"].push_back(row);
                    break;
                case 2:
                    SkelPtMap["left_elbow"].push_back(row);
                    break;
                case 3:
                    SkelPtMap["left_wrist"].push_back(row);
                    i = 0;
                    break;
            }
        }
    }
//    pullSkelPt("left_shoulder");
}

void SkelPointLoader::pullSkelPt(std::string key){

    if (SkelPtMap.find(key) != SkelPtMap.end()) {
        std::vector<std::vector<double>>& vec = SkelPtMap[key];
        std::cout << "Contents of SkelPtMap["<< key << "] " << std::endl;

        for (const std::vector<double>& row : vec) {
            key_px = row[0];
            key_py = row[1];
        }

    } else {
        std::cout << "Key not found: " << key << std::endl;
    }
}
