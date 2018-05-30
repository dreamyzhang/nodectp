//*******************************************************************************
//  *Copyright(C),2018, invesmart.cn                                             
//  *FileName:  WrapTd.h                                                       
//  *Author: 	dreamyzhang                                                      
//  *Version:   v2.1                                                             
//  *Date:  	2018-05-30                                                       
//  *Description:  invoked by js                                                 
//*******************************************************************************

#ifndef __WRAPTD_H__
#define __WRAPTD_H__

//#include <sys/socket.h>
//#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <string>
#include <math.h>
//#include <pthread.h>
#include <map>
#include <node.h>
#include <node_object_wrap.h>

#include <set>

#include "comm.h"

#include "ThostFtdcTraderSpiI.h"
#include "ctp_node.h"


using namespace std;

namespace td
{
    class WrapTd : public CThostFtdcTraderSpiI, public node::ObjectWrap
    {
        public:
            WrapTd();
            virtual ~WrapTd();

            static void On(const v8::FunctionCallbackInfo<v8::Value>& args);
            static void NewInstance(const v8::FunctionCallbackInfo<v8::Value>& args);
            static void Init(v8::Isolate* isolate);

            ///////////////////////////////����������start//////////////////////////////////////////////////
            //���������Զ������ʽ
            static void GetApiVersion(const v8::FunctionCallbackInfo<v8::Value>& args);
            static void Init(const v8::FunctionCallbackInfo<v8::Value>& args);
            static void Release(const v8::FunctionCallbackInfo<v8::Value>& args);
            static void CreateFtdcTraderApi(const v8::FunctionCallbackInfo<v8::Value>& args);
            static void GetTradingDay(const v8::FunctionCallbackInfo<v8::Value>& args);
            static void RegisterFront(const v8::FunctionCallbackInfo<v8::Value>& args);
            static void RegisterNameServer(const v8::FunctionCallbackInfo<v8::Value>& args);
            static void RegisterFensUserInfo(const v8::FunctionCallbackInfo<v8::Value>& args);
            static void SubscribePrivateTopic(const v8::FunctionCallbackInfo<v8::Value>& args);
            static void SubscribePublicTopic(const v8::FunctionCallbackInfo<v8::Value>& args);
            static void ReqAuthenticate(const v8::FunctionCallbackInfo<v8::Value>& args);
            static void ReqUserLogin(const v8::FunctionCallbackInfo<v8::Value>& args);
            static void ReqUserLogout(const v8::FunctionCallbackInfo<v8::Value>& args);
            static void ReqUserPasswordUpdate(const v8::FunctionCallbackInfo<v8::Value>& args);
            static void ReqTradingAccountPasswordUpdate(const v8::FunctionCallbackInfo<v8::Value>& args);
            static void ReqOrderAction(const v8::FunctionCallbackInfo<v8::Value>& args);
            static void ReqOrderInsert(const v8::FunctionCallbackInfo<v8::Value>& args);
            static void ReqSettlementInfoConfirm(const v8::FunctionCallbackInfo<v8::Value>& args);
            static void ReqQryProduct(const v8::FunctionCallbackInfo<v8::Value>& args);
            static void ReqQryInstrument(const v8::FunctionCallbackInfo<v8::Value>& args);
            static void ReqQryInvestorPositionDetail(const v8::FunctionCallbackInfo<v8::Value>& args);
            static void ReqQryOrder(const v8::FunctionCallbackInfo<v8::Value>& args);
            static void ReqQryTrade(const v8::FunctionCallbackInfo<v8::Value>& args);
            static void ReqQryInvestorPosition(const v8::FunctionCallbackInfo<v8::Value>& args);
            static void ReqQryTradingAccount(const v8::FunctionCallbackInfo<v8::Value>& args);
            static void ReqParkedOrderInsert(const v8::FunctionCallbackInfo<v8::Value>& args);
            static void ReqParkedOrderAction(const v8::FunctionCallbackInfo<v8::Value>& args);
            static void ReqQueryMaxOrderVolume(const v8::FunctionCallbackInfo<v8::Value>& args);
            static void ReqRemoveParkedOrder(const v8::FunctionCallbackInfo<v8::Value>& args);
            static void ReqRemoveParkedOrderAction(const v8::FunctionCallbackInfo<v8::Value>& args);
            static void ReqExecOrderInsert(const v8::FunctionCallbackInfo<v8::Value>& args);
            static void ReqExecOrderAction(const v8::FunctionCallbackInfo<v8::Value>& args);
            static void ReqForQuoteInsert(const v8::FunctionCallbackInfo<v8::Value>& args);
            static void ReqQuoteInsert(const v8::FunctionCallbackInfo<v8::Value>& args);
            static void ReqQuoteAction(const v8::FunctionCallbackInfo<v8::Value>& args);
            static void ReqBatchOrderAction(const v8::FunctionCallbackInfo<v8::Value>& args);
            static void ReqCombActionInsert(const v8::FunctionCallbackInfo<v8::Value>& args);

