#include "SerialDelegate.h"
#include <sstream>
#include <iostream>
SerialDelegate::SerialDelegate(const string &filePath, StartStopper *startStopper, CurrentRecord *currentRecord, WarningSignaller *signaller) : filePath(filePath),
    startStopper(startStopper),
    currentRecord(currentRecord),
    signaller(signaller)
{
    stream.open(filePath,ios_base::in | ios_base::out | ios_base::app);;
    if(!stream.is_open()){
        std::cout<<"Could not open: " + filePath<<std::endl;
    }
}

void SerialDelegate::run(){
    int counter = 0;
    while(true){
        startStopper->awaitPermissionToStart();

        string line;
        getline(stream,line);

        stringstream ss{line};
        string token;

        float temp{-1},dist{-1},smoke{-1};

        if(getline(ss,token,','))
            temp = stof(token);
        if(getline(ss,token,','))
            dist = stof(token);
        if(getline(ss,token,','))
            smoke = stof(token);

        currentRecord->updateReadings(temp,dist,smoke);

//        bool* updates = signaller->getWarnings();
//        if(updates[0] == true){
//            Send updates back to the microcontroller
//            stream << updates[1]<<","<<updates[2]<<","<<updates[3]<<"\n";
//        }
//        delete[] updates;
    }
}
