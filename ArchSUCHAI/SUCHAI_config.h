/**
 * @file  SUCHAI_config.h
 * @author Tomas Opazo T
 * @author Carlos Gonzalez C
 * @date 04-01-2013
 * @copyright GNU Public License.
 *
 * El proposito de este header file es configurar las ditintas opciones de SUCHAI
 * en un solo archivo a traves de una serie de defines que son utilzadas por
 * el pre-procesador del compilador. Las configuraciones descritas aca, afectan
 * la forma en que funciona el sistema de vuelo del satelite SUCHAI, por ejemplo
 * activando o desactivando opciones de debug, hardware disponible y parametros
 * generales del sistema.
 */

#ifndef SUCHAI_CONFIG_H
#define	SUCHAI_CONFIG_H

/******************************************************************************/
/* Target Architecture */
/******************************************************************************/
/**
 * @def SCH_TARGET_ARCH
 * 0 = POSIX (Linux)
 * 1 = FreeRTOS ((uControllers)
 */
#define SCH_TARGET_ARCH             (0)

/******************************************************************************/
/* OnBoard - OffBoard */
/******************************************************************************/
/* Bus Onboard */
#define SCH_SYSBUS_ONBOARD                  (1) ///< Onboard => I2C1 en uso
#define SCH_PAYBUS_ONBOARD                  (1) ///< Onboard => I2C3 en uso
#define SCH_ANTENNA_ONBOARD                 (1) ///< Onboard => 3 pin(es) en modo Switch, 1 pin(es) en modo Check
#define SCH_TRX_ONBOARD                     (1) ///< 0=Ninguno, 1= TRX Gomspace => I2C1 en uso
#define SCH_RTC_ONBOARD                     (1) ///< 1 = Onboard 0 = Not Onboard
#define SCH_MEMEEPROM_ONBOARD               (1) ///< 1 = Onboard 0 = Not Onboard
#define SCH_EPS_ONBOARD                     (1) ///< Onboard => I2C1 en uso
#define SCH_MEMSD_ONBOARD                   (1) ///< Onboard => SPI3 en uso, 1 pin(es) en modo Switch (nSS)
#define SCH_MGN_ONBOARD                     (0) ///< Onboard => 1 pin(es) en modo Switch

/* Payloads Onboard */
#define SCH_PAY_LANGMUIR_ONBOARD            (1)  ///< Ocupa UART3_en_H1.19_y_H1.20
#define SCH_PAY_SENSTEMP_ONBOARD            (1)  ///< 1 = Onboard (automatic)  0 = Offboard (or manually operated)
#define SCH_PAY_TMESTADO_ONBOARD            (1)  ///< 1 = Onboard (automatic)  0 = Offboard (or manually operated)
#define SCH_PAY_BATTERY_ONBOARD             (1)  ///< 1 = Onboard (automatic)  0 = Offboard (or manually operated)
#define SCH_PAY_GYRO_ONBOARD                (1)  ///< Onboard => SPI3 en uso, 1 pin(es) en modo Switch (nSS)
#define SCH_PAY_GPS_ONBOARD                 (1)  ///< Onboard => UART4 en uso, 1 pin(es) en modo Switch
#define SCH_PAY_CAM_nMEMFLASH_ONBOARD       (1)  ///< Onboard => SPI-1 asignado a la Camara. Offboard => SPI-1 asignado a memFlash
#define SCH_PAY_FIS_ONBOARD                 (1)  ///< 1 = Onboard (automatic)  0 = Offboard (or manually operated)
#define SCH_PAY_DEBUG_ONBOARD               (1)  ///< 1 = Onboard (automatic)  0 = Offboard (or manually operated)

