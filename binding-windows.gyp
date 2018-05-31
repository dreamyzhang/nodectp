{
  "targets": [
    {
      "target_name": "shifctp",
      "sources": [ "src/shifctp.cpp",  "src/ThostFtdcMdSpiI.cpp", "src/WrapMd.cpp",  "src/ThostFtdcTraderSpiI.cpp", "src/WrapTd.cpp"],
      "libraries":["../20180109_tradeapi64_windows/thostmduserapi.lib", "../20180109_tradeapi64_windows/thosttraderapi.lib"],
      "include_dirs":["20180109_tradeapi64_windows", "src"]
    }
  ],
}


