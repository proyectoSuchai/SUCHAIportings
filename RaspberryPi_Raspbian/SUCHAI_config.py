#!/usr/bin/Python
# -*- coding: utf-8 -*-
__author__ = 'toopazo'

# /**
#  * @file  SUCHAI_config.h
#  * @author Tomas Opazo T
#  * @author Carlos Gonzalez C
#  * @date 04-01-2013
#  * @copyright GNU Public License.
#  *
#  * El proposito de este header file es configurar las ditintas opciones de SUCHAI
#  * en un solo archivo a traves de una serie de defines que son utilzadas por
#  * el pre-procesador del compilador. Las configuraciones descritas aca, afectan
#  * la forma en que funciona el sistema de vuelo del satelite SUCHAI, por ejemplo
#  * activando o desactivando opciones de debug, hardware disponible y parametros
#  * generales del sistema.
#  */

#ifndef SUCHAI_CONFIG_H
#define	SUCHAI_CONFIG_H

# /* Peripheral's config */
#define SCH_UART_DEBUG_PORT     (0) ///< 0-Habilita DB9, 1-Habilita USB
#define SCH_I2C1_ADDR           (0x00) ///< I2C 1 Slave address
#define SCH_I2C2_ADDR           (0xF3) ///< I2C 2 Slave address
#define SCH_I2C3_ADDR           (0xF4) ///< I2C 3 Slave address

# /* Realtime config */
#define SCH_THK_SILENT_REALTIME             (0)  ///< 1=Realtime 0=Debugtime
#define SCH_THK_ANTENNA_REALTIME            (0)  ///< 1=Realtime 0=Debugtime
#define SCH_THK_REALTIME                    (1)  ///< 1=Realtime 0=Debugtime
#define SCH_TASKFLIGHTPLAN_REALTIME         (1)  ///< 1=Realtime 0=Debugtime
#define SCH_FLIGHTPLAN2_REALTIME            (1)  ///< 1=Realtime 0=Debugtime
#define SCH_FLIGHTPLAN3_REALTIME            (1)  ///< 1=Realtime 0=Debugtime

# /* Bus Onboard */
#define SCH_SYSBUS_ONBOARD                  (1)  //< Onboard => I2C1 en uso
#define SCH_PAYBUS_ONBOARD                  (1)  ///< Onboard => I2C3 en uso
#define SCH_ANTENNA_ONBOARD                 (1) ///< Onboard => 3 pin(es) en modo Switch, 1 pin(es) en modo Check
#define SCH_TRX_ONBOARD                     (1) ///< 0=Ninguno, 1= TRX Gomspace => I2C1 en uso
#define SCH_RTC_ONBOARD                     (1) ///< 1 = Onboard 0 = Not Onboard
#define SCH_MEMEEPROM_ONBOARD               (1) ///< 1 = Onboard 0 = Not Onboard
SCH_CAM_ONBOARD = 0                         # ///< Onboard => I2C1 en uso
#define SCH_EPS_ONBOARD                     (0) ///< Onboard => I2C1 en uso
#define SCH_MEMSD_ONBOARD                   (1) ///< Onboard => SPI3 en uso, 1 pin(es) en modo Switch (nSS)
#define SCH_MGN_ONBOARD                     (0)  ///< Onboard => 1 pin(es) en modo Switch