/******************************************************************************/
/* Tasks */
/******************************************************************************/
/* Main Tasks configurations */
#define SCH_THOUSEKEEPING_USE                    (1)    ///< 1 = use it, 0 = do not use it
#define SCH_TCONSOLE_USE                         (1)    ///< 1 = use it, 0 = do not use it
#define SCH_TFLIGHTPLAN_USE                      (3)    ///< 0 = do not use it, 1 = FP, 2 = FP2, 3 = FP3
#define SCH_TCOMMUNICATION_USE                   (SCH_TRX_ONBOARD)  ///< 1 = use it, 0 = do not use it
/* Id Tasks configs */
#define SCH_TCONSOLE_IDORIG                     (0x1101)
#define SCH_THOUSEKEEPING_IDORIG                (0x1102)
#define SCH_TCOMUNICATIONS_IDORIG               (0x1103)
#define SCH_TFLIGHTPLAN_IDORIG                  (0x1104)
#define SCH_TFLIGHTPLAN2_IDORIG                 (0x1105)
#define SCH_TFLIGHTPLAN3_IDORIG                 (0x1106)
#define SCH_TDEPLOYMENT_IDORIG                  (0x1107)
/* Additional Tasks configurations */
#define SCH_NUM_CMDXXX                          (10)    //< Numero maximo de repositorios de comando que pueden ser agregados (min 3)
#define SCH_TASKDISPATCHER_CHECK_IF_EXECUTABLE  (0)     ///< 1=Activo ( EPS montada ) 0= Inactivo ( EPS no montada SOC se lleva a MAX_SOC )
#define SCH_TASKEXECUTER_INSIDE_TASKDISPATCHER  (1)     //< 0=taskExecuter como tarea separada 1=taskExecuter como parte de taskDispatcher
#define SCH_TFLIGHTPLAN_RESOLUTION              (1)    ///< [MINUTES] Resolucion de tiempo del flight plan
#define SCH_TFLIGHTPLAN_N_CMD                   ((24 * 60) / SCH_TFLIGHTPLAN_RESOLUTION) ///< Total de comandos en el flight plan 24[hrs]*60[min] / RES[min]
#define SCH_TFLIGHTPLAN_EXTMEMORY               (1)     ///< (0) buffer en  RAM, (1) en memoria SD
/* VERBOSE Tasks configurations */
#define SCH_TCOMUNICATIONS_VERBOSE              (1)  ///< 1=verboso 0=austero
#define SCH_TCONSOLE_VERBOSE                    (1)  ///< 1=verboso 0=austero
#define SCH_TDEPLOYMENT_VERBOSE                 (2)  ///< 1=verboso 0=austero
#define SCH_TDISPATCHER_VERBOSE                 (1)  ///< 1=verboso 0=austero
#define SCH_TEXECUTER_VERBOSE                   (1)  ///< 1=verboso 0=austero
#define SCH_TFLIGHTPLAN_VERBOSE                 (1)  ///< 1=verboso 0=austero
#define SCH_TFLIGHTPLAN2_VERBOSE                (1)  ///< 1=verboso 0=austero
#define SCH_TFLIGHTPLAN3_VERBOSE                (1)  ///< 1=verboso 0=austero
#define SCH_THOUSEKEEPING_VERBOSE               (1)  ///< 1=verboso 0=austero

