/////////////////////////////////////////////////////////////////////////
///@system node ctp addon
///@company ��������
///@file ThostFtdcTraderSpiI.cpp
///@brief ctp�ӿ�
///@history 
///20160326	dreamyzhang		�������ļ�
/////////////////////////////////////////////////////////////////////////

#include "ThostFtdcTraderSpiI.h"

namespace td
{

CThostFtdcTraderSpiI::CThostFtdcTraderSpiI()
{
    task_size = 1000;
    task_position = 0;
    ptask = new taskdata* [task_size];
    for(uint32_t i=0; i<task_size; i++)
    {
        ptask[i] = new taskdata(this);
        uv_async_init(uv_default_loop(), &ptask[i]->handle, on_async_cb);
    }
    
    //m_pApi = CThostFtdcTraderApi::CreateFtdcTraderApi();
    //m_pApi->RegisterSpi(this);
}

CThostFtdcTraderSpiI::~CThostFtdcTraderSpiI()
{
    for(uint32_t i=0; i<task_size; i++)
    {
        uv_close((uv_handle_t*) & ptask[i]->handle, on_uv_close_cb);
    }
    delete ptask;
    
    m_pApi->Release(); 
    m_pApi = NULL;
}

void CThostFtdcTraderSpiI::on_uv_close_cb(uv_handle_t* handle) 
{
    delete (taskdata*)(((uv_async_t*)handle)->data);
}

void CThostFtdcTraderSpiI::on_async_cb(uv_async_t* handle)
{
    //����js�еĻص����� �ڳ�ʼ����ʱ��ע���
    taskdata* task = (taskdata*)handle->data;
    //printf("on_async_cb api=%s\n", task->api.c_str());
    do{
        if(task->api == "OnFrontConnected") { task->ptd->MainOnFrontConnected(); continue; };
        if(task->api == "OnFrontDisconnected") { task->ptd->MainOnFrontDisconnected(task->data.nReason); continue; };
        if(task->api == "OnHeartBeatWarning") { task->ptd->MainOnHeartBeatWarning(task->data.nTimeLapse); continue; };
        if(task->api == "OnRspAuthenticate") { task->ptd->MainOnRspAuthenticate(&task->data.RspAuthenticateField, &task->RspInfo, task->nRequestID, task->bIsLast); continue; };
        if(task->api == "OnRspUserLogin") { task->ptd->MainOnRspUserLogin(&task->data.RspUserLogin, &task->RspInfo, task->nRequestID, task->bIsLast); continue; };
        if(task->api == "OnRspUserLogout") { task->ptd->MainOnRspUserLogout(&task->data.UserLogout, &task->RspInfo, task->nRequestID, task->bIsLast); continue; };
        if(task->api == "OnRspUserPasswordUpdate") { task->ptd->MainOnRspUserPasswordUpdate(&task->data.UserPasswordUpdate, &task->RspInfo, task->nRequestID, task->bIsLast); continue; };
        if(task->api == "OnRspTradingAccountPasswordUpdate") { task->ptd->MainOnRspTradingAccountPasswordUpdate(&task->data.TradingAccountPasswordUpdate, &task->RspInfo, task->nRequestID, task->bIsLast); continue; };
        if(task->api == "OnRspOrderInsert") { task->ptd->MainOnRspOrderInsert(&task->data.InputOrder, &task->RspInfo, task->nRequestID, task->bIsLast); continue; };
        if(task->api == "OnRspParkedOrderInsert") { task->ptd->MainOnRspParkedOrderInsert(&task->data.ParkedOrder, &task->RspInfo, task->nRequestID, task->bIsLast); continue; };
        if(task->api == "OnRspParkedOrderAction") { task->ptd->MainOnRspParkedOrderAction(&task->data.ParkedOrderAction, &task->RspInfo, task->nRequestID, task->bIsLast); continue; };
        if(task->api == "OnRspOrderAction") { task->ptd->MainOnRspOrderAction(&task->data.InputOrderAction, &task->RspInfo, task->nRequestID, task->bIsLast); continue; };
        if(task->api == "OnRspQueryMaxOrderVolume") { task->ptd->MainOnRspQueryMaxOrderVolume(&task->data.QueryMaxOrderVolume, &task->RspInfo, task->nRequestID, task->bIsLast); continue; };
        if(task->api == "OnRspSettlementInfoConfirm") { task->ptd->MainOnRspSettlementInfoConfirm(&task->data.SettlementInfoConfirm, &task->RspInfo, task->nRequestID, task->bIsLast); continue; };
        if(task->api == "OnRspRemoveParkedOrder") { task->ptd->MainOnRspRemoveParkedOrder(&task->data.RemoveParkedOrder, &task->RspInfo, task->nRequestID, task->bIsLast); continue; };
        if(task->api == "OnRspRemoveParkedOrderAction") { task->ptd->MainOnRspRemoveParkedOrderAction(&task->data.RemoveParkedOrderAction, &task->RspInfo, task->nRequestID, task->bIsLast); continue; };
        if(task->api == "OnRspExecOrderInsert") { task->ptd->MainOnRspExecOrderInsert(&task->data.InputExecOrder, &task->RspInfo, task->nRequestID, task->bIsLast); continue; };
        if(task->api == "OnRspExecOrderAction") { task->ptd->MainOnRspExecOrderAction(&task->data.InputExecOrderAction, &task->RspInfo, task->nRequestID, task->bIsLast); continue; };
        if(task->api == "OnRspForQuoteInsert") { task->ptd->MainOnRspForQuoteInsert(&task->data.InputForQuote, &task->RspInfo, task->nRequestID, task->bIsLast); continue; };
        if(task->api == "OnRspQuoteInsert") { task->ptd->MainOnRspQuoteInsert(&task->data.InputQuote, &task->RspInfo, task->nRequestID, task->bIsLast); continue; };
        if(task->api == "OnRspQuoteAction") { task->ptd->MainOnRspQuoteAction(&task->data.InputQuoteAction, &task->RspInfo, task->nRequestID, task->bIsLast); continue; };
        if(task->api == "OnRspBatchOrderAction") { task->ptd->MainOnRspBatchOrderAction(&task->data.InputBatchOrderAction, &task->RspInfo, task->nRequestID, task->bIsLast); continue; };
        if(task->api == "OnRspQryProductGroup") { task->ptd->MainOnRspQryProductGroup(&task->data.ProductGroup, &task->RspInfo, task->nRequestID, task->bIsLast); continue; };
        if(task->api == "OnRspQryMMInstrumentCommissionRate") { task->ptd->MainOnRspQryMMInstrumentCommissionRate(&task->data.MMInstrumentCommissionRate, &task->RspInfo, task->nRequestID, task->bIsLast); continue; };
        if(task->api == "OnRspQryMMOptionInstrCommRate") { task->ptd->MainOnRspQryMMOptionInstrCommRate(&task->data.MMOptionInstrCommRate, &task->RspInfo, task->nRequestID, task->bIsLast); continue; };
        if(task->api == "OnRspQryInstrumentOrderCommRate") { task->ptd->MainOnRspQryInstrumentOrderCommRate(&task->data.InstrumentOrderCommRate, &task->RspInfo, task->nRequestID, task->bIsLast); continue; };
        if(task->api == "OnRtnBulletin") { task->ptd->MainOnRtnBulletin(&task->data.Bulletin); continue; };
        if(task->api == "OnErrRtnBatchOrderAction") { task->ptd->MainOnErrRtnBatchOrderAction(&task->data.BatchOrderAction, &task->RspInfo); continue; };
        if(task->api == "OnRspCombActionInsert") { task->ptd->MainOnRspCombActionInsert(&task->data.InputCombAction, &task->RspInfo, task->nRequestID, task->bIsLast); continue; };
        if(task->api == "OnRspQryOrder") { task->ptd->MainOnRspQryOrder(&task->data.Order, &task->RspInfo, task->nRequestID, task->bIsLast); continue; };
        if(task->api == "OnRspQryTrade") { task->ptd->MainOnRspQryTrade(&task->data.Trade, &task->RspInfo, task->nRequestID, task->bIsLast); continue; };
        if(task->api == "OnRspQryInvestorPosition") { task->ptd->MainOnRspQryInvestorPosition(&task->data.InvestorPosition, &task->RspInfo, task->nRequestID, task->bIsLast); continue; };
        if(task->api == "OnRspQryTradingAccount") { task->ptd->MainOnRspQryTradingAccount(&task->data.TradingAccount, &task->RspInfo, task->nRequestID, task->bIsLast); continue; };
        if(task->api == "OnRspQryInvestor") { task->ptd->MainOnRspQryInvestor(&task->data.Investor, &task->RspInfo, task->nRequestID, task->bIsLast); continue; };
        if(task->api == "OnRspQryTradingCode") { task->ptd->MainOnRspQryTradingCode(&task->data.TradingCode, &task->RspInfo, task->nRequestID, task->bIsLast); continue; };
        if(task->api == "OnRspQryInstrumentMarginRate") { task->ptd->MainOnRspQryInstrumentMarginRate(&task->data.InstrumentMarginRate, &task->RspInfo, task->nRequestID, task->bIsLast); continue; };
        if(task->api == "OnRspQryInstrumentCommissionRate") { task->ptd->MainOnRspQryInstrumentCommissionRate(&task->data.InstrumentCommissionRate, &task->RspInfo, task->nRequestID, task->bIsLast); continue; };
        if(task->api == "OnRspQryExchange") { task->ptd->MainOnRspQryExchange(&task->data.Exchange, &task->RspInfo, task->nRequestID, task->bIsLast); continue; };
        if(task->api == "OnRspQryProduct") { task->ptd->MainOnRspQryProduct(&task->data.Product, &task->RspInfo, task->nRequestID, task->bIsLast); continue; };
        if(task->api == "OnRspQryInstrument") { task->ptd->MainOnRspQryInstrument(&task->data.Instrument, &task->RspInfo, task->nRequestID, task->bIsLast); continue; };
        if(task->api == "OnRspQryDepthMarketData") { task->ptd->MainOnRspQryDepthMarketData(&task->data.DepthMarketData, &task->RspInfo, task->nRequestID, task->bIsLast); continue; };
        if(task->api == "OnRspQrySettlementInfo") { task->ptd->MainOnRspQrySettlementInfo(&task->data.SettlementInfo, &task->RspInfo, task->nRequestID, task->bIsLast); continue; };
        if(task->api == "OnRspQryTransferBank") { task->ptd->MainOnRspQryTransferBank(&task->data.TransferBank, &task->RspInfo, task->nRequestID, task->bIsLast); continue; };
        if(task->api == "OnRspQryInvestorPositionDetail") { task->ptd->MainOnRspQryInvestorPositionDetail(&task->data.InvestorPositionDetail, &task->RspInfo, task->nRequestID, task->bIsLast); continue; };
        if(task->api == "OnRspQryNotice") { task->ptd->MainOnRspQryNotice(&task->data.Notice, &task->RspInfo, task->nRequestID, task->bIsLast); continue; };
        if(task->api == "OnRspQrySettlementInfoConfirm") { task->ptd->MainOnRspQrySettlementInfoConfirm(&task->data.SettlementInfoConfirm, &task->RspInfo, task->nRequestID, task->bIsLast); continue; };
        if(task->api == "OnRspQryInvestorPositionCombineDetail") { task->ptd->MainOnRspQryInvestorPositionCombineDetail(&task->data.InvestorPositionCombineDetail, &task->RspInfo, task->nRequestID, task->bIsLast); continue; };
        if(task->api == "OnRspQryCFMMCTradingAccountKey") { task->ptd->MainOnRspQryCFMMCTradingAccountKey(&task->data.CFMMCTradingAccountKey, &task->RspInfo, task->nRequestID, task->bIsLast); continue; };
        if(task->api == "OnRspQryEWarrantOffset") { task->ptd->MainOnRspQryEWarrantOffset(&task->data.EWarrantOffset, &task->RspInfo, task->nRequestID, task->bIsLast); continue; };
        if(task->api == "OnRspQryInvestorProductGroupMargin") { task->ptd->MainOnRspQryInvestorProductGroupMargin(&task->data.InvestorProductGroupMargin, &task->RspInfo, task->nRequestID, task->bIsLast); continue; };
        if(task->api == "OnRspQryExchangeMarginRate") { task->ptd->MainOnRspQryExchangeMarginRate(&task->data.ExchangeMarginRate, &task->RspInfo, task->nRequestID, task->bIsLast); continue; };
        if(task->api == "OnRspQryExchangeMarginRateAdjust") { task->ptd->MainOnRspQryExchangeMarginRateAdjust(&task->data.ExchangeMarginRateAdjust, &task->RspInfo, task->nRequestID, task->bIsLast); continue; };
        if(task->api == "OnRspQryExchangeRate") { task->ptd->MainOnRspQryExchangeRate(&task->data.ExchangeRate, &task->RspInfo, task->nRequestID, task->bIsLast); continue; };
        if(task->api == "OnRspQrySecAgentACIDMap") { task->ptd->MainOnRspQrySecAgentACIDMap(&task->data.SecAgentACIDMap, &task->RspInfo, task->nRequestID, task->bIsLast); continue; };
        if(task->api == "OnRspQryProductExchRate") { task->ptd->MainOnRspQryProductExchRate(&task->data.ProductExchRate, &task->RspInfo, task->nRequestID, task->bIsLast); continue; };
        if(task->api == "OnRspQryOptionInstrTradeCost") { task->ptd->MainOnRspQryOptionInstrTradeCost(&task->data.OptionInstrTradeCost, &task->RspInfo, task->nRequestID, task->bIsLast); continue; };
        if(task->api == "OnRspQryOptionInstrCommRate") { task->ptd->MainOnRspQryOptionInstrCommRate(&task->data.OptionInstrCommRate, &task->RspInfo, task->nRequestID, task->bIsLast); continue; };
        if(task->api == "OnRspQryExecOrder") { task->ptd->MainOnRspQryExecOrder(&task->data.ExecOrder, &task->RspInfo, task->nRequestID, task->bIsLast); continue; };
        if(task->api == "OnRspQryForQuote") { task->ptd->MainOnRspQryForQuote(&task->data.ForQuote, &task->RspInfo, task->nRequestID, task->bIsLast); continue; };
        if(task->api == "OnRspQryQuote") { task->ptd->MainOnRspQryQuote(&task->data.Quote, &task->RspInfo, task->nRequestID, task->bIsLast); continue; };
        if(task->api == "OnRspQryCombInstrumentGuard") { task->ptd->MainOnRspQryCombInstrumentGuard(&task->data.CombInstrumentGuard, &task->RspInfo, task->nRequestID, task->bIsLast); continue; };
        if(task->api == "OnRspQryCombAction") { task->ptd->MainOnRspQryCombAction(&task->data.CombAction, &task->RspInfo, task->nRequestID, task->bIsLast); continue; };
        if(task->api == "OnRspQryTransferSerial") { task->ptd->MainOnRspQryTransferSerial(&task->data.TransferSerial, &task->RspInfo, task->nRequestID, task->bIsLast); continue; };
        if(task->api == "OnRspQryAccountregister") { task->ptd->MainOnRspQryAccountregister(&task->data.Accountregister, &task->RspInfo, task->nRequestID, task->bIsLast); continue; };
        if(task->api == "OnRspError") { task->ptd->MainOnRspError(&task->RspInfo, task->nRequestID, task->bIsLast); continue; };
        if(task->api == "OnRtnOrder") { task->ptd->MainOnRtnOrder(&task->data.Order); continue; };
        if(task->api == "OnRtnTrade") { task->ptd->MainOnRtnTrade(&task->data.Trade); continue; };
        if(task->api == "OnErrRtnOrderInsert") { task->ptd->MainOnErrRtnOrderInsert(&task->data.InputOrder, &task->RspInfo); continue; };
        if(task->api == "OnErrRtnOrderAction") { task->ptd->MainOnErrRtnOrderAction(&task->data.OrderAction, &task->RspInfo); continue; };
        if(task->api == "OnRtnInstrumentStatus") { task->ptd->MainOnRtnInstrumentStatus(&task->data.InstrumentStatus); continue; };
        if(task->api == "OnRtnTradingNotice") { task->ptd->MainOnRtnTradingNotice(&task->data.TradingNoticeInfo); continue; };
        if(task->api == "OnRtnErrorConditionalOrder") { task->ptd->MainOnRtnErrorConditionalOrder(&task->data.ErrorConditionalOrder); continue; };
        if(task->api == "OnRtnExecOrder") { task->ptd->MainOnRtnExecOrder(&task->data.ExecOrder); continue; };
        if(task->api == "OnErrRtnExecOrderInsert") { task->ptd->MainOnErrRtnExecOrderInsert(&task->data.InputExecOrder, &task->RspInfo); continue; };
        if(task->api == "OnErrRtnExecOrderAction") { task->ptd->MainOnErrRtnExecOrderAction(&task->data.ExecOrderAction, &task->RspInfo); continue; };
        if(task->api == "OnErrRtnForQuoteInsert") { task->ptd->MainOnErrRtnForQuoteInsert(&task->data.InputForQuote, &task->RspInfo); continue; };
        if(task->api == "OnRtnQuote") { task->ptd->MainOnRtnQuote(&task->data.Quote); continue; };
        if(task->api == "OnErrRtnQuoteInsert") { task->ptd->MainOnErrRtnQuoteInsert(&task->data.InputQuote, &task->RspInfo); continue; };
        if(task->api == "OnErrRtnQuoteAction") { task->ptd->MainOnErrRtnQuoteAction(&task->data.QuoteAction, &task->RspInfo); continue; };
        if(task->api == "OnRtnForQuoteRsp") { task->ptd->MainOnRtnForQuoteRsp(&task->data.ForQuoteRsp); continue; };
        if(task->api == "OnRtnCFMMCTradingAccountToken") { task->ptd->MainOnRtnCFMMCTradingAccountToken(&task->data.CFMMCTradingAccountToken); continue; };
        if(task->api == "OnRtnCombAction") { task->ptd->MainOnRtnCombAction(&task->data.CombAction); continue; };
        if(task->api == "OnErrRtnCombActionInsert") { task->ptd->MainOnErrRtnCombActionInsert(&task->data.InputCombAction, &task->RspInfo); continue; };
        if(task->api == "OnRspQryContractBank") { task->ptd->MainOnRspQryContractBank(&task->data.ContractBank, &task->RspInfo, task->nRequestID, task->bIsLast); continue; };
        if(task->api == "OnRspQryParkedOrder") { task->ptd->MainOnRspQryParkedOrder(&task->data.ParkedOrder, &task->RspInfo, task->nRequestID, task->bIsLast); continue; };
        if(task->api == "OnRspQryParkedOrderAction") { task->ptd->MainOnRspQryParkedOrderAction(&task->data.ParkedOrderAction, &task->RspInfo, task->nRequestID, task->bIsLast); continue; };
        if(task->api == "OnRspQryTradingNotice") { task->ptd->MainOnRspQryTradingNotice(&task->data.TradingNotice, &task->RspInfo, task->nRequestID, task->bIsLast); continue; };
        if(task->api == "OnRspQryBrokerTradingParams") { task->ptd->MainOnRspQryBrokerTradingParams(&task->data.BrokerTradingParams, &task->RspInfo, task->nRequestID, task->bIsLast); continue; };
        if(task->api == "OnRspQryBrokerTradingAlgos") { task->ptd->MainOnRspQryBrokerTradingAlgos(&task->data.BrokerTradingAlgos, &task->RspInfo, task->nRequestID, task->bIsLast); continue; };
        if(task->api == "OnRspQueryCFMMCTradingAccountToken") { task->ptd->MainOnRspQueryCFMMCTradingAccountToken(&task->data.QueryCFMMCTradingAccountToken, &task->RspInfo, task->nRequestID, task->bIsLast); continue; };
        if(task->api == "OnRtnFromBankToFutureByBank") { task->ptd->MainOnRtnFromBankToFutureByBank(&task->data.RspTransfer); continue; };
        if(task->api == "OnRtnFromFutureToBankByBank") { task->ptd->MainOnRtnFromFutureToBankByBank(&task->data.RspTransfer); continue; };
        if(task->api == "OnRtnRepealFromBankToFutureByBank") { task->ptd->MainOnRtnRepealFromBankToFutureByBank(&task->data.RspRepeal); continue; };
        if(task->api == "OnRtnRepealFromFutureToBankByBank") { task->ptd->MainOnRtnRepealFromFutureToBankByBank(&task->data.RspRepeal); continue; };
        if(task->api == "OnRtnFromBankToFutureByFuture") { task->ptd->MainOnRtnFromBankToFutureByFuture(&task->data.RspTransfer); continue; };
        if(task->api == "OnRtnFromFutureToBankByFuture") { task->ptd->MainOnRtnFromFutureToBankByFuture(&task->data.RspTransfer); continue; };
        if(task->api == "OnRtnRepealFromBankToFutureByFutureManual") { task->ptd->MainOnRtnRepealFromBankToFutureByFutureManual(&task->data.RspRepeal); continue; };
        if(task->api == "OnRtnRepealFromFutureToBankByFutureManual") { task->ptd->MainOnRtnRepealFromFutureToBankByFutureManual(&task->data.RspRepeal); continue; };
        if(task->api == "OnRtnQueryBankBalanceByFuture") { task->ptd->MainOnRtnQueryBankBalanceByFuture(&task->data.NotifyQueryAccount); continue; };
        if(task->api == "OnErrRtnBankToFutureByFuture") { task->ptd->MainOnErrRtnBankToFutureByFuture(&task->data.ReqTransfer, &task->RspInfo); continue; };
        if(task->api == "OnErrRtnFutureToBankByFuture") { task->ptd->MainOnErrRtnFutureToBankByFuture(&task->data.ReqTransfer, &task->RspInfo); continue; };
        if(task->api == "OnErrRtnRepealBankToFutureByFutureManual") { task->ptd->MainOnErrRtnRepealBankToFutureByFutureManual(&task->data.ReqRepeal, &task->RspInfo); continue; };
        if(task->api == "OnErrRtnRepealFutureToBankByFutureManual") { task->ptd->MainOnErrRtnRepealFutureToBankByFutureManual(&task->data.ReqRepeal, &task->RspInfo); continue; };
        if(task->api == "OnErrRtnQueryBankBalanceByFuture") { task->ptd->MainOnErrRtnQueryBankBalanceByFuture(&task->data.ReqQueryAccount, &task->RspInfo); continue; };
        if(task->api == "OnRtnRepealFromBankToFutureByFuture") { task->ptd->MainOnRtnRepealFromBankToFutureByFuture(&task->data.RspRepeal); continue; };
        if(task->api == "OnRtnRepealFromFutureToBankByFuture") { task->ptd->MainOnRtnRepealFromFutureToBankByFuture(&task->data.RspRepeal); continue; };
        if(task->api == "OnRspFromBankToFutureByFuture") { task->ptd->MainOnRspFromBankToFutureByFuture(&task->data.ReqTransfer, &task->RspInfo, task->nRequestID, task->bIsLast); continue; };
        if(task->api == "OnRspFromFutureToBankByFuture") { task->ptd->MainOnRspFromFutureToBankByFuture(&task->data.ReqTransfer, &task->RspInfo, task->nRequestID, task->bIsLast); continue; };
        if(task->api == "OnRspQueryBankAccountMoneyByFuture") { task->ptd->MainOnRspQueryBankAccountMoneyByFuture(&task->data.ReqQueryAccount, &task->RspInfo, task->nRequestID, task->bIsLast); continue; };
        if(task->api == "OnRtnOpenAccountByBank") { task->ptd->MainOnRtnOpenAccountByBank(&task->data.OpenAccount); continue; };
        if(task->api == "OnRtnCancelAccountByBank") { task->ptd->MainOnRtnCancelAccountByBank(&task->data.CancelAccount); continue; };
        if(task->api == "OnRtnChangeAccountByBank") { task->ptd->MainOnRtnChangeAccountByBank(&task->data.ChangeAccount); continue; };
    }while(0); 
    task->reinit();
    //uv_close((uv_handle_t*)handle, on_uv_close_cb);
}

void CThostFtdcTraderSpiI::OnFrontConnected()
{
    QUEUEPUSH(__FUNCTION__);
}

void CThostFtdcTraderSpiI::OnFrontDisconnected(int nReason)
{
    QUEUEPUSH(__FUNCTION__, &nReason, sizeof(nReason));
}

void CThostFtdcTraderSpiI::OnHeartBeatWarning(int nTimeLapse)
{
    QUEUEPUSH(__FUNCTION__, &nTimeLapse, sizeof(nTimeLapse));
}

void CThostFtdcTraderSpiI::OnRspAuthenticate(CThostFtdcRspAuthenticateField *pRspAuthenticateField, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
    QUEUEPUSH(__FUNCTION__, pRspAuthenticateField, sizeof(CThostFtdcRspAuthenticateField), pRspInfo, nRequestID, bIsLast);
}

void CThostFtdcTraderSpiI::OnRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
    QUEUEPUSH(__FUNCTION__, pRspUserLogin, sizeof(CThostFtdcRspUserLoginField), pRspInfo, nRequestID, bIsLast);
}

