#ifndef MFIKEYPADPARSER_H
#define MFIKEYPADPARSER_H

#include "structkeypad.h"
#include <QObject>

class BuildinKeypadParser  : public QObject
{
    Q_OBJECT
public:
    BuildinKeypadParser(QObject *parent = nullptr);
    void setReceivedKeypadMessage(std::string &message);

signals:
    void actionKey(int keyId, bool isPress);
    void stateBrightness(int brightnessKeys,    int brightnessDisplay,
                         int brightnessSensor1, int brightnessSensor2);
    void stateTemperature(int temperature1, int temperature2);
    void statePowerSupply(bool isOperabilityBoardPowerSupply, bool isOperabilityAccumPowerSupply);


public:
//private:
    bool checkLength(unsigned long &length);
    bool checkFormat(std::string &message, unsigned long &length);
    bool checkCommand(std::string &commandName);
    IdKey getKey(std::string &data);
    IdKey lastPressed = IdKey::NONE;
    std::vector<int> getArgs(std::string &data);
    std::map <std::string, int> _commandsMap = {
        {"MKEY", 1},
        {"MBRI", 2},
        {"MTMP", 3},
        {"MPWR", 4},
    };
};

#endif // MFIKEYPADPARSER_H
