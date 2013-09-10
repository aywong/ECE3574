/*
#include "proffunc.h"
#include "ui_proffunc.h"


profFunc::profFunc(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::profFunc)
{
    ui->setupUi(this);
}

profFunc::~profFunc()
{
    delete ui;
}
*/

#include "profFunc.h"

int profFunc(int sourceStringLen, const char *sourceString, int destStringLen, char *destString)
{

    if(sourceStringLen < destStringLen){
        for(int i = 0; i < sourceStringLen; i++){
            *destString = *sourceString;

            destString++;
            sourceString++;
        }
        return sourceStringLen;
    }else{
        for(int i = 0; i < destStringLen; i++){
            *destString = *sourceString;

            destString++;
            sourceString++;
        }
        return destStringLen;
    }
}

int testProfFunc(int srcLen, const char* src, int destLen, char* dest){
   // const char* src = "hell0";
    //char* dest = 0;
    int i = profFunc(srcLen,src,destLen,dest);

return i;
}