# /* Payloads Onboard */
# //#define SCH_PAYLOADS_ONBOARD                (0) ///< 0 = no payloads is onboard
#define SCH_PAY_LANGMUIR_ONBOARD            (1) ///< Ocupa UART3_en_H1.19_y_H1.20
#define SCH_PAY_FIS_ONBOARD                 (1)  ///<
#define SCH_PAY_GYRO_ONBOARD                (1)  ///< Onboard => SPI3 en uso, 1 pin(es) en modo Switch (nSS)
#define SCH_PAY_SENSTEMP_ONBOARD            (1)  ///<
#define SCH_PAY_GPS_ONBOARD                 (1)  ///< Onboard => UART4 en uso, 1 pin(es) en modo Switch
#define SCH_PAYCAM_nMEMFLASH_ONBOARD        (1)  ///< Onboard => SPI-1 asignado a la Camara. Offboard => SPI-1 asignado a memFlash
#define SCH_PAY_TMESTADO_ONBOARD            (1)  ///< 1 = Onboard 0 = Offboard
#define SCH_PAY_BATTERY_ONBOARD             (1)  ///< 1 = Onboard 0 = Offboard
#define SCH_PAY_DEBUG_ONBOARD               (1)  ///< 1 = Onboard 0 = Offboard


# /* Command Repo configs */
class ConfigCmdgroup():
    """Indicates the belonging of a certain CmdId.
     E.g.
      If PPC = 0x0100 cmds in range 0x0100-0x01FF belongs to PPC.
      If CON = 0x0200  cmds in range 0x0200-0x02FF belongs to CON
      """
    SCH_GID_PPC = 0x0100
    SCH_GNM_PPC = "CmdPPC"
    SCH_GID_CON = 0x0200
    SCH_GNM_CON = "CmdCON"
    SCH_GID_TRX = 0x0300
    SCH_GNM_TRX = "CmdTRX"
    SCH_GID_EPS = 0x0400
    SCH_GNM_EPS = "CmdEPS"
    SCH_GID_DRP = 0x0500
    SCH_GNM_DRP = "CmdDRP"
    SCH_GID_CAM = 0x0600
    SCH_GNM_CAM = "CmdCAM"
    SCH_GID_RTC = 0x0700
    SCH_GNM_RTC = "CmdRTC"
    SCH_GID_TCM = 0x0800
    SCH_GNM_TCM = "CmdTCM"
    SCH_GID_SRP = 0x0900
    SCH_GNM_SRP = "CmdSRP"
    SCH_GID_THK = 0x0A00
    SCH_GNM_THK = "CmdTHK"


#Listeners Id = taskorigId
class ConfigTaskorig():
    TCONSOLE = 0x0001
    THOUSEKEEPING = 0x0002
    TCOMUNICATIONS = 0x0003
    TFLIGHTPLAN = 0x0004
    TFLIGHTPLAN2 = 0x0005
    TFLIGHTPLAN3 = 0x0006
    TDEPLOYMENT = 0x0007


class ConfigPermanentMem():
    SCH_DATA_FOLDER = "runtimefiles/data/"
    SCH_STATE_FOLDER = "runtimefiles/state/"


class GnrlCmds():
    #define CMD_CMDNULL     (0xFFFF)    ///< Dummy command id. Represent a null command
    CMD_NULL = 0xFFFF
    #define CMD_STOP        (0xFFFE)    ///< Reserved id. Represent a stop or separation code
    CMD_STOP = 0xFFFE


#define CMD_SYSREQ_MIN      (1)     ///< Min energy level possible
#define CMD_SYSREQ_MAX      (9)     ///< Max energy level possible
class Sysreqs():
    SYSREQ_MIN = 1
    SYSREQ_MAX = 10

