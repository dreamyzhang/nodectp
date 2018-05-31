//process.env.PATH += ';D:\\nodectp\\20180109_tradeapi64_windows'
//console.log(process.env.PATH)
var ctp = require('bindings')('shifctp');

var mduser = ctp.crmd();
var login = Object()
//login.BrokerID = "4040";
//login.UserID = "369658";
//login.Password = "123456";
//var url = "tcp://180.166.125.146:41213"

login.BrokerID = "4500";
login.UserID = "8010800705";
login.Password = "J105828.";
var url = 'tcp://180.166.45.116:41213'

//var instrucments = ['IC1703', 'IC1706', 'IF1703', 'IF1706', 'IH1703', 'IH1706', 'T1706', 'T1709', 'TF1706', 'TF1709', 'CF705', 'CF709', 'FG705', 'FG709', 'JR703', 'JR711', 'LR703', 'LR705', 'MA705', 'MA709', 'OI705', 'OI709', 'PM703', 'PM705', 'RI703', 'RI709', 'RM705', 'RM709', 'RS707', 'RS708', 'SF705', 'SF801', 'SM705', 'SM709', 'SR705', 'SR709', 'TA705', 'TA709', 'WH705', 'WH709', 'ZC705', 'ZC709', 'a1705', 'a1709', 'b1703', 'b1705', 'bb1703', 'bb1704', 'c1705', 'c1709', 'cs1705', 'cs1709', 'fb1703', 'fb1709', 'i1705', 'i1709', 'j1705', 'j1709', 'jd1705', 'jd1709', 'jm1705', 'jm1709', 'l1705', 'l1709', 'm1705', 'm1709', 'p1705', 'p1709', 'pp1705', 'pp1709', 'v1705', 'v1709', 'y1705', 'y1709', 'ag1706', 'ag1712', 'al1704', 'al1705', 'au1706', 'au1712', 'bu1706', 'bu1709', 'cu1704', 'cu1705', 'fu1704', 'fu1705', 'hc1705', 'hc1710', 'ni1705', 'ni1709', 'pb1704', 'pb1705', 'rb1705', 'rb1710', 'ru1705', 'ru1709', 'sn1705', 'sn1709', 'wr1703', 'wr1712', 'zn1704', 'zn1705'];

var instrucments = ["i1703", "bu1703", "bu1706", "fu1705", "v1704", "FG704", "MA704", "SF704", "SM704", "TA704", "a1703", "SR703", "bu1709", "ZC703", "cu1703", "hc1703", "ni1703", "pb1703", "a1707", "SR707", "a1705", "SR705", "j1703", "jd1703", "jm1703", "l1703", "m1703", "p1703", "pp1703", "v1703", "y1703", "CF703", "FG703", "JR703", "rb1703", "ru1703", "sn1703", "wr1703", "zn1703", "ag1703", "al1703", "au1704", "bu1803", "LR703", "MA703", "OI703", "PM703", "RI703", "RM703", "SF703", "SM703", "SR709", "TA703", "WH703", "a1709", "b1703", "bb1703", "c1703", "cs1703", "fb1703", "bu1712", "fu1704", "ZC704", "ag1704", "al1704", "cu1704", "hc1704", "ni1704", "pb1704", "rb1704", "ru1704", "sn1704", "wr1704", "zn1704", "bb1704", "fb1704", "i1704", "j1704", "jd1704", "jm1704", "l1704", "p1704", "pp1704", "T1703", "TF1703", "bb1706", "fb1706", "i1706", "j1706", "jd1706", "jm1706", "l1706", "p1706", "pp1706", "v1706", "FG706", "MA706", "SF706", "SM706", "TA706", "fu1706", "ZC706", "ag1706", "al1706", "bu1806", "cu1706", "hc1706", "ni1706", "pb1706", "rb1706", "ru1706", "sn1706", "wr1706", "zn1706", "ag1705", "al1705", "au1706", "cu1705", "hc1705", "ni1705", "pb1705", "rb1705", "ru1705", "sn1705", "wr1705", "zn1705", "a1711", "b1705", "bb1705", "c1705", "cs1705", "fb1705", "i1705", "j1705", "jd1705", "jm1705", "l1705", "m1705", "p1705", "pp1705", "v1705", "y1705", "CF705", "FG705", "JR705", "LR705", "MA705", "OI705", "PM705", "RI705", "RM705", "SF705", "SM705", "SR711", "TA705", "WH705", "ZC705", "fu1707", "ZC707", "a1801", "b1707", "bb1707", "c1707", "cs1707", "fb1707", "i1707", "j1707", "jd1707", "jm1707", "l1707", "m1707", "p1707", "pp1707", "v1707", "y1707", "CF707", "FG707", "JR707", "LR707", "MA707", "OI707", "PM707", "RI707", "RM707", "RS707", "SF707", "SM707", "SR801", "TA707", "WH707", "ag1707", "al1707", "au1708", "cu1707", "hc1707", "ni1707", "pb1707", "rb1707", "ru1707", "sn1707", "wr1707", "zn1707", "IC1703", "IF1703", "IH1703", "fu1708", "ZC708", "bb1708", "fb1708", "i1708", "j1708", "jd1708", "jm1708", "l1708", "m1708", "p1708", "pp1708", "v1708", "y1708", "FG708", "MA708", "RM708", "RS708", "SF708", "SM708", "ru1708", "sn1708", "wr1708", "zn1708", "ag1708", "al1708", "cu1708", "hc1708", "ni1708", "pb1708", "rb1708", "TA708", "fu1709", "ZC709", "TF1706", "T1706", "SR803", "CF709", "TA709", "LR709", "bb1709", "y1709", "FG709", "JR709", "OI709", "PM709", "RM709", "SF709", "a1803", "b1709", "c1709", "RS709", "WH709", "cs1709", "fb1709", "i1709", "j1709", "jd1709", "jm1709", "l1709", "m1709", "p1709", "v1709", "MA709", "SM709", "pp1709", "RI709", "zn1709", "bu1809", "cu1709", "hc1709", "ni1709", "pb1709", "rb1709", "ru1709", "ag1709", "al1709", "au1710", "sn1709", "wr1709", "fu1710", "ZC710", "ag1710", "al1710", "bu1704", "cu1710", "hc1710", "ni1710", "pb1710", "rb1710", "ru1710", "sn1710", "wr1710", "zn1710", "T1709", "FG710", "MA710", "SF710", "SM710", "TA710", "IC1706", "IF1706", "IH1706", "bb1710", "fb1710", "i1710", "j1710", "jd1710", "jm1710", "l1710", "p1710", "pp1710", "v1710", "fu1711", "ZC711", "a1805", "b1711", "bb1711", "c1711", "cs1711", "fb1711", "i1711", "j1711", "jd1711", "jm1711", "l1711", "m1711", "p1711", "pp1711", "CF711", "v1711", "y1711", "FG711", "JR711", "LR711", "MA711", "OI711", "PM711", "RI711", "RM711", "RS711", "SF711", "SM711", "SR805", "TA711", "WH711", "ag1711", "al1711", "au1712", "bu1705", "cu1711", "hc1711", "ni1711", "pb1711", "rb1711", "ru1711", "sn1711", "wr1711", "zn1711", "fu1712", "ZC712", "TF1709", "SF712", "SM712", "TA712", "bb1712", "fb1712", "p1712", "pp1712", "y1712", "j1712", "FG712", "i1712", "jd1712", "jm1712", "l1712", "m1712", "v1712", "MA712", "cu1712", "hc1712", "ni1712", "wr1712", "zn1712", "bu1812", "al1712", "pb1712", "ag1712", "rb1712", "sn1712", "au1703", "fu1801", "ZC801", "wr1801", "SF801", "WH801", "a1807", "b1801", "bb1801", "c1801", "cs1801", "jd1801", "jm1801", "p1801", "y1801", "ag1801", "bu1707", "SM801", "SR807", "CF801", "FG801", "JR801", "pb1801", "ru1801", "RI801", "TA801", "fb1801", "i1801", "j1801", "v1801", "al1801", "ni1801", "rb1801", "sn1801", "zn1801", "au1802", "LR801", "MA801", "OI801", "PM801", "RM801", "l1801", "m1801", "pp1801", "cu1801", "hc1801", "IH1709", "IF1709", "IC1709", "ZC802", "ag1802", "al1802", "ni1802", "cu1802", "hc1802", "pb1802", "rb1802", "sn1802", "zn1802", "au1705", "wr1802", "bu1708", "i1802", "jd1802", "l1802", "p1802", "MA802", "SM802", "fb1802", "bb1802", "j1802", "jm1802", "FG802", "TA802", "SF802", "pp1802", "v1802", "IC1704", "IF1704", "IH1704", "fu1803"];
mduser.CreateFtdcMdApi('./data/md/');

