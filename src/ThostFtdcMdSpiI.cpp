/////////////////////////////////////////////////////////////////////////
///@system ctp行情nodejs addon
///@company 慧网基金
///@file ThostFtdcMdApiSpiI.cpp
///@brief 定义了ctp线程及回调
///@history 
///20160326	dreamyzhang		创建该文件
/////////////////////////////////////////////////////////////////////////

#include "ThostFtdcMdSpiI.h"

namespace md
{

CThostFtdcMdSpiI::CThostFtdcMdSpiI()
{
    uv_async_init(uv_default_loop(),&async_t,NULL);
    m_pApi = CThostFtdcMdApi::CreateFtdcMdApi();
    m_pApi->RegisterSpi(this);         
}

CThostFtdcMdSpiI::~CThostFtdcMdSpiI()
{
    m_pApi->RegisterSpi(NULL);
    m_pApi->Release();
    m_pApi = NULL;
    uv_close((uv_handle_t*)&async_t,NULL);
}

void CThostFtdcMdSpiI::_on_completed(uv_work_t * work, int status)
{
    //调用js中的回调函数 在初始化的时候注册的
    taskdata* task = (taskdata*)work->data;
    do{
    if(task->api == "OnRtnDepthMarketData") { task->pmd->MainOnRtnDepthMarketData(&task->data.DepthMarketData); continue;}
    else if(task->api == "OnRtnForQuoteRsp") { task->pmd->MainOnRtnForQuoteRsp(&task->data.ForQuoteRsp); continue;}
    else if(task->api == "OnFrontConnected") { task->pmd->MainOnFrontConnected(); continue;}
    else if(task->api == "OnFrontDisconnected") { task->pmd->MainOnFrontDisconnected(task->data.nReason); continue;}
    else if(task->api == "OnHeartBeatWarning") { task->pmd->MainOnHeartBeatWarning(task->data.nTimeLapse); continue;}
    else if(task->api == "OnRspUserLogin") { task->pmd->MainOnRspUserLogin(&task->data.RspUserLogin, &task->RspInfo, task->nRequestID, task->bIsLast); continue;}
    else if(task->api == "OnRspUserLogout") { task->pmd->MainOnRspUserLogout(&task->data.UserLogout, &task->RspInfo, task->nRequestID, task->bIsLast); continue;}
    else if(task->api == "OnRspError") { task->pmd->MainOnRspError(&task->RspInfo, task->nRequestID, task->bIsLast); continue;}
    else if(task->api == "OnRspSubMarketData") { task->pmd->MainOnRspSubMarketData(&task->data.SpecificInstrument, &task->RspInfo, task->nRequestID, task->bIsLast); continue;}
    else if(task->api == "OnRspUnSubMarketData") { task->pmd->MainOnRspUnSubMarketData(&task->data.SpecificInstrument,&task->RspInfo, task->nRequestID, task->bIsLast); continue;}
    else if(task->api == "OnRspSubForQuoteRsp") { task->pmd->MainOnRspSubForQuoteRsp(&task->data.SpecificInstrument, &task->RspInfo, task->nRequestID, task->bIsLast); continue;}
    else if(task->api == "OnRspUnSubForQuoteRsp") { task->pmd->MainOnRspUnSubForQuoteRsp(&task->data.SpecificInstrument, &task->RspInfo, task->nRequestID, task->bIsLast); continue;}
    else {printf("ERROR:%s _on_completed\n", task->api.c_str());}
    }while(0);
    delete task; 
}

void CThostFtdcMdSpiI::_on_async_queue(uv_work_t * work)
{
    uv_async_send(&((taskdata*)work->data)->pmd->async_t);
}

/////////////////////////////on回调函数///////////////////////////////////////////////////////////
void CThostFtdcMdSpiI::OnFrontConnected()
{
    taskdata* t = new taskdata(this);
    t->api = "OnFrontConnected";
    uv_queue_work(uv_default_loop(), &t->work, _on_async_queue, _on_completed);
}

void CThostFtdcMdSpiI::OnFrontDisconnected(int nReason)
{
    taskdata* t = new taskdata(this);
    t->api = "OnFrontDisconnected";
    t->data.nReason = nReason;
    uv_queue_work(uv_default_loop(), &t->work, _on_async_queue, _on_completed);
}

void CThostFtdcMdSpiI::OnHeartBeatWarning(int nTimeLapse)
{
    taskdata* t = new taskdata(this);
    t->api = "OnHeartBeatWarning";
    t->data.nTimeLapse = nTimeLapse;
    uv_queue_work(uv_default_loop(), &t->work, _on_async_queue, _on_completed);
}

void CThostFtdcMdSpiI::OnRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
    taskdata* t = new taskdata(this);
    t->api = "OnRspUserLogin";
    t->data.RspUserLogin = *pRspUserLogin;
    t->RspInfo = *pRspInfo;
    t->nRequestID = nRequestID;
    t->bIsLast = bIsLast;
    uv_queue_work(uv_default_loop(), &t->work, _on_async_queue, _on_completed);
}

