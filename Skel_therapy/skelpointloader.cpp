#include "skelpointloader.h"
#include <iostream>
#include <fstream>
#include <string>

SkelPointLoader::SkelPointLoader()
{
    loadSkel();
}

SkelPointLoader::~SkelPointLoader()
{
}

void SkelPointLoader::loadSkel(){

//    int static skelPointArr[] ={};
    std::fstream fs;
    std::string line;
    fs.open("C:/Users/User/Downloads/SkelData3.csv",std::ios::in); //파일을 읽기 전용으로 open
    if (!fs.is_open()) {
        std::cerr << "Failed to open SkelData.csv" << std::endl;
        return;
    }
    while(!fs.eof()) //파일 끝에 도달할 때 까지 반복
    {
        getline(fs,line);
        std::cout << line << std::endl;


    }


//    return skelPointArr;
}
