#ifndef STRUCTKEYPAD_H
#define STRUCTKEYPAD_H

#include <map>
#include <string>

enum class IdKey
{
    NONE = 0,
    MFCP_MAIN_1,
    MFCP_MAIN_2,
    MFCP_MAIN_3,
    MFCP_MAIN_4,
    MFCP_MAIN_5,
    MFCP_MAIN_6,
    MFCP_MAIN_7,
    MFCP_MAIN_8,
    MFCP_MAIN_9,
    MFCP_MAIN_0,
    MFCP_MAIN_A,
    MFCP_MAIN_B,
    MFCP_MAIN_C,
    MFCP_MAIN_D,
    MFCP_MAIN_E,
    MFCP_MAIN_F,
    MFCP_MAIN_G,
    MFCP_MAIN_H,
    MFCP_MAIN_I,
    MFCP_MAIN_J,
    MFCP_MAIN_K,
    MFCP_MAIN_L,
    MFCP_MAIN_M,
    MFCP_MAIN_N,
    MFCP_MAIN_O,
    MFCP_MAIN_P,
    MFCP_MAIN_Q,
    MFCP_MAIN_R,
    MFCP_MAIN_S,
    MFCP_MAIN_T,
    MFCP_MAIN_U,
    MFCP_MAIN_V,
    MFCP_MAIN_W,
    MFCP_MAIN_X,
    MFCP_MAIN_Y,
    MFCP_MAIN_Z,
    MFCP_MAIN_POINT,        //.(точка)
    MFCP_MAIN_ERASE,        //СТЕР
    MFCP_MAIN_SPACE,        //ПРОБ
    MFCP_MAIN_RESET,        //СБР
    MFCP_MAIN_ENTER,        //ВВОД
    MFCP_MAIN_PLUS_MINUS,   //+-
    MFCP_FRAMED_TO,         //НА
    MFCP_FRAMED_PLAN,       //ПЛАН
    MFCP_FRAMED_RESET,      //СБР
    MFCP_FRAMED_MENU,       //МЕНЮ
    MFCP_FRAMED_PROC,       //ПРОЦ
    MFCP_FRAMED_ENTER,      //ВВОД
    MFCP_FRAMED_HOME,       //дом
    MFCP_FRAMED_FSV,        //ФСВ
    MFCP_FRAMED_RAD,        //РАД
    MFCP_FRAMED_NAV,        //НАВ
    MFCP_FRAMED_ANSW,       //ОТВ
    MFCP_FRAMED_ARROWS,     //стрелка влево-вправо
    MFCP_ENCOD_ASSIGN_COURSE,   //ЗК
    MFCP_ENCOD_AZIMUTH,         //АЗИМУТ
    MFCP_ENCOD_ALTITUDE,        //ВЫС
    MFCP_ENCOD_VOLUME,          //ГРОМК
    MFCP_ENCOD_UNIVERSAL,       //универсальный (ФСВ/РАД/НАВ/ОТВ)
    MFCP_ENCOD_FSV_,            //ФСВ
    MFCP_ENCOD_RAD_,            //РАД
    MFCP_ENCOD_NAV_,            //НАВ
    MFCP_ENCOD_ANSW_,           //ОТВ
    MFCP_ENCOD_SCALE_CENTER,    //МАСШТАБ (центр)
    MFCP_ENCOD_SCALE_UP,        //МАСШТАБ (вверх)
    MFCP_ENCOD_SCALE_RIGHT,     //МАСШТАБ (вправо)
    MFCP_ENCOD_SCALE_DOWN,      //МАСШТАБ (вниз)
    MFCP_ENCOD_SCALE_LEFT,      //МАСШТАБ (влево)
    ICP_TO,         //НА (используется как разделитель между МФПУ и ПУИ, поэтому всегда первый)
    ICP_PLAN,       //ПЛАН
    ICP_RESET,      //СБР
    ICP_MENU,       //МЕНЮ
    ICP_PROC,       //ПРОЦ
    ICP_ENTER,      //ВВОД
    ICP_FSV,        //ФСВ
    ICP_RAD,        //РАД
    ICP_NAV,        //НАВ
    ICP_ARROWS,     //стрелка влево-вправо
    ICP_ENCOD_FSV,            //ФСВ
    ICP_ENCOD_PRESSURE_BAROM, //Рбар
    ICP_ENCOD_UNIVERSAL,      //универсальный (НАВ/РАД)
    ICP_ENCOD_RAD_,           //РАД
    ICP_ENCOD_NAV_,           //НАВ
    ICP_ENCOD_SCALE_CENTER,   //МАСШТ (центр)
    ICP_ENCOD_SCALE_UP,       //МАСШТ (вверх)
    ICP_ENCOD_SCALE_RIGHT,    //МАСШТ (вправо)
    ICP_ENCOD_SCALE_DOWN,     //МАСШТ (вниз)
    ICP_ENCOD_SCALE_LEFT,     //МАСШТ (влево)
    BUILDIN_KEY_1,          //кнопка 1
    BUILDIN_KEY_2,          //кнопка 2
    BUILDIN_KEY_3,          //кнопка 3
    BUILDIN_KEY_4,          //кнопка 4
    BUILDIN_KEY_5,          //кнопка 5
    BUILDIN_KEY_6,          //кнопка 6
    BUILDIN_KEY_7,          //кнопка 7
    BUILDIN_KEY_8,          //кнопка 8
    BUILDIN_KEY_9,          //кнопка 9
    BUILDIN_KEY_10,         //кнопка 10
    BUILDIN_KEY_11,         //кнопка 11
    BUILDIN_KEY_12,         //кнопка 12
};

