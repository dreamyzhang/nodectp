{
  "targets": [
    {
      "target_name": "shifctp",
      "sources": [ "src/shifctp.cpp",  "src/ThostFtdcMdSpiI.cpp", "src/WrapMd.cpp",  "src/ThostFtdcTraderSpiI.cpp", "src/WrapTd.cpp"],
      "libraries":["/home/nodectp/linux_api_trade_6.3.6/thostmduserapi.so", "/home/nodectp/linux_api_trade_6.3.6/thosttraderapi.so"],
      "include_dirs":["linux_api_trade_6.3.6", "src"]
    }
  ],
}


