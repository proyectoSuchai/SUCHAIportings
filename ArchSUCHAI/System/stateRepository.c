///*                                 SUCHAI
// *                      NANOSATELLITE FLIGHT SOFTWARE
// *
// *      Copyright 2013, Tomas Opazo Toro, tomas.opazo.t@gmail.com
// *
// * This program is free software: you can redistribute it and/or modify
// * it under the terms of the GNU General Public License as published by
// * the Free Software Foundation, either version 3 of the License, or
// * (at your option) any later version.
// *
// * This program is distributed in the hope that it will be useful,
// * but WITHOUT ANY WARRANTY; without even the implied warranty of
// * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// * GNU General Public License for more details.
// *
// * You should have received a copy of the GNU General Public License
// * along with this program.  If not, see <http://www.gnu.org/licenses/>.
// */
//
//#include "stateRepository.h"
//#include "include/cmdIncludes.h"
////#include "include/stateRepository.h"
//
//#define SCH_DATAREPOSITORY_VERBOSEMEMSD_ 0
//
////semaforo para sincronizar accceso a las variables de estado
////extern xSemaphoreHandle statusRepositorySem;
//bool statusRepositorySem;
//
//
////******************************************************************************
//// BUS section
////******************************************************************************
//
//#if (SCH_MEMEEPROM_ONBOARD==0)
//    int STA_STATE_VAR_BUFF[sta_busStateVar_last_one];
//#endif
//
///**
// * Funcion para obtener una variable de estado
// * @param indxVar. Variable de estado que quiero modificar
// */
//int sta_get_BusStateVar(STA_BusStateVar indxVar){
//    portBASE_TYPE semStatus = xSemaphoreTake( statusRepositorySem, portMAX_DELAY );
//
//    int value;
//    int param;
//    switch(indxVar){
//        // Bus Hw status (connected trough the PC/104 to the OBC -PIC24-)
//        case sta_RTC_isAlive:
//            value = RTC_isAlive();
//            break;
//        case sta_TRX_isAlive:
//            value = trx_isAlive(NULL);
//            break;
//        case sta_EPS_isAlive:
//            value = eps_isAlive(NULL);
//            break;
//        case sta_MemEEPROM_isAlive:
//            value = mem_EEPROM_isAlive();
//            break;
//        case sta_MemSD_isAlive:
//            value = memSD_isAlive();
//            break;
//        case sta_AntSwitch_isOpen:
//            param = 1000;
//            value = thk_get_AntSwitch_isOpen(&param);
//            break;
//        //FPL => (C&DH subsystem)
//        case sta_fpl_index:
//            //printf("FPL => (C&DH subsystem, Fligth Plan)\r\n");
//            value =  drp_fpl_get_index(NULL);
//            break;
//        //PPC => (C&DH subsystem)
//        case sta_ppc_opMode:
//            //printf("PPC => (C&DH subsystem)\r\n");
//            value = ppc_get_opMode(NULL);
//            break;
//        case sta_ppc_lastResetSource:
//            param = 0;  //verbosity level
//            value = ppc_get_lastResetSource(&param);
//            break;
//        case sta_ppc_hoursAlive:
//            value = ppc_get_hoursAlive(NULL);
//            break;
//        case sta_ppc_hoursWithoutReset:
//            value = ppc_get_hoursWithoutReset(NULL);
//            break;
//        case sta_ppc_resetCounter:
//            value = ppc_get_resetCounter(NULL);
//            break;
//        case sta_ppc_wdt:
//            value = ppc_get_wdt_state(NULL);
//            break;
//        case sta_ppc_osc:
//            param = 0;  //verbosity level
//            value = ppc_get_osc(&param);
//            break;
//        case sta_ppc_MB_nOE_USB_nINT_stat:
//            value = ppc_get_PPC_MB_nOE_USB_nINT(NULL);
//            break;
//        case sta_ppc_MB_nOE_MHX_stat:
//            value = ppc_get_PPC_MB_nOE_MHX(NULL);
//            break;
//        case sta_ppc_MB_nON_MHX_stat:
//            value = ppc_get_PPC_MB_nON_MHX(NULL);
//            break;
//        case sta_ppc_MB_nON_SD_stat:
//            value = ppc_get_PPC_MB_nON_SD(NULL);
//            break;
//        //DEP => (C&DH subsystem)
//        case sta_dep_ant_deployed:
//            //printf("DEP => (C&DH subsystem)\r\n");
//            value = thk_get_dep_ant_deployed(NULL);
//            break;
//        case sta_dep_ant_tries:
//            value = thk_get_dep_ant_tries(NULL);
//            break;
//        case sta_dep_year:
//            value = thk_get_dep_year(NULL);
//            break;
//        case sta_dep_month:
//            value = thk_get_dep_month(NULL);
//            break;
//        case sta_dep_week_day:
//            value = thk_get_dep_week_day(NULL);
//            break;
//        case sta_dep_day_number:
//            value = thk_get_dep_day_number(NULL);
//            break;
//        case sta_dep_hours:
//            value = thk_get_dep_hours(NULL);
//            break;
//        case sta_dep_minutes:
//            value = thk_get_dep_minutes(NULL);
//            break;
//        case sta_dep_seconds:
//            value = thk_get_dep_seconds(NULL);
//            break;
//        //RTC => (C&DH subsystem)
//        case sta_rtc_year:
//            //printf("RTC => (C&DH subsystem)\r\n");
//            value = RTC_get_year();
//            break;
//        case sta_rtc_month:
//            value = RTC_get_month();
//            break;
//        case sta_rtc_week_day:
//            value = RTC_get_week_day();
//            break;
//        case sta_rtc_day_number:
//            value = RTC_get_day_num();
//            break;
//        case sta_rtc_hours:
//            value = RTC_get_hours();
//            break;
//        case sta_rtc_minutes:
//            value = RTC_get_minutes();
//            break;
//        case sta_rtc_seconds:
//            value = RTC_get_seconds();
//            break;
//        #if (SCH_EPS_ONBOARD==1)
//            case sta_eps_batt_temp_0:
//                param = EPS_ID_batt_temp_0;
//                value = eps_read_vars(&param);
//                break;
//            case sta_eps_batt_temp_1:
//                param = EPS_ID_batt_temp_1;
//                value = eps_read_vars(&param);
//                break;
//            case sta_eps_battery_voltage:
//                param = EPS_ID_battery_voltage;
//                value = eps_read_vars(&param);
//                break;
//            case sta_eps_panel_current:
//                param = EPS_ID_panel_current;
//                value = eps_read_vars(&param);
//                break;
//            case sta_eps_panel_voltage_1:
//                param = EPS_ID_panel_voltage_1;
//                value = eps_read_vars(&param);
//                break;
//            case sta_eps_panel_voltage_2:
//                param = EPS_ID_panel_voltage_2;
//                value = eps_read_vars(&param);
//                break;
//            case sta_eps_panel_voltage_3:
//                param = EPS_ID_panel_voltage_3;
//                value = eps_read_vars(&param);
//                break;
//            case sta_eps_system_current:
//                param = EPS_ID_system_current;
//                value = eps_read_vars(&param);
//                break;
//        #endif
//        #if (SCH_TRX_ONBOARD==1)
//            //TRX => (Communication subsystem)
//            case sta_trx_opmode:
//                value = trx_get_operation_mode(NULL);
//                break;
//            case sta_trx_count_tm:
//                value = trx_get_count_tm(NULL);
//                break;
//            case sta_trx_count_tc:
//                value = trx_get_count_tc(NULL);
//                break;
//            case sta_trx_day_last_tc:
//                value = trx_get_day_last_tc(NULL);
//                break;
//            case sta_trx_beacon_bat_lvl:
//                value = trx_get_beacon_level(NULL);
//                break;
//            case sta_trx_beacon_period:
//                value = trx_get_beacon_period(NULL);
//                break;
//            case sta_trx_rx_baud:
//                value = trx_get_rx_baud(NULL);
//                break;
//            case sta_trx_tx_baud:
//                value = trx_get_tx_baud(NULL);
//                break;
//        #endif
//        default:
//            printf("[sta_get_stateVar] Error: No function/command for STA_StateVar %d \r\n", indxVar);
//            value = -(0x7FFF);
//        break;
//    }
//
//    semStatus = xSemaphoreGive(statusRepositorySem);
//
//    return value;
//}
//
///**
// * Funcion a llamar luego de un Reset del PIC y luego de
// * @sa sta_onReset_memEEPROM para inicializar a los valore correctos las
// * variables de estado que necesitan ser modificadas.
// *
// * No todas son modificadas, hay muchas que se inicializan en otros
// * llamados anteriores o posteriores (@sa default_PIC_config,
// * @sa dep_init_suchai_hw, @sa dep_init_suchai_repos).
// */
//void sta_onReset_BusStateRepo(void)
//{
//    int param, res;
//
//    // Set to default
//    //param = STA_PPC_OPMODE_NORMAL;
//    //ppc_set_opMode(&param);
//
//    // Increment reset counter
//    param = ppc_get_resetCounter(NULL);
//    param++;
//    ppc_set_resetCounter(&param);
//
//
//    //print important StatusVars
//    printf("    [sta_onResetStatRepo] Important STA_StateVar variables:\r\n");
//
//    res = ppc_get_resetCounter(NULL);
//    printf("        * ppc_get_resetCounter: %d\r\n", res);
//    #if (SCH_DATAREPOSITORY_VERBOSE>=1)
//        if(res == 0){
//            printf("            * First time on, resetCounter = %d\n", res);
//        }
//        else{
//            printf("            * NOT the First time on, resetCounter = %d\n", res);
//        }
//    #endif
//
//    param = 1;  //verbose
//    ppc_get_lastResetSource(&param);
//
//    res = ppc_get_hoursAlive(NULL);
//    printf("        * ppc_get_hoursAlive: %d\r\n", res);
//
//    res = ppc_get_hoursWithoutReset(NULL);
//    printf("        * ppc_get_hoursWithoutReset: %d\r\n", res);
//
//    res = ppc_get_wdt_state(NULL);
//    printf("        * ppc_get_wdt_state: %d\r\n", res);
//
//    param = 1;  //verbose
//    res = ppc_get_osc(&param);
//
//    //Antenna
//    param = 1000;
//    res = thk_get_AntSwitch_isOpen(&param);
//    printf("        * thk_get_AntSwitch_isOpen: %d\r\n", res);
//    #if (SCH_DATAREPOSITORY_VERBOSE>=1)
//        printf("            * Antenna Deployment rely on this var AND others\r\n");
//    #endif
//
//    res = thk_get_dep_ant_deployed(NULL);
//    printf("        * thk_get_dep_ant_deployed: %d\r\n", res);
//    #if (SCH_DATAREPOSITORY_VERBOSE>=1)
//        if(res == 0){
//            printf("            * Antenna Deployment is pending\r\n");
//        }
//        else{
//            printf("            * Antenna Deployment was successfully completed\r\n");
//        }
//    #endif
//
////    /* Debug purposes      */
////    int dep = thk_get_dep_ant_deployed(NULL);
////    if(dep == 0){
////        printf("[sta_onResetStatRepo] All STA_StateVar variables:\r\n");
////        //print all SatatusVars
////        srp_print_STA_stateVar(NULL);
////    }
//}
//
//char* sta_BusStateVarToString(STA_BusStateVar var_i){
//    char *pc;
//    switch(var_i){
//        case sta_RTC_isAlive:
//            pc = "sta_RTC_isAlive";
//            break;
//        case sta_TRX_isAlive:
//            pc = "sta_TRX_isAlive";
//            break;
//        case sta_EPS_isAlive:
//            pc = "sta_EPS_isAlive";
//            break;
//        case sta_MemEEPROM_isAlive:
//            pc = "sta_MemEEPROM_isAlive";
//            break;
//        case sta_MemSD_isAlive:
//            pc = "sta_MemSD_isAlive";
//            break;
//        case sta_AntSwitch_isOpen:
//            pc = "sta_AntSwitch_isOpen";
//            break;
//
//        //FLIGHT PLAN => (C&DH subsystem)
//        case sta_fpl_index:         // Indice del flight plan que sera editado
//            pc = "sta_fpl_index";
//            break;
//
//        //PPC => (C&DH subsystem)
//        case sta_ppc_opMode:
//            pc = "sta_ppc_opMode";
//            break;
//        case sta_ppc_lastResetSource:
//            pc = "sta_ppc_lastResetSource";
//            break;
//        case sta_ppc_hoursAlive:
//            pc = "sta_ppc_hoursAlive";
//            break;
//        case sta_ppc_hoursWithoutReset:
//            pc = "sta_ppc_hoursWithoutReset";
//            break;
//        case sta_ppc_resetCounter:
//            pc = "sta_ppc_resetCounter";
//            break;
//        case sta_ppc_wdt:				// 1=WDT Active: 0=WDT Inactive
//            pc = "sta_ppc_wdt";
//            break;
//        case sta_ppc_osc:				// holds Current Oscillator
//            pc = "sta_ppc_osc";
//            break;
//        case sta_ppc_MB_nOE_USB_nINT_stat:
//            pc = "sta_ppc_MB_nOE_USB_nINT_stat";
//            break;
//        case sta_ppc_MB_nOE_MHX_stat:
//            pc = "sta_ppc_MB_nOE_MHX_stat";
//            break;
//        case sta_ppc_MB_nON_MHX_stat:
//            pc = "sta_ppc_MB_nON_MHX_stat";
//            break;
//        case sta_ppc_MB_nON_SD_stat:
//            pc = "sta_ppc_MB_nON_SD_stat";
//            break;
//
//        //DEP => (C&DH subsystem)
//        case sta_dep_ant_deployed:      // 1=already deployed: 0=not deployed yet
//            pc = "sta_dep_ant_deployed";
//            break;
//        case sta_dep_ant_tries:         // Number of tries to deploy antenna
//            pc = "sta_dep_ant_tries";
//            break;
//        case sta_dep_year:
//            pc = "sta_dep_year";
//     	    break;
//        case sta_dep_month:
//            pc = "sta_dep_month";
//     	    break;
//        case sta_dep_week_day:
//            pc = "sta_dep_week_day";
//     	    break;
//        case sta_dep_day_number:
//            pc = "sta_dep_day_number";
//     	    break;
//        case sta_dep_hours:
//            pc = "sta_dep_hours";
//     	    break;
//        case sta_dep_minutes:
//            pc = "sta_dep_minutes";
//     	    break;
//        case sta_dep_seconds:
//            pc = "sta_dep_seconds";
//     	    break;
//
//        //RTC => (C&DH subsystem)
//        case sta_rtc_year:
//            pc = "sta_rtc_year";
//     	    break;
//        case sta_rtc_month:
//            pc = "sta_rtc_month";
//     	    break;
//        case sta_rtc_week_day:
//            pc = "sta_rtc_week_day";
//     	    break;
//        case sta_rtc_day_number:
//            pc = "sta_rtc_day_number";
//     	    break;
//        case sta_rtc_hours:
//            pc = "sta_rtc_hours";
//     	    break;
//        case sta_rtc_minutes:
//            pc = "sta_rtc_minutes";
//     	    break;
//        case sta_rtc_seconds:
//            pc = "sta_rtc_seconds";
//     	    break;
//
//        #if (SCH_EPS_ONBOARD == 1)
//            //EPS => (Energy subsystem)
//            case sta_eps_batt_temp_0:
//                pc = "sta_eps_batt_temp_0";
//                break;
//            case sta_eps_batt_temp_1:
//                pc = "sta_eps_batt_temp_1";
//                break;
//            case sta_eps_battery_voltage:
//                pc = "sta_eps_battery_voltage";
//                break;
//            case sta_eps_panel_current:
//                pc = "sta_eps_panel_current";
//                break;
//            case sta_eps_panel_voltage_1:
//                pc = "sta_eps_panel_voltage_1";
//                break;
//            case sta_eps_panel_voltage_2:
//                pc = "sta_eps_panel_voltage_2";
//                break;
//            case sta_eps_panel_voltage_3:
//                pc = "sta_eps_panel_voltage_3";
//                break;
//            case sta_eps_system_current:
//                pc = "sta_eps_system_current";
//                break;
//        #endif
//
//        /* Revisar de aqui hacia abajo si aun son necesarios !!! */
//
//        //TRX => (Communication subsystem)
//        #if (SCH_TRX_ONBOARD==1)
//            case sta_trx_opmode:           // Operation mode
//                pc = "sta_trx_opmode";
//                break;
//            case sta_trx_count_tm:         // number of sended TM
//                pc = "sta_trx_count_tm";
//                break;
//            case sta_trx_count_tc:         // number of received TC
//                pc = "sta_trx_count_tc";
//                break;
//            case sta_trx_day_last_tc:      // day of the last received tc (since 1/1/00)
//                pc = "sta_trx_day_last_tc";
//                break;
//            case sta_trx_beacon_period:
//                pc = "sta_trx_beacon_period";
//                break;
//            case sta_trx_beacon_bat_lvl:
//                pc = "sta_trx_beacon_bat_lvl";
//                break;
//            case sta_trx_rx_baud:
//                pc = "sta_trx_rx_baud";
//                break;
//            case sta_trx_tx_baud:
//                pc = "sta_trx_tx_baud";
//                break;
//        #endif
//        default:
//            pc = "unknown BusStateVar";
//            break;
//    }
//    return pc;
//}
//
////******************************************************************************
//// PAYLOAD section
////******************************************************************************
//
//void sta_onReset_PayStateRepo(void){
//    return;
//}
//
//int sta_get_PayStateVar(STA_PayStateVar indxVar){
//    portBASE_TYPE semStatus = xSemaphoreTake( statusRepositorySem, portMAX_DELAY );
//
//    int value;
//    //int param;
//    switch(indxVar){
//    // Payload Hw status (connected trough the PC/104 to the OBC -PIC24-)
//        case sta_pay_lagmuirProbe_isAlive:
//            //printf("PAY => (Payload subsystem)\r\n");
//            value = pay_isAlive_langmuirProbe(NULL);
//            break;
//        case sta_pay_sensTemp_isAlive:
//            value = pay_isAlive_sensTemp(NULL);
//            break;
//        case sta_pay_gps_isAlive:
//            value = pay_isAlive_gps(NULL);
//            break;
//        case sta_pay_expFis_isAlive:
//            value = pay_isAlive_expFis(NULL);
//            break;
//        case sta_pay_camera_isAlive:
//            value = pay_isAlive_camera(NULL);
//            break;
//        case sta_pay_gyro_isAlive:
//            value = pay_isAlive_gyro(NULL);
//            break;
//        case sta_pay_tmEstado_isAlive:
//            value = pay_isAlive_tmEstado(NULL);
//            break;
//        case sta_pay_battery_isAlive:
//            value = pay_isAlive_battery(NULL);
//            break;
//        case sta_pay_debug_isAlive:
//            value = pay_isAlive_debug(NULL);
//            break;
//        case sta_pay_langmuirProbe_isDeployed:
//            value = 0;  //no hay forma de saberlo !!
//            break;
//
//        //PAY => (Payload subsystem)
//        case sta_pay_langmuirProbe_state:
//            //printf("PAY => (Payload subsystem)\r\n");
//            value = pay_get_state_langmuirProbe(NULL);
//            break;
//        case sta_pay_sensTemp_state:
//            value = pay_get_state_sensTemp(NULL);
//            break;
//        case sta_pay_gps_state:
//            value = pay_get_state_gps(NULL);
//            break;
//        case sta_pay_expFis_state:
//            value = pay_get_state_expFis(NULL);
//            break;
//        case sta_pay_camera_state:
//            value = pay_get_state_camera(NULL);
//            break;
//        case sta_pay_gyro_state:
//            value = pay_get_state_gyro(NULL);
//            break;
//        case sta_pay_tmEstado_state:
//            value = pay_get_state_tmEstado(NULL);
//            break;
//        case sta_pay_battery_state:
//            value = pay_get_state_battery(NULL);
//            break;
//        case sta_pay_debug_state:
//            value = pay_get_state_debug(NULL);
//            break;
//
//        default:
//            printf("[sta_get_stateVar] Error: No function/command for STA_StateVar %d \r\n", indxVar);
//            value = -(0x7FFF);
//        break;
//    }
//
//    semStatus = xSemaphoreGive(statusRepositorySem);
//
//    return value;
//}
//
//char* sta_PayStateVarToString(STA_PayStateVar var_i){
//    char *pc;
//    switch(var_i){
//        case sta_pay_lagmuirProbe_isAlive:
//            pc = "sta_pay_lagmuirProbe_isAlive";
//            break;
//        case sta_pay_sensTemp_isAlive:
//            pc = "sta_pay_sensTemp_isAlive";
//            break;
//        case sta_pay_gps_isAlive:
//            pc = "sta_pay_gps_isAlive";
//            break;
//        case sta_pay_expFis_isAlive:
//            pc = "sta_pay_expFis_isAlive";
//            break;
//        case sta_pay_camera_isAlive:
//            pc = "sta_pay_camera_isAlive";
//            break;
//        case sta_pay_gyro_isAlive:
//            pc = "sta_pay_gyro_isAlive";
//            break;
//        case sta_pay_tmEstado_isAlive:
//            pc = "sta_pay_tmEstado_isAlive";
//            break;
//        case sta_pay_battery_isAlive:
//            pc = "sta_pay_battery_isAlive";
//            break;
//        case sta_pay_debug_isAlive:
//            pc = "sta_pay_debug_isAlive";
//            break;
//        case sta_pay_langmuirProbe_isDeployed:
//            pc = "sta_pay_lagmuirProbe_isDeployed";
//            break;
//
//    // FP2 variables
//        case sta_pay_langmuirProbe_state:
//            pc = "sta_pay_lagmuirProbe_state";
//            break;
//        case sta_pay_sensTemp_state:
//            pc = "sta_pay_sensTemp_state";
//            break;
//        case sta_pay_gps_state:
//            pc = "sta_pay_gps_state";
//            break;
//        case sta_pay_expFis_state:
//            pc = "sta_pay_expFis_state";
//            break;
//        case sta_pay_camera_state:
//            pc = "sta_pay_camera_state";
//            break;
//        case sta_pay_gyro_state:
//            pc = "sta_pay_gyro_state";
//            break;
//        case sta_pay_tmEstado_state:
//            pc = "sta_pay_tmEstado_state";
//            break;
//        case sta_pay_battery_state:
//            pc = "sta_pay_battery_state";
//            break;
//        case sta_pay_debug_state:
//            pc = "sta_pay_debug_state";
//            break;
//        default:
//            pc = "unknown PayStateVar";
//            break;
//    }
//    return pc;
//}
//
///**
// * Asocia el DAT_Payload_Buff pay_i a la STA_StateVar que controla la ejecucion o
// * o no de ese Payload
// * @param pay_i DAT_Payload del que quiero obtener el DAT_StateVar
// * @return DAT_StateVar dat_pay_xxx_perform
// */
//STA_PayStateVar sta_DAT_Payload_Buff_to_STA_PayStateVar(DAT_Payload_Buff pay_i){
////STA_StateVar sta_DAT_Payload_Buff_to_STA_StateVar(int pay_i){
//    STA_PayStateVar dat_pay_xxx_state;
//
//    switch(pay_i){
//        case dat_pay_langmuirProbe:
//            dat_pay_xxx_state = sta_pay_langmuirProbe_state;
//        break;
//        case dat_pay_sensTemp:
//            dat_pay_xxx_state = sta_pay_sensTemp_state;
//        break;
//        case dat_pay_gps:
//            dat_pay_xxx_state = sta_pay_gps_state;
//        break;
//        case dat_pay_gyro:
//            dat_pay_xxx_state = sta_pay_gyro_state;
//        break;
//        case dat_pay_expFis:
//            dat_pay_xxx_state = sta_pay_expFis_state;
//        break;
//        case dat_pay_camera:
//            dat_pay_xxx_state = sta_pay_camera_state;
//        break;
//        case dat_pay_tmEstado:
//            dat_pay_xxx_state = sta_pay_tmEstado_state;
//        break;
//        case dat_pay_battery:
//            dat_pay_xxx_state = sta_pay_battery_state;
//        break;
//        case dat_pay_debug:
//            dat_pay_xxx_state = sta_pay_debug_state;
//        break;
//        default:
//            dat_pay_xxx_state=-1;
//        break;
//    }
//
//    return dat_pay_xxx_state;
//}
