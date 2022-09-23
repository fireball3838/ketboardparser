#include "mfikeypadparser.h"
#include <sstream>

#include <iostream>

BuildinKeypadParser::BuildinKeypadParser(QObject *parent)
    : QObject(parent)
{  }

std::vector<int> BuildinKeypadParser::getArgs(std::string &data) {
    std::vector<int> dataVector;
    std::stringstream dataStream;
    dataStream << data;
    while( dataStream.good() ) {
        std::string substr;
        std::getline(dataStream, substr, ',');
        dataVector.push_back( std::stoi( substr ) );
    }
    return dataVector;
}

void BuildinKeypadParser::setReceivedKeypadMessage(std::string &message)
{
    unsigned long length = message.length();   
    if ( !checkLength(length) )
        return;

    if ( !checkFormat(message, length) )
        return;

    std::string commandName = message.substr(1, 4);
    if (!checkCommand(commandName))
        return;

    std::string data = message.substr(6, length-7);
    switch( _commandsMap[commandName] ) {
    case 1: {
        if (data[0] == ' ') {
            emit actionKey( static_cast<int>(lastPressed), false );
            lastPressed = IdKey::NONE;
    }
        else {
            lastPressed = getKey(data);
            emit actionKey( static_cast<int>(lastPressed), true );
        }
        break;
    }
    case 2: {
        std::vector<int> bri_data = getArgs(data);
        emit stateBrightness(bri_data[0], bri_data[1], bri_data[2], bri_data[3], bri_data[4]);
        break;
    }
    case 3: {
        std::vector<int> temp_data = getArgs(data);
        emit stateTemperature(temp_data[0], temp_data[1]);
        break;
    }
    case 4: {
        std::vector<int> power_data = getArgs(data);
        emit stateTemperature(power_data[0], power_data[1]);
        break;
    }
    default:
        return;
    }
    return;
}

bool BuildinKeypadParser::checkLength(unsigned long &length) {
    return !( (length<8) || (length>18) );
}

bool BuildinKeypadParser::checkFormat(std::string &message, unsigned long &length) {
    return !( (message[0]!='$') || (message[5]!=':') || (message[length-1]!='\n') );
}

bool BuildinKeypadParser::checkCommand(std::string &commandName) {
    return _commandsMap[commandName];
}

IdKey BuildinKeypadParser::getKey(std::string &data) {
    if (data == "0" || data == "~0")  return IdKey::BUILDIN_KEY_1;
    if (data == "1" || data == "~1")  return IdKey::BUILDIN_KEY_2;
    if (data == "2" || data == "~2")  return IdKey::BUILDIN_KEY_3;
    if (data == "3" || data == "~3")  return IdKey::BUILDIN_KEY_4;
    if (data == "4" || data == "~4")  return IdKey::BUILDIN_KEY_5;
    if (data == "5" || data == "~5")  return IdKey::BUILDIN_KEY_6;
    if (data == "6" || data == "~6")  return IdKey::BUILDIN_KEY_7;
    if (data == "7" || data == "~7")  return IdKey::BUILDIN_KEY_8;
    if (data == "8" || data == "~8")  return IdKey::BUILDIN_KEY_9;
    if (data == "9" || data == "~9")  return IdKey::BUILDIN_KEY_10;
    if (data == "10"|| data == "~10") return IdKey::BUILDIN_KEY_11;
    if (data == "11"|| data == "~11") return IdKey::BUILDIN_KEY_12;
    return IdKey::NONE;
}