void CThostFtdcTraderSpiI::OnRspUserLogout(CThostFtdcUserLogoutField *pUserLogout, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
    QUEUEPUSH(__FUNCTION__, pUserLogout, sizeof(CThostFtdcUserLogoutField), pRspInfo, nRequestID, bIsLast);
}

void CThostFtdcTraderSpiI::OnRspUserPasswordUpdate(CThostFtdcUserPasswordUpdateField *pUserPasswordUpdate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
    QUEUEPUSH(__FUNCTION__, pUserPasswordUpdate, sizeof(CThostFtdcUserPasswordUpdateField), pRspInfo, nRequestID, bIsLast);
}

void CThostFtdcTraderSpiI::OnRspTradingAccountPasswordUpdate(CThostFtdcTradingAccountPasswordUpdateField *pTradingAccountPasswordUpdate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	///TODO  �����������
    QUEUEPUSH(__FUNCTION__, pTradingAccountPasswordUpdate, sizeof(CThostFtdcTradingAccountPasswordUpdateField), pRspInfo, nRequestID, bIsLast);
}

void CThostFtdcTraderSpiI::OnRspOrderInsert(CThostFtdcInputOrderField *pInputOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
    QUEUEPUSH(__FUNCTION__, pInputOrder, sizeof(CThostFtdcInputOrderField), pRspInfo, nRequestID, bIsLast);
}