            //TODO
            static void ReqQryInvestor(const v8::FunctionCallbackInfo<v8::Value>& args);
            static void ReqQryTradingCode(const v8::FunctionCallbackInfo<v8::Value>& args);
            static void ReqQryInstrumentMarginRate(const v8::FunctionCallbackInfo<v8::Value>& args);
            static void ReqQryInstrumentCommissionRate(const v8::FunctionCallbackInfo<v8::Value>& args);
            static void ReqQryExchange(const v8::FunctionCallbackInfo<v8::Value>& args);
            static void ReqQryDepthMarketData(const v8::FunctionCallbackInfo<v8::Value>& args);
            static void ReqQrySettlementInfo(const v8::FunctionCallbackInfo<v8::Value>& args);
            static void ReqQryTransferBank(const v8::FunctionCallbackInfo<v8::Value>& args);
            static void ReqQryNotice(const v8::FunctionCallbackInfo<v8::Value>& args);
            static void ReqQrySettlementInfoConfirm(const v8::FunctionCallbackInfo<v8::Value>& args);
            static void ReqQryInvestorPositionCombineDetail(const v8::FunctionCallbackInfo<v8::Value>& args);
            static void ReqQryCFMMCTradingAccountKey(const v8::FunctionCallbackInfo<v8::Value>& args);
            static void ReqQryEWarrantOffset(const v8::FunctionCallbackInfo<v8::Value>& args);
            static void ReqQryInvestorProductGroupMargin(const v8::FunctionCallbackInfo<v8::Value>& args);
            static void ReqQryExchangeMarginRate(const v8::FunctionCallbackInfo<v8::Value>& args);
            static void ReqQryExchangeMarginRateAdjust(const v8::FunctionCallbackInfo<v8::Value>& args);
            static void ReqQryExchangeRate(const v8::FunctionCallbackInfo<v8::Value>& args);
            static void ReqQrySecAgentACIDMap(const v8::FunctionCallbackInfo<v8::Value>& args);
            static void ReqQryProductExchRate(const v8::FunctionCallbackInfo<v8::Value>& args);
            static void ReqQryProductGroup(const v8::FunctionCallbackInfo<v8::Value>& args);
            static void ReqQryMMInstrumentCommissionRate(const v8::FunctionCallbackInfo<v8::Value>& args);
            static void ReqQryMMOptionInstrCommRate(const v8::FunctionCallbackInfo<v8::Value>& args);
            static void ReqQryInstrumentOrderCommRate(const v8::FunctionCallbackInfo<v8::Value>& args);
            static void ReqQryOptionInstrTradeCost(const v8::FunctionCallbackInfo<v8::Value>& args);
            static void ReqQryOptionInstrCommRate(const v8::FunctionCallbackInfo<v8::Value>& args);
            static void ReqQryExecOrder(const v8::FunctionCallbackInfo<v8::Value>& args);
            static void ReqQryForQuote(const v8::FunctionCallbackInfo<v8::Value>& args);
            static void ReqQryQuote(const v8::FunctionCallbackInfo<v8::Value>& args);
            static void ReqQryCombInstrumentGuard(const v8::FunctionCallbackInfo<v8::Value>& args);
            static void ReqQryCombAction(const v8::FunctionCallbackInfo<v8::Value>& args);
            static void ReqQryTransferSerial(const v8::FunctionCallbackInfo<v8::Value>& args);
            static void ReqQryAccountregister(const v8::FunctionCallbackInfo<v8::Value>& args);
            static void ReqQryContractBank(const v8::FunctionCallbackInfo<v8::Value>& args);
            static void ReqQryParkedOrder(const v8::FunctionCallbackInfo<v8::Value>& args);
            static void ReqQryParkedOrderAction(const v8::FunctionCallbackInfo<v8::Value>& args);
            static void ReqQryTradingNotice(const v8::FunctionCallbackInfo<v8::Value>& args);
            static void ReqQryBrokerTradingParams(const v8::FunctionCallbackInfo<v8::Value>& args);
            static void ReqQryBrokerTradingAlgos(const v8::FunctionCallbackInfo<v8::Value>& args);
            static void ReqQueryCFMMCTradingAccountToken(const v8::FunctionCallbackInfo<v8::Value>& args);
            static void ReqFromBankToFutureByFuture(const v8::FunctionCallbackInfo<v8::Value>& args);
            static void ReqFromFutureToBankByFuture(const v8::FunctionCallbackInfo<v8::Value>& args);
            static void ReqQueryBankAccountMoneyByFuture(const v8::FunctionCallbackInfo<v8::Value>& args);