void CThostFtdcMdSpiI::OnRspUserLogout(CThostFtdcUserLogoutField *pUserLogout, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
    taskdata* t = new taskdata(this);
    t->api = "OnRspUserLogout";
    t->data.UserLogout = *pUserLogout;
    t->RspInfo = *pRspInfo;
    t->nRequestID = nRequestID;
    t->bIsLast = bIsLast;
    uv_queue_work(uv_default_loop(), &t->work, _on_async_queue, _on_completed);
}

void CThostFtdcMdSpiI::OnRspError(CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
    taskdata* t = new taskdata(this);
    t->api = "OnRspError";
    t->RspInfo = *pRspInfo;
    t->nRequestID = nRequestID;
    t->bIsLast = bIsLast;
    uv_queue_work(uv_default_loop(), &t->work, _on_async_queue, _on_completed);
}

void CThostFtdcMdSpiI::OnRspSubMarketData(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
    taskdata* t = new taskdata(this);
    t->api = "OnRspSubMarketData";
    t->data.SpecificInstrument = *pSpecificInstrument;
    t->RspInfo = *pRspInfo;
    t->nRequestID = nRequestID;
    t->bIsLast = bIsLast;
    uv_queue_work(uv_default_loop(), &t->work, _on_async_queue, _on_completed);
}

void CThostFtdcMdSpiI::OnRspUnSubMarketData(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
    taskdata* t = new taskdata(this);
    t->api = "OnRspUnSubMarketData";
    t->data.SpecificInstrument = *pSpecificInstrument;
    t->RspInfo = *pRspInfo;
    t->nRequestID = nRequestID;
    t->bIsLast = bIsLast;
    uv_queue_work(uv_default_loop(), &t->work, _on_async_queue, _on_completed);
}

void CThostFtdcMdSpiI::OnRspSubForQuoteRsp(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
    taskdata* t = new taskdata(this);
    t->api = "OnRspSubForQuoteRsp";
    t->data.SpecificInstrument = *pSpecificInstrument;
    t->RspInfo = *pRspInfo;
    t->nRequestID = nRequestID;
    t->bIsLast = bIsLast;
    uv_queue_work(uv_default_loop(), &t->work, _on_async_queue, _on_completed);
}

void CThostFtdcMdSpiI::OnRspUnSubForQuoteRsp(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) 
{
    taskdata* t = new taskdata(this);
    t->api = "OnRspUnSubForQuoteRsp";
    t->data.SpecificInstrument = *pSpecificInstrument;
    t->RspInfo = *pRspInfo;
    t->nRequestID = nRequestID;
    t->bIsLast = bIsLast;
    uv_queue_work(uv_default_loop(), &t->work, _on_async_queue, _on_completed);
}   

void CThostFtdcMdSpiI::OnRtnDepthMarketData(CThostFtdcDepthMarketDataField *pDepthMarketData) 
{
    taskdata* t = new taskdata(this);
    t->api = "OnRtnDepthMarketData";
    t->data.DepthMarketData = *pDepthMarketData;
    uv_queue_work(uv_default_loop(), &t->work, _on_async_queue, _on_completed);
}

void CThostFtdcMdSpiI::OnRtnForQuoteRsp(CThostFtdcForQuoteRspField *pForQuoteRsp) 
{
    taskdata* t = new taskdata(this);
    t->api = "OnRtnForQuoteRsp";
    t->data.ForQuoteRsp = *pForQuoteRsp;
    uv_queue_work(uv_default_loop(), &t->work, _on_async_queue, _on_completed);
}

}