# /* TRX and COMM configs */
#define SCH_TRX_BEACON_PERIOD              (4*60)   ///< [s] Periodo del beacon en segundos (UINT16)
#define SCH_TRX_BEACON_WPM                 (20)     ///< Velocidad del beacon en palabras por minuto 1-255
#define SCH_TRX_BEACON_BAT_LVL             (750)    ///< Nivel de bateria minimo para transmitir beacon
#define SCH_TRX_BEACON_MODE                (2)      ///< Tipo de beacon 0=CW, 1=Cw+FM, 2=FM
#define SCH_TRX_BEACON_POSPONE_PRE         (30*60)  ///< [s] Periodo de inactividad del beacon luego del 1er encendido (silencio radial) (UINT16)
#define SCH_TRX_BEACON_POSPONE_NOM         (1*60)   ///< [s] Periodo de inactividad del beacon luego de cada reinicio (excepto el 1ero) (UINT16)
#define SCH_TRX_RX_BAUD                    (48)     /// RX Baurade 12=1200bps, 24=2400bps, 48=4800bps [48 default]
#define SCH_TRX_TX_BAUD                    (48)     /// TX Baurade 12=1200bps, 24=2400bps, 48=4800bps [48 default]
#define SCH_TRX_NODE_GND                   (10)     /// Nodo de la estacion terrena
#define SCH_TRX_PORT_TM                    (10)     /// Puerto correspondiente a telemetria (en la estacion terrena)
#define SCH_TRX_PORT_TC                    (10)     /// Puerto correspondiente a telecomandos (en el software de vuelo)
#define SCH_TRX_PORT_DEBUG                 (11)     /// Puerto debug en software de vuelo. Solo imprimie el paquete
#define SCH_TRX_PORT_CONSOLE               (12)     /// Puerto consola en software de vuelo. Ejecuta comandos de consola

# /* Other Software configs */
#define SCH_NUM_CMDXXX                          (10)    //< Numero maximo de repositorios de comando que pueden ser agregados (min 3)
#define SCH_TASKDISPATCHER_CHECK_IF_EXECUTABLE  (0)     ///< 1=Activo ( EPS montada ) 0= Inactivo ( EPS no montada SOC se lleva a MAX_SOC )
SCH_TASKDISPATCHER_CHECK_IF_EXECUTABLE = 0      # ///< 1=Activo ( EPS montada ) 0= Inactivo ( EPS no montada SOC se lleva a MAX_SOC )
#define CMD_CMDNULL     (0xFFFF)    ///< Dummy command id. Represent a null command
SCH_TASKEXECUTER_INSIDE_TASKDISPATCHER = 1      # ///< 0=taskExecuter como tarea separada 1=taskExecuter como parte de taskDispatcher
#define SCH_FLIGHTPLAN_RESOLUTION               (1)    ///< [MINUTES] Resolucion de tiempo del flight plan
#define SCH_FLIGHTPLAN_N_CMD                    ((24 * 60) / SCH_FLIGHTPLAN_RESOLUTION) ///< Total de comandos en el flight plan 24[hrs]*60[min] / RES[min]
#define SCH_FLIGHTPLAN_EXTMEMORY                (1)     ///< (0) buffer en  RAM, (1) en memoria SD
#define SCH_FLIGHTPLAN_TYPE                     (3)     ///< 0 = do not use it, 1 = FP, 2 = FP2, 3 = FP3
# //#define SCH_USE_FLIGHTPLAN2                     (1)     ///< 1 = use it, 0 = do not use it
#define SCH_USE_HOUSEKEEPING                    (1)     ///< 1 = use it, 0 = do not use it

# /**
#  * @def SCH_DATAREPOSITORY_MAX_BUFF_TELECMD
#  * Cantidad de telecomandos en cola para ser procesados por el SUCHAI
#  * Max internal (not Transceiver mem) TeleCMD buffer length considering TC in
#  * format [0xTCID|0xARGM|.....|0xSTOP] in frames of 63 bytes each one.
#  * So 15 commands plus 15 args, that means 62 bytes (15 cmd + 15 cmdParam + 1 stop)
#  */
#define SCH_DATAREPOSITORY_MAX_BUFF_TELECMD (10*2)
#define SCH_TC_BUFF_EXTMEMORY               (1)   ///< 1=buffer en la memSD 0=buff en mem RAM
#define SCH_TCM_SYS_REQ                     (3)   ///< Nivel de SOC sobre SYS_REQ_MIN que requieren los comandos de telemetria
#define SCH_BCN_SYS_REQ                     (2)   ///< Nivel de SOC sobre SYS_REQ_MIN que requieren los comandos de beacon
#define SCH_DEP_SYS_REQ                     (2)   ///< Nivel de SOC sobre SYS_REQ_MIN que requieren los comandos de antenna deployment
#define SCH_PAY_GPS_SYS_REQ                 (2)   ///< Nivel de SOC sobre SYS_REQ_MIN que requieren los comandos de PAY del GPS