enum class IdEncoder
{
    NONE = 0,
    MFCP_ASSIGN_COURSE,     //ЗК
    MFCP_AZIMUTH,           //АЗИМУТ
    MFCP_PRESSURE_BAROM,    //Pбар
    MFCP_ALTITUDE,          //ВЫС
    MFCP_UNIVERSAL_OUTER,   //универсальный (внешний) (ФСВ/РАД/НАВ/ОТВ)
    MFCP_UNIVERSAL_INNER,   //универсальный (внутренний) (ФСВ/РАД/НАВ/ОТВ)
    MFCP_SCALE,             //МАСШТ
    MFCP_VOLUME,            //ГРОМК
    MFCP_FSV_INNER_,        //ФСВ (внутренний)
    MFCP_FSV_OUTER_,        //ФСВ (внешний)
    MFCP_RAD_INNER_,        //РАД (внутренний)
    MFCP_RAD_OUTER_,        //РАД (внешний)
    MFCP_NAV_INNER_,        //НАВ (внутренний)
    MFCP_NAV_OUTER_,        //НАВ (внешний)
    MFCP_ANSW_INNER_,       //ОТВ (внутренний)
    MFCP_ANSW_OUTER_,       //ОТВ (внешний)
    ICP_SCALE,           //МАСШТ
    ICP_FSV_OUTER,       //ФСВ (внешний)
    ICP_FSV_INNER,       //ФСВ (внутренний)
    ICP_UNIVERSAL_OUTER, //универсальный (внешний) (РАД/НАВ)
    ICP_UNIVERSAL_INNER, //универсальный (внутренний) (РАД/НАВ)
    ICP_PRESSURE_BAROM,  //Рбар
    ICP_RAD_OUTER_,      //РАД (внешний)
    ICP_RAD_INNER_,      //РАД (внутренний)
    ICP_NAV_OUTER_,      //НАВ (внешний)
    ICP_NAV_INNER_,      //НАВ (внутренний)
};

enum class KeypadDeviceId
{
    NONE = 0,
    MFI_LEFT    = 1,
    MFI_RIGHT   = 2,
    MFCP        = 3,
    ICP         = 4,
    BROADCAST   = 255,
};

enum class TypeKeypadCommand
{
    NONE = 0,
    LED,
    BRI,
    RQS,
    OKY,
    ERR,
};