void CThostFtdcTraderSpiI::OnRspParkedOrderInsert(CThostFtdcParkedOrderField *pParkedOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	///Ԥ��¼��������Ӧ
    QUEUEPUSH(__FUNCTION__, pParkedOrder, sizeof(CThostFtdcParkedOrderField), pRspInfo, nRequestID, bIsLast);
}

void CThostFtdcTraderSpiI::OnRspParkedOrderAction(CThostFtdcParkedOrderActionField *pParkedOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	///Ԥ�񳷵�¼��������Ӧ
    QUEUEPUSH(__FUNCTION__, pParkedOrderAction, sizeof(CThostFtdcParkedOrderActionField), pRspInfo, nRequestID, bIsLast);
}

void CThostFtdcTraderSpiI::OnRspOrderAction(CThostFtdcInputOrderActionField *pInputOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
    QUEUEPUSH(__FUNCTION__, pInputOrderAction, sizeof(CThostFtdcInputOrderActionField), pRspInfo, nRequestID, bIsLast);
}

void CThostFtdcTraderSpiI::OnRspQueryMaxOrderVolume(CThostFtdcQueryMaxOrderVolumeField *pQueryMaxOrderVolume, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	///��ѯ��󱨵�������Ӧ
    QUEUEPUSH(__FUNCTION__, pQueryMaxOrderVolume, sizeof(CThostFtdcQueryMaxOrderVolumeField), pRspInfo, nRequestID, bIsLast);
}