# /* Drivers config VERBOSE */
#define SCH_CONSOLE_VERBOSE                 (1)   ///< 1=verboso 0=austero
#define SCH_EPS_SUCHAI_VERBOSE              (1)   ///< 1=verboso 0=austero
#define SCH_I2C_SUCHAI_VERBOSE              (0)   ///< 1=verboso 0=austero
#define SCH_INTERFAZ_SPI_VERBOSE            (1)   ///< 1=verboso 0=austero
#define SCH_MEMFLASH_VERBOSE                (1)   ///< 1=verboso 0=austero
#define SCH_MEMSD_VERBOSE                   (1)   ///< 1=verboso 0=austero
#define SCH_PIC_PC104_CONFIG_VERBOSE        (1)   ///< 1=verboso 0=austero
#define SCH_RS232_SUCHAI_VERBOSE            (1)   ///< 1=verboso 0=austero
#define SCH_RTC_MB_VERBOSE                  (1)   ///< 1=verboso 0=austero
#define SCH_TRASNCEIVER_VERBOSE             (1)   ///< 1=verboso 0=austero
#define SCH_CAMERA_VERBOSE                  (1)   ///< 1=verboso 0=austero
#define SCH_GYRO_VERBOSE                    (1)   ///< 1=verboso 0=austero
#define SCH_FISICA_VERBOSE                  (1)   ///< 1=verboso 0=austero
#define SCH_LANGMUIR_VERBOSE                (1)   ///< 1=verboso 0=austero
#define SCH_SENS_TEMP_VERBOSE               (1)   ///< 1=verboso 0=austero

# //System config VERBOSE:
#define SCH_CMDCONSOLE_VERBOSE              (1)  ///< 1=verboso 0=austero
#define SCH_CMDDRP_VERBOSE                  (1)  ///< 1=verboso 0=austero
#define SCH_CMDEPS_VERBOSE                  (1)  ///< 1=verboso 0=austero
#define SCH_CMDPAYLOAD_VERBOSE              (1)  ///< 1=verboso 0=austero
#define SCH_CMDPPC_VERBOSE                  (1)  ///< 1=verboso 0=austero
#define SCH_CMDREPOSITORY_VERBOSE           (1)  ///< 1=verboso 0=austero
#define SCH_CMDRTC_VERBOSE                  (1)  ///< 1=verboso 0=austero
#define SCH_CMDTRX_VERBOSE                  (1)  ///< 1=verboso 0=austero
#define SCH_CMDTCM_VERBOSE                  (1)  ///< 1=verboso 0=austero
#define SCH_DATAREPOSITORY_VERBOSE          (1)  ///< 1=verboso 0=austero
#define SCH_TASKCOMUNICATIONS_VERBOSE       (1)  ///< 1=verboso 0=austero
#define SCH_TASKCONSOLE_VERBOSE             (1)  ///< 1=verboso 0=austero
#define SCH_TASKDEPLOYMENT_VERBOSE          (2)  ///< 1=verboso 0=austero
#define SCH_TASKDISPATCHER_VERBOSE          (1)  ///< 1=verboso 0=austero
#define SCH_TASKEXECUTER_VERBOSE            (1)  ///< 1=verboso 0=austero
#define SCH_TASKFLIGHTPLAN_VERBOSE          (1)  ///< 1=verboso 0=austero
#define SCH_FLIGHTPLAN2_VERBOSE             (1)  ///< 1=verboso 0=austero
#define SCH_FLIGHTPLAN3_VERBOSE             (1)  ///< 1=verboso 0=austero
#define SCH_TASKHOUSEKEEPING_VERBOSE        (1)  ///< 1=verboso 0=austero

#endif	/* SUCHAI_CONFIG_H */