/******************************************************************************/
/* CmdXXX */
/******************************************************************************/
/* Command Repo configs */
#define SCH_CMD_PPC                             (0x10)  ///< Indicates the belonging of a certain CmdId. E.g. (cmdId = 0x0A01 and cmdBar=0x0A) => command 0x01 belongs to cmdBar
#define SCH_CMD_CON                             (0x20)  ///< Indicates the belonging of a certain CmdId. E.g. (cmdId = 0x0A01 and cmdBar=0x0A) => command 0x01 belongs to cmdBar
#define SCH_CMD_TRX                             (0x30)  ///< Indicates the belonging of a certain CmdId. E.g. (cmdId = 0x0A01 and cmdBar=0x0A) => command 0x01 belongs to cmdBar
#define SCH_CMD_EPS                             (0x40)  ///< Indicates the belonging of a certain CmdId. E.g. (cmdId = 0x0A01 and cmdBar=0x0A) => command 0x01 belongs to cmdBar
#define SCH_CMD_DRP                             (0x50)  ///< Indicates the belonging of a certain CmdId. E.g. (cmdId = 0x0A01 and cmdBar=0x0A) => command 0x01 belongs to cmdBar
#define SCH_CMD_PAY                             (0x60)  ///< Indicates the belonging of a certain CmdId. E.g. (cmdId = 0x0A01 and cmdBar=0x0A) => command 0x01 belongs to cmdBar
#define SCH_CMD_RTC                             (0x70)  ///< Indicates the belonging of a certain CmdId. E.g. (cmdId = 0x0A01 and cmdBar=0x0A) => command 0x01 belongs to cmdBar
#define SCH_CMD_TCM                             (0x80)  ///< Indicates the belonging of a certain CmdId. E.g. (cmdId = 0x0A01 and cmdBar=0x0A) => command 0x01 belongs to cmdBar
#define SCH_CMD_SRP                             (0x90)  ///< Indicates the belonging of a certain CmdId. E.g. (cmdId = 0x0A01 and cmdBar=0x0A) => command 0x01 belongs to cmdBar
#define SCH_CMD_THK                             (0xA0)  ///< Indicates the belonging of a certain CmdId. E.g. (cmdId = 0x0A01 and cmdBar=0x0A) => command 0x01 belongs to cmdBar
/* VERBOSE CMD configurations */
#define SCH_CMDCONSOLE_VERBOSE                  (1)  ///< 1=verboso 0=austero
#define SCH_CMDDRP_VERBOSE                      (1)  ///< 1=verboso 0=austero
#define SCH_CMDEPS_VERBOSE                      (1)  ///< 1=verboso 0=austero
#define SCH_CMDPAYLOAD_VERBOSE                  (1)  ///< 1=verboso 0=austero
#define SCH_CMDPPC_VERBOSE                      (1)  ///< 1=verboso 0=austero
#define SCH_CMDREPOSITORY_VERBOSE               (1)  ///< 1=verboso 0=austero
#define SCH_CMDRTC_VERBOSE                      (1)  ///< 1=verboso 0=austero
#define SCH_CMDTRX_VERBOSE                      (1)  ///< 1=verboso 0=austero
#define SCH_CMDTCM_VERBOSE                      (1)  ///< 1=verboso 0=austero

/******************************************************************************/
/* Respositories */
/******************************************************************************/
/* General Repos configurations */
/**
 * @def SCH_DATAREPOSITORY_MAX_BUFF_TELECMD
 * Cantidad de telecomandos en cola para ser procesados por el SUCHAI
 * Max internal (not Transceiver mem) TeleCMD buffer length considering TC in
 * format [0xTCID|0xARGM|.....|0xSTOP] in frames of 63 bytes each one.
 * So 15 commands plus 15 args, that means 62 bytes (15 cmd + 15 param + 1 stop)
 */
#define SCH_DATAREPOSITORY_MAX_BUFF_TELECMD (10*2)
#define SCH_TC_BUFF_EXTMEMORY               (1)   ///< 1=buffer en la memSD 0=buff en mem RAM
/* VERBOSE Repos configurations */
#define SCH_DATAREPOSITORY_VERBOSE          (1)  ///< 1=verboso 0=austero

/******************************************************************************/
/* Various aspects */
/******************************************************************************/
/* Realtime config */
#define SCH_THOUSEKEEPING_SILENT_REALTIME   (1)  ///< 1=Realtime 0=Debugtime
#define SCH_THOUSEKEEPING_ANT_DEP_REALTIME  (1)  ///< 1=Realtime 0=Debugtime
#define SCH_THOUSEKEEPING_REALTIME          (1)  ///< 1=Realtime 0=Debugtime
#define SCH_TFLIGHTPLAN_REALTIME            (1)  ///< 1=Realtime 0=Debugtime
#define SCH_TFLIGHTPLAN2_REALTIME           (1)  ///< 1=Realtime 0=Debugtime
#define SCH_TFLIGHTPLAN3_REALTIME           (1)  ///< 1=Realtime 0=Debugtime