void CThostFtdcTraderSpiI::OnRspSettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField *pSettlementInfoConfirm, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
    QUEUEPUSH(__FUNCTION__, pSettlementInfoConfirm, sizeof(CThostFtdcSettlementInfoConfirmField), pRspInfo, nRequestID, bIsLast);
}

void CThostFtdcTraderSpiI::OnRspRemoveParkedOrder(CThostFtdcRemoveParkedOrderField *pRemoveParkedOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	///ɾ��Ԥ����Ӧ
    QUEUEPUSH(__FUNCTION__, pRemoveParkedOrder, sizeof(CThostFtdcRemoveParkedOrderField), pRspInfo, nRequestID, bIsLast);
}

void CThostFtdcTraderSpiI::OnRspRemoveParkedOrderAction(CThostFtdcRemoveParkedOrderActionField *pRemoveParkedOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	///ɾ��Ԥ�񳷵���Ӧ
    QUEUEPUSH(__FUNCTION__, pRemoveParkedOrderAction, sizeof(CThostFtdcRemoveParkedOrderActionField), pRspInfo, nRequestID, bIsLast);
}

void CThostFtdcTraderSpiI::OnRspExecOrderInsert(CThostFtdcInputExecOrderField *pInputExecOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	///ִ������¼��������Ӧ
    QUEUEPUSH(__FUNCTION__, pInputExecOrder, sizeof(CThostFtdcInputExecOrderField), pRspInfo, nRequestID, bIsLast);
}

void CThostFtdcTraderSpiI::OnRspExecOrderAction(CThostFtdcInputExecOrderActionField *pInputExecOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	///ִ���������������Ӧ
    QUEUEPUSH(__FUNCTION__, pInputExecOrderAction, sizeof(CThostFtdcInputExecOrderActionField), pRspInfo, nRequestID, bIsLast);
}

void CThostFtdcTraderSpiI::OnRspForQuoteInsert(CThostFtdcInputForQuoteField *pInputForQuote, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	///ѯ��¼��������Ӧ
    QUEUEPUSH(__FUNCTION__, pInputForQuote, sizeof(CThostFtdcInputForQuoteField), pRspInfo, nRequestID, bIsLast);
}

void CThostFtdcTraderSpiI::OnRspQuoteInsert(CThostFtdcInputQuoteField *pInputQuote, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	///����¼��������Ӧ
    QUEUEPUSH(__FUNCTION__, pInputQuote, sizeof(CThostFtdcInputQuoteField), pRspInfo, nRequestID, bIsLast);
}

void CThostFtdcTraderSpiI::OnRspQuoteAction(CThostFtdcInputQuoteActionField *pInputQuoteAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	///���۲���������Ӧ
    QUEUEPUSH(__FUNCTION__, pInputQuoteAction, sizeof(CThostFtdcInputQuoteActionField), pRspInfo, nRequestID, bIsLast);
}

void CThostFtdcTraderSpiI::OnRspBatchOrderAction(CThostFtdcInputBatchOrderActionField *pInputBatchOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	///������������������Ӧ
    QUEUEPUSH(__FUNCTION__, pInputBatchOrderAction, sizeof(CThostFtdcInputBatchOrderActionField), pRspInfo, nRequestID, bIsLast);
}

void CThostFtdcTraderSpiI::OnRspCombActionInsert(CThostFtdcInputCombActionField *pInputCombAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	///�������¼��������Ӧ
    QUEUEPUSH(__FUNCTION__, pInputCombAction, sizeof(CThostFtdcInputCombActionField), pRspInfo, nRequestID, bIsLast);
}

void CThostFtdcTraderSpiI::OnRspQryOrder(CThostFtdcOrderField *pOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
    QUEUEPUSH(__FUNCTION__, pOrder, sizeof(CThostFtdcOrderField), pRspInfo, nRequestID, bIsLast);
}	

