#ifndef KZ_CONST_H
#define KZ_CONST_H

#include <QStringList>

//定义宏，删除对象并置NULL
typedef unsigned char Byte;
#define SAFE_DELETE(p) {if(p) {delete (p);(p)=NULL;}}

#define DATABASE_NAME "/911.db"

//  权限
#define USERRITHTS_ADMIN 0 //0：管理员
#define USERRITHTS_USER 1  //1：非管理员
#define USERRITHTS_DEBUG 2 //2：系统调试

// 语言 LANGUGE
#define ENGLISH  0
#define CHINESE  1
#define KOREAN   2

// 系统操作
#define REBOOT    0
#define UPDATE    1
#define LOGOUT    2
#define SHUTDOWN -1

//define file type
#define SIMPLE_PCR 0    //简单pcr
#define ADVANCED_PCR 1  //高级pcr
#define LINK_PCR   2    //连接文件

// 仪器类型
#define INSTRUCT_1  1  // 普通仪器,没有梯度和电动热盖
#define INSTRUCT_6  6  // 6路梯度功能，电动热盖
//maitec.
#define MAITEC_AREAS 6
#define MAITEC1   1
#define MAITEC3   3
#define MAITEC6   6
//  梯度类型
#define MAITEC_STATE_0     0   // 升温速率相同
#define MAITEC_STATE_1     1   // 恒温时间相同
#define MAITEC_STATE_NONE -1


// 当前任务的状态
#define TASK_STATE_NULL      0   // 任务调度为空
#define TASK_STATE_START     1   // 开始执行任务
#define TASK_STATE_RUN       2   // 当前任务正在执行
#define TASK_STATE_PAUSE     3   // 当前任务暂停
#define TASK_STATE_FINISHED  4   // 当前任务已经完成
#define TASK_STATE_ERROR     5   // 当前任务执行错误
#define TASK_STATE_END       6   // 当前任务列表执行完成

// serial thread
#define DEVICE_WIN    "COM1"
#define DEVICE_LINUX  "/dev/ttySAC1"
#define BAUDRATE      BAUD9600
//#define MAX_READ_COUNT 5
#define MAX_SEND_COUNT 10
//#define TIME_OUT       2   //超时单位秒
#define TIME_OUT       1200   //超时单位毫秒
#define PAUSE_TIMEOUT  600    //单位 秒 暂停默认超时时间为 10 分钟

/*
（1）对当前热盖、散热系统、制冷片、热管理运动部分的查询：Q
（2）对热盖、散热系统、制冷片、热管理电机运动位置的控制：P
（3）系统参数的设置(主要是热盖、散热系统、制冷片)：S
（4）文件的控制：F
（5）报警信息：W
（6）广播信息：B
（7）系统升级：U
*/

#define BEGIN_MARK  '&'   /*开始标识*/
#define END_MARK    '$'   /*结束标识*/
#define MAST_MAKR   'M'   /*主机标识*/
#define SLAVE_MARK  'S'   /*从机标识*/
#define S_SCI       'S'   // 串口通讯
#define S_CAN       'C'   // can通讯
#define S_QUERY     'Q'   // 查询
#define S_CONTROL   'P'   // 控制
#define S_SETUP     'S'   // 系统设置
#define S_FILE      'F'   // 文件
#define S_FILE_V    'V'   // 反应体系
#define S_FILE_O    'O'   // 管外控温
#define S_FILE_I    'I'   // 管内控温
#define S_FILE_A    'A'   // 主机发紧急通知（开始/停止）上传温度数据
#define S_FILE_C    'C'   // 主机停止文件控制
#define S_WARNING   'W'   // 报警
#define S_REBOOT    'B'   // 重启下位机
#define S_UPDATE    'U'   // 升级
#define S_ISUPGRADE 'S'   // 是否升级
#define S_NORMAL    'N'   // 下位机返回正常消息
#define DATA_LENGTH  6    // 默认的解析数据长度

