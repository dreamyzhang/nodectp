var ctp = require('bindings')('shifctp');
var tduser = ctp.crtd();
var login = Object()
    login.BrokerID = "4040";
    login.UserID = "369658";
    login.Password = "123456";
var q = Object()
    q.BrokerID =  "4040"
    q.InvestorID = "123456"

function sleep(milliSeconds){
    var startTime = new Date().getTime(); 
    while (new Date().getTime() < startTime + milliSeconds);
};

tduser.CreateFtdcTraderApi('./data/td/');

tduser.On("OnFrontConnected", function(){
    console.log("login : ", tduser.ReqUserLogin(login, (new Date()).valueOf()/1000))
    console.log("OnFrontConnected")
});

tduser.On("OnFrontDisconnected", function(nReason){
    console.log("OnFrontDisconnected nReason:", nReason)
});

tduser.On("OnHeartBeatWarning", function(nTimeLapse){
    console.log("OnHeartBeatWarning nTimeLapse:", nTimeLapse)
});

tduser.On("OnRspUserLogin", function(Login, Rsp, nRequestID, bIsLast){
    console.log("OnRspUserLogin", Login, Rsp, nRequestID, bIsLast);
    //console.log("ReqQryTradingAccount=", tduser.ReqQryTradingAccount(q, (new Date()).valueOf()/1000));
    //sleep(2000);
    //console.log("ReqQryInvestorPosition=", tduser.ReqQryInvestorPosition(q, (new Date()).valueOf()/1000));
    //console.log("ReqQryTrade=", tduser.ReqQryTrade(q, (new Date()).valueOf()/1000));
    //console.log("ReqQryOrder=", tduser.ReqQryOrder(q, (new Date()).valueOf()/1000));
    //console.log("ReqQryProduct=", tduser.ReqQryProduct(q, (new Date()).valueOf()/1000));
    //console.log("ReqQryInstrument=", tduser.ReqQryInstrument(q, (new Date()).valueOf()/1000));
});

tduser.On("OnRspUserLogout", function(Logout, Rsp, nRequestID,bIsLast){
    console.log("OnRspUserLogout:", Logout, Rsp, nRequestID, bIsLast)
});

tduser.On("OnRspError", function(Rsp, nRequestID, bIsLast){
    console.log("OnRspError:",  Rsp, nRequestID, bIsLast)
});

tduser.On("OnRtnOrder", function(data){
    console.log("OnRtnOrder:",  data)
});

tduser.On("OnRspQryOrder", function(data, Rsp, nRequestID, bIsLast){
    console.log("OnRspQryOrder:",  data, Rsp, nRequestID, bIsLast)
});

tduser.On("OnRspQryTrade", function(data, Rsp, nRequestID, bIsLast){
        console.log("OnRspQryTrade:", data,  Rsp, nRequestID, bIsLast)

});

tduser.On("OnRspQryTradingAccount", function(data, Rsp, nRequestID, bIsLast){
    console.log("OnRspQryTradingAccount:", data,  Rsp, nRequestID, bIsLast)
});

tduser.On("OnRspQryInvestorPosition", function(data, Rsp, nRequestID, bIsLast){
    console.log("OnRspQryInvestorPosition:", data,  Rsp, nRequestID, bIsLast)
});

tduser.On("OnRspQryProduct", function(data, Rsp, nRequestID, bIsLast){
    console.log("OnRspQryProduct:", data,  Rsp, nRequestID, bIsLast)
});

tduser.On("OnRspQryInstrument", function(data, Rsp, nRequestID, bIsLast){
    console.log("OnRspQryInstrument:", data,  Rsp, nRequestID, bIsLast)
});

tduser.On("OnRspOrderInsert", function(data, Rsp, nRequestID, bIsLast){
    console.log("OnRspOrderInsert(下单回调):", data,  Rsp, nRequestID, bIsLast)
});

tduser.On("OnErrRtnOrderInsert", function(data, Rsp){
    console.log("OnErrRtnOrderInsert(下单错误回调):", data,  Rsp)
});

tduser.On("OnRspOrderAction", function(data, Rsp, nRequestID, bIsLast){
    console.log("OnRspOrderAction(撤单回调):", data,  Rsp, nRequestID, bIsLast)
});

tduser.On("OnErrRtnOrderAction", function(data, Rsp, nRequestID, bIsLast){
    console.log("OnErrRtnOrderAction(撤单错误回调):", data,  Rsp, nRequestID, bIsLast)
});

console.log("version : ", tduser.GetApiVersion());
tduser.RegisterFront("tcp://180.166.103.21:51205");
//THOST_TERT_RESTART:从本交易日开始重传 0
//THOST_TERT_RESUME:从上次收到的续传    1
//THOST_TERT_QUICK:只传送登录后私有流的内容 2
tduser.SubscribePrivateTopic(2);
tduser.SubscribePublicTopic(2);
tduser.Init();