void CThostFtdcTraderSpiI::OnRspQryTrade(CThostFtdcTradeField *pTrade, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
    QUEUEPUSH(__FUNCTION__, pTrade, sizeof(CThostFtdcTradeField), pRspInfo, nRequestID, bIsLast);

}

void CThostFtdcTraderSpiI::OnRspQryInvestorPosition(CThostFtdcInvestorPositionField *pInvestorPosition, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
    QUEUEPUSH(__FUNCTION__, pInvestorPosition, sizeof(CThostFtdcInvestorPositionField), pRspInfo, nRequestID, bIsLast);
}

void CThostFtdcTraderSpiI::OnRspQryTradingAccount(CThostFtdcTradingAccountField *pTradingAccount, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
    QUEUEPUSH(__FUNCTION__, pTradingAccount, sizeof(CThostFtdcTradingAccountField), pRspInfo, nRequestID, bIsLast);
}

void CThostFtdcTraderSpiI::OnRspQryInvestor(CThostFtdcInvestorField *pInvestor, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	///�����ѯͶ������Ӧ
    QUEUEPUSH(__FUNCTION__,pInvestor, sizeof(CThostFtdcInvestorField), pRspInfo, nRequestID, bIsLast);
}

void CThostFtdcTraderSpiI::OnRspQryTradingCode(CThostFtdcTradingCodeField *pTradingCode, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	///�����ѯ���ױ�����Ӧ
    QUEUEPUSH(__FUNCTION__, pTradingCode, sizeof(CThostFtdcTradingCodeField), pRspInfo, nRequestID, bIsLast);
}

void CThostFtdcTraderSpiI::OnRspQryInstrumentMarginRate(CThostFtdcInstrumentMarginRateField *pInstrumentMarginRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	///�����ѯ��Լ��֤������Ӧ
    QUEUEPUSH(__FUNCTION__, pInstrumentMarginRate, sizeof(CThostFtdcInstrumentMarginRateField), pRspInfo, nRequestID, bIsLast);
}

void CThostFtdcTraderSpiI::OnRspQryInstrumentCommissionRate(CThostFtdcInstrumentCommissionRateField *pInstrumentCommissionRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	///�����ѯ��Լ����������Ӧ
    QUEUEPUSH(__FUNCTION__, pInstrumentCommissionRate, sizeof(CThostFtdcInstrumentCommissionRateField), pRspInfo, nRequestID, bIsLast);
}

void CThostFtdcTraderSpiI::OnRspQryExchange(CThostFtdcExchangeField *pExchange, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	///�����ѯ��������Ӧ
    QUEUEPUSH(__FUNCTION__, pExchange, sizeof(CThostFtdcExchangeField), pRspInfo, nRequestID, bIsLast);
}

void CThostFtdcTraderSpiI::OnRspQryProduct(CThostFtdcProductField *pProduct, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	///�����ѯ��Ʒ��Ӧ
    QUEUEPUSH(__FUNCTION__, pProduct, sizeof(CThostFtdcProductField), pRspInfo, nRequestID, bIsLast);
}

void CThostFtdcTraderSpiI::OnRspQryInstrument(CThostFtdcInstrumentField *pInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	///�����ѯ��Լ��Ӧ
    QUEUEPUSH(__FUNCTION__, pInstrument, sizeof(CThostFtdcInstrumentField), pRspInfo, nRequestID, bIsLast);
}

void CThostFtdcTraderSpiI::OnRspQryDepthMarketData(CThostFtdcDepthMarketDataField *pDepthMarketData, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	///�����ѯ������Ӧ
    QUEUEPUSH(__FUNCTION__, pDepthMarketData, sizeof(CThostFtdcDepthMarketDataField), pRspInfo, nRequestID, bIsLast);
}

void CThostFtdcTraderSpiI::OnRspQrySettlementInfo(CThostFtdcSettlementInfoField *pSettlementInfo, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	///�����ѯͶ���߽�������Ӧ
    QUEUEPUSH(__FUNCTION__, pSettlementInfo, sizeof(CThostFtdcSettlementInfoField), pRspInfo, nRequestID, bIsLast);
}

void CThostFtdcTraderSpiI::OnRspQryTransferBank(CThostFtdcTransferBankField *pTransferBank, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	///�����ѯת��������Ӧ
    QUEUEPUSH(__FUNCTION__, pTransferBank, sizeof(CThostFtdcTransferBankField), pRspInfo, nRequestID, bIsLast);

}

void CThostFtdcTraderSpiI::OnRspQryInvestorPositionDetail(CThostFtdcInvestorPositionDetailField *pInvestorPositionDetail, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	///�����ѯͶ���ֲ߳���ϸ��Ӧ
    QUEUEPUSH(__FUNCTION__, pInvestorPositionDetail, sizeof(CThostFtdcInvestorPositionDetailField), pRspInfo, nRequestID, bIsLast);

}

void CThostFtdcTraderSpiI::OnRspQryNotice(CThostFtdcNoticeField *pNotice, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	///�����ѯ�ͻ�֪ͨ��Ӧ
    QUEUEPUSH(__FUNCTION__, pNotice, sizeof(CThostFtdcNoticeField), pRspInfo, nRequestID, bIsLast);
}

void CThostFtdcTraderSpiI::OnRspQrySettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField *pSettlementInfoConfirm, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	///�����ѯ������Ϣȷ����Ӧ
    QUEUEPUSH(__FUNCTION__, pSettlementInfoConfirm, sizeof(CThostFtdcSettlementInfoConfirmField), pRspInfo, nRequestID, bIsLast);
}

void CThostFtdcTraderSpiI::OnRspQryInvestorPositionCombineDetail(CThostFtdcInvestorPositionCombineDetailField *pInvestorPositionCombineDetail, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	///�����ѯͶ���ֲ߳���ϸ��Ӧ
    QUEUEPUSH(__FUNCTION__, pInvestorPositionCombineDetail, sizeof(CThostFtdcInvestorPositionCombineDetailField), pRspInfo, nRequestID, bIsLast);
}

void CThostFtdcTraderSpiI::OnRspQryCFMMCTradingAccountKey(CThostFtdcCFMMCTradingAccountKeyField *pCFMMCTradingAccountKey, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	///��ѯ��֤����ϵͳ���͹�˾�ʽ��˻���Կ��Ӧ
    QUEUEPUSH(__FUNCTION__, pCFMMCTradingAccountKey, sizeof(CThostFtdcCFMMCTradingAccountKeyField), pRspInfo, nRequestID, bIsLast);
}

void CThostFtdcTraderSpiI::OnRspQryEWarrantOffset(CThostFtdcEWarrantOffsetField *pEWarrantOffset, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	///�����ѯ�ֵ��۵���Ϣ��Ӧ
    QUEUEPUSH(__FUNCTION__, pEWarrantOffset, sizeof(CThostFtdcEWarrantOffsetField), pRspInfo, nRequestID, bIsLast);
}

void CThostFtdcTraderSpiI::OnRspQryInvestorProductGroupMargin(CThostFtdcInvestorProductGroupMarginField *pInvestorProductGroupMargin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	///�����ѯͶ����Ʒ��/��Ʒ�ֱ�֤����Ӧ
    QUEUEPUSH(__FUNCTION__, pInvestorProductGroupMargin, sizeof(CThostFtdcInvestorProductGroupMarginField), pRspInfo, nRequestID, bIsLast);
}

void CThostFtdcTraderSpiI::OnRspQryExchangeMarginRate(CThostFtdcExchangeMarginRateField *pExchangeMarginRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	///�����ѯ��������֤������Ӧ
    QUEUEPUSH(__FUNCTION__, pExchangeMarginRate, sizeof(CThostFtdcExchangeMarginRateField), pRspInfo, nRequestID, bIsLast);
}