// 升级状态
#define UPDATE_NULL    0
#define UPDATE_RUN     1
#define UPDATE_ERROR   2
#define UPDATE_END     3

// 超时等待状态
#define WaitNULL      0
#define sendCmdWait   1
#define sendArkWait   2

// 报警类型

#define NullError            0
#define crc_checkError       1
#define hotLid_Sensor_Error  2
#define fan_Sensor_Error     3
#define block_Sensor_Error   4
#define all_parmer_Error     5
#define Unknown_Error        6
#define no_ArkMeg_Error      7



#define SLAVE_T     'T'   // 从机自动上传温度数据
#define SLAVE_Z     'Z'   // 从机到达目标后发送紧急通知
#define SLAVE_K     'K'   // 从机到达保温时间后发送紧急通知

#define STATE_OPEN   'O'   // 打开
#define STATE_CLOSE  'C'   // 关闭
#define STATE_TEST   'T'   // 测试
#define STATE_KEEP   'K'   // 保温
#define STATE_KEEP_Z 'Z'   // 保温到达
#define STATE_H      'H'   // 加热
#define STATE_D      'D'   // 制冷
#define STATE_ERROR  'E'   // 错误
#define STATE_NULL   '0'   //默认初始化为空

#define FUNCTION_MOTOR       'M'  //温块马达
#define FUNCTION_HOTLID      'H'  //热盖功能部件编号
#define FUNCTION_FAN         'F'  //散热系统功能部件编号
#define FUNCTION_T           'T'  //自动传输温度
#define FUNCTION_BLOCK       'A'  //制冷片功能部件编号
#define FUNCTION_VER         'B'  //下位机版本号

#define FUNCTION_STATUS      'C'  //下位机状态查询
#define FUNCTION_RESET       'S'

// common status
#define Status_Y = 0
#define Status_N = 1
#define Status_Error = 9

//温度控制状态
enum Temperature_Control_Status {
    Temperature_Control_Open = 0,      /*打开*/
    Temperature_Control_Keep = 1,      /*恒温*/
    Temperature_Control_Close = 2,     /*关闭*/
    Temperature_Control_Heating = 3,   /*加热*/
    Temperature_Control_Cooling = 4    /*制冷*/

};

// block 位置状态
enum Block_Position_Status{
    Block_Position_Pull_Open = 0,      /*抽屉拉开*/
    Block_Position_Push_Close = 1,     /*抽屉关闭*/
    Block_Position_Up_High = 2,        /*上升到最高位（上升高位传感器为 true）*/
    Block_Position_Down_Low = 3,       /*下降到压紧 （下降压紧传感器为 true）*/
    Block_Position_Tristate = 4        /*中间状态（电机处于上升或下降状态 上下传感器都为 false）*/
};



//step data error info
#define STEP_STRU_ERROR   1
#define STEP_HEAD_ERROR   2
#define STEP_TEMP_ERROR   3
#define STEP_DATA_ERROR   4


//stage navigate info
#define KZ_SCROLL_DISABLE 0
#define KZ_SCROLL_ENABLE 15
#define KZ_SCROLL_LEFTEND_ENABLE 1
#define KZ_SCROLL_LEFT_ENABLE    2
#define KZ_SCROLL_RIGHT_ENABLE   4
#define KZ_SCROLL_RIGHTEND_ENABLE 8
//kz_image mode definition
#define BROWSE_EDIT_MODE 0
#define RUN_MODE 1
//looptime forever
#define LOOP_FOREVER 60000



//step edit items.
#define BASIC_ITEM     0
#define MAITEC_ITEM    1
#define TOUCHLONG_ITEM 2
#define PAUSE_ITEM     3


// 热盖温块速率
#define HOTlID_RATE 0.5
#define BLOCK_RATE  2.0
#define PLUS        '+'
#define MINUS       '-'



