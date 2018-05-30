{
  "targets": [
    {
      "target_name": "shifctp",
      "sources": [ "src/shifctp.cpp",  "src/ThostFtdcMdSpiI.cpp", "src/WrapMd.cpp",  "src/ThostFtdcTraderSpiI.cpp", "src/WrapTd.cpp"],
      "libraries":["$(CURDIR)/../v6.3.11_20180109_api_tradeapi_linux64/thostmduserapi.so", "$(CURDIR)/../v6.3.11_20180109_api_tradeapi_linux64/thosttraderapi.so"],
      "include_dirs":["v6.3.11_20180109_api_tradeapi_linux64", "src"]
    }
  ],
}