void CThostFtdcTraderSpiI::OnRspQryExchangeMarginRateAdjust(CThostFtdcExchangeMarginRateAdjustField *pExchangeMarginRateAdjust, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	///�����ѯ������������֤������Ӧ
    QUEUEPUSH(__FUNCTION__, pExchangeMarginRateAdjust, sizeof(CThostFtdcExchangeMarginRateAdjustField), pRspInfo, nRequestID, bIsLast);
}

void CThostFtdcTraderSpiI::OnRspQryExchangeRate(CThostFtdcExchangeRateField *pExchangeRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	///�����ѯ������Ӧ
    QUEUEPUSH(__FUNCTION__, pExchangeRate, sizeof(CThostFtdcExchangeRateField), pRspInfo, nRequestID, bIsLast);
}

void CThostFtdcTraderSpiI::OnRspQrySecAgentACIDMap(CThostFtdcSecAgentACIDMapField *pSecAgentACIDMap, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	///�����ѯ�����������Ա����Ȩ����Ӧ
    QUEUEPUSH(__FUNCTION__, pSecAgentACIDMap, sizeof(CThostFtdcSecAgentACIDMapField), pRspInfo, nRequestID, bIsLast);
}

void CThostFtdcTraderSpiI::OnRspQryProductExchRate(CThostFtdcProductExchRateField *pProductExchRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	///�����ѯ��Ʒ���ۻ���
    QUEUEPUSH(__FUNCTION__, pProductExchRate, sizeof(CThostFtdcProductExchRateField), pRspInfo, nRequestID, bIsLast);
}

void CThostFtdcTraderSpiI::OnRspQryProductGroup(CThostFtdcProductGroupField *pProductGroup, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	///�����ѯ��Ʒ��
    QUEUEPUSH(__FUNCTION__, pProductGroup, sizeof(CThostFtdcProductGroupField), pRspInfo, nRequestID, bIsLast);
}

void CThostFtdcTraderSpiI::OnRspQryMMInstrumentCommissionRate(CThostFtdcMMInstrumentCommissionRateField *pMMInstrumentCommissionRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	///�����ѯ�����̺�Լ����������Ӧ
    QUEUEPUSH(__FUNCTION__, pMMInstrumentCommissionRate, sizeof(CThostFtdcMMInstrumentCommissionRateField), pRspInfo, nRequestID, bIsLast);
}

void CThostFtdcTraderSpiI::OnRspQryMMOptionInstrCommRate(CThostFtdcMMOptionInstrCommRateField *pMMOptionInstrCommRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	///�����ѯ��������Ȩ��Լ��������Ӧ
    QUEUEPUSH(__FUNCTION__, pMMOptionInstrCommRate, sizeof(CThostFtdcMMOptionInstrCommRateField), pRspInfo, nRequestID, bIsLast);
}

void CThostFtdcTraderSpiI::OnRspQryInstrumentOrderCommRate(CThostFtdcInstrumentOrderCommRateField *pInstrumentOrderCommRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	///�����ѯ������������Ӧ
    QUEUEPUSH(__FUNCTION__, pInstrumentOrderCommRate, sizeof(CThostFtdcInstrumentOrderCommRateField), pRspInfo, nRequestID, bIsLast);
}

void CThostFtdcTraderSpiI::OnRspQryOptionInstrTradeCost(CThostFtdcOptionInstrTradeCostField *pOptionInstrTradeCost, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	///�����ѯ��Ȩ���׳ɱ���Ӧ
    QUEUEPUSH(__FUNCTION__, pOptionInstrTradeCost, sizeof(CThostFtdcOptionInstrTradeCostField), pRspInfo, nRequestID, bIsLast);
}

void CThostFtdcTraderSpiI::OnRspQryOptionInstrCommRate(CThostFtdcOptionInstrCommRateField *pOptionInstrCommRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	///�����ѯ��Ȩ��Լ��������Ӧ
    QUEUEPUSH(__FUNCTION__, pOptionInstrCommRate, sizeof(CThostFtdcOptionInstrCommRateField), pRspInfo, nRequestID, bIsLast);
}

void CThostFtdcTraderSpiI::OnRspQryExecOrder(CThostFtdcExecOrderField *pExecOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	///�����ѯִ��������Ӧ
    QUEUEPUSH(__FUNCTION__, pExecOrder, sizeof(CThostFtdcExecOrderField), pRspInfo, nRequestID, bIsLast);
}

void CThostFtdcTraderSpiI::OnRspQryForQuote(CThostFtdcForQuoteField *pForQuote, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	///�����ѯѯ����Ӧ
    QUEUEPUSH(__FUNCTION__, pForQuote, sizeof(CThostFtdcForQuoteField), pRspInfo, nRequestID, bIsLast);
}

void CThostFtdcTraderSpiI::OnRspQryQuote(CThostFtdcQuoteField *pQuote, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	///�����ѯ������Ӧ
    QUEUEPUSH(__FUNCTION__, pQuote, sizeof(CThostFtdcQuoteField), pRspInfo, nRequestID, bIsLast);
}

void CThostFtdcTraderSpiI::OnRspQryCombInstrumentGuard(CThostFtdcCombInstrumentGuardField *pCombInstrumentGuard, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	///�����ѯ��Ϻ�Լ��ȫϵ����Ӧ
    QUEUEPUSH(__FUNCTION__, pCombInstrumentGuard, sizeof(CThostFtdcCombInstrumentGuardField), pRspInfo, nRequestID, bIsLast);
}

void CThostFtdcTraderSpiI::OnRspQryCombAction(CThostFtdcCombActionField *pCombAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	///�����ѯ���������Ӧ
    QUEUEPUSH(__FUNCTION__, pCombAction, sizeof(CThostFtdcCombActionField), pRspInfo, nRequestID, bIsLast);
}

void CThostFtdcTraderSpiI::OnRspQryTransferSerial(CThostFtdcTransferSerialField *pTransferSerial, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	///�����ѯת����ˮ��Ӧ
    QUEUEPUSH(__FUNCTION__, pTransferSerial, sizeof(CThostFtdcTransferSerialField), pRspInfo, nRequestID, bIsLast);
}

void CThostFtdcTraderSpiI::OnRspQryAccountregister(CThostFtdcAccountregisterField *pAccountregister, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	///�����ѯ����ǩԼ��ϵ��Ӧ
    QUEUEPUSH(__FUNCTION__, pAccountregister, sizeof(CThostFtdcAccountregisterField), pRspInfo, nRequestID, bIsLast);
}

void CThostFtdcTraderSpiI::OnRspError(CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	///����Ӧ��
    QUEUEPUSH(__FUNCTION__, NULL, 0, pRspInfo, nRequestID, bIsLast);
}

void CThostFtdcTraderSpiI::OnRtnOrder(CThostFtdcOrderField *pOrder) 
{
    QUEUEPUSH(__FUNCTION__, pOrder, sizeof(CThostFtdcOrderField));
}

void CThostFtdcTraderSpiI::OnRtnTrade(CThostFtdcTradeField *pTrade) 
{
    QUEUEPUSH(__FUNCTION__, pTrade, sizeof(CThostFtdcTradeField));
}

void CThostFtdcTraderSpiI::OnErrRtnOrderInsert(CThostFtdcInputOrderField *pInputOrder, CThostFtdcRspInfoField *pRspInfo) 
{
	///����¼�����ر�
    QUEUEPUSH(__FUNCTION__, pInputOrder, sizeof(CThostFtdcInputOrderField), pRspInfo);
}

void CThostFtdcTraderSpiI::OnErrRtnOrderAction(CThostFtdcOrderActionField *pOrderAction, CThostFtdcRspInfoField *pRspInfo) 
{
    QUEUEPUSH(__FUNCTION__, pOrderAction, sizeof(CThostFtdcOrderActionField), pRspInfo);
}

void CThostFtdcTraderSpiI::OnRtnInstrumentStatus(CThostFtdcInstrumentStatusField *pInstrumentStatus) 
{
	///��Լ����״̬֪ͨ
    QUEUEPUSH(__FUNCTION__, pInstrumentStatus, sizeof(CThostFtdcInstrumentStatusField));
}

