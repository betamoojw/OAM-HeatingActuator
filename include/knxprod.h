#pragma once


#define paramDelay(time) (uint32_t)( \
            (time & 0xC000) == 0xC000 ? (time & 0x3FFF) * 100 : \
            (time & 0xC000) == 0x0000 ? (time & 0x3FFF) * 1000 : \
            (time & 0xC000) == 0x4000 ? (time & 0x3FFF) * 60000 : \
            (time & 0xC000) == 0x8000 ? ((time & 0x3FFF) > 1000 ? 3600000 : \
                                         (time & 0x3FFF) * 3600000 ) : 0 )
                                             
#define ETS_ModuleId_NONE 0
#define ETS_ModuleId_BASE 1
#define ETS_ModuleId_UCT 2
#define ETS_ModuleId_CLI 3
#define ETS_ModuleId_HTA 4
#define ETS_ModuleId_WIRE 5
#define ETS_ModuleId_LOG 6
#define MAIN_FirmwareName "Heizungsaktor (dev)"
#define MAIN_OpenKnxId 0xAF
#define MAIN_ApplicationNumber 6
#define MAIN_ApplicationVersion 21
#define MAIN_ApplicationEncoding iso-8859-15
#define MAIN_ParameterSize 6010
#define MAIN_MaxKoNumber 1315
#define MAIN_OrderNumber "OpenKnxHeatingActuator"
#define BASE_ModuleVersion 24
#define UCT_ModuleVersion 5
#define CLI_ModuleVersion 1
#define HTA_ModuleVersion 1
#define WIRE_ModuleVersion 34
#define LOG_ModuleVersion 67
// Parameter with single occurrence


#define BASE_StartupDelayBase                     0      // 2 Bits, Bit 7-6
#define     BASE_StartupDelayBaseMask 0xC0
#define     BASE_StartupDelayBaseShift 6
#define BASE_StartupDelayTime                     0      // 14 Bits, Bit 13-0
#define     BASE_StartupDelayTimeMask 0x3FFF
#define     BASE_StartupDelayTimeShift 0
#define BASE_HeartbeatDelayBase                   2      // 2 Bits, Bit 7-6
#define     BASE_HeartbeatDelayBaseMask 0xC0
#define     BASE_HeartbeatDelayBaseShift 6
#define BASE_HeartbeatDelayTime                   2      // 14 Bits, Bit 13-0
#define     BASE_HeartbeatDelayTimeMask 0x3FFF
#define     BASE_HeartbeatDelayTimeShift 0
#define BASE_Timezone                             4      // 5 Bits, Bit 7-3
#define     BASE_TimezoneMask 0xF8
#define     BASE_TimezoneShift 3
#define BASE_CombinedTimeDate                     4      // 1 Bit, Bit 2
#define     BASE_CombinedTimeDateMask 0x04
#define     BASE_CombinedTimeDateShift 2
#define BASE_SummertimeAll                        4      // 2 Bits, Bit 1-0
#define     BASE_SummertimeAllMask 0x03
#define     BASE_SummertimeAllShift 0
#define BASE_SummertimeDE                         4      // 2 Bits, Bit 1-0
#define     BASE_SummertimeDEMask 0x03
#define     BASE_SummertimeDEShift 0
#define BASE_SummertimeWorld                      4      // 2 Bits, Bit 1-0
#define     BASE_SummertimeWorldMask 0x03
#define     BASE_SummertimeWorldShift 0
#define BASE_SummertimeKO                         4      // 2 Bits, Bit 1-0
#define     BASE_SummertimeKOMask 0x03
#define     BASE_SummertimeKOShift 0
#define BASE_TimezoneCustom                       5      // char*, 63 Byte
#define     BASE_TimezoneCustomLength 63
#define BASE_Latitude                            69      // float (4 Byte)
#define BASE_Longitude                           73      // float (4 Byte)
#define BASE_Diagnose                            78      // 1 Bit, Bit 7
#define     BASE_DiagnoseMask 0x80
#define     BASE_DiagnoseShift 7
#define BASE_Watchdog                            78      // 1 Bit, Bit 6
#define     BASE_WatchdogMask 0x40
#define     BASE_WatchdogShift 6
#define BASE_ReadTimeDate                        78      // 1 Bit, Bit 5
#define     BASE_ReadTimeDateMask 0x20
#define     BASE_ReadTimeDateShift 5
#define BASE_HeartbeatExtended                   78      // 1 Bit, Bit 4
#define     BASE_HeartbeatExtendedMask 0x10
#define     BASE_HeartbeatExtendedShift 4
#define BASE_InternalTime                        78      // 1 Bit, Bit 3
#define     BASE_InternalTimeMask 0x08
#define     BASE_InternalTimeShift 3
#define BASE_ManualSave                          78      // 3 Bits, Bit 2-0
#define     BASE_ManualSaveMask 0x07
#define     BASE_ManualSaveShift 0
#define BASE_PeriodicSave                        79      // 8 Bits, Bit 7-0
#define BASE_Info1LedFunc                        80      // 16 Bits, Bit 15-0
#define BASE_Info2LedFunc                        82      // 16 Bits, Bit 15-0
#define BASE_Info3LedFunc                        84      // 16 Bits, Bit 15-0
#define BASE_DefaultLedFunc                      86      // 1 Bit, Bit 7
#define     BASE_DefaultLedFuncMask 0x80
#define     BASE_DefaultLedFuncShift 7
#define BASE_Dummy                               109      // uint8_t
#define BASE_ModuleEnabled_UCT                   110      // 1 Bit, Bit 6
#define     BASE_ModuleEnabled_UCTMask 0x40
#define     BASE_ModuleEnabled_UCTShift 6
#define BASE_ModuleEnabled_CLI                   110      // 1 Bit, Bit 5
#define     BASE_ModuleEnabled_CLIMask 0x20
#define     BASE_ModuleEnabled_CLIShift 5
#define BASE_ModuleEnabled_HTA                   110      // 1 Bit, Bit 4
#define     BASE_ModuleEnabled_HTAMask 0x10
#define     BASE_ModuleEnabled_HTAShift 4
#define BASE_ModuleEnabled_WIRE                  110      // 1 Bit, Bit 3
#define     BASE_ModuleEnabled_WIREMask 0x08
#define     BASE_ModuleEnabled_WIREShift 3
#define BASE_ModuleEnabled_LOG                   110      // 1 Bit, Bit 2
#define     BASE_ModuleEnabled_LOGMask 0x04
#define     BASE_ModuleEnabled_LOGShift 2

// Zeitbasis
#define ParamBASE_StartupDelayBase                    ((knx.paramByte(BASE_StartupDelayBase) & BASE_StartupDelayBaseMask) >> BASE_StartupDelayBaseShift)
// Zeit
#define ParamBASE_StartupDelayTime                    (knx.paramWord(BASE_StartupDelayTime) & BASE_StartupDelayTimeMask)
// Zeit (in Millisekunden)
#define ParamBASE_StartupDelayTimeMS                  (paramDelay(knx.paramWord(BASE_StartupDelayTime)))
// Zeitbasis
#define ParamBASE_HeartbeatDelayBase                  ((knx.paramByte(BASE_HeartbeatDelayBase) & BASE_HeartbeatDelayBaseMask) >> BASE_HeartbeatDelayBaseShift)
// Zeit
#define ParamBASE_HeartbeatDelayTime                  (knx.paramWord(BASE_HeartbeatDelayTime) & BASE_HeartbeatDelayTimeMask)
// Zeit (in Millisekunden)
#define ParamBASE_HeartbeatDelayTimeMS                (paramDelay(knx.paramWord(BASE_HeartbeatDelayTime)))
// Zeitzone
#define ParamBASE_Timezone                            ((knx.paramByte(BASE_Timezone) & BASE_TimezoneMask) >> BASE_TimezoneShift)
// Empfangen über
#define ParamBASE_CombinedTimeDate                    ((bool)(knx.paramByte(BASE_CombinedTimeDate) & BASE_CombinedTimeDateMask))
// Sommerzeit ermitteln durch
#define ParamBASE_SummertimeAll                       (knx.paramByte(BASE_SummertimeAll) & BASE_SummertimeAllMask)
// Sommerzeit ermitteln durch
#define ParamBASE_SummertimeDE                        (knx.paramByte(BASE_SummertimeDE) & BASE_SummertimeDEMask)
// Sommerzeit ermitteln durch
#define ParamBASE_SummertimeWorld                     (knx.paramByte(BASE_SummertimeWorld) & BASE_SummertimeWorldMask)
// Sommerzeit ermitteln durch
#define ParamBASE_SummertimeKO                        (knx.paramByte(BASE_SummertimeKO) & BASE_SummertimeKOMask)
// POSIX TZ-String
#define ParamBASE_TimezoneCustom                      (knx.paramData(BASE_TimezoneCustom))
#define ParamBASE_TimezoneCustomStr                   (knx.paramString(BASE_TimezoneCustom, BASE_TimezoneCustomLength))
// Breitengrad
#define ParamBASE_Latitude                            (knx.paramFloat(BASE_Latitude, Float_Enc_IEEE754Single))
// Längengrad
#define ParamBASE_Longitude                           (knx.paramFloat(BASE_Longitude, Float_Enc_IEEE754Single))
// Diagnoseobjekt anzeigen
#define ParamBASE_Diagnose                            ((bool)(knx.paramByte(BASE_Diagnose) & BASE_DiagnoseMask))
// Watchdog aktivieren
#define ParamBASE_Watchdog                            ((bool)(knx.paramByte(BASE_Watchdog) & BASE_WatchdogMask))
// Bei Neustart vom Bus lesen
#define ParamBASE_ReadTimeDate                        ((bool)(knx.paramByte(BASE_ReadTimeDate) & BASE_ReadTimeDateMask))
// Erweitertes "In Betrieb"
#define ParamBASE_HeartbeatExtended                   ((bool)(knx.paramByte(BASE_HeartbeatExtended) & BASE_HeartbeatExtendedMask))
// InternalTime
#define ParamBASE_InternalTime                        ((bool)(knx.paramByte(BASE_InternalTime) & BASE_InternalTimeMask))
// Manuelles speichern
#define ParamBASE_ManualSave                          (knx.paramByte(BASE_ManualSave) & BASE_ManualSaveMask)
// Zyklisches speichern
#define ParamBASE_PeriodicSave                        (knx.paramByte(BASE_PeriodicSave))
// Info1
#define ParamBASE_Info1LedFunc                        (knx.paramWord(BASE_Info1LedFunc))
// Info2
#define ParamBASE_Info2LedFunc                        (knx.paramWord(BASE_Info2LedFunc))
// Info3
#define ParamBASE_Info3LedFunc                        (knx.paramWord(BASE_Info3LedFunc))
// 
#define ParamBASE_DefaultLedFunc                      ((bool)(knx.paramByte(BASE_DefaultLedFunc) & BASE_DefaultLedFuncMask))
// 
#define ParamBASE_Dummy                               (knx.paramByte(BASE_Dummy))
// UCT
#define ParamBASE_ModuleEnabled_UCT                   ((bool)(knx.paramByte(BASE_ModuleEnabled_UCT) & BASE_ModuleEnabled_UCTMask))
// CLI
#define ParamBASE_ModuleEnabled_CLI                   ((bool)(knx.paramByte(BASE_ModuleEnabled_CLI) & BASE_ModuleEnabled_CLIMask))
// HTA
#define ParamBASE_ModuleEnabled_HTA                   ((bool)(knx.paramByte(BASE_ModuleEnabled_HTA) & BASE_ModuleEnabled_HTAMask))
// WIRE
#define ParamBASE_ModuleEnabled_WIRE                  ((bool)(knx.paramByte(BASE_ModuleEnabled_WIRE) & BASE_ModuleEnabled_WIREMask))
// LOG
#define ParamBASE_ModuleEnabled_LOG                   ((bool)(knx.paramByte(BASE_ModuleEnabled_LOG) & BASE_ModuleEnabled_LOGMask))

#define BASE_KoHeartbeat 1
#define BASE_KoTime 2
#define BASE_KoDate 3
#define BASE_KoDateTime 4
#define BASE_KoIsSummertime 5
#define BASE_KoManualSave 6
#define BASE_KoDiagnose 7

// In Betrieb
#define KoBASE_Heartbeat                           (knx.getGroupObject(BASE_KoHeartbeat))
// Uhrzeit
#define KoBASE_Time                                (knx.getGroupObject(BASE_KoTime))
// Datum
#define KoBASE_Date                                (knx.getGroupObject(BASE_KoDate))
// Uhrzeit/Datum
#define KoBASE_DateTime                            (knx.getGroupObject(BASE_KoDateTime))
// Sommerzeit aktiv
#define KoBASE_IsSummertime                        (knx.getGroupObject(BASE_KoIsSummertime))
// Speichern
#define KoBASE_ManualSave                          (knx.getGroupObject(BASE_KoManualSave))
// Diagnose
#define KoBASE_Diagnose                            (knx.getGroupObject(BASE_KoDiagnose))



#define CLI_VisibleChannels                     114      // uint8_t
#define CLI_SummerWinterKo                      115      // 1 Bit, Bit 7
#define     CLI_SummerWinterKoMask 0x80
#define     CLI_SummerWinterKoShift 7
#define CLI_SummerWinterDate                    115      // 1 Bit, Bit 6
#define     CLI_SummerWinterDateMask 0x40
#define     CLI_SummerWinterDateShift 6
#define CLI_SummerWinterDayTemp                 115      // 1 Bit, Bit 5
#define     CLI_SummerWinterDayTempMask 0x20
#define     CLI_SummerWinterDayTempShift 5
#define CLI_AverageTempCalc                     116      // 4 Bits, Bit 7-4
#define     CLI_AverageTempCalcMask 0xF0
#define     CLI_AverageTempCalcShift 4
#define CLI_SendReadRequest                     116      // 1 Bit, Bit 3
#define     CLI_SendReadRequestMask 0x08
#define     CLI_SendReadRequestShift 3
#define CLI_AverageTempSummer                   117      // uint8_t
#define CLI_AverageDaysSummer                   118      // 4 Bits, Bit 7-4
#define     CLI_AverageDaysSummerMask 0xF0
#define     CLI_AverageDaysSummerShift 4
#define CLI_AverageTempWinter                   119      // uint8_t
#define CLI_AverageDaysWinter                   120      // 4 Bits, Bit 7-4
#define     CLI_AverageDaysWinterMask 0xF0
#define     CLI_AverageDaysWinterShift 4
#define CLI_SummerTimeStartDay                  121      // 24 Bits, Bit 31-8
#define     CLI_SummerTimeStartDayMask 0xFFFFFF00
#define     CLI_SummerTimeStartDayShift 8
#define CLI_WinterTimeStartDay                  124      // 24 Bits, Bit 31-8
#define     CLI_WinterTimeStartDayMask 0xFFFFFF00
#define     CLI_WinterTimeStartDayShift 8
#define CLI_SummerModeChange                    127      // 8 Bits, Bit 7-0
#define CLI_WinterModeChange                    128      // 8 Bits, Bit 7-0

// Anzahl der Räume
#define ParamCLI_VisibleChannels                     (knx.paramByte(CLI_VisibleChannels))
// Objekt
#define ParamCLI_SummerWinterKo                      ((bool)(knx.paramByte(CLI_SummerWinterKo) & CLI_SummerWinterKoMask))
// Datum
#define ParamCLI_SummerWinterDate                    ((bool)(knx.paramByte(CLI_SummerWinterDate) & CLI_SummerWinterDateMask))
// 24h Temperaturdurchschnitt
#define ParamCLI_SummerWinterDayTemp                 ((bool)(knx.paramByte(CLI_SummerWinterDayTemp) & CLI_SummerWinterDayTempMask))
// Berechnung
#define ParamCLI_AverageTempCalc                     (PT_CLIAverageTemperatureCalculation)((knx.paramByte(CLI_AverageTempCalc) & CLI_AverageTempCalcMask) >> CLI_AverageTempCalcShift)
// Leseanfrage zum Berechnungszeitpunkt senden
#define ParamCLI_SendReadRequest                     ((bool)(knx.paramByte(CLI_SendReadRequest) & CLI_SendReadRequestMask))
// Sommer bei ≥
#define ParamCLI_AverageTempSummer                   (knx.paramByte(CLI_AverageTempSummer))
// für
#define ParamCLI_AverageDaysSummer                   ((knx.paramByte(CLI_AverageDaysSummer) & CLI_AverageDaysSummerMask) >> CLI_AverageDaysSummerShift)
// Winter bei ≤
#define ParamCLI_AverageTempWinter                   (knx.paramByte(CLI_AverageTempWinter))
// für
#define ParamCLI_AverageDaysWinter                   ((knx.paramByte(CLI_AverageDaysWinter) & CLI_AverageDaysWinterMask) >> CLI_AverageDaysWinterShift)
// Sommerbetrieb ab
#define ParamCLI_SummerTimeStartDay                  ((knx.paramInt(CLI_SummerTimeStartDay) & CLI_SummerTimeStartDayMask) >> CLI_SummerTimeStartDayShift)
// Winterbetrieb ab
#define ParamCLI_WinterTimeStartDay                  ((knx.paramInt(CLI_WinterTimeStartDay) & CLI_WinterTimeStartDayMask) >> CLI_WinterTimeStartDayShift)
// Bei Sommerbetriebsstart Wechsel auf
#define ParamCLI_SummerModeChange                    (PT_CLIModeChange)(knx.paramByte(CLI_SummerModeChange))
// Bei Winterbetriebsstart Wechsel auf
#define ParamCLI_WinterModeChange                    (PT_CLIModeChange)(knx.paramByte(CLI_WinterModeChange))

#define CLI_KoWinter 790
#define CLI_KoWinterStatus 791
#define CLI_KoOutsideTemp 792
#define CLI_KoDayAverage 793

// Sommer- / Winterbetrieb
#define KoCLI_Winter                              (knx.getGroupObject(CLI_KoWinter))
// Sommer- / Winterbetrieb Status
#define KoCLI_WinterStatus                        (knx.getGroupObject(CLI_KoWinterStatus))
// Außentemperatur
#define KoCLI_OutsideTemp                         (knx.getGroupObject(CLI_KoOutsideTemp))
// 
#define KoCLI_DayAverage                          (knx.getGroupObject(CLI_KoDayAverage))

#define CLI_ChannelCount 12

// Parameter per channel
#define CLI_ParamBlockOffset 129
#define CLI_ParamBlockSize 75
#define CLI_ParamCalcIndex(index) (index + CLI_ParamBlockOffset + _channelIndex * CLI_ParamBlockSize)

#define CLI_CHChannelDisabled                    0      // 1 Bit, Bit 7
#define     CLI_CHChannelDisabledMask 0x80
#define     CLI_CHChannelDisabledShift 7
#define CLI_CHKOForRelativTempChange             0      // 1 Bit, Bit 6
#define     CLI_CHKOForRelativTempChangeMask 0x40
#define     CLI_CHKOForRelativTempChangeShift 6
#define CLI_CHModeSelectionTurnOn                0      // 1 Bit, Bit 5
#define     CLI_CHModeSelectionTurnOnMask 0x20
#define     CLI_CHModeSelectionTurnOnShift 5
#define CLI_CHTargetLimitHandling                0      // 1 Bit, Bit 4
#define     CLI_CHTargetLimitHandlingMask 0x10
#define     CLI_CHTargetLimitHandlingShift 4
#define CLI_CHModeFeedbackReturnOff              0      // 1 Bit, Bit 3
#define     CLI_CHModeFeedbackReturnOffMask 0x08
#define     CLI_CHModeFeedbackReturnOffShift 3
#define CLI_CHRelativTempChangeHeating           1      // 8 Bits, Bit 7-0
#define CLI_CHTargetMinHeating                   2      // float (2 Byte)
#define CLI_CHTargetMaxHeating                   4      // float (2 Byte)
#define CLI_CHTargetDefaultHeating               6      // float (2 Byte)
#define CLI_CHTargetMinCooling                   8      // float (2 Byte)
#define CLI_CHTargetMaxCooling                  10      // float (2 Byte)
#define CLI_CHTargetDefaultCooling              12      // float (2 Byte)
#define CLI_CHInitTemp                          14      // 4 Bits, Bit 7-4
#define     CLI_CHInitTempMask 0xF0
#define     CLI_CHInitTempShift 4
#define CLI_CHDefaultMode                       15      // 8 Bits, Bit 7-0
#define CLI_CHInitMode                          16      // 4 Bits, Bit 7-4
#define     CLI_CHInitModeMask 0xF0
#define     CLI_CHInitModeShift 4
#define CLI_CHInitPower                         17      // 4 Bits, Bit 7-4
#define     CLI_CHInitPowerMask 0xF0
#define     CLI_CHInitPowerShift 4
#define CLI_CHDefaultPower                      17      // 1 Bit, Bit 3
#define     CLI_CHDefaultPowerMask 0x08
#define     CLI_CHDefaultPowerShift 3
#define CLI_CH2TargetTemp                       17      // 1 Bit, Bit 2
#define     CLI_CH2TargetTempMask 0x04
#define     CLI_CH2TargetTempShift 2
#define CLI_CHRelativTempChangeCooling          18      // 8 Bits, Bit 7-0
#define CLI_CHControlMode1                      20      // 4 Bits, Bit 7-4
#define     CLI_CHControlMode1Mask 0xF0
#define     CLI_CHControlMode1Shift 4
#define CLI_CHControlTemperature1               20      // 4 Bits, Bit 3-0
#define     CLI_CHControlTemperature1Mask 0x0F
#define     CLI_CHControlTemperature1Shift 0
#define CLI_CHFullPowerOff1                     21      // 1 Bit, Bit 7
#define     CLI_CHFullPowerOff1Mask 0x80
#define     CLI_CHFullPowerOff1Shift 7
#define CLI_CHWaitTimeAfterPowerUp1             21      // 7 Bits, Bit 6-0
#define     CLI_CHWaitTimeAfterPowerUp1Mask 0x7F
#define     CLI_CHWaitTimeAfterPowerUp1Shift 0
#define CLI_CHPIPreset1                         22      // 4 Bits, Bit 7-4
#define     CLI_CHPIPreset1Mask 0xF0
#define     CLI_CHPIPreset1Shift 4
#define CLI_CHPII1                              23      // uint8_t
#define CLI_CHPID1                              24      // uint8_t
#define CLI_CHTargetTempRounding1               25      // 4 Bits, Bit 7-4
#define     CLI_CHTargetTempRounding1Mask 0xF0
#define     CLI_CHTargetTempRounding1Shift 4
#define CLI_CHIsActive1                         25      // 2 Bits, Bit 3-2
#define     CLI_CHIsActive1Mask 0x0C
#define     CLI_CHIsActive1Shift 2
#define CLI_CHPWM1                              26      // uint16_t
#define CLI_CHControlMode2                      28      // 4 Bits, Bit 7-4
#define     CLI_CHControlMode2Mask 0xF0
#define     CLI_CHControlMode2Shift 4
#define CLI_CHControlTemperature2               28      // 4 Bits, Bit 3-0
#define     CLI_CHControlTemperature2Mask 0x0F
#define     CLI_CHControlTemperature2Shift 0
#define CLI_CHFullPowerOff2                     29      // 1 Bit, Bit 7
#define     CLI_CHFullPowerOff2Mask 0x80
#define     CLI_CHFullPowerOff2Shift 7
#define CLI_CHWaitTimeAfterPowerUp2             29      // 7 Bits, Bit 6-0
#define     CLI_CHWaitTimeAfterPowerUp2Mask 0x7F
#define     CLI_CHWaitTimeAfterPowerUp2Shift 0
#define CLI_CHPIPreset2                         30      // 4 Bits, Bit 7-4
#define     CLI_CHPIPreset2Mask 0xF0
#define     CLI_CHPIPreset2Shift 4
#define CLI_CHPII2                              31      // uint8_t
#define CLI_CHPID2                              32      // uint8_t
#define CLI_CHTargetTempRounding2               33      // 4 Bits, Bit 7-4
#define     CLI_CHTargetTempRounding2Mask 0xF0
#define     CLI_CHTargetTempRounding2Shift 4
#define CLI_CHIsActive2                         33      // 2 Bits, Bit 3-2
#define     CLI_CHIsActive2Mask 0x0C
#define     CLI_CHIsActive2Shift 2
#define CLI_CHPWM2                              34      // uint16_t
#define CLI_CHCoolDeviceSelection               36      // 4 Bits, Bit 7-4
#define     CLI_CHCoolDeviceSelectionMask 0xF0
#define     CLI_CHCoolDeviceSelectionShift 4
#define CLI_CHCoolDeactiveInWinter              37      // 1 Bit, Bit 7
#define     CLI_CHCoolDeactiveInWinterMask 0x80
#define     CLI_CHCoolDeactiveInWinterShift 7
#define CLI_CHHeatDeviceSelection               38      // 4 Bits, Bit 7-4
#define     CLI_CHHeatDeviceSelectionMask 0xF0
#define     CLI_CHHeatDeviceSelectionShift 4
#define CLI_CHHeatDeactiveInSummer              39      // 1 Bit, Bit 7
#define     CLI_CHHeatDeactiveInSummerMask 0x80
#define     CLI_CHHeatDeactiveInSummerShift 7
#define CLI_CHDehumDeviceSelection              40      // 4 Bits, Bit 7-4
#define     CLI_CHDehumDeviceSelectionMask 0xF0
#define     CLI_CHDehumDeviceSelectionShift 4
#define CLI_CHFanDeviceSelection                42      // 4 Bits, Bit 7-4
#define     CLI_CHFanDeviceSelectionMask 0xF0
#define     CLI_CHFanDeviceSelectionShift 4
#define CLI_CHAutoDeviceSelection               44      // 4 Bits, Bit 7-4
#define     CLI_CHAutoDeviceSelectionMask 0xF0
#define     CLI_CHAutoDeviceSelectionShift 4
#define CLI_CHAutoCoolDeviceSelection           45      // 4 Bits, Bit 7-4
#define     CLI_CHAutoCoolDeviceSelectionMask 0xF0
#define     CLI_CHAutoCoolDeviceSelectionShift 4
#define CLI_CHAutoHeatDeviceSelection           45      // 4 Bits, Bit 3-0
#define     CLI_CHAutoHeatDeviceSelectionMask 0x0F
#define     CLI_CHAutoHeatDeviceSelectionShift 0
#define CLI_CHAutoDehumDeviceSelection          46      // 4 Bits, Bit 7-4
#define     CLI_CHAutoDehumDeviceSelectionMask 0xF0
#define     CLI_CHAutoDehumDeviceSelectionShift 4
#define CLI_CHAutoFanDeviceSelection            46      // 4 Bits, Bit 3-0
#define     CLI_CHAutoFanDeviceSelectionMask 0x0F
#define     CLI_CHAutoFanDeviceSelectionShift 0
#define CLI_CHBehaviorOnDeviceChange            47      // 4 Bits, Bit 7-4
#define     CLI_CHBehaviorOnDeviceChangeMask 0xF0
#define     CLI_CHBehaviorOnDeviceChangeShift 4
#define CLI_CHCoolingWinterAllowed              47      // 1 Bit, Bit 3
#define     CLI_CHCoolingWinterAllowedMask 0x08
#define     CLI_CHCoolingWinterAllowedShift 3
#define CLI_CHHeatingSummerAllowed              47      // 1 Bit, Bit 2
#define     CLI_CHHeatingSummerAllowedMask 0x04
#define     CLI_CHHeatingSummerAllowedShift 2
#define CLI_CHFallbackAutoWaitTimeDelayBase     48      // 2 Bits, Bit 7-6
#define     CLI_CHFallbackAutoWaitTimeDelayBaseMask 0xC0
#define     CLI_CHFallbackAutoWaitTimeDelayBaseShift 6
#define CLI_CHFallbackAutoWaitTimeDelayTime     48      // 14 Bits, Bit 13-0
#define     CLI_CHFallbackAutoWaitTimeDelayTimeMask 0x3FFF
#define     CLI_CHFallbackAutoWaitTimeDelayTimeShift 0
#define CLI_CHHysteresisCooling                 50      // 4 Bits, Bit 7-4
#define     CLI_CHHysteresisCoolingMask 0xF0
#define     CLI_CHHysteresisCoolingShift 4
#define CLI_CHHysteresisHeating                 50      // 4 Bits, Bit 3-0
#define     CLI_CHHysteresisHeatingMask 0x0F
#define     CLI_CHHysteresisHeatingShift 0
#define CLI_CHWindowOpenEnabled                 51      // 1 Bit, Bit 7
#define     CLI_CHWindowOpenEnabledMask 0x80
#define     CLI_CHWindowOpenEnabledShift 7
#define CLI_CHWindowOpenCondition1              52      // 4 Bits, Bit 7-4
#define     CLI_CHWindowOpenCondition1Mask 0xF0
#define     CLI_CHWindowOpenCondition1Shift 4
#define CLI_CHWindowOpenAction1                 52      // 4 Bits, Bit 3-0
#define     CLI_CHWindowOpenAction1Mask 0x0F
#define     CLI_CHWindowOpenAction1Shift 0
#define CLI_CHWindowOpenDelayBase1              53      // 2 Bits, Bit 7-6
#define     CLI_CHWindowOpenDelayBase1Mask 0xC0
#define     CLI_CHWindowOpenDelayBase1Shift 6
#define CLI_CHWindowOpenDelayTime1              53      // 14 Bits, Bit 13-0
#define     CLI_CHWindowOpenDelayTime1Mask 0x3FFF
#define     CLI_CHWindowOpenDelayTime1Shift 0
#define CLI_CHWindowOpenTempCorrection1         55      // 8 Bits, Bit 7-0
#define CLI_CHWindowOpenCondition2              56      // 4 Bits, Bit 7-4
#define     CLI_CHWindowOpenCondition2Mask 0xF0
#define     CLI_CHWindowOpenCondition2Shift 4
#define CLI_CHWindowOpenAction2                 56      // 4 Bits, Bit 3-0
#define     CLI_CHWindowOpenAction2Mask 0x0F
#define     CLI_CHWindowOpenAction2Shift 0
#define CLI_CHWindowOpenDelayBase2              57      // 2 Bits, Bit 7-6
#define     CLI_CHWindowOpenDelayBase2Mask 0xC0
#define     CLI_CHWindowOpenDelayBase2Shift 6
#define CLI_CHWindowOpenDelayTime2              57      // 14 Bits, Bit 13-0
#define     CLI_CHWindowOpenDelayTime2Mask 0x3FFF
#define     CLI_CHWindowOpenDelayTime2Shift 0
#define CLI_CHWindowOpenTempCorrection2         59      // 8 Bits, Bit 7-0
#define CLI_CHWindowOpenCondition3              60      // 4 Bits, Bit 7-4
#define     CLI_CHWindowOpenCondition3Mask 0xF0
#define     CLI_CHWindowOpenCondition3Shift 4
#define CLI_CHWindowOpenAction3                 60      // 4 Bits, Bit 3-0
#define     CLI_CHWindowOpenAction3Mask 0x0F
#define     CLI_CHWindowOpenAction3Shift 0
#define CLI_CHWindowOpenDelayBase3              61      // 2 Bits, Bit 7-6
#define     CLI_CHWindowOpenDelayBase3Mask 0xC0
#define     CLI_CHWindowOpenDelayBase3Shift 6
#define CLI_CHWindowOpenDelayTime3              61      // 14 Bits, Bit 13-0
#define     CLI_CHWindowOpenDelayTime3Mask 0x3FFF
#define     CLI_CHWindowOpenDelayTime3Shift 0
#define CLI_CHWindowOpenTempCorrection3         63      // 8 Bits, Bit 7-0
#define CLI_CHWindowOpenCondition4              64      // 4 Bits, Bit 7-4
#define     CLI_CHWindowOpenCondition4Mask 0xF0
#define     CLI_CHWindowOpenCondition4Shift 4
#define CLI_CHWindowOpenAction4                 64      // 4 Bits, Bit 3-0
#define     CLI_CHWindowOpenAction4Mask 0x0F
#define     CLI_CHWindowOpenAction4Shift 0
#define CLI_CHWindowOpenDelayBase4              65      // 2 Bits, Bit 7-6
#define     CLI_CHWindowOpenDelayBase4Mask 0xC0
#define     CLI_CHWindowOpenDelayBase4Shift 6
#define CLI_CHWindowOpenDelayTime4              65      // 14 Bits, Bit 13-0
#define     CLI_CHWindowOpenDelayTime4Mask 0x3FFF
#define     CLI_CHWindowOpenDelayTime4Shift 0
#define CLI_CHWindowOpenTempCorrection4         67      // 8 Bits, Bit 7-0
#define CLI_CHWindowOpenCondition5              68      // 4 Bits, Bit 7-4
#define     CLI_CHWindowOpenCondition5Mask 0xF0
#define     CLI_CHWindowOpenCondition5Shift 4
#define CLI_CHWindowOpenAction5                 68      // 4 Bits, Bit 3-0
#define     CLI_CHWindowOpenAction5Mask 0x0F
#define     CLI_CHWindowOpenAction5Shift 0
#define CLI_CHWindowOpenDelayBase5              69      // 2 Bits, Bit 7-6
#define     CLI_CHWindowOpenDelayBase5Mask 0xC0
#define     CLI_CHWindowOpenDelayBase5Shift 6
#define CLI_CHWindowOpenDelayTime5              69      // 14 Bits, Bit 13-0
#define     CLI_CHWindowOpenDelayTime5Mask 0x3FFF
#define     CLI_CHWindowOpenDelayTime5Shift 0
#define CLI_CHWindowOpenTempCorrection5         71      // 8 Bits, Bit 7-0
#define CLI_CHWindowClose                       72      // 1 Bit, Bit 7
#define     CLI_CHWindowCloseMask 0x80
#define     CLI_CHWindowCloseShift 7
#define CLI_CHWindowCloseWaitTimeDelayBase      73      // 2 Bits, Bit 7-6
#define     CLI_CHWindowCloseWaitTimeDelayBaseMask 0xC0
#define     CLI_CHWindowCloseWaitTimeDelayBaseShift 6
#define CLI_CHWindowCloseWaitTimeDelayTime      73      // 14 Bits, Bit 13-0
#define     CLI_CHWindowCloseWaitTimeDelayTimeMask 0x3FFF
#define     CLI_CHWindowCloseWaitTimeDelayTimeShift 0

// Kanal deaktivieren (zu Testzwecken)
#define ParamCLI_CHChannelDisabled                   ((bool)(knx.paramByte(CLI_ParamCalcIndex(CLI_CHChannelDisabled)) & CLI_CHChannelDisabledMask))
// Objekt für relative Solltemperaturänderung
#define ParamCLI_CHKOForRelativTempChange            ((bool)(knx.paramByte(CLI_ParamCalcIndex(CLI_CHKOForRelativTempChange)) & CLI_CHKOForRelativTempChangeMask))
// Modus Auswahl schaltet EIN
#define ParamCLI_CHModeSelectionTurnOn               ((bool)(knx.paramByte(CLI_ParamCalcIndex(CLI_CHModeSelectionTurnOn)) & CLI_CHModeSelectionTurnOnMask))
// Bei ungültiger Solltemperaturvorgabe
#define ParamCLI_CHTargetLimitHandling               (PT_CLITargetLimitHandling)((knx.paramByte(CLI_ParamCalcIndex(CLI_CHTargetLimitHandling)) & CLI_CHTargetLimitHandlingMask) >> CLI_CHTargetLimitHandlingShift)
// 'Modus Aktueller Status' bei AUS
#define ParamCLI_CHModeFeedbackReturnOff             (PT_CLIModeFeedback)((knx.paramByte(CLI_ParamCalcIndex(CLI_CHModeFeedbackReturnOff)) & CLI_CHModeFeedbackReturnOffMask) >> CLI_CHModeFeedbackReturnOffShift)
// Erhöhen / Verringern um
#define ParamCLI_CHRelativTempChangeHeating          (knx.paramByte(CLI_ParamCalcIndex(CLI_CHRelativTempChangeHeating)))
// Minimal
#define ParamCLI_CHTargetMinHeating                  (knx.paramFloat(CLI_ParamCalcIndex(CLI_CHTargetMinHeating), Float_Enc_DPT9))
// Maximal
#define ParamCLI_CHTargetMaxHeating                  (knx.paramFloat(CLI_ParamCalcIndex(CLI_CHTargetMaxHeating), Float_Enc_DPT9))
// Initialwert
#define ParamCLI_CHTargetDefaultHeating              (knx.paramFloat(CLI_ParamCalcIndex(CLI_CHTargetDefaultHeating), Float_Enc_DPT9))
// Minimal
#define ParamCLI_CHTargetMinCooling                  (knx.paramFloat(CLI_ParamCalcIndex(CLI_CHTargetMinCooling), Float_Enc_DPT9))
// Maximal
#define ParamCLI_CHTargetMaxCooling                  (knx.paramFloat(CLI_ParamCalcIndex(CLI_CHTargetMaxCooling), Float_Enc_DPT9))
// Initialwert
#define ParamCLI_CHTargetDefaultCooling              (knx.paramFloat(CLI_ParamCalcIndex(CLI_CHTargetDefaultCooling), Float_Enc_DPT9))
// Nach Gerätestart
#define ParamCLI_CHInitTemp                          (PT_CLIInit)((knx.paramByte(CLI_ParamCalcIndex(CLI_CHInitTemp)) & CLI_CHInitTempMask) >> CLI_CHInitTempShift)
// Initialwert
#define ParamCLI_CHDefaultMode                       (PT_CLIDefaultHVAC)(knx.paramByte(CLI_ParamCalcIndex(CLI_CHDefaultMode)))
// Nach Gerätestart
#define ParamCLI_CHInitMode                          (PT_CLIInit)((knx.paramByte(CLI_ParamCalcIndex(CLI_CHInitMode)) & CLI_CHInitModeMask) >> CLI_CHInitModeShift)
// Nach Gerätestart
#define ParamCLI_CHInitPower                         (PT_CLIInit)((knx.paramByte(CLI_ParamCalcIndex(CLI_CHInitPower)) & CLI_CHInitPowerMask) >> CLI_CHInitPowerShift)
// Initialwert
#define ParamCLI_CHDefaultPower                      ((bool)(knx.paramByte(CLI_ParamCalcIndex(CLI_CHDefaultPower)) & CLI_CHDefaultPowerMask))
// Getrennte Solltemperatur für Heiz- und Kühlbetrieb
#define ParamCLI_CH2TargetTemp                       ((bool)(knx.paramByte(CLI_ParamCalcIndex(CLI_CH2TargetTemp)) & CLI_CH2TargetTempMask))
// Erhöhen / Verringern um
#define ParamCLI_CHRelativTempChangeCooling          (knx.paramByte(CLI_ParamCalcIndex(CLI_CHRelativTempChangeCooling)))
// Modusauswahl über
#define ParamCLI_CHControlMode1                      (PT_CLIControlMode)((knx.paramByte(CLI_ParamCalcIndex(CLI_CHControlMode1)) & CLI_CHControlMode1Mask) >> CLI_CHControlMode1Shift)
// Temperaturregelung über
#define ParamCLI_CHControlTemperature1               (PT_CLIControlTemperature)(knx.paramByte(CLI_ParamCalcIndex(CLI_CHControlTemperature1)) & CLI_CHControlTemperature1Mask)
// Objekt zum vollständigen Ein-/Ausschalten
#define ParamCLI_CHFullPowerOff1                     ((bool)(knx.paramByte(CLI_ParamCalcIndex(CLI_CHFullPowerOff1)) & CLI_CHFullPowerOff1Mask))
// Wartezeit nach Einschalten
#define ParamCLI_CHWaitTimeAfterPowerUp1             (PT_CLIWaitTimeAfterPowerUp)(knx.paramByte(CLI_ParamCalcIndex(CLI_CHWaitTimeAfterPowerUp1)) & CLI_CHWaitTimeAfterPowerUp1Mask)
// Heizungstyp
#define ParamCLI_CHPIPreset1                         (PT_CLIPIPreset)((knx.paramByte(CLI_ParamCalcIndex(CLI_CHPIPreset1)) & CLI_CHPIPreset1Mask) >> CLI_CHPIPreset1Shift)
// Proportional
#define ParamCLI_CHPII1                              (knx.paramByte(CLI_ParamCalcIndex(CLI_CHPII1)))
// Nachstellzeit
#define ParamCLI_CHPID1                              (knx.paramByte(CLI_ParamCalcIndex(CLI_CHPID1)))
// Maximale Genauigkeit der Solltemperatur
#define ParamCLI_CHTargetTempRounding1               ((knx.paramByte(CLI_ParamCalcIndex(CLI_CHTargetTempRounding1)) & CLI_CHTargetTempRounding1Mask) >> CLI_CHTargetTempRounding1Shift)
// Ist Aktiv Rückmeldung
#define ParamCLI_CHIsActive1                         (PT_CLIIsActive)((knx.paramByte(CLI_ParamCalcIndex(CLI_CHIsActive1)) & CLI_CHIsActive1Mask) >> CLI_CHIsActive1Shift)
// Pulsweitenmodulation Periode
#define ParamCLI_CHPWM1                              (knx.paramWord(CLI_ParamCalcIndex(CLI_CHPWM1)))
// Modusauswahl über
#define ParamCLI_CHControlMode2                      (PT_CLIControlMode)((knx.paramByte(CLI_ParamCalcIndex(CLI_CHControlMode2)) & CLI_CHControlMode2Mask) >> CLI_CHControlMode2Shift)
// Temperaturregelung über
#define ParamCLI_CHControlTemperature2               (PT_CLIControlTemperature)(knx.paramByte(CLI_ParamCalcIndex(CLI_CHControlTemperature2)) & CLI_CHControlTemperature2Mask)
// Objekt zum vollständigen Ein-/Ausschalten
#define ParamCLI_CHFullPowerOff2                     ((bool)(knx.paramByte(CLI_ParamCalcIndex(CLI_CHFullPowerOff2)) & CLI_CHFullPowerOff2Mask))
// Wartezeit nach Einschalten
#define ParamCLI_CHWaitTimeAfterPowerUp2             (PT_CLIWaitTimeAfterPowerUp)(knx.paramByte(CLI_ParamCalcIndex(CLI_CHWaitTimeAfterPowerUp2)) & CLI_CHWaitTimeAfterPowerUp2Mask)
// Heizungstyp
#define ParamCLI_CHPIPreset2                         (PT_CLIPIPreset)((knx.paramByte(CLI_ParamCalcIndex(CLI_CHPIPreset2)) & CLI_CHPIPreset2Mask) >> CLI_CHPIPreset2Shift)
// Proportional
#define ParamCLI_CHPII2                              (knx.paramByte(CLI_ParamCalcIndex(CLI_CHPII2)))
// Nachstellzeit
#define ParamCLI_CHPID2                              (knx.paramByte(CLI_ParamCalcIndex(CLI_CHPID2)))
// Maximale Genauigkeit der Solltemperatur
#define ParamCLI_CHTargetTempRounding2               ((knx.paramByte(CLI_ParamCalcIndex(CLI_CHTargetTempRounding2)) & CLI_CHTargetTempRounding2Mask) >> CLI_CHTargetTempRounding2Shift)
// Ist Aktiv Rückmeldung
#define ParamCLI_CHIsActive2                         (PT_CLIIsActive)((knx.paramByte(CLI_ParamCalcIndex(CLI_CHIsActive2)) & CLI_CHIsActive2Mask) >> CLI_CHIsActive2Shift)
// Pulsweitenmodulation Periode
#define ParamCLI_CHPWM2                              (knx.paramWord(CLI_ParamCalcIndex(CLI_CHPWM2)))
// Durch
#define ParamCLI_CHCoolDeviceSelection               (PT_CLIDeviceSelection)((knx.paramByte(CLI_ParamCalcIndex(CLI_CHCoolDeviceSelection)) & CLI_CHCoolDeviceSelectionMask) >> CLI_CHCoolDeviceSelectionShift)
// Kühlen im Winterbetrieb gesperrt
#define ParamCLI_CHCoolDeactiveInWinter              ((bool)(knx.paramByte(CLI_ParamCalcIndex(CLI_CHCoolDeactiveInWinter)) & CLI_CHCoolDeactiveInWinterMask))
// Durch
#define ParamCLI_CHHeatDeviceSelection               (PT_CLIDeviceSelection)((knx.paramByte(CLI_ParamCalcIndex(CLI_CHHeatDeviceSelection)) & CLI_CHHeatDeviceSelectionMask) >> CLI_CHHeatDeviceSelectionShift)
// Heizen im Sommerbetrieb gesperrt
#define ParamCLI_CHHeatDeactiveInSummer              ((bool)(knx.paramByte(CLI_ParamCalcIndex(CLI_CHHeatDeactiveInSummer)) & CLI_CHHeatDeactiveInSummerMask))
// Durch
#define ParamCLI_CHDehumDeviceSelection              (PT_CLIDeviceSelection)((knx.paramByte(CLI_ParamCalcIndex(CLI_CHDehumDeviceSelection)) & CLI_CHDehumDeviceSelectionMask) >> CLI_CHDehumDeviceSelectionShift)
// Durch
#define ParamCLI_CHFanDeviceSelection                (PT_CLIDeviceSelection)((knx.paramByte(CLI_ParamCalcIndex(CLI_CHFanDeviceSelection)) & CLI_CHFanDeviceSelectionMask) >> CLI_CHFanDeviceSelectionShift)
// Durch
#define ParamCLI_CHAutoDeviceSelection               (PT_CLIDeviceSelection)((knx.paramByte(CLI_ParamCalcIndex(CLI_CHAutoDeviceSelection)) & CLI_CHAutoDeviceSelectionMask) >> CLI_CHAutoDeviceSelectionShift)
// Kühlen Auswahl durch
#define ParamCLI_CHAutoCoolDeviceSelection           (PT_CLIAutomaticDevice)((knx.paramByte(CLI_ParamCalcIndex(CLI_CHAutoCoolDeviceSelection)) & CLI_CHAutoCoolDeviceSelectionMask) >> CLI_CHAutoCoolDeviceSelectionShift)
// Heizen Auswahl durch
#define ParamCLI_CHAutoHeatDeviceSelection           (PT_CLIAutomaticDevice)(knx.paramByte(CLI_ParamCalcIndex(CLI_CHAutoHeatDeviceSelection)) & CLI_CHAutoHeatDeviceSelectionMask)
// Entfeuchten Auswahl durch
#define ParamCLI_CHAutoDehumDeviceSelection          (PT_CLIAutomaticDevice)((knx.paramByte(CLI_ParamCalcIndex(CLI_CHAutoDehumDeviceSelection)) & CLI_CHAutoDehumDeviceSelectionMask) >> CLI_CHAutoDehumDeviceSelectionShift)
// Ventilator Auswahl durch
#define ParamCLI_CHAutoFanDeviceSelection            (PT_CLIAutomaticDevice)(knx.paramByte(CLI_ParamCalcIndex(CLI_CHAutoFanDeviceSelection)) & CLI_CHAutoFanDeviceSelectionMask)
// Manuelle Änderung am Kühl-/Heizsystem
#define ParamCLI_CHBehaviorOnDeviceChange            (PT_CLIBehaviorDeviceChange)((knx.paramByte(CLI_ParamCalcIndex(CLI_CHBehaviorOnDeviceChange)) & CLI_CHBehaviorOnDeviceChangeMask) >> CLI_CHBehaviorOnDeviceChangeShift)
// Kühlen im Winterbetrieb erlaubt
#define ParamCLI_CHCoolingWinterAllowed              ((bool)(knx.paramByte(CLI_ParamCalcIndex(CLI_CHCoolingWinterAllowed)) & CLI_CHCoolingWinterAllowedMask))
// Heizen im Sommerbetrieb erlaubt
#define ParamCLI_CHHeatingSummerAllowed              ((bool)(knx.paramByte(CLI_ParamCalcIndex(CLI_CHHeatingSummerAllowed)) & CLI_CHHeatingSummerAllowedMask))
// 
#define ParamCLI_CHFallbackAutoWaitTimeDelayBase     ((knx.paramByte(CLI_ParamCalcIndex(CLI_CHFallbackAutoWaitTimeDelayBase)) & CLI_CHFallbackAutoWaitTimeDelayBaseMask) >> CLI_CHFallbackAutoWaitTimeDelayBaseShift)
// 
#define ParamCLI_CHFallbackAutoWaitTimeDelayTime     (knx.paramWord(CLI_ParamCalcIndex(CLI_CHFallbackAutoWaitTimeDelayTime)) & CLI_CHFallbackAutoWaitTimeDelayTimeMask)
//  (in Millisekunden)
#define ParamCLI_CHFallbackAutoWaitTimeDelayTimeMS   (paramDelay(knx.paramWord(CLI_ParamCalcIndex(CLI_CHFallbackAutoWaitTimeDelayTime))))
// Hysterese Kühlen
#define ParamCLI_CHHysteresisCooling                 (PT_CLIHysteresis)((knx.paramByte(CLI_ParamCalcIndex(CLI_CHHysteresisCooling)) & CLI_CHHysteresisCoolingMask) >> CLI_CHHysteresisCoolingShift)
// Hysterese Heizen
#define ParamCLI_CHHysteresisHeating                 (PT_CLIHysteresis)(knx.paramByte(CLI_ParamCalcIndex(CLI_CHHysteresisHeating)) & CLI_CHHysteresisHeatingMask)
// Fenster offen Behandlung
#define ParamCLI_CHWindowOpenEnabled                 ((bool)(knx.paramByte(CLI_ParamCalcIndex(CLI_CHWindowOpenEnabled)) & CLI_CHWindowOpenEnabledMask))
// Ausführen
#define ParamCLI_CHWindowOpenCondition1              (PT_CLIWindowOpenCondition)((knx.paramByte(CLI_ParamCalcIndex(CLI_CHWindowOpenCondition1)) & CLI_CHWindowOpenCondition1Mask) >> CLI_CHWindowOpenCondition1Shift)
// Aktion
#define ParamCLI_CHWindowOpenAction1                 (PT_CLIWindowOpenAction)(knx.paramByte(CLI_ParamCalcIndex(CLI_CHWindowOpenAction1)) & CLI_CHWindowOpenAction1Mask)
// Nach Einheit
#define ParamCLI_CHWindowOpenDelayBase1              ((knx.paramByte(CLI_ParamCalcIndex(CLI_CHWindowOpenDelayBase1)) & CLI_CHWindowOpenDelayBase1Mask) >> CLI_CHWindowOpenDelayBase1Shift)
// Nach
#define ParamCLI_CHWindowOpenDelayTime1              (knx.paramWord(CLI_ParamCalcIndex(CLI_CHWindowOpenDelayTime1)) & CLI_CHWindowOpenDelayTime1Mask)
// Nach (in Millisekunden)
#define ParamCLI_CHWindowOpenDelayTime1MS            (paramDelay(knx.paramWord(CLI_ParamCalcIndex(CLI_CHWindowOpenDelayTime1))))
// Kühlbetrieb plus / Heizbetrieb minus
#define ParamCLI_CHWindowOpenTempCorrection1         (knx.paramByte(CLI_ParamCalcIndex(CLI_CHWindowOpenTempCorrection1)))
// Ausführen
#define ParamCLI_CHWindowOpenCondition2              (PT_CLIWindowOpenCondition)((knx.paramByte(CLI_ParamCalcIndex(CLI_CHWindowOpenCondition2)) & CLI_CHWindowOpenCondition2Mask) >> CLI_CHWindowOpenCondition2Shift)
// Aktion
#define ParamCLI_CHWindowOpenAction2                 (PT_CLIWindowOpenAction)(knx.paramByte(CLI_ParamCalcIndex(CLI_CHWindowOpenAction2)) & CLI_CHWindowOpenAction2Mask)
// Nach Einheit
#define ParamCLI_CHWindowOpenDelayBase2              ((knx.paramByte(CLI_ParamCalcIndex(CLI_CHWindowOpenDelayBase2)) & CLI_CHWindowOpenDelayBase2Mask) >> CLI_CHWindowOpenDelayBase2Shift)
// Nach
#define ParamCLI_CHWindowOpenDelayTime2              (knx.paramWord(CLI_ParamCalcIndex(CLI_CHWindowOpenDelayTime2)) & CLI_CHWindowOpenDelayTime2Mask)
// Nach (in Millisekunden)
#define ParamCLI_CHWindowOpenDelayTime2MS            (paramDelay(knx.paramWord(CLI_ParamCalcIndex(CLI_CHWindowOpenDelayTime2))))
// Kühlbetrieb plus / Heizbetrieb minus
#define ParamCLI_CHWindowOpenTempCorrection2         (knx.paramByte(CLI_ParamCalcIndex(CLI_CHWindowOpenTempCorrection2)))
// Ausführen
#define ParamCLI_CHWindowOpenCondition3              (PT_CLIWindowOpenCondition)((knx.paramByte(CLI_ParamCalcIndex(CLI_CHWindowOpenCondition3)) & CLI_CHWindowOpenCondition3Mask) >> CLI_CHWindowOpenCondition3Shift)
// Aktion
#define ParamCLI_CHWindowOpenAction3                 (PT_CLIWindowOpenAction)(knx.paramByte(CLI_ParamCalcIndex(CLI_CHWindowOpenAction3)) & CLI_CHWindowOpenAction3Mask)
// Nach Einheit
#define ParamCLI_CHWindowOpenDelayBase3              ((knx.paramByte(CLI_ParamCalcIndex(CLI_CHWindowOpenDelayBase3)) & CLI_CHWindowOpenDelayBase3Mask) >> CLI_CHWindowOpenDelayBase3Shift)
// Nach
#define ParamCLI_CHWindowOpenDelayTime3              (knx.paramWord(CLI_ParamCalcIndex(CLI_CHWindowOpenDelayTime3)) & CLI_CHWindowOpenDelayTime3Mask)
// Nach (in Millisekunden)
#define ParamCLI_CHWindowOpenDelayTime3MS            (paramDelay(knx.paramWord(CLI_ParamCalcIndex(CLI_CHWindowOpenDelayTime3))))
// Kühlbetrieb plus / Heizbetrieb minus
#define ParamCLI_CHWindowOpenTempCorrection3         (knx.paramByte(CLI_ParamCalcIndex(CLI_CHWindowOpenTempCorrection3)))
// Ausführen
#define ParamCLI_CHWindowOpenCondition4              (PT_CLIWindowOpenCondition)((knx.paramByte(CLI_ParamCalcIndex(CLI_CHWindowOpenCondition4)) & CLI_CHWindowOpenCondition4Mask) >> CLI_CHWindowOpenCondition4Shift)
// Aktion
#define ParamCLI_CHWindowOpenAction4                 (PT_CLIWindowOpenAction)(knx.paramByte(CLI_ParamCalcIndex(CLI_CHWindowOpenAction4)) & CLI_CHWindowOpenAction4Mask)
// Nach Einheit
#define ParamCLI_CHWindowOpenDelayBase4              ((knx.paramByte(CLI_ParamCalcIndex(CLI_CHWindowOpenDelayBase4)) & CLI_CHWindowOpenDelayBase4Mask) >> CLI_CHWindowOpenDelayBase4Shift)
// Nach
#define ParamCLI_CHWindowOpenDelayTime4              (knx.paramWord(CLI_ParamCalcIndex(CLI_CHWindowOpenDelayTime4)) & CLI_CHWindowOpenDelayTime4Mask)
// Nach (in Millisekunden)
#define ParamCLI_CHWindowOpenDelayTime4MS            (paramDelay(knx.paramWord(CLI_ParamCalcIndex(CLI_CHWindowOpenDelayTime4))))
// Kühlbetrieb plus / Heizbetrieb minus
#define ParamCLI_CHWindowOpenTempCorrection4         (knx.paramByte(CLI_ParamCalcIndex(CLI_CHWindowOpenTempCorrection4)))
// Ausführen
#define ParamCLI_CHWindowOpenCondition5              (PT_CLIWindowOpenCondition)((knx.paramByte(CLI_ParamCalcIndex(CLI_CHWindowOpenCondition5)) & CLI_CHWindowOpenCondition5Mask) >> CLI_CHWindowOpenCondition5Shift)
// Aktion
#define ParamCLI_CHWindowOpenAction5                 (PT_CLIWindowOpenAction)(knx.paramByte(CLI_ParamCalcIndex(CLI_CHWindowOpenAction5)) & CLI_CHWindowOpenAction5Mask)
// Nach Einheit
#define ParamCLI_CHWindowOpenDelayBase5              ((knx.paramByte(CLI_ParamCalcIndex(CLI_CHWindowOpenDelayBase5)) & CLI_CHWindowOpenDelayBase5Mask) >> CLI_CHWindowOpenDelayBase5Shift)
// Nach
#define ParamCLI_CHWindowOpenDelayTime5              (knx.paramWord(CLI_ParamCalcIndex(CLI_CHWindowOpenDelayTime5)) & CLI_CHWindowOpenDelayTime5Mask)
// Nach (in Millisekunden)
#define ParamCLI_CHWindowOpenDelayTime5MS            (paramDelay(knx.paramWord(CLI_ParamCalcIndex(CLI_CHWindowOpenDelayTime5))))
// Kühlbetrieb plus / Heizbetrieb minus
#define ParamCLI_CHWindowOpenTempCorrection5         (knx.paramByte(CLI_ParamCalcIndex(CLI_CHWindowOpenTempCorrection5)))
// Aktionen rückgängig
#define ParamCLI_CHWindowClose                       (PT_CLIWindowClose)((knx.paramByte(CLI_ParamCalcIndex(CLI_CHWindowClose)) & CLI_CHWindowCloseMask) >> CLI_CHWindowCloseShift)
// 
#define ParamCLI_CHWindowCloseWaitTimeDelayBase      ((knx.paramByte(CLI_ParamCalcIndex(CLI_CHWindowCloseWaitTimeDelayBase)) & CLI_CHWindowCloseWaitTimeDelayBaseMask) >> CLI_CHWindowCloseWaitTimeDelayBaseShift)
// 
#define ParamCLI_CHWindowCloseWaitTimeDelayTime      (knx.paramWord(CLI_ParamCalcIndex(CLI_CHWindowCloseWaitTimeDelayTime)) & CLI_CHWindowCloseWaitTimeDelayTimeMask)
//  (in Millisekunden)
#define ParamCLI_CHWindowCloseWaitTimeDelayTimeMS    (paramDelay(knx.paramWord(CLI_ParamCalcIndex(CLI_CHWindowCloseWaitTimeDelayTime))))

// deprecated
#define CLI_KoOffset 800

// Communication objects per channel (multiple occurrence)
#define CLI_KoBlockOffset 800
#define CLI_KoBlockSize 43

#define CLI_KoCalcNumber(index) (index + CLI_KoBlockOffset + _channelIndex * CLI_KoBlockSize)
#define CLI_KoCalcIndex(number) ((number >= CLI_KoCalcNumber(0) && number < CLI_KoCalcNumber(CLI_KoBlockSize)) ? (number - CLI_KoBlockOffset) % CLI_KoBlockSize : -1)
#define CLI_KoCalcChannel(number) ((number >= CLI_KoBlockOffset && number < CLI_KoBlockOffset + CLI_ChannelCount * CLI_KoBlockSize) ? (number - CLI_KoBlockOffset) / CLI_KoBlockSize : -1)

#define CLI_KoCModeSelection 0
#define CLI_KoCModeSelectionFb 1
#define CLI_KoCPower 2
#define CLI_KoCPowerFb 3
#define CLI_KoCTargetTemp 4
#define CLI_KoCTargetTempFb 5
#define CLI_KoCTargetTempRelativ 6
#define CLI_KoCRoomTemp 7
#define CLI_KoCActiveMode 8
#define CLI_KoCAutoReqHeat 9
#define CLI_KoCAutoReqCool 10
#define CLI_KoCAutoReqDehum 11
#define CLI_KoCAutoReqFan 12
#define CLI_KoCKo13 13
#define CLI_KoCKo14 14
#define CLI_KoCKo15 15
#define CLI_KoCKo16 16
#define CLI_KoCKo17 17
#define CLI_KoCKo18 18
#define CLI_KoCKo19 19
#define CLI_KoCKo20 20
#define CLI_KoCDev1Power 21
#define CLI_KoCDev1Set 22
#define CLI_KoCDev1PWM 23
#define CLI_KoCDev1SetFb 24
#define CLI_KoCDev1RoomTemp 25
#define CLI_KoCDev1IsActive 26
#define CLI_KoCKo26 27
#define CLI_KoCKo27 28
#define CLI_KoCKo28 29
#define CLI_KoCKo29 30
#define CLI_KoCKo30 31
#define CLI_KoCKo31 32
#define CLI_KoCKo32 33
#define CLI_KoCKo33 34
#define CLI_KoCDev2Power 35
#define CLI_KoCDev2Set 36
#define CLI_KoCDev2PWM 37
#define CLI_KoCDev2SetFb 38
#define CLI_KoCDev2RoomTemp 39
#define CLI_KoCDev2IsActive 40
#define CLI_KoCWindowOpen 41
#define CLI_KoCWindowOpenAlarm 42

// {{0:HVAC %C%}}: Modus Auswahl
#define KoCLI_CModeSelection                      (knx.getGroupObject(CLI_KoCalcNumber(CLI_KoCModeSelection)))
// {{0:HVAC %C%}}: Modus Aktuelle Auswahl
#define KoCLI_CModeSelectionFb                    (knx.getGroupObject(CLI_KoCalcNumber(CLI_KoCModeSelectionFb)))
// {{0:HVAC %C%}}: Ein/Aus
#define KoCLI_CPower                              (knx.getGroupObject(CLI_KoCalcNumber(CLI_KoCPower)))
// {{0:HVAC %C%}}: Aktueller Ein/Aus Zustand
#define KoCLI_CPowerFb                            (knx.getGroupObject(CLI_KoCalcNumber(CLI_KoCPowerFb)))
// {{0:HVAC %C%}}: Solltemperatur
#define KoCLI_CTargetTemp                         (knx.getGroupObject(CLI_KoCalcNumber(CLI_KoCTargetTemp)))
// {{0:HVAC %C%}}: Aktuelle Solltemperatur
#define KoCLI_CTargetTempFb                       (knx.getGroupObject(CLI_KoCalcNumber(CLI_KoCTargetTempFb)))
// {{0:HVAC %C%}}: Solltemperatur verringern/erhöhen
#define KoCLI_CTargetTempRelativ                  (knx.getGroupObject(CLI_KoCalcNumber(CLI_KoCTargetTempRelativ)))
// {{0:HVAC %C%}}: Raumtemperatur
#define KoCLI_CRoomTemp                           (knx.getGroupObject(CLI_KoCalcNumber(CLI_KoCRoomTemp)))
// {{0:HVAC %C%}}: Aktiver Modus
#define KoCLI_CActiveMode                         (knx.getGroupObject(CLI_KoCalcNumber(CLI_KoCActiveMode)))
// {{0:HVAC %C%}}: Anforderung Heizen für Automatik
#define KoCLI_CAutoReqHeat                        (knx.getGroupObject(CLI_KoCalcNumber(CLI_KoCAutoReqHeat)))
// {{0:HVAC %C%}}: Anforderung Kühlen für Automatik
#define KoCLI_CAutoReqCool                        (knx.getGroupObject(CLI_KoCalcNumber(CLI_KoCAutoReqCool)))
// {{0:HVAC %C%}}: Anforderung Entfeuchtung für Automatik
#define KoCLI_CAutoReqDehum                       (knx.getGroupObject(CLI_KoCalcNumber(CLI_KoCAutoReqDehum)))
// {{0:HVAC %C%}}: Anforderung Lüfter für Automatik
#define KoCLI_CAutoReqFan                         (knx.getGroupObject(CLI_KoCalcNumber(CLI_KoCAutoReqFan)))
// 
#define KoCLI_CKo13                               (knx.getGroupObject(CLI_KoCalcNumber(CLI_KoCKo13)))
// 
#define KoCLI_CKo14                               (knx.getGroupObject(CLI_KoCalcNumber(CLI_KoCKo14)))
// 
#define KoCLI_CKo15                               (knx.getGroupObject(CLI_KoCalcNumber(CLI_KoCKo15)))
// 
#define KoCLI_CKo16                               (knx.getGroupObject(CLI_KoCalcNumber(CLI_KoCKo16)))
// 
#define KoCLI_CKo17                               (knx.getGroupObject(CLI_KoCalcNumber(CLI_KoCKo17)))
// 
#define KoCLI_CKo18                               (knx.getGroupObject(CLI_KoCalcNumber(CLI_KoCKo18)))
// 
#define KoCLI_CKo19                               (knx.getGroupObject(CLI_KoCalcNumber(CLI_KoCKo19)))
// 
#define KoCLI_CKo20                               (knx.getGroupObject(CLI_KoCalcNumber(CLI_KoCKo20)))
// {{0:HVAC %C% %CLI_ClimateDevice1Name%}}: Strom
#define KoCLI_CDev1Power                          (knx.getGroupObject(CLI_KoCalcNumber(CLI_KoCDev1Power)))
// {{0:HVAC %C% %CLI_ClimateDevice1Name%}}: Solltemperatur
#define KoCLI_CDev1Set                            (knx.getGroupObject(CLI_KoCalcNumber(CLI_KoCDev1Set)))
// {{0:HVAC %CLI_ClimateDevice1Name% %C%}}: Pulsweitenmodulation
#define KoCLI_CDev1PWM                            (knx.getGroupObject(CLI_KoCalcNumber(CLI_KoCDev1PWM)))
// {{0:HVAC %C% %CLI_ClimateDevice1Name%}}: Solltemperatur Rückmeldung
#define KoCLI_CDev1SetFb                          (knx.getGroupObject(CLI_KoCalcNumber(CLI_KoCDev1SetFb)))
// 
#define KoCLI_CDev1RoomTemp                       (knx.getGroupObject(CLI_KoCalcNumber(CLI_KoCDev1RoomTemp)))
// 
#define KoCLI_CDev1IsActive                       (knx.getGroupObject(CLI_KoCalcNumber(CLI_KoCDev1IsActive)))
// 
#define KoCLI_CKo26                               (knx.getGroupObject(CLI_KoCalcNumber(CLI_KoCKo26)))
// 
#define KoCLI_CKo27                               (knx.getGroupObject(CLI_KoCalcNumber(CLI_KoCKo27)))
// 
#define KoCLI_CKo28                               (knx.getGroupObject(CLI_KoCalcNumber(CLI_KoCKo28)))
// 
#define KoCLI_CKo29                               (knx.getGroupObject(CLI_KoCalcNumber(CLI_KoCKo29)))
// 
#define KoCLI_CKo30                               (knx.getGroupObject(CLI_KoCalcNumber(CLI_KoCKo30)))
// 
#define KoCLI_CKo31                               (knx.getGroupObject(CLI_KoCalcNumber(CLI_KoCKo31)))
// 
#define KoCLI_CKo32                               (knx.getGroupObject(CLI_KoCalcNumber(CLI_KoCKo32)))
// 
#define KoCLI_CKo33                               (knx.getGroupObject(CLI_KoCalcNumber(CLI_KoCKo33)))
// {{0:HVAC %C%: %CLI_ClimateDevice2Name%}}: Strom
#define KoCLI_CDev2Power                          (knx.getGroupObject(CLI_KoCalcNumber(CLI_KoCDev2Power)))
// {{0:HVAC %C%: %CLI_ClimateDevice2Name%}}: Solltemperatur
#define KoCLI_CDev2Set                            (knx.getGroupObject(CLI_KoCalcNumber(CLI_KoCDev2Set)))
// {{0:HVAC %CLI_ClimateDevice2Name% %C%}}: Pulsweitenmodulation
#define KoCLI_CDev2PWM                            (knx.getGroupObject(CLI_KoCalcNumber(CLI_KoCDev2PWM)))
// {{0:HVAC %C%: %CLI_ClimateDevice2Name%}}: Solltemperatur Rückmeldung
#define KoCLI_CDev2SetFb                          (knx.getGroupObject(CLI_KoCalcNumber(CLI_KoCDev2SetFb)))
// 
#define KoCLI_CDev2RoomTemp                       (knx.getGroupObject(CLI_KoCalcNumber(CLI_KoCDev2RoomTemp)))
// 
#define KoCLI_CDev2IsActive                       (knx.getGroupObject(CLI_KoCalcNumber(CLI_KoCDev2IsActive)))
// {{0:HVAC %C%}}: Fenster offen
#define KoCLI_CWindowOpen                         (knx.getGroupObject(CLI_KoCalcNumber(CLI_KoCWindowOpen)))
// {{0:HVAC %C%}}: Fenster offen Alarm
#define KoCLI_CWindowOpenAlarm                    (knx.getGroupObject(CLI_KoCalcNumber(CLI_KoCWindowOpenAlarm)))

#define HTA_OperationMode                       1030      // 2 Bits, Bit 7-6
#define     HTA_OperationModeMask 0xC0
#define     HTA_OperationModeShift 6
#define HTA_OperationModeChange                 1030      // 2 Bits, Bit 5-4
#define     HTA_OperationModeChangeMask 0x30
#define     HTA_OperationModeChangeShift 4
#define HTA_OperationModeCyclicBase             1031      // 2 Bits, Bit 7-6
#define     HTA_OperationModeCyclicBaseMask 0xC0
#define     HTA_OperationModeCyclicBaseShift 6
#define HTA_OperationModeCyclicTime             1031      // 14 Bits, Bit 13-0
#define     HTA_OperationModeCyclicTimeMask 0x3FFF
#define     HTA_OperationModeCyclicTimeShift 0
#define HTA_StuckProtection                     1033      // uint8_t
#define HTA_PowerRestoreRequestValues           1034      // 1 Bit, Bit 7
#define     HTA_PowerRestoreRequestValuesMask 0x80
#define     HTA_PowerRestoreRequestValuesShift 7
#define HTA_ObjectsMaxSetValueHeating           1035      // 1 Bit, Bit 7
#define     HTA_ObjectsMaxSetValueHeatingMask 0x80
#define     HTA_ObjectsMaxSetValueHeatingShift 7
#define HTA_ObjectsMaxSetValueCooling           1035      // 1 Bit, Bit 6
#define     HTA_ObjectsMaxSetValueCoolingMask 0x40
#define     HTA_ObjectsMaxSetValueCoolingShift 6
#define HTA_ObjectsMaxSetValueCombined          1035      // 1 Bit, Bit 5
#define     HTA_ObjectsMaxSetValueCombinedMask 0x20
#define     HTA_ObjectsMaxSetValueCombinedShift 5
#define HTA_ObjectsMaxSetValueHeatingCyclicBase 1036      // 2 Bits, Bit 7-6
#define     HTA_ObjectsMaxSetValueHeatingCyclicBaseMask 0xC0
#define     HTA_ObjectsMaxSetValueHeatingCyclicBaseShift 6
#define HTA_ObjectsMaxSetValueHeatingCyclicTime 1036      // 14 Bits, Bit 13-0
#define     HTA_ObjectsMaxSetValueHeatingCyclicTimeMask 0x3FFF
#define     HTA_ObjectsMaxSetValueHeatingCyclicTimeShift 0
#define HTA_ObjectsMaxSetValueCoolingCyclicBase 1038      // 2 Bits, Bit 7-6
#define     HTA_ObjectsMaxSetValueCoolingCyclicBaseMask 0xC0
#define     HTA_ObjectsMaxSetValueCoolingCyclicBaseShift 6
#define HTA_ObjectsMaxSetValueCoolingCyclicTime 1038      // 14 Bits, Bit 13-0
#define     HTA_ObjectsMaxSetValueCoolingCyclicTimeMask 0x3FFF
#define     HTA_ObjectsMaxSetValueCoolingCyclicTimeShift 0
#define HTA_ObjectsMaxSetValueCombinedCyclicBase 1040      // 2 Bits, Bit 7-6
#define     HTA_ObjectsMaxSetValueCombinedCyclicBaseMask 0xC0
#define     HTA_ObjectsMaxSetValueCombinedCyclicBaseShift 6
#define HTA_ObjectsMaxSetValueCombinedCyclicTime 1040      // 14 Bits, Bit 13-0
#define     HTA_ObjectsMaxSetValueCombinedCyclicTimeMask 0x3FFF
#define     HTA_ObjectsMaxSetValueCombinedCyclicTimeShift 0
#define HTA_ObjectsHeatingCoolingRequest        1042      // 1 Bit, Bit 7
#define     HTA_ObjectsHeatingCoolingRequestMask 0x80
#define     HTA_ObjectsHeatingCoolingRequestShift 7

// Betriebsmodus
#define ParamHTA_OperationMode                       ((knx.paramByte(HTA_OperationMode) & HTA_OperationModeMask) >> HTA_OperationModeShift)
// Umschaltung Heizen/Kühlen
#define ParamHTA_OperationModeChange                 ((knx.paramByte(HTA_OperationModeChange) & HTA_OperationModeChangeMask) >> HTA_OperationModeChangeShift)
// Zeitbasis
#define ParamHTA_OperationModeCyclicBase             ((knx.paramByte(HTA_OperationModeCyclicBase) & HTA_OperationModeCyclicBaseMask) >> HTA_OperationModeCyclicBaseShift)
// Zeit
#define ParamHTA_OperationModeCyclicTime             (knx.paramWord(HTA_OperationModeCyclicTime) & HTA_OperationModeCyclicTimeMask)
// Zeit (in Millisekunden)
#define ParamHTA_OperationModeCyclicTimeMS           (paramDelay(knx.paramWord(HTA_OperationModeCyclicTime)))
// Festsitzschutz alle (0 = inaktiv)
#define ParamHTA_StuckProtection                     (knx.paramByte(HTA_StuckProtection))
// Werte zusätzlich abfragen
#define ParamHTA_PowerRestoreRequestValues           ((bool)(knx.paramByte(HTA_PowerRestoreRequestValues) & HTA_PowerRestoreRequestValuesMask))
// Objekte max. Stellwert Heizen
#define ParamHTA_ObjectsMaxSetValueHeating           ((bool)(knx.paramByte(HTA_ObjectsMaxSetValueHeating) & HTA_ObjectsMaxSetValueHeatingMask))
// Objekte max. Stellwert Kühlen
#define ParamHTA_ObjectsMaxSetValueCooling           ((bool)(knx.paramByte(HTA_ObjectsMaxSetValueCooling) & HTA_ObjectsMaxSetValueCoolingMask))
// Objekte max. Stellwert kombiniert
#define ParamHTA_ObjectsMaxSetValueCombined          ((bool)(knx.paramByte(HTA_ObjectsMaxSetValueCombined) & HTA_ObjectsMaxSetValueCombinedMask))
// Zeitbasis
#define ParamHTA_ObjectsMaxSetValueHeatingCyclicBase ((knx.paramByte(HTA_ObjectsMaxSetValueHeatingCyclicBase) & HTA_ObjectsMaxSetValueHeatingCyclicBaseMask) >> HTA_ObjectsMaxSetValueHeatingCyclicBaseShift)
// Zeit
#define ParamHTA_ObjectsMaxSetValueHeatingCyclicTime (knx.paramWord(HTA_ObjectsMaxSetValueHeatingCyclicTime) & HTA_ObjectsMaxSetValueHeatingCyclicTimeMask)
// Zeit (in Millisekunden)
#define ParamHTA_ObjectsMaxSetValueHeatingCyclicTimeMS (paramDelay(knx.paramWord(HTA_ObjectsMaxSetValueHeatingCyclicTime)))
// Zeitbasis
#define ParamHTA_ObjectsMaxSetValueCoolingCyclicBase ((knx.paramByte(HTA_ObjectsMaxSetValueCoolingCyclicBase) & HTA_ObjectsMaxSetValueCoolingCyclicBaseMask) >> HTA_ObjectsMaxSetValueCoolingCyclicBaseShift)
// Zeit
#define ParamHTA_ObjectsMaxSetValueCoolingCyclicTime (knx.paramWord(HTA_ObjectsMaxSetValueCoolingCyclicTime) & HTA_ObjectsMaxSetValueCoolingCyclicTimeMask)
// Zeit (in Millisekunden)
#define ParamHTA_ObjectsMaxSetValueCoolingCyclicTimeMS (paramDelay(knx.paramWord(HTA_ObjectsMaxSetValueCoolingCyclicTime)))
// Zeitbasis
#define ParamHTA_ObjectsMaxSetValueCombinedCyclicBase ((knx.paramByte(HTA_ObjectsMaxSetValueCombinedCyclicBase) & HTA_ObjectsMaxSetValueCombinedCyclicBaseMask) >> HTA_ObjectsMaxSetValueCombinedCyclicBaseShift)
// Zeit
#define ParamHTA_ObjectsMaxSetValueCombinedCyclicTime (knx.paramWord(HTA_ObjectsMaxSetValueCombinedCyclicTime) & HTA_ObjectsMaxSetValueCombinedCyclicTimeMask)
// Zeit (in Millisekunden)
#define ParamHTA_ObjectsMaxSetValueCombinedCyclicTimeMS (paramDelay(knx.paramWord(HTA_ObjectsMaxSetValueCombinedCyclicTime)))
// Objekte für Heiz-/Kühlanforderung
#define ParamHTA_ObjectsHeatingCoolingRequest        ((bool)(knx.paramByte(HTA_ObjectsHeatingCoolingRequest) & HTA_ObjectsHeatingCoolingRequestMask))

#define HTA_KoCentralFunction 21
#define HTA_KoOperationMode 22
#define HTA_KoOperationModeStatus 23
#define HTA_KoSummerWinter 24
#define HTA_KoSummerWinterStatus 25
#define HTA_KoMaxSetValueHeating 26
#define HTA_KoMaxSetValueHeatingStatus 27
#define HTA_KoMaxSetValueCooling 28
#define HTA_KoMaxSetValueCoolingStatus 29
#define HTA_KoMaxSetValueCombined 30
#define HTA_KoMaxSetValueCombinedStatus 31
#define HTA_KoRequestHeating 32
#define HTA_KoRequestCooling 33
#define HTA_KoRequestCombined 34

// Zentralfunktion
#define KoHTA_CentralFunction                     (knx.getGroupObject(HTA_KoCentralFunction))
// Heizen = 1, Kühlen = 0
#define KoHTA_OperationMode                       (knx.getGroupObject(HTA_KoOperationMode))
// Heizen = 1, Kühlen = 0
#define KoHTA_OperationModeStatus                 (knx.getGroupObject(HTA_KoOperationModeStatus))
// Sommer = 1, Winter = 0
#define KoHTA_SummerWinter                        (knx.getGroupObject(HTA_KoSummerWinter))
// Sommer = 1, Winter = 0
#define KoHTA_SummerWinterStatus                  (knx.getGroupObject(HTA_KoSummerWinterStatus))
// Max. Stellwert Heizen
#define KoHTA_MaxSetValueHeating                  (knx.getGroupObject(HTA_KoMaxSetValueHeating))
// Max. Stellwert Heizen
#define KoHTA_MaxSetValueHeatingStatus            (knx.getGroupObject(HTA_KoMaxSetValueHeatingStatus))
// Max. Stellwert Kühlen
#define KoHTA_MaxSetValueCooling                  (knx.getGroupObject(HTA_KoMaxSetValueCooling))
// Max. Stellwert Kühlen
#define KoHTA_MaxSetValueCoolingStatus            (knx.getGroupObject(HTA_KoMaxSetValueCoolingStatus))
// Max. Stellwert Heizen/Kühlen
#define KoHTA_MaxSetValueCombined                 (knx.getGroupObject(HTA_KoMaxSetValueCombined))
// Max. Stellwert Heizen/Kühlen
#define KoHTA_MaxSetValueCombinedStatus           (knx.getGroupObject(HTA_KoMaxSetValueCombinedStatus))
// Heizanforderung
#define KoHTA_RequestHeating                      (knx.getGroupObject(HTA_KoRequestHeating))
// Kühlanforderung
#define KoHTA_RequestCooling                      (knx.getGroupObject(HTA_KoRequestCooling))
// Heiz-/Kühlanforderung
#define KoHTA_RequestCombined                     (knx.getGroupObject(HTA_KoRequestCombined))

#define HTA_ChannelCount 12

// Parameter per channel
#define HTA_ParamBlockOffset 1049
#define HTA_ParamBlockSize 95
#define HTA_ParamCalcIndex(index) (index + HTA_ParamBlockOffset + _channelIndex * HTA_ParamBlockSize)

#define HTA_ChActive                             0      // 2 Bits, Bit 7-6
#define     HTA_ChActiveMask 0xC0
#define     HTA_ChActiveShift 6
#define HTA_ChControlMode                        1      // 2 Bits, Bit 7-6
#define     HTA_ChControlModeMask 0xC0
#define     HTA_ChControlModeShift 6
#define HTA_ChOperationMode                      1      // 2 Bits, Bit 5-4
#define     HTA_ChOperationModeMask 0x30
#define     HTA_ChOperationModeShift 4
#define HTA_ChSetValueZero                       1      // 1 Bit, Bit 3
#define     HTA_ChSetValueZeroMask 0x08
#define     HTA_ChSetValueZeroShift 3
#define HTA_ChHeatingProportional                2      // uint8_t
#define HTA_ChHeatingResetTime                   3      // uint8_t
#define HTA_ChCoolingProportional                4      // uint8_t
#define HTA_ChCoolingResetTime                   5      // uint8_t
#define HTA_ChTargetTempHeatingComfort           6      // int8_t
#define HTA_ChTargetTempHeatingStandby           7      // int8_t
#define HTA_ChTargetTempHeatingNight             8      // int8_t
#define HTA_ChTargetTempHeatingProtect           9      // int8_t
#define HTA_ChTargetTempCoolingComfort          10      // int8_t
#define HTA_ChTargetTempCoolingStandby          11      // int8_t
#define HTA_ChTargetTempCoolingNight            12      // int8_t
#define HTA_ChTargetTempCoolingProtect          13      // int8_t
#define HTA_ChHvacModePriority                  14      // 1 Bit, Bit 7
#define     HTA_ChHvacModePriorityMask 0x80
#define     HTA_ChHvacModePriorityShift 7
#define HTA_ChTargetTempResetOnHvacModeChange   14      // 1 Bit, Bit 6
#define     HTA_ChTargetTempResetOnHvacModeChangeMask 0x40
#define     HTA_ChTargetTempResetOnHvacModeChangeShift 6
#define HTA_ChTargetTempShiftMax                15      // uint8_t
#define HTA_ChTargetTempShift                   16      // 2 Bits, Bit 7-6
#define     HTA_ChTargetTempShiftMask 0xC0
#define     HTA_ChTargetTempShiftShift 6
#define HTA_ChTargetTempShiftResetOnHvacModeChange 16      // 1 Bit, Bit 5
#define     HTA_ChTargetTempShiftResetOnHvacModeChangeMask 0x20
#define     HTA_ChTargetTempShiftResetOnHvacModeChangeShift 5
#define HTA_ChTargetTempShiftResetOnNewTargetTemp 16      // 1 Bit, Bit 4
#define     HTA_ChTargetTempShiftResetOnNewTargetTempMask 0x10
#define     HTA_ChTargetTempShiftResetOnNewTargetTempShift 4
#define HTA_ChTargetTempShiftApplyToComfort     17      // 1 Bit, Bit 7
#define     HTA_ChTargetTempShiftApplyToComfortMask 0x80
#define     HTA_ChTargetTempShiftApplyToComfortShift 7
#define HTA_ChTargetTempShiftApplyToStandby     17      // 1 Bit, Bit 6
#define     HTA_ChTargetTempShiftApplyToStandbyMask 0x40
#define     HTA_ChTargetTempShiftApplyToStandbyShift 6
#define HTA_ChTargetTempShiftApplyToNight       17      // 1 Bit, Bit 5
#define     HTA_ChTargetTempShiftApplyToNightMask 0x20
#define     HTA_ChTargetTempShiftApplyToNightShift 5
#define HTA_ChTargetTempShiftActionNight        17      // 1 Bit, Bit 4
#define     HTA_ChTargetTempShiftActionNightMask 0x10
#define     HTA_ChTargetTempShiftActionNightShift 4
#define HTA_ChTargetTempShiftActionStandby      17      // 1 Bit, Bit 3
#define     HTA_ChTargetTempShiftActionStandbyMask 0x08
#define     HTA_ChTargetTempShiftActionStandbyShift 3
#define HTA_ChSetValueChangeSend                18      // 1 Bit, Bit 7
#define     HTA_ChSetValueChangeSendMask 0x80
#define     HTA_ChSetValueChangeSendShift 7
#define HTA_ChTargetTempChangeSend              18      // 1 Bit, Bit 6
#define     HTA_ChTargetTempChangeSendMask 0x40
#define     HTA_ChTargetTempChangeSendShift 6
#define HTA_ChConsiderForRequestAndMaxSetValue  18      // 1 Bit, Bit 0
#define     HTA_ChConsiderForRequestAndMaxSetValueMask 0x01
#define     HTA_ChConsiderForRequestAndMaxSetValueShift 0
#define HTA_ChSetValueCyclicBase                19      // 2 Bits, Bit 7-6
#define     HTA_ChSetValueCyclicBaseMask 0xC0
#define     HTA_ChSetValueCyclicBaseShift 6
#define HTA_ChSetValueCyclicTime                19      // 14 Bits, Bit 13-0
#define     HTA_ChSetValueCyclicTimeMask 0x3FFF
#define     HTA_ChSetValueCyclicTimeShift 0
#define HTA_ChTargetTempCyclicBase              21      // 2 Bits, Bit 7-6
#define     HTA_ChTargetTempCyclicBaseMask 0xC0
#define     HTA_ChTargetTempCyclicBaseShift 6
#define HTA_ChTargetTempCyclicTime              21      // 14 Bits, Bit 13-0
#define     HTA_ChTargetTempCyclicTimeMask 0x3FFF
#define     HTA_ChTargetTempCyclicTimeShift 0
#define HTA_ChEnforcedPosition                  23      // 1 Bit, Bit 7
#define     HTA_ChEnforcedPositionMask 0x80
#define     HTA_ChEnforcedPositionShift 7
#define HTA_ChEnforcedSetValueHeatingOrExtern   24      // uint8_t
#define HTA_ChEnforcedSetValueCooling           25      // uint8_t
#define HTA_ChEmergencyMode                     26      // 1 Bit, Bit 7
#define     HTA_ChEmergencyModeMask 0x80
#define     HTA_ChEmergencyModeShift 7
#define HTA_ChEmergencyModeChangeSend           26      // 1 Bit, Bit 6
#define     HTA_ChEmergencyModeChangeSendMask 0x40
#define     HTA_ChEmergencyModeChangeSendShift 6
#define HTA_ChEmergencyModeDelayBase            27      // 2 Bits, Bit 7-6
#define     HTA_ChEmergencyModeDelayBaseMask 0xC0
#define     HTA_ChEmergencyModeDelayBaseShift 6
#define HTA_ChEmergencyModeDelayTime            27      // 14 Bits, Bit 13-0
#define     HTA_ChEmergencyModeDelayTimeMask 0x3FFF
#define     HTA_ChEmergencyModeDelayTimeShift 0
#define HTA_ChEmergencyModeSetValueHeatingOrExtern 29      // uint8_t
#define HTA_ChEmergencyModeSetValueCooling      30      // uint8_t
#define HTA_ChEmergencyModeCyclicBase           31      // 2 Bits, Bit 7-6
#define     HTA_ChEmergencyModeCyclicBaseMask 0xC0
#define     HTA_ChEmergencyModeCyclicBaseShift 6
#define HTA_ChEmergencyModeCyclicTime           31      // 14 Bits, Bit 13-0
#define     HTA_ChEmergencyModeCyclicTimeMask 0x3FFF
#define     HTA_ChEmergencyModeCyclicTimeShift 0
#define HTA_ChManualMode                        33      // 1 Bit, Bit 7
#define     HTA_ChManualModeMask 0x80
#define     HTA_ChManualModeShift 7
#define HTA_ChManualModeChangeSend              33      // 1 Bit, Bit 6
#define     HTA_ChManualModeChangeSendMask 0x40
#define     HTA_ChManualModeChangeSendShift 6
#define HTA_ChManualModeChangeToAuto            33      // 2 Bits, Bit 1-0
#define     HTA_ChManualModeChangeToAutoMask 0x03
#define     HTA_ChManualModeChangeToAutoShift 0
#define HTA_ChManualModeSetValueOff             34      // uint8_t
#define HTA_ChManualModeSetValueOn              35      // uint8_t
#define HTA_ChManualModeCyclicBase              36      // 2 Bits, Bit 7-6
#define     HTA_ChManualModeCyclicBaseMask 0xC0
#define     HTA_ChManualModeCyclicBaseShift 6
#define HTA_ChManualModeCyclicTime              36      // 14 Bits, Bit 13-0
#define     HTA_ChManualModeCyclicTimeMask 0x3FFF
#define     HTA_ChManualModeCyclicTimeShift 0
#define HTA_ChManualModeChangeToAutoBase        38      // 2 Bits, Bit 7-6
#define     HTA_ChManualModeChangeToAutoBaseMask 0xC0
#define     HTA_ChManualModeChangeToAutoBaseShift 6
#define HTA_ChManualModeChangeToAutoTime        38      // 14 Bits, Bit 13-0
#define     HTA_ChManualModeChangeToAutoTimeMask 0x3FFF
#define     HTA_ChManualModeChangeToAutoTimeShift 0
#define HTA_ChMotorMaxCurrentClose              40      // uint8_t
#define HTA_ChMotorMaxCurrentOpen               41      // uint8_t
#define HTA_ChScenesActive                      42      // 1 Bit, Bit 7
#define     HTA_ChScenesActiveMask 0x80
#define     HTA_ChScenesActiveShift 7
#define HTA_ChHeatingPidP                       43      // uint16_t
#define HTA_ChHeatingPidI                       45      // uint16_t
#define HTA_ChHeatingPidD                       47      // uint16_t
#define HTA_ChHeatingPidInterval                49      // uint16_t
#define HTA_ChCoolingPidP                       51      // uint16_t
#define HTA_ChCoolingPidI                       53      // uint16_t
#define HTA_ChCoolingPidD                       55      // uint16_t
#define HTA_ChCoolingPidInterval                57      // uint16_t
#define HTA_ChSceneAActive                      59      // 1 Bit, Bit 7
#define     HTA_ChSceneAActiveMask 0x80
#define     HTA_ChSceneAActiveShift 7
#define HTA_ChSceneAChangeHvacMode              59      // 1 Bit, Bit 6
#define     HTA_ChSceneAChangeHvacModeMask 0x40
#define     HTA_ChSceneAChangeHvacModeShift 6
#define HTA_ChSceneAChangeTargetTempInput       59      // 1 Bit, Bit 5
#define     HTA_ChSceneAChangeTargetTempInputMask 0x20
#define     HTA_ChSceneAChangeTargetTempInputShift 5
#define HTA_ChSceneAChangeTargetTempShift       59      // 1 Bit, Bit 4
#define     HTA_ChSceneAChangeTargetTempShiftMask 0x10
#define     HTA_ChSceneAChangeTargetTempShiftShift 4
#define HTA_ChSceneAHvacMode                    59      // 2 Bits, Bit 3-2
#define     HTA_ChSceneAHvacModeMask 0x0C
#define     HTA_ChSceneAHvacModeShift 2
#define HTA_ChSceneATargetTempShift             59      // 2 Bits, Bit 1-0
#define     HTA_ChSceneATargetTempShiftMask 0x03
#define     HTA_ChSceneATargetTempShiftShift 0
#define HTA_ChSceneANumber                      60      // 8 Bits, Bit 7-0
#define HTA_ChSceneATargetTemp                  61      // int8_t
#define HTA_ChSceneBActive                      62      // 1 Bit, Bit 7
#define     HTA_ChSceneBActiveMask 0x80
#define     HTA_ChSceneBActiveShift 7
#define HTA_ChSceneBChangeHvacMode              62      // 1 Bit, Bit 6
#define     HTA_ChSceneBChangeHvacModeMask 0x40
#define     HTA_ChSceneBChangeHvacModeShift 6
#define HTA_ChSceneBChangeTargetTempInput       62      // 1 Bit, Bit 5
#define     HTA_ChSceneBChangeTargetTempInputMask 0x20
#define     HTA_ChSceneBChangeTargetTempInputShift 5
#define HTA_ChSceneBChangeTargetTempShift       62      // 1 Bit, Bit 4
#define     HTA_ChSceneBChangeTargetTempShiftMask 0x10
#define     HTA_ChSceneBChangeTargetTempShiftShift 4
#define HTA_ChSceneBHvacMode                    62      // 2 Bits, Bit 3-2
#define     HTA_ChSceneBHvacModeMask 0x0C
#define     HTA_ChSceneBHvacModeShift 2
#define HTA_ChSceneBTargetTempShift             62      // 2 Bits, Bit 1-0
#define     HTA_ChSceneBTargetTempShiftMask 0x03
#define     HTA_ChSceneBTargetTempShiftShift 0
#define HTA_ChSceneBNumber                      63      // 8 Bits, Bit 7-0
#define HTA_ChSceneBTargetTemp                  64      // int8_t
#define HTA_ChSceneCActive                      65      // 1 Bit, Bit 7
#define     HTA_ChSceneCActiveMask 0x80
#define     HTA_ChSceneCActiveShift 7
#define HTA_ChSceneCChangeHvacMode              65      // 1 Bit, Bit 6
#define     HTA_ChSceneCChangeHvacModeMask 0x40
#define     HTA_ChSceneCChangeHvacModeShift 6
#define HTA_ChSceneCChangeTargetTempInput       65      // 1 Bit, Bit 5
#define     HTA_ChSceneCChangeTargetTempInputMask 0x20
#define     HTA_ChSceneCChangeTargetTempInputShift 5
#define HTA_ChSceneCChangeTargetTempShift       65      // 1 Bit, Bit 4
#define     HTA_ChSceneCChangeTargetTempShiftMask 0x10
#define     HTA_ChSceneCChangeTargetTempShiftShift 4
#define HTA_ChSceneCHvacMode                    65      // 2 Bits, Bit 3-2
#define     HTA_ChSceneCHvacModeMask 0x0C
#define     HTA_ChSceneCHvacModeShift 2
#define HTA_ChSceneCTargetTempShift             65      // 2 Bits, Bit 1-0
#define     HTA_ChSceneCTargetTempShiftMask 0x03
#define     HTA_ChSceneCTargetTempShiftShift 0
#define HTA_ChSceneCNumber                      66      // 8 Bits, Bit 7-0
#define HTA_ChSceneCTargetTemp                  67      // int8_t
#define HTA_ChSceneDActive                      68      // 1 Bit, Bit 7
#define     HTA_ChSceneDActiveMask 0x80
#define     HTA_ChSceneDActiveShift 7
#define HTA_ChSceneDChangeHvacMode              68      // 1 Bit, Bit 6
#define     HTA_ChSceneDChangeHvacModeMask 0x40
#define     HTA_ChSceneDChangeHvacModeShift 6
#define HTA_ChSceneDChangeTargetTempInput       68      // 1 Bit, Bit 5
#define     HTA_ChSceneDChangeTargetTempInputMask 0x20
#define     HTA_ChSceneDChangeTargetTempInputShift 5
#define HTA_ChSceneDChangeTargetTempShift       68      // 1 Bit, Bit 4
#define     HTA_ChSceneDChangeTargetTempShiftMask 0x10
#define     HTA_ChSceneDChangeTargetTempShiftShift 4
#define HTA_ChSceneDHvacMode                    68      // 2 Bits, Bit 3-2
#define     HTA_ChSceneDHvacModeMask 0x0C
#define     HTA_ChSceneDHvacModeShift 2
#define HTA_ChSceneDTargetTempShift             68      // 2 Bits, Bit 1-0
#define     HTA_ChSceneDTargetTempShiftMask 0x03
#define     HTA_ChSceneDTargetTempShiftShift 0
#define HTA_ChSceneDNumber                      69      // 8 Bits, Bit 7-0
#define HTA_ChSceneDTargetTemp                  70      // int8_t
#define HTA_ChSceneEActive                      71      // 1 Bit, Bit 7
#define     HTA_ChSceneEActiveMask 0x80
#define     HTA_ChSceneEActiveShift 7
#define HTA_ChSceneEChangeHvacMode              71      // 1 Bit, Bit 6
#define     HTA_ChSceneEChangeHvacModeMask 0x40
#define     HTA_ChSceneEChangeHvacModeShift 6
#define HTA_ChSceneEChangeTargetTempInput       71      // 1 Bit, Bit 5
#define     HTA_ChSceneEChangeTargetTempInputMask 0x20
#define     HTA_ChSceneEChangeTargetTempInputShift 5
#define HTA_ChSceneEChangeTargetTempShift       71      // 1 Bit, Bit 4
#define     HTA_ChSceneEChangeTargetTempShiftMask 0x10
#define     HTA_ChSceneEChangeTargetTempShiftShift 4
#define HTA_ChSceneEHvacMode                    71      // 2 Bits, Bit 3-2
#define     HTA_ChSceneEHvacModeMask 0x0C
#define     HTA_ChSceneEHvacModeShift 2
#define HTA_ChSceneETargetTempShift             71      // 2 Bits, Bit 1-0
#define     HTA_ChSceneETargetTempShiftMask 0x03
#define     HTA_ChSceneETargetTempShiftShift 0
#define HTA_ChSceneENumber                      72      // 8 Bits, Bit 7-0
#define HTA_ChSceneETargetTemp                  73      // int8_t
#define HTA_ChSceneFActive                      74      // 1 Bit, Bit 7
#define     HTA_ChSceneFActiveMask 0x80
#define     HTA_ChSceneFActiveShift 7
#define HTA_ChSceneFChangeHvacMode              74      // 1 Bit, Bit 6
#define     HTA_ChSceneFChangeHvacModeMask 0x40
#define     HTA_ChSceneFChangeHvacModeShift 6
#define HTA_ChSceneFChangeTargetTempInput       74      // 1 Bit, Bit 5
#define     HTA_ChSceneFChangeTargetTempInputMask 0x20
#define     HTA_ChSceneFChangeTargetTempInputShift 5
#define HTA_ChSceneFChangeTargetTempShift       74      // 1 Bit, Bit 4
#define     HTA_ChSceneFChangeTargetTempShiftMask 0x10
#define     HTA_ChSceneFChangeTargetTempShiftShift 4
#define HTA_ChSceneFHvacMode                    74      // 2 Bits, Bit 3-2
#define     HTA_ChSceneFHvacModeMask 0x0C
#define     HTA_ChSceneFHvacModeShift 2
#define HTA_ChSceneFTargetTempShift             74      // 2 Bits, Bit 1-0
#define     HTA_ChSceneFTargetTempShiftMask 0x03
#define     HTA_ChSceneFTargetTempShiftShift 0
#define HTA_ChSceneFNumber                      75      // 8 Bits, Bit 7-0
#define HTA_ChSceneFTargetTemp                  76      // int8_t
#define HTA_ChSceneGActive                      77      // 1 Bit, Bit 7
#define     HTA_ChSceneGActiveMask 0x80
#define     HTA_ChSceneGActiveShift 7
#define HTA_ChSceneGChangeHvacMode              77      // 1 Bit, Bit 6
#define     HTA_ChSceneGChangeHvacModeMask 0x40
#define     HTA_ChSceneGChangeHvacModeShift 6
#define HTA_ChSceneGChangeTargetTempInput       77      // 1 Bit, Bit 5
#define     HTA_ChSceneGChangeTargetTempInputMask 0x20
#define     HTA_ChSceneGChangeTargetTempInputShift 5
#define HTA_ChSceneGChangeTargetTempShift       77      // 1 Bit, Bit 4
#define     HTA_ChSceneGChangeTargetTempShiftMask 0x10
#define     HTA_ChSceneGChangeTargetTempShiftShift 4
#define HTA_ChSceneGHvacMode                    77      // 2 Bits, Bit 3-2
#define     HTA_ChSceneGHvacModeMask 0x0C
#define     HTA_ChSceneGHvacModeShift 2
#define HTA_ChSceneGTargetTempShift             77      // 2 Bits, Bit 1-0
#define     HTA_ChSceneGTargetTempShiftMask 0x03
#define     HTA_ChSceneGTargetTempShiftShift 0
#define HTA_ChSceneGNumber                      78      // 8 Bits, Bit 7-0
#define HTA_ChSceneGTargetTemp                  79      // int8_t
#define HTA_ChSceneHActive                      80      // 1 Bit, Bit 7
#define     HTA_ChSceneHActiveMask 0x80
#define     HTA_ChSceneHActiveShift 7
#define HTA_ChSceneHChangeHvacMode              80      // 1 Bit, Bit 6
#define     HTA_ChSceneHChangeHvacModeMask 0x40
#define     HTA_ChSceneHChangeHvacModeShift 6
#define HTA_ChSceneHChangeTargetTempInput       80      // 1 Bit, Bit 5
#define     HTA_ChSceneHChangeTargetTempInputMask 0x20
#define     HTA_ChSceneHChangeTargetTempInputShift 5
#define HTA_ChSceneHChangeTargetTempShift       80      // 1 Bit, Bit 4
#define     HTA_ChSceneHChangeTargetTempShiftMask 0x10
#define     HTA_ChSceneHChangeTargetTempShiftShift 4
#define HTA_ChSceneHHvacMode                    80      // 2 Bits, Bit 3-2
#define     HTA_ChSceneHHvacModeMask 0x0C
#define     HTA_ChSceneHHvacModeShift 2
#define HTA_ChSceneHTargetTempShift             80      // 2 Bits, Bit 1-0
#define     HTA_ChSceneHTargetTempShiftMask 0x03
#define     HTA_ChSceneHTargetTempShiftShift 0
#define HTA_ChSceneHNumber                      81      // 8 Bits, Bit 7-0
#define HTA_ChSceneHTargetTemp                  82      // int8_t
#define HTA_ChSceneIActive                      83      // 1 Bit, Bit 7
#define     HTA_ChSceneIActiveMask 0x80
#define     HTA_ChSceneIActiveShift 7
#define HTA_ChSceneIChangeHvacMode              83      // 1 Bit, Bit 6
#define     HTA_ChSceneIChangeHvacModeMask 0x40
#define     HTA_ChSceneIChangeHvacModeShift 6
#define HTA_ChSceneIChangeTargetTempInput       83      // 1 Bit, Bit 5
#define     HTA_ChSceneIChangeTargetTempInputMask 0x20
#define     HTA_ChSceneIChangeTargetTempInputShift 5
#define HTA_ChSceneIChangeTargetTempShift       83      // 1 Bit, Bit 4
#define     HTA_ChSceneIChangeTargetTempShiftMask 0x10
#define     HTA_ChSceneIChangeTargetTempShiftShift 4
#define HTA_ChSceneIHvacMode                    83      // 2 Bits, Bit 3-2
#define     HTA_ChSceneIHvacModeMask 0x0C
#define     HTA_ChSceneIHvacModeShift 2
#define HTA_ChSceneITargetTempShift             83      // 2 Bits, Bit 1-0
#define     HTA_ChSceneITargetTempShiftMask 0x03
#define     HTA_ChSceneITargetTempShiftShift 0
#define HTA_ChSceneINumber                      84      // 8 Bits, Bit 7-0
#define HTA_ChSceneITargetTemp                  85      // int8_t
#define HTA_ChSceneJActive                      86      // 1 Bit, Bit 7
#define     HTA_ChSceneJActiveMask 0x80
#define     HTA_ChSceneJActiveShift 7
#define HTA_ChSceneJChangeHvacMode              86      // 1 Bit, Bit 6
#define     HTA_ChSceneJChangeHvacModeMask 0x40
#define     HTA_ChSceneJChangeHvacModeShift 6
#define HTA_ChSceneJChangeTargetTempInput       86      // 1 Bit, Bit 5
#define     HTA_ChSceneJChangeTargetTempInputMask 0x20
#define     HTA_ChSceneJChangeTargetTempInputShift 5
#define HTA_ChSceneJChangeTargetTempShift       86      // 1 Bit, Bit 4
#define     HTA_ChSceneJChangeTargetTempShiftMask 0x10
#define     HTA_ChSceneJChangeTargetTempShiftShift 4
#define HTA_ChSceneJHvacMode                    86      // 2 Bits, Bit 3-2
#define     HTA_ChSceneJHvacModeMask 0x0C
#define     HTA_ChSceneJHvacModeShift 2
#define HTA_ChSceneJTargetTempShift             86      // 2 Bits, Bit 1-0
#define     HTA_ChSceneJTargetTempShiftMask 0x03
#define     HTA_ChSceneJTargetTempShiftShift 0
#define HTA_ChSceneJNumber                      87      // 8 Bits, Bit 7-0
#define HTA_ChSceneJTargetTemp                  88      // int8_t
#define HTA_ChSceneKActive                      89      // 1 Bit, Bit 7
#define     HTA_ChSceneKActiveMask 0x80
#define     HTA_ChSceneKActiveShift 7
#define HTA_ChSceneKChangeHvacMode              89      // 1 Bit, Bit 6
#define     HTA_ChSceneKChangeHvacModeMask 0x40
#define     HTA_ChSceneKChangeHvacModeShift 6
#define HTA_ChSceneKChangeTargetTempInput       89      // 1 Bit, Bit 5
#define     HTA_ChSceneKChangeTargetTempInputMask 0x20
#define     HTA_ChSceneKChangeTargetTempInputShift 5
#define HTA_ChSceneKChangeTargetTempShift       89      // 1 Bit, Bit 4
#define     HTA_ChSceneKChangeTargetTempShiftMask 0x10
#define     HTA_ChSceneKChangeTargetTempShiftShift 4
#define HTA_ChSceneKHvacMode                    89      // 2 Bits, Bit 3-2
#define     HTA_ChSceneKHvacModeMask 0x0C
#define     HTA_ChSceneKHvacModeShift 2
#define HTA_ChSceneKTargetTempShift             89      // 2 Bits, Bit 1-0
#define     HTA_ChSceneKTargetTempShiftMask 0x03
#define     HTA_ChSceneKTargetTempShiftShift 0
#define HTA_ChSceneKNumber                      90      // 8 Bits, Bit 7-0
#define HTA_ChSceneKTargetTemp                  91      // int8_t
#define HTA_ChSceneLActive                      92      // 1 Bit, Bit 7
#define     HTA_ChSceneLActiveMask 0x80
#define     HTA_ChSceneLActiveShift 7
#define HTA_ChSceneLChangeHvacMode              92      // 1 Bit, Bit 6
#define     HTA_ChSceneLChangeHvacModeMask 0x40
#define     HTA_ChSceneLChangeHvacModeShift 6
#define HTA_ChSceneLChangeTargetTempInput       92      // 1 Bit, Bit 5
#define     HTA_ChSceneLChangeTargetTempInputMask 0x20
#define     HTA_ChSceneLChangeTargetTempInputShift 5
#define HTA_ChSceneLChangeTargetTempShift       92      // 1 Bit, Bit 4
#define     HTA_ChSceneLChangeTargetTempShiftMask 0x10
#define     HTA_ChSceneLChangeTargetTempShiftShift 4
#define HTA_ChSceneLHvacMode                    92      // 2 Bits, Bit 3-2
#define     HTA_ChSceneLHvacModeMask 0x0C
#define     HTA_ChSceneLHvacModeShift 2
#define HTA_ChSceneLTargetTempShift             92      // 2 Bits, Bit 1-0
#define     HTA_ChSceneLTargetTempShiftMask 0x03
#define     HTA_ChSceneLTargetTempShiftShift 0
#define HTA_ChSceneLNumber                      93      // 8 Bits, Bit 7-0
#define HTA_ChSceneLTargetTemp                  94      // int8_t

// Kanalaktivität
#define ParamHTA_ChActive                            ((knx.paramByte(HTA_ParamCalcIndex(HTA_ChActive)) & HTA_ChActiveMask) >> HTA_ChActiveShift)
// Regelungsart
#define ParamHTA_ChControlMode                       ((knx.paramByte(HTA_ParamCalcIndex(HTA_ChControlMode)) & HTA_ChControlModeMask) >> HTA_ChControlModeShift)
// Betriebsmodus
#define ParamHTA_ChOperationMode                     ((knx.paramByte(HTA_ParamCalcIndex(HTA_ChOperationMode)) & HTA_ChOperationModeMask) >> HTA_ChOperationModeShift)
// 
#define ParamHTA_ChSetValueZero                      ((bool)(knx.paramByte(HTA_ParamCalcIndex(HTA_ChSetValueZero)) & HTA_ChSetValueZeroMask))
// Soll-/Ist-Differenz
#define ParamHTA_ChHeatingProportional               (knx.paramByte(HTA_ParamCalcIndex(HTA_ChHeatingProportional)))
// Nachstellzeit
#define ParamHTA_ChHeatingResetTime                  (knx.paramByte(HTA_ParamCalcIndex(HTA_ChHeatingResetTime)))
// Soll-/Ist-Differenz
#define ParamHTA_ChCoolingProportional               (knx.paramByte(HTA_ParamCalcIndex(HTA_ChCoolingProportional)))
// Nachstellzeit
#define ParamHTA_ChCoolingResetTime                  (knx.paramByte(HTA_ParamCalcIndex(HTA_ChCoolingResetTime)))
// Sollwert Komfort
#define ParamHTA_ChTargetTempHeatingComfort          ((int8_t)knx.paramByte(HTA_ParamCalcIndex(HTA_ChTargetTempHeatingComfort)))
// Sollwert Standby
#define ParamHTA_ChTargetTempHeatingStandby          ((int8_t)knx.paramByte(HTA_ParamCalcIndex(HTA_ChTargetTempHeatingStandby)))
// Sollwert Nacht
#define ParamHTA_ChTargetTempHeatingNight            ((int8_t)knx.paramByte(HTA_ParamCalcIndex(HTA_ChTargetTempHeatingNight)))
// Sollwert Frostschutz
#define ParamHTA_ChTargetTempHeatingProtect          ((int8_t)knx.paramByte(HTA_ParamCalcIndex(HTA_ChTargetTempHeatingProtect)))
// Sollwert Komfort
#define ParamHTA_ChTargetTempCoolingComfort          ((int8_t)knx.paramByte(HTA_ParamCalcIndex(HTA_ChTargetTempCoolingComfort)))
// Sollwert Standby
#define ParamHTA_ChTargetTempCoolingStandby          ((int8_t)knx.paramByte(HTA_ParamCalcIndex(HTA_ChTargetTempCoolingStandby)))
// Sollwert Nacht
#define ParamHTA_ChTargetTempCoolingNight            ((int8_t)knx.paramByte(HTA_ParamCalcIndex(HTA_ChTargetTempCoolingNight)))
// Sollwert Hitzeschutz
#define ParamHTA_ChTargetTempCoolingProtect          ((int8_t)knx.paramByte(HTA_ParamCalcIndex(HTA_ChTargetTempCoolingProtect)))
// HVAC-Modus Priorität
#define ParamHTA_ChHvacModePriority                  ((bool)(knx.paramByte(HTA_ParamCalcIndex(HTA_ChHvacModePriority)) & HTA_ChHvacModePriorityMask))
// Sollwerte bei HVAC-Modus-Wechsel zurücksetzen
#define ParamHTA_ChTargetTempResetOnHvacModeChange   ((bool)(knx.paramByte(HTA_ParamCalcIndex(HTA_ChTargetTempResetOnHvacModeChange)) & HTA_ChTargetTempResetOnHvacModeChangeMask))
// Maximale Sollwertverschiebung
#define ParamHTA_ChTargetTempShiftMax                (knx.paramByte(HTA_ParamCalcIndex(HTA_ChTargetTempShiftMax)))
// Sollwertverschiebung Schritt
#define ParamHTA_ChTargetTempShift                   ((knx.paramByte(HTA_ParamCalcIndex(HTA_ChTargetTempShift)) & HTA_ChTargetTempShiftMask) >> HTA_ChTargetTempShiftShift)
// Sollwertverschiebung bei HVAC-Modus-Wechsel zurücksetzen
#define ParamHTA_ChTargetTempShiftResetOnHvacModeChange ((bool)(knx.paramByte(HTA_ParamCalcIndex(HTA_ChTargetTempShiftResetOnHvacModeChange)) & HTA_ChTargetTempShiftResetOnHvacModeChangeMask))
// Sollwertverschiebung bei neuem Sollwert zurücksetzen
#define ParamHTA_ChTargetTempShiftResetOnNewTargetTemp ((bool)(knx.paramByte(HTA_ParamCalcIndex(HTA_ChTargetTempShiftResetOnNewTargetTemp)) & HTA_ChTargetTempShiftResetOnNewTargetTempMask))
// Komfort
#define ParamHTA_ChTargetTempShiftApplyToComfort     ((bool)(knx.paramByte(HTA_ParamCalcIndex(HTA_ChTargetTempShiftApplyToComfort)) & HTA_ChTargetTempShiftApplyToComfortMask))
// Standby
#define ParamHTA_ChTargetTempShiftApplyToStandby     ((bool)(knx.paramByte(HTA_ParamCalcIndex(HTA_ChTargetTempShiftApplyToStandby)) & HTA_ChTargetTempShiftApplyToStandbyMask))
// Nacht
#define ParamHTA_ChTargetTempShiftApplyToNight       ((bool)(knx.paramByte(HTA_ParamCalcIndex(HTA_ChTargetTempShiftApplyToNight)) & HTA_ChTargetTempShiftApplyToNightMask))
// Aktion bei Verschiebung in Nacht
#define ParamHTA_ChTargetTempShiftActionNight        ((bool)(knx.paramByte(HTA_ParamCalcIndex(HTA_ChTargetTempShiftActionNight)) & HTA_ChTargetTempShiftActionNightMask))
// Aktion bei Verschiebung in Standby
#define ParamHTA_ChTargetTempShiftActionStandby      ((bool)(knx.paramByte(HTA_ParamCalcIndex(HTA_ChTargetTempShiftActionStandby)) & HTA_ChTargetTempShiftActionStandbyMask))
// Stellwertänderungen senden
#define ParamHTA_ChSetValueChangeSend                ((bool)(knx.paramByte(HTA_ParamCalcIndex(HTA_ChSetValueChangeSend)) & HTA_ChSetValueChangeSendMask))
// Sollwertänderungen senden
#define ParamHTA_ChTargetTempChangeSend              ((bool)(knx.paramByte(HTA_ParamCalcIndex(HTA_ChTargetTempChangeSend)) & HTA_ChTargetTempChangeSendMask))
// Kanal bei Anforderung und max. Stellwert berücksichtigen
#define ParamHTA_ChConsiderForRequestAndMaxSetValue  ((bool)(knx.paramByte(HTA_ParamCalcIndex(HTA_ChConsiderForRequestAndMaxSetValue)) & HTA_ChConsiderForRequestAndMaxSetValueMask))
// Zeitbasis
#define ParamHTA_ChSetValueCyclicBase                ((knx.paramByte(HTA_ParamCalcIndex(HTA_ChSetValueCyclicBase)) & HTA_ChSetValueCyclicBaseMask) >> HTA_ChSetValueCyclicBaseShift)
// Zeit
#define ParamHTA_ChSetValueCyclicTime                (knx.paramWord(HTA_ParamCalcIndex(HTA_ChSetValueCyclicTime)) & HTA_ChSetValueCyclicTimeMask)
// Zeit (in Millisekunden)
#define ParamHTA_ChSetValueCyclicTimeMS              (paramDelay(knx.paramWord(HTA_ParamCalcIndex(HTA_ChSetValueCyclicTime))))
// Zeitbasis
#define ParamHTA_ChTargetTempCyclicBase              ((knx.paramByte(HTA_ParamCalcIndex(HTA_ChTargetTempCyclicBase)) & HTA_ChTargetTempCyclicBaseMask) >> HTA_ChTargetTempCyclicBaseShift)
// Zeit
#define ParamHTA_ChTargetTempCyclicTime              (knx.paramWord(HTA_ParamCalcIndex(HTA_ChTargetTempCyclicTime)) & HTA_ChTargetTempCyclicTimeMask)
// Zeit (in Millisekunden)
#define ParamHTA_ChTargetTempCyclicTimeMS            (paramDelay(knx.paramWord(HTA_ParamCalcIndex(HTA_ChTargetTempCyclicTime))))
// Zwangsstellung aktivieren
#define ParamHTA_ChEnforcedPosition                  ((bool)(knx.paramByte(HTA_ParamCalcIndex(HTA_ChEnforcedPosition)) & HTA_ChEnforcedPositionMask))
// Stellwert Zwangsstellung Heizen
#define ParamHTA_ChEnforcedSetValueHeatingOrExtern   (knx.paramByte(HTA_ParamCalcIndex(HTA_ChEnforcedSetValueHeatingOrExtern)))
// Stellwert Zwangsstellung Kühlen
#define ParamHTA_ChEnforcedSetValueCooling           (knx.paramByte(HTA_ParamCalcIndex(HTA_ChEnforcedSetValueCooling)))
// Notbetrieb aktivieren
#define ParamHTA_ChEmergencyMode                     ((bool)(knx.paramByte(HTA_ParamCalcIndex(HTA_ChEmergencyMode)) & HTA_ChEmergencyModeMask))
// Notbetrieb senden
#define ParamHTA_ChEmergencyModeChangeSend           ((bool)(knx.paramByte(HTA_ParamCalcIndex(HTA_ChEmergencyModeChangeSend)) & HTA_ChEmergencyModeChangeSendMask))
// Zeitbasis
#define ParamHTA_ChEmergencyModeDelayBase            ((knx.paramByte(HTA_ParamCalcIndex(HTA_ChEmergencyModeDelayBase)) & HTA_ChEmergencyModeDelayBaseMask) >> HTA_ChEmergencyModeDelayBaseShift)
// Zeit
#define ParamHTA_ChEmergencyModeDelayTime            (knx.paramWord(HTA_ParamCalcIndex(HTA_ChEmergencyModeDelayTime)) & HTA_ChEmergencyModeDelayTimeMask)
// Zeit (in Millisekunden)
#define ParamHTA_ChEmergencyModeDelayTimeMS          (paramDelay(knx.paramWord(HTA_ParamCalcIndex(HTA_ChEmergencyModeDelayTime))))
// Stellwert Notbetrieb Heizen
#define ParamHTA_ChEmergencyModeSetValueHeatingOrExtern (knx.paramByte(HTA_ParamCalcIndex(HTA_ChEmergencyModeSetValueHeatingOrExtern)))
// Stellwert Notbetrieb Kühlen
#define ParamHTA_ChEmergencyModeSetValueCooling      (knx.paramByte(HTA_ParamCalcIndex(HTA_ChEmergencyModeSetValueCooling)))
// Zeitbasis
#define ParamHTA_ChEmergencyModeCyclicBase           ((knx.paramByte(HTA_ParamCalcIndex(HTA_ChEmergencyModeCyclicBase)) & HTA_ChEmergencyModeCyclicBaseMask) >> HTA_ChEmergencyModeCyclicBaseShift)
// Zeit
#define ParamHTA_ChEmergencyModeCyclicTime           (knx.paramWord(HTA_ParamCalcIndex(HTA_ChEmergencyModeCyclicTime)) & HTA_ChEmergencyModeCyclicTimeMask)
// Zeit (in Millisekunden)
#define ParamHTA_ChEmergencyModeCyclicTimeMS         (paramDelay(knx.paramWord(HTA_ParamCalcIndex(HTA_ChEmergencyModeCyclicTime))))
// Manueller Modus aktivieren
#define ParamHTA_ChManualMode                        ((bool)(knx.paramByte(HTA_ParamCalcIndex(HTA_ChManualMode)) & HTA_ChManualModeMask))
// Manueller Modus senden
#define ParamHTA_ChManualModeChangeSend              ((bool)(knx.paramByte(HTA_ParamCalcIndex(HTA_ChManualModeChangeSend)) & HTA_ChManualModeChangeSendMask))
// Umschaltung auf Automatik
#define ParamHTA_ChManualModeChangeToAuto            (knx.paramByte(HTA_ParamCalcIndex(HTA_ChManualModeChangeToAuto)) & HTA_ChManualModeChangeToAutoMask)
// Stellwert bei Aus
#define ParamHTA_ChManualModeSetValueOff             (knx.paramByte(HTA_ParamCalcIndex(HTA_ChManualModeSetValueOff)))
// Stellwert bei An
#define ParamHTA_ChManualModeSetValueOn              (knx.paramByte(HTA_ParamCalcIndex(HTA_ChManualModeSetValueOn)))
// Zeitbasis
#define ParamHTA_ChManualModeCyclicBase              ((knx.paramByte(HTA_ParamCalcIndex(HTA_ChManualModeCyclicBase)) & HTA_ChManualModeCyclicBaseMask) >> HTA_ChManualModeCyclicBaseShift)
// Zeit
#define ParamHTA_ChManualModeCyclicTime              (knx.paramWord(HTA_ParamCalcIndex(HTA_ChManualModeCyclicTime)) & HTA_ChManualModeCyclicTimeMask)
// Zeit (in Millisekunden)
#define ParamHTA_ChManualModeCyclicTimeMS            (paramDelay(knx.paramWord(HTA_ParamCalcIndex(HTA_ChManualModeCyclicTime))))
// Zeitbasis
#define ParamHTA_ChManualModeChangeToAutoBase        ((knx.paramByte(HTA_ParamCalcIndex(HTA_ChManualModeChangeToAutoBase)) & HTA_ChManualModeChangeToAutoBaseMask) >> HTA_ChManualModeChangeToAutoBaseShift)
// Zeit
#define ParamHTA_ChManualModeChangeToAutoTime        (knx.paramWord(HTA_ParamCalcIndex(HTA_ChManualModeChangeToAutoTime)) & HTA_ChManualModeChangeToAutoTimeMask)
// Zeit (in Millisekunden)
#define ParamHTA_ChManualModeChangeToAutoTimeMS      (paramDelay(knx.paramWord(HTA_ParamCalcIndex(HTA_ChManualModeChangeToAutoTime))))
// Max. Stromstärke Schließen
#define ParamHTA_ChMotorMaxCurrentClose              (knx.paramByte(HTA_ParamCalcIndex(HTA_ChMotorMaxCurrentClose)))
// Max. Stromstärke Öffnen
#define ParamHTA_ChMotorMaxCurrentOpen               (knx.paramByte(HTA_ParamCalcIndex(HTA_ChMotorMaxCurrentOpen)))
// Szenen aktivieren
#define ParamHTA_ChScenesActive                      ((bool)(knx.paramByte(HTA_ParamCalcIndex(HTA_ChScenesActive)) & HTA_ChScenesActiveMask))
// PID-Controller: P
#define ParamHTA_ChHeatingPidP                       (knx.paramWord(HTA_ParamCalcIndex(HTA_ChHeatingPidP)))
// PID-Controller: I
#define ParamHTA_ChHeatingPidI                       (knx.paramWord(HTA_ParamCalcIndex(HTA_ChHeatingPidI)))
// PID-Controller: D
#define ParamHTA_ChHeatingPidD                       (knx.paramWord(HTA_ParamCalcIndex(HTA_ChHeatingPidD)))
// PID-Controller: Interval
#define ParamHTA_ChHeatingPidInterval                (knx.paramWord(HTA_ParamCalcIndex(HTA_ChHeatingPidInterval)))
// PID-Controller: P
#define ParamHTA_ChCoolingPidP                       (knx.paramWord(HTA_ParamCalcIndex(HTA_ChCoolingPidP)))
// PID-Controller: I
#define ParamHTA_ChCoolingPidI                       (knx.paramWord(HTA_ParamCalcIndex(HTA_ChCoolingPidI)))
// PID-Controller: D
#define ParamHTA_ChCoolingPidD                       (knx.paramWord(HTA_ParamCalcIndex(HTA_ChCoolingPidD)))
// PID-Controller: Interval
#define ParamHTA_ChCoolingPidInterval                (knx.paramWord(HTA_ParamCalcIndex(HTA_ChCoolingPidInterval)))
// Szene aktiv
#define ParamHTA_ChSceneAActive                      ((bool)(knx.paramByte(HTA_ParamCalcIndex(HTA_ChSceneAActive)) & HTA_ChSceneAActiveMask))
// HVAC-Modus ändern
#define ParamHTA_ChSceneAChangeHvacMode              ((bool)(knx.paramByte(HTA_ParamCalcIndex(HTA_ChSceneAChangeHvacMode)) & HTA_ChSceneAChangeHvacModeMask))
// Sollwert ändern
#define ParamHTA_ChSceneAChangeTargetTempInput       ((bool)(knx.paramByte(HTA_ParamCalcIndex(HTA_ChSceneAChangeTargetTempInput)) & HTA_ChSceneAChangeTargetTempInputMask))
// Sollwertverschiebung ändern
#define ParamHTA_ChSceneAChangeTargetTempShift       ((bool)(knx.paramByte(HTA_ParamCalcIndex(HTA_ChSceneAChangeTargetTempShift)) & HTA_ChSceneAChangeTargetTempShiftMask))
// HVAC-Modus
#define ParamHTA_ChSceneAHvacMode                    ((knx.paramByte(HTA_ParamCalcIndex(HTA_ChSceneAHvacMode)) & HTA_ChSceneAHvacModeMask) >> HTA_ChSceneAHvacModeShift)
// Sollwertverschiebung
#define ParamHTA_ChSceneATargetTempShift             (knx.paramByte(HTA_ParamCalcIndex(HTA_ChSceneATargetTempShift)) & HTA_ChSceneATargetTempShiftMask)
// Szene Nummer
#define ParamHTA_ChSceneANumber                      (knx.paramByte(HTA_ParamCalcIndex(HTA_ChSceneANumber)))
// Sollwert
#define ParamHTA_ChSceneATargetTemp                  ((int8_t)knx.paramByte(HTA_ParamCalcIndex(HTA_ChSceneATargetTemp)))
// Szene aktiv
#define ParamHTA_ChSceneBActive                      ((bool)(knx.paramByte(HTA_ParamCalcIndex(HTA_ChSceneBActive)) & HTA_ChSceneBActiveMask))
// HVAC-Modus ändern
#define ParamHTA_ChSceneBChangeHvacMode              ((bool)(knx.paramByte(HTA_ParamCalcIndex(HTA_ChSceneBChangeHvacMode)) & HTA_ChSceneBChangeHvacModeMask))
// Sollwert ändern
#define ParamHTA_ChSceneBChangeTargetTempInput       ((bool)(knx.paramByte(HTA_ParamCalcIndex(HTA_ChSceneBChangeTargetTempInput)) & HTA_ChSceneBChangeTargetTempInputMask))
// Sollwertverschiebung ändern
#define ParamHTA_ChSceneBChangeTargetTempShift       ((bool)(knx.paramByte(HTA_ParamCalcIndex(HTA_ChSceneBChangeTargetTempShift)) & HTA_ChSceneBChangeTargetTempShiftMask))
// HVAC-Modus
#define ParamHTA_ChSceneBHvacMode                    ((knx.paramByte(HTA_ParamCalcIndex(HTA_ChSceneBHvacMode)) & HTA_ChSceneBHvacModeMask) >> HTA_ChSceneBHvacModeShift)
// Sollwertverschiebung
#define ParamHTA_ChSceneBTargetTempShift             (knx.paramByte(HTA_ParamCalcIndex(HTA_ChSceneBTargetTempShift)) & HTA_ChSceneBTargetTempShiftMask)
// Szene Nummer
#define ParamHTA_ChSceneBNumber                      (knx.paramByte(HTA_ParamCalcIndex(HTA_ChSceneBNumber)))
// Sollwert
#define ParamHTA_ChSceneBTargetTemp                  ((int8_t)knx.paramByte(HTA_ParamCalcIndex(HTA_ChSceneBTargetTemp)))
// Szene aktiv
#define ParamHTA_ChSceneCActive                      ((bool)(knx.paramByte(HTA_ParamCalcIndex(HTA_ChSceneCActive)) & HTA_ChSceneCActiveMask))
// HVAC-Modus ändern
#define ParamHTA_ChSceneCChangeHvacMode              ((bool)(knx.paramByte(HTA_ParamCalcIndex(HTA_ChSceneCChangeHvacMode)) & HTA_ChSceneCChangeHvacModeMask))
// Sollwert ändern
#define ParamHTA_ChSceneCChangeTargetTempInput       ((bool)(knx.paramByte(HTA_ParamCalcIndex(HTA_ChSceneCChangeTargetTempInput)) & HTA_ChSceneCChangeTargetTempInputMask))
// Sollwertverschiebung ändern
#define ParamHTA_ChSceneCChangeTargetTempShift       ((bool)(knx.paramByte(HTA_ParamCalcIndex(HTA_ChSceneCChangeTargetTempShift)) & HTA_ChSceneCChangeTargetTempShiftMask))
// HVAC-Modus
#define ParamHTA_ChSceneCHvacMode                    ((knx.paramByte(HTA_ParamCalcIndex(HTA_ChSceneCHvacMode)) & HTA_ChSceneCHvacModeMask) >> HTA_ChSceneCHvacModeShift)
// Sollwertverschiebung
#define ParamHTA_ChSceneCTargetTempShift             (knx.paramByte(HTA_ParamCalcIndex(HTA_ChSceneCTargetTempShift)) & HTA_ChSceneCTargetTempShiftMask)
// Szene Nummer
#define ParamHTA_ChSceneCNumber                      (knx.paramByte(HTA_ParamCalcIndex(HTA_ChSceneCNumber)))
// Sollwert
#define ParamHTA_ChSceneCTargetTemp                  ((int8_t)knx.paramByte(HTA_ParamCalcIndex(HTA_ChSceneCTargetTemp)))
// Szene aktiv
#define ParamHTA_ChSceneDActive                      ((bool)(knx.paramByte(HTA_ParamCalcIndex(HTA_ChSceneDActive)) & HTA_ChSceneDActiveMask))
// HVAC-Modus ändern
#define ParamHTA_ChSceneDChangeHvacMode              ((bool)(knx.paramByte(HTA_ParamCalcIndex(HTA_ChSceneDChangeHvacMode)) & HTA_ChSceneDChangeHvacModeMask))
// Sollwert ändern
#define ParamHTA_ChSceneDChangeTargetTempInput       ((bool)(knx.paramByte(HTA_ParamCalcIndex(HTA_ChSceneDChangeTargetTempInput)) & HTA_ChSceneDChangeTargetTempInputMask))
// Sollwertverschiebung ändern
#define ParamHTA_ChSceneDChangeTargetTempShift       ((bool)(knx.paramByte(HTA_ParamCalcIndex(HTA_ChSceneDChangeTargetTempShift)) & HTA_ChSceneDChangeTargetTempShiftMask))
// HVAC-Modus
#define ParamHTA_ChSceneDHvacMode                    ((knx.paramByte(HTA_ParamCalcIndex(HTA_ChSceneDHvacMode)) & HTA_ChSceneDHvacModeMask) >> HTA_ChSceneDHvacModeShift)
// Sollwertverschiebung
#define ParamHTA_ChSceneDTargetTempShift             (knx.paramByte(HTA_ParamCalcIndex(HTA_ChSceneDTargetTempShift)) & HTA_ChSceneDTargetTempShiftMask)
// Szene Nummer
#define ParamHTA_ChSceneDNumber                      (knx.paramByte(HTA_ParamCalcIndex(HTA_ChSceneDNumber)))
// Sollwert
#define ParamHTA_ChSceneDTargetTemp                  ((int8_t)knx.paramByte(HTA_ParamCalcIndex(HTA_ChSceneDTargetTemp)))
// Szene aktiv
#define ParamHTA_ChSceneEActive                      ((bool)(knx.paramByte(HTA_ParamCalcIndex(HTA_ChSceneEActive)) & HTA_ChSceneEActiveMask))
// HVAC-Modus ändern
#define ParamHTA_ChSceneEChangeHvacMode              ((bool)(knx.paramByte(HTA_ParamCalcIndex(HTA_ChSceneEChangeHvacMode)) & HTA_ChSceneEChangeHvacModeMask))
// Sollwert ändern
#define ParamHTA_ChSceneEChangeTargetTempInput       ((bool)(knx.paramByte(HTA_ParamCalcIndex(HTA_ChSceneEChangeTargetTempInput)) & HTA_ChSceneEChangeTargetTempInputMask))
// Sollwertverschiebung ändern
#define ParamHTA_ChSceneEChangeTargetTempShift       ((bool)(knx.paramByte(HTA_ParamCalcIndex(HTA_ChSceneEChangeTargetTempShift)) & HTA_ChSceneEChangeTargetTempShiftMask))
// HVAC-Modus
#define ParamHTA_ChSceneEHvacMode                    ((knx.paramByte(HTA_ParamCalcIndex(HTA_ChSceneEHvacMode)) & HTA_ChSceneEHvacModeMask) >> HTA_ChSceneEHvacModeShift)
// Sollwertverschiebung
#define ParamHTA_ChSceneETargetTempShift             (knx.paramByte(HTA_ParamCalcIndex(HTA_ChSceneETargetTempShift)) & HTA_ChSceneETargetTempShiftMask)
// Szene Nummer
#define ParamHTA_ChSceneENumber                      (knx.paramByte(HTA_ParamCalcIndex(HTA_ChSceneENumber)))
// Sollwert
#define ParamHTA_ChSceneETargetTemp                  ((int8_t)knx.paramByte(HTA_ParamCalcIndex(HTA_ChSceneETargetTemp)))
// Szene aktiv
#define ParamHTA_ChSceneFActive                      ((bool)(knx.paramByte(HTA_ParamCalcIndex(HTA_ChSceneFActive)) & HTA_ChSceneFActiveMask))
// HVAC-Modus ändern
#define ParamHTA_ChSceneFChangeHvacMode              ((bool)(knx.paramByte(HTA_ParamCalcIndex(HTA_ChSceneFChangeHvacMode)) & HTA_ChSceneFChangeHvacModeMask))
// Sollwert ändern
#define ParamHTA_ChSceneFChangeTargetTempInput       ((bool)(knx.paramByte(HTA_ParamCalcIndex(HTA_ChSceneFChangeTargetTempInput)) & HTA_ChSceneFChangeTargetTempInputMask))
// Sollwertverschiebung ändern
#define ParamHTA_ChSceneFChangeTargetTempShift       ((bool)(knx.paramByte(HTA_ParamCalcIndex(HTA_ChSceneFChangeTargetTempShift)) & HTA_ChSceneFChangeTargetTempShiftMask))
// HVAC-Modus
#define ParamHTA_ChSceneFHvacMode                    ((knx.paramByte(HTA_ParamCalcIndex(HTA_ChSceneFHvacMode)) & HTA_ChSceneFHvacModeMask) >> HTA_ChSceneFHvacModeShift)
// Sollwertverschiebung
#define ParamHTA_ChSceneFTargetTempShift             (knx.paramByte(HTA_ParamCalcIndex(HTA_ChSceneFTargetTempShift)) & HTA_ChSceneFTargetTempShiftMask)
// Szene Nummer
#define ParamHTA_ChSceneFNumber                      (knx.paramByte(HTA_ParamCalcIndex(HTA_ChSceneFNumber)))
// Sollwert
#define ParamHTA_ChSceneFTargetTemp                  ((int8_t)knx.paramByte(HTA_ParamCalcIndex(HTA_ChSceneFTargetTemp)))
// Szene aktiv
#define ParamHTA_ChSceneGActive                      ((bool)(knx.paramByte(HTA_ParamCalcIndex(HTA_ChSceneGActive)) & HTA_ChSceneGActiveMask))
// HVAC-Modus ändern
#define ParamHTA_ChSceneGChangeHvacMode              ((bool)(knx.paramByte(HTA_ParamCalcIndex(HTA_ChSceneGChangeHvacMode)) & HTA_ChSceneGChangeHvacModeMask))
// Sollwert ändern
#define ParamHTA_ChSceneGChangeTargetTempInput       ((bool)(knx.paramByte(HTA_ParamCalcIndex(HTA_ChSceneGChangeTargetTempInput)) & HTA_ChSceneGChangeTargetTempInputMask))
// Sollwertverschiebung ändern
#define ParamHTA_ChSceneGChangeTargetTempShift       ((bool)(knx.paramByte(HTA_ParamCalcIndex(HTA_ChSceneGChangeTargetTempShift)) & HTA_ChSceneGChangeTargetTempShiftMask))
// HVAC-Modus
#define ParamHTA_ChSceneGHvacMode                    ((knx.paramByte(HTA_ParamCalcIndex(HTA_ChSceneGHvacMode)) & HTA_ChSceneGHvacModeMask) >> HTA_ChSceneGHvacModeShift)
// Sollwertverschiebung
#define ParamHTA_ChSceneGTargetTempShift             (knx.paramByte(HTA_ParamCalcIndex(HTA_ChSceneGTargetTempShift)) & HTA_ChSceneGTargetTempShiftMask)
// Szene Nummer
#define ParamHTA_ChSceneGNumber                      (knx.paramByte(HTA_ParamCalcIndex(HTA_ChSceneGNumber)))
// Sollwert
#define ParamHTA_ChSceneGTargetTemp                  ((int8_t)knx.paramByte(HTA_ParamCalcIndex(HTA_ChSceneGTargetTemp)))
// Szene aktiv
#define ParamHTA_ChSceneHActive                      ((bool)(knx.paramByte(HTA_ParamCalcIndex(HTA_ChSceneHActive)) & HTA_ChSceneHActiveMask))
// HVAC-Modus ändern
#define ParamHTA_ChSceneHChangeHvacMode              ((bool)(knx.paramByte(HTA_ParamCalcIndex(HTA_ChSceneHChangeHvacMode)) & HTA_ChSceneHChangeHvacModeMask))
// Sollwert ändern
#define ParamHTA_ChSceneHChangeTargetTempInput       ((bool)(knx.paramByte(HTA_ParamCalcIndex(HTA_ChSceneHChangeTargetTempInput)) & HTA_ChSceneHChangeTargetTempInputMask))
// Sollwertverschiebung ändern
#define ParamHTA_ChSceneHChangeTargetTempShift       ((bool)(knx.paramByte(HTA_ParamCalcIndex(HTA_ChSceneHChangeTargetTempShift)) & HTA_ChSceneHChangeTargetTempShiftMask))
// HVAC-Modus
#define ParamHTA_ChSceneHHvacMode                    ((knx.paramByte(HTA_ParamCalcIndex(HTA_ChSceneHHvacMode)) & HTA_ChSceneHHvacModeMask) >> HTA_ChSceneHHvacModeShift)
// Sollwertverschiebung
#define ParamHTA_ChSceneHTargetTempShift             (knx.paramByte(HTA_ParamCalcIndex(HTA_ChSceneHTargetTempShift)) & HTA_ChSceneHTargetTempShiftMask)
// Szene Nummer
#define ParamHTA_ChSceneHNumber                      (knx.paramByte(HTA_ParamCalcIndex(HTA_ChSceneHNumber)))
// Sollwert
#define ParamHTA_ChSceneHTargetTemp                  ((int8_t)knx.paramByte(HTA_ParamCalcIndex(HTA_ChSceneHTargetTemp)))
// Szene aktiv
#define ParamHTA_ChSceneIActive                      ((bool)(knx.paramByte(HTA_ParamCalcIndex(HTA_ChSceneIActive)) & HTA_ChSceneIActiveMask))
// HVAC-Modus ändern
#define ParamHTA_ChSceneIChangeHvacMode              ((bool)(knx.paramByte(HTA_ParamCalcIndex(HTA_ChSceneIChangeHvacMode)) & HTA_ChSceneIChangeHvacModeMask))
// Sollwert ändern
#define ParamHTA_ChSceneIChangeTargetTempInput       ((bool)(knx.paramByte(HTA_ParamCalcIndex(HTA_ChSceneIChangeTargetTempInput)) & HTA_ChSceneIChangeTargetTempInputMask))
// Sollwertverschiebung ändern
#define ParamHTA_ChSceneIChangeTargetTempShift       ((bool)(knx.paramByte(HTA_ParamCalcIndex(HTA_ChSceneIChangeTargetTempShift)) & HTA_ChSceneIChangeTargetTempShiftMask))
// HVAC-Modus
#define ParamHTA_ChSceneIHvacMode                    ((knx.paramByte(HTA_ParamCalcIndex(HTA_ChSceneIHvacMode)) & HTA_ChSceneIHvacModeMask) >> HTA_ChSceneIHvacModeShift)
// Sollwertverschiebung
#define ParamHTA_ChSceneITargetTempShift             (knx.paramByte(HTA_ParamCalcIndex(HTA_ChSceneITargetTempShift)) & HTA_ChSceneITargetTempShiftMask)
// Szene Nummer
#define ParamHTA_ChSceneINumber                      (knx.paramByte(HTA_ParamCalcIndex(HTA_ChSceneINumber)))
// Sollwert
#define ParamHTA_ChSceneITargetTemp                  ((int8_t)knx.paramByte(HTA_ParamCalcIndex(HTA_ChSceneITargetTemp)))
// Szene aktiv
#define ParamHTA_ChSceneJActive                      ((bool)(knx.paramByte(HTA_ParamCalcIndex(HTA_ChSceneJActive)) & HTA_ChSceneJActiveMask))
// HVAC-Modus ändern
#define ParamHTA_ChSceneJChangeHvacMode              ((bool)(knx.paramByte(HTA_ParamCalcIndex(HTA_ChSceneJChangeHvacMode)) & HTA_ChSceneJChangeHvacModeMask))
// Sollwert ändern
#define ParamHTA_ChSceneJChangeTargetTempInput       ((bool)(knx.paramByte(HTA_ParamCalcIndex(HTA_ChSceneJChangeTargetTempInput)) & HTA_ChSceneJChangeTargetTempInputMask))
// Sollwertverschiebung ändern
#define ParamHTA_ChSceneJChangeTargetTempShift       ((bool)(knx.paramByte(HTA_ParamCalcIndex(HTA_ChSceneJChangeTargetTempShift)) & HTA_ChSceneJChangeTargetTempShiftMask))
// HVAC-Modus
#define ParamHTA_ChSceneJHvacMode                    ((knx.paramByte(HTA_ParamCalcIndex(HTA_ChSceneJHvacMode)) & HTA_ChSceneJHvacModeMask) >> HTA_ChSceneJHvacModeShift)
// Sollwertverschiebung
#define ParamHTA_ChSceneJTargetTempShift             (knx.paramByte(HTA_ParamCalcIndex(HTA_ChSceneJTargetTempShift)) & HTA_ChSceneJTargetTempShiftMask)
// Szene Nummer
#define ParamHTA_ChSceneJNumber                      (knx.paramByte(HTA_ParamCalcIndex(HTA_ChSceneJNumber)))
// Sollwert
#define ParamHTA_ChSceneJTargetTemp                  ((int8_t)knx.paramByte(HTA_ParamCalcIndex(HTA_ChSceneJTargetTemp)))
// Szene aktiv
#define ParamHTA_ChSceneKActive                      ((bool)(knx.paramByte(HTA_ParamCalcIndex(HTA_ChSceneKActive)) & HTA_ChSceneKActiveMask))
// HVAC-Modus ändern
#define ParamHTA_ChSceneKChangeHvacMode              ((bool)(knx.paramByte(HTA_ParamCalcIndex(HTA_ChSceneKChangeHvacMode)) & HTA_ChSceneKChangeHvacModeMask))
// Sollwert ändern
#define ParamHTA_ChSceneKChangeTargetTempInput       ((bool)(knx.paramByte(HTA_ParamCalcIndex(HTA_ChSceneKChangeTargetTempInput)) & HTA_ChSceneKChangeTargetTempInputMask))
// Sollwertverschiebung ändern
#define ParamHTA_ChSceneKChangeTargetTempShift       ((bool)(knx.paramByte(HTA_ParamCalcIndex(HTA_ChSceneKChangeTargetTempShift)) & HTA_ChSceneKChangeTargetTempShiftMask))
// HVAC-Modus
#define ParamHTA_ChSceneKHvacMode                    ((knx.paramByte(HTA_ParamCalcIndex(HTA_ChSceneKHvacMode)) & HTA_ChSceneKHvacModeMask) >> HTA_ChSceneKHvacModeShift)
// Sollwertverschiebung
#define ParamHTA_ChSceneKTargetTempShift             (knx.paramByte(HTA_ParamCalcIndex(HTA_ChSceneKTargetTempShift)) & HTA_ChSceneKTargetTempShiftMask)
// Szene Nummer
#define ParamHTA_ChSceneKNumber                      (knx.paramByte(HTA_ParamCalcIndex(HTA_ChSceneKNumber)))
// Sollwert
#define ParamHTA_ChSceneKTargetTemp                  ((int8_t)knx.paramByte(HTA_ParamCalcIndex(HTA_ChSceneKTargetTemp)))
// Szene aktiv
#define ParamHTA_ChSceneLActive                      ((bool)(knx.paramByte(HTA_ParamCalcIndex(HTA_ChSceneLActive)) & HTA_ChSceneLActiveMask))
// HVAC-Modus ändern
#define ParamHTA_ChSceneLChangeHvacMode              ((bool)(knx.paramByte(HTA_ParamCalcIndex(HTA_ChSceneLChangeHvacMode)) & HTA_ChSceneLChangeHvacModeMask))
// Sollwert ändern
#define ParamHTA_ChSceneLChangeTargetTempInput       ((bool)(knx.paramByte(HTA_ParamCalcIndex(HTA_ChSceneLChangeTargetTempInput)) & HTA_ChSceneLChangeTargetTempInputMask))
// Sollwertverschiebung ändern
#define ParamHTA_ChSceneLChangeTargetTempShift       ((bool)(knx.paramByte(HTA_ParamCalcIndex(HTA_ChSceneLChangeTargetTempShift)) & HTA_ChSceneLChangeTargetTempShiftMask))
// HVAC-Modus
#define ParamHTA_ChSceneLHvacMode                    ((knx.paramByte(HTA_ParamCalcIndex(HTA_ChSceneLHvacMode)) & HTA_ChSceneLHvacModeMask) >> HTA_ChSceneLHvacModeShift)
// Sollwertverschiebung
#define ParamHTA_ChSceneLTargetTempShift             (knx.paramByte(HTA_ParamCalcIndex(HTA_ChSceneLTargetTempShift)) & HTA_ChSceneLTargetTempShiftMask)
// Szene Nummer
#define ParamHTA_ChSceneLNumber                      (knx.paramByte(HTA_ParamCalcIndex(HTA_ChSceneLNumber)))
// Sollwert
#define ParamHTA_ChSceneLTargetTemp                  ((int8_t)knx.paramByte(HTA_ParamCalcIndex(HTA_ChSceneLTargetTemp)))

// deprecated
#define HTA_KoOffset 500

// Communication objects per channel (multiple occurrence)
#define HTA_KoBlockOffset 500
#define HTA_KoBlockSize 23

#define HTA_KoCalcNumber(index) (index + HTA_KoBlockOffset + _channelIndex * HTA_KoBlockSize)
#define HTA_KoCalcIndex(number) ((number >= HTA_KoCalcNumber(0) && number < HTA_KoCalcNumber(HTA_KoBlockSize)) ? (number - HTA_KoBlockOffset) % HTA_KoBlockSize : -1)
#define HTA_KoCalcChannel(number) ((number >= HTA_KoBlockOffset && number < HTA_KoBlockOffset + HTA_ChannelCount * HTA_KoBlockSize) ? (number - HTA_KoBlockOffset) / HTA_KoBlockSize : -1)

#define HTA_KoChSetValueInput 0
#define HTA_KoChSetValueStatusHeatingOrExtern 1
#define HTA_KoChSetValueStatusCooling 2
#define HTA_KoChHvacModeInput 3
#define HTA_KoChHvacModeInputComfort 4
#define HTA_KoChHvacModeInputNight 5
#define HTA_KoChHvacModeInputProtect 6
#define HTA_KoChHvacModeStatus 7
#define HTA_KoChRoomTempInput 8
#define HTA_KoChTargetTempInput 9
#define HTA_KoChTargetTempStatus 10
#define HTA_KoChTargetTempShiftInput 11
#define HTA_KoChTargetTempShiftStep 12
#define HTA_KoChTargetTempShiftStatus 13
#define HTA_KoChTargetTempLockHeating 14
#define HTA_KoChTargetTempLockHeatingStatus 15
#define HTA_KoChTargetTempLockCooling 16
#define HTA_KoChTargetTempLockCoolingStatus 17
#define HTA_KoChEnforcedPosition 18
#define HTA_KoChEmergencyModeStatus 19
#define HTA_KoChManualMode 20
#define HTA_KoChManualModeStatus 21
#define HTA_KoChScene 22

// 
#define KoHTA_ChSetValueInput                     (knx.getGroupObject(HTA_KoCalcNumber(HTA_KoChSetValueInput)))
// 
#define KoHTA_ChSetValueStatusHeatingOrExtern     (knx.getGroupObject(HTA_KoCalcNumber(HTA_KoChSetValueStatusHeatingOrExtern)))
// 
#define KoHTA_ChSetValueStatusCooling             (knx.getGroupObject(HTA_KoCalcNumber(HTA_KoChSetValueStatusCooling)))
// 
#define KoHTA_ChHvacModeInput                     (knx.getGroupObject(HTA_KoCalcNumber(HTA_KoChHvacModeInput)))
// 
#define KoHTA_ChHvacModeInputComfort              (knx.getGroupObject(HTA_KoCalcNumber(HTA_KoChHvacModeInputComfort)))
// 
#define KoHTA_ChHvacModeInputNight                (knx.getGroupObject(HTA_KoCalcNumber(HTA_KoChHvacModeInputNight)))
// 
#define KoHTA_ChHvacModeInputProtect              (knx.getGroupObject(HTA_KoCalcNumber(HTA_KoChHvacModeInputProtect)))
// 
#define KoHTA_ChHvacModeStatus                    (knx.getGroupObject(HTA_KoCalcNumber(HTA_KoChHvacModeStatus)))
// 
#define KoHTA_ChRoomTempInput                     (knx.getGroupObject(HTA_KoCalcNumber(HTA_KoChRoomTempInput)))
// 
#define KoHTA_ChTargetTempInput                   (knx.getGroupObject(HTA_KoCalcNumber(HTA_KoChTargetTempInput)))
// 
#define KoHTA_ChTargetTempStatus                  (knx.getGroupObject(HTA_KoCalcNumber(HTA_KoChTargetTempStatus)))
// 
#define KoHTA_ChTargetTempShiftInput              (knx.getGroupObject(HTA_KoCalcNumber(HTA_KoChTargetTempShiftInput)))
// 
#define KoHTA_ChTargetTempShiftStep               (knx.getGroupObject(HTA_KoCalcNumber(HTA_KoChTargetTempShiftStep)))
// 
#define KoHTA_ChTargetTempShiftStatus             (knx.getGroupObject(HTA_KoCalcNumber(HTA_KoChTargetTempShiftStatus)))
// 
#define KoHTA_ChTargetTempLockHeating             (knx.getGroupObject(HTA_KoCalcNumber(HTA_KoChTargetTempLockHeating)))
// 
#define KoHTA_ChTargetTempLockHeatingStatus       (knx.getGroupObject(HTA_KoCalcNumber(HTA_KoChTargetTempLockHeatingStatus)))
// 
#define KoHTA_ChTargetTempLockCooling             (knx.getGroupObject(HTA_KoCalcNumber(HTA_KoChTargetTempLockCooling)))
// 
#define KoHTA_ChTargetTempLockCoolingStatus       (knx.getGroupObject(HTA_KoCalcNumber(HTA_KoChTargetTempLockCoolingStatus)))
// 
#define KoHTA_ChEnforcedPosition                  (knx.getGroupObject(HTA_KoCalcNumber(HTA_KoChEnforcedPosition)))
// 
#define KoHTA_ChEmergencyModeStatus               (knx.getGroupObject(HTA_KoCalcNumber(HTA_KoChEmergencyModeStatus)))
// 
#define KoHTA_ChManualMode                        (knx.getGroupObject(HTA_KoCalcNumber(HTA_KoChManualMode)))
// 
#define KoHTA_ChManualModeStatus                  (knx.getGroupObject(HTA_KoCalcNumber(HTA_KoChManualModeStatus)))
// 
#define KoHTA_ChScene                             (knx.getGroupObject(HTA_KoCalcNumber(HTA_KoChScene)))

#define WIRE_WireError                           2189      // 1 Bit, Bit 7
#define     WIRE_WireErrorMask 0x80
#define     WIRE_WireErrorShift 7
#define WIRE_IdSearch                            2189      // 1 Bit, Bit 4
#define     WIRE_IdSearchMask 0x10
#define     WIRE_IdSearchShift 4
#define WIRE_IButton1                            2189      // 1 Bit, Bit 3
#define     WIRE_IButton1Mask 0x08
#define     WIRE_IButton1Shift 3
#define WIRE_IButton2                            2189      // 1 Bit, Bit 2
#define     WIRE_IButton2Mask 0x04
#define     WIRE_IButton2Shift 2
#define WIRE_IButton3                            2189      // 1 Bit, Bit 1
#define     WIRE_IButton3Mask 0x02
#define     WIRE_IButton3Shift 1
#define WIRE_Group1                              2190      // 1 Bit, Bit 7
#define     WIRE_Group1Mask 0x80
#define     WIRE_Group1Shift 7
#define WIRE_Group2                              2190      // 1 Bit, Bit 6
#define     WIRE_Group2Mask 0x40
#define     WIRE_Group2Shift 6
#define WIRE_Group3                              2190      // 1 Bit, Bit 5
#define     WIRE_Group3Mask 0x20
#define     WIRE_Group3Shift 5
#define WIRE_Group4                              2190      // 1 Bit, Bit 4
#define     WIRE_Group4Mask 0x10
#define     WIRE_Group4Shift 4
#define WIRE_Group5                              2190      // 1 Bit, Bit 3
#define     WIRE_Group5Mask 0x08
#define     WIRE_Group5Shift 3
#define WIRE_Group6                              2190      // 1 Bit, Bit 2
#define     WIRE_Group6Mask 0x04
#define     WIRE_Group6Shift 2
#define WIRE_Group7                              2190      // 1 Bit, Bit 1
#define     WIRE_Group7Mask 0x02
#define     WIRE_Group7Shift 1
#define WIRE_Group8                              2190      // 1 Bit, Bit 0
#define     WIRE_Group8Mask 0x01
#define     WIRE_Group8Shift 0
#define WIRE_Busmaster1RSTL                      2191      // 4 Bits, Bit 7-4
#define     WIRE_Busmaster1RSTLMask 0xF0
#define     WIRE_Busmaster1RSTLShift 4
#define WIRE_Busmaster1MSP                       2191      // 4 Bits, Bit 3-0
#define     WIRE_Busmaster1MSPMask 0x0F
#define     WIRE_Busmaster1MSPShift 0
#define WIRE_Busmaster1W0L                       2192      // 4 Bits, Bit 7-4
#define     WIRE_Busmaster1W0LMask 0xF0
#define     WIRE_Busmaster1W0LShift 4
#define WIRE_Busmaster1REC0                      2192      // 4 Bits, Bit 3-0
#define     WIRE_Busmaster1REC0Mask 0x0F
#define     WIRE_Busmaster1REC0Shift 0
#define WIRE_Busmaster1WPU                       2193      // 4 Bits, Bit 7-4
#define     WIRE_Busmaster1WPUMask 0xF0
#define     WIRE_Busmaster1WPUShift 4
#define WIRE_VisibleChannels                     2194      // uint8_t
#define WIRE_BusMasterCount                      2195      // 2 Bits, Bit 7-6
#define     WIRE_BusMasterCountMask 0xC0
#define     WIRE_BusMasterCountShift 6

// Fehlerobjekt(e) anzeigen
#define ParamWIRE_WireError                           ((bool)(knx.paramByte(WIRE_WireError) & WIRE_WireErrorMask))
// Sucheinstellung
#define ParamWIRE_IdSearch                            ((bool)(knx.paramByte(WIRE_IdSearch) & WIRE_IdSearchMask))
// iButton auf Busmaster 1 auswerten?
#define ParamWIRE_IButton1                            ((bool)(knx.paramByte(WIRE_IButton1) & WIRE_IButton1Mask))
// iButton auf Busmaster 2 auswerten?
#define ParamWIRE_IButton2                            ((bool)(knx.paramByte(WIRE_IButton2) & WIRE_IButton2Mask))
// iButton auf Busmaster 3 auswerten?
#define ParamWIRE_IButton3                            ((bool)(knx.paramByte(WIRE_IButton3) & WIRE_IButton3Mask))
//                   Typ
#define ParamWIRE_Group1                              ((bool)(knx.paramByte(WIRE_Group1) & WIRE_Group1Mask))
//                   Typ
#define ParamWIRE_Group2                              ((bool)(knx.paramByte(WIRE_Group2) & WIRE_Group2Mask))
//                   Typ
#define ParamWIRE_Group3                              ((bool)(knx.paramByte(WIRE_Group3) & WIRE_Group3Mask))
//                   Typ
#define ParamWIRE_Group4                              ((bool)(knx.paramByte(WIRE_Group4) & WIRE_Group4Mask))
//                   Typ
#define ParamWIRE_Group5                              ((bool)(knx.paramByte(WIRE_Group5) & WIRE_Group5Mask))
//                   Typ
#define ParamWIRE_Group6                              ((bool)(knx.paramByte(WIRE_Group6) & WIRE_Group6Mask))
//                   Typ
#define ParamWIRE_Group7                              ((bool)(knx.paramByte(WIRE_Group7) & WIRE_Group7Mask))
//                   Typ
#define ParamWIRE_Group8                              ((bool)(knx.paramByte(WIRE_Group8) & WIRE_Group8Mask))
// tRSTL (in Mikrosekunden)
#define ParamWIRE_Busmaster1RSTL                      ((knx.paramByte(WIRE_Busmaster1RSTL) & WIRE_Busmaster1RSTLMask) >> WIRE_Busmaster1RSTLShift)
// tMSP (in Mikrosekunden)
#define ParamWIRE_Busmaster1MSP                       (knx.paramByte(WIRE_Busmaster1MSP) & WIRE_Busmaster1MSPMask)
// tW0L (in Mikrosekunden)
#define ParamWIRE_Busmaster1W0L                       ((knx.paramByte(WIRE_Busmaster1W0L) & WIRE_Busmaster1W0LMask) >> WIRE_Busmaster1W0LShift)
// tREC0 (in Mikrosekunden)
#define ParamWIRE_Busmaster1REC0                      (knx.paramByte(WIRE_Busmaster1REC0) & WIRE_Busmaster1REC0Mask)
// RWPU (in Ohm)
#define ParamWIRE_Busmaster1WPU                       ((knx.paramByte(WIRE_Busmaster1WPU) & WIRE_Busmaster1WPUMask) >> WIRE_Busmaster1WPUShift)
// Verfügbare Kanäle
#define ParamWIRE_VisibleChannels                     (knx.paramByte(WIRE_VisibleChannels))
// Installierte Busmaster
#define ParamWIRE_BusMasterCount                      ((knx.paramByte(WIRE_BusMasterCount) & WIRE_BusMasterCountMask) >> WIRE_BusMasterCountShift)

#define WIRE_KoNewId 100
#define WIRE_KoErrorBusmaster1 101
#define WIRE_KoErrorBusmaster2 102
#define WIRE_KoErrorBusmaster3 103
#define WIRE_KoGroup1 104
#define WIRE_KoGroup2 105
#define WIRE_KoGroup3 106
#define WIRE_KoGroup4 107
#define WIRE_KoGroup5 108
#define WIRE_KoGroup6 109
#define WIRE_KoGroup7 110
#define WIRE_KoGroup8 111

// IDs unbekannter Geräte
#define KoWIRE_NewId                               (knx.getGroupObject(WIRE_KoNewId))
// Gerätefehler Busmaster 1
#define KoWIRE_ErrorBusmaster1                     (knx.getGroupObject(WIRE_KoErrorBusmaster1))
// Gerätefehler Busmaster 2
#define KoWIRE_ErrorBusmaster2                     (knx.getGroupObject(WIRE_KoErrorBusmaster2))
// Gerätefehler Busmaster 3
#define KoWIRE_ErrorBusmaster3                     (knx.getGroupObject(WIRE_KoErrorBusmaster3))
// Gruppe 1
#define KoWIRE_Group1                              (knx.getGroupObject(WIRE_KoGroup1))
// Gruppe 2
#define KoWIRE_Group2                              (knx.getGroupObject(WIRE_KoGroup2))
// Gruppe 3
#define KoWIRE_Group3                              (knx.getGroupObject(WIRE_KoGroup3))
// Gruppe 4
#define KoWIRE_Group4                              (knx.getGroupObject(WIRE_KoGroup4))
// Gruppe 5
#define KoWIRE_Group5                              (knx.getGroupObject(WIRE_KoGroup5))
// Gruppe 6
#define KoWIRE_Group6                              (knx.getGroupObject(WIRE_KoGroup6))
// Gruppe 7
#define KoWIRE_Group7                              (knx.getGroupObject(WIRE_KoGroup7))
// Gruppe 8
#define KoWIRE_Group8                              (knx.getGroupObject(WIRE_KoGroup8))

#define WIRE_ChannelCount 30

// Parameter per channel
#define WIRE_ParamBlockOffset 2196
#define WIRE_ParamBlockSize 18
#define WIRE_ParamCalcIndex(index) (index + WIRE_ParamBlockOffset + _channelIndex * WIRE_ParamBlockSize)

#define WIRE_sDeviceId                            0      // char*, 7 Byte
#define     WIRE_sDeviceIdLength 7
#define WIRE_sFamilyCode                          0      // 8 Bits, Bit 7-0
#define WIRE_sId0                                 1      // 4 Bits, Bit 7-4
#define     WIRE_sId0Mask 0xF0
#define     WIRE_sId0Shift 4
#define WIRE_sId1                                 1      // 4 Bits, Bit 3-0
#define     WIRE_sId1Mask 0x0F
#define     WIRE_sId1Shift 0
#define WIRE_sId2                                 2      // 4 Bits, Bit 7-4
#define     WIRE_sId2Mask 0xF0
#define     WIRE_sId2Shift 4
#define WIRE_sId3                                 2      // 4 Bits, Bit 3-0
#define     WIRE_sId3Mask 0x0F
#define     WIRE_sId3Shift 0
#define WIRE_sId4                                 3      // 4 Bits, Bit 7-4
#define     WIRE_sId4Mask 0xF0
#define     WIRE_sId4Shift 4
#define WIRE_sId5                                 3      // 4 Bits, Bit 3-0
#define     WIRE_sId5Mask 0x0F
#define     WIRE_sId5Shift 0
#define WIRE_sId6                                 4      // 4 Bits, Bit 7-4
#define     WIRE_sId6Mask 0xF0
#define     WIRE_sId6Shift 4
#define WIRE_sId7                                 4      // 4 Bits, Bit 3-0
#define     WIRE_sId7Mask 0x0F
#define     WIRE_sId7Shift 0
#define WIRE_sId8                                 5      // 4 Bits, Bit 7-4
#define     WIRE_sId8Mask 0xF0
#define     WIRE_sId8Shift 4
#define WIRE_sId9                                 5      // 4 Bits, Bit 3-0
#define     WIRE_sId9Mask 0x0F
#define     WIRE_sId9Shift 0
#define WIRE_sIdA                                 6      // 4 Bits, Bit 7-4
#define     WIRE_sIdAMask 0xF0
#define     WIRE_sIdAShift 4
#define WIRE_sIdB                                 6      // 4 Bits, Bit 3-0
#define     WIRE_sIdBMask 0x0F
#define     WIRE_sIdBShift 0
#define WIRE_sModelFunction                       7      // 8 Bits, Bit 7-0
#define WIRE_sModelFunctionDS18B20                7      // 8 Bits, Bit 7-0
#define WIRE_sModelFunctionDS2408                 7      // 8 Bits, Bit 7-0
#define WIRE_sModelFunctionDS2413                 7      // 8 Bits, Bit 7-0
#define WIRE_sModelFunctionDS2438                 7      // 8 Bits, Bit 7-0
#define WIRE_sBusMasterSelect1                    8      // 2 Bits, Bit 7-6
#define     WIRE_sBusMasterSelect1Mask 0xC0
#define     WIRE_sBusMasterSelect1Shift 6
#define WIRE_sBusMasterSelect2                    8      // 2 Bits, Bit 7-6
#define     WIRE_sBusMasterSelect2Mask 0xC0
#define     WIRE_sBusMasterSelect2Shift 6
#define WIRE_sBusMasterSelect3                    8      // 2 Bits, Bit 7-6
#define     WIRE_sBusMasterSelect3Mask 0xC0
#define     WIRE_sBusMasterSelect3Shift 6
#define WIRE_siButtonSendStatus                   9      // 1 Bit, Bit 7
#define     WIRE_siButtonSendStatusMask 0x80
#define     WIRE_siButtonSendStatusShift 7
#define WIRE_sGroup1                             10      // 1 Bit, Bit 7
#define     WIRE_sGroup1Mask 0x80
#define     WIRE_sGroup1Shift 7
#define WIRE_sGroup2                             10      // 1 Bit, Bit 6
#define     WIRE_sGroup2Mask 0x40
#define     WIRE_sGroup2Shift 6
#define WIRE_sGroup3                             10      // 1 Bit, Bit 5
#define     WIRE_sGroup3Mask 0x20
#define     WIRE_sGroup3Shift 5
#define WIRE_sGroup4                             10      // 1 Bit, Bit 4
#define     WIRE_sGroup4Mask 0x10
#define     WIRE_sGroup4Shift 4
#define WIRE_sGroup5                             10      // 1 Bit, Bit 3
#define     WIRE_sGroup5Mask 0x08
#define     WIRE_sGroup5Shift 3
#define WIRE_sGroup6                             10      // 1 Bit, Bit 2
#define     WIRE_sGroup6Mask 0x04
#define     WIRE_sGroup6Shift 2
#define WIRE_sGroup7                             10      // 1 Bit, Bit 1
#define     WIRE_sGroup7Mask 0x02
#define     WIRE_sGroup7Shift 1
#define WIRE_sGroup8                             10      // 1 Bit, Bit 0
#define     WIRE_sGroup8Mask 0x01
#define     WIRE_sGroup8Shift 0
#define WIRE_sIOSendStatus                        9      // 1 Bit, Bit 7
#define     WIRE_sIOSendStatusMask 0x80
#define     WIRE_sIOSendStatusShift 7
#define WIRE_sIOReadRequest                       9      // 1 Bit, Bit 6
#define     WIRE_sIOReadRequestMask 0x40
#define     WIRE_sIOReadRequestShift 6
#define WIRE_sIoBitmask0                         10      // 1 Bit, Bit 0
#define     WIRE_sIoBitmask0Mask 0x01
#define     WIRE_sIoBitmask0Shift 0
#define WIRE_sIoBitmask1                         10      // 1 Bit, Bit 1
#define     WIRE_sIoBitmask1Mask 0x02
#define     WIRE_sIoBitmask1Shift 1
#define WIRE_sIoBitmask2                         10      // 1 Bit, Bit 2
#define     WIRE_sIoBitmask2Mask 0x04
#define     WIRE_sIoBitmask2Shift 2
#define WIRE_sIoBitmask3                         10      // 1 Bit, Bit 3
#define     WIRE_sIoBitmask3Mask 0x08
#define     WIRE_sIoBitmask3Shift 3
#define WIRE_sIoBitmask4                         10      // 1 Bit, Bit 4
#define     WIRE_sIoBitmask4Mask 0x10
#define     WIRE_sIoBitmask4Shift 4
#define WIRE_sIoBitmask5                         10      // 1 Bit, Bit 5
#define     WIRE_sIoBitmask5Mask 0x20
#define     WIRE_sIoBitmask5Shift 5
#define WIRE_sIoBitmask6                         10      // 1 Bit, Bit 6
#define     WIRE_sIoBitmask6Mask 0x40
#define     WIRE_sIoBitmask6Shift 6
#define WIRE_sIoBitmask7                         10      // 1 Bit, Bit 7
#define     WIRE_sIoBitmask7Mask 0x80
#define     WIRE_sIoBitmask7Shift 7
#define WIRE_sIoInvertBitmask0                   11      // 1 Bit, Bit 0
#define     WIRE_sIoInvertBitmask0Mask 0x01
#define     WIRE_sIoInvertBitmask0Shift 0
#define WIRE_sIoInvertBitmask1                   11      // 1 Bit, Bit 1
#define     WIRE_sIoInvertBitmask1Mask 0x02
#define     WIRE_sIoInvertBitmask1Shift 1
#define WIRE_sIoInvertBitmask2                   11      // 1 Bit, Bit 2
#define     WIRE_sIoInvertBitmask2Mask 0x04
#define     WIRE_sIoInvertBitmask2Shift 2
#define WIRE_sIoInvertBitmask3                   11      // 1 Bit, Bit 3
#define     WIRE_sIoInvertBitmask3Mask 0x08
#define     WIRE_sIoInvertBitmask3Shift 3
#define WIRE_sIoInvertBitmask4                   11      // 1 Bit, Bit 4
#define     WIRE_sIoInvertBitmask4Mask 0x10
#define     WIRE_sIoInvertBitmask4Shift 4
#define WIRE_sIoInvertBitmask5                   11      // 1 Bit, Bit 5
#define     WIRE_sIoInvertBitmask5Mask 0x20
#define     WIRE_sIoInvertBitmask5Shift 5
#define WIRE_sIoInvertBitmask6                   11      // 1 Bit, Bit 6
#define     WIRE_sIoInvertBitmask6Mask 0x40
#define     WIRE_sIoInvertBitmask6Shift 6
#define WIRE_sIoInvertBitmask7                   11      // 1 Bit, Bit 7
#define     WIRE_sIoInvertBitmask7Mask 0x80
#define     WIRE_sIoInvertBitmask7Shift 7
#define WIRE_sSensorOffset                        9      // int8_t
#define WIRE_sSensorDelayBase                    10      // 2 Bits, Bit 7-6
#define     WIRE_sSensorDelayBaseMask 0xC0
#define     WIRE_sSensorDelayBaseShift 6
#define WIRE_sSensorDelayTime                    10      // 14 Bits, Bit 13-0
#define     WIRE_sSensorDelayTimeMask 0x3FFF
#define     WIRE_sSensorDelayTimeShift 0
#define WIRE_sSensorDeltaAbs                     14      // uint16_t
#define WIRE_sSensorDeltaPercent                 16      // uint8_t
#define WIRE_sSensorSmooth                       17      // uint8_t

// Geräte-Id
#define ParamWIRE_sDeviceId                           (knx.paramData(WIRE_ParamCalcIndex(WIRE_sDeviceId)))
#define ParamWIRE_sDeviceIdStr                        (knx.paramString(WIRE_ParamCalcIndex(WIRE_sDeviceId), WIRE_sDeviceIdLength))
// Familienkode
#define ParamWIRE_sFamilyCode                         (knx.paramByte(WIRE_ParamCalcIndex(WIRE_sFamilyCode)))
// 
#define ParamWIRE_sId0                                ((knx.paramByte(WIRE_ParamCalcIndex(WIRE_sId0)) & WIRE_sId0Mask) >> WIRE_sId0Shift)
// 
#define ParamWIRE_sId1                                (knx.paramByte(WIRE_ParamCalcIndex(WIRE_sId1)) & WIRE_sId1Mask)
// 
#define ParamWIRE_sId2                                ((knx.paramByte(WIRE_ParamCalcIndex(WIRE_sId2)) & WIRE_sId2Mask) >> WIRE_sId2Shift)
// 
#define ParamWIRE_sId3                                (knx.paramByte(WIRE_ParamCalcIndex(WIRE_sId3)) & WIRE_sId3Mask)
// 
#define ParamWIRE_sId4                                ((knx.paramByte(WIRE_ParamCalcIndex(WIRE_sId4)) & WIRE_sId4Mask) >> WIRE_sId4Shift)
// 
#define ParamWIRE_sId5                                (knx.paramByte(WIRE_ParamCalcIndex(WIRE_sId5)) & WIRE_sId5Mask)
// 
#define ParamWIRE_sId6                                ((knx.paramByte(WIRE_ParamCalcIndex(WIRE_sId6)) & WIRE_sId6Mask) >> WIRE_sId6Shift)
// 
#define ParamWIRE_sId7                                (knx.paramByte(WIRE_ParamCalcIndex(WIRE_sId7)) & WIRE_sId7Mask)
// 
#define ParamWIRE_sId8                                ((knx.paramByte(WIRE_ParamCalcIndex(WIRE_sId8)) & WIRE_sId8Mask) >> WIRE_sId8Shift)
// 
#define ParamWIRE_sId9                                (knx.paramByte(WIRE_ParamCalcIndex(WIRE_sId9)) & WIRE_sId9Mask)
// 
#define ParamWIRE_sIdA                                ((knx.paramByte(WIRE_ParamCalcIndex(WIRE_sIdA)) & WIRE_sIdAMask) >> WIRE_sIdAShift)
// 
#define ParamWIRE_sIdB                                (knx.paramByte(WIRE_ParamCalcIndex(WIRE_sIdB)) & WIRE_sIdBMask)
// Modellfunktion
#define ParamWIRE_sModelFunction                      (knx.paramByte(WIRE_ParamCalcIndex(WIRE_sModelFunction)))
// Sensorgenauigkeit
#define ParamWIRE_sModelFunctionDS18B20               (knx.paramByte(WIRE_ParamCalcIndex(WIRE_sModelFunctionDS18B20)))
// Modellfunktion
#define ParamWIRE_sModelFunctionDS2408                (knx.paramByte(WIRE_ParamCalcIndex(WIRE_sModelFunctionDS2408)))
// Modellfunktion
#define ParamWIRE_sModelFunctionDS2413                (knx.paramByte(WIRE_ParamCalcIndex(WIRE_sModelFunctionDS2413)))
// Modellfunktion
#define ParamWIRE_sModelFunctionDS2438                (knx.paramByte(WIRE_ParamCalcIndex(WIRE_sModelFunctionDS2438)))
// Angeschlossen an
#define ParamWIRE_sBusMasterSelect1                   ((knx.paramByte(WIRE_ParamCalcIndex(WIRE_sBusMasterSelect1)) & WIRE_sBusMasterSelect1Mask) >> WIRE_sBusMasterSelect1Shift)
// Angeschlossen an
#define ParamWIRE_sBusMasterSelect2                   ((knx.paramByte(WIRE_ParamCalcIndex(WIRE_sBusMasterSelect2)) & WIRE_sBusMasterSelect2Mask) >> WIRE_sBusMasterSelect2Shift)
// Angeschlossen an
#define ParamWIRE_sBusMasterSelect3                   ((knx.paramByte(WIRE_ParamCalcIndex(WIRE_sBusMasterSelect3)) & WIRE_sBusMasterSelect3Mask) >> WIRE_sBusMasterSelect3Shift)
// Nach Neustart Zustand auf den Bus senden (auch für alle beteiligten Gruppen)?
#define ParamWIRE_siButtonSendStatus                  ((bool)(knx.paramByte(WIRE_ParamCalcIndex(WIRE_siButtonSendStatus)) & WIRE_siButtonSendStatusMask))
// Gruppe 1
#define ParamWIRE_sGroup1                             ((bool)(knx.paramByte(WIRE_ParamCalcIndex(WIRE_sGroup1)) & WIRE_sGroup1Mask))
// Gruppe 2
#define ParamWIRE_sGroup2                             ((bool)(knx.paramByte(WIRE_ParamCalcIndex(WIRE_sGroup2)) & WIRE_sGroup2Mask))
// Gruppe 3
#define ParamWIRE_sGroup3                             ((bool)(knx.paramByte(WIRE_ParamCalcIndex(WIRE_sGroup3)) & WIRE_sGroup3Mask))
// Gruppe 4
#define ParamWIRE_sGroup4                             ((bool)(knx.paramByte(WIRE_ParamCalcIndex(WIRE_sGroup4)) & WIRE_sGroup4Mask))
// Gruppe 5
#define ParamWIRE_sGroup5                             ((bool)(knx.paramByte(WIRE_ParamCalcIndex(WIRE_sGroup5)) & WIRE_sGroup5Mask))
// Gruppe 6
#define ParamWIRE_sGroup6                             ((bool)(knx.paramByte(WIRE_ParamCalcIndex(WIRE_sGroup6)) & WIRE_sGroup6Mask))
// Gruppe 7
#define ParamWIRE_sGroup7                             ((bool)(knx.paramByte(WIRE_ParamCalcIndex(WIRE_sGroup7)) & WIRE_sGroup7Mask))
// Gruppe 8
#define ParamWIRE_sGroup8                             ((bool)(knx.paramByte(WIRE_ParamCalcIndex(WIRE_sGroup8)) & WIRE_sGroup8Mask))
// Eingänge: Nach Neustart Zustand auf den Bus senden?
#define ParamWIRE_sIOSendStatus                       ((bool)(knx.paramByte(WIRE_ParamCalcIndex(WIRE_sIOSendStatus)) & WIRE_sIOSendStatusMask))
// Ausgänge: Nach Neustart Wert vom Bus lesen und Ausgang passend setzen?
#define ParamWIRE_sIOReadRequest                      ((bool)(knx.paramByte(WIRE_ParamCalcIndex(WIRE_sIOReadRequest)) & WIRE_sIOReadRequestMask))
// 
#define ParamWIRE_sIoBitmask0                         ((bool)(knx.paramByte(WIRE_ParamCalcIndex(WIRE_sIoBitmask0)) & WIRE_sIoBitmask0Mask))
// 
#define ParamWIRE_sIoBitmask1                         ((bool)(knx.paramByte(WIRE_ParamCalcIndex(WIRE_sIoBitmask1)) & WIRE_sIoBitmask1Mask))
// 
#define ParamWIRE_sIoBitmask2                         ((bool)(knx.paramByte(WIRE_ParamCalcIndex(WIRE_sIoBitmask2)) & WIRE_sIoBitmask2Mask))
// 
#define ParamWIRE_sIoBitmask3                         ((bool)(knx.paramByte(WIRE_ParamCalcIndex(WIRE_sIoBitmask3)) & WIRE_sIoBitmask3Mask))
// 
#define ParamWIRE_sIoBitmask4                         ((bool)(knx.paramByte(WIRE_ParamCalcIndex(WIRE_sIoBitmask4)) & WIRE_sIoBitmask4Mask))
// 
#define ParamWIRE_sIoBitmask5                         ((bool)(knx.paramByte(WIRE_ParamCalcIndex(WIRE_sIoBitmask5)) & WIRE_sIoBitmask5Mask))
// 
#define ParamWIRE_sIoBitmask6                         ((bool)(knx.paramByte(WIRE_ParamCalcIndex(WIRE_sIoBitmask6)) & WIRE_sIoBitmask6Mask))
// 
#define ParamWIRE_sIoBitmask7                         ((bool)(knx.paramByte(WIRE_ParamCalcIndex(WIRE_sIoBitmask7)) & WIRE_sIoBitmask7Mask))
// 
#define ParamWIRE_sIoInvertBitmask0                   ((bool)(knx.paramByte(WIRE_ParamCalcIndex(WIRE_sIoInvertBitmask0)) & WIRE_sIoInvertBitmask0Mask))
// 
#define ParamWIRE_sIoInvertBitmask1                   ((bool)(knx.paramByte(WIRE_ParamCalcIndex(WIRE_sIoInvertBitmask1)) & WIRE_sIoInvertBitmask1Mask))
// 
#define ParamWIRE_sIoInvertBitmask2                   ((bool)(knx.paramByte(WIRE_ParamCalcIndex(WIRE_sIoInvertBitmask2)) & WIRE_sIoInvertBitmask2Mask))
// 
#define ParamWIRE_sIoInvertBitmask3                   ((bool)(knx.paramByte(WIRE_ParamCalcIndex(WIRE_sIoInvertBitmask3)) & WIRE_sIoInvertBitmask3Mask))
// 
#define ParamWIRE_sIoInvertBitmask4                   ((bool)(knx.paramByte(WIRE_ParamCalcIndex(WIRE_sIoInvertBitmask4)) & WIRE_sIoInvertBitmask4Mask))
// 
#define ParamWIRE_sIoInvertBitmask5                   ((bool)(knx.paramByte(WIRE_ParamCalcIndex(WIRE_sIoInvertBitmask5)) & WIRE_sIoInvertBitmask5Mask))
// 
#define ParamWIRE_sIoInvertBitmask6                   ((bool)(knx.paramByte(WIRE_ParamCalcIndex(WIRE_sIoInvertBitmask6)) & WIRE_sIoInvertBitmask6Mask))
// 
#define ParamWIRE_sIoInvertBitmask7                   ((bool)(knx.paramByte(WIRE_ParamCalcIndex(WIRE_sIoInvertBitmask7)) & WIRE_sIoInvertBitmask7Mask))
// Sensorwert anpassen
#define ParamWIRE_sSensorOffset                       ((int8_t)knx.paramByte(WIRE_ParamCalcIndex(WIRE_sSensorOffset)))
// Zeitbasis
#define ParamWIRE_sSensorDelayBase                    ((knx.paramByte(WIRE_ParamCalcIndex(WIRE_sSensorDelayBase)) & WIRE_sSensorDelayBaseMask) >> WIRE_sSensorDelayBaseShift)
// Zeit
#define ParamWIRE_sSensorDelayTime                    (knx.paramWord(WIRE_ParamCalcIndex(WIRE_sSensorDelayTime)) & WIRE_sSensorDelayTimeMask)
// Zeit (in Millisekunden)
#define ParamWIRE_sSensorDelayTimeMS                  (paramDelay(knx.paramWord(WIRE_ParamCalcIndex(WIRE_sSensorDelayTime))))
// Bei absoluter Abweichung senden(0=nicht senden)
#define ParamWIRE_sSensorDeltaAbs                     (knx.paramWord(WIRE_ParamCalcIndex(WIRE_sSensorDeltaAbs)))
// Bei Abweichung vom vorherigen Wert senden(0=nicht senden)
#define ParamWIRE_sSensorDeltaPercent                 (knx.paramByte(WIRE_ParamCalcIndex(WIRE_sSensorDeltaPercent)))
// Sensorwert glätten: P =
#define ParamWIRE_sSensorSmooth                       (knx.paramByte(WIRE_ParamCalcIndex(WIRE_sSensorSmooth)))

// deprecated
#define WIRE_KoOffset 120

// Communication objects per channel (multiple occurrence)
#define WIRE_KoBlockOffset 120
#define WIRE_KoBlockSize 1

#define WIRE_KoCalcNumber(index) (index + WIRE_KoBlockOffset + _channelIndex * WIRE_KoBlockSize)
#define WIRE_KoCalcIndex(number) ((number >= WIRE_KoCalcNumber(0) && number < WIRE_KoCalcNumber(WIRE_KoBlockSize)) ? (number - WIRE_KoBlockOffset) % WIRE_KoBlockSize : -1)
#define WIRE_KoCalcChannel(number) ((number >= WIRE_KoBlockOffset && number < WIRE_KoBlockOffset + WIRE_ChannelCount * WIRE_KoBlockSize) ? (number - WIRE_KoBlockOffset) / WIRE_KoBlockSize : -1)

#define WIRE_KoKOs 0

// Dynamic
#define KoWIRE_KOs                                 (knx.getGroupObject(WIRE_KoCalcNumber(WIRE_KoKOs)))

#define LOG_VisibleChannels                     2736      // uint8_t
#define LOG_VacationKo                          2737      // 1 Bit, Bit 7
#define     LOG_VacationKoMask 0x80
#define     LOG_VacationKoShift 7
#define LOG_HolidayKo                           2737      // 1 Bit, Bit 6
#define     LOG_HolidayKoMask 0x40
#define     LOG_HolidayKoShift 6
#define LOG_VacationRead                        2737      // 1 Bit, Bit 5
#define     LOG_VacationReadMask 0x20
#define     LOG_VacationReadShift 5
#define LOG_HolidaySend                         2737      // 1 Bit, Bit 4
#define     LOG_HolidaySendMask 0x10
#define     LOG_HolidaySendShift 4
#define LOG_Neujahr                             2738      // 1 Bit, Bit 7
#define     LOG_NeujahrMask 0x80
#define     LOG_NeujahrShift 7
#define LOG_DreiKoenige                         2738      // 1 Bit, Bit 6
#define     LOG_DreiKoenigeMask 0x40
#define     LOG_DreiKoenigeShift 6
#define LOG_Weiberfastnacht                     2738      // 1 Bit, Bit 5
#define     LOG_WeiberfastnachtMask 0x20
#define     LOG_WeiberfastnachtShift 5
#define LOG_Rosenmontag                         2738      // 1 Bit, Bit 4
#define     LOG_RosenmontagMask 0x10
#define     LOG_RosenmontagShift 4
#define LOG_Fastnachtsdienstag                  2738      // 1 Bit, Bit 3
#define     LOG_FastnachtsdienstagMask 0x08
#define     LOG_FastnachtsdienstagShift 3
#define LOG_Aschermittwoch                      2738      // 1 Bit, Bit 2
#define     LOG_AschermittwochMask 0x04
#define     LOG_AschermittwochShift 2
#define LOG_Frauentag                           2738      // 1 Bit, Bit 1
#define     LOG_FrauentagMask 0x02
#define     LOG_FrauentagShift 1
#define LOG_Gruendonnerstag                     2738      // 1 Bit, Bit 0
#define     LOG_GruendonnerstagMask 0x01
#define     LOG_GruendonnerstagShift 0
#define LOG_Karfreitag                          2739      // 1 Bit, Bit 7
#define     LOG_KarfreitagMask 0x80
#define     LOG_KarfreitagShift 7
#define LOG_Ostersonntag                        2739      // 1 Bit, Bit 6
#define     LOG_OstersonntagMask 0x40
#define     LOG_OstersonntagShift 6
#define LOG_Ostermontag                         2739      // 1 Bit, Bit 5
#define     LOG_OstermontagMask 0x20
#define     LOG_OstermontagShift 5
#define LOG_TagDerArbeit                        2739      // 1 Bit, Bit 4
#define     LOG_TagDerArbeitMask 0x10
#define     LOG_TagDerArbeitShift 4
#define LOG_Himmelfahrt                         2739      // 1 Bit, Bit 3
#define     LOG_HimmelfahrtMask 0x08
#define     LOG_HimmelfahrtShift 3
#define LOG_Pfingstsonntag                      2739      // 1 Bit, Bit 2
#define     LOG_PfingstsonntagMask 0x04
#define     LOG_PfingstsonntagShift 2
#define LOG_Pfingstmontag                       2739      // 1 Bit, Bit 1
#define     LOG_PfingstmontagMask 0x02
#define     LOG_PfingstmontagShift 1
#define LOG_Fronleichnam                        2739      // 1 Bit, Bit 0
#define     LOG_FronleichnamMask 0x01
#define     LOG_FronleichnamShift 0
#define LOG_Friedensfest                        2740      // 1 Bit, Bit 7
#define     LOG_FriedensfestMask 0x80
#define     LOG_FriedensfestShift 7
#define LOG_MariaHimmelfahrt                    2740      // 1 Bit, Bit 6
#define     LOG_MariaHimmelfahrtMask 0x40
#define     LOG_MariaHimmelfahrtShift 6
#define LOG_DeutscheEinheit                     2740      // 1 Bit, Bit 5
#define     LOG_DeutscheEinheitMask 0x20
#define     LOG_DeutscheEinheitShift 5
#define LOG_Reformationstag                     2740      // 1 Bit, Bit 4
#define     LOG_ReformationstagMask 0x10
#define     LOG_ReformationstagShift 4
#define LOG_Allerheiligen                       2740      // 1 Bit, Bit 3
#define     LOG_AllerheiligenMask 0x08
#define     LOG_AllerheiligenShift 3
#define LOG_BussBettag                          2740      // 1 Bit, Bit 2
#define     LOG_BussBettagMask 0x04
#define     LOG_BussBettagShift 2
#define LOG_Advent1                             2740      // 1 Bit, Bit 1
#define     LOG_Advent1Mask 0x02
#define     LOG_Advent1Shift 1
#define LOG_Advent2                             2740      // 1 Bit, Bit 0
#define     LOG_Advent2Mask 0x01
#define     LOG_Advent2Shift 0
#define LOG_Advent3                             2741      // 1 Bit, Bit 7
#define     LOG_Advent3Mask 0x80
#define     LOG_Advent3Shift 7
#define LOG_Advent4                             2741      // 1 Bit, Bit 6
#define     LOG_Advent4Mask 0x40
#define     LOG_Advent4Shift 6
#define LOG_Heiligabend                         2741      // 1 Bit, Bit 5
#define     LOG_HeiligabendMask 0x20
#define     LOG_HeiligabendShift 5
#define LOG_Weihnachtstag1                      2741      // 1 Bit, Bit 4
#define     LOG_Weihnachtstag1Mask 0x10
#define     LOG_Weihnachtstag1Shift 4
#define LOG_Weihnachtstag2                      2741      // 1 Bit, Bit 3
#define     LOG_Weihnachtstag2Mask 0x08
#define     LOG_Weihnachtstag2Shift 3
#define LOG_Silvester                           2741      // 1 Bit, Bit 2
#define     LOG_SilvesterMask 0x04
#define     LOG_SilvesterShift 2
#define LOG_Nationalfeiertag                    2741      // 1 Bit, Bit 1
#define     LOG_NationalfeiertagMask 0x02
#define     LOG_NationalfeiertagShift 1
#define LOG_MariaEmpfaengnis                    2741      // 1 Bit, Bit 0
#define     LOG_MariaEmpfaengnisMask 0x01
#define     LOG_MariaEmpfaengnisShift 0
#define LOG_NationalfeiertagSchweiz             2742      // 1 Bit, Bit 7
#define     LOG_NationalfeiertagSchweizMask 0x80
#define     LOG_NationalfeiertagSchweizShift 7
#define LOG_Totensonntag                        2742      // 1 Bit, Bit 6
#define     LOG_TotensonntagMask 0x40
#define     LOG_TotensonntagShift 6
#define LOG_Weltkindertag                       2742      // 1 Bit, Bit 5
#define     LOG_WeltkindertagMask 0x20
#define     LOG_WeltkindertagShift 5
#define LOG_UserFormula1                        2743      // char*, 99 Byte
#define     LOG_UserFormula1Length 99
#define LOG_UserFormula1Active                  2842      // 1 Bit, Bit 7
#define     LOG_UserFormula1ActiveMask 0x80
#define     LOG_UserFormula1ActiveShift 7
#define LOG_UserFormula2                        2843      // char*, 99 Byte
#define     LOG_UserFormula2Length 99
#define LOG_UserFormula2Active                  2942      // 1 Bit, Bit 7
#define     LOG_UserFormula2ActiveMask 0x80
#define     LOG_UserFormula2ActiveShift 7
#define LOG_UserFormula3                        2943      // char*, 99 Byte
#define     LOG_UserFormula3Length 99
#define LOG_UserFormula3Active                  3042      // 1 Bit, Bit 7
#define     LOG_UserFormula3ActiveMask 0x80
#define     LOG_UserFormula3ActiveShift 7
#define LOG_UserFormula4                        3043      // char*, 99 Byte
#define     LOG_UserFormula4Length 99
#define LOG_UserFormula4Active                  3142      // 1 Bit, Bit 7
#define     LOG_UserFormula4ActiveMask 0x80
#define     LOG_UserFormula4ActiveShift 7
#define LOG_UserFormula5                        3143      // char*, 99 Byte
#define     LOG_UserFormula5Length 99
#define LOG_UserFormula5Active                  3242      // 1 Bit, Bit 7
#define     LOG_UserFormula5ActiveMask 0x80
#define     LOG_UserFormula5ActiveShift 7
#define LOG_UserFormula6                        3243      // char*, 99 Byte
#define     LOG_UserFormula6Length 99
#define LOG_UserFormula6Active                  3342      // 1 Bit, Bit 7
#define     LOG_UserFormula6ActiveMask 0x80
#define     LOG_UserFormula6ActiveShift 7
#define LOG_UserFormula7                        3343      // char*, 99 Byte
#define     LOG_UserFormula7Length 99
#define LOG_UserFormula7Active                  3442      // 1 Bit, Bit 7
#define     LOG_UserFormula7ActiveMask 0x80
#define     LOG_UserFormula7ActiveShift 7
#define LOG_UserFormula8                        3443      // char*, 99 Byte
#define     LOG_UserFormula8Length 99
#define LOG_UserFormula8Active                  3542      // 1 Bit, Bit 7
#define     LOG_UserFormula8ActiveMask 0x80
#define     LOG_UserFormula8ActiveShift 7
#define LOG_UserFormula9                        3543      // char*, 99 Byte
#define     LOG_UserFormula9Length 99
#define LOG_UserFormula9Active                  3642      // 1 Bit, Bit 7
#define     LOG_UserFormula9ActiveMask 0x80
#define     LOG_UserFormula9ActiveShift 7
#define LOG_UserFormula10                       3643      // char*, 99 Byte
#define     LOG_UserFormula10Length 99
#define LOG_UserFormula10Active                 3742      // 1 Bit, Bit 7
#define     LOG_UserFormula10ActiveMask 0x80
#define     LOG_UserFormula10ActiveShift 7
#define LOG_UserFormula11                       3743      // char*, 99 Byte
#define     LOG_UserFormula11Length 99
#define LOG_UserFormula11Active                 3842      // 1 Bit, Bit 7
#define     LOG_UserFormula11ActiveMask 0x80
#define     LOG_UserFormula11ActiveShift 7
#define LOG_UserFormula12                       3843      // char*, 99 Byte
#define     LOG_UserFormula12Length 99
#define LOG_UserFormula12Active                 3942      // 1 Bit, Bit 7
#define     LOG_UserFormula12ActiveMask 0x80
#define     LOG_UserFormula12ActiveShift 7
#define LOG_UserFormula13                       3943      // char*, 99 Byte
#define     LOG_UserFormula13Length 99
#define LOG_UserFormula13Active                 4042      // 1 Bit, Bit 7
#define     LOG_UserFormula13ActiveMask 0x80
#define     LOG_UserFormula13ActiveShift 7
#define LOG_UserFormula14                       4043      // char*, 99 Byte
#define     LOG_UserFormula14Length 99
#define LOG_UserFormula14Active                 4142      // 1 Bit, Bit 7
#define     LOG_UserFormula14ActiveMask 0x80
#define     LOG_UserFormula14ActiveShift 7
#define LOG_UserFormula15                       4143      // char*, 99 Byte
#define     LOG_UserFormula15Length 99
#define LOG_UserFormula15Active                 4242      // 1 Bit, Bit 7
#define     LOG_UserFormula15ActiveMask 0x80
#define     LOG_UserFormula15ActiveShift 7
#define LOG_UserFormula16                       4243      // char*, 99 Byte
#define     LOG_UserFormula16Length 99
#define LOG_UserFormula16Active                 4342      // 1 Bit, Bit 7
#define     LOG_UserFormula16ActiveMask 0x80
#define     LOG_UserFormula16ActiveShift 7
#define LOG_UserFormula17                       4343      // char*, 99 Byte
#define     LOG_UserFormula17Length 99
#define LOG_UserFormula17Active                 4442      // 1 Bit, Bit 7
#define     LOG_UserFormula17ActiveMask 0x80
#define     LOG_UserFormula17ActiveShift 7
#define LOG_UserFormula18                       4443      // char*, 99 Byte
#define     LOG_UserFormula18Length 99
#define LOG_UserFormula18Active                 4542      // 1 Bit, Bit 7
#define     LOG_UserFormula18ActiveMask 0x80
#define     LOG_UserFormula18ActiveShift 7
#define LOG_UserFormula19                       4543      // char*, 99 Byte
#define     LOG_UserFormula19Length 99
#define LOG_UserFormula19Active                 4642      // 1 Bit, Bit 7
#define     LOG_UserFormula19ActiveMask 0x80
#define     LOG_UserFormula19ActiveShift 7
#define LOG_UserFormula20                       4643      // char*, 99 Byte
#define     LOG_UserFormula20Length 99
#define LOG_UserFormula20Active                 4742      // 1 Bit, Bit 7
#define     LOG_UserFormula20ActiveMask 0x80
#define     LOG_UserFormula20ActiveShift 7
#define LOG_UserFormula21                       4743      // char*, 99 Byte
#define     LOG_UserFormula21Length 99
#define LOG_UserFormula21Active                 4842      // 1 Bit, Bit 7
#define     LOG_UserFormula21ActiveMask 0x80
#define     LOG_UserFormula21ActiveShift 7
#define LOG_UserFormula22                       4843      // char*, 99 Byte
#define     LOG_UserFormula22Length 99
#define LOG_UserFormula22Active                 4942      // 1 Bit, Bit 7
#define     LOG_UserFormula22ActiveMask 0x80
#define     LOG_UserFormula22ActiveShift 7
#define LOG_UserFormula23                       4943      // char*, 99 Byte
#define     LOG_UserFormula23Length 99
#define LOG_UserFormula23Active                 5042      // 1 Bit, Bit 7
#define     LOG_UserFormula23ActiveMask 0x80
#define     LOG_UserFormula23ActiveShift 7
#define LOG_UserFormula24                       5043      // char*, 99 Byte
#define     LOG_UserFormula24Length 99
#define LOG_UserFormula24Active                 5142      // 1 Bit, Bit 7
#define     LOG_UserFormula24ActiveMask 0x80
#define     LOG_UserFormula24ActiveShift 7
#define LOG_UserFormula25                       5143      // char*, 99 Byte
#define     LOG_UserFormula25Length 99
#define LOG_UserFormula25Active                 5242      // 1 Bit, Bit 7
#define     LOG_UserFormula25ActiveMask 0x80
#define     LOG_UserFormula25ActiveShift 7
#define LOG_UserFormula26                       5243      // char*, 99 Byte
#define     LOG_UserFormula26Length 99
#define LOG_UserFormula26Active                 5342      // 1 Bit, Bit 7
#define     LOG_UserFormula26ActiveMask 0x80
#define     LOG_UserFormula26ActiveShift 7
#define LOG_UserFormula27                       5343      // char*, 99 Byte
#define     LOG_UserFormula27Length 99
#define LOG_UserFormula27Active                 5442      // 1 Bit, Bit 7
#define     LOG_UserFormula27ActiveMask 0x80
#define     LOG_UserFormula27ActiveShift 7
#define LOG_UserFormula28                       5443      // char*, 99 Byte
#define     LOG_UserFormula28Length 99
#define LOG_UserFormula28Active                 5542      // 1 Bit, Bit 7
#define     LOG_UserFormula28ActiveMask 0x80
#define     LOG_UserFormula28ActiveShift 7
#define LOG_UserFormula29                       5543      // char*, 99 Byte
#define     LOG_UserFormula29Length 99
#define LOG_UserFormula29Active                 5642      // 1 Bit, Bit 7
#define     LOG_UserFormula29ActiveMask 0x80
#define     LOG_UserFormula29ActiveShift 7
#define LOG_UserFormula30                       5643      // char*, 99 Byte
#define     LOG_UserFormula30Length 99
#define LOG_UserFormula30Active                 5742      // 1 Bit, Bit 7
#define     LOG_UserFormula30ActiveMask 0x80
#define     LOG_UserFormula30ActiveShift 7

// Verfügbare Kanäle
#define ParamLOG_VisibleChannels                     (knx.paramByte(LOG_VisibleChannels))
// Urlaubsbehandlung aktivieren?
#define ParamLOG_VacationKo                          ((bool)(knx.paramByte(LOG_VacationKo) & LOG_VacationKoMask))
// Feiertage auf dem Bus verfügbar machen?
#define ParamLOG_HolidayKo                           ((bool)(knx.paramByte(LOG_HolidayKo) & LOG_HolidayKoMask))
// Nach Neustart Urlaubsinfo lesen?
#define ParamLOG_VacationRead                        ((bool)(knx.paramByte(LOG_VacationRead) & LOG_VacationReadMask))
// Nach Neuberechnung Feiertagsinfo senden?
#define ParamLOG_HolidaySend                         ((bool)(knx.paramByte(LOG_HolidaySend) & LOG_HolidaySendMask))
// 1. Neujahr
#define ParamLOG_Neujahr                             ((bool)(knx.paramByte(LOG_Neujahr) & LOG_NeujahrMask))
// 2. Heilige Drei Könige
#define ParamLOG_DreiKoenige                         ((bool)(knx.paramByte(LOG_DreiKoenige) & LOG_DreiKoenigeMask))
// 3. Weiberfastnacht
#define ParamLOG_Weiberfastnacht                     ((bool)(knx.paramByte(LOG_Weiberfastnacht) & LOG_WeiberfastnachtMask))
// 4. Rosenmontag
#define ParamLOG_Rosenmontag                         ((bool)(knx.paramByte(LOG_Rosenmontag) & LOG_RosenmontagMask))
// 5. Fastnachtsdienstag
#define ParamLOG_Fastnachtsdienstag                  ((bool)(knx.paramByte(LOG_Fastnachtsdienstag) & LOG_FastnachtsdienstagMask))
// 6. Aschermittwoch
#define ParamLOG_Aschermittwoch                      ((bool)(knx.paramByte(LOG_Aschermittwoch) & LOG_AschermittwochMask))
// 7. Frauentag
#define ParamLOG_Frauentag                           ((bool)(knx.paramByte(LOG_Frauentag) & LOG_FrauentagMask))
// 8. Gründonnerstag
#define ParamLOG_Gruendonnerstag                     ((bool)(knx.paramByte(LOG_Gruendonnerstag) & LOG_GruendonnerstagMask))
// 9. Karfreitag
#define ParamLOG_Karfreitag                          ((bool)(knx.paramByte(LOG_Karfreitag) & LOG_KarfreitagMask))
// 10. Ostersonntag
#define ParamLOG_Ostersonntag                        ((bool)(knx.paramByte(LOG_Ostersonntag) & LOG_OstersonntagMask))
// 11. Ostermontag
#define ParamLOG_Ostermontag                         ((bool)(knx.paramByte(LOG_Ostermontag) & LOG_OstermontagMask))
// 12. Tag der Arbeit
#define ParamLOG_TagDerArbeit                        ((bool)(knx.paramByte(LOG_TagDerArbeit) & LOG_TagDerArbeitMask))
// 13. Christi Himmelfahrt
#define ParamLOG_Himmelfahrt                         ((bool)(knx.paramByte(LOG_Himmelfahrt) & LOG_HimmelfahrtMask))
// 14. Pfingstsonntag
#define ParamLOG_Pfingstsonntag                      ((bool)(knx.paramByte(LOG_Pfingstsonntag) & LOG_PfingstsonntagMask))
// 15. Pfingstmontag
#define ParamLOG_Pfingstmontag                       ((bool)(knx.paramByte(LOG_Pfingstmontag) & LOG_PfingstmontagMask))
// 16. Fronleichnam
#define ParamLOG_Fronleichnam                        ((bool)(knx.paramByte(LOG_Fronleichnam) & LOG_FronleichnamMask))
// 17. Hohes Friedensfest
#define ParamLOG_Friedensfest                        ((bool)(knx.paramByte(LOG_Friedensfest) & LOG_FriedensfestMask))
// 18. Mariä Himmelfahrt
#define ParamLOG_MariaHimmelfahrt                    ((bool)(knx.paramByte(LOG_MariaHimmelfahrt) & LOG_MariaHimmelfahrtMask))
// 19. Tag der Deutschen Einheit
#define ParamLOG_DeutscheEinheit                     ((bool)(knx.paramByte(LOG_DeutscheEinheit) & LOG_DeutscheEinheitMask))
// 20. Reformationstag
#define ParamLOG_Reformationstag                     ((bool)(knx.paramByte(LOG_Reformationstag) & LOG_ReformationstagMask))
// 21. Allerheiligen
#define ParamLOG_Allerheiligen                       ((bool)(knx.paramByte(LOG_Allerheiligen) & LOG_AllerheiligenMask))
// 22. Buß- und Bettag
#define ParamLOG_BussBettag                          ((bool)(knx.paramByte(LOG_BussBettag) & LOG_BussBettagMask))
// 23. Erster Advent
#define ParamLOG_Advent1                             ((bool)(knx.paramByte(LOG_Advent1) & LOG_Advent1Mask))
// 24. Zweiter Advent
#define ParamLOG_Advent2                             ((bool)(knx.paramByte(LOG_Advent2) & LOG_Advent2Mask))
// 25. Dritter Advent
#define ParamLOG_Advent3                             ((bool)(knx.paramByte(LOG_Advent3) & LOG_Advent3Mask))
// 26. Vierter Advent
#define ParamLOG_Advent4                             ((bool)(knx.paramByte(LOG_Advent4) & LOG_Advent4Mask))
// 27. Heiligabend
#define ParamLOG_Heiligabend                         ((bool)(knx.paramByte(LOG_Heiligabend) & LOG_HeiligabendMask))
// 28. Erster Weihnachtstag
#define ParamLOG_Weihnachtstag1                      ((bool)(knx.paramByte(LOG_Weihnachtstag1) & LOG_Weihnachtstag1Mask))
// 29. Zweiter Weihnachtstag
#define ParamLOG_Weihnachtstag2                      ((bool)(knx.paramByte(LOG_Weihnachtstag2) & LOG_Weihnachtstag2Mask))
// 30. Silvester
#define ParamLOG_Silvester                           ((bool)(knx.paramByte(LOG_Silvester) & LOG_SilvesterMask))
// 31. Nationalfeiertag (AT)
#define ParamLOG_Nationalfeiertag                    ((bool)(knx.paramByte(LOG_Nationalfeiertag) & LOG_NationalfeiertagMask))
// 32. Maria Empfängnis (AT)
#define ParamLOG_MariaEmpfaengnis                    ((bool)(knx.paramByte(LOG_MariaEmpfaengnis) & LOG_MariaEmpfaengnisMask))
// 33. Nationalfeiertag (CH)
#define ParamLOG_NationalfeiertagSchweiz             ((bool)(knx.paramByte(LOG_NationalfeiertagSchweiz) & LOG_NationalfeiertagSchweizMask))
// 34. Totensonntag
#define ParamLOG_Totensonntag                        ((bool)(knx.paramByte(LOG_Totensonntag) & LOG_TotensonntagMask))
// 35. Weltkindertag
#define ParamLOG_Weltkindertag                       ((bool)(knx.paramByte(LOG_Weltkindertag) & LOG_WeltkindertagMask))
// Formeldefinition
#define ParamLOG_UserFormula1                        (knx.paramData(LOG_UserFormula1))
#define ParamLOG_UserFormula1Str                     (knx.paramString(LOG_UserFormula1, LOG_UserFormula1Length))
// Benutzerformel 1 aktiv
#define ParamLOG_UserFormula1Active                  ((bool)(knx.paramByte(LOG_UserFormula1Active) & LOG_UserFormula1ActiveMask))
// Formeldefinition
#define ParamLOG_UserFormula2                        (knx.paramData(LOG_UserFormula2))
#define ParamLOG_UserFormula2Str                     (knx.paramString(LOG_UserFormula2, LOG_UserFormula2Length))
// Benutzerformel 2 aktiv
#define ParamLOG_UserFormula2Active                  ((bool)(knx.paramByte(LOG_UserFormula2Active) & LOG_UserFormula2ActiveMask))
// Formeldefinition
#define ParamLOG_UserFormula3                        (knx.paramData(LOG_UserFormula3))
#define ParamLOG_UserFormula3Str                     (knx.paramString(LOG_UserFormula3, LOG_UserFormula3Length))
// Benutzerformel 3 aktiv
#define ParamLOG_UserFormula3Active                  ((bool)(knx.paramByte(LOG_UserFormula3Active) & LOG_UserFormula3ActiveMask))
// Formeldefinition
#define ParamLOG_UserFormula4                        (knx.paramData(LOG_UserFormula4))
#define ParamLOG_UserFormula4Str                     (knx.paramString(LOG_UserFormula4, LOG_UserFormula4Length))
// Benutzerformel 4 aktiv
#define ParamLOG_UserFormula4Active                  ((bool)(knx.paramByte(LOG_UserFormula4Active) & LOG_UserFormula4ActiveMask))
// Formeldefinition
#define ParamLOG_UserFormula5                        (knx.paramData(LOG_UserFormula5))
#define ParamLOG_UserFormula5Str                     (knx.paramString(LOG_UserFormula5, LOG_UserFormula5Length))
// Benutzerformel 5 aktiv
#define ParamLOG_UserFormula5Active                  ((bool)(knx.paramByte(LOG_UserFormula5Active) & LOG_UserFormula5ActiveMask))
// Formeldefinition
#define ParamLOG_UserFormula6                        (knx.paramData(LOG_UserFormula6))
#define ParamLOG_UserFormula6Str                     (knx.paramString(LOG_UserFormula6, LOG_UserFormula6Length))
// Benutzerformel 6 aktiv
#define ParamLOG_UserFormula6Active                  ((bool)(knx.paramByte(LOG_UserFormula6Active) & LOG_UserFormula6ActiveMask))
// Formeldefinition
#define ParamLOG_UserFormula7                        (knx.paramData(LOG_UserFormula7))
#define ParamLOG_UserFormula7Str                     (knx.paramString(LOG_UserFormula7, LOG_UserFormula7Length))
// Benutzerformel 7 aktiv
#define ParamLOG_UserFormula7Active                  ((bool)(knx.paramByte(LOG_UserFormula7Active) & LOG_UserFormula7ActiveMask))
// Formeldefinition
#define ParamLOG_UserFormula8                        (knx.paramData(LOG_UserFormula8))
#define ParamLOG_UserFormula8Str                     (knx.paramString(LOG_UserFormula8, LOG_UserFormula8Length))
// Benutzerformel 8 aktiv
#define ParamLOG_UserFormula8Active                  ((bool)(knx.paramByte(LOG_UserFormula8Active) & LOG_UserFormula8ActiveMask))
// Formeldefinition
#define ParamLOG_UserFormula9                        (knx.paramData(LOG_UserFormula9))
#define ParamLOG_UserFormula9Str                     (knx.paramString(LOG_UserFormula9, LOG_UserFormula9Length))
// Benutzerformel 9 aktiv
#define ParamLOG_UserFormula9Active                  ((bool)(knx.paramByte(LOG_UserFormula9Active) & LOG_UserFormula9ActiveMask))
// Formeldefinition
#define ParamLOG_UserFormula10                       (knx.paramData(LOG_UserFormula10))
#define ParamLOG_UserFormula10Str                    (knx.paramString(LOG_UserFormula10, LOG_UserFormula10Length))
// Benutzerformel 10 aktiv
#define ParamLOG_UserFormula10Active                 ((bool)(knx.paramByte(LOG_UserFormula10Active) & LOG_UserFormula10ActiveMask))
// Formeldefinition
#define ParamLOG_UserFormula11                       (knx.paramData(LOG_UserFormula11))
#define ParamLOG_UserFormula11Str                    (knx.paramString(LOG_UserFormula11, LOG_UserFormula11Length))
// Benutzerformel 11 aktiv
#define ParamLOG_UserFormula11Active                 ((bool)(knx.paramByte(LOG_UserFormula11Active) & LOG_UserFormula11ActiveMask))
// Formeldefinition
#define ParamLOG_UserFormula12                       (knx.paramData(LOG_UserFormula12))
#define ParamLOG_UserFormula12Str                    (knx.paramString(LOG_UserFormula12, LOG_UserFormula12Length))
// Benutzerformel 12 aktiv
#define ParamLOG_UserFormula12Active                 ((bool)(knx.paramByte(LOG_UserFormula12Active) & LOG_UserFormula12ActiveMask))
// Formeldefinition
#define ParamLOG_UserFormula13                       (knx.paramData(LOG_UserFormula13))
#define ParamLOG_UserFormula13Str                    (knx.paramString(LOG_UserFormula13, LOG_UserFormula13Length))
// Benutzerformel 13 aktiv
#define ParamLOG_UserFormula13Active                 ((bool)(knx.paramByte(LOG_UserFormula13Active) & LOG_UserFormula13ActiveMask))
// Formeldefinition
#define ParamLOG_UserFormula14                       (knx.paramData(LOG_UserFormula14))
#define ParamLOG_UserFormula14Str                    (knx.paramString(LOG_UserFormula14, LOG_UserFormula14Length))
// Benutzerformel 14 aktiv
#define ParamLOG_UserFormula14Active                 ((bool)(knx.paramByte(LOG_UserFormula14Active) & LOG_UserFormula14ActiveMask))
// Formeldefinition
#define ParamLOG_UserFormula15                       (knx.paramData(LOG_UserFormula15))
#define ParamLOG_UserFormula15Str                    (knx.paramString(LOG_UserFormula15, LOG_UserFormula15Length))
// Benutzerformel 15 aktiv
#define ParamLOG_UserFormula15Active                 ((bool)(knx.paramByte(LOG_UserFormula15Active) & LOG_UserFormula15ActiveMask))
// Formeldefinition
#define ParamLOG_UserFormula16                       (knx.paramData(LOG_UserFormula16))
#define ParamLOG_UserFormula16Str                    (knx.paramString(LOG_UserFormula16, LOG_UserFormula16Length))
// Benutzerformel 16 aktiv
#define ParamLOG_UserFormula16Active                 ((bool)(knx.paramByte(LOG_UserFormula16Active) & LOG_UserFormula16ActiveMask))
// Formeldefinition
#define ParamLOG_UserFormula17                       (knx.paramData(LOG_UserFormula17))
#define ParamLOG_UserFormula17Str                    (knx.paramString(LOG_UserFormula17, LOG_UserFormula17Length))
// Benutzerformel 17 aktiv
#define ParamLOG_UserFormula17Active                 ((bool)(knx.paramByte(LOG_UserFormula17Active) & LOG_UserFormula17ActiveMask))
// Formeldefinition
#define ParamLOG_UserFormula18                       (knx.paramData(LOG_UserFormula18))
#define ParamLOG_UserFormula18Str                    (knx.paramString(LOG_UserFormula18, LOG_UserFormula18Length))
// Benutzerformel 18 aktiv
#define ParamLOG_UserFormula18Active                 ((bool)(knx.paramByte(LOG_UserFormula18Active) & LOG_UserFormula18ActiveMask))
// Formeldefinition
#define ParamLOG_UserFormula19                       (knx.paramData(LOG_UserFormula19))
#define ParamLOG_UserFormula19Str                    (knx.paramString(LOG_UserFormula19, LOG_UserFormula19Length))
// Benutzerformel 19 aktiv
#define ParamLOG_UserFormula19Active                 ((bool)(knx.paramByte(LOG_UserFormula19Active) & LOG_UserFormula19ActiveMask))
// Formeldefinition
#define ParamLOG_UserFormula20                       (knx.paramData(LOG_UserFormula20))
#define ParamLOG_UserFormula20Str                    (knx.paramString(LOG_UserFormula20, LOG_UserFormula20Length))
// Benutzerformel 20 aktiv
#define ParamLOG_UserFormula20Active                 ((bool)(knx.paramByte(LOG_UserFormula20Active) & LOG_UserFormula20ActiveMask))
// Formeldefinition
#define ParamLOG_UserFormula21                       (knx.paramData(LOG_UserFormula21))
#define ParamLOG_UserFormula21Str                    (knx.paramString(LOG_UserFormula21, LOG_UserFormula21Length))
// Benutzerformel 21 aktiv
#define ParamLOG_UserFormula21Active                 ((bool)(knx.paramByte(LOG_UserFormula21Active) & LOG_UserFormula21ActiveMask))
// Formeldefinition
#define ParamLOG_UserFormula22                       (knx.paramData(LOG_UserFormula22))
#define ParamLOG_UserFormula22Str                    (knx.paramString(LOG_UserFormula22, LOG_UserFormula22Length))
// Benutzerformel 22 aktiv
#define ParamLOG_UserFormula22Active                 ((bool)(knx.paramByte(LOG_UserFormula22Active) & LOG_UserFormula22ActiveMask))
// Formeldefinition
#define ParamLOG_UserFormula23                       (knx.paramData(LOG_UserFormula23))
#define ParamLOG_UserFormula23Str                    (knx.paramString(LOG_UserFormula23, LOG_UserFormula23Length))
// Benutzerformel 23 aktiv
#define ParamLOG_UserFormula23Active                 ((bool)(knx.paramByte(LOG_UserFormula23Active) & LOG_UserFormula23ActiveMask))
// Formeldefinition
#define ParamLOG_UserFormula24                       (knx.paramData(LOG_UserFormula24))
#define ParamLOG_UserFormula24Str                    (knx.paramString(LOG_UserFormula24, LOG_UserFormula24Length))
// Benutzerformel 24 aktiv
#define ParamLOG_UserFormula24Active                 ((bool)(knx.paramByte(LOG_UserFormula24Active) & LOG_UserFormula24ActiveMask))
// Formeldefinition
#define ParamLOG_UserFormula25                       (knx.paramData(LOG_UserFormula25))
#define ParamLOG_UserFormula25Str                    (knx.paramString(LOG_UserFormula25, LOG_UserFormula25Length))
// Benutzerformel 25 aktiv
#define ParamLOG_UserFormula25Active                 ((bool)(knx.paramByte(LOG_UserFormula25Active) & LOG_UserFormula25ActiveMask))
// Formeldefinition
#define ParamLOG_UserFormula26                       (knx.paramData(LOG_UserFormula26))
#define ParamLOG_UserFormula26Str                    (knx.paramString(LOG_UserFormula26, LOG_UserFormula26Length))
// Benutzerformel 26 aktiv
#define ParamLOG_UserFormula26Active                 ((bool)(knx.paramByte(LOG_UserFormula26Active) & LOG_UserFormula26ActiveMask))
// Formeldefinition
#define ParamLOG_UserFormula27                       (knx.paramData(LOG_UserFormula27))
#define ParamLOG_UserFormula27Str                    (knx.paramString(LOG_UserFormula27, LOG_UserFormula27Length))
// Benutzerformel 27 aktiv
#define ParamLOG_UserFormula27Active                 ((bool)(knx.paramByte(LOG_UserFormula27Active) & LOG_UserFormula27ActiveMask))
// Formeldefinition
#define ParamLOG_UserFormula28                       (knx.paramData(LOG_UserFormula28))
#define ParamLOG_UserFormula28Str                    (knx.paramString(LOG_UserFormula28, LOG_UserFormula28Length))
// Benutzerformel 28 aktiv
#define ParamLOG_UserFormula28Active                 ((bool)(knx.paramByte(LOG_UserFormula28Active) & LOG_UserFormula28ActiveMask))
// Formeldefinition
#define ParamLOG_UserFormula29                       (knx.paramData(LOG_UserFormula29))
#define ParamLOG_UserFormula29Str                    (knx.paramString(LOG_UserFormula29, LOG_UserFormula29Length))
// Benutzerformel 29 aktiv
#define ParamLOG_UserFormula29Active                 ((bool)(knx.paramByte(LOG_UserFormula29Active) & LOG_UserFormula29ActiveMask))
// Formeldefinition
#define ParamLOG_UserFormula30                       (knx.paramData(LOG_UserFormula30))
#define ParamLOG_UserFormula30Str                    (knx.paramString(LOG_UserFormula30, LOG_UserFormula30Length))
// Benutzerformel 30 aktiv
#define ParamLOG_UserFormula30Active                 ((bool)(knx.paramByte(LOG_UserFormula30Active) & LOG_UserFormula30ActiveMask))

#define LOG_KoVacation 15
#define LOG_KoHoliday1 16
#define LOG_KoHoliday2 17

// Urlaub
#define KoLOG_Vacation                            (knx.getGroupObject(LOG_KoVacation))
// Welcher Feiertag ist heute?
#define KoLOG_Holiday1                            (knx.getGroupObject(LOG_KoHoliday1))
// Welcher Feiertag ist morgen?
#define KoLOG_Holiday2                            (knx.getGroupObject(LOG_KoHoliday2))

#define LOG_ChannelCount 3

// Parameter per channel
#define LOG_ParamBlockOffset 5743
#define LOG_ParamBlockSize 89
#define LOG_ParamCalcIndex(index) (index + LOG_ParamBlockOffset + _channelIndex * LOG_ParamBlockSize)

#define LOG_fChannelDelayBase                    0      // 2 Bits, Bit 7-6
#define     LOG_fChannelDelayBaseMask 0xC0
#define     LOG_fChannelDelayBaseShift 6
#define LOG_fChannelDelayTime                    0      // 14 Bits, Bit 13-0
#define     LOG_fChannelDelayTimeMask 0x3FFF
#define     LOG_fChannelDelayTimeShift 0
#define LOG_fLogic                               2      // 8 Bits, Bit 7-0
#define LOG_fCalculate                           3      // 2 Bits, Bit 1-0
#define     LOG_fCalculateMask 0x03
#define     LOG_fCalculateShift 0
#define LOG_fDisable                             3      // 1 Bit, Bit 2
#define     LOG_fDisableMask 0x04
#define     LOG_fDisableShift 2
#define LOG_fTGate                               3      // 1 Bit, Bit 4
#define     LOG_fTGateMask 0x10
#define     LOG_fTGateShift 4
#define LOG_fOInternalOn                         3      // 1 Bit, Bit 5
#define     LOG_fOInternalOnMask 0x20
#define     LOG_fOInternalOnShift 5
#define LOG_fOInternalOff                        3      // 1 Bit, Bit 6
#define     LOG_fOInternalOffMask 0x40
#define     LOG_fOInternalOffShift 6
#define LOG_fTrigger                             4      // 8 Bits, Bit 7-0
#define LOG_fTriggerE1                           4      // 1 Bit, Bit 0
#define     LOG_fTriggerE1Mask 0x01
#define     LOG_fTriggerE1Shift 0
#define LOG_fTriggerE2                           4      // 1 Bit, Bit 1
#define     LOG_fTriggerE2Mask 0x02
#define     LOG_fTriggerE2Shift 1
#define LOG_fTriggerI1                           4      // 1 Bit, Bit 2
#define     LOG_fTriggerI1Mask 0x04
#define     LOG_fTriggerI1Shift 2
#define LOG_fTriggerI2                           4      // 1 Bit, Bit 3
#define     LOG_fTriggerI2Mask 0x08
#define     LOG_fTriggerI2Shift 3
#define LOG_fTriggerTime                         4      // 8 Bits, Bit 7-0
#define LOG_fTriggerGateClose                    5      // 2 Bits, Bit 7-6
#define     LOG_fTriggerGateCloseMask 0xC0
#define     LOG_fTriggerGateCloseShift 6
#define LOG_fTriggerGateOpen                     5      // 2 Bits, Bit 5-4
#define     LOG_fTriggerGateOpenMask 0x30
#define     LOG_fTriggerGateOpenShift 4
#define LOG_fE1ConvertInt                        6      // 4 Bits, Bit 7-4
#define     LOG_fE1ConvertIntMask 0xF0
#define     LOG_fE1ConvertIntShift 4
#define LOG_fE1Convert                           6      // 4 Bits, Bit 7-4
#define     LOG_fE1ConvertMask 0xF0
#define     LOG_fE1ConvertShift 4
#define LOG_fE1ConvertFloat                      6      // 4 Bits, Bit 7-4
#define     LOG_fE1ConvertFloatMask 0xF0
#define     LOG_fE1ConvertFloatShift 4
#define LOG_fE1ConvertSpecial                    6      // 4 Bits, Bit 7-4
#define     LOG_fE1ConvertSpecialMask 0xF0
#define     LOG_fE1ConvertSpecialShift 4
#define LOG_fE1ConvertBool                       6      // 4 Bits, Bit 7-4
#define     LOG_fE1ConvertBoolMask 0xF0
#define     LOG_fE1ConvertBoolShift 4
#define LOG_fE1                                  6      // 2 Bits, Bit 1-0
#define     LOG_fE1Mask 0x03
#define     LOG_fE1Shift 0
#define LOG_fE1Dpt                               7      // 8 Bits, Bit 7-0
#define LOG_fE1RepeatBase                        8      // 2 Bits, Bit 7-6
#define     LOG_fE1RepeatBaseMask 0xC0
#define     LOG_fE1RepeatBaseShift 6
#define LOG_fE1RepeatTime                        8      // 14 Bits, Bit 13-0
#define     LOG_fE1RepeatTimeMask 0x3FFF
#define     LOG_fE1RepeatTimeShift 0
#define LOG_fE1OtherKO                          10      // uint16_t
#define LOG_fE1OtherKORel                       10      // int16_t
#define LOG_fE1Default                          12      // 2 Bits, Bit 1-0
#define     LOG_fE1DefaultMask 0x03
#define     LOG_fE1DefaultShift 0
#define LOG_fE1DefaultExt                       12      // 2 Bits, Bit 1-0
#define     LOG_fE1DefaultExtMask 0x03
#define     LOG_fE1DefaultExtShift 0
#define LOG_fE1DefaultEEPROM                    12      // 1 Bit, Bit 2
#define     LOG_fE1DefaultEEPROMMask 0x04
#define     LOG_fE1DefaultEEPROMShift 2
#define LOG_fE1DefaultRepeat                    12      // 1 Bit, Bit 3
#define     LOG_fE1DefaultRepeatMask 0x08
#define     LOG_fE1DefaultRepeatShift 3
#define LOG_fE1UseOtherKO                       12      // 2 Bits, Bit 5-4
#define     LOG_fE1UseOtherKOMask 0x30
#define     LOG_fE1UseOtherKOShift 4
#define LOG_fE1LowDelta                         13      // int32_t
#define LOG_fE1HighDelta                        17      // int32_t
#define LOG_fE1LowDeltaFloat                    13      // float (4 Byte)
#define LOG_fE1HighDeltaFloat                   17      // float (4 Byte)
#define LOG_fE1LowDeltaDouble                   13      // float (4 Byte)
#define LOG_fE1HighDeltaDouble                  17      // float (4 Byte)
#define LOG_fE1Low0Valid                        20      // 1 Bit, Bit 7
#define     LOG_fE1Low0ValidMask 0x80
#define     LOG_fE1Low0ValidShift 7
#define LOG_fE1Low1Valid                        20      // 1 Bit, Bit 6
#define     LOG_fE1Low1ValidMask 0x40
#define     LOG_fE1Low1ValidShift 6
#define LOG_fE1Low2Valid                        20      // 1 Bit, Bit 5
#define     LOG_fE1Low2ValidMask 0x20
#define     LOG_fE1Low2ValidShift 5
#define LOG_fE1Low3Valid                        20      // 1 Bit, Bit 4
#define     LOG_fE1Low3ValidMask 0x10
#define     LOG_fE1Low3ValidShift 4
#define LOG_fE1Low4Valid                        20      // 1 Bit, Bit 3
#define     LOG_fE1Low4ValidMask 0x08
#define     LOG_fE1Low4ValidShift 3
#define LOG_fE1Low5Valid                        20      // 1 Bit, Bit 2
#define     LOG_fE1Low5ValidMask 0x04
#define     LOG_fE1Low5ValidShift 2
#define LOG_fE1Low6Valid                        20      // 1 Bit, Bit 1
#define     LOG_fE1Low6ValidMask 0x02
#define     LOG_fE1Low6ValidShift 1
#define LOG_fE1Low0Dpt2                         13      // 8 Bits, Bit 7-0
#define LOG_fE1Low1Dpt2                         14      // 8 Bits, Bit 7-0
#define LOG_fE1Low2Dpt2                         15      // 8 Bits, Bit 7-0
#define LOG_fE1Low3Dpt2                         16      // 8 Bits, Bit 7-0
#define LOG_fE1LowDpt2Fix                       13      // 8 Bits, Bit 7-0
#define LOG_fE1Low0Dpt3Dir                      13      // 5 Bits, Bit 7-3
#define     LOG_fE1Low0Dpt3DirMask 0xF8
#define     LOG_fE1Low0Dpt3DirShift 3
#define LOG_fE1Low0Dpt3Dim                      13      // 3 Bits, Bit 2-0
#define     LOG_fE1Low0Dpt3DimMask 0x07
#define     LOG_fE1Low0Dpt3DimShift 0
#define LOG_fE1Low1Dpt3Dir                      14      // 5 Bits, Bit 7-3
#define     LOG_fE1Low1Dpt3DirMask 0xF8
#define     LOG_fE1Low1Dpt3DirShift 3
#define LOG_fE1Low1Dpt3Dim                      14      // 3 Bits, Bit 2-0
#define     LOG_fE1Low1Dpt3DimMask 0x07
#define     LOG_fE1Low1Dpt3DimShift 0
#define LOG_fE1Low2Dpt3Dir                      15      // 5 Bits, Bit 7-3
#define     LOG_fE1Low2Dpt3DirMask 0xF8
#define     LOG_fE1Low2Dpt3DirShift 3
#define LOG_fE1Low2Dpt3Dim                      15      // 3 Bits, Bit 2-0
#define     LOG_fE1Low2Dpt3DimMask 0x07
#define     LOG_fE1Low2Dpt3DimShift 0
#define LOG_fE1Low3Dpt3Dir                      16      // 5 Bits, Bit 7-3
#define     LOG_fE1Low3Dpt3DirMask 0xF8
#define     LOG_fE1Low3Dpt3DirShift 3
#define LOG_fE1Low3Dpt3Dim                      16      // 3 Bits, Bit 2-0
#define     LOG_fE1Low3Dpt3DimMask 0x07
#define     LOG_fE1Low3Dpt3DimShift 0
#define LOG_fE1LowDpt3FixDir                    13      // 5 Bits, Bit 7-3
#define     LOG_fE1LowDpt3FixDirMask 0xF8
#define     LOG_fE1LowDpt3FixDirShift 3
#define LOG_fE1LowDpt3FixDim                    13      // 3 Bits, Bit 2-0
#define     LOG_fE1LowDpt3FixDimMask 0x07
#define     LOG_fE1LowDpt3FixDimShift 0
#define LOG_fE1LowDpt5                          13      // uint8_t
#define LOG_fE1HighDpt5                         17      // uint8_t
#define LOG_fE1Low0Dpt5In                       13      // uint8_t
#define LOG_fE1Low1Dpt5In                       14      // uint8_t
#define LOG_fE1Low2Dpt5In                       15      // uint8_t
#define LOG_fE1Low3Dpt5In                       16      // uint8_t
#define LOG_fE1Low4Dpt5In                       17      // uint8_t
#define LOG_fE1Low5Dpt5In                       18      // uint8_t
#define LOG_fE1Low6Dpt5In                       19      // uint8_t
#define LOG_fE1LowDpt5Fix                       13      // uint8_t
#define LOG_fE1LowDpt5001                       13      // uint8_t
#define LOG_fE1HighDpt5001                      17      // uint8_t
#define LOG_fE1Low0Dpt5xIn                      13      // uint8_t
#define LOG_fE1Low1Dpt5xIn                      14      // uint8_t
#define LOG_fE1Low2Dpt5xIn                      15      // uint8_t
#define LOG_fE1Low3Dpt5xIn                      16      // uint8_t
#define LOG_fE1Low4Dpt5xIn                      17      // uint8_t
#define LOG_fE1Low5Dpt5xIn                      18      // uint8_t
#define LOG_fE1Low6Dpt5xIn                      19      // uint8_t
#define LOG_fE1LowDpt5xFix                      13      // uint8_t
#define LOG_fE1LowDpt6                          13      // int8_t
#define LOG_fE1HighDpt6                         17      // int8_t
#define LOG_fE1Low0Dpt6In                       13      // int8_t
#define LOG_fE1Low1Dpt6In                       14      // int8_t
#define LOG_fE1Low2Dpt6In                       15      // int8_t
#define LOG_fE1Low3Dpt6In                       16      // int8_t
#define LOG_fE1Low4Dpt6In                       17      // int8_t
#define LOG_fE1Low5Dpt6In                       18      // int8_t
#define LOG_fE1Low6Dpt6In                       19      // int8_t
#define LOG_fE1LowDpt6Fix                       13      // int8_t
#define LOG_fE1LowDpt7                          13      // uint16_t
#define LOG_fE1HighDpt7                         17      // uint16_t
#define LOG_fE1Low0Dpt7In                       13      // uint16_t
#define LOG_fE1Low1Dpt7In                       15      // uint16_t
#define LOG_fE1Low2Dpt7In                       17      // uint16_t
#define LOG_fE1LowDpt7Fix                       13      // uint16_t
#define LOG_fE1LowDpt8                          13      // int16_t
#define LOG_fE1HighDpt8                         17      // int16_t
#define LOG_fE1Low0Dpt8In                       13      // int16_t
#define LOG_fE1Low1Dpt8In                       15      // int16_t
#define LOG_fE1Low2Dpt8In                       17      // int16_t
#define LOG_fE1LowDpt8Fix                       13      // int16_t
#define LOG_fE1LowDpt9                          13      // float (4 Byte)
#define LOG_fE1HighDpt9                         17      // float (4 Byte)
#define LOG_fE1LowDpt9Fix                       13      // float (4 Byte)
#define LOG_fE1LowDpt12                         13      // uint32_t
#define LOG_fE1HighDpt12                        17      // uint32_t
#define LOG_fE1LowDpt12Fix                      13      // uint32_t
#define LOG_fE1LowDpt13                         13      // int32_t
#define LOG_fE1HighDpt13                        17      // int32_t
#define LOG_fE1LowDpt13Fix                      13      // int32_t
#define LOG_fE1LowDpt14                         13      // float (4 Byte)
#define LOG_fE1HighDpt14                        17      // float (4 Byte)
#define LOG_fE1LowDpt14Fix                      13      // float (4 Byte)
#define LOG_fE1Low0Dpt17                        13      // 8 Bits, Bit 7-0
#define LOG_fE1Low1Dpt17                        14      // 8 Bits, Bit 7-0
#define LOG_fE1Low2Dpt17                        15      // 8 Bits, Bit 7-0
#define LOG_fE1Low3Dpt17                        16      // 8 Bits, Bit 7-0
#define LOG_fE1Low4Dpt17                        17      // 8 Bits, Bit 7-0
#define LOG_fE1Low5Dpt17                        18      // 8 Bits, Bit 7-0
#define LOG_fE1Low6Dpt17                        19      // 8 Bits, Bit 7-0
#define LOG_fE1Low7Dpt17                        20      // 8 Bits, Bit 7-0
#define LOG_fE1LowDpt17Fix                      13      // 8 Bits, Bit 7-0
#define LOG_fE1LowDptRGB                        13      // int32_t
#define LOG_fE1HighDptRGB                       17      // int32_t
#define LOG_fE1LowDptRGBFix                     13      // int32_t
#define LOG_fE2ConvertInt                       21      // 4 Bits, Bit 7-4
#define     LOG_fE2ConvertIntMask 0xF0
#define     LOG_fE2ConvertIntShift 4
#define LOG_fE2Convert                          21      // 4 Bits, Bit 7-4
#define     LOG_fE2ConvertMask 0xF0
#define     LOG_fE2ConvertShift 4
#define LOG_fE2ConvertFloat                     21      // 4 Bits, Bit 7-4
#define     LOG_fE2ConvertFloatMask 0xF0
#define     LOG_fE2ConvertFloatShift 4
#define LOG_fE2ConvertSpecial                   21      // 4 Bits, Bit 7-4
#define     LOG_fE2ConvertSpecialMask 0xF0
#define     LOG_fE2ConvertSpecialShift 4
#define LOG_fE2ConvertBool                      21      // 4 Bits, Bit 7-4
#define     LOG_fE2ConvertBoolMask 0xF0
#define     LOG_fE2ConvertBoolShift 4
#define LOG_fE2                                 21      // 2 Bits, Bit 1-0
#define     LOG_fE2Mask 0x03
#define     LOG_fE2Shift 0
#define LOG_fE2Dpt                              22      // 8 Bits, Bit 7-0
#define LOG_fE2RepeatBase                       23      // 2 Bits, Bit 7-6
#define     LOG_fE2RepeatBaseMask 0xC0
#define     LOG_fE2RepeatBaseShift 6
#define LOG_fE2RepeatTime                       23      // 14 Bits, Bit 13-0
#define     LOG_fE2RepeatTimeMask 0x3FFF
#define     LOG_fE2RepeatTimeShift 0
#define LOG_fE2OtherKO                          25      // uint16_t
#define LOG_fE2OtherKORel                       25      // int16_t
#define LOG_fE2Default                          27      // 2 Bits, Bit 1-0
#define     LOG_fE2DefaultMask 0x03
#define     LOG_fE2DefaultShift 0
#define LOG_fE2DefaultExt                       27      // 2 Bits, Bit 1-0
#define     LOG_fE2DefaultExtMask 0x03
#define     LOG_fE2DefaultExtShift 0
#define LOG_fE2DefaultEEPROM                    27      // 1 Bit, Bit 2
#define     LOG_fE2DefaultEEPROMMask 0x04
#define     LOG_fE2DefaultEEPROMShift 2
#define LOG_fE2DefaultRepeat                    27      // 1 Bit, Bit 3
#define     LOG_fE2DefaultRepeatMask 0x08
#define     LOG_fE2DefaultRepeatShift 3
#define LOG_fE2UseOtherKO                       27      // 2 Bits, Bit 5-4
#define     LOG_fE2UseOtherKOMask 0x30
#define     LOG_fE2UseOtherKOShift 4
#define LOG_fE2LowDelta                         28      // int32_t
#define LOG_fE2HighDelta                        32      // int32_t
#define LOG_fE2LowDeltaFloat                    28      // float (4 Byte)
#define LOG_fE2HighDeltaFloat                   32      // float (4 Byte)
#define LOG_fE2LowDeltaDouble                   28      // float (4 Byte)
#define LOG_fE2HighDeltaDouble                  32      // float (4 Byte)
#define LOG_fE2Low0Valid                        35      // 1 Bit, Bit 7
#define     LOG_fE2Low0ValidMask 0x80
#define     LOG_fE2Low0ValidShift 7
#define LOG_fE2Low1Valid                        35      // 1 Bit, Bit 6
#define     LOG_fE2Low1ValidMask 0x40
#define     LOG_fE2Low1ValidShift 6
#define LOG_fE2Low2Valid                        35      // 1 Bit, Bit 5
#define     LOG_fE2Low2ValidMask 0x20
#define     LOG_fE2Low2ValidShift 5
#define LOG_fE2Low3Valid                        35      // 1 Bit, Bit 4
#define     LOG_fE2Low3ValidMask 0x10
#define     LOG_fE2Low3ValidShift 4
#define LOG_fE2Low4Valid                        35      // 1 Bit, Bit 3
#define     LOG_fE2Low4ValidMask 0x08
#define     LOG_fE2Low4ValidShift 3
#define LOG_fE2Low5Valid                        35      // 1 Bit, Bit 2
#define     LOG_fE2Low5ValidMask 0x04
#define     LOG_fE2Low5ValidShift 2
#define LOG_fE2Low6Valid                        35      // 1 Bit, Bit 1
#define     LOG_fE2Low6ValidMask 0x02
#define     LOG_fE2Low6ValidShift 1
#define LOG_fE2Low0Dpt2                         28      // 8 Bits, Bit 7-0
#define LOG_fE2Low1Dpt2                         29      // 8 Bits, Bit 7-0
#define LOG_fE2Low2Dpt2                         30      // 8 Bits, Bit 7-0
#define LOG_fE2Low3Dpt2                         31      // 8 Bits, Bit 7-0
#define LOG_fE2LowDpt2Fix                       28      // 8 Bits, Bit 7-0
#define LOG_fE2Low0Dpt3Dir                      28      // 5 Bits, Bit 7-3
#define     LOG_fE2Low0Dpt3DirMask 0xF8
#define     LOG_fE2Low0Dpt3DirShift 3
#define LOG_fE2Low0Dpt3Dim                      28      // 3 Bits, Bit 2-0
#define     LOG_fE2Low0Dpt3DimMask 0x07
#define     LOG_fE2Low0Dpt3DimShift 0
#define LOG_fE2Low1Dpt3Dir                      29      // 5 Bits, Bit 7-3
#define     LOG_fE2Low1Dpt3DirMask 0xF8
#define     LOG_fE2Low1Dpt3DirShift 3
#define LOG_fE2Low1Dpt3Dim                      29      // 3 Bits, Bit 2-0
#define     LOG_fE2Low1Dpt3DimMask 0x07
#define     LOG_fE2Low1Dpt3DimShift 0
#define LOG_fE2Low2Dpt3Dir                      30      // 5 Bits, Bit 7-3
#define     LOG_fE2Low2Dpt3DirMask 0xF8
#define     LOG_fE2Low2Dpt3DirShift 3
#define LOG_fE2Low2Dpt3Dim                      30      // 3 Bits, Bit 2-0
#define     LOG_fE2Low2Dpt3DimMask 0x07
#define     LOG_fE2Low2Dpt3DimShift 0
#define LOG_fE2Low3Dpt3Dir                      31      // 5 Bits, Bit 7-3
#define     LOG_fE2Low3Dpt3DirMask 0xF8
#define     LOG_fE2Low3Dpt3DirShift 3
#define LOG_fE2Low3Dpt3Dim                      31      // 3 Bits, Bit 2-0
#define     LOG_fE2Low3Dpt3DimMask 0x07
#define     LOG_fE2Low3Dpt3DimShift 0
#define LOG_fE2LowDpt3FixDir                    28      // 5 Bits, Bit 7-3
#define     LOG_fE2LowDpt3FixDirMask 0xF8
#define     LOG_fE2LowDpt3FixDirShift 3
#define LOG_fE2LowDpt3FixDim                    28      // 3 Bits, Bit 2-0
#define     LOG_fE2LowDpt3FixDimMask 0x07
#define     LOG_fE2LowDpt3FixDimShift 0
#define LOG_fE2LowDpt5                          28      // uint8_t
#define LOG_fE2HighDpt5                         32      // uint8_t
#define LOG_fE2Low0Dpt5In                       28      // uint8_t
#define LOG_fE2Low1Dpt5In                       29      // uint8_t
#define LOG_fE2Low2Dpt5In                       30      // uint8_t
#define LOG_fE2Low3Dpt5In                       31      // uint8_t
#define LOG_fE2Low4Dpt5In                       32      // uint8_t
#define LOG_fE2Low5Dpt5In                       33      // uint8_t
#define LOG_fE2Low6Dpt5In                       34      // uint8_t
#define LOG_fE2LowDpt5Fix                       28      // uint8_t
#define LOG_fE2LowDpt5001                       28      // uint8_t
#define LOG_fE2HighDpt5001                      32      // uint8_t
#define LOG_fE2Low0Dpt5xIn                      28      // uint8_t
#define LOG_fE2Low1Dpt5xIn                      29      // uint8_t
#define LOG_fE2Low2Dpt5xIn                      30      // uint8_t
#define LOG_fE2Low3Dpt5xIn                      31      // uint8_t
#define LOG_fE2Low4Dpt5xIn                      32      // uint8_t
#define LOG_fE2Low5Dpt5xIn                      33      // uint8_t
#define LOG_fE2Low6Dpt5xIn                      34      // uint8_t
#define LOG_fE2LowDpt5xFix                      28      // uint8_t
#define LOG_fE2LowDpt6                          28      // int8_t
#define LOG_fE2HighDpt6                         32      // int8_t
#define LOG_fE2Low0Dpt6In                       28      // int8_t
#define LOG_fE2Low1Dpt6In                       29      // int8_t
#define LOG_fE2Low2Dpt6In                       30      // int8_t
#define LOG_fE2Low3Dpt6In                       31      // int8_t
#define LOG_fE2Low4Dpt6In                       32      // int8_t
#define LOG_fE2Low5Dpt6In                       33      // int8_t
#define LOG_fE2Low6Dpt6In                       34      // int8_t
#define LOG_fE2LowDpt6Fix                       28      // int8_t
#define LOG_fE2LowDpt7                          28      // uint16_t
#define LOG_fE2HighDpt7                         32      // uint16_t
#define LOG_fE2Low0Dpt7In                       28      // uint16_t
#define LOG_fE2Low1Dpt7In                       30      // uint16_t
#define LOG_fE2Low2Dpt7In                       32      // uint16_t
#define LOG_fE2LowDpt7Fix                       28      // uint16_t
#define LOG_fE2LowDpt8                          28      // int16_t
#define LOG_fE2HighDpt8                         32      // int16_t
#define LOG_fE2Low0Dpt8In                       28      // int16_t
#define LOG_fE2Low1Dpt8In                       30      // int16_t
#define LOG_fE2Low2Dpt8In                       32      // int16_t
#define LOG_fE2LowDpt8Fix                       28      // int16_t
#define LOG_fE2LowDpt9                          28      // float (4 Byte)
#define LOG_fE2HighDpt9                         32      // float (4 Byte)
#define LOG_fE2LowDpt9Fix                       28      // float (4 Byte)
#define LOG_fE2LowDpt12                         28      // uint32_t
#define LOG_fE2HighDpt12                        32      // uint32_t
#define LOG_fE2LowDpt12Fix                      28      // uint32_t
#define LOG_fE2LowDpt13                         28      // int32_t
#define LOG_fE2HighDpt13                        32      // int32_t
#define LOG_fE2LowDpt13Fix                      28      // int32_t
#define LOG_fE2LowDpt14                         28      // float (4 Byte)
#define LOG_fE2HighDpt14                        32      // float (4 Byte)
#define LOG_fE2LowDpt14Fix                      28      // float (4 Byte)
#define LOG_fE2Low0Dpt17                        28      // 8 Bits, Bit 7-0
#define LOG_fE2Low1Dpt17                        29      // 8 Bits, Bit 7-0
#define LOG_fE2Low2Dpt17                        30      // 8 Bits, Bit 7-0
#define LOG_fE2Low3Dpt17                        31      // 8 Bits, Bit 7-0
#define LOG_fE2Low4Dpt17                        32      // 8 Bits, Bit 7-0
#define LOG_fE2Low5Dpt17                        33      // 8 Bits, Bit 7-0
#define LOG_fE2Low6Dpt17                        34      // 8 Bits, Bit 7-0
#define LOG_fE2Low7Dpt17                        35      // 8 Bits, Bit 7-0
#define LOG_fE2LowDpt17Fix                      28      // 8 Bits, Bit 7-0
#define LOG_fE2LowDptRGB                        28      // int32_t
#define LOG_fE2HighDptRGB                       32      // int32_t
#define LOG_fE2LowDptRGBFix                     28      // int32_t
#define LOG_fTd1DuskDawn                         6      // 4 Bits, Bit 7-4
#define     LOG_fTd1DuskDawnMask 0xF0
#define     LOG_fTd1DuskDawnShift 4
#define LOG_fTd2DuskDawn                         6      // 4 Bits, Bit 3-0
#define     LOG_fTd2DuskDawnMask 0x0F
#define     LOG_fTd2DuskDawnShift 0
#define LOG_fTd3DuskDawn                         7      // 4 Bits, Bit 7-4
#define     LOG_fTd3DuskDawnMask 0xF0
#define     LOG_fTd3DuskDawnShift 4
#define LOG_fTd4DuskDawn                         7      // 4 Bits, Bit 3-0
#define     LOG_fTd4DuskDawnMask 0x0F
#define     LOG_fTd4DuskDawnShift 0
#define LOG_fTd5DuskDawn                         8      // 4 Bits, Bit 7-4
#define     LOG_fTd5DuskDawnMask 0xF0
#define     LOG_fTd5DuskDawnShift 4
#define LOG_fTd6DuskDawn                         8      // 4 Bits, Bit 3-0
#define     LOG_fTd6DuskDawnMask 0x0F
#define     LOG_fTd6DuskDawnShift 0
#define LOG_fTd7DuskDawn                         9      // 4 Bits, Bit 7-4
#define     LOG_fTd7DuskDawnMask 0xF0
#define     LOG_fTd7DuskDawnShift 4
#define LOG_fTd8DuskDawn                         9      // 4 Bits, Bit 3-0
#define     LOG_fTd8DuskDawnMask 0x0F
#define     LOG_fTd8DuskDawnShift 0
#define LOG_fTYearDay                           10      // 2 Bits, Bit 7-6
#define     LOG_fTYearDayMask 0xC0
#define     LOG_fTYearDayShift 6
#define LOG_fTHoliday                           10      // 2 Bits, Bit 5-4
#define     LOG_fTHolidayMask 0x30
#define     LOG_fTHolidayShift 4
#define LOG_fTRestoreState                      10      // 2 Bits, Bit 3-2
#define     LOG_fTRestoreStateMask 0x0C
#define     LOG_fTRestoreStateShift 2
#define LOG_fTVacation                          10      // 2 Bits, Bit 1-0
#define     LOG_fTVacationMask 0x03
#define     LOG_fTVacationShift 0
#define LOG_fTd1ValueNum                        11      // uint8_t
#define LOG_fTd2ValueNum                        12      // uint8_t
#define LOG_fTd3ValueNum                        13      // uint8_t
#define LOG_fTd4ValueNum                        14      // uint8_t
#define LOG_fTd5ValueNum                        15      // uint8_t
#define LOG_fTd6ValueNum                        16      // uint8_t
#define LOG_fTd7ValueNum                        17      // uint8_t
#define LOG_fTd8ValueNum                        18      // uint8_t
#define LOG_fTd1Value                           20      // 1 Bit, Bit 7
#define     LOG_fTd1ValueMask 0x80
#define     LOG_fTd1ValueShift 7
#define LOG_fTd1Degree                          20      // 6 Bits, Bit 6-1
#define     LOG_fTd1DegreeMask 0x7E
#define     LOG_fTd1DegreeShift 1
#define LOG_fTd1HourAbs                         20      // 5 Bits, Bit 5-1
#define     LOG_fTd1HourAbsMask 0x3E
#define     LOG_fTd1HourAbsShift 1
#define LOG_fTd1HourRel                         20      // 5 Bits, Bit 5-1
#define     LOG_fTd1HourRelMask 0x3E
#define     LOG_fTd1HourRelShift 1
#define LOG_fTd1HourRelShort                    20      // 5 Bits, Bit 5-1
#define     LOG_fTd1HourRelShortMask 0x3E
#define     LOG_fTd1HourRelShortShift 1
#define LOG_fTd1MinuteAbs                       20      // 6 Bits, Bit 0--5
#define LOG_fTd1MinuteRel                       20      // 6 Bits, Bit 0--5
#define LOG_fTd1Weekday                         21      // 3 Bits, Bit 2-0
#define     LOG_fTd1WeekdayMask 0x07
#define     LOG_fTd1WeekdayShift 0
#define LOG_fTd2Value                           22      // 1 Bit, Bit 7
#define     LOG_fTd2ValueMask 0x80
#define     LOG_fTd2ValueShift 7
#define LOG_fTd2Degree                          22      // 6 Bits, Bit 6-1
#define     LOG_fTd2DegreeMask 0x7E
#define     LOG_fTd2DegreeShift 1
#define LOG_fTd2HourAbs                         22      // 5 Bits, Bit 5-1
#define     LOG_fTd2HourAbsMask 0x3E
#define     LOG_fTd2HourAbsShift 1
#define LOG_fTd2HourRel                         22      // 5 Bits, Bit 5-1
#define     LOG_fTd2HourRelMask 0x3E
#define     LOG_fTd2HourRelShift 1
#define LOG_fTd2HourRelShort                    22      // 5 Bits, Bit 5-1
#define     LOG_fTd2HourRelShortMask 0x3E
#define     LOG_fTd2HourRelShortShift 1
#define LOG_fTd2MinuteAbs                       22      // 6 Bits, Bit 0--5
#define LOG_fTd2MinuteRel                       22      // 6 Bits, Bit 0--5
#define LOG_fTd2Weekday                         23      // 3 Bits, Bit 2-0
#define     LOG_fTd2WeekdayMask 0x07
#define     LOG_fTd2WeekdayShift 0
#define LOG_fTd3Value                           24      // 1 Bit, Bit 7
#define     LOG_fTd3ValueMask 0x80
#define     LOG_fTd3ValueShift 7
#define LOG_fTd3Degree                          24      // 6 Bits, Bit 6-1
#define     LOG_fTd3DegreeMask 0x7E
#define     LOG_fTd3DegreeShift 1
#define LOG_fTd3HourAbs                         24      // 5 Bits, Bit 5-1
#define     LOG_fTd3HourAbsMask 0x3E
#define     LOG_fTd3HourAbsShift 1
#define LOG_fTd3HourRel                         24      // 5 Bits, Bit 5-1
#define     LOG_fTd3HourRelMask 0x3E
#define     LOG_fTd3HourRelShift 1
#define LOG_fTd3HourRelShort                    24      // 5 Bits, Bit 5-1
#define     LOG_fTd3HourRelShortMask 0x3E
#define     LOG_fTd3HourRelShortShift 1
#define LOG_fTd3MinuteAbs                       24      // 6 Bits, Bit 0--5
#define LOG_fTd3MinuteRel                       24      // 6 Bits, Bit 0--5
#define LOG_fTd3Weekday                         25      // 3 Bits, Bit 2-0
#define     LOG_fTd3WeekdayMask 0x07
#define     LOG_fTd3WeekdayShift 0
#define LOG_fTd4Value                           26      // 1 Bit, Bit 7
#define     LOG_fTd4ValueMask 0x80
#define     LOG_fTd4ValueShift 7
#define LOG_fTd4Degree                          26      // 6 Bits, Bit 6-1
#define     LOG_fTd4DegreeMask 0x7E
#define     LOG_fTd4DegreeShift 1
#define LOG_fTd4HourAbs                         26      // 5 Bits, Bit 5-1
#define     LOG_fTd4HourAbsMask 0x3E
#define     LOG_fTd4HourAbsShift 1
#define LOG_fTd4HourRel                         26      // 5 Bits, Bit 5-1
#define     LOG_fTd4HourRelMask 0x3E
#define     LOG_fTd4HourRelShift 1
#define LOG_fTd4HourRelShort                    26      // 5 Bits, Bit 5-1
#define     LOG_fTd4HourRelShortMask 0x3E
#define     LOG_fTd4HourRelShortShift 1
#define LOG_fTd4MinuteAbs                       26      // 6 Bits, Bit 0--5
#define LOG_fTd4MinuteRel                       26      // 6 Bits, Bit 0--5
#define LOG_fTd4Weekday                         27      // 3 Bits, Bit 2-0
#define     LOG_fTd4WeekdayMask 0x07
#define     LOG_fTd4WeekdayShift 0
#define LOG_fTd5Value                           28      // 1 Bit, Bit 7
#define     LOG_fTd5ValueMask 0x80
#define     LOG_fTd5ValueShift 7
#define LOG_fTd5Degree                          28      // 6 Bits, Bit 6-1
#define     LOG_fTd5DegreeMask 0x7E
#define     LOG_fTd5DegreeShift 1
#define LOG_fTd5HourAbs                         28      // 5 Bits, Bit 5-1
#define     LOG_fTd5HourAbsMask 0x3E
#define     LOG_fTd5HourAbsShift 1
#define LOG_fTd5HourRel                         28      // 5 Bits, Bit 5-1
#define     LOG_fTd5HourRelMask 0x3E
#define     LOG_fTd5HourRelShift 1
#define LOG_fTd5HourRelShort                    28      // 5 Bits, Bit 5-1
#define     LOG_fTd5HourRelShortMask 0x3E
#define     LOG_fTd5HourRelShortShift 1
#define LOG_fTd5MinuteAbs                       28      // 6 Bits, Bit 0--5
#define LOG_fTd5MinuteRel                       28      // 6 Bits, Bit 0--5
#define LOG_fTd5Weekday                         29      // 3 Bits, Bit 2-0
#define     LOG_fTd5WeekdayMask 0x07
#define     LOG_fTd5WeekdayShift 0
#define LOG_fTd6Value                           30      // 1 Bit, Bit 7
#define     LOG_fTd6ValueMask 0x80
#define     LOG_fTd6ValueShift 7
#define LOG_fTd6Degree                          30      // 6 Bits, Bit 6-1
#define     LOG_fTd6DegreeMask 0x7E
#define     LOG_fTd6DegreeShift 1
#define LOG_fTd6HourAbs                         30      // 5 Bits, Bit 5-1
#define     LOG_fTd6HourAbsMask 0x3E
#define     LOG_fTd6HourAbsShift 1
#define LOG_fTd6HourRel                         30      // 5 Bits, Bit 5-1
#define     LOG_fTd6HourRelMask 0x3E
#define     LOG_fTd6HourRelShift 1
#define LOG_fTd6HourRelShort                    30      // 5 Bits, Bit 5-1
#define     LOG_fTd6HourRelShortMask 0x3E
#define     LOG_fTd6HourRelShortShift 1
#define LOG_fTd6MinuteAbs                       30      // 6 Bits, Bit 0--5
#define LOG_fTd6MinuteRel                       30      // 6 Bits, Bit 0--5
#define LOG_fTd6Weekday                         31      // 3 Bits, Bit 2-0
#define     LOG_fTd6WeekdayMask 0x07
#define     LOG_fTd6WeekdayShift 0
#define LOG_fTd7Value                           32      // 1 Bit, Bit 7
#define     LOG_fTd7ValueMask 0x80
#define     LOG_fTd7ValueShift 7
#define LOG_fTd7Degree                          32      // 6 Bits, Bit 6-1
#define     LOG_fTd7DegreeMask 0x7E
#define     LOG_fTd7DegreeShift 1
#define LOG_fTd7HourAbs                         32      // 5 Bits, Bit 5-1
#define     LOG_fTd7HourAbsMask 0x3E
#define     LOG_fTd7HourAbsShift 1
#define LOG_fTd7HourRel                         32      // 5 Bits, Bit 5-1
#define     LOG_fTd7HourRelMask 0x3E
#define     LOG_fTd7HourRelShift 1
#define LOG_fTd7HourRelShort                    32      // 5 Bits, Bit 5-1
#define     LOG_fTd7HourRelShortMask 0x3E
#define     LOG_fTd7HourRelShortShift 1
#define LOG_fTd7MinuteAbs                       32      // 6 Bits, Bit 0--5
#define LOG_fTd7MinuteRel                       32      // 6 Bits, Bit 0--5
#define LOG_fTd7Weekday                         33      // 3 Bits, Bit 2-0
#define     LOG_fTd7WeekdayMask 0x07
#define     LOG_fTd7WeekdayShift 0
#define LOG_fTd8Value                           34      // 1 Bit, Bit 7
#define     LOG_fTd8ValueMask 0x80
#define     LOG_fTd8ValueShift 7
#define LOG_fTd8Degree                          34      // 6 Bits, Bit 6-1
#define     LOG_fTd8DegreeMask 0x7E
#define     LOG_fTd8DegreeShift 1
#define LOG_fTd8HourAbs                         34      // 5 Bits, Bit 5-1
#define     LOG_fTd8HourAbsMask 0x3E
#define     LOG_fTd8HourAbsShift 1
#define LOG_fTd8HourRel                         34      // 5 Bits, Bit 5-1
#define     LOG_fTd8HourRelMask 0x3E
#define     LOG_fTd8HourRelShift 1
#define LOG_fTd8HourRelShort                    34      // 5 Bits, Bit 5-1
#define     LOG_fTd8HourRelShortMask 0x3E
#define     LOG_fTd8HourRelShortShift 1
#define LOG_fTd8MinuteAbs                       34      // 6 Bits, Bit 0--5
#define LOG_fTd8MinuteRel                       34      // 6 Bits, Bit 0--5
#define LOG_fTd8Weekday                         35      // 3 Bits, Bit 2-0
#define     LOG_fTd8WeekdayMask 0x07
#define     LOG_fTd8WeekdayShift 0
#define LOG_fTy1Weekday1                        28      // 1 Bit, Bit 7
#define     LOG_fTy1Weekday1Mask 0x80
#define     LOG_fTy1Weekday1Shift 7
#define LOG_fTy1Weekday2                        28      // 1 Bit, Bit 6
#define     LOG_fTy1Weekday2Mask 0x40
#define     LOG_fTy1Weekday2Shift 6
#define LOG_fTy1Weekday3                        28      // 1 Bit, Bit 5
#define     LOG_fTy1Weekday3Mask 0x20
#define     LOG_fTy1Weekday3Shift 5
#define LOG_fTy1Weekday4                        28      // 1 Bit, Bit 4
#define     LOG_fTy1Weekday4Mask 0x10
#define     LOG_fTy1Weekday4Shift 4
#define LOG_fTy1Weekday5                        28      // 1 Bit, Bit 3
#define     LOG_fTy1Weekday5Mask 0x08
#define     LOG_fTy1Weekday5Shift 3
#define LOG_fTy1Weekday6                        28      // 1 Bit, Bit 2
#define     LOG_fTy1Weekday6Mask 0x04
#define     LOG_fTy1Weekday6Shift 2
#define LOG_fTy1Weekday7                        28      // 1 Bit, Bit 1
#define     LOG_fTy1Weekday7Mask 0x02
#define     LOG_fTy1Weekday7Shift 1
#define LOG_fTy1Day                             28      // 7 Bits, Bit 7-1
#define     LOG_fTy1DayMask 0xFE
#define     LOG_fTy1DayShift 1
#define LOG_fTy1IsWeekday                       28      // 1 Bit, Bit 0
#define     LOG_fTy1IsWeekdayMask 0x01
#define     LOG_fTy1IsWeekdayShift 0
#define LOG_fTy1Month                           29      // 4 Bits, Bit 7-4
#define     LOG_fTy1MonthMask 0xF0
#define     LOG_fTy1MonthShift 4
#define LOG_fTy2Weekday1                        30      // 1 Bit, Bit 7
#define     LOG_fTy2Weekday1Mask 0x80
#define     LOG_fTy2Weekday1Shift 7
#define LOG_fTy2Weekday2                        30      // 1 Bit, Bit 6
#define     LOG_fTy2Weekday2Mask 0x40
#define     LOG_fTy2Weekday2Shift 6
#define LOG_fTy2Weekday3                        30      // 1 Bit, Bit 5
#define     LOG_fTy2Weekday3Mask 0x20
#define     LOG_fTy2Weekday3Shift 5
#define LOG_fTy2Weekday4                        30      // 1 Bit, Bit 4
#define     LOG_fTy2Weekday4Mask 0x10
#define     LOG_fTy2Weekday4Shift 4
#define LOG_fTy2Weekday5                        30      // 1 Bit, Bit 3
#define     LOG_fTy2Weekday5Mask 0x08
#define     LOG_fTy2Weekday5Shift 3
#define LOG_fTy2Weekday6                        30      // 1 Bit, Bit 2
#define     LOG_fTy2Weekday6Mask 0x04
#define     LOG_fTy2Weekday6Shift 2
#define LOG_fTy2Weekday7                        30      // 1 Bit, Bit 1
#define     LOG_fTy2Weekday7Mask 0x02
#define     LOG_fTy2Weekday7Shift 1
#define LOG_fTy2Day                             30      // 7 Bits, Bit 7-1
#define     LOG_fTy2DayMask 0xFE
#define     LOG_fTy2DayShift 1
#define LOG_fTy2IsWeekday                       30      // 1 Bit, Bit 0
#define     LOG_fTy2IsWeekdayMask 0x01
#define     LOG_fTy2IsWeekdayShift 0
#define LOG_fTy2Month                           31      // 4 Bits, Bit 7-4
#define     LOG_fTy2MonthMask 0xF0
#define     LOG_fTy2MonthShift 4
#define LOG_fTy3Weekday1                        32      // 1 Bit, Bit 7
#define     LOG_fTy3Weekday1Mask 0x80
#define     LOG_fTy3Weekday1Shift 7
#define LOG_fTy3Weekday2                        32      // 1 Bit, Bit 6
#define     LOG_fTy3Weekday2Mask 0x40
#define     LOG_fTy3Weekday2Shift 6
#define LOG_fTy3Weekday3                        32      // 1 Bit, Bit 5
#define     LOG_fTy3Weekday3Mask 0x20
#define     LOG_fTy3Weekday3Shift 5
#define LOG_fTy3Weekday4                        32      // 1 Bit, Bit 4
#define     LOG_fTy3Weekday4Mask 0x10
#define     LOG_fTy3Weekday4Shift 4
#define LOG_fTy3Weekday5                        32      // 1 Bit, Bit 3
#define     LOG_fTy3Weekday5Mask 0x08
#define     LOG_fTy3Weekday5Shift 3
#define LOG_fTy3Weekday6                        32      // 1 Bit, Bit 2
#define     LOG_fTy3Weekday6Mask 0x04
#define     LOG_fTy3Weekday6Shift 2
#define LOG_fTy3Weekday7                        32      // 1 Bit, Bit 1
#define     LOG_fTy3Weekday7Mask 0x02
#define     LOG_fTy3Weekday7Shift 1
#define LOG_fTy3Day                             32      // 7 Bits, Bit 7-1
#define     LOG_fTy3DayMask 0xFE
#define     LOG_fTy3DayShift 1
#define LOG_fTy3IsWeekday                       32      // 1 Bit, Bit 0
#define     LOG_fTy3IsWeekdayMask 0x01
#define     LOG_fTy3IsWeekdayShift 0
#define LOG_fTy3Month                           33      // 4 Bits, Bit 7-4
#define     LOG_fTy3MonthMask 0xF0
#define     LOG_fTy3MonthShift 4
#define LOG_fTy4Weekday1                        34      // 1 Bit, Bit 7
#define     LOG_fTy4Weekday1Mask 0x80
#define     LOG_fTy4Weekday1Shift 7
#define LOG_fTy4Weekday2                        34      // 1 Bit, Bit 6
#define     LOG_fTy4Weekday2Mask 0x40
#define     LOG_fTy4Weekday2Shift 6
#define LOG_fTy4Weekday3                        34      // 1 Bit, Bit 5
#define     LOG_fTy4Weekday3Mask 0x20
#define     LOG_fTy4Weekday3Shift 5
#define LOG_fTy4Weekday4                        34      // 1 Bit, Bit 4
#define     LOG_fTy4Weekday4Mask 0x10
#define     LOG_fTy4Weekday4Shift 4
#define LOG_fTy4Weekday5                        34      // 1 Bit, Bit 3
#define     LOG_fTy4Weekday5Mask 0x08
#define     LOG_fTy4Weekday5Shift 3
#define LOG_fTy4Weekday6                        34      // 1 Bit, Bit 2
#define     LOG_fTy4Weekday6Mask 0x04
#define     LOG_fTy4Weekday6Shift 2
#define LOG_fTy4Weekday7                        34      // 1 Bit, Bit 1
#define     LOG_fTy4Weekday7Mask 0x02
#define     LOG_fTy4Weekday7Shift 1
#define LOG_fTy4Day                             34      // 7 Bits, Bit 7-1
#define     LOG_fTy4DayMask 0xFE
#define     LOG_fTy4DayShift 1
#define LOG_fTy4IsWeekday                       34      // 1 Bit, Bit 0
#define     LOG_fTy4IsWeekdayMask 0x01
#define     LOG_fTy4IsWeekdayShift 0
#define LOG_fTy4Month                           35      // 4 Bits, Bit 7-4
#define     LOG_fTy4MonthMask 0xF0
#define     LOG_fTy4MonthShift 4
#define LOG_fI1                                 36      // 2 Bits, Bit 7-6
#define     LOG_fI1Mask 0xC0
#define     LOG_fI1Shift 6
#define LOG_fI1Kind                             36      // 2 Bits, Bit 5-4
#define     LOG_fI1KindMask 0x30
#define     LOG_fI1KindShift 4
#define LOG_fI1AsTrigger                        36      // 1 Bit, Bit 3
#define     LOG_fI1AsTriggerMask 0x08
#define     LOG_fI1AsTriggerShift 3
#define LOG_fI1InternalInputType                36      // 1 Bit, Bit 2
#define     LOG_fI1InternalInputTypeMask 0x04
#define     LOG_fI1InternalInputTypeShift 2
#define LOG_fI1Function                         37      // uint8_t
#define LOG_fI1FunctionRel                      37      // int8_t
#define LOG_fI1StatusLed                        37      // 16 Bits, Bit 15-0
#define LOG_fI2                                 39      // 2 Bits, Bit 7-6
#define     LOG_fI2Mask 0xC0
#define     LOG_fI2Shift 6
#define LOG_fI2Kind                             39      // 2 Bits, Bit 5-4
#define     LOG_fI2KindMask 0x30
#define     LOG_fI2KindShift 4
#define LOG_fI2AsTrigger                        39      // 1 Bit, Bit 3
#define     LOG_fI2AsTriggerMask 0x08
#define     LOG_fI2AsTriggerShift 3
#define LOG_fI2InternalInputType                39      // 1 Bit, Bit 2
#define     LOG_fI2InternalInputTypeMask 0x04
#define     LOG_fI2InternalInputTypeShift 2
#define LOG_fI2Function                         40      // uint8_t
#define LOG_fI2FunctionRel                      40      // int8_t
#define LOG_fI2StatusLed                        40      // 16 Bits, Bit 15-0
#define LOG_fOStairtimeBase                     42      // 2 Bits, Bit 7-6
#define     LOG_fOStairtimeBaseMask 0xC0
#define     LOG_fOStairtimeBaseShift 6
#define LOG_fOStairtimeTime                     42      // 14 Bits, Bit 13-0
#define     LOG_fOStairtimeTimeMask 0x3FFF
#define     LOG_fOStairtimeTimeShift 0
#define LOG_fOBlinkBase                         44      // 2 Bits, Bit 7-6
#define     LOG_fOBlinkBaseMask 0xC0
#define     LOG_fOBlinkBaseShift 6
#define LOG_fOBlinkTime                         44      // 14 Bits, Bit 13-0
#define     LOG_fOBlinkTimeMask 0x3FFF
#define     LOG_fOBlinkTimeShift 0
#define LOG_fODelayOnBase                       46      // 2 Bits, Bit 7-6
#define     LOG_fODelayOnBaseMask 0xC0
#define     LOG_fODelayOnBaseShift 6
#define LOG_fODelayOnTime                       46      // 14 Bits, Bit 13-0
#define     LOG_fODelayOnTimeMask 0x3FFF
#define     LOG_fODelayOnTimeShift 0
#define LOG_fODelayOffBase                      48      // 2 Bits, Bit 7-6
#define     LOG_fODelayOffBaseMask 0xC0
#define     LOG_fODelayOffBaseShift 6
#define LOG_fODelayOffTime                      48      // 14 Bits, Bit 13-0
#define     LOG_fODelayOffTimeMask 0x3FFF
#define     LOG_fODelayOffTimeShift 0
#define LOG_fORepeatOnBase                      50      // 2 Bits, Bit 7-6
#define     LOG_fORepeatOnBaseMask 0xC0
#define     LOG_fORepeatOnBaseShift 6
#define LOG_fORepeatOnTime                      50      // 14 Bits, Bit 13-0
#define     LOG_fORepeatOnTimeMask 0x3FFF
#define     LOG_fORepeatOnTimeShift 0
#define LOG_fORepeatOffBase                     52      // 2 Bits, Bit 7-6
#define     LOG_fORepeatOffBaseMask 0xC0
#define     LOG_fORepeatOffBaseShift 6
#define LOG_fORepeatOffTime                     52      // 14 Bits, Bit 13-0
#define     LOG_fORepeatOffTimeMask 0x3FFF
#define     LOG_fORepeatOffTimeShift 0
#define LOG_fODelay                             54      // 1 Bit, Bit 7
#define     LOG_fODelayMask 0x80
#define     LOG_fODelayShift 7
#define LOG_fODelayOnRepeat                     54      // 2 Bits, Bit 6-5
#define     LOG_fODelayOnRepeatMask 0x60
#define     LOG_fODelayOnRepeatShift 5
#define LOG_fODelayOnReset                      54      // 1 Bit, Bit 4
#define     LOG_fODelayOnResetMask 0x10
#define     LOG_fODelayOnResetShift 4
#define LOG_fODelayOffRepeat                    54      // 2 Bits, Bit 3-2
#define     LOG_fODelayOffRepeatMask 0x0C
#define     LOG_fODelayOffRepeatShift 2
#define LOG_fODelayOffReset                     54      // 1 Bit, Bit 1
#define     LOG_fODelayOffResetMask 0x02
#define     LOG_fODelayOffResetShift 1
#define LOG_fOStair                             54      // 1 Bit, Bit 0
#define     LOG_fOStairMask 0x01
#define     LOG_fOStairShift 0
#define LOG_fORetrigger                         55      // 1 Bit, Bit 7
#define     LOG_fORetriggerMask 0x80
#define     LOG_fORetriggerShift 7
#define LOG_fOStairOff                          55      // 1 Bit, Bit 6
#define     LOG_fOStairOffMask 0x40
#define     LOG_fOStairOffShift 6
#define LOG_fORepeat                            55      // 1 Bit, Bit 5
#define     LOG_fORepeatMask 0x20
#define     LOG_fORepeatShift 5
#define LOG_fOOutputFilter                      55      // 2 Bits, Bit 4-3
#define     LOG_fOOutputFilterMask 0x18
#define     LOG_fOOutputFilterShift 3
#define LOG_fOSendOnChange                      55      // 1 Bit, Bit 2
#define     LOG_fOSendOnChangeMask 0x04
#define     LOG_fOSendOnChangeShift 2
#define LOG_fOLockEnabled                       55      // 1 Bit, Bit 1
#define     LOG_fOLockEnabledMask 0x02
#define     LOG_fOLockEnabledShift 1
#define LOG_fODpt                               56      // 8 Bits, Bit 7-0
#define LOG_fOLockTriggerLock                   57      // 2 Bits, Bit 7-6
#define     LOG_fOLockTriggerLockMask 0xC0
#define     LOG_fOLockTriggerLockShift 6
#define LOG_fOLockTriggerUnlock                 57      // 2 Bits, Bit 5-4
#define     LOG_fOLockTriggerUnlockMask 0x30
#define     LOG_fOLockTriggerUnlockShift 4
#define LOG_fOLockResetQueue                    57      // 2 Bits, Bit 3-2
#define     LOG_fOLockResetQueueMask 0x0C
#define     LOG_fOLockResetQueueShift 2
#define LOG_fOLockKind                          57      // 2 Bits, Bit 1-0
#define     LOG_fOLockKindMask 0x03
#define     LOG_fOLockKindShift 0
#define LOG_fOLockFunction                      58      // uint8_t
#define LOG_fOLockFunctionRel                   58      // int8_t
#define LOG_fOOnAll                             59      // 8 Bits, Bit 7-0
#define LOG_fOOnDpt1                            60      // 8 Bits, Bit 7-0
#define LOG_fOOnDpt2                            60      // 8 Bits, Bit 7-0
#define LOG_fOOnDpt3Dir                         60      // 5 Bits, Bit 7-3
#define     LOG_fOOnDpt3DirMask 0xF8
#define     LOG_fOOnDpt3DirShift 3
#define LOG_fOOnDpt3Dim                         60      // 3 Bits, Bit 2-0
#define     LOG_fOOnDpt3DimMask 0x07
#define     LOG_fOOnDpt3DimShift 0
#define LOG_fOOnDpt5                            60      // uint8_t
#define LOG_fOOnDpt5001                         60      // uint8_t
#define LOG_fOOnDpt6                            60      // int8_t
#define LOG_fOOnDpt7                            60      // uint16_t
#define LOG_fOOnDpt8                            60      // int16_t
#define LOG_fOOnDpt9                            60      // float (4 Byte)
#define LOG_fOOnDpt12                           60      // uint32_t
#define LOG_fOOnDpt13                           60      // int32_t
#define LOG_fOOnDpt14                           60      // float (4 Byte)
#define LOG_fOOnDpt16                           60      // char*, 14 Byte
#define     LOG_fOOnDpt16Length 14
#define LOG_fOOnDpt17                           60      // 8 Bits, Bit 7-0
#define LOG_fOOnRGB                             60      // 24 Bits, Bit 31-8
#define     LOG_fOOnRGBMask 0xFFFFFF00
#define     LOG_fOOnRGBShift 8
#define LOG_fOOnLedProvider                     64      // 3 Bits, Bit 2-0
#define     LOG_fOOnLedProviderMask 0x07
#define     LOG_fOOnLedProviderShift 0
#define LOG_fOOnLedEffect                       65      // 3 Bits, Bit 2-0
#define     LOG_fOOnLedEffectMask 0x07
#define     LOG_fOOnLedEffectShift 0
#define LOG_fOOnLedDuration                     66      // uint16_t
#define LOG_fOOnPAArea                          60      // 4 Bits, Bit 7-4
#define     LOG_fOOnPAAreaMask 0xF0
#define     LOG_fOOnPAAreaShift 4
#define LOG_fOOnPALine                          60      // 4 Bits, Bit 3-0
#define     LOG_fOOnPALineMask 0x0F
#define     LOG_fOOnPALineShift 0
#define LOG_fOOnPADevice                        61      // uint8_t
#define LOG_fOOnFunction                        60      // 8 Bits, Bit 7-0
#define LOG_fOOnKOKind                          65      // 2 Bits, Bit 7-6
#define     LOG_fOOnKOKindMask 0xC0
#define     LOG_fOOnKOKindShift 6
#define LOG_fOOnKONumber                        60      // uint16_t
#define LOG_fOOnKONumberRel                     60      // int16_t
#define LOG_fOOnKODpt                           62      // 8 Bits, Bit 7-0
#define LOG_fOOnKOSend                          65      // 2 Bits, Bit 5-4
#define     LOG_fOOnKOSendMask 0x30
#define     LOG_fOOnKOSendShift 4
#define LOG_fOOnKOSendNumber                    66      // uint16_t
#define LOG_fOOnKOSendNumberRel                 66      // int16_t
#define LOG_fOOffAll                            74      // 8 Bits, Bit 7-0
#define LOG_fOOffDpt1                           75      // 8 Bits, Bit 7-0
#define LOG_fOOffDpt2                           75      // 8 Bits, Bit 7-0
#define LOG_fOOffDpt3Dir                        75      // 5 Bits, Bit 7-3
#define     LOG_fOOffDpt3DirMask 0xF8
#define     LOG_fOOffDpt3DirShift 3
#define LOG_fOOffDpt3Dim                        75      // 3 Bits, Bit 2-0
#define     LOG_fOOffDpt3DimMask 0x07
#define     LOG_fOOffDpt3DimShift 0
#define LOG_fOOffDpt5                           75      // uint8_t
#define LOG_fOOffDpt5001                        75      // uint8_t
#define LOG_fOOffDpt6                           75      // int8_t
#define LOG_fOOffDpt7                           75      // uint16_t
#define LOG_fOOffDpt8                           75      // int16_t
#define LOG_fOOffDpt9                           75      // float (4 Byte)
#define LOG_fOOffDpt12                          75      // uint32_t
#define LOG_fOOffDpt13                          75      // int32_t
#define LOG_fOOffDpt14                          75      // float (4 Byte)
#define LOG_fOOffDpt16                          75      // char*, 14 Byte
#define     LOG_fOOffDpt16Length 14
#define LOG_fOOffDpt17                          75      // 8 Bits, Bit 7-0
#define LOG_fOOffRGB                            75      // 24 Bits, Bit 31-8
#define     LOG_fOOffRGBMask 0xFFFFFF00
#define     LOG_fOOffRGBShift 8
#define LOG_fOOffLedProvider                    79      // 3 Bits, Bit 2-0
#define     LOG_fOOffLedProviderMask 0x07
#define     LOG_fOOffLedProviderShift 0
#define LOG_fOOffLedEffect                      80      // 3 Bits, Bit 2-0
#define     LOG_fOOffLedEffectMask 0x07
#define     LOG_fOOffLedEffectShift 0
#define LOG_fOOffLedDuration                    81      // uint16_t
#define LOG_fOOffPAArea                         75      // 4 Bits, Bit 7-4
#define     LOG_fOOffPAAreaMask 0xF0
#define     LOG_fOOffPAAreaShift 4
#define LOG_fOOffPALine                         75      // 4 Bits, Bit 3-0
#define     LOG_fOOffPALineMask 0x0F
#define     LOG_fOOffPALineShift 0
#define LOG_fOOffPADevice                       76      // uint8_t
#define LOG_fOOffFunction                       75      // 8 Bits, Bit 7-0
#define LOG_fOOffKOKind                         80      // 2 Bits, Bit 7-6
#define     LOG_fOOffKOKindMask 0xC0
#define     LOG_fOOffKOKindShift 6
#define LOG_fOOffKONumber                       75      // uint16_t
#define LOG_fOOffKONumberRel                    75      // int16_t
#define LOG_fOOffKODpt                          77      // 8 Bits, Bit 7-0
#define LOG_fOOffKOSend                         80      // 2 Bits, Bit 5-4
#define     LOG_fOOffKOSendMask 0x30
#define     LOG_fOOffKOSendShift 4
#define LOG_fOOffKOSendNumber                   81      // uint16_t
#define LOG_fOOffKOSendNumberRel                81      // int16_t

// Zeit bis der Kanal nach einem Neustart aktiv wird
#define ParamLOG_fChannelDelayBase                   ((knx.paramByte(LOG_ParamCalcIndex(LOG_fChannelDelayBase)) & LOG_fChannelDelayBaseMask) >> LOG_fChannelDelayBaseShift)
// Zeit bis der Kanal nach einem Neustart aktiv wird
#define ParamLOG_fChannelDelayTime                   (knx.paramWord(LOG_ParamCalcIndex(LOG_fChannelDelayTime)) & LOG_fChannelDelayTimeMask)
// Zeit bis der Kanal nach einem Neustart aktiv wird (in Millisekunden)
#define ParamLOG_fChannelDelayTimeMS                 (paramDelay(knx.paramWord(LOG_ParamCalcIndex(LOG_fChannelDelayTime))))
// Logik-Operation
#define ParamLOG_fLogic                              (PT_Logic)(knx.paramByte(LOG_ParamCalcIndex(LOG_fLogic)))
// Logik auswerten
#define ParamLOG_fCalculate                          (PT_Calculate)(knx.paramByte(LOG_ParamCalcIndex(LOG_fCalculate)) & LOG_fCalculateMask)
// Kanal deaktivieren (zu Testzwecken)
#define ParamLOG_fDisable                            ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fDisable)) & LOG_fDisableMask))
// Tor geht sofort wieder zu
#define ParamLOG_fTGate                              ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTGate)) & LOG_fTGateMask))
// Wert EIN intern weiterleiten
#define ParamLOG_fOInternalOn                        ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fOInternalOn)) & LOG_fOInternalOnMask))
// Wert AUS intern weiterleiten
#define ParamLOG_fOInternalOff                       ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fOInternalOff)) & LOG_fOInternalOffMask))
// Logik sendet ihren Wert weiter
#define ParamLOG_fTrigger                            (knx.paramByte(LOG_ParamCalcIndex(LOG_fTrigger)))
//           Eingang 1
#define ParamLOG_fTriggerE1                          ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTriggerE1)) & LOG_fTriggerE1Mask))
//           Eingang 2
#define ParamLOG_fTriggerE2                          ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTriggerE2)) & LOG_fTriggerE2Mask))
//           Interner Eingang 3
#define ParamLOG_fTriggerI1                          ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTriggerI1)) & LOG_fTriggerI1Mask))
//           Interner Eingang 4
#define ParamLOG_fTriggerI2                          ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTriggerI2)) & LOG_fTriggerI2Mask))
// Logik sendet ihren Wert weiter
#define ParamLOG_fTriggerTime                        (knx.paramByte(LOG_ParamCalcIndex(LOG_fTriggerTime)))
// Beim schließen vom Tor wird
#define ParamLOG_fTriggerGateClose                   (PT_GateTrigger)((knx.paramByte(LOG_ParamCalcIndex(LOG_fTriggerGateClose)) & LOG_fTriggerGateCloseMask) >> LOG_fTriggerGateCloseShift)
// Beim öffnen vom Tor wird
#define ParamLOG_fTriggerGateOpen                    (PT_GateTrigger)((knx.paramByte(LOG_ParamCalcIndex(LOG_fTriggerGateOpen)) & LOG_fTriggerGateOpenMask) >> LOG_fTriggerGateOpenShift)
// Wert für Eingang wird ermittelt durch
#define ParamLOG_fE1ConvertInt                       (PT_InputConv)((knx.paramByte(LOG_ParamCalcIndex(LOG_fE1ConvertInt)) & LOG_fE1ConvertIntMask) >> LOG_fE1ConvertIntShift)
// Wert für Eingang wird ermittelt durch
#define ParamLOG_fE1Convert                          (PT_InputConv)((knx.paramByte(LOG_ParamCalcIndex(LOG_fE1Convert)) & LOG_fE1ConvertMask) >> LOG_fE1ConvertShift)
// Wert für Eingang wird ermittelt durch
#define ParamLOG_fE1ConvertFloat                     (PT_InputConv)((knx.paramByte(LOG_ParamCalcIndex(LOG_fE1ConvertFloat)) & LOG_fE1ConvertFloatMask) >> LOG_fE1ConvertFloatShift)
// Wert für Eingang wird ermittelt durch
#define ParamLOG_fE1ConvertSpecial                   (PT_InputConv)((knx.paramByte(LOG_ParamCalcIndex(LOG_fE1ConvertSpecial)) & LOG_fE1ConvertSpecialMask) >> LOG_fE1ConvertSpecialShift)
// Wert für Eingang wird ermittelt durch
#define ParamLOG_fE1ConvertBool                      (PT_InputConv)((knx.paramByte(LOG_ParamCalcIndex(LOG_fE1ConvertBool)) & LOG_fE1ConvertBoolMask) >> LOG_fE1ConvertBoolShift)
// Eingang 1
#define ParamLOG_fE1                                 (PT_InputEnable)(knx.paramByte(LOG_ParamCalcIndex(LOG_fE1)) & LOG_fE1Mask)
// DPT für Eingang
#define ParamLOG_fE1Dpt                              (PT_LogicDpt)(knx.paramByte(LOG_ParamCalcIndex(LOG_fE1Dpt)))
// Eingang wird gelesen alle
#define ParamLOG_fE1RepeatBase                       ((knx.paramByte(LOG_ParamCalcIndex(LOG_fE1RepeatBase)) & LOG_fE1RepeatBaseMask) >> LOG_fE1RepeatBaseShift)
// Eingang wird gelesen alle
#define ParamLOG_fE1RepeatTime                       (knx.paramWord(LOG_ParamCalcIndex(LOG_fE1RepeatTime)) & LOG_fE1RepeatTimeMask)
// Eingang wird gelesen alle (in Millisekunden)
#define ParamLOG_fE1RepeatTimeMS                     (paramDelay(knx.paramWord(LOG_ParamCalcIndex(LOG_fE1RepeatTime))))
//     Nummer des Kommunikationsobjekts
#define ParamLOG_fE1OtherKO                          (knx.paramWord(LOG_ParamCalcIndex(LOG_fE1OtherKO)))
//     Nummer des Kommunikationsobjekts
#define ParamLOG_fE1OtherKORel                       ((int16_t)knx.paramWord(LOG_ParamCalcIndex(LOG_fE1OtherKORel)))
// Falls Vorbelegung aus dem Speicher nicht möglich oder nicht gewünscht, dann vorbelegen mit
#define ParamLOG_fE1Default                          (PT_InputDefault)(knx.paramByte(LOG_ParamCalcIndex(LOG_fE1Default)) & LOG_fE1DefaultMask)
// Eingang vorbelegen mit
#define ParamLOG_fE1DefaultExt                       (PT_InputDefault)(knx.paramByte(LOG_ParamCalcIndex(LOG_fE1DefaultExt)) & LOG_fE1DefaultExtMask)
// Eingangswert speichern und beim nächsten Neustart als Vorbelegung nutzen?
#define ParamLOG_fE1DefaultEEPROM                    ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fE1DefaultEEPROM)) & LOG_fE1DefaultEEPROMMask))
// Nur so lange zyklisch lesen, bis erstes Telegramm eingeht
#define ParamLOG_fE1DefaultRepeat                    ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fE1DefaultRepeat)) & LOG_fE1DefaultRepeatMask))
// Kommunikationsobjekt für Eingang
#define ParamLOG_fE1UseOtherKO                       (PT_KORelInput)((knx.paramByte(LOG_ParamCalcIndex(LOG_fE1UseOtherKO)) & LOG_fE1UseOtherKOMask) >> LOG_fE1UseOtherKOShift)
// Von-Wert
#define ParamLOG_fE1LowDelta                         ((int32_t)knx.paramInt(LOG_ParamCalcIndex(LOG_fE1LowDelta)))
// Bis-Wert
#define ParamLOG_fE1HighDelta                        ((int32_t)knx.paramInt(LOG_ParamCalcIndex(LOG_fE1HighDelta)))
// Von-Wert
#define ParamLOG_fE1LowDeltaFloat                    (knx.paramFloat(LOG_ParamCalcIndex(LOG_fE1LowDeltaFloat), Float_Enc_IEEE754Single))
// Bis-Wert
#define ParamLOG_fE1HighDeltaFloat                   (knx.paramFloat(LOG_ParamCalcIndex(LOG_fE1HighDeltaFloat), Float_Enc_IEEE754Single))
// Von-Wert
#define ParamLOG_fE1LowDeltaDouble                   (knx.paramFloat(LOG_ParamCalcIndex(LOG_fE1LowDeltaDouble), Float_Enc_IEEE754Single))
// Bis-Wert
#define ParamLOG_fE1HighDeltaDouble                  (knx.paramFloat(LOG_ParamCalcIndex(LOG_fE1HighDeltaDouble), Float_Enc_IEEE754Single))
// Nächste Zeile auswerten?
#define ParamLOG_fE1Low0Valid                        ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fE1Low0Valid)) & LOG_fE1Low0ValidMask))
// Nächste Zeile auswerten?
#define ParamLOG_fE1Low1Valid                        ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fE1Low1Valid)) & LOG_fE1Low1ValidMask))
// Nächste Zeile auswerten?
#define ParamLOG_fE1Low2Valid                        ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fE1Low2Valid)) & LOG_fE1Low2ValidMask))
// Nächste Zeile auswerten?
#define ParamLOG_fE1Low3Valid                        ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fE1Low3Valid)) & LOG_fE1Low3ValidMask))
// Nächste Zeile auswerten?
#define ParamLOG_fE1Low4Valid                        ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fE1Low4Valid)) & LOG_fE1Low4ValidMask))
// Nächste Zeile auswerten?
#define ParamLOG_fE1Low5Valid                        ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fE1Low5Valid)) & LOG_fE1Low5ValidMask))
// Nächste Zeile auswerten?
#define ParamLOG_fE1Low6Valid                        ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fE1Low6Valid)) & LOG_fE1Low6ValidMask))
// Eingang ist EIN, wenn Wert gleich
#define ParamLOG_fE1Low0Dpt2                         (knx.paramByte(LOG_ParamCalcIndex(LOG_fE1Low0Dpt2)))
// ... oder wenn Wert gleich 
#define ParamLOG_fE1Low1Dpt2                         (knx.paramByte(LOG_ParamCalcIndex(LOG_fE1Low1Dpt2)))
// ... oder wenn Wert gleich 
#define ParamLOG_fE1Low2Dpt2                         (knx.paramByte(LOG_ParamCalcIndex(LOG_fE1Low2Dpt2)))
// ... oder wenn Wert gleich 
#define ParamLOG_fE1Low3Dpt2                         (knx.paramByte(LOG_ParamCalcIndex(LOG_fE1Low3Dpt2)))
// Eingang ist konstant
#define ParamLOG_fE1LowDpt2Fix                       (knx.paramByte(LOG_ParamCalcIndex(LOG_fE1LowDpt2Fix)))
// Eingang ist EIN, wenn Wert gleich
#define ParamLOG_fE1Low0Dpt3Dir                      ((knx.paramByte(LOG_ParamCalcIndex(LOG_fE1Low0Dpt3Dir)) & LOG_fE1Low0Dpt3DirMask) >> LOG_fE1Low0Dpt3DirShift)
// 
#define ParamLOG_fE1Low0Dpt3Dim                      (knx.paramByte(LOG_ParamCalcIndex(LOG_fE1Low0Dpt3Dim)) & LOG_fE1Low0Dpt3DimMask)
// ... oder wenn Wert gleich 
#define ParamLOG_fE1Low1Dpt3Dir                      ((knx.paramByte(LOG_ParamCalcIndex(LOG_fE1Low1Dpt3Dir)) & LOG_fE1Low1Dpt3DirMask) >> LOG_fE1Low1Dpt3DirShift)
// 
#define ParamLOG_fE1Low1Dpt3Dim                      (knx.paramByte(LOG_ParamCalcIndex(LOG_fE1Low1Dpt3Dim)) & LOG_fE1Low1Dpt3DimMask)
// ... oder wenn Wert gleich 
#define ParamLOG_fE1Low2Dpt3Dir                      ((knx.paramByte(LOG_ParamCalcIndex(LOG_fE1Low2Dpt3Dir)) & LOG_fE1Low2Dpt3DirMask) >> LOG_fE1Low2Dpt3DirShift)
// 
#define ParamLOG_fE1Low2Dpt3Dim                      (knx.paramByte(LOG_ParamCalcIndex(LOG_fE1Low2Dpt3Dim)) & LOG_fE1Low2Dpt3DimMask)
// ... oder wenn Wert gleich 
#define ParamLOG_fE1Low3Dpt3Dir                      ((knx.paramByte(LOG_ParamCalcIndex(LOG_fE1Low3Dpt3Dir)) & LOG_fE1Low3Dpt3DirMask) >> LOG_fE1Low3Dpt3DirShift)
// 
#define ParamLOG_fE1Low3Dpt3Dim                      (knx.paramByte(LOG_ParamCalcIndex(LOG_fE1Low3Dpt3Dim)) & LOG_fE1Low3Dpt3DimMask)
// Eingang ist konstant
#define ParamLOG_fE1LowDpt3FixDir                    ((knx.paramByte(LOG_ParamCalcIndex(LOG_fE1LowDpt3FixDir)) & LOG_fE1LowDpt3FixDirMask) >> LOG_fE1LowDpt3FixDirShift)
// 
#define ParamLOG_fE1LowDpt3FixDim                    (knx.paramByte(LOG_ParamCalcIndex(LOG_fE1LowDpt3FixDim)) & LOG_fE1LowDpt3FixDimMask)
// Von-Wert
#define ParamLOG_fE1LowDpt5                          (knx.paramByte(LOG_ParamCalcIndex(LOG_fE1LowDpt5)))
// Bis-Wert
#define ParamLOG_fE1HighDpt5                         (knx.paramByte(LOG_ParamCalcIndex(LOG_fE1HighDpt5)))
// Eingang ist EIN bei Wert
#define ParamLOG_fE1Low0Dpt5In                       (knx.paramByte(LOG_ParamCalcIndex(LOG_fE1Low0Dpt5In)))
// ... oder bei Wert
#define ParamLOG_fE1Low1Dpt5In                       (knx.paramByte(LOG_ParamCalcIndex(LOG_fE1Low1Dpt5In)))
// ... oder bei Wert
#define ParamLOG_fE1Low2Dpt5In                       (knx.paramByte(LOG_ParamCalcIndex(LOG_fE1Low2Dpt5In)))
// ... oder bei Wert
#define ParamLOG_fE1Low3Dpt5In                       (knx.paramByte(LOG_ParamCalcIndex(LOG_fE1Low3Dpt5In)))
// ... oder bei Wert
#define ParamLOG_fE1Low4Dpt5In                       (knx.paramByte(LOG_ParamCalcIndex(LOG_fE1Low4Dpt5In)))
// ... oder bei Wert
#define ParamLOG_fE1Low5Dpt5In                       (knx.paramByte(LOG_ParamCalcIndex(LOG_fE1Low5Dpt5In)))
// ... oder bei Wert
#define ParamLOG_fE1Low6Dpt5In                       (knx.paramByte(LOG_ParamCalcIndex(LOG_fE1Low6Dpt5In)))
// Eingang ist konstant
#define ParamLOG_fE1LowDpt5Fix                       (knx.paramByte(LOG_ParamCalcIndex(LOG_fE1LowDpt5Fix)))
// Von-Wert
#define ParamLOG_fE1LowDpt5001                       (knx.paramByte(LOG_ParamCalcIndex(LOG_fE1LowDpt5001)))
// Bis-Wert
#define ParamLOG_fE1HighDpt5001                      (knx.paramByte(LOG_ParamCalcIndex(LOG_fE1HighDpt5001)))
// Eingang ist EIN bei Wert
#define ParamLOG_fE1Low0Dpt5xIn                      (knx.paramByte(LOG_ParamCalcIndex(LOG_fE1Low0Dpt5xIn)))
// ... oder bei Wert
#define ParamLOG_fE1Low1Dpt5xIn                      (knx.paramByte(LOG_ParamCalcIndex(LOG_fE1Low1Dpt5xIn)))
// ... oder bei Wert
#define ParamLOG_fE1Low2Dpt5xIn                      (knx.paramByte(LOG_ParamCalcIndex(LOG_fE1Low2Dpt5xIn)))
// ... oder bei Wert
#define ParamLOG_fE1Low3Dpt5xIn                      (knx.paramByte(LOG_ParamCalcIndex(LOG_fE1Low3Dpt5xIn)))
// ... oder bei Wert
#define ParamLOG_fE1Low4Dpt5xIn                      (knx.paramByte(LOG_ParamCalcIndex(LOG_fE1Low4Dpt5xIn)))
// ... oder bei Wert
#define ParamLOG_fE1Low5Dpt5xIn                      (knx.paramByte(LOG_ParamCalcIndex(LOG_fE1Low5Dpt5xIn)))
// ... oder bei Wert
#define ParamLOG_fE1Low6Dpt5xIn                      (knx.paramByte(LOG_ParamCalcIndex(LOG_fE1Low6Dpt5xIn)))
// Eingang ist konstant
#define ParamLOG_fE1LowDpt5xFix                      (knx.paramByte(LOG_ParamCalcIndex(LOG_fE1LowDpt5xFix)))
// Von-Wert
#define ParamLOG_fE1LowDpt6                          ((int8_t)knx.paramByte(LOG_ParamCalcIndex(LOG_fE1LowDpt6)))
// Bis-Wert
#define ParamLOG_fE1HighDpt6                         ((int8_t)knx.paramByte(LOG_ParamCalcIndex(LOG_fE1HighDpt6)))
// Eingang ist EIN bei Wert
#define ParamLOG_fE1Low0Dpt6In                       ((int8_t)knx.paramByte(LOG_ParamCalcIndex(LOG_fE1Low0Dpt6In)))
// ... oder bei Wert
#define ParamLOG_fE1Low1Dpt6In                       ((int8_t)knx.paramByte(LOG_ParamCalcIndex(LOG_fE1Low1Dpt6In)))
// ... oder bei Wert
#define ParamLOG_fE1Low2Dpt6In                       ((int8_t)knx.paramByte(LOG_ParamCalcIndex(LOG_fE1Low2Dpt6In)))
// ... oder bei Wert
#define ParamLOG_fE1Low3Dpt6In                       ((int8_t)knx.paramByte(LOG_ParamCalcIndex(LOG_fE1Low3Dpt6In)))
// ... oder bei Wert
#define ParamLOG_fE1Low4Dpt6In                       ((int8_t)knx.paramByte(LOG_ParamCalcIndex(LOG_fE1Low4Dpt6In)))
// ... oder bei Wert
#define ParamLOG_fE1Low5Dpt6In                       ((int8_t)knx.paramByte(LOG_ParamCalcIndex(LOG_fE1Low5Dpt6In)))
// ... oder bei Wert
#define ParamLOG_fE1Low6Dpt6In                       ((int8_t)knx.paramByte(LOG_ParamCalcIndex(LOG_fE1Low6Dpt6In)))
// Eingang ist konstant
#define ParamLOG_fE1LowDpt6Fix                       ((int8_t)knx.paramByte(LOG_ParamCalcIndex(LOG_fE1LowDpt6Fix)))
// Von-Wert
#define ParamLOG_fE1LowDpt7                          (knx.paramWord(LOG_ParamCalcIndex(LOG_fE1LowDpt7)))
// Bis-Wert
#define ParamLOG_fE1HighDpt7                         (knx.paramWord(LOG_ParamCalcIndex(LOG_fE1HighDpt7)))
// Eingang ist EIN bei Wert
#define ParamLOG_fE1Low0Dpt7In                       (knx.paramWord(LOG_ParamCalcIndex(LOG_fE1Low0Dpt7In)))
// ... oder bei Wert
#define ParamLOG_fE1Low1Dpt7In                       (knx.paramWord(LOG_ParamCalcIndex(LOG_fE1Low1Dpt7In)))
// ... oder bei Wert
#define ParamLOG_fE1Low2Dpt7In                       (knx.paramWord(LOG_ParamCalcIndex(LOG_fE1Low2Dpt7In)))
// Eingang ist konstant
#define ParamLOG_fE1LowDpt7Fix                       (knx.paramWord(LOG_ParamCalcIndex(LOG_fE1LowDpt7Fix)))
// Von-Wert
#define ParamLOG_fE1LowDpt8                          ((int16_t)knx.paramWord(LOG_ParamCalcIndex(LOG_fE1LowDpt8)))
// Bis-Wert
#define ParamLOG_fE1HighDpt8                         ((int16_t)knx.paramWord(LOG_ParamCalcIndex(LOG_fE1HighDpt8)))
// Eingang ist EIN bei Wert
#define ParamLOG_fE1Low0Dpt8In                       ((int16_t)knx.paramWord(LOG_ParamCalcIndex(LOG_fE1Low0Dpt8In)))
// ... oder bei Wert
#define ParamLOG_fE1Low1Dpt8In                       ((int16_t)knx.paramWord(LOG_ParamCalcIndex(LOG_fE1Low1Dpt8In)))
// ... oder bei Wert
#define ParamLOG_fE1Low2Dpt8In                       ((int16_t)knx.paramWord(LOG_ParamCalcIndex(LOG_fE1Low2Dpt8In)))
// Eingang ist konstant
#define ParamLOG_fE1LowDpt8Fix                       ((int16_t)knx.paramWord(LOG_ParamCalcIndex(LOG_fE1LowDpt8Fix)))
// Von-Wert
#define ParamLOG_fE1LowDpt9                          (knx.paramFloat(LOG_ParamCalcIndex(LOG_fE1LowDpt9), Float_Enc_IEEE754Single))
// Bis-Wert
#define ParamLOG_fE1HighDpt9                         (knx.paramFloat(LOG_ParamCalcIndex(LOG_fE1HighDpt9), Float_Enc_IEEE754Single))
// Eingang ist konstant
#define ParamLOG_fE1LowDpt9Fix                       (knx.paramFloat(LOG_ParamCalcIndex(LOG_fE1LowDpt9Fix), Float_Enc_IEEE754Single))
// Von-Wert
#define ParamLOG_fE1LowDpt12                         (knx.paramInt(LOG_ParamCalcIndex(LOG_fE1LowDpt12)))
// Bis-Wert
#define ParamLOG_fE1HighDpt12                        (knx.paramInt(LOG_ParamCalcIndex(LOG_fE1HighDpt12)))
// Eingang ist konstant
#define ParamLOG_fE1LowDpt12Fix                      (knx.paramInt(LOG_ParamCalcIndex(LOG_fE1LowDpt12Fix)))
// Von-Wert
#define ParamLOG_fE1LowDpt13                         ((int32_t)knx.paramInt(LOG_ParamCalcIndex(LOG_fE1LowDpt13)))
// Bis-Wert
#define ParamLOG_fE1HighDpt13                        ((int32_t)knx.paramInt(LOG_ParamCalcIndex(LOG_fE1HighDpt13)))
// Eingang ist konstant
#define ParamLOG_fE1LowDpt13Fix                      ((int32_t)knx.paramInt(LOG_ParamCalcIndex(LOG_fE1LowDpt13Fix)))
// Von-Wert
#define ParamLOG_fE1LowDpt14                         (knx.paramFloat(LOG_ParamCalcIndex(LOG_fE1LowDpt14), Float_Enc_IEEE754Single))
// Bis-Wert
#define ParamLOG_fE1HighDpt14                        (knx.paramFloat(LOG_ParamCalcIndex(LOG_fE1HighDpt14), Float_Enc_IEEE754Single))
// Eingang ist konstant
#define ParamLOG_fE1LowDpt14Fix                      (knx.paramFloat(LOG_ParamCalcIndex(LOG_fE1LowDpt14Fix), Float_Enc_IEEE754Single))
// Eingang ist EIN bei Szene
#define ParamLOG_fE1Low0Dpt17                        (knx.paramByte(LOG_ParamCalcIndex(LOG_fE1Low0Dpt17)))
// ... oder bei Szene
#define ParamLOG_fE1Low1Dpt17                        (knx.paramByte(LOG_ParamCalcIndex(LOG_fE1Low1Dpt17)))
// ... oder bei Szene
#define ParamLOG_fE1Low2Dpt17                        (knx.paramByte(LOG_ParamCalcIndex(LOG_fE1Low2Dpt17)))
// ... oder bei Szene
#define ParamLOG_fE1Low3Dpt17                        (knx.paramByte(LOG_ParamCalcIndex(LOG_fE1Low3Dpt17)))
// ... oder bei Szene
#define ParamLOG_fE1Low4Dpt17                        (knx.paramByte(LOG_ParamCalcIndex(LOG_fE1Low4Dpt17)))
// ... oder bei Szene
#define ParamLOG_fE1Low5Dpt17                        (knx.paramByte(LOG_ParamCalcIndex(LOG_fE1Low5Dpt17)))
// ... oder bei Szene
#define ParamLOG_fE1Low6Dpt17                        (knx.paramByte(LOG_ParamCalcIndex(LOG_fE1Low6Dpt17)))
// ... oder bei Szene
#define ParamLOG_fE1Low7Dpt17                        (knx.paramByte(LOG_ParamCalcIndex(LOG_fE1Low7Dpt17)))
// Eingang ist konstant
#define ParamLOG_fE1LowDpt17Fix                      (knx.paramByte(LOG_ParamCalcIndex(LOG_fE1LowDpt17Fix)))
// Von-Wert
#define ParamLOG_fE1LowDptRGB                        ((int32_t)knx.paramInt(LOG_ParamCalcIndex(LOG_fE1LowDptRGB)))
// Bis-Wert
#define ParamLOG_fE1HighDptRGB                       ((int32_t)knx.paramInt(LOG_ParamCalcIndex(LOG_fE1HighDptRGB)))
// Eingang ist konstant
#define ParamLOG_fE1LowDptRGBFix                     ((int32_t)knx.paramInt(LOG_ParamCalcIndex(LOG_fE1LowDptRGBFix)))
// Wert für Eingang wird ermittelt durch
#define ParamLOG_fE2ConvertInt                       (PT_InputConv)((knx.paramByte(LOG_ParamCalcIndex(LOG_fE2ConvertInt)) & LOG_fE2ConvertIntMask) >> LOG_fE2ConvertIntShift)
// Wert für Eingang wird ermittelt durch
#define ParamLOG_fE2Convert                          (PT_InputConv)((knx.paramByte(LOG_ParamCalcIndex(LOG_fE2Convert)) & LOG_fE2ConvertMask) >> LOG_fE2ConvertShift)
// Wert für Eingang wird ermittelt durch
#define ParamLOG_fE2ConvertFloat                     (PT_InputConv)((knx.paramByte(LOG_ParamCalcIndex(LOG_fE2ConvertFloat)) & LOG_fE2ConvertFloatMask) >> LOG_fE2ConvertFloatShift)
// Wert für Eingang wird ermittelt durch
#define ParamLOG_fE2ConvertSpecial                   (PT_InputConv)((knx.paramByte(LOG_ParamCalcIndex(LOG_fE2ConvertSpecial)) & LOG_fE2ConvertSpecialMask) >> LOG_fE2ConvertSpecialShift)
// Wert für Eingang wird ermittelt durch
#define ParamLOG_fE2ConvertBool                      (PT_InputConv)((knx.paramByte(LOG_ParamCalcIndex(LOG_fE2ConvertBool)) & LOG_fE2ConvertBoolMask) >> LOG_fE2ConvertBoolShift)
// Eingang 2
#define ParamLOG_fE2                                 (PT_InputEnable)(knx.paramByte(LOG_ParamCalcIndex(LOG_fE2)) & LOG_fE2Mask)
// DPT für Eingang
#define ParamLOG_fE2Dpt                              (PT_LogicDpt)(knx.paramByte(LOG_ParamCalcIndex(LOG_fE2Dpt)))
// Eingang wird gelesen alle
#define ParamLOG_fE2RepeatBase                       ((knx.paramByte(LOG_ParamCalcIndex(LOG_fE2RepeatBase)) & LOG_fE2RepeatBaseMask) >> LOG_fE2RepeatBaseShift)
// Eingang wird gelesen alle
#define ParamLOG_fE2RepeatTime                       (knx.paramWord(LOG_ParamCalcIndex(LOG_fE2RepeatTime)) & LOG_fE2RepeatTimeMask)
// Eingang wird gelesen alle (in Millisekunden)
#define ParamLOG_fE2RepeatTimeMS                     (paramDelay(knx.paramWord(LOG_ParamCalcIndex(LOG_fE2RepeatTime))))
//     Nummer des Kommunikationsobjekts
#define ParamLOG_fE2OtherKO                          (knx.paramWord(LOG_ParamCalcIndex(LOG_fE2OtherKO)))
//     Nummer des Kommunikationsobjekts
#define ParamLOG_fE2OtherKORel                       ((int16_t)knx.paramWord(LOG_ParamCalcIndex(LOG_fE2OtherKORel)))
// Falls Vorbelegung aus dem Speicher nicht möglich oder nicht gewünscht, dann vorbelegen mit
#define ParamLOG_fE2Default                          (PT_InputDefault)(knx.paramByte(LOG_ParamCalcIndex(LOG_fE2Default)) & LOG_fE2DefaultMask)
// Eingang vorbelegen mit
#define ParamLOG_fE2DefaultExt                       (PT_InputDefault)(knx.paramByte(LOG_ParamCalcIndex(LOG_fE2DefaultExt)) & LOG_fE2DefaultExtMask)
// Eingangswert speichern und beim nächsten Neustart als Vorbelegung nutzen?
#define ParamLOG_fE2DefaultEEPROM                    ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fE2DefaultEEPROM)) & LOG_fE2DefaultEEPROMMask))
// Nur so lange zyklisch lesen, bis erstes Telegramm eingeht
#define ParamLOG_fE2DefaultRepeat                    ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fE2DefaultRepeat)) & LOG_fE2DefaultRepeatMask))
// Kommunikationsobjekt für Eingang
#define ParamLOG_fE2UseOtherKO                       (PT_KORelInput)((knx.paramByte(LOG_ParamCalcIndex(LOG_fE2UseOtherKO)) & LOG_fE2UseOtherKOMask) >> LOG_fE2UseOtherKOShift)
// Von-Wert
#define ParamLOG_fE2LowDelta                         ((int32_t)knx.paramInt(LOG_ParamCalcIndex(LOG_fE2LowDelta)))
// Bis-Wert
#define ParamLOG_fE2HighDelta                        ((int32_t)knx.paramInt(LOG_ParamCalcIndex(LOG_fE2HighDelta)))
// Von-Wert
#define ParamLOG_fE2LowDeltaFloat                    (knx.paramFloat(LOG_ParamCalcIndex(LOG_fE2LowDeltaFloat), Float_Enc_IEEE754Single))
// Bis-Wert
#define ParamLOG_fE2HighDeltaFloat                   (knx.paramFloat(LOG_ParamCalcIndex(LOG_fE2HighDeltaFloat), Float_Enc_IEEE754Single))
// Von-Wert
#define ParamLOG_fE2LowDeltaDouble                   (knx.paramFloat(LOG_ParamCalcIndex(LOG_fE2LowDeltaDouble), Float_Enc_IEEE754Single))
// Bis-Wert
#define ParamLOG_fE2HighDeltaDouble                  (knx.paramFloat(LOG_ParamCalcIndex(LOG_fE2HighDeltaDouble), Float_Enc_IEEE754Single))
// Nächste Zeile auswerten?
#define ParamLOG_fE2Low0Valid                        ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fE2Low0Valid)) & LOG_fE2Low0ValidMask))
// Nächste Zeile auswerten?
#define ParamLOG_fE2Low1Valid                        ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fE2Low1Valid)) & LOG_fE2Low1ValidMask))
// Nächste Zeile auswerten?
#define ParamLOG_fE2Low2Valid                        ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fE2Low2Valid)) & LOG_fE2Low2ValidMask))
// Nächste Zeile auswerten?
#define ParamLOG_fE2Low3Valid                        ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fE2Low3Valid)) & LOG_fE2Low3ValidMask))
// Nächste Zeile auswerten?
#define ParamLOG_fE2Low4Valid                        ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fE2Low4Valid)) & LOG_fE2Low4ValidMask))
// Nächste Zeile auswerten?
#define ParamLOG_fE2Low5Valid                        ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fE2Low5Valid)) & LOG_fE2Low5ValidMask))
// Nächste Zeile auswerten?
#define ParamLOG_fE2Low6Valid                        ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fE2Low6Valid)) & LOG_fE2Low6ValidMask))
// Eingang ist EIN, wenn Wert gleich
#define ParamLOG_fE2Low0Dpt2                         (knx.paramByte(LOG_ParamCalcIndex(LOG_fE2Low0Dpt2)))
// ... oder wenn Wert gleich 
#define ParamLOG_fE2Low1Dpt2                         (knx.paramByte(LOG_ParamCalcIndex(LOG_fE2Low1Dpt2)))
// ... oder wenn Wert gleich 
#define ParamLOG_fE2Low2Dpt2                         (knx.paramByte(LOG_ParamCalcIndex(LOG_fE2Low2Dpt2)))
// ... oder wenn Wert gleich 
#define ParamLOG_fE2Low3Dpt2                         (knx.paramByte(LOG_ParamCalcIndex(LOG_fE2Low3Dpt2)))
// Eingang ist konstant
#define ParamLOG_fE2LowDpt2Fix                       (knx.paramByte(LOG_ParamCalcIndex(LOG_fE2LowDpt2Fix)))
// Eingang ist EIN, wenn Wert gleich
#define ParamLOG_fE2Low0Dpt3Dir                      ((knx.paramByte(LOG_ParamCalcIndex(LOG_fE2Low0Dpt3Dir)) & LOG_fE2Low0Dpt3DirMask) >> LOG_fE2Low0Dpt3DirShift)
// 
#define ParamLOG_fE2Low0Dpt3Dim                      (knx.paramByte(LOG_ParamCalcIndex(LOG_fE2Low0Dpt3Dim)) & LOG_fE2Low0Dpt3DimMask)
// ... oder wenn Wert gleich 
#define ParamLOG_fE2Low1Dpt3Dir                      ((knx.paramByte(LOG_ParamCalcIndex(LOG_fE2Low1Dpt3Dir)) & LOG_fE2Low1Dpt3DirMask) >> LOG_fE2Low1Dpt3DirShift)
// 
#define ParamLOG_fE2Low1Dpt3Dim                      (knx.paramByte(LOG_ParamCalcIndex(LOG_fE2Low1Dpt3Dim)) & LOG_fE2Low1Dpt3DimMask)
// ... oder wenn Wert gleich 
#define ParamLOG_fE2Low2Dpt3Dir                      ((knx.paramByte(LOG_ParamCalcIndex(LOG_fE2Low2Dpt3Dir)) & LOG_fE2Low2Dpt3DirMask) >> LOG_fE2Low2Dpt3DirShift)
// 
#define ParamLOG_fE2Low2Dpt3Dim                      (knx.paramByte(LOG_ParamCalcIndex(LOG_fE2Low2Dpt3Dim)) & LOG_fE2Low2Dpt3DimMask)
// ... oder wenn Wert gleich 
#define ParamLOG_fE2Low3Dpt3Dir                      ((knx.paramByte(LOG_ParamCalcIndex(LOG_fE2Low3Dpt3Dir)) & LOG_fE2Low3Dpt3DirMask) >> LOG_fE2Low3Dpt3DirShift)
// 
#define ParamLOG_fE2Low3Dpt3Dim                      (knx.paramByte(LOG_ParamCalcIndex(LOG_fE2Low3Dpt3Dim)) & LOG_fE2Low3Dpt3DimMask)
// Eingang ist konstant
#define ParamLOG_fE2LowDpt3FixDir                    ((knx.paramByte(LOG_ParamCalcIndex(LOG_fE2LowDpt3FixDir)) & LOG_fE2LowDpt3FixDirMask) >> LOG_fE2LowDpt3FixDirShift)
// 
#define ParamLOG_fE2LowDpt3FixDim                    (knx.paramByte(LOG_ParamCalcIndex(LOG_fE2LowDpt3FixDim)) & LOG_fE2LowDpt3FixDimMask)
// Von-Wert
#define ParamLOG_fE2LowDpt5                          (knx.paramByte(LOG_ParamCalcIndex(LOG_fE2LowDpt5)))
// Bis-Wert
#define ParamLOG_fE2HighDpt5                         (knx.paramByte(LOG_ParamCalcIndex(LOG_fE2HighDpt5)))
// Eingang ist EIN bei Wert
#define ParamLOG_fE2Low0Dpt5In                       (knx.paramByte(LOG_ParamCalcIndex(LOG_fE2Low0Dpt5In)))
// ... oder bei Wert
#define ParamLOG_fE2Low1Dpt5In                       (knx.paramByte(LOG_ParamCalcIndex(LOG_fE2Low1Dpt5In)))
// ... oder bei Wert
#define ParamLOG_fE2Low2Dpt5In                       (knx.paramByte(LOG_ParamCalcIndex(LOG_fE2Low2Dpt5In)))
// ... oder bei Wert
#define ParamLOG_fE2Low3Dpt5In                       (knx.paramByte(LOG_ParamCalcIndex(LOG_fE2Low3Dpt5In)))
// ... oder bei Wert
#define ParamLOG_fE2Low4Dpt5In                       (knx.paramByte(LOG_ParamCalcIndex(LOG_fE2Low4Dpt5In)))
// ... oder bei Wert
#define ParamLOG_fE2Low5Dpt5In                       (knx.paramByte(LOG_ParamCalcIndex(LOG_fE2Low5Dpt5In)))
// ... oder bei Wert
#define ParamLOG_fE2Low6Dpt5In                       (knx.paramByte(LOG_ParamCalcIndex(LOG_fE2Low6Dpt5In)))
// Eingang ist konstant
#define ParamLOG_fE2LowDpt5Fix                       (knx.paramByte(LOG_ParamCalcIndex(LOG_fE2LowDpt5Fix)))
// Von-Wert
#define ParamLOG_fE2LowDpt5001                       (knx.paramByte(LOG_ParamCalcIndex(LOG_fE2LowDpt5001)))
// Bis-Wert
#define ParamLOG_fE2HighDpt5001                      (knx.paramByte(LOG_ParamCalcIndex(LOG_fE2HighDpt5001)))
// Eingang ist EIN bei Wert
#define ParamLOG_fE2Low0Dpt5xIn                      (knx.paramByte(LOG_ParamCalcIndex(LOG_fE2Low0Dpt5xIn)))
// ... oder bei Wert
#define ParamLOG_fE2Low1Dpt5xIn                      (knx.paramByte(LOG_ParamCalcIndex(LOG_fE2Low1Dpt5xIn)))
// ... oder bei Wert
#define ParamLOG_fE2Low2Dpt5xIn                      (knx.paramByte(LOG_ParamCalcIndex(LOG_fE2Low2Dpt5xIn)))
// ... oder bei Wert
#define ParamLOG_fE2Low3Dpt5xIn                      (knx.paramByte(LOG_ParamCalcIndex(LOG_fE2Low3Dpt5xIn)))
// ... oder bei Wert
#define ParamLOG_fE2Low4Dpt5xIn                      (knx.paramByte(LOG_ParamCalcIndex(LOG_fE2Low4Dpt5xIn)))
// ... oder bei Wert
#define ParamLOG_fE2Low5Dpt5xIn                      (knx.paramByte(LOG_ParamCalcIndex(LOG_fE2Low5Dpt5xIn)))
// ... oder bei Wert
#define ParamLOG_fE2Low6Dpt5xIn                      (knx.paramByte(LOG_ParamCalcIndex(LOG_fE2Low6Dpt5xIn)))
// Eingang ist konstant
#define ParamLOG_fE2LowDpt5xFix                      (knx.paramByte(LOG_ParamCalcIndex(LOG_fE2LowDpt5xFix)))
// Von-Wert
#define ParamLOG_fE2LowDpt6                          ((int8_t)knx.paramByte(LOG_ParamCalcIndex(LOG_fE2LowDpt6)))
// Bis-Wert
#define ParamLOG_fE2HighDpt6                         ((int8_t)knx.paramByte(LOG_ParamCalcIndex(LOG_fE2HighDpt6)))
// Eingang ist EIN bei Wert
#define ParamLOG_fE2Low0Dpt6In                       ((int8_t)knx.paramByte(LOG_ParamCalcIndex(LOG_fE2Low0Dpt6In)))
// ... oder bei Wert
#define ParamLOG_fE2Low1Dpt6In                       ((int8_t)knx.paramByte(LOG_ParamCalcIndex(LOG_fE2Low1Dpt6In)))
// ... oder bei Wert
#define ParamLOG_fE2Low2Dpt6In                       ((int8_t)knx.paramByte(LOG_ParamCalcIndex(LOG_fE2Low2Dpt6In)))
// ... oder bei Wert
#define ParamLOG_fE2Low3Dpt6In                       ((int8_t)knx.paramByte(LOG_ParamCalcIndex(LOG_fE2Low3Dpt6In)))
// ... oder bei Wert
#define ParamLOG_fE2Low4Dpt6In                       ((int8_t)knx.paramByte(LOG_ParamCalcIndex(LOG_fE2Low4Dpt6In)))
// ... oder bei Wert
#define ParamLOG_fE2Low5Dpt6In                       ((int8_t)knx.paramByte(LOG_ParamCalcIndex(LOG_fE2Low5Dpt6In)))
// ... oder bei Wert
#define ParamLOG_fE2Low6Dpt6In                       ((int8_t)knx.paramByte(LOG_ParamCalcIndex(LOG_fE2Low6Dpt6In)))
// Eingang ist konstant
#define ParamLOG_fE2LowDpt6Fix                       ((int8_t)knx.paramByte(LOG_ParamCalcIndex(LOG_fE2LowDpt6Fix)))
// Von-Wert
#define ParamLOG_fE2LowDpt7                          (knx.paramWord(LOG_ParamCalcIndex(LOG_fE2LowDpt7)))
// Bis-Wert
#define ParamLOG_fE2HighDpt7                         (knx.paramWord(LOG_ParamCalcIndex(LOG_fE2HighDpt7)))
// Eingang ist EIN bei Wert
#define ParamLOG_fE2Low0Dpt7In                       (knx.paramWord(LOG_ParamCalcIndex(LOG_fE2Low0Dpt7In)))
// ... oder bei Wert
#define ParamLOG_fE2Low1Dpt7In                       (knx.paramWord(LOG_ParamCalcIndex(LOG_fE2Low1Dpt7In)))
// ... oder bei Wert
#define ParamLOG_fE2Low2Dpt7In                       (knx.paramWord(LOG_ParamCalcIndex(LOG_fE2Low2Dpt7In)))
// Eingang ist konstant
#define ParamLOG_fE2LowDpt7Fix                       (knx.paramWord(LOG_ParamCalcIndex(LOG_fE2LowDpt7Fix)))
// Von-Wert
#define ParamLOG_fE2LowDpt8                          ((int16_t)knx.paramWord(LOG_ParamCalcIndex(LOG_fE2LowDpt8)))
// Bis-Wert
#define ParamLOG_fE2HighDpt8                         ((int16_t)knx.paramWord(LOG_ParamCalcIndex(LOG_fE2HighDpt8)))
// Eingang ist EIN bei Wert
#define ParamLOG_fE2Low0Dpt8In                       ((int16_t)knx.paramWord(LOG_ParamCalcIndex(LOG_fE2Low0Dpt8In)))
// ... oder bei Wert
#define ParamLOG_fE2Low1Dpt8In                       ((int16_t)knx.paramWord(LOG_ParamCalcIndex(LOG_fE2Low1Dpt8In)))
// ... oder bei Wert
#define ParamLOG_fE2Low2Dpt8In                       ((int16_t)knx.paramWord(LOG_ParamCalcIndex(LOG_fE2Low2Dpt8In)))
// Eingang ist konstant
#define ParamLOG_fE2LowDpt8Fix                       ((int16_t)knx.paramWord(LOG_ParamCalcIndex(LOG_fE2LowDpt8Fix)))
// Von-Wert
#define ParamLOG_fE2LowDpt9                          (knx.paramFloat(LOG_ParamCalcIndex(LOG_fE2LowDpt9), Float_Enc_IEEE754Single))
// Bis-Wert
#define ParamLOG_fE2HighDpt9                         (knx.paramFloat(LOG_ParamCalcIndex(LOG_fE2HighDpt9), Float_Enc_IEEE754Single))
// Eingang ist konstant
#define ParamLOG_fE2LowDpt9Fix                       (knx.paramFloat(LOG_ParamCalcIndex(LOG_fE2LowDpt9Fix), Float_Enc_IEEE754Single))
// Von-Wert
#define ParamLOG_fE2LowDpt12                         (knx.paramInt(LOG_ParamCalcIndex(LOG_fE2LowDpt12)))
// Bis-Wert
#define ParamLOG_fE2HighDpt12                        (knx.paramInt(LOG_ParamCalcIndex(LOG_fE2HighDpt12)))
// Eingang ist konstant
#define ParamLOG_fE2LowDpt12Fix                      (knx.paramInt(LOG_ParamCalcIndex(LOG_fE2LowDpt12Fix)))
// Von-Wert
#define ParamLOG_fE2LowDpt13                         ((int32_t)knx.paramInt(LOG_ParamCalcIndex(LOG_fE2LowDpt13)))
// Bis-Wert
#define ParamLOG_fE2HighDpt13                        ((int32_t)knx.paramInt(LOG_ParamCalcIndex(LOG_fE2HighDpt13)))
// Eingang ist konstant
#define ParamLOG_fE2LowDpt13Fix                      ((int32_t)knx.paramInt(LOG_ParamCalcIndex(LOG_fE2LowDpt13Fix)))
// Von-Wert
#define ParamLOG_fE2LowDpt14                         (knx.paramFloat(LOG_ParamCalcIndex(LOG_fE2LowDpt14), Float_Enc_IEEE754Single))
// Bis-Wert
#define ParamLOG_fE2HighDpt14                        (knx.paramFloat(LOG_ParamCalcIndex(LOG_fE2HighDpt14), Float_Enc_IEEE754Single))
// Eingang ist konstant
#define ParamLOG_fE2LowDpt14Fix                      (knx.paramFloat(LOG_ParamCalcIndex(LOG_fE2LowDpt14Fix), Float_Enc_IEEE754Single))
// Eingang ist EIN bei Szene
#define ParamLOG_fE2Low0Dpt17                        (knx.paramByte(LOG_ParamCalcIndex(LOG_fE2Low0Dpt17)))
// ... oder bei Szene
#define ParamLOG_fE2Low1Dpt17                        (knx.paramByte(LOG_ParamCalcIndex(LOG_fE2Low1Dpt17)))
// ... oder bei Szene
#define ParamLOG_fE2Low2Dpt17                        (knx.paramByte(LOG_ParamCalcIndex(LOG_fE2Low2Dpt17)))
// ... oder bei Szene
#define ParamLOG_fE2Low3Dpt17                        (knx.paramByte(LOG_ParamCalcIndex(LOG_fE2Low3Dpt17)))
// ... oder bei Szene
#define ParamLOG_fE2Low4Dpt17                        (knx.paramByte(LOG_ParamCalcIndex(LOG_fE2Low4Dpt17)))
// ... oder bei Szene
#define ParamLOG_fE2Low5Dpt17                        (knx.paramByte(LOG_ParamCalcIndex(LOG_fE2Low5Dpt17)))
// ... oder bei Szene
#define ParamLOG_fE2Low6Dpt17                        (knx.paramByte(LOG_ParamCalcIndex(LOG_fE2Low6Dpt17)))
// ... oder bei Szene
#define ParamLOG_fE2Low7Dpt17                        (knx.paramByte(LOG_ParamCalcIndex(LOG_fE2Low7Dpt17)))
// Eingang ist konstant
#define ParamLOG_fE2LowDpt17Fix                      (knx.paramByte(LOG_ParamCalcIndex(LOG_fE2LowDpt17Fix)))
// Von-Wert
#define ParamLOG_fE2LowDptRGB                        ((int32_t)knx.paramInt(LOG_ParamCalcIndex(LOG_fE2LowDptRGB)))
// Bis-Wert
#define ParamLOG_fE2HighDptRGB                       ((int32_t)knx.paramInt(LOG_ParamCalcIndex(LOG_fE2HighDptRGB)))
// Eingang ist konstant
#define ParamLOG_fE2LowDptRGBFix                     ((int32_t)knx.paramInt(LOG_ParamCalcIndex(LOG_fE2LowDptRGBFix)))
// Zeitbezug
#define ParamLOG_fTd1DuskDawn                        (PT_DuskDawn)((knx.paramByte(LOG_ParamCalcIndex(LOG_fTd1DuskDawn)) & LOG_fTd1DuskDawnMask) >> LOG_fTd1DuskDawnShift)
// Zeitbezug
#define ParamLOG_fTd2DuskDawn                        (PT_DuskDawn)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTd2DuskDawn)) & LOG_fTd2DuskDawnMask)
// Zeitbezug
#define ParamLOG_fTd3DuskDawn                        (PT_DuskDawn)((knx.paramByte(LOG_ParamCalcIndex(LOG_fTd3DuskDawn)) & LOG_fTd3DuskDawnMask) >> LOG_fTd3DuskDawnShift)
// Zeitbezug
#define ParamLOG_fTd4DuskDawn                        (PT_DuskDawn)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTd4DuskDawn)) & LOG_fTd4DuskDawnMask)
// Zeitbezug
#define ParamLOG_fTd5DuskDawn                        (PT_DuskDawn)((knx.paramByte(LOG_ParamCalcIndex(LOG_fTd5DuskDawn)) & LOG_fTd5DuskDawnMask) >> LOG_fTd5DuskDawnShift)
// Zeitbezug
#define ParamLOG_fTd6DuskDawn                        (PT_DuskDawn)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTd6DuskDawn)) & LOG_fTd6DuskDawnMask)
// Zeitbezug
#define ParamLOG_fTd7DuskDawn                        (PT_DuskDawn)((knx.paramByte(LOG_ParamCalcIndex(LOG_fTd7DuskDawn)) & LOG_fTd7DuskDawnMask) >> LOG_fTd7DuskDawnShift)
// Zeitbezug
#define ParamLOG_fTd8DuskDawn                        (PT_DuskDawn)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTd8DuskDawn)) & LOG_fTd8DuskDawnMask)
// Typ der Zeitschaltuhr
#define ParamLOG_fTYearDay                           (PT_YearDay)((knx.paramByte(LOG_ParamCalcIndex(LOG_fTYearDay)) & LOG_fTYearDayMask) >> LOG_fTYearDayShift)
// Feiertagsbehandlung
#define ParamLOG_fTHoliday                           (PT_Holiday)((knx.paramByte(LOG_ParamCalcIndex(LOG_fTHoliday)) & LOG_fTHolidayMask) >> LOG_fTHolidayShift)
// Bei Neustart letzte Schaltzeit nachholen
#define ParamLOG_fTRestoreState                      ((knx.paramByte(LOG_ParamCalcIndex(LOG_fTRestoreState)) & LOG_fTRestoreStateMask) >> LOG_fTRestoreStateShift)
// Urlaubsbehandlung
#define ParamLOG_fTVacation                          (PT_Vacation)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTVacation)) & LOG_fTVacationMask)
// Zahlenwert
#define ParamLOG_fTd1ValueNum                        (knx.paramByte(LOG_ParamCalcIndex(LOG_fTd1ValueNum)))
// Zahlenwert
#define ParamLOG_fTd2ValueNum                        (knx.paramByte(LOG_ParamCalcIndex(LOG_fTd2ValueNum)))
// Zahlenwert
#define ParamLOG_fTd3ValueNum                        (knx.paramByte(LOG_ParamCalcIndex(LOG_fTd3ValueNum)))
// Zahlenwert
#define ParamLOG_fTd4ValueNum                        (knx.paramByte(LOG_ParamCalcIndex(LOG_fTd4ValueNum)))
// Zahlenwert
#define ParamLOG_fTd5ValueNum                        (knx.paramByte(LOG_ParamCalcIndex(LOG_fTd5ValueNum)))
// Zahlenwert
#define ParamLOG_fTd6ValueNum                        (knx.paramByte(LOG_ParamCalcIndex(LOG_fTd6ValueNum)))
// Zahlenwert
#define ParamLOG_fTd7ValueNum                        (knx.paramByte(LOG_ParamCalcIndex(LOG_fTd7ValueNum)))
// Zahlenwert
#define ParamLOG_fTd8ValueNum                        (knx.paramByte(LOG_ParamCalcIndex(LOG_fTd8ValueNum)))
// Schaltwert
#define ParamLOG_fTd1Value                           ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTd1Value)) & LOG_fTd1ValueMask))
// Grad
#define ParamLOG_fTd1Degree                          ((knx.paramByte(LOG_ParamCalcIndex(LOG_fTd1Degree)) & LOG_fTd1DegreeMask) >> LOG_fTd1DegreeShift)
// Stunde
#define ParamLOG_fTd1HourAbs                         ((knx.paramByte(LOG_ParamCalcIndex(LOG_fTd1HourAbs)) & LOG_fTd1HourAbsMask) >> LOG_fTd1HourAbsShift)
// Sonnen auf-/untergang
#define ParamLOG_fTd1HourRel                         ((knx.paramByte(LOG_ParamCalcIndex(LOG_fTd1HourRel)) & LOG_fTd1HourRelMask) >> LOG_fTd1HourRelShift)
// Sonnen auf-/untergang
#define ParamLOG_fTd1HourRelShort                    ((knx.paramByte(LOG_ParamCalcIndex(LOG_fTd1HourRelShort)) & LOG_fTd1HourRelShortMask) >> LOG_fTd1HourRelShortShift)
// Minute
#define ParamLOG_fTd1MinuteAbs                       (knx.paramByte(LOG_ParamCalcIndex(LOG_fTd1MinuteAbs)))
// Minute
#define ParamLOG_fTd1MinuteRel                       (knx.paramByte(LOG_ParamCalcIndex(LOG_fTd1MinuteRel)))
// Wochentag
#define ParamLOG_fTd1Weekday                         (knx.paramByte(LOG_ParamCalcIndex(LOG_fTd1Weekday)) & LOG_fTd1WeekdayMask)
// Schaltwert
#define ParamLOG_fTd2Value                           ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTd2Value)) & LOG_fTd2ValueMask))
// Grad
#define ParamLOG_fTd2Degree                          ((knx.paramByte(LOG_ParamCalcIndex(LOG_fTd2Degree)) & LOG_fTd2DegreeMask) >> LOG_fTd2DegreeShift)
// Stunde
#define ParamLOG_fTd2HourAbs                         ((knx.paramByte(LOG_ParamCalcIndex(LOG_fTd2HourAbs)) & LOG_fTd2HourAbsMask) >> LOG_fTd2HourAbsShift)
// Sonnen auf-/untergang
#define ParamLOG_fTd2HourRel                         ((knx.paramByte(LOG_ParamCalcIndex(LOG_fTd2HourRel)) & LOG_fTd2HourRelMask) >> LOG_fTd2HourRelShift)
// Sonnen auf-/untergang
#define ParamLOG_fTd2HourRelShort                    ((knx.paramByte(LOG_ParamCalcIndex(LOG_fTd2HourRelShort)) & LOG_fTd2HourRelShortMask) >> LOG_fTd2HourRelShortShift)
// Minute
#define ParamLOG_fTd2MinuteAbs                       (knx.paramByte(LOG_ParamCalcIndex(LOG_fTd2MinuteAbs)))
// Minute
#define ParamLOG_fTd2MinuteRel                       (knx.paramByte(LOG_ParamCalcIndex(LOG_fTd2MinuteRel)))
// Wochentag
#define ParamLOG_fTd2Weekday                         (knx.paramByte(LOG_ParamCalcIndex(LOG_fTd2Weekday)) & LOG_fTd2WeekdayMask)
// Schaltwert
#define ParamLOG_fTd3Value                           ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTd3Value)) & LOG_fTd3ValueMask))
// Grad
#define ParamLOG_fTd3Degree                          ((knx.paramByte(LOG_ParamCalcIndex(LOG_fTd3Degree)) & LOG_fTd3DegreeMask) >> LOG_fTd3DegreeShift)
// Stunde
#define ParamLOG_fTd3HourAbs                         ((knx.paramByte(LOG_ParamCalcIndex(LOG_fTd3HourAbs)) & LOG_fTd3HourAbsMask) >> LOG_fTd3HourAbsShift)
// Sonnen auf-/untergang
#define ParamLOG_fTd3HourRel                         ((knx.paramByte(LOG_ParamCalcIndex(LOG_fTd3HourRel)) & LOG_fTd3HourRelMask) >> LOG_fTd3HourRelShift)
// Sonnen auf-/untergang
#define ParamLOG_fTd3HourRelShort                    ((knx.paramByte(LOG_ParamCalcIndex(LOG_fTd3HourRelShort)) & LOG_fTd3HourRelShortMask) >> LOG_fTd3HourRelShortShift)
// Minute
#define ParamLOG_fTd3MinuteAbs                       (knx.paramByte(LOG_ParamCalcIndex(LOG_fTd3MinuteAbs)))
// Minute
#define ParamLOG_fTd3MinuteRel                       (knx.paramByte(LOG_ParamCalcIndex(LOG_fTd3MinuteRel)))
// Wochentag
#define ParamLOG_fTd3Weekday                         (knx.paramByte(LOG_ParamCalcIndex(LOG_fTd3Weekday)) & LOG_fTd3WeekdayMask)
// Schaltwert
#define ParamLOG_fTd4Value                           ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTd4Value)) & LOG_fTd4ValueMask))
// Grad
#define ParamLOG_fTd4Degree                          ((knx.paramByte(LOG_ParamCalcIndex(LOG_fTd4Degree)) & LOG_fTd4DegreeMask) >> LOG_fTd4DegreeShift)
// Stunde
#define ParamLOG_fTd4HourAbs                         ((knx.paramByte(LOG_ParamCalcIndex(LOG_fTd4HourAbs)) & LOG_fTd4HourAbsMask) >> LOG_fTd4HourAbsShift)
// Sonnen auf-/untergang
#define ParamLOG_fTd4HourRel                         ((knx.paramByte(LOG_ParamCalcIndex(LOG_fTd4HourRel)) & LOG_fTd4HourRelMask) >> LOG_fTd4HourRelShift)
// Sonnen auf-/untergang
#define ParamLOG_fTd4HourRelShort                    ((knx.paramByte(LOG_ParamCalcIndex(LOG_fTd4HourRelShort)) & LOG_fTd4HourRelShortMask) >> LOG_fTd4HourRelShortShift)
// Minute
#define ParamLOG_fTd4MinuteAbs                       (knx.paramByte(LOG_ParamCalcIndex(LOG_fTd4MinuteAbs)))
// Minute
#define ParamLOG_fTd4MinuteRel                       (knx.paramByte(LOG_ParamCalcIndex(LOG_fTd4MinuteRel)))
// Wochentag
#define ParamLOG_fTd4Weekday                         (knx.paramByte(LOG_ParamCalcIndex(LOG_fTd4Weekday)) & LOG_fTd4WeekdayMask)
// Schaltwert
#define ParamLOG_fTd5Value                           ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTd5Value)) & LOG_fTd5ValueMask))
// Grad
#define ParamLOG_fTd5Degree                          ((knx.paramByte(LOG_ParamCalcIndex(LOG_fTd5Degree)) & LOG_fTd5DegreeMask) >> LOG_fTd5DegreeShift)
// Stunde
#define ParamLOG_fTd5HourAbs                         ((knx.paramByte(LOG_ParamCalcIndex(LOG_fTd5HourAbs)) & LOG_fTd5HourAbsMask) >> LOG_fTd5HourAbsShift)
// Sonnen auf-/untergang
#define ParamLOG_fTd5HourRel                         ((knx.paramByte(LOG_ParamCalcIndex(LOG_fTd5HourRel)) & LOG_fTd5HourRelMask) >> LOG_fTd5HourRelShift)
// Sonnen auf-/untergang
#define ParamLOG_fTd5HourRelShort                    ((knx.paramByte(LOG_ParamCalcIndex(LOG_fTd5HourRelShort)) & LOG_fTd5HourRelShortMask) >> LOG_fTd5HourRelShortShift)
// Minute
#define ParamLOG_fTd5MinuteAbs                       (knx.paramByte(LOG_ParamCalcIndex(LOG_fTd5MinuteAbs)))
// Minute
#define ParamLOG_fTd5MinuteRel                       (knx.paramByte(LOG_ParamCalcIndex(LOG_fTd5MinuteRel)))
// Wochentag
#define ParamLOG_fTd5Weekday                         (knx.paramByte(LOG_ParamCalcIndex(LOG_fTd5Weekday)) & LOG_fTd5WeekdayMask)
// Schaltwert
#define ParamLOG_fTd6Value                           ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTd6Value)) & LOG_fTd6ValueMask))
// Grad
#define ParamLOG_fTd6Degree                          ((knx.paramByte(LOG_ParamCalcIndex(LOG_fTd6Degree)) & LOG_fTd6DegreeMask) >> LOG_fTd6DegreeShift)
// Stunde
#define ParamLOG_fTd6HourAbs                         ((knx.paramByte(LOG_ParamCalcIndex(LOG_fTd6HourAbs)) & LOG_fTd6HourAbsMask) >> LOG_fTd6HourAbsShift)
// Sonnen auf-/untergang
#define ParamLOG_fTd6HourRel                         ((knx.paramByte(LOG_ParamCalcIndex(LOG_fTd6HourRel)) & LOG_fTd6HourRelMask) >> LOG_fTd6HourRelShift)
// Sonnen auf-/untergang
#define ParamLOG_fTd6HourRelShort                    ((knx.paramByte(LOG_ParamCalcIndex(LOG_fTd6HourRelShort)) & LOG_fTd6HourRelShortMask) >> LOG_fTd6HourRelShortShift)
// Minute
#define ParamLOG_fTd6MinuteAbs                       (knx.paramByte(LOG_ParamCalcIndex(LOG_fTd6MinuteAbs)))
// Minute
#define ParamLOG_fTd6MinuteRel                       (knx.paramByte(LOG_ParamCalcIndex(LOG_fTd6MinuteRel)))
// Wochentag
#define ParamLOG_fTd6Weekday                         (knx.paramByte(LOG_ParamCalcIndex(LOG_fTd6Weekday)) & LOG_fTd6WeekdayMask)
// Schaltwert
#define ParamLOG_fTd7Value                           ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTd7Value)) & LOG_fTd7ValueMask))
// Grad
#define ParamLOG_fTd7Degree                          ((knx.paramByte(LOG_ParamCalcIndex(LOG_fTd7Degree)) & LOG_fTd7DegreeMask) >> LOG_fTd7DegreeShift)
// Stunde
#define ParamLOG_fTd7HourAbs                         ((knx.paramByte(LOG_ParamCalcIndex(LOG_fTd7HourAbs)) & LOG_fTd7HourAbsMask) >> LOG_fTd7HourAbsShift)
// Sonnen auf-/untergang
#define ParamLOG_fTd7HourRel                         ((knx.paramByte(LOG_ParamCalcIndex(LOG_fTd7HourRel)) & LOG_fTd7HourRelMask) >> LOG_fTd7HourRelShift)
// Sonnen auf-/untergang
#define ParamLOG_fTd7HourRelShort                    ((knx.paramByte(LOG_ParamCalcIndex(LOG_fTd7HourRelShort)) & LOG_fTd7HourRelShortMask) >> LOG_fTd7HourRelShortShift)
// Minute
#define ParamLOG_fTd7MinuteAbs                       (knx.paramByte(LOG_ParamCalcIndex(LOG_fTd7MinuteAbs)))
// Minute
#define ParamLOG_fTd7MinuteRel                       (knx.paramByte(LOG_ParamCalcIndex(LOG_fTd7MinuteRel)))
// Wochentag
#define ParamLOG_fTd7Weekday                         (knx.paramByte(LOG_ParamCalcIndex(LOG_fTd7Weekday)) & LOG_fTd7WeekdayMask)
// Schaltwert
#define ParamLOG_fTd8Value                           ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTd8Value)) & LOG_fTd8ValueMask))
// Grad
#define ParamLOG_fTd8Degree                          ((knx.paramByte(LOG_ParamCalcIndex(LOG_fTd8Degree)) & LOG_fTd8DegreeMask) >> LOG_fTd8DegreeShift)
// Stunde
#define ParamLOG_fTd8HourAbs                         ((knx.paramByte(LOG_ParamCalcIndex(LOG_fTd8HourAbs)) & LOG_fTd8HourAbsMask) >> LOG_fTd8HourAbsShift)
// Sonnen auf-/untergang
#define ParamLOG_fTd8HourRel                         ((knx.paramByte(LOG_ParamCalcIndex(LOG_fTd8HourRel)) & LOG_fTd8HourRelMask) >> LOG_fTd8HourRelShift)
// Sonnen auf-/untergang
#define ParamLOG_fTd8HourRelShort                    ((knx.paramByte(LOG_ParamCalcIndex(LOG_fTd8HourRelShort)) & LOG_fTd8HourRelShortMask) >> LOG_fTd8HourRelShortShift)
// Minute
#define ParamLOG_fTd8MinuteAbs                       (knx.paramByte(LOG_ParamCalcIndex(LOG_fTd8MinuteAbs)))
// Minute
#define ParamLOG_fTd8MinuteRel                       (knx.paramByte(LOG_ParamCalcIndex(LOG_fTd8MinuteRel)))
// Wochentag
#define ParamLOG_fTd8Weekday                         (knx.paramByte(LOG_ParamCalcIndex(LOG_fTd8Weekday)) & LOG_fTd8WeekdayMask)
// Mo
#define ParamLOG_fTy1Weekday1                        ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTy1Weekday1)) & LOG_fTy1Weekday1Mask))
// Di
#define ParamLOG_fTy1Weekday2                        ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTy1Weekday2)) & LOG_fTy1Weekday2Mask))
// Mi
#define ParamLOG_fTy1Weekday3                        ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTy1Weekday3)) & LOG_fTy1Weekday3Mask))
// Do
#define ParamLOG_fTy1Weekday4                        ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTy1Weekday4)) & LOG_fTy1Weekday4Mask))
// Fr
#define ParamLOG_fTy1Weekday5                        ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTy1Weekday5)) & LOG_fTy1Weekday5Mask))
// Sa
#define ParamLOG_fTy1Weekday6                        ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTy1Weekday6)) & LOG_fTy1Weekday6Mask))
// So
#define ParamLOG_fTy1Weekday7                        ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTy1Weekday7)) & LOG_fTy1Weekday7Mask))
// Tag
#define ParamLOG_fTy1Day                             ((knx.paramByte(LOG_ParamCalcIndex(LOG_fTy1Day)) & LOG_fTy1DayMask) >> LOG_fTy1DayShift)
// Wochentag
#define ParamLOG_fTy1IsWeekday                       ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTy1IsWeekday)) & LOG_fTy1IsWeekdayMask))
// Monat
#define ParamLOG_fTy1Month                           ((knx.paramByte(LOG_ParamCalcIndex(LOG_fTy1Month)) & LOG_fTy1MonthMask) >> LOG_fTy1MonthShift)
// Mo
#define ParamLOG_fTy2Weekday1                        ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTy2Weekday1)) & LOG_fTy2Weekday1Mask))
// Di
#define ParamLOG_fTy2Weekday2                        ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTy2Weekday2)) & LOG_fTy2Weekday2Mask))
// Mi
#define ParamLOG_fTy2Weekday3                        ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTy2Weekday3)) & LOG_fTy2Weekday3Mask))
// Do
#define ParamLOG_fTy2Weekday4                        ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTy2Weekday4)) & LOG_fTy2Weekday4Mask))
// Fr
#define ParamLOG_fTy2Weekday5                        ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTy2Weekday5)) & LOG_fTy2Weekday5Mask))
// Sa
#define ParamLOG_fTy2Weekday6                        ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTy2Weekday6)) & LOG_fTy2Weekday6Mask))
// So
#define ParamLOG_fTy2Weekday7                        ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTy2Weekday7)) & LOG_fTy2Weekday7Mask))
// Tag
#define ParamLOG_fTy2Day                             ((knx.paramByte(LOG_ParamCalcIndex(LOG_fTy2Day)) & LOG_fTy2DayMask) >> LOG_fTy2DayShift)
// Wochentag
#define ParamLOG_fTy2IsWeekday                       ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTy2IsWeekday)) & LOG_fTy2IsWeekdayMask))
// Monat
#define ParamLOG_fTy2Month                           ((knx.paramByte(LOG_ParamCalcIndex(LOG_fTy2Month)) & LOG_fTy2MonthMask) >> LOG_fTy2MonthShift)
// Mo
#define ParamLOG_fTy3Weekday1                        ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTy3Weekday1)) & LOG_fTy3Weekday1Mask))
// Di
#define ParamLOG_fTy3Weekday2                        ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTy3Weekday2)) & LOG_fTy3Weekday2Mask))
// Mi
#define ParamLOG_fTy3Weekday3                        ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTy3Weekday3)) & LOG_fTy3Weekday3Mask))
// Do
#define ParamLOG_fTy3Weekday4                        ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTy3Weekday4)) & LOG_fTy3Weekday4Mask))
// Fr
#define ParamLOG_fTy3Weekday5                        ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTy3Weekday5)) & LOG_fTy3Weekday5Mask))
// Sa
#define ParamLOG_fTy3Weekday6                        ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTy3Weekday6)) & LOG_fTy3Weekday6Mask))
// So
#define ParamLOG_fTy3Weekday7                        ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTy3Weekday7)) & LOG_fTy3Weekday7Mask))
// Tag
#define ParamLOG_fTy3Day                             ((knx.paramByte(LOG_ParamCalcIndex(LOG_fTy3Day)) & LOG_fTy3DayMask) >> LOG_fTy3DayShift)
// Wochentag
#define ParamLOG_fTy3IsWeekday                       ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTy3IsWeekday)) & LOG_fTy3IsWeekdayMask))
// Monat
#define ParamLOG_fTy3Month                           ((knx.paramByte(LOG_ParamCalcIndex(LOG_fTy3Month)) & LOG_fTy3MonthMask) >> LOG_fTy3MonthShift)
// Mo
#define ParamLOG_fTy4Weekday1                        ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTy4Weekday1)) & LOG_fTy4Weekday1Mask))
// Di
#define ParamLOG_fTy4Weekday2                        ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTy4Weekday2)) & LOG_fTy4Weekday2Mask))
// Mi
#define ParamLOG_fTy4Weekday3                        ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTy4Weekday3)) & LOG_fTy4Weekday3Mask))
// Do
#define ParamLOG_fTy4Weekday4                        ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTy4Weekday4)) & LOG_fTy4Weekday4Mask))
// Fr
#define ParamLOG_fTy4Weekday5                        ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTy4Weekday5)) & LOG_fTy4Weekday5Mask))
// Sa
#define ParamLOG_fTy4Weekday6                        ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTy4Weekday6)) & LOG_fTy4Weekday6Mask))
// So
#define ParamLOG_fTy4Weekday7                        ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTy4Weekday7)) & LOG_fTy4Weekday7Mask))
// Tag
#define ParamLOG_fTy4Day                             ((knx.paramByte(LOG_ParamCalcIndex(LOG_fTy4Day)) & LOG_fTy4DayMask) >> LOG_fTy4DayShift)
// Wochentag
#define ParamLOG_fTy4IsWeekday                       ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fTy4IsWeekday)) & LOG_fTy4IsWeekdayMask))
// Monat
#define ParamLOG_fTy4Month                           ((knx.paramByte(LOG_ParamCalcIndex(LOG_fTy4Month)) & LOG_fTy4MonthMask) >> LOG_fTy4MonthShift)
// Interner Eingang 3
#define ParamLOG_fI1                                 (PT_InputEnable)((knx.paramByte(LOG_ParamCalcIndex(LOG_fI1)) & LOG_fI1Mask) >> LOG_fI1Shift)
// Art der Verknüpfung
#define ParamLOG_fI1Kind                             (PT_KORelInput)((knx.paramByte(LOG_ParamCalcIndex(LOG_fI1Kind)) & LOG_fI1KindMask) >> LOG_fI1KindShift)
// Internen Eingang als Trigger nutzen(ist immer logisch EIN)
#define ParamLOG_fI1AsTrigger                        ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fI1AsTrigger)) & LOG_fI1AsTriggerMask))
// Interner Eingang wird versorgt vom
#define ParamLOG_fI1InternalInputType                (PT_InternalInputType)((knx.paramByte(LOG_ParamCalcIndex(LOG_fI1InternalInputType)) & LOG_fI1InternalInputTypeMask) >> LOG_fI1InternalInputTypeShift)
// Internen Eingang verbinden mit Kanal Nr.
#define ParamLOG_fI1Function                         (knx.paramByte(LOG_ParamCalcIndex(LOG_fI1Function)))
// Internen Eingang verbinden mit Kanal Nr.
#define ParamLOG_fI1FunctionRel                      ((int8_t)knx.paramByte(LOG_ParamCalcIndex(LOG_fI1FunctionRel)))
// Statuskanal
#define ParamLOG_fI1StatusLed                        (knx.paramWord(LOG_ParamCalcIndex(LOG_fI1StatusLed)))
// Interner Eingang 4
#define ParamLOG_fI2                                 (PT_InputEnable)((knx.paramByte(LOG_ParamCalcIndex(LOG_fI2)) & LOG_fI2Mask) >> LOG_fI2Shift)
// Art der Verknüpfung
#define ParamLOG_fI2Kind                             (PT_KORelInput)((knx.paramByte(LOG_ParamCalcIndex(LOG_fI2Kind)) & LOG_fI2KindMask) >> LOG_fI2KindShift)
// Internen Eingang als Trigger nutzen(ist immer logisch EIN)
#define ParamLOG_fI2AsTrigger                        ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fI2AsTrigger)) & LOG_fI2AsTriggerMask))
// Interner Eingang wird versorgt vom
#define ParamLOG_fI2InternalInputType                (PT_InternalInputType)((knx.paramByte(LOG_ParamCalcIndex(LOG_fI2InternalInputType)) & LOG_fI2InternalInputTypeMask) >> LOG_fI2InternalInputTypeShift)
// Internen Eingang verbinden mit Kanal Nr.
#define ParamLOG_fI2Function                         (knx.paramByte(LOG_ParamCalcIndex(LOG_fI2Function)))
// Internen Eingang verbinden mit Kanal Nr.
#define ParamLOG_fI2FunctionRel                      ((int8_t)knx.paramByte(LOG_ParamCalcIndex(LOG_fI2FunctionRel)))
// Statuskanal
#define ParamLOG_fI2StatusLed                        (knx.paramWord(LOG_ParamCalcIndex(LOG_fI2StatusLed)))
// Zeit für Treppenlicht
#define ParamLOG_fOStairtimeBase                     ((knx.paramByte(LOG_ParamCalcIndex(LOG_fOStairtimeBase)) & LOG_fOStairtimeBaseMask) >> LOG_fOStairtimeBaseShift)
// Zeit für Treppenlicht
#define ParamLOG_fOStairtimeTime                     (knx.paramWord(LOG_ParamCalcIndex(LOG_fOStairtimeTime)) & LOG_fOStairtimeTimeMask)
// Zeit für Treppenlicht (in Millisekunden)
#define ParamLOG_fOStairtimeTimeMS                   (paramDelay(knx.paramWord(LOG_ParamCalcIndex(LOG_fOStairtimeTime))))
// Treppenlicht blinkt im Rhythmus
#define ParamLOG_fOBlinkBase                         ((knx.paramByte(LOG_ParamCalcIndex(LOG_fOBlinkBase)) & LOG_fOBlinkBaseMask) >> LOG_fOBlinkBaseShift)
// Treppenlicht blinkt im Rhythmus
#define ParamLOG_fOBlinkTime                         (knx.paramWord(LOG_ParamCalcIndex(LOG_fOBlinkTime)) & LOG_fOBlinkTimeMask)
// Treppenlicht blinkt im Rhythmus (in Millisekunden)
#define ParamLOG_fOBlinkTimeMS                       (paramDelay(knx.paramWord(LOG_ParamCalcIndex(LOG_fOBlinkTime))))
// EINschalten wird verzögert um
#define ParamLOG_fODelayOnBase                       ((knx.paramByte(LOG_ParamCalcIndex(LOG_fODelayOnBase)) & LOG_fODelayOnBaseMask) >> LOG_fODelayOnBaseShift)
// EINschalten wird verzögert um
#define ParamLOG_fODelayOnTime                       (knx.paramWord(LOG_ParamCalcIndex(LOG_fODelayOnTime)) & LOG_fODelayOnTimeMask)
// EINschalten wird verzögert um (in Millisekunden)
#define ParamLOG_fODelayOnTimeMS                     (paramDelay(knx.paramWord(LOG_ParamCalcIndex(LOG_fODelayOnTime))))
// AUSschalten wird verzögert um
#define ParamLOG_fODelayOffBase                      ((knx.paramByte(LOG_ParamCalcIndex(LOG_fODelayOffBase)) & LOG_fODelayOffBaseMask) >> LOG_fODelayOffBaseShift)
// AUSschalten wird verzögert um
#define ParamLOG_fODelayOffTime                      (knx.paramWord(LOG_ParamCalcIndex(LOG_fODelayOffTime)) & LOG_fODelayOffTimeMask)
// AUSschalten wird verzögert um (in Millisekunden)
#define ParamLOG_fODelayOffTimeMS                    (paramDelay(knx.paramWord(LOG_ParamCalcIndex(LOG_fODelayOffTime))))
// EIN-Telegramm wird wiederholt alle
#define ParamLOG_fORepeatOnBase                      ((knx.paramByte(LOG_ParamCalcIndex(LOG_fORepeatOnBase)) & LOG_fORepeatOnBaseMask) >> LOG_fORepeatOnBaseShift)
// EIN-Telegramm wird wiederholt alle
#define ParamLOG_fORepeatOnTime                      (knx.paramWord(LOG_ParamCalcIndex(LOG_fORepeatOnTime)) & LOG_fORepeatOnTimeMask)
// EIN-Telegramm wird wiederholt alle (in Millisekunden)
#define ParamLOG_fORepeatOnTimeMS                    (paramDelay(knx.paramWord(LOG_ParamCalcIndex(LOG_fORepeatOnTime))))
// AUS-Telegramm wird wiederholt alle
#define ParamLOG_fORepeatOffBase                     ((knx.paramByte(LOG_ParamCalcIndex(LOG_fORepeatOffBase)) & LOG_fORepeatOffBaseMask) >> LOG_fORepeatOffBaseShift)
// AUS-Telegramm wird wiederholt alle
#define ParamLOG_fORepeatOffTime                     (knx.paramWord(LOG_ParamCalcIndex(LOG_fORepeatOffTime)) & LOG_fORepeatOffTimeMask)
// AUS-Telegramm wird wiederholt alle (in Millisekunden)
#define ParamLOG_fORepeatOffTimeMS                   (paramDelay(knx.paramWord(LOG_ParamCalcIndex(LOG_fORepeatOffTime))))
// Ausgang schaltet zeitverzögert
#define ParamLOG_fODelay                             ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fODelay)) & LOG_fODelayMask))
// Erneutes EIN führt zu
#define ParamLOG_fODelayOnRepeat                     (PT_OnOffRepeat)((knx.paramByte(LOG_ParamCalcIndex(LOG_fODelayOnRepeat)) & LOG_fODelayOnRepeatMask) >> LOG_fODelayOnRepeatShift)
// Darauffolgendes AUS führt zu
#define ParamLOG_fODelayOnReset                      (PT_OnOffReset)((knx.paramByte(LOG_ParamCalcIndex(LOG_fODelayOnReset)) & LOG_fODelayOnResetMask) >> LOG_fODelayOnResetShift)
// Erneutes AUS führt zu
#define ParamLOG_fODelayOffRepeat                    (PT_OnOffRepeat)((knx.paramByte(LOG_ParamCalcIndex(LOG_fODelayOffRepeat)) & LOG_fODelayOffRepeatMask) >> LOG_fODelayOffRepeatShift)
// Darauffolgendes EIN führt zu
#define ParamLOG_fODelayOffReset                     (PT_OnOffReset)((knx.paramByte(LOG_ParamCalcIndex(LOG_fODelayOffReset)) & LOG_fODelayOffResetMask) >> LOG_fODelayOffResetShift)
// Ausgang hat eine Treppenlichtfunktion
#define ParamLOG_fOStair                             ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fOStair)) & LOG_fOStairMask))
// Treppenlicht kann verlängert werden
#define ParamLOG_fORetrigger                         ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fORetrigger)) & LOG_fORetriggerMask))
// Treppenlicht kann ausgeschaltet werden
#define ParamLOG_fOStairOff                          ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fOStairOff)) & LOG_fOStairOffMask))
// Ausgang wiederholt zyklisch
#define ParamLOG_fORepeat                            ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fORepeat)) & LOG_fORepeatMask))
// Wiederholungsfilter
#define ParamLOG_fOOutputFilter                      (PT_OutputFilter)((knx.paramByte(LOG_ParamCalcIndex(LOG_fOOutputFilter)) & LOG_fOOutputFilterMask) >> LOG_fOOutputFilterShift)
// Sendeverhalten für Ausgang
#define ParamLOG_fOSendOnChange                      (PT_SendOnChange)((knx.paramByte(LOG_ParamCalcIndex(LOG_fOSendOnChange)) & LOG_fOSendOnChangeMask) >> LOG_fOSendOnChangeShift)
// Sperre aktivieren
#define ParamLOG_fOLockEnabled                       ((bool)(knx.paramByte(LOG_ParamCalcIndex(LOG_fOLockEnabled)) & LOG_fOLockEnabledMask))
// DPT für Ausgang
#define ParamLOG_fODpt                               (PT_LogicDpt)(knx.paramByte(LOG_ParamCalcIndex(LOG_fODpt)))
// Beim Sperren
#define ParamLOG_fOLockTriggerLock                   (PT_LockTrigger)((knx.paramByte(LOG_ParamCalcIndex(LOG_fOLockTriggerLock)) & LOG_fOLockTriggerLockMask) >> LOG_fOLockTriggerLockShift)
// Beim Entsperren
#define ParamLOG_fOLockTriggerUnlock                 (PT_LockTrigger)((knx.paramByte(LOG_ParamCalcIndex(LOG_fOLockTriggerUnlock)) & LOG_fOLockTriggerUnlockMask) >> LOG_fOLockTriggerUnlockShift)
// Anschließend die Signalverarbeitung
#define ParamLOG_fOLockResetQueue                    (PT_LockResetQueue)((knx.paramByte(LOG_ParamCalcIndex(LOG_fOLockResetQueue)) & LOG_fOLockResetQueueMask) >> LOG_fOLockResetQueueShift)
// Art der Verknüpfung
#define ParamLOG_fOLockKind                          (PT_KORelInput)(knx.paramByte(LOG_ParamCalcIndex(LOG_fOLockKind)) & LOG_fOLockKindMask)
// Sperre verbinden mit Kanal Nr.
#define ParamLOG_fOLockFunction                      (knx.paramByte(LOG_ParamCalcIndex(LOG_fOLockFunction)))
// Sperre verbinden mit Kanal Nr.
#define ParamLOG_fOLockFunctionRel                   ((int8_t)knx.paramByte(LOG_ParamCalcIndex(LOG_fOLockFunctionRel)))
// Wert für EIN senden?
#define ParamLOG_fOOnAll                             (PT_OutputSend)(knx.paramByte(LOG_ParamCalcIndex(LOG_fOOnAll)))
//     Wert für EIN senden als
#define ParamLOG_fOOnDpt1                            (knx.paramByte(LOG_ParamCalcIndex(LOG_fOOnDpt1)))
//     Wert für EIN senden als
#define ParamLOG_fOOnDpt2                            (knx.paramByte(LOG_ParamCalcIndex(LOG_fOOnDpt2)))
//     Wert für EIN senden als
#define ParamLOG_fOOnDpt3Dir                         ((knx.paramByte(LOG_ParamCalcIndex(LOG_fOOnDpt3Dir)) & LOG_fOOnDpt3DirMask) >> LOG_fOOnDpt3DirShift)
// 
#define ParamLOG_fOOnDpt3Dim                         (knx.paramByte(LOG_ParamCalcIndex(LOG_fOOnDpt3Dim)) & LOG_fOOnDpt3DimMask)
//     Wert für EIN senden als 
#define ParamLOG_fOOnDpt5                            (knx.paramByte(LOG_ParamCalcIndex(LOG_fOOnDpt5)))
//     Wert für EIN senden als
#define ParamLOG_fOOnDpt5001                         (knx.paramByte(LOG_ParamCalcIndex(LOG_fOOnDpt5001)))
//     Wert für EIN senden als
#define ParamLOG_fOOnDpt6                            ((int8_t)knx.paramByte(LOG_ParamCalcIndex(LOG_fOOnDpt6)))
//     Wert für EIN senden als
#define ParamLOG_fOOnDpt7                            (knx.paramWord(LOG_ParamCalcIndex(LOG_fOOnDpt7)))
//     Wert für EIN senden als
#define ParamLOG_fOOnDpt8                            ((int16_t)knx.paramWord(LOG_ParamCalcIndex(LOG_fOOnDpt8)))
//     Wert für EIN senden als
#define ParamLOG_fOOnDpt9                            (knx.paramFloat(LOG_ParamCalcIndex(LOG_fOOnDpt9), Float_Enc_IEEE754Single))
//     Wert für EIN senden als
#define ParamLOG_fOOnDpt12                           (knx.paramInt(LOG_ParamCalcIndex(LOG_fOOnDpt12)))
//     Wert für EIN senden als
#define ParamLOG_fOOnDpt13                           ((int32_t)knx.paramInt(LOG_ParamCalcIndex(LOG_fOOnDpt13)))
//     Wert für EIN senden als
#define ParamLOG_fOOnDpt14                           (knx.paramFloat(LOG_ParamCalcIndex(LOG_fOOnDpt14), Float_Enc_IEEE754Single))
//     Wert für EIN senden als 
#define ParamLOG_fOOnDpt16                           (knx.paramData(LOG_ParamCalcIndex(LOG_fOOnDpt16)))
#define ParamLOG_fOOnDpt16Str                        (knx.paramString(LOG_ParamCalcIndex(LOG_fOOnDpt16), LOG_fOOnDpt16Length))
//     Wert für EIN senden als 
#define ParamLOG_fOOnDpt17                           (knx.paramByte(LOG_ParamCalcIndex(LOG_fOOnDpt17)))
//     Wert für EIN senden als (3-Byte-RGB)
#define ParamLOG_fOOnRGB                             ((knx.paramInt(LOG_ParamCalcIndex(LOG_fOOnRGB)) & LOG_fOOnRGBMask) >> LOG_fOOnRGBShift)
//     Status-LED Kanal
#define ParamLOG_fOOnLedProvider                     (knx.paramByte(LOG_ParamCalcIndex(LOG_fOOnLedProvider)) & LOG_fOOnLedProviderMask)
//     Status-LED Effekt
#define ParamLOG_fOOnLedEffect                       (PT_StatusLedEffect)(knx.paramByte(LOG_ParamCalcIndex(LOG_fOOnLedEffect)) & LOG_fOOnLedEffectMask)
//     Status-LED Effektdauer
#define ParamLOG_fOOnLedDuration                     (knx.paramWord(LOG_ParamCalcIndex(LOG_fOOnLedDuration)))
// 
#define ParamLOG_fOOnPAArea                          ((knx.paramByte(LOG_ParamCalcIndex(LOG_fOOnPAArea)) & LOG_fOOnPAAreaMask) >> LOG_fOOnPAAreaShift)
// 
#define ParamLOG_fOOnPALine                          (knx.paramByte(LOG_ParamCalcIndex(LOG_fOOnPALine)) & LOG_fOOnPALineMask)
// 
#define ParamLOG_fOOnPADevice                        (knx.paramByte(LOG_ParamCalcIndex(LOG_fOOnPADevice)))
//     Wert für EIN ermitteln als
#define ParamLOG_fOOnFunction                        (knx.paramByte(LOG_ParamCalcIndex(LOG_fOOnFunction)))
//     Nummer des Kommunikationsobjekts
#define ParamLOG_fOOnKOKind                          (PT_KORelInput)((knx.paramByte(LOG_ParamCalcIndex(LOG_fOOnKOKind)) & LOG_fOOnKOKindMask) >> LOG_fOOnKOKindShift)
//     Nummer des Kommunikationsobjekts
#define ParamLOG_fOOnKONumber                        (knx.paramWord(LOG_ParamCalcIndex(LOG_fOOnKONumber)))
//     Nummer des Kommunikationsobjekts
#define ParamLOG_fOOnKONumberRel                     ((int16_t)knx.paramWord(LOG_ParamCalcIndex(LOG_fOOnKONumberRel)))
//     DPT des Kommunikationsobjekts
#define ParamLOG_fOOnKODpt                           (PT_LogicDpt)(knx.paramByte(LOG_ParamCalcIndex(LOG_fOOnKODpt)))
//     Wert für EIN an ein zusätzliches    KO senden?
#define ParamLOG_fOOnKOSend                          (PT_KORelInput)((knx.paramByte(LOG_ParamCalcIndex(LOG_fOOnKOSend)) & LOG_fOOnKOSendMask) >> LOG_fOOnKOSendShift)
//         Nummer des zusätzlichen KO
#define ParamLOG_fOOnKOSendNumber                    (knx.paramWord(LOG_ParamCalcIndex(LOG_fOOnKOSendNumber)))
//         Nummer des zusätzlichen KO
#define ParamLOG_fOOnKOSendNumberRel                 ((int16_t)knx.paramWord(LOG_ParamCalcIndex(LOG_fOOnKOSendNumberRel)))
// Wert für AUS senden?
#define ParamLOG_fOOffAll                            (PT_OutputSend)(knx.paramByte(LOG_ParamCalcIndex(LOG_fOOffAll)))
//     Wert für AUS senden als
#define ParamLOG_fOOffDpt1                           (knx.paramByte(LOG_ParamCalcIndex(LOG_fOOffDpt1)))
//     Wert für AUS senden als
#define ParamLOG_fOOffDpt2                           (knx.paramByte(LOG_ParamCalcIndex(LOG_fOOffDpt2)))
//     Wert für AUS senden als
#define ParamLOG_fOOffDpt3Dir                        ((knx.paramByte(LOG_ParamCalcIndex(LOG_fOOffDpt3Dir)) & LOG_fOOffDpt3DirMask) >> LOG_fOOffDpt3DirShift)
// 
#define ParamLOG_fOOffDpt3Dim                        (knx.paramByte(LOG_ParamCalcIndex(LOG_fOOffDpt3Dim)) & LOG_fOOffDpt3DimMask)
//     Wert für AUS senden als
#define ParamLOG_fOOffDpt5                           (knx.paramByte(LOG_ParamCalcIndex(LOG_fOOffDpt5)))
//     Wert für AUS senden als
#define ParamLOG_fOOffDpt5001                        (knx.paramByte(LOG_ParamCalcIndex(LOG_fOOffDpt5001)))
//     Wert für AUS senden als
#define ParamLOG_fOOffDpt6                           ((int8_t)knx.paramByte(LOG_ParamCalcIndex(LOG_fOOffDpt6)))
//     Wert für AUS senden als
#define ParamLOG_fOOffDpt7                           (knx.paramWord(LOG_ParamCalcIndex(LOG_fOOffDpt7)))
//     Wert für AUS senden als
#define ParamLOG_fOOffDpt8                           ((int16_t)knx.paramWord(LOG_ParamCalcIndex(LOG_fOOffDpt8)))
//     Wert für AUS senden als
#define ParamLOG_fOOffDpt9                           (knx.paramFloat(LOG_ParamCalcIndex(LOG_fOOffDpt9), Float_Enc_IEEE754Single))
//     Wert für AUS senden als
#define ParamLOG_fOOffDpt12                          (knx.paramInt(LOG_ParamCalcIndex(LOG_fOOffDpt12)))
//     Wert für AUS senden als
#define ParamLOG_fOOffDpt13                          ((int32_t)knx.paramInt(LOG_ParamCalcIndex(LOG_fOOffDpt13)))
//     Wert für AUS senden als
#define ParamLOG_fOOffDpt14                          (knx.paramFloat(LOG_ParamCalcIndex(LOG_fOOffDpt14), Float_Enc_IEEE754Single))
//     Wert für AUS senden als
#define ParamLOG_fOOffDpt16                          (knx.paramData(LOG_ParamCalcIndex(LOG_fOOffDpt16)))
#define ParamLOG_fOOffDpt16Str                       (knx.paramString(LOG_ParamCalcIndex(LOG_fOOffDpt16), LOG_fOOffDpt16Length))
//     Wert für AUS senden als 
#define ParamLOG_fOOffDpt17                          (knx.paramByte(LOG_ParamCalcIndex(LOG_fOOffDpt17)))
//     Wert für AUS senden als (3-Byte-RGB)
#define ParamLOG_fOOffRGB                            ((knx.paramInt(LOG_ParamCalcIndex(LOG_fOOffRGB)) & LOG_fOOffRGBMask) >> LOG_fOOffRGBShift)
//     Status-LED-Kanal
#define ParamLOG_fOOffLedProvider                    (knx.paramByte(LOG_ParamCalcIndex(LOG_fOOffLedProvider)) & LOG_fOOffLedProviderMask)
//     Status-LED Effekt
#define ParamLOG_fOOffLedEffect                      (PT_StatusLedEffect)(knx.paramByte(LOG_ParamCalcIndex(LOG_fOOffLedEffect)) & LOG_fOOffLedEffectMask)
//     Status-LED Effektdauer
#define ParamLOG_fOOffLedDuration                    (knx.paramWord(LOG_ParamCalcIndex(LOG_fOOffLedDuration)))
// 
#define ParamLOG_fOOffPAArea                         ((knx.paramByte(LOG_ParamCalcIndex(LOG_fOOffPAArea)) & LOG_fOOffPAAreaMask) >> LOG_fOOffPAAreaShift)
// 
#define ParamLOG_fOOffPALine                         (knx.paramByte(LOG_ParamCalcIndex(LOG_fOOffPALine)) & LOG_fOOffPALineMask)
// 
#define ParamLOG_fOOffPADevice                       (knx.paramByte(LOG_ParamCalcIndex(LOG_fOOffPADevice)))
//     Wert für AUS ermitteln als
#define ParamLOG_fOOffFunction                       (knx.paramByte(LOG_ParamCalcIndex(LOG_fOOffFunction)))
//     Nummer des Kommunikationsobjekts
#define ParamLOG_fOOffKOKind                         (PT_KORelInput)((knx.paramByte(LOG_ParamCalcIndex(LOG_fOOffKOKind)) & LOG_fOOffKOKindMask) >> LOG_fOOffKOKindShift)
//     Nummer des Kommunikationsobjekts
#define ParamLOG_fOOffKONumber                       (knx.paramWord(LOG_ParamCalcIndex(LOG_fOOffKONumber)))
//     Nummer des Kommunikationsobjekts
#define ParamLOG_fOOffKONumberRel                    ((int16_t)knx.paramWord(LOG_ParamCalcIndex(LOG_fOOffKONumberRel)))
//     DPT des Kommunikationsobjekts
#define ParamLOG_fOOffKODpt                          (PT_LogicDpt)(knx.paramByte(LOG_ParamCalcIndex(LOG_fOOffKODpt)))
//     Wert für AUS an ein zusätzliches    KO senden?
#define ParamLOG_fOOffKOSend                         (PT_KORelInput)((knx.paramByte(LOG_ParamCalcIndex(LOG_fOOffKOSend)) & LOG_fOOffKOSendMask) >> LOG_fOOffKOSendShift)
//         Nummer des zusätzlichen KO
#define ParamLOG_fOOffKOSendNumber                   (knx.paramWord(LOG_ParamCalcIndex(LOG_fOOffKOSendNumber)))
//         Nummer des zusätzlichen KO
#define ParamLOG_fOOffKOSendNumberRel                ((int16_t)knx.paramWord(LOG_ParamCalcIndex(LOG_fOOffKOSendNumberRel)))

// deprecated
#define LOG_KoOffset 50

// Communication objects per channel (multiple occurrence)
#define LOG_KoBlockOffset 50
#define LOG_KoBlockSize 3

#define LOG_KoCalcNumber(index) (index + LOG_KoBlockOffset + _channelIndex * LOG_KoBlockSize)
#define LOG_KoCalcIndex(number) ((number >= LOG_KoCalcNumber(0) && number < LOG_KoCalcNumber(LOG_KoBlockSize)) ? (number - LOG_KoBlockOffset) % LOG_KoBlockSize : -1)
#define LOG_KoCalcChannel(number) ((number >= LOG_KoBlockOffset && number < LOG_KoBlockOffset + LOG_ChannelCount * LOG_KoBlockSize) ? (number - LOG_KoBlockOffset) / LOG_KoBlockSize : -1)

#define LOG_KoKOfE1 0
#define LOG_KoKOfE2 1
#define LOG_KoKOfO 2

// Eingang 1
#define KoLOG_KOfE1                               (knx.getGroupObject(LOG_KoCalcNumber(LOG_KoKOfE1)))
// Eingang 2
#define KoLOG_KOfE2                               (knx.getGroupObject(LOG_KoCalcNumber(LOG_KoKOfE2)))
// Ausgang
#define KoLOG_KOfO                                (knx.getGroupObject(LOG_KoCalcNumber(LOG_KoKOfO)))



// Header generation for Module 'BASE_KommentarModule'

#define BASE_KommentarModuleCount 0
#define BASE_KommentarModuleModuleParamSize 0
#define BASE_KommentarModuleSubmodulesParamSize 0
#define BASE_KommentarModuleParamSize 0
#define BASE_KommentarModuleParamOffset 6010
#define BASE_KommentarModuleCalcIndex(index, m1) (index + BASE_KommentarModuleParamOffset + _channelIndex * BASE_KommentarModuleCount * BASE_KommentarModuleParamSize + m1 * BASE_KommentarModuleParamSize)




// enumeration types
enum class PT_CLIInit
{
    Saved = 0,
    ReadFromBus = 1,
    ReadFromBusOrSaved = 2
};

enum class PT_CLIHVAC
{
    Off = 6,
    Auto = 0,
    Heating = 1,
    Cooling = 3,
    Fan = 9,
    Dehumification = 14
};

enum class PT_CLIDefaultHVAC
{
    DependentOnSeason = 254,
    Off = 6,
    Auto = 0,
    Heating = 1,
    Cooling = 3,
    Fan = 9,
    Dehumification = 14
};

enum class PT_CLIModeChange
{
    Deactivated = 255,
    Off = 6,
    Auto = 0,
    Heating = 1,
    Cooling = 3,
    Fan = 9,
    Dehumification = 14
};

enum class PT_CLIHysteresis
{
    Hysteresis0_5 = 0,
    Hysteresis1_0 = 1,
    Hysteresis2_0 = 2
};

enum class PT_CLIControlMode
{
    HVAC = 0,
    HVAC_AND_POWER = 1,
    ONE_OBJECT_PER_MODE = 2
};

enum class PT_CLIControlTemperature
{
    TargetTemperature = 0,
    Setpoint = 1,
    PulseWidthModulation = 2,
    FakeSetTemperature = 3
};

enum class PT_CLIWaitTimeAfterPowerUp
{
    WaitTime1s = 0,
    WaitTime5s = 1,
    WaitTime10s = 2,
    WaitTime20s = 3,
    WaitTime30s = 4
};

enum class PT_CLIAverageTemperatureCalculation
{
    EveryHour = 0,
    MannheimHours = 1,
    MinMaxAverage = 2,
    GroupObjectDailyAverage = 3
};

enum class PT_CLIDeviceSelection
{
    Disabled = 0,
    CoolingHeatingSystem1 = 1,
    CoolingHeatingSystem2 = 2,
    CoolingHeatingSystem1And2 = 3
};

enum class PT_CLIDeviceSelectionFix
{
    CLI_DeviceName = 0,
    ExternalCoolingHeatingSystem = 1
};

enum class PT_CLIWindowOpenCondition
{
    Disabled = 0,
    IfHeating = 1,
    IfCooling = 2,
    IfHeatingOrCooling = 3,
    Always = 4
};

enum class PT_CLIWindowOpenAction
{
    SetpointAdjustment = 0,
    RevertSetpointAdjustment = 1,
    DisableHeatingCooling = 2,
    DisableHeatingCoolingOnlyInAuto = 3,
    EnableHeatingCooling = 4,
    DoNotForwardRoomTemperatureChange = 5,
    ForwardRoomTemperatureChange = 6,
    WindowOpenAlarm = 7,
    WindowOpenAlarmActiveHeatingCooling = 8
};

enum class PT_CLIWindowClose
{
    RoomTempStable = 0,
    WaitTime = 1
};

enum class PT_CLIPIPreset
{
    FloorHeating = 0,
    Radiator = 1,
    AirHeating = 2,
    Custom = 15
};

enum class PT_CLITargetLimitHandling
{
    MinMax = 0,
    Ignore = 1
};

enum class PT_CLIAutomaticDevice
{
    Disabled = 0,
    OpenKNXAutomatic = 1,
    RequestByGroupObject = 2
};

enum class PT_CLIIsActive
{
    Calculated = 0,
    FeedbackOnOff = 1,
    FeedbackPercent = 2
};

enum class PT_CLIBehaviorDeviceChange
{
    LeavesAutomaticModeTemp = 0,
    LeavesAutomaticMode = 1,
    OpenKNXOverridesSelection = 2
};

enum class PT_CLIModeFeedback
{
    ReturnLastActiveMode = 0,
    ReturnOff = 1
};

enum class PT_Logic
{
    AUS = 0,
    UND = 1,
    ODER = 2,
    EXOR = 3,
    TOR = 4,
    SCHALTER = 6,
    ZEITSCHALTUHR = 5
};

enum class PT_Calculate
{
    Invalid = 0,
    Valid = 1
};

enum class PT_GateTrigger
{
    None = 0,
    Off = 1,
    On = 2,
    Input = 3
};

enum class PT_LockTrigger
{
    None = 0,
    Off = 1,
    On = 2,
    Value = 3
};

enum class PT_LockResetQueue
{
    None = 0,
    ResetAfterLock = 1,
    ResetAfterUnlock = 2
};

enum class PT_InputEnable
{
    Inactive = 0,
    ActiveNormal = 1,
    ActiveInverted = 2
};

enum class PT_InputConv
{
    Wertintervall = 0,
    Differenzintervall = 1,
    Hysterese = 2,
    Differenzhysterese = 3,
    Einzelwerte = 4,
    Konstante = 5,
    Eingangswert = 6,
    Trigger = 7
};

enum class PT_LogicDpt
{
    DPT_1 = 0,
    DPT_2 = 1,
    DPT_3 = 17,
    DPT_5 = 2,
    DPT_5001 = 3,
    DPT_6 = 4,
    DPT_7 = 5,
    DPT_8 = 6,
    DPT_9 = 7,
    DPT_12 = 13,
    DPT_13 = 14,
    DPT_14 = 15,
    DPT_16 = 8,
    DPT_17 = 9,
    DPT_232 = 10
};

enum class PT_InputDefault
{
    None = 0,
    Bus = 1,
    Off = 2,
    On = 3
};

enum class PT_OnOffRepeat
{
    Verzoegerung_bleibt_bestehen = 0,
    Verzoegerung_wird_verlaengert = 1,
    Sofort_schalten_ohne_Verzoegerung = 2
};

enum class PT_OnOffReset
{
    Verzoegerung_bleibt_bestehen = 0,
    Verzoegerung_beenden_ohne_zu_schalten = 1
};

enum class PT_OutputFilter
{
    Alle_Wiederholungen_durchlassen = 0,
    Nur_EIN_Wiederholungen_durchlassen = 1,
    Nur_AUS_Wiederholungen_durchlassen = 2,
    Keine_Wiederholungen_durchlassen = 3
};

enum class PT_SendOnChange
{
    Alle_Werte_senden = 0,
    Nur_geaenderte_Werte_senden = 1
};

enum class PT_OutputSend
{
    None = 0,
    Constant = 1,
    ValueInput1 = 2,
    ValueInput2 = 3,
    OtherKo = 9,
    Function = 8,
    ReadRequest = 4,
    RestartDevice = 5,
    StatusLed = 7
};

enum class PT_YearDay
{
    Tagesschaltuhr = 0,
    Jahresschaltuhr = 1,
    Tagesschaltuhr_verbunden = 2,
    Jahresschaltuhr_verbunden = 3
};

enum class PT_Holiday
{
    Feiertage_nicht_beachten = 0,
    An_Feiertagen_nicht_schalten = 1,
    Nur_an_Feiertagen_schalten = 2,
    Feiertage_wie_Sonntage_behandeln = 3
};

enum class PT_Vacation
{
    Urlaub_nicht_beachten = 0,
    Bei_Urlaub_nicht_schalten = 1,
    Nur_bei_Urlaub_schalten = 2,
    Urlaub_wie_Sonntag_behandeln = 3
};

enum class PT_DuskDawn
{
    Inactive = 0,
    PointInTime = 1,
    Sunrise_Plus = 4,
    Sunrise_Minus = 5,
    Sunrise_Earliest = 6,
    Sunrise_Latest = 7,
    Sunrise_DegreeUp = 12,
    Sunrise_DegreeDown = 14,
    Sunset_Plus = 8,
    Sunset_Minus = 9,
    Sunset_Earliest = 10,
    Sunset_Latest = 11,
    Sunset_DegreeUp = 13,
    Sunset_DegreeDown = 15
};

enum class PT_KORelInput
{
    None = 0,
    Absolute = 1,
    Relative = 2,
    Bitmask = 3
};

enum class PT_StatusLedEffect
{
    Aus = 0,
    Ein = 1,
    Blinken = 2,
    Pulsieren = 3,
    Aufblitzen = 4
};

enum class PT_InternalInputType
{
    Anderen_Logikkanal = 0,
    Statuskanal = 1
};



#ifdef MAIN_FirmwareRevision
#ifndef FIRMWARE_REVISION
#define FIRMWARE_REVISION MAIN_FirmwareRevision
#endif
#endif
#ifdef MAIN_FirmwareName
#ifndef FIRMWARE_NAME
#define FIRMWARE_NAME MAIN_FirmwareName
#endif
#endif