const std::map<TypeKeypadCommand, std::string>  titleKeypadCommand {
    {TypeKeypadCommand::LED, "LED"},
    {TypeKeypadCommand::BRI, "BRI"},
    {TypeKeypadCommand::RQS, "RQS"},
    {TypeKeypadCommand::OKY, "OKY"},
    {TypeKeypadCommand::ERR, "ERR"},
};

struct StateControlPanel
{
    uint8_t switchPosition;     //!< положение переключателя, для ПУИ равно 0 (левый - 1, средний - 2, правый - 3)
    uint8_t brightnessTitle;    //!< яркость подсветки группы надписей (0-255)
    uint8_t brightnessKeys;     //!< яркость подсветки группы кнопок (0-255)
    uint8_t stateLedFsv;        //!< состояние светодиода ФСВ: 0 - выкл, 1 - вкл
    uint8_t stateLedRad;        //!< состояние светодиода РАД: 0 - выкл, 1 - вкл
    uint8_t stateLedNav;        //!< состояние светодиода НАВ: 0 - выкл, 1 - вкл
    uint8_t stateLedAnsw;       //!< состояние светодиода ОТВ: 0 - выкл, 1 - вкл (для ПУИ всегда равно 0)
    int16_t voltage;            //!< напряжение на пульте,В (хранит 271 для значения 27.1)
};

struct VersionControlPanel
{
    uint8_t major;  //!< major версия ПО
    uint8_t minor;  //!< minor версия ПО
    uint8_t patch;  //!< patch версия ПО
    uint8_t day;    //!< дата сборки - день
    uint8_t month;  //!< дата сборки - месяц
    uint8_t year;   //!< дата сборки - год
};

const std::map<IdKey, char> keysMfcp{
    {IdKey::NONE, 0},
    {IdKey::MFCP_MAIN_1, 49},
    {IdKey::MFCP_MAIN_2, 50},
    {IdKey::MFCP_MAIN_3, 51},
    {IdKey::MFCP_MAIN_4, 52},
    {IdKey::MFCP_MAIN_5, 53},
    {IdKey::MFCP_MAIN_6, 54},
    {IdKey::MFCP_MAIN_7, 55},
    {IdKey::MFCP_MAIN_8, 56},
    {IdKey::MFCP_MAIN_9, 57},
    {IdKey::MFCP_MAIN_0, 48},

    {IdKey::MFCP_MAIN_A, 65},
    {IdKey::MFCP_MAIN_B, 66},
    {IdKey::MFCP_MAIN_C, 67},
    {IdKey::MFCP_MAIN_D, 68},
    {IdKey::MFCP_MAIN_E, 69},
    {IdKey::MFCP_MAIN_F, 70},
    {IdKey::MFCP_MAIN_G, 71},
    {IdKey::MFCP_MAIN_H, 72},
    {IdKey::MFCP_MAIN_I, 73},
    {IdKey::MFCP_MAIN_J, 74},
    {IdKey::MFCP_MAIN_K, 75},
    {IdKey::MFCP_MAIN_L, 76},
    {IdKey::MFCP_MAIN_M, 77},
    {IdKey::MFCP_MAIN_N, 78},
    {IdKey::MFCP_MAIN_O, 79},
    {IdKey::MFCP_MAIN_P, 80},
    {IdKey::MFCP_MAIN_Q, 81},
    {IdKey::MFCP_MAIN_R, 82},
    {IdKey::MFCP_MAIN_S, 83},
    {IdKey::MFCP_MAIN_T, 84},
    {IdKey::MFCP_MAIN_U, 85},
    {IdKey::MFCP_MAIN_V, 86},
    {IdKey::MFCP_MAIN_W, 87},
    {IdKey::MFCP_MAIN_X, 88},
    {IdKey::MFCP_MAIN_Y, 89},
    {IdKey::MFCP_MAIN_Z, 90}
};

#endif // STRUCTKEYPAD_H