void CThostFtdcTraderSpiI::OnRtnBulletin(CThostFtdcBulletinField *pBulletin) 
{
	///����������֪ͨ
    QUEUEPUSH(__FUNCTION__, pBulletin, sizeof(CThostFtdcBulletinField));
}

void CThostFtdcTraderSpiI::OnRtnTradingNotice(CThostFtdcTradingNoticeInfoField *pTradingNoticeInfo) 
{
	///����֪ͨ
    QUEUEPUSH(__FUNCTION__, pTradingNoticeInfo, sizeof(CThostFtdcTradingNoticeInfoField));
}

void CThostFtdcTraderSpiI::OnRtnErrorConditionalOrder(CThostFtdcErrorConditionalOrderField *pErrorConditionalOrder) 
{
	///��ʾ������У�����
    QUEUEPUSH(__FUNCTION__, pErrorConditionalOrder, sizeof(CThostFtdcErrorConditionalOrderField));
}

void CThostFtdcTraderSpiI::OnRtnExecOrder(CThostFtdcExecOrderField *pExecOrder) 
{
	///ִ������֪ͨ
    QUEUEPUSH(__FUNCTION__, pExecOrder, sizeof(CThostFtdcExecOrderField));
}

void CThostFtdcTraderSpiI::OnErrRtnExecOrderInsert(CThostFtdcInputExecOrderField *pInputExecOrder, CThostFtdcRspInfoField *pRspInfo) 
{
	///ִ������¼�����ر�
    QUEUEPUSH(__FUNCTION__, pInputExecOrder, sizeof(CThostFtdcInputExecOrderField), pRspInfo);
}

void CThostFtdcTraderSpiI::OnErrRtnExecOrderAction(CThostFtdcExecOrderActionField *pExecOrderAction, CThostFtdcRspInfoField *pRspInfo) 
{
	///ִ�������������ر�
    QUEUEPUSH(__FUNCTION__, pExecOrderAction, sizeof(CThostFtdcExecOrderActionField), pRspInfo);
}

void CThostFtdcTraderSpiI::OnErrRtnForQuoteInsert(CThostFtdcInputForQuoteField *pInputForQuote, CThostFtdcRspInfoField *pRspInfo) 
{
	///ѯ��¼�����ر�
    QUEUEPUSH(__FUNCTION__, pInputForQuote, sizeof(CThostFtdcInputForQuoteField), pRspInfo);
}

void CThostFtdcTraderSpiI::OnRtnQuote(CThostFtdcQuoteField *pQuote) 
{
	///����֪ͨ
    QUEUEPUSH(__FUNCTION__, pQuote, sizeof(CThostFtdcQuoteField));
}

void CThostFtdcTraderSpiI::OnErrRtnQuoteInsert(CThostFtdcInputQuoteField *pInputQuote, CThostFtdcRspInfoField *pRspInfo) 
{
	///����¼�����ر�
    QUEUEPUSH(__FUNCTION__, pInputQuote, sizeof(CThostFtdcInputQuoteField), pRspInfo);
}

void CThostFtdcTraderSpiI::OnErrRtnQuoteAction(CThostFtdcQuoteActionField *pQuoteAction, CThostFtdcRspInfoField *pRspInfo) 
{
	///���۲�������ر�
    QUEUEPUSH(__FUNCTION__, pQuoteAction, sizeof(CThostFtdcQuoteActionField), pRspInfo);
}

void CThostFtdcTraderSpiI::OnRtnForQuoteRsp(CThostFtdcForQuoteRspField *pForQuoteRsp) 
{
	///ѯ��֪ͨ
    QUEUEPUSH(__FUNCTION__, pForQuoteRsp, sizeof(CThostFtdcForQuoteRspField));
}

void CThostFtdcTraderSpiI::OnRtnCFMMCTradingAccountToken(CThostFtdcCFMMCTradingAccountTokenField *pCFMMCTradingAccountToken) 
{
	///��֤���������û�����
    QUEUEPUSH(__FUNCTION__, pCFMMCTradingAccountToken, sizeof(CThostFtdcCFMMCTradingAccountTokenField));
}

void CThostFtdcTraderSpiI::OnErrRtnBatchOrderAction(CThostFtdcBatchOrderActionField *pBatchOrderAction, CThostFtdcRspInfoField *pRspInfo) 
{
	///����������������ر�
    QUEUEPUSH(__FUNCTION__, pBatchOrderAction, sizeof(CThostFtdcBatchOrderActionField), pRspInfo);
}

void CThostFtdcTraderSpiI::OnRtnCombAction(CThostFtdcCombActionField *pCombAction) 
{	
	///�������֪ͨ
    QUEUEPUSH(__FUNCTION__, pCombAction, sizeof(CThostFtdcCombActionField));
}

void CThostFtdcTraderSpiI::OnErrRtnCombActionInsert(CThostFtdcInputCombActionField *pInputCombAction, CThostFtdcRspInfoField *pRspInfo) 
{
	///�������¼�����ر�
    QUEUEPUSH(__FUNCTION__, pInputCombAction, sizeof(CThostFtdcInputCombActionField), pRspInfo);
}

void CThostFtdcTraderSpiI::OnRspQryContractBank(CThostFtdcContractBankField *pContractBank, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	///�����ѯǩԼ������Ӧ
    QUEUEPUSH(__FUNCTION__, pContractBank, sizeof(CThostFtdcContractBankField), pRspInfo, nRequestID, bIsLast);
}

void CThostFtdcTraderSpiI::OnRspQryParkedOrder(CThostFtdcParkedOrderField *pParkedOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	///�����ѯԤ����Ӧ
    QUEUEPUSH(__FUNCTION__, pParkedOrder, sizeof(CThostFtdcParkedOrderField), pRspInfo, nRequestID, bIsLast);
}

void CThostFtdcTraderSpiI::OnRspQryParkedOrderAction(CThostFtdcParkedOrderActionField *pParkedOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	///�����ѯԤ�񳷵���Ӧ
    QUEUEPUSH(__FUNCTION__, pParkedOrderAction, sizeof(CThostFtdcParkedOrderActionField), pRspInfo, nRequestID, bIsLast);
}

void CThostFtdcTraderSpiI::OnRspQryTradingNotice(CThostFtdcTradingNoticeField *pTradingNotice, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	///�����ѯ����֪ͨ��Ӧ
    QUEUEPUSH(__FUNCTION__, pTradingNotice, sizeof(CThostFtdcTradingNoticeField), pRspInfo, nRequestID, bIsLast);
}

void CThostFtdcTraderSpiI::OnRspQryBrokerTradingParams(CThostFtdcBrokerTradingParamsField *pBrokerTradingParams, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	///�����ѯ���͹�˾���ײ�����Ӧ
    QUEUEPUSH(__FUNCTION__, pBrokerTradingParams, sizeof(CThostFtdcBrokerTradingParamsField), pRspInfo, nRequestID, bIsLast);
}

void CThostFtdcTraderSpiI::OnRspQryBrokerTradingAlgos(CThostFtdcBrokerTradingAlgosField *pBrokerTradingAlgos, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	///�����ѯ���͹�˾�����㷨��Ӧ
    QUEUEPUSH(__FUNCTION__, pBrokerTradingAlgos, sizeof(CThostFtdcBrokerTradingAlgosField), pRspInfo, nRequestID, bIsLast);
}

void CThostFtdcTraderSpiI::OnRspQueryCFMMCTradingAccountToken(CThostFtdcQueryCFMMCTradingAccountTokenField *pQueryCFMMCTradingAccountToken, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	///�����ѯ��������û�����
    QUEUEPUSH(__FUNCTION__, pQueryCFMMCTradingAccountToken, sizeof(CThostFtdcQueryCFMMCTradingAccountTokenField), pRspInfo, nRequestID, bIsLast);
}

void CThostFtdcTraderSpiI::OnRtnFromBankToFutureByBank(CThostFtdcRspTransferField *pRspTransfer) 
{
	///���з��������ʽ�ת�ڻ�֪ͨ
    QUEUEPUSH(__FUNCTION__, pRspTransfer, sizeof(CThostFtdcRspTransferField));
}