mduser.On("OnFrontConnected", function(){
    console.log("login : ", mduser.ReqUserLogin(login, (new Date()).valueOf()/1000))
    console.log("OnFrontConnected")
});

mduser.On("OnFrontDisconnected", function(nReason){
    console.log("OnFrontDisconnected nReason:", nReason)
});

mduser.On("OnHeartBeatWarning", function(nTimeLapse){
    console.log("OnHeartBeatWarning nTimeLapse:", nTimeLapse)
});

mduser.On("OnRspUserLogin", function(Login, Rsp, nRequestID, bIsLast){
    console.log("OnRspUserLogin", Login, Rsp, nRequestID, bIsLast);
    console.log("subscribe:", mduser.SubscribeMarketData(instrucments));
});

mduser.On("OnRspUserLogout", function(Logout, Rsp, nRequestID,bIsLast){
    console.log("OnRspUserLogout:", Logout, Rsp, nRequestID, bIsLast)
});

mduser.On("OnRspError", function(Rsp, nRequestID, bIsLast){
    console.log("OnRspError:",  Rsp, nRequestID, bIsLast)
});

mduser.On("OnRspSubMarketData", function(Instrument, Rsp, nRequestID, bIsLast){
    console.log("OnRspSubMarketData:", Instrument, Rsp, nRequestID, bIsLast)
});

mduser.On("OnRspUnSubMarketData", function(Instrument, Rsp, nRequestID, bIsLast){
    console.log("OnRspSubMarketData:", Instrument, Rsp, nRequestID, bIsLast)
});

mduser.On("OnRspSubForQuoteRsp", function(Instrument, Rsp, nRequestID, bIsLast){
    console.log("OnRspSubForQuoteRsp:", Instrument, Rsp, nRequestID, bIsLast)
});

mduser.On("OnRspUnSubForQuoteRsp", function(Instrument, Rsp, nRequestID, bIsLast){
    console.log("OnRspUnSubForQuoteRsp:", Instrument, Rsp, nRequestID, bIsLast)
});

mduser.On("OnRtnDepthMarketData", function(data){
    console.log("OnRtnDepthMarketData:", data)
});

mduser.On("OnRtnForQuoteRsp", function(data){
    console.log("OnRtnDepthMarketData:", data)
});

console.log("version : ", mduser.GetApiVersion());
mduser.RegisterFront(url)
mduser.Init()