typedef struct __PowerOffState
{
    bool ok;
    int file_no;
    qint8 stageid;
    qint8 stepid;
    qint8 cycle;
    QString time;
}_PowerOffState;


//for stage data.
typedef struct _Temp_Control
{
    int targettemp[6];  //target temp. all with *10 save. so can be int.
    qint8  maitec_state; //-1: no maitec, 0: maitec0, 1: maitec1
    int target_speed; //+- is ok, centigrade/s.  0 is default speed.
    int keeptime; //seconds.
}Temp_Control;

typedef struct _TouchDown_Long
{
    bool enabled;
    int start_loop;
    int end_loop;
    float delta;
}TouchDown_Long;

typedef struct _Pause_Con
{
    bool enabled;
    int start_loop;
    int end_loop;
    int between_loop;
    unsigned int pause_time;
}Pause_Con;

//system informaiton definitin.
typedef struct __Idle_Status
{
    bool hotlid;
    int  hotlid_t;  // 直接保存实际温度 *10 后的数据
    bool block;
    int block_t;    // 直接保存实际温度 *10 后的数据
}_Idle_Status;

//仪器信息
typedef struct __Instruct_Info
{
    QString instru_ver;
    QString instru_name;
    QString instru_sn;
    QString ip;
    QString ip_mask;
    QString mac;
    QString gatway;
    QString dns1;
    QString dns2;
}_Instruct_Info;

//// 试验运行状态标志
//typedef struct __RunSignState
//{
//    int sign;
//    QString name;
//    QString msg;
//}_RunSignState;

// 倒计时
typedef struct __Experiment_Countdown
{
    uint totalTime;
    uint cur_Time;
    uint jump_Time;

    float start_T;
    float end_T;

    float hotLid_rate;
    float block_rate;
    bool isStart;
    bool is4C;

}_Experiment_Countdown;

// 下位机升级
typedef struct __Upgrade_Slave
{
    qint8 slaveId;
    qint8 updateState;
    QString path;
    QList<QByteArray> fileList;
}_Upgrade_Slave;

typedef struct __Stage
{
    qint8 cycle;
    QString name;
    QList<QString> steps;
}_Stage;

typedef struct __KZ_FileInfo
{
    QString Ver; //;
    qint8 language;     //仪器语言
    qint8 instru_type;  //仪器类型 单路 或六路
    qint8 target_speed; //目标速率 100
    char temperature_type;        //控温方式 O 管内控温 I 管外控温
    QString Name;
    QString fmemo;
    QString createdate;
    QString modifydate;
    int     fileno;
    qint8   file_type;  //define file type simple, advance, link.
    qint8   maitec_state;
    bool    touchdownPcr;
    bool    longPcr;
    int     file_owner;
    int     reactionsystem; //uL
    bool    hotlid_on;      //on / off
    int     hotlid_temp;
    bool    shorcut;        // on /off
    QList<_Stage> stage;
}_KZ_FileInfo;

//系统调度任务结构
typedef struct __Task_Scheduling
{

    qint8 cur_task_state;
    qint8 taskid;
    char task_type;

    char file_state;
    char control_state;

    double hotLid_t;
    double block_t[6];

    char hotLid_t_State;
    char hotLid_p_State;
    char block_t_State;

    char func_Unit;

    qint8 max_cycle;
    qint8 cur_cycle;
    qint8 max_stage;
    qint8 cur_stageid;
    qint8 max_step;
    qint8 cur_stepid;
    qint8 waitType;
    qint8 alarmType;

    bool isExcute;


    bool isWait;
    bool isArkMsg;

    bool start;
    bool ispause;

    uint waitTimes;
    uint pauseTimes;
    uint send_Count;
    uint alarm_Count;

    QByteArray sendMsg;
    QByteArray ArkMsg;

}_Task_Scheduling;

void qmsleep(const uint msec);

#endif // KZ_CONST_H