void CThostFtdcTraderSpiI::OnRtnFromFutureToBankByBank(CThostFtdcRspTransferField *pRspTransfer) 
{
	///���з����ڻ��ʽ�ת����֪ͨ
    QUEUEPUSH(__FUNCTION__, pRspTransfer, sizeof(CThostFtdcRspTransferField));
}

void CThostFtdcTraderSpiI::OnRtnRepealFromBankToFutureByBank(CThostFtdcRspRepealField *pRspRepeal) 
{
    QUEUEPUSH(__FUNCTION__, pRspRepeal, sizeof(CThostFtdcRspRepealField));
	///���з����������ת�ڻ�֪ͨ
}

void CThostFtdcTraderSpiI::OnRtnRepealFromFutureToBankByBank(CThostFtdcRspRepealField *pRspRepeal) 
{
	///���з�������ڻ�ת����֪ͨ
    QUEUEPUSH(__FUNCTION__, pRspRepeal, sizeof(CThostFtdcRspRepealField));
}

void CThostFtdcTraderSpiI::OnRtnFromBankToFutureByFuture(CThostFtdcRspTransferField *pRspTransfer)
{
	///�ڻ����������ʽ�ת�ڻ�֪ͨ
    QUEUEPUSH(__FUNCTION__, pRspTransfer, sizeof(CThostFtdcRspTransferField));
}

void CThostFtdcTraderSpiI::OnRtnFromFutureToBankByFuture(CThostFtdcRspTransferField *pRspTransfer)
{
	///�ڻ������ڻ��ʽ�ת����֪ͨ
    QUEUEPUSH(__FUNCTION__, pRspTransfer, sizeof(CThostFtdcRspTransferField));
}

void CThostFtdcTraderSpiI::OnRtnRepealFromBankToFutureByFutureManual(CThostFtdcRspRepealField *pRspRepeal)
{
	///ϵͳ����ʱ�ڻ����ֹ������������ת�ڻ��������д�����Ϻ��̷��ص�֪ͨ
    QUEUEPUSH(__FUNCTION__, pRspRepeal, sizeof(CThostFtdcRspRepealField));
}

void CThostFtdcTraderSpiI::OnRtnRepealFromFutureToBankByFutureManual(CThostFtdcRspRepealField *pRspRepeal) 
{
	///ϵͳ����ʱ�ڻ����ֹ���������ڻ�ת�����������д�����Ϻ��̷��ص�֪ͨ
    QUEUEPUSH(__FUNCTION__, pRspRepeal, sizeof(CThostFtdcRspRepealField));
}

void CThostFtdcTraderSpiI::OnRtnQueryBankBalanceByFuture(CThostFtdcNotifyQueryAccountField *pNotifyQueryAccount) 
{
	///�ڻ������ѯ�������֪ͨ
    QUEUEPUSH(__FUNCTION__, pNotifyQueryAccount, sizeof(CThostFtdcNotifyQueryAccountField));
}

void CThostFtdcTraderSpiI::OnErrRtnBankToFutureByFuture(CThostFtdcReqTransferField *pReqTransfer, CThostFtdcRspInfoField *pRspInfo) 
{
	///�ڻ����������ʽ�ת�ڻ�����ر�
    QUEUEPUSH(__FUNCTION__, pReqTransfer, sizeof(CThostFtdcReqTransferField), pRspInfo);
}

void CThostFtdcTraderSpiI::OnErrRtnFutureToBankByFuture(CThostFtdcReqTransferField *pReqTransfer, CThostFtdcRspInfoField *pRspInfo) 
{
	///�ڻ������ڻ��ʽ�ת���д���ر�
    QUEUEPUSH(__FUNCTION__, pReqTransfer, sizeof(CThostFtdcReqTransferField), pRspInfo);
}

void CThostFtdcTraderSpiI::OnErrRtnRepealBankToFutureByFutureManual(CThostFtdcReqRepealField *pReqRepeal, CThostFtdcRspInfoField *pRspInfo) 
{
	///ϵͳ����ʱ�ڻ����ֹ������������ת�ڻ�����ر�
    QUEUEPUSH(__FUNCTION__, pReqRepeal, sizeof(CThostFtdcReqRepealField), pRspInfo);
}

void CThostFtdcTraderSpiI::OnErrRtnRepealFutureToBankByFutureManual(CThostFtdcReqRepealField *pReqRepeal, CThostFtdcRspInfoField *pRspInfo) 
{
	///ϵͳ����ʱ�ڻ����ֹ���������ڻ�ת���д���ر�
    QUEUEPUSH(__FUNCTION__, pReqRepeal, sizeof(CThostFtdcReqRepealField), pRspInfo);
}

void CThostFtdcTraderSpiI::OnErrRtnQueryBankBalanceByFuture(CThostFtdcReqQueryAccountField *pReqQueryAccount, CThostFtdcRspInfoField *pRspInfo) 
{
	///�ڻ������ѯ����������ر�
    QUEUEPUSH(__FUNCTION__, pReqQueryAccount, sizeof(CThostFtdcReqQueryAccountField), pRspInfo);
}

void CThostFtdcTraderSpiI::OnRtnRepealFromBankToFutureByFuture(CThostFtdcRspRepealField *pRspRepeal) 
{
	///�ڻ������������ת�ڻ��������д�����Ϻ��̷��ص�֪ͨ
    QUEUEPUSH(__FUNCTION__, pRspRepeal, sizeof(CThostFtdcRspRepealField));
}

void CThostFtdcTraderSpiI::OnRtnRepealFromFutureToBankByFuture(CThostFtdcRspRepealField *pRspRepeal) 
{
	///�ڻ���������ڻ�ת�����������д�����Ϻ��̷��ص�֪ͨ
    QUEUEPUSH(__FUNCTION__, pRspRepeal, sizeof(CThostFtdcRspRepealField));
}

void CThostFtdcTraderSpiI::OnRspFromBankToFutureByFuture(CThostFtdcReqTransferField *pReqTransfer, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	///�ڻ����������ʽ�ת�ڻ�Ӧ��
    QUEUEPUSH(__FUNCTION__, pReqTransfer, sizeof(CThostFtdcReqTransferField), pRspInfo, nRequestID, bIsLast);
}

void CThostFtdcTraderSpiI::OnRspFromFutureToBankByFuture(CThostFtdcReqTransferField *pReqTransfer, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	///�ڻ������ڻ��ʽ�ת����Ӧ��
    QUEUEPUSH(__FUNCTION__, pReqTransfer, sizeof(CThostFtdcReqTransferField), pRspInfo, nRequestID, bIsLast);
}

void CThostFtdcTraderSpiI::OnRspQueryBankAccountMoneyByFuture(CThostFtdcReqQueryAccountField *pReqQueryAccount, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
	///�ڻ������ѯ�������Ӧ��
    QUEUEPUSH(__FUNCTION__, pReqQueryAccount, sizeof(CThostFtdcReqQueryAccountField), pRspInfo, nRequestID, bIsLast);
}

void CThostFtdcTraderSpiI::OnRtnOpenAccountByBank(CThostFtdcOpenAccountField *pOpenAccount) 
{
	///���з������ڿ���֪ͨ
    QUEUEPUSH(__FUNCTION__, pOpenAccount, sizeof(CThostFtdcOpenAccountField));
}

void CThostFtdcTraderSpiI::OnRtnCancelAccountByBank(CThostFtdcCancelAccountField *pCancelAccount)
{
	///���з�����������֪ͨ
    QUEUEPUSH(__FUNCTION__, pCancelAccount, sizeof(CThostFtdcCancelAccountField));
}

void CThostFtdcTraderSpiI::OnRtnChangeAccountByBank(CThostFtdcChangeAccountField *pChangeAccount)
{	
	///���з����������˺�֪ͨ
    QUEUEPUSH(__FUNCTION__, pChangeAccount, sizeof(CThostFtdcChangeAccountField));
}

}