            /////////////////////////////����������end/////////////////////////////////////////////////////



            /////////////////////////ctp�̻߳ص�������///////////////////////////////////////////////////
            ///���ͻ����뽻�׺�̨������ͨ������ʱ����δ��¼ǰ�����÷��������á�
            virtual void MainOnFrontConnected();

            ///���ͻ����뽻�׺�̨ͨ�����ӶϿ�ʱ���÷��������á���������������API���Զ��������ӣ��ͻ��˿ɲ�������
            ///@param nReason ����ԭ��
            ///        0x1001 �����ʧ��
            ///        0x1002 ����дʧ��
            ///        0x2001 ����������ʱ
            ///        0x2002 ��������ʧ��
            ///        0x2003 �յ�������
            virtual void MainOnFrontDisconnected(int nReason);

            ///������ʱ���档����ʱ��δ�յ�����ʱ���÷��������á�
            ///@param nTimeLapse �����ϴν��ձ��ĵ�ʱ��
            virtual void MainOnHeartBeatWarning(int nTimeLapse);

            ///�ͻ�����֤��Ӧ
            virtual void MainOnRspAuthenticate(CThostFtdcRspAuthenticateField *pRspAuthenticateField, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

            ///��¼������Ӧ
            virtual void MainOnRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

            ///�ǳ�������Ӧ
            virtual void MainOnRspUserLogout(CThostFtdcUserLogoutField *pUserLogout, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

            ///�û��������������Ӧ
            virtual void MainOnRspUserPasswordUpdate(CThostFtdcUserPasswordUpdateField *pUserPasswordUpdate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

            ///�ʽ��˻��������������Ӧ
            virtual void MainOnRspTradingAccountPasswordUpdate(CThostFtdcTradingAccountPasswordUpdateField *pTradingAccountPasswordUpdate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

            ///����¼��������Ӧ
            virtual void MainOnRspOrderInsert(CThostFtdcInputOrderField *pInputOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

            ///Ԥ��¼��������Ӧ
            virtual void MainOnRspParkedOrderInsert(CThostFtdcParkedOrderField *pParkedOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

            ///Ԥ�񳷵�¼��������Ӧ
            virtual void MainOnRspParkedOrderAction(CThostFtdcParkedOrderActionField *pParkedOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

            ///��������������Ӧ
            virtual void MainOnRspOrderAction(CThostFtdcInputOrderActionField *pInputOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

            ///��ѯ��󱨵�������Ӧ
            virtual void MainOnRspQueryMaxOrderVolume(CThostFtdcQueryMaxOrderVolumeField *pQueryMaxOrderVolume, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

            ///Ͷ���߽�����ȷ����Ӧ
            virtual void MainOnRspSettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField *pSettlementInfoConfirm, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

            ///ɾ��Ԥ����Ӧ
            virtual void MainOnRspRemoveParkedOrder(CThostFtdcRemoveParkedOrderField *pRemoveParkedOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

            ///ɾ��Ԥ�񳷵���Ӧ
            virtual void MainOnRspRemoveParkedOrderAction(CThostFtdcRemoveParkedOrderActionField *pRemoveParkedOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

            ///ִ������¼��������Ӧ
            virtual void MainOnRspExecOrderInsert(CThostFtdcInputExecOrderField *pInputExecOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

            ///ִ���������������Ӧ
            virtual void MainOnRspExecOrderAction(CThostFtdcInputExecOrderActionField *pInputExecOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

            ///ѯ��¼��������Ӧ
            virtual void MainOnRspForQuoteInsert(CThostFtdcInputForQuoteField *pInputForQuote, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

            ///����¼��������Ӧ
            virtual void MainOnRspQuoteInsert(CThostFtdcInputQuoteField *pInputQuote, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

            ///���۲���������Ӧ
            virtual void MainOnRspQuoteAction(CThostFtdcInputQuoteActionField *pInputQuoteAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

            ///������������������Ӧ
            virtual void MainOnRspBatchOrderAction(CThostFtdcInputBatchOrderActionField *pInputBatchOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
            ///�����ѯ��Ʒ��
            virtual void MainOnRspQryProductGroup(CThostFtdcProductGroupField *pProductGroup, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
            ///�����ѯ�����̺�Լ����������Ӧ
            virtual void MainOnRspQryMMInstrumentCommissionRate(CThostFtdcMMInstrumentCommissionRateField *pMMInstrumentCommissionRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
            ///�����ѯ��������Ȩ��Լ��������Ӧ
            virtual void MainOnRspQryMMOptionInstrCommRate(CThostFtdcMMOptionInstrCommRateField *pMMOptionInstrCommRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
            ///�����ѯ������������Ӧ
            virtual void MainOnRspQryInstrumentOrderCommRate(CThostFtdcInstrumentOrderCommRateField *pInstrumentOrderCommRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
            ///����������֪ͨ
            virtual void MainOnRtnBulletin(CThostFtdcBulletinField *pBulletin);
            ///����������������ر�
            virtual void MainOnErrRtnBatchOrderAction(CThostFtdcBatchOrderActionField *pBatchOrderAction, CThostFtdcRspInfoField *pRspInfo);
            ///�������¼��������Ӧ
            virtual void MainOnRspCombActionInsert(CThostFtdcInputCombActionField *pInputCombAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

            ///�����ѯ������Ӧ
            virtual void MainOnRspQryOrder(CThostFtdcOrderField *pOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

            ///�����ѯ�ɽ���Ӧ
            virtual void MainOnRspQryTrade(CThostFtdcTradeField *pTrade, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

            ///�����ѯͶ���ֲ߳���Ӧ
            virtual void MainOnRspQryInvestorPosition(CThostFtdcInvestorPositionField *pInvestorPosition, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

            ///�����ѯ�ʽ��˻���Ӧ
            virtual void MainOnRspQryTradingAccount(CThostFtdcTradingAccountField *pTradingAccount, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

            ///�����ѯͶ������Ӧ
            virtual void MainOnRspQryInvestor(CThostFtdcInvestorField *pInvestor, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

            ///�����ѯ���ױ�����Ӧ
            virtual void MainOnRspQryTradingCode(CThostFtdcTradingCodeField *pTradingCode, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

            ///�����ѯ��Լ��֤������Ӧ
            virtual void MainOnRspQryInstrumentMarginRate(CThostFtdcInstrumentMarginRateField *pInstrumentMarginRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

            ///�����ѯ��Լ����������Ӧ
            virtual void MainOnRspQryInstrumentCommissionRate(CThostFtdcInstrumentCommissionRateField *pInstrumentCommissionRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

            ///�����ѯ��������Ӧ
            virtual void MainOnRspQryExchange(CThostFtdcExchangeField *pExchange, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

            ///�����ѯ��Ʒ��Ӧ
            virtual void MainOnRspQryProduct(CThostFtdcProductField *pProduct, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

            ///�����ѯ��Լ��Ӧ
            virtual void MainOnRspQryInstrument(CThostFtdcInstrumentField *pInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

            ///�����ѯ������Ӧ
            virtual void MainOnRspQryDepthMarketData(CThostFtdcDepthMarketDataField *pDepthMarketData, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

            ///�����ѯͶ���߽�������Ӧ
            virtual void MainOnRspQrySettlementInfo(CThostFtdcSettlementInfoField *pSettlementInfo, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

            ///�����ѯת��������Ӧ
            virtual void MainOnRspQryTransferBank(CThostFtdcTransferBankField *pTransferBank, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

            ///�����ѯͶ���ֲ߳���ϸ��Ӧ
            virtual void MainOnRspQryInvestorPositionDetail(CThostFtdcInvestorPositionDetailField *pInvestorPositionDetail, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

            ///�����ѯ�ͻ�֪ͨ��Ӧ
            virtual void MainOnRspQryNotice(CThostFtdcNoticeField *pNotice, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

            ///�����ѯ������Ϣȷ����Ӧ
            virtual void MainOnRspQrySettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField *pSettlementInfoConfirm, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

            ///�����ѯͶ���ֲ߳���ϸ��Ӧ
            virtual void MainOnRspQryInvestorPositionCombineDetail(CThostFtdcInvestorPositionCombineDetailField *pInvestorPositionCombineDetail, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

            ///��ѯ��֤����ϵͳ���͹�˾�ʽ��˻���Կ��Ӧ
            virtual void MainOnRspQryCFMMCTradingAccountKey(CThostFtdcCFMMCTradingAccountKeyField *pCFMMCTradingAccountKey, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

            ///�����ѯ�ֵ��۵���Ϣ��Ӧ
            virtual void MainOnRspQryEWarrantOffset(CThostFtdcEWarrantOffsetField *pEWarrantOffset, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

            ///�����ѯͶ����Ʒ��/��Ʒ�ֱ�֤����Ӧ
            virtual void MainOnRspQryInvestorProductGroupMargin(CThostFtdcInvestorProductGroupMarginField *pInvestorProductGroupMargin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

            ///�����ѯ��������֤������Ӧ
            virtual void MainOnRspQryExchangeMarginRate(CThostFtdcExchangeMarginRateField *pExchangeMarginRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

            ///�����ѯ������������֤������Ӧ
            virtual void MainOnRspQryExchangeMarginRateAdjust(CThostFtdcExchangeMarginRateAdjustField *pExchangeMarginRateAdjust, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

            ///�����ѯ������Ӧ
            virtual void MainOnRspQryExchangeRate(CThostFtdcExchangeRateField *pExchangeRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

            ///�����ѯ�����������Ա����Ȩ����Ӧ
            virtual void MainOnRspQrySecAgentACIDMap(CThostFtdcSecAgentACIDMapField *pSecAgentACIDMap, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

            ///�����ѯ��Ʒ���ۻ���
            virtual void MainOnRspQryProductExchRate(CThostFtdcProductExchRateField *pProductExchRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

            ///�����ѯ��Ȩ���׳ɱ���Ӧ
            virtual void MainOnRspQryOptionInstrTradeCost(CThostFtdcOptionInstrTradeCostField *pOptionInstrTradeCost, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

            ///�����ѯ��Ȩ��Լ��������Ӧ
            virtual void MainOnRspQryOptionInstrCommRate(CThostFtdcOptionInstrCommRateField *pOptionInstrCommRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

            ///�����ѯִ��������Ӧ
            virtual void MainOnRspQryExecOrder(CThostFtdcExecOrderField *pExecOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

            ///�����ѯѯ����Ӧ
            virtual void MainOnRspQryForQuote(CThostFtdcForQuoteField *pForQuote, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

            ///�����ѯ������Ӧ
            virtual void MainOnRspQryQuote(CThostFtdcQuoteField *pQuote, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

            ///�����ѯ��Ϻ�Լ��ȫϵ����Ӧ
            virtual void MainOnRspQryCombInstrumentGuard(CThostFtdcCombInstrumentGuardField *pCombInstrumentGuard, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

            ///�����ѯ���������Ӧ
            virtual void MainOnRspQryCombAction(CThostFtdcCombActionField *pCombAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

            ///�����ѯת����ˮ��Ӧ
            virtual void MainOnRspQryTransferSerial(CThostFtdcTransferSerialField *pTransferSerial, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

            ///�����ѯ����ǩԼ��ϵ��Ӧ
            virtual void MainOnRspQryAccountregister(CThostFtdcAccountregisterField *pAccountregister, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

            ///����Ӧ��
            virtual void MainOnRspError(CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

            ///����֪ͨ
            virtual void MainOnRtnOrder(CThostFtdcOrderField *pOrder);

            ///�ɽ�֪ͨ
            virtual void MainOnRtnTrade(CThostFtdcTradeField *pTrade);

            ///����¼�����ر�
            virtual void MainOnErrRtnOrderInsert(CThostFtdcInputOrderField *pInputOrder, CThostFtdcRspInfoField *pRspInfo);

            ///������������ر�
            virtual void MainOnErrRtnOrderAction(CThostFtdcOrderActionField *pOrderAction, CThostFtdcRspInfoField *pRspInfo);

            ///��Լ����״̬֪ͨ
            virtual void MainOnRtnInstrumentStatus(CThostFtdcInstrumentStatusField *pInstrumentStatus);

            ///����֪ͨ
            virtual void MainOnRtnTradingNotice(CThostFtdcTradingNoticeInfoField *pTradingNoticeInfo);

            ///��ʾ������У�����
            virtual void MainOnRtnErrorConditionalOrder(CThostFtdcErrorConditionalOrderField *pErrorConditionalOrder);

            ///ִ������֪ͨ
            virtual void MainOnRtnExecOrder(CThostFtdcExecOrderField *pExecOrder);

            ///ִ������¼�����ر�
            virtual void MainOnErrRtnExecOrderInsert(CThostFtdcInputExecOrderField *pInputExecOrder, CThostFtdcRspInfoField *pRspInfo);

            ///ִ�������������ر�
            virtual void MainOnErrRtnExecOrderAction(CThostFtdcExecOrderActionField *pExecOrderAction, CThostFtdcRspInfoField *pRspInfo);

            ///ѯ��¼�����ر�
            virtual void MainOnErrRtnForQuoteInsert(CThostFtdcInputForQuoteField *pInputForQuote, CThostFtdcRspInfoField *pRspInfo);

            ///����֪ͨ
            virtual void MainOnRtnQuote(CThostFtdcQuoteField *pQuote);

            ///����¼�����ر�
            virtual void MainOnErrRtnQuoteInsert(CThostFtdcInputQuoteField *pInputQuote, CThostFtdcRspInfoField *pRspInfo);

            ///���۲�������ر�
            virtual void MainOnErrRtnQuoteAction(CThostFtdcQuoteActionField *pQuoteAction, CThostFtdcRspInfoField *pRspInfo);

            ///ѯ��֪ͨ
            virtual void MainOnRtnForQuoteRsp(CThostFtdcForQuoteRspField *pForQuoteRsp);

            ///��֤���������û�����
            virtual void MainOnRtnCFMMCTradingAccountToken(CThostFtdcCFMMCTradingAccountTokenField *pCFMMCTradingAccountToken);

            ///�������֪ͨ
            virtual void MainOnRtnCombAction(CThostFtdcCombActionField *pCombAction);

            ///�������¼�����ر�
            virtual void MainOnErrRtnCombActionInsert(CThostFtdcInputCombActionField *pInputCombAction, CThostFtdcRspInfoField *pRspInfo);

            ///�����ѯǩԼ������Ӧ
            virtual void MainOnRspQryContractBank(CThostFtdcContractBankField *pContractBank, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

            ///�����ѯԤ����Ӧ
            virtual void MainOnRspQryParkedOrder(CThostFtdcParkedOrderField *pParkedOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

            ///�����ѯԤ�񳷵���Ӧ
            virtual void MainOnRspQryParkedOrderAction(CThostFtdcParkedOrderActionField *pParkedOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

            ///�����ѯ����֪ͨ��Ӧ
            virtual void MainOnRspQryTradingNotice(CThostFtdcTradingNoticeField *pTradingNotice, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

            ///�����ѯ���͹�˾���ײ�����Ӧ
            virtual void MainOnRspQryBrokerTradingParams(CThostFtdcBrokerTradingParamsField *pBrokerTradingParams, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

            ///�����ѯ���͹�˾�����㷨��Ӧ
            virtual void MainOnRspQryBrokerTradingAlgos(CThostFtdcBrokerTradingAlgosField *pBrokerTradingAlgos, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

            ///�����ѯ��������û�����
            virtual void MainOnRspQueryCFMMCTradingAccountToken(CThostFtdcQueryCFMMCTradingAccountTokenField *pQueryCFMMCTradingAccountToken, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

            ///���з��������ʽ�ת�ڻ�֪ͨ
            virtual void MainOnRtnFromBankToFutureByBank(CThostFtdcRspTransferField *pRspTransfer);

            ///���з����ڻ��ʽ�ת����֪ͨ
            virtual void MainOnRtnFromFutureToBankByBank(CThostFtdcRspTransferField *pRspTransfer);

            ///���з����������ת�ڻ�֪ͨ
            virtual void MainOnRtnRepealFromBankToFutureByBank(CThostFtdcRspRepealField *pRspRepeal);

            ///���з�������ڻ�ת����֪ͨ
            virtual void MainOnRtnRepealFromFutureToBankByBank(CThostFtdcRspRepealField *pRspRepeal);

            ///�ڻ����������ʽ�ת�ڻ�֪ͨ
            virtual void MainOnRtnFromBankToFutureByFuture(CThostFtdcRspTransferField *pRspTransfer);

            ///�ڻ������ڻ��ʽ�ת����֪ͨ
            virtual void MainOnRtnFromFutureToBankByFuture(CThostFtdcRspTransferField *pRspTransfer);

            ///ϵͳ����ʱ�ڻ����ֹ������������ת�ڻ��������д�����Ϻ��̷��ص�֪ͨ
            virtual void MainOnRtnRepealFromBankToFutureByFutureManual(CThostFtdcRspRepealField *pRspRepeal);

            ///ϵͳ����ʱ�ڻ����ֹ���������ڻ�ת�����������д�����Ϻ��̷��ص�֪ͨ
            virtual void MainOnRtnRepealFromFutureToBankByFutureManual(CThostFtdcRspRepealField *pRspRepeal);

            ///�ڻ������ѯ�������֪ͨ
            virtual void MainOnRtnQueryBankBalanceByFuture(CThostFtdcNotifyQueryAccountField *pNotifyQueryAccount);

            ///�ڻ����������ʽ�ת�ڻ�����ر�
            virtual void MainOnErrRtnBankToFutureByFuture(CThostFtdcReqTransferField *pReqTransfer, CThostFtdcRspInfoField *pRspInfo);

            ///�ڻ������ڻ��ʽ�ת���д���ر�
            virtual void MainOnErrRtnFutureToBankByFuture(CThostFtdcReqTransferField *pReqTransfer, CThostFtdcRspInfoField *pRspInfo);

            ///ϵͳ����ʱ�ڻ����ֹ������������ת�ڻ�����ر�
            virtual void MainOnErrRtnRepealBankToFutureByFutureManual(CThostFtdcReqRepealField *pReqRepeal, CThostFtdcRspInfoField *pRspInfo);

            ///ϵͳ����ʱ�ڻ����ֹ���������ڻ�ת���д���ر�
            virtual void MainOnErrRtnRepealFutureToBankByFutureManual(CThostFtdcReqRepealField *pReqRepeal, CThostFtdcRspInfoField *pRspInfo);

            ///�ڻ������ѯ����������ر�
            virtual void MainOnErrRtnQueryBankBalanceByFuture(CThostFtdcReqQueryAccountField *pReqQueryAccount, CThostFtdcRspInfoField *pRspInfo);

            ///�ڻ������������ת�ڻ��������д�����Ϻ��̷��ص�֪ͨ
            virtual void MainOnRtnRepealFromBankToFutureByFuture(CThostFtdcRspRepealField *pRspRepeal);

            ///�ڻ���������ڻ�ת�����������д�����Ϻ��̷��ص�֪ͨ
            virtual void MainOnRtnRepealFromFutureToBankByFuture(CThostFtdcRspRepealField *pRspRepeal);

            ///�ڻ����������ʽ�ת�ڻ�Ӧ��
            virtual void MainOnRspFromBankToFutureByFuture(CThostFtdcReqTransferField *pReqTransfer, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

            ///�ڻ������ڻ��ʽ�ת����Ӧ��
            virtual void MainOnRspFromFutureToBankByFuture(CThostFtdcReqTransferField *pReqTransfer, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

            ///�ڻ������ѯ�������Ӧ��
            virtual void MainOnRspQueryBankAccountMoneyByFuture(CThostFtdcReqQueryAccountField *pReqQueryAccount, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

            ///���з������ڿ���֪ͨ
            virtual void MainOnRtnOpenAccountByBank(CThostFtdcOpenAccountField *pOpenAccount);

            ///���з�����������֪ͨ
            virtual void MainOnRtnCancelAccountByBank(CThostFtdcCancelAccountField *pCancelAccount);

            ///���з����������˺�֪ͨ
            virtual void MainOnRtnChangeAccountByBank(CThostFtdcChangeAccountField *pChangeAccount);

            bool CanCallback(string event)
            {
                if(callback_map.find(event) != callback_map.end()) return true;
                return false;
            }
            void SetCallback(string event, v8::Local<v8::Function>& cb, v8::Isolate* isolate)
            {
                callback_map[event].Reset(isolate, cb);
            }

        private:
            std::map<string, v8::Persistent<v8::Function> > callback_map; //�ص�js nameӳ��ص�������

            static set<string>         m_event;                //����ע��Ļص��¼�
            static v8::Persistent<v8::Function> constructor;           //����������ӳ��js name

            static void New(const v8::FunctionCallbackInfo<v8::Value>& args);
            v8::Local<v8::Value> PkgRspInfo(CThostFtdcRspInfoField *pRspInfo) 
            {
                v8::Isolate* isolate = v8::Isolate::GetCurrent();
                if (pRspInfo != NULL) 
                { 
                    //printf("-----%d %s--------\n", pRspInfo->ErrorID, pRspInfo->ErrorMsg);
                    v8::Local<v8::Object> jsonInfo = v8::Object::New(isolate);                                       
                    jsonInfo->Set(v8::String::NewFromUtf8(isolate, "ErrorID"), v8::Int32::New(isolate, pRspInfo->ErrorID));   
                    jsonInfo->Set(v8::String::NewFromUtf8(isolate, "ErrorMsg"), v8::String::NewFromUtf8(isolate, CSFunction::GBK2UTF8(pRspInfo->ErrorMsg).c_str()));
                    return jsonInfo; 
                } 
                else
                {
                    return  v8::Local<v8::Value>::New(isolate, v8::Undefined(isolate));                                       
                }     
            }

    };
}


#endif