/* TRX and COMM configs */
#define SCH_TRX_BEACON_PERIOD              (1*60)   ///< [s] Periodo del beacon en segundos (UINT16)
#define SCH_TRX_BEACON_UPDATE              (570)    ///< [s] Periodo del actualización del beacon en segundos
#define SCH_TRX_BEACON_WPM                 (20)     ///< Velocidad del beacon en palabras por minuto 1-255
#define SCH_TRX_BEACON_BAT_LVL             (500)    ///< Nivel de bateria minimo para transmitir beacon
#define SCH_TRX_BEACON_MODE                (0)      ///< Tipo de beacon 0=CW, 1=Cw+FM, 2=FM
#define SCH_TRX_BEACON_POSPONE_PRE         (5*60)   ///< def:30*60 [s] Periodo de inactividad del beacon luego del 1er encendido (silencio radial) (UINT16)
#define SCH_TRX_BEACON_POSPONE_NOM         (5*60)   ///< [s] Periodo de inactividad del beacon luego de cada reinicio (excepto el 1ero) (UINT16)
#define SCH_TRX_RX_BAUD                    (12)     /// RX Baurade 12=1200bps, 24=2400bps, 48=4800bps [48 default]
#define SCH_TRX_TX_BAUD                    (12)     /// TX Baurade 12=1200bps, 24=2400bps, 48=4800bps [48 default]
#define SCH_TRX_NODE_OBC                   (00)     /// Nodo del OBC
#define SCH_TRX_NODE_EPS                   (02)     /// Nodo de la EPS
#define SCH_TRX_NODE_TRX                   (05)     /// Nodo del TRX
#define SCH_TRX_NODE_TNC                   (09)     /// Nodo del TNC
#define SCH_TRX_NODE_GND                   (10)     /// Nodo de la estacion terrena

#define SCH_TRX_PORT_TM                    (10)     /// Puerto correspondiente a telemetria (en la estacion terrena)
#define SCH_TRX_PORT_TC                    (10)     /// Puerto correspondiente a telecomandos (en el software de vuelo)
#define SCH_TRX_PORT_DEBUG                 (11)     /// Puerto debug en software de vuelo. Solo imprimie el paquete
#define SCH_TRX_PORT_CONSOLE               (12)     /// Puerto consola en software de vuelo. Ejecuta comandos de consola

/*  Peripheral's config */
#define SCH_UART_DEBUG_PORT     (1) ///< 0-Habilita DB9, 1-Habilita USB
#define SCH_I2C1_ADDR           (SCH_TRX_NODE_OBC) ///< I2C 1 Slave address
#define SCH_I2C2_ADDR           (0xF3) ///< I2C 2 Slave address
#define SCH_I2C3_ADDR           (0xF4) ///< I2C 3 Slave address

/* Important SysReq configurations */
#define SCH_TCTM_SYS_REQ                    (1)   ///< Nivel de SOC sobre SYS_REQ_MIN que requieren los comandos de telemetria
#define SCH_BCN_SYS_REQ                     (2)   ///< Nivel de SOC sobre SYS_REQ_MIN que requieren los comandos de beacon
#define SCH_DEPLOYMENT_SYS_REQ              (0)   ///< Nivel de SOC sobre SYS_REQ_MIN que requieren los comandos de antenna deployment
#define SCH_PAY_GPS_SYS_REQ                 (2)   ///< Nivel de SOC sobre SYS_REQ_MIN que requieren los comandos de PAY del GPS

/* Drivers config VERBOSE */
#define SCH_CONSOLE_VERBOSE                 (1)   ///< 1=verboso 0=austero
#define SCH_EPS_VERBOSE                     (1)   ///< 1=verboso 0=austero
#define SCH_I2C_VERBOSE                     (0)   ///< 1=verboso 0=austero
#define SCH_INTERFAZ_SPI_VERBOSE            (1)   ///< 1=verboso 0=austero
#define SCH_MEMFLASH_VERBOSE                (1)   ///< 1=verboso 0=austero
#define SCH_MEMSD_VERBOSE                   (1)   ///< 1=verboso 0=austero
#define SCH_PIC_PC104_CONFIG_VERBOSE        (1)   ///< 1=verboso 0=austero
#define SCH_RS232_SUCHAI_VERBOSE            (1)   ///< 1=verboso 0=austero
#define SCH_RTC_MB_VERBOSE                  (1)   ///< 1=verboso 0=austero
#define SCH_TRASNCEIVER_VERBOSE             (1)   ///< 1=verboso 0=austero
#define SCH_CAMERA_VERBOSE                  (2)   ///< 1=verboso 0=austero
#define SCH_GYRO_VERBOSE                    (1)   ///< 1=verboso 0=austero
#define SCH_FISICA_VERBOSE                  (1)   ///< 1=verboso 0=austero
#define SCH_LANGMUIR_VERBOSE                (1)   ///< 1=verboso 0=austero
#define SCH_SENS_TEMP_VERBOSE               (1)   ///< 1=verboso 0=austero


#endif	/* SUCHAI_CONFIG_H */
