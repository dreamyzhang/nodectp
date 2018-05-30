{
  "targets": [
    {
      "target_name": "shifctp",
      "sources": [ "src/shifctp.cpp",  "src/ThostFtdcMdSpiI.cpp", "src/WrapMd.cpp",  "src/ThostFtdcTraderSpiI.cpp", "src/WrapTd.cpp"],
      "libraries":["$(CURDIR)/../20180109_tradeapi64_windows/thostmduserapi.so", "$(CURDIR)/../20180109_tradeapi64_windows/thosttraderapi.so"],
      "include_dirs":["20180109_tradeapi64_windows", "src"]
    }
  ],
}


