/////////////////////////////////////////////////////////////////////////
///@system 新一代交易所系统
///@company 上海期货信息技术有限公司
///@file ThostFtdcUserApiStruct.h
///@brief 定义了客户端接口使用的业务数据结构
///@history 
///20060106	赵鸿昊		创建该文件
/////////////////////////////////////////////////////////////////////////

#if !defined(THOST_FTDCSTRUCT_H)
#define THOST_FTDCSTRUCT_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ThostFtdcUserApiDataType.h"

///信息分发
struct CThostFtdcDisseminationField
{
	///序列系列号
	TThostFtdcSequenceSeriesType	SequenceSeries;
	///序列号
	int	SequenceNo;
};

///用户登录请求
struct CThostFtdcReqUserLoginField
{
	///交易日
	TThostFtdcDateType	TradingDay;
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///用户代码
	TThostFtdcUserIDType	UserID;
	///密码
	TThostFtdcPasswordType	Password;
	///用户端产品信息
	TThostFtdcProductInfoType	UserProductInfo;
	///接口端产品信息
	TThostFtdcProductInfoType	InterfaceProductInfo;
	///协议信息
	TThostFtdcProtocolInfoType	ProtocolInfo;
	///Mac地址
	TThostFtdcMacAddressType	MacAddress;
	///动态密码
	TThostFtdcPasswordType	OneTimePassword;
	///终端IP地址
	TThostFtdcIPAddressType	ClientIPAddress;
	///登录备注
	TThostFtdcLoginRemarkType	LoginRemark;
};

///用户登录应答
struct CThostFtdcRspUserLoginField
{
	///交易日
	TThostFtdcDateType	TradingDay;
	///登录成功时间
	TThostFtdcTimeType	LoginTime;
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///用户代码
	TThostFtdcUserIDType	UserID;
	///交易系统名称
	TThostFtdcSystemNameType	SystemName;
	///前置编号
	int	FrontID;
	///会话编号
	int	SessionID;
	///最大报单引用
	TThostFtdcOrderRefType	MaxOrderRef;
	///上期所时间
	TThostFtdcTimeType	SHFETime;
	///大商所时间
	TThostFtdcTimeType	DCETime;
	///郑商所时间
	TThostFtdcTimeType	CZCETime;
	///中金所时间
	TThostFtdcTimeType	FFEXTime;
	///能源中心时间
	TThostFtdcTimeType	INETime;
};

///用户登出请求
struct CThostFtdcUserLogoutField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///用户代码
	TThostFtdcUserIDType	UserID;
};

///强制交易员退出
struct CThostFtdcForceUserLogoutField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///用户代码
	TThostFtdcUserIDType	UserID;
};

///客户端认证请求
struct CThostFtdcReqAuthenticateField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///用户代码
	TThostFtdcUserIDType	UserID;
	///用户端产品信息
	TThostFtdcProductInfoType	UserProductInfo;
	///认证码
	TThostFtdcAuthCodeType	AuthCode;
};

///客户端认证响应
struct CThostFtdcRspAuthenticateField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///用户代码
	TThostFtdcUserIDType	UserID;
	///用户端产品信息
	TThostFtdcProductInfoType	UserProductInfo;
};

///客户端认证信息
struct CThostFtdcAuthenticationInfoField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///用户代码
	TThostFtdcUserIDType	UserID;
	///用户端产品信息
	TThostFtdcProductInfoType	UserProductInfo;
	///认证信息
	TThostFtdcAuthInfoType	AuthInfo;
	///是否为认证结果
	int	IsResult;
};

///银期转帐报文头
struct CThostFtdcTransferHeaderField
{
	///版本号，常量，1.0
	TThostFtdcVersionType	Version;
	///交易代码，必填
	TThostFtdcTradeCodeType	TradeCode;
	///交易日期，必填，格式：yyyymmdd
	TThostFtdcTradeDateType	TradeDate;
	///交易时间，必填，格式：hhmmss
	TThostFtdcTradeTimeType	TradeTime;
	///发起方流水号，N/A
	TThostFtdcTradeSerialType	TradeSerial;
	///期货公司代码，必填
	TThostFtdcFutureIDType	FutureID;
	///银行代码，根据查询银行得到，必填
	TThostFtdcBankIDType	BankID;
	///银行分中心代码，根据查询银行得到，必填
	TThostFtdcBankBrchIDType	BankBrchID;
	///操作员，N/A
	TThostFtdcOperNoType	OperNo;
	///交易设备类型，N/A
	TThostFtdcDeviceIDType	DeviceID;
	///记录数，N/A
	TThostFtdcRecordNumType	RecordNum;
	///会话编号，N/A
	int	SessionID;
	///请求编号，N/A
	int	RequestID;
};

///银行资金转期货请求，TradeCode=202001
struct CThostFtdcTransferBankToFutureReqField
{
	///期货资金账户
	TThostFtdcAccountIDType	FutureAccount;
	///密码标志
	char	FuturePwdFlag;
	///密码
	TThostFtdcFutureAccPwdType	FutureAccPwd;
	///转账金额
	double	TradeAmt;
	///客户手续费
	double	CustFee;
	///币种：RMB-人民币 USD-美圆 HKD-港元
	TThostFtdcCurrencyCodeType	CurrencyCode;
};

///银行资金转期货请求响应
struct CThostFtdcTransferBankToFutureRspField
{
	///响应代码
	TThostFtdcRetCodeType	RetCode;
	///响应信息
	TThostFtdcRetInfoType	RetInfo;
	///资金账户
	TThostFtdcAccountIDType	FutureAccount;
	///转帐金额
	double	TradeAmt;
	///应收客户手续费
	double	CustFee;
	///币种
	TThostFtdcCurrencyCodeType	CurrencyCode;
};

///期货资金转银行请求，TradeCode=202002
struct CThostFtdcTransferFutureToBankReqField
{
	///期货资金账户
	TThostFtdcAccountIDType	FutureAccount;
	///密码标志
	char	FuturePwdFlag;
	///密码
	TThostFtdcFutureAccPwdType	FutureAccPwd;
	///转账金额
	double	TradeAmt;
	///客户手续费
	double	CustFee;
	///币种：RMB-人民币 USD-美圆 HKD-港元
	TThostFtdcCurrencyCodeType	CurrencyCode;
};

///期货资金转银行请求响应
struct CThostFtdcTransferFutureToBankRspField
{
	///响应代码
	TThostFtdcRetCodeType	RetCode;
	///响应信息
	TThostFtdcRetInfoType	RetInfo;
	///资金账户
	TThostFtdcAccountIDType	FutureAccount;
	///转帐金额
	double	TradeAmt;
	///应收客户手续费
	double	CustFee;
	///币种
	TThostFtdcCurrencyCodeType	CurrencyCode;
};

///查询银行资金请求，TradeCode=204002
struct CThostFtdcTransferQryBankReqField
{
	///期货资金账户
	TThostFtdcAccountIDType	FutureAccount;
	///密码标志
	char	FuturePwdFlag;
	///密码
	TThostFtdcFutureAccPwdType	FutureAccPwd;
	///币种：RMB-人民币 USD-美圆 HKD-港元
	TThostFtdcCurrencyCodeType	CurrencyCode;
};

///查询银行资金请求响应
struct CThostFtdcTransferQryBankRspField
{
	///响应代码
	TThostFtdcRetCodeType	RetCode;
	///响应信息
	TThostFtdcRetInfoType	RetInfo;
	///资金账户
	TThostFtdcAccountIDType	FutureAccount;
	///银行余额
	double	TradeAmt;
	///银行可用余额
	double	UseAmt;
	///银行可取余额
	double	FetchAmt;
	///币种
	TThostFtdcCurrencyCodeType	CurrencyCode;
};

///查询银行交易明细请求，TradeCode=204999
struct CThostFtdcTransferQryDetailReqField
{
	///期货资金账户
	TThostFtdcAccountIDType	FutureAccount;
};

///查询银行交易明细请求响应
struct CThostFtdcTransferQryDetailRspField
{
	///交易日期
	TThostFtdcDateType	TradeDate;
	///交易时间
	TThostFtdcTradeTimeType	TradeTime;
	///交易代码
	TThostFtdcTradeCodeType	TradeCode;
	///期货流水号
	int	FutureSerial;
	///期货公司代码
	TThostFtdcFutureIDType	FutureID;
	///资金帐号
	TThostFtdcFutureAccountType	FutureAccount;
	///银行流水号
	int	BankSerial;
	///银行代码
	TThostFtdcBankIDType	BankID;
	///银行分中心代码
	TThostFtdcBankBrchIDType	BankBrchID;
	///银行账号
	TThostFtdcBankAccountType	BankAccount;
	///证件号码
	TThostFtdcCertCodeType	CertCode;
	///货币代码
	TThostFtdcCurrencyCodeType	CurrencyCode;
	///发生金额
	double	TxAmount;
	///有效标志
	char	Flag;
};

///响应信息
struct CThostFtdcRspInfoField
{
	///错误代码
	int	ErrorID;
	///错误信息
	TThostFtdcErrorMsgType	ErrorMsg;
};

///交易所
struct CThostFtdcExchangeField
{
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///交易所名称
	TThostFtdcExchangeNameType	ExchangeName;
	///交易所属性
	char	ExchangeProperty;
};

///产品
struct CThostFtdcProductField
{
	///产品代码
	TThostFtdcInstrumentIDType	ProductID;
	///产品名称
	TThostFtdcProductNameType	ProductName;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///产品类型
	char	ProductClass;
	///合约数量乘数
	int	VolumeMultiple;
	///最小变动价位
	double	PriceTick;
	///市价单最大下单量
	int	MaxMarketOrderVolume;
	///市价单最小下单量
	int	MinMarketOrderVolume;
	///限价单最大下单量
	int	MaxLimitOrderVolume;
	///限价单最小下单量
	int	MinLimitOrderVolume;
	///持仓类型
	char	PositionType;
	///持仓日期类型
	char	PositionDateType;
	///平仓处理类型
	char	CloseDealType;
	///交易币种类型
	TThostFtdcCurrencyIDType	TradeCurrencyID;
	///质押资金可用范围
	char	MortgageFundUseRange;
	///交易所产品代码
	TThostFtdcInstrumentIDType	ExchangeProductID;
	///合约基础商品乘数
	double	UnderlyingMultiple;
};

///合约
struct CThostFtdcInstrumentField
{
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///合约名称
	TThostFtdcInstrumentNameType	InstrumentName;
	///合约在交易所的代码
	TThostFtdcExchangeInstIDType	ExchangeInstID;
	///产品代码
	TThostFtdcInstrumentIDType	ProductID;
	///产品类型
	char	ProductClass;
	///交割年份
	int	DeliveryYear;
	///交割月
	int	DeliveryMonth;
	///市价单最大下单量
	int	MaxMarketOrderVolume;
	///市价单最小下单量
	int	MinMarketOrderVolume;
	///限价单最大下单量
	int	MaxLimitOrderVolume;
	///限价单最小下单量
	int	MinLimitOrderVolume;
	///合约数量乘数
	int	VolumeMultiple;
	///最小变动价位
	double	PriceTick;
	///创建日
	TThostFtdcDateType	CreateDate;
	///上市日
	TThostFtdcDateType	OpenDate;
	///到期日
	TThostFtdcDateType	ExpireDate;
	///开始交割日
	TThostFtdcDateType	StartDelivDate;
	///结束交割日
	TThostFtdcDateType	EndDelivDate;
	///合约生命周期状态
	char	InstLifePhase;
	///当前是否交易
	int	IsTrading;
	///持仓类型
	char	PositionType;
	///持仓日期类型
	char	PositionDateType;
	///多头保证金率
	double	LongMarginRatio;
	///空头保证金率
	double	ShortMarginRatio;
	///是否使用大额单边保证金算法
	char	MaxMarginSideAlgorithm;
	///基础商品代码
	TThostFtdcInstrumentIDType	UnderlyingInstrID;
	///执行价
	double	StrikePrice;
	///期权类型
	char	OptionsType;
	///合约基础商品乘数
	double	UnderlyingMultiple;
	///组合类型
	char	CombinationType;
};

///经纪公司
struct CThostFtdcBrokerField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///经纪公司简称
	TThostFtdcBrokerAbbrType	BrokerAbbr;
	///经纪公司名称
	TThostFtdcBrokerNameType	BrokerName;
	///是否活跃
	int	IsActive;
};

///交易所交易员
struct CThostFtdcTraderField
{
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///交易所交易员代码
	TThostFtdcTraderIDType	TraderID;
	///会员代码
	TThostFtdcParticipantIDType	ParticipantID;
	///密码
	TThostFtdcPasswordType	Password;
	///安装数量
	int	InstallCount;
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
};

///投资者
struct CThostFtdcInvestorField
{
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者分组代码
	TThostFtdcInvestorIDType	InvestorGroupID;
	///投资者名称
	TThostFtdcPartyNameType	InvestorName;
	///证件类型
	char	IdentifiedCardType;
	///证件号码
	TThostFtdcIdentifiedCardNoType	IdentifiedCardNo;
	///是否活跃
	int	IsActive;
	///联系电话
	TThostFtdcTelephoneType	Telephone;
	///通讯地址
	TThostFtdcAddressType	Address;
	///开户日期
	TThostFtdcDateType	OpenDate;
	///手机
	TThostFtdcMobileType	Mobile;
	///手续费率模板代码
	TThostFtdcInvestorIDType	CommModelID;
	///保证金率模板代码
	TThostFtdcInvestorIDType	MarginModelID;
};

///交易编码
struct CThostFtdcTradingCodeField
{
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///客户代码
	TThostFtdcClientIDType	ClientID;
	///是否活跃
	int	IsActive;
	///交易编码类型
	char	ClientIDType;
};

///会员编码和经纪公司编码对照表
struct CThostFtdcPartBrokerField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///会员代码
	TThostFtdcParticipantIDType	ParticipantID;
	///是否活跃
	int	IsActive;
};

///管理用户
struct CThostFtdcSuperUserField
{
	///用户代码
	TThostFtdcUserIDType	UserID;
	///用户名称
	TThostFtdcUserNameType	UserName;
	///密码
	TThostFtdcPasswordType	Password;
	///是否活跃
	int	IsActive;
};

///管理用户功能权限
struct CThostFtdcSuperUserFunctionField
{
	///用户代码
	TThostFtdcUserIDType	UserID;
	///功能代码
	char	FunctionCode;
};

///投资者组
struct CThostFtdcInvestorGroupField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者分组代码
	TThostFtdcInvestorIDType	InvestorGroupID;
	///投资者分组名称
	TThostFtdcInvestorGroupNameType	InvestorGroupName;
};

///资金账户
struct CThostFtdcTradingAccountField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者帐号
	TThostFtdcAccountIDType	AccountID;
	///上次质押金额
	double	PreMortgage;
	///上次信用额度
	double	PreCredit;
	///上次存款额
	double	PreDeposit;
	///上次结算准备金
	double	PreBalance;
	///上次占用的保证金
	double	PreMargin;
	///利息基数
	double	InterestBase;
	///利息收入
	double	Interest;
	///入金金额
	double	Deposit;
	///出金金额
	double	Withdraw;
	///冻结的保证金
	double	FrozenMargin;
	///冻结的资金
	double	FrozenCash;
	///冻结的手续费
	double	FrozenCommission;
	///当前保证金总额
	double	CurrMargin;
	///资金差额
	double	CashIn;
	///手续费
	double	Commission;
	///平仓盈亏
	double	CloseProfit;
	///持仓盈亏
	double	PositionProfit;
	///期货结算准备金
	double	Balance;
	///可用资金
	double	Available;
	///可取资金
	double	WithdrawQuota;
	///基本准备金
	double	Reserve;
	///交易日
	TThostFtdcDateType	TradingDay;
	///结算编号
	int	SettlementID;
	///信用额度
	double	Credit;
	///质押金额
	double	Mortgage;
	///交易所保证金
	double	ExchangeMargin;
	///投资者交割保证金
	double	DeliveryMargin;
	///交易所交割保证金
	double	ExchangeDeliveryMargin;
	///保底期货结算准备金
	double	ReserveBalance;
	///币种代码
	TThostFtdcCurrencyIDType	CurrencyID;
	///上次货币质入金额
	double	PreFundMortgageIn;
	///上次货币质出金额
	double	PreFundMortgageOut;
	///货币质入金额
	double	FundMortgageIn;
	///货币质出金额
	double	FundMortgageOut;
	///货币质押余额
	double	FundMortgageAvailable;
	///可质押货币金额
	double	MortgageableFund;
	///特殊产品占用保证金
	double	SpecProductMargin;
	///特殊产品冻结保证金
	double	SpecProductFrozenMargin;
	///特殊产品手续费
	double	SpecProductCommission;
	///特殊产品冻结手续费
	double	SpecProductFrozenCommission;
	///特殊产品持仓盈亏
	double	SpecProductPositionProfit;
	///特殊产品平仓盈亏
	double	SpecProductCloseProfit;
	///根据持仓盈亏算法计算的特殊产品持仓盈亏
	double	SpecProductPositionProfitByAlg;
	///特殊产品交易所保证金
	double	SpecProductExchangeMargin;
};

///投资者持仓
struct CThostFtdcInvestorPositionField
{
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///持仓多空方向
	char	PosiDirection;
	///投机套保标志
	char	HedgeFlag;
	///持仓日期
	char	PositionDate;
	///上日持仓
	int	YdPosition;
	///今日持仓
	int	Position;
	///多头冻结
	int	LongFrozen;
	///空头冻结
	int	ShortFrozen;
	///开仓冻结金额
	double	LongFrozenAmount;
	///开仓冻结金额
	double	ShortFrozenAmount;
	///开仓量
	int	OpenVolume;
	///平仓量
	int	CloseVolume;
	///开仓金额
	double	OpenAmount;
	///平仓金额
	double	CloseAmount;
	///持仓成本
	double	PositionCost;
	///上次占用的保证金
	double	PreMargin;
	///占用的保证金
	double	UseMargin;
	///冻结的保证金
	double	FrozenMargin;
	///冻结的资金
	double	FrozenCash;
	///冻结的手续费
	double	FrozenCommission;
	///资金差额
	double	CashIn;
	///手续费
	double	Commission;
	///平仓盈亏
	double	CloseProfit;
	///持仓盈亏
	double	PositionProfit;
	///上次结算价
	double	PreSettlementPrice;
	///本次结算价
	double	SettlementPrice;
	///交易日
	TThostFtdcDateType	TradingDay;
	///结算编号
	int	SettlementID;
	///开仓成本
	double	OpenCost;
	///交易所保证金
	double	ExchangeMargin;
	///组合成交形成的持仓
	int	CombPosition;
	///组合多头冻结
	int	CombLongFrozen;
	///组合空头冻结
	int	CombShortFrozen;
	///逐日盯市平仓盈亏
	double	CloseProfitByDate;
	///逐笔对冲平仓盈亏
	double	CloseProfitByTrade;
	///今日持仓
	int	TodayPosition;
	///保证金率
	double	MarginRateByMoney;
	///保证金率(按手数)
	double	MarginRateByVolume;
	///执行冻结
	int	StrikeFrozen;
	///执行冻结金额
	double	StrikeFrozenAmount;
	///放弃执行冻结
	int	AbandonFrozen;
};

///合约保证金率
struct CThostFtdcInstrumentMarginRateField
{
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///投资者范围
	char	InvestorRange;
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///投机套保标志
	char	HedgeFlag;
	///多头保证金率
	double	LongMarginRatioByMoney;
	///多头保证金费
	double	LongMarginRatioByVolume;
	///空头保证金率
	double	ShortMarginRatioByMoney;
	///空头保证金费
	double	ShortMarginRatioByVolume;
	///是否相对交易所收取
	int	IsRelative;
};

///合约手续费率
struct CThostFtdcInstrumentCommissionRateField
{
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///投资者范围
	char	InvestorRange;
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///开仓手续费率
	double	OpenRatioByMoney;
	///开仓手续费
	double	OpenRatioByVolume;
	///平仓手续费率
	double	CloseRatioByMoney;
	///平仓手续费
	double	CloseRatioByVolume;
	///平今手续费率
	double	CloseTodayRatioByMoney;
	///平今手续费
	double	CloseTodayRatioByVolume;
};

///深度行情
struct CThostFtdcDepthMarketDataField
{
	///交易日
	TThostFtdcDateType	TradingDay;
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///合约在交易所的代码
	TThostFtdcExchangeInstIDType	ExchangeInstID;
	///最新价
	double	LastPrice;
	///上次结算价
	double	PreSettlementPrice;
	///昨收盘
	double	PreClosePrice;
	///昨持仓量
	double	PreOpenInterest;
	///今开盘
	double	OpenPrice;
	///最高价
	double	HighestPrice;
	///最低价
	double	LowestPrice;
	///数量
	int	Volume;
	///成交金额
	double	Turnover;
	///持仓量
	double	OpenInterest;
	///今收盘
	double	ClosePrice;
	///本次结算价
	double	SettlementPrice;
	///涨停板价
	double	UpperLimitPrice;
	///跌停板价
	double	LowerLimitPrice;
	///昨虚实度
	double	PreDelta;
	///今虚实度
	double	CurrDelta;
	///最后修改时间
	TThostFtdcTimeType	UpdateTime;
	///最后修改毫秒
	int	UpdateMillisec;
	///申买价一
	double	BidPrice1;
	///申买量一
	int	BidVolume1;
	///申卖价一
	double	AskPrice1;
	///申卖量一
	int	AskVolume1;
	///申买价二
	double	BidPrice2;
	///申买量二
	int	BidVolume2;
	///申卖价二
	double	AskPrice2;
	///申卖量二
	int	AskVolume2;
	///申买价三
	double	BidPrice3;
	///申买量三
	int	BidVolume3;
	///申卖价三
	double	AskPrice3;
	///申卖量三
	int	AskVolume3;
	///申买价四
	double	BidPrice4;
	///申买量四
	int	BidVolume4;
	///申卖价四
	double	AskPrice4;
	///申卖量四
	int	AskVolume4;
	///申买价五
	double	BidPrice5;
	///申买量五
	int	BidVolume5;
	///申卖价五
	double	AskPrice5;
	///申卖量五
	int	AskVolume5;
	///当日均价
	double	AveragePrice;
	///业务日期
	TThostFtdcDateType	ActionDay;
};

///投资者合约交易权限
struct CThostFtdcInstrumentTradingRightField
{
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///投资者范围
	char	InvestorRange;
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///交易权限
	char	TradingRight;
};

///经纪公司用户
struct CThostFtdcBrokerUserField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///用户代码
	TThostFtdcUserIDType	UserID;
	///用户名称
	TThostFtdcUserNameType	UserName;
	///用户类型
	char	UserType;
	///是否活跃
	int	IsActive;
	///是否使用令牌
	int	IsUsingOTP;
};

///经纪公司用户口令
struct CThostFtdcBrokerUserPasswordField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///用户代码
	TThostFtdcUserIDType	UserID;
	///密码
	TThostFtdcPasswordType	Password;
};

///经纪公司用户功能权限
struct CThostFtdcBrokerUserFunctionField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///用户代码
	TThostFtdcUserIDType	UserID;
	///经纪公司功能代码
	char	BrokerFunctionCode;
};

///交易所交易员报盘机
struct CThostFtdcTraderOfferField
{
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///交易所交易员代码
	TThostFtdcTraderIDType	TraderID;
	///会员代码
	TThostFtdcParticipantIDType	ParticipantID;
	///密码
	TThostFtdcPasswordType	Password;
	///安装编号
	int	InstallID;
	///本地报单编号
	TThostFtdcOrderLocalIDType	OrderLocalID;
	///交易所交易员连接状态
	char	TraderConnectStatus;
	///发出连接请求的日期
	TThostFtdcDateType	ConnectRequestDate;
	///发出连接请求的时间
	TThostFtdcTimeType	ConnectRequestTime;
	///上次报告日期
	TThostFtdcDateType	LastReportDate;
	///上次报告时间
	TThostFtdcTimeType	LastReportTime;
	///完成连接日期
	TThostFtdcDateType	ConnectDate;
	///完成连接时间
	TThostFtdcTimeType	ConnectTime;
	///启动日期
	TThostFtdcDateType	StartDate;
	///启动时间
	TThostFtdcTimeType	StartTime;
	///交易日
	TThostFtdcDateType	TradingDay;
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///本席位最大成交编号
	TThostFtdcTradeIDType	MaxTradeID;
	///本席位最大报单备拷
	TThostFtdcReturnCodeType	MaxOrderMessageReference;
};

///投资者结算结果
struct CThostFtdcSettlementInfoField
{
	///交易日
	TThostFtdcDateType	TradingDay;
	///结算编号
	int	SettlementID;
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///序号
	int	SequenceNo;
	///消息正文
	TThostFtdcContentType	Content;
};

///合约保证金率调整
struct CThostFtdcInstrumentMarginRateAdjustField
{
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///投资者范围
	char	InvestorRange;
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///投机套保标志
	char	HedgeFlag;
	///多头保证金率
	double	LongMarginRatioByMoney;
	///多头保证金费
	double	LongMarginRatioByVolume;
	///空头保证金率
	double	ShortMarginRatioByMoney;
	///空头保证金费
	double	ShortMarginRatioByVolume;
	///是否相对交易所收取
	int	IsRelative;
};

///交易所保证金率
struct CThostFtdcExchangeMarginRateField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///投机套保标志
	char	HedgeFlag;
	///多头保证金率
	double	LongMarginRatioByMoney;
	///多头保证金费
	double	LongMarginRatioByVolume;
	///空头保证金率
	double	ShortMarginRatioByMoney;
	///空头保证金费
	double	ShortMarginRatioByVolume;
};

///交易所保证金率调整
struct CThostFtdcExchangeMarginRateAdjustField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///投机套保标志
	char	HedgeFlag;
	///跟随交易所投资者多头保证金率
	double	LongMarginRatioByMoney;
	///跟随交易所投资者多头保证金费
	double	LongMarginRatioByVolume;
	///跟随交易所投资者空头保证金率
	double	ShortMarginRatioByMoney;
	///跟随交易所投资者空头保证金费
	double	ShortMarginRatioByVolume;
	///交易所多头保证金率
	double	ExchLongMarginRatioByMoney;
	///交易所多头保证金费
	double	ExchLongMarginRatioByVolume;
	///交易所空头保证金率
	double	ExchShortMarginRatioByMoney;
	///交易所空头保证金费
	double	ExchShortMarginRatioByVolume;
	///不跟随交易所投资者多头保证金率
	double	NoLongMarginRatioByMoney;
	///不跟随交易所投资者多头保证金费
	double	NoLongMarginRatioByVolume;
	///不跟随交易所投资者空头保证金率
	double	NoShortMarginRatioByMoney;
	///不跟随交易所投资者空头保证金费
	double	NoShortMarginRatioByVolume;
};

///汇率
struct CThostFtdcExchangeRateField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///源币种
	TThostFtdcCurrencyIDType	FromCurrencyID;
	///源币种单位数量
	double	FromCurrencyUnit;
	///目标币种
	TThostFtdcCurrencyIDType	ToCurrencyID;
	///汇率
	double	ExchangeRate;
};

///结算引用
struct CThostFtdcSettlementRefField
{
	///交易日
	TThostFtdcDateType	TradingDay;
	///结算编号
	int	SettlementID;
};

///当前时间
struct CThostFtdcCurrentTimeField
{
	///当前日期
	TThostFtdcDateType	CurrDate;
	///当前时间
	TThostFtdcTimeType	CurrTime;
	///当前时间（毫秒）
	int	CurrMillisec;
	///业务日期
	TThostFtdcDateType	ActionDay;
};

///通讯阶段
struct CThostFtdcCommPhaseField
{
	///交易日
	TThostFtdcDateType	TradingDay;
	///通讯时段编号
	TThostFtdcCommPhaseNoType	CommPhaseNo;
	///系统编号
	TThostFtdcSystemIDType	SystemID;
};

///登录信息
struct CThostFtdcLoginInfoField
{
	///前置编号
	int	FrontID;
	///会话编号
	int	SessionID;
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///用户代码
	TThostFtdcUserIDType	UserID;
	///登录日期
	TThostFtdcDateType	LoginDate;
	///登录时间
	TThostFtdcTimeType	LoginTime;
	///IP地址
	TThostFtdcIPAddressType	IPAddress;
	///用户端产品信息
	TThostFtdcProductInfoType	UserProductInfo;
	///接口端产品信息
	TThostFtdcProductInfoType	InterfaceProductInfo;
	///协议信息
	TThostFtdcProtocolInfoType	ProtocolInfo;
	///系统名称
	TThostFtdcSystemNameType	SystemName;
	///密码
	TThostFtdcPasswordType	Password;
	///最大报单引用
	TThostFtdcOrderRefType	MaxOrderRef;
	///上期所时间
	TThostFtdcTimeType	SHFETime;
	///大商所时间
	TThostFtdcTimeType	DCETime;
	///郑商所时间
	TThostFtdcTimeType	CZCETime;
	///中金所时间
	TThostFtdcTimeType	FFEXTime;
	///Mac地址
	TThostFtdcMacAddressType	MacAddress;
	///动态密码
	TThostFtdcPasswordType	OneTimePassword;
	///能源中心时间
	TThostFtdcTimeType	INETime;
	///查询时是否需要流控
	int	IsQryControl;
	///登录备注
	TThostFtdcLoginRemarkType	LoginRemark;
};

///登录信息
struct CThostFtdcLogoutAllField
{
	///前置编号
	int	FrontID;
	///会话编号
	int	SessionID;
	///系统名称
	TThostFtdcSystemNameType	SystemName;
};

///前置状态
struct CThostFtdcFrontStatusField
{
	///前置编号
	int	FrontID;
	///上次报告日期
	TThostFtdcDateType	LastReportDate;
	///上次报告时间
	TThostFtdcTimeType	LastReportTime;
	///是否活跃
	int	IsActive;
};

///用户口令变更
struct CThostFtdcUserPasswordUpdateField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///用户代码
	TThostFtdcUserIDType	UserID;
	///原来的口令
	TThostFtdcPasswordType	OldPassword;
	///新的口令
	TThostFtdcPasswordType	NewPassword;
};

///输入报单
struct CThostFtdcInputOrderField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///报单引用
	TThostFtdcOrderRefType	OrderRef;
	///用户代码
	TThostFtdcUserIDType	UserID;
	///报单价格条件
	char	OrderPriceType;
	///买卖方向
	char	Direction;
	///组合开平标志
	TThostFtdcCombOffsetFlagType	CombOffsetFlag;
	///组合投机套保标志
	TThostFtdcCombHedgeFlagType	CombHedgeFlag;
	///价格
	double	LimitPrice;
	///数量
	int	VolumeTotalOriginal;
	///有效期类型
	char	TimeCondition;
	///GTD日期
	TThostFtdcDateType	GTDDate;
	///成交量类型
	char	VolumeCondition;
	///最小成交量
	int	MinVolume;
	///触发条件
	char	ContingentCondition;
	///止损价
	double	StopPrice;
	///强平原因
	char	ForceCloseReason;
	///自动挂起标志
	int	IsAutoSuspend;
	///业务单元
	TThostFtdcBusinessUnitType	BusinessUnit;
	///请求编号
	int	RequestID;
	///用户强评标志
	int	UserForceClose;
	///互换单标志
	int	IsSwapOrder;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///投资单元代码
	TThostFtdcInvestUnitIDType	InvestUnitID;
	///资金账号
	TThostFtdcAccountIDType	AccountID;
	///币种代码
	TThostFtdcCurrencyIDType	CurrencyID;
	///交易编码
	TThostFtdcClientIDType	ClientID;
	///IP地址
	TThostFtdcIPAddressType	IPAddress;
	///Mac地址
	TThostFtdcMacAddressType	MacAddress;
};

///报单
struct CThostFtdcOrderField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///报单引用
	TThostFtdcOrderRefType	OrderRef;
	///用户代码
	TThostFtdcUserIDType	UserID;
	///报单价格条件
	char	OrderPriceType;
	///买卖方向
	char	Direction;
	///组合开平标志
	TThostFtdcCombOffsetFlagType	CombOffsetFlag;
	///组合投机套保标志
	TThostFtdcCombHedgeFlagType	CombHedgeFlag;
	///价格
	double	LimitPrice;
	///数量
	int	VolumeTotalOriginal;
	///有效期类型
	char	TimeCondition;
	///GTD日期
	TThostFtdcDateType	GTDDate;
	///成交量类型
	char	VolumeCondition;
	///最小成交量
	int	MinVolume;
	///触发条件
	char	ContingentCondition;
	///止损价
	double	StopPrice;
	///强平原因
	char	ForceCloseReason;
	///自动挂起标志
	int	IsAutoSuspend;
	///业务单元
	TThostFtdcBusinessUnitType	BusinessUnit;
	///请求编号
	int	RequestID;
	///本地报单编号
	TThostFtdcOrderLocalIDType	OrderLocalID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///会员代码
	TThostFtdcParticipantIDType	ParticipantID;
	///客户代码
	TThostFtdcClientIDType	ClientID;
	///合约在交易所的代码
	TThostFtdcExchangeInstIDType	ExchangeInstID;
	///交易所交易员代码
	TThostFtdcTraderIDType	TraderID;
	///安装编号
	int	InstallID;
	///报单提交状态
	char	OrderSubmitStatus;
	///报单提示序号
	int	NotifySequence;
	///交易日
	TThostFtdcDateType	TradingDay;
	///结算编号
	int	SettlementID;
	///报单编号
	TThostFtdcOrderSysIDType	OrderSysID;
	///报单来源
	char	OrderSource;
	///报单状态
	char	OrderStatus;
	///报单类型
	char	OrderType;
	///今成交数量
	int	VolumeTraded;
	///剩余数量
	int	VolumeTotal;
	///报单日期
	TThostFtdcDateType	InsertDate;
	///委托时间
	TThostFtdcTimeType	InsertTime;
	///激活时间
	TThostFtdcTimeType	ActiveTime;
	///挂起时间
	TThostFtdcTimeType	SuspendTime;
	///最后修改时间
	TThostFtdcTimeType	UpdateTime;
	///撤销时间
	TThostFtdcTimeType	CancelTime;
	///最后修改交易所交易员代码
	TThostFtdcTraderIDType	ActiveTraderID;
	///结算会员编号
	TThostFtdcParticipantIDType	ClearingPartID;
	///序号
	int	SequenceNo;
	///前置编号
	int	FrontID;
	///会话编号
	int	SessionID;
	///用户端产品信息
	TThostFtdcProductInfoType	UserProductInfo;
	///状态信息
	TThostFtdcErrorMsgType	StatusMsg;
	///用户强评标志
	int	UserForceClose;
	///操作用户代码
	TThostFtdcUserIDType	ActiveUserID;
	///经纪公司报单编号
	int	BrokerOrderSeq;
	///相关报单
	TThostFtdcOrderSysIDType	RelativeOrderSysID;
	///郑商所成交数量
	int	ZCETotalTradedVolume;
	///互换单标志
	int	IsSwapOrder;
	///营业部编号
	TThostFtdcBranchIDType	BranchID;
	///投资单元代码
	TThostFtdcInvestUnitIDType	InvestUnitID;
	///资金账号
	TThostFtdcAccountIDType	AccountID;
	///币种代码
	TThostFtdcCurrencyIDType	CurrencyID;
	///IP地址
	TThostFtdcIPAddressType	IPAddress;
	///Mac地址
	TThostFtdcMacAddressType	MacAddress;
};

///交易所报单
struct CThostFtdcExchangeOrderField
{
	///报单价格条件
	char	OrderPriceType;
	///买卖方向
	char	Direction;
	///组合开平标志
	TThostFtdcCombOffsetFlagType	CombOffsetFlag;
	///组合投机套保标志
	TThostFtdcCombHedgeFlagType	CombHedgeFlag;
	///价格
	double	LimitPrice;
	///数量
	int	VolumeTotalOriginal;
	///有效期类型
	char	TimeCondition;
	///GTD日期
	TThostFtdcDateType	GTDDate;
	///成交量类型
	char	VolumeCondition;
	///最小成交量
	int	MinVolume;
	///触发条件
	char	ContingentCondition;
	///止损价
	double	StopPrice;
	///强平原因
	char	ForceCloseReason;
	///自动挂起标志
	int	IsAutoSuspend;
	///业务单元
	TThostFtdcBusinessUnitType	BusinessUnit;
	///请求编号
	int	RequestID;
	///本地报单编号
	TThostFtdcOrderLocalIDType	OrderLocalID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///会员代码
	TThostFtdcParticipantIDType	ParticipantID;
	///客户代码
	TThostFtdcClientIDType	ClientID;
	///合约在交易所的代码
	TThostFtdcExchangeInstIDType	ExchangeInstID;
	///交易所交易员代码
	TThostFtdcTraderIDType	TraderID;
	///安装编号
	int	InstallID;
	///报单提交状态
	char	OrderSubmitStatus;
	///报单提示序号
	int	NotifySequence;
	///交易日
	TThostFtdcDateType	TradingDay;
	///结算编号
	int	SettlementID;
	///报单编号
	TThostFtdcOrderSysIDType	OrderSysID;
	///报单来源
	char	OrderSource;
	///报单状态
	char	OrderStatus;
	///报单类型
	char	OrderType;
	///今成交数量
	int	VolumeTraded;
	///剩余数量
	int	VolumeTotal;
	///报单日期
	TThostFtdcDateType	InsertDate;
	///委托时间
	TThostFtdcTimeType	InsertTime;
	///激活时间
	TThostFtdcTimeType	ActiveTime;
	///挂起时间
	TThostFtdcTimeType	SuspendTime;
	///最后修改时间
	TThostFtdcTimeType	UpdateTime;
	///撤销时间
	TThostFtdcTimeType	CancelTime;
	///最后修改交易所交易员代码
	TThostFtdcTraderIDType	ActiveTraderID;
	///结算会员编号
	TThostFtdcParticipantIDType	ClearingPartID;
	///序号
	int	SequenceNo;
	///营业部编号
	TThostFtdcBranchIDType	BranchID;
	///IP地址
	TThostFtdcIPAddressType	IPAddress;
	///Mac地址
	TThostFtdcMacAddressType	MacAddress;
};

///交易所报单插入失败
struct CThostFtdcExchangeOrderInsertErrorField
{
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///会员代码
	TThostFtdcParticipantIDType	ParticipantID;
	///交易所交易员代码
	TThostFtdcTraderIDType	TraderID;
	///安装编号
	int	InstallID;
	///本地报单编号
	TThostFtdcOrderLocalIDType	OrderLocalID;
	///错误代码
	int	ErrorID;
	///错误信息
	TThostFtdcErrorMsgType	ErrorMsg;
};

///输入报单操作
struct CThostFtdcInputOrderActionField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///报单操作引用
	int	OrderActionRef;
	///报单引用
	TThostFtdcOrderRefType	OrderRef;
	///请求编号
	int	RequestID;
	///前置编号
	int	FrontID;
	///会话编号
	int	SessionID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///报单编号
	TThostFtdcOrderSysIDType	OrderSysID;
	///操作标志
	char	ActionFlag;
	///价格
	double	LimitPrice;
	///数量变化
	int	VolumeChange;
	///用户代码
	TThostFtdcUserIDType	UserID;
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///投资单元代码
	TThostFtdcInvestUnitIDType	InvestUnitID;
	///IP地址
	TThostFtdcIPAddressType	IPAddress;
	///Mac地址
	TThostFtdcMacAddressType	MacAddress;
};

///报单操作
struct CThostFtdcOrderActionField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///报单操作引用
	int	OrderActionRef;
	///报单引用
	TThostFtdcOrderRefType	OrderRef;
	///请求编号
	int	RequestID;
	///前置编号
	int	FrontID;
	///会话编号
	int	SessionID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///报单编号
	TThostFtdcOrderSysIDType	OrderSysID;
	///操作标志
	char	ActionFlag;
	///价格
	double	LimitPrice;
	///数量变化
	int	VolumeChange;
	///操作日期
	TThostFtdcDateType	ActionDate;
	///操作时间
	TThostFtdcTimeType	ActionTime;
	///交易所交易员代码
	TThostFtdcTraderIDType	TraderID;
	///安装编号
	int	InstallID;
	///本地报单编号
	TThostFtdcOrderLocalIDType	OrderLocalID;
	///操作本地编号
	TThostFtdcOrderLocalIDType	ActionLocalID;
	///会员代码
	TThostFtdcParticipantIDType	ParticipantID;
	///客户代码
	TThostFtdcClientIDType	ClientID;
	///业务单元
	TThostFtdcBusinessUnitType	BusinessUnit;
	///报单操作状态
	char	OrderActionStatus;
	///用户代码
	TThostFtdcUserIDType	UserID;
	///状态信息
	TThostFtdcErrorMsgType	StatusMsg;
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///营业部编号
	TThostFtdcBranchIDType	BranchID;
	///投资单元代码
	TThostFtdcInvestUnitIDType	InvestUnitID;
	///IP地址
	TThostFtdcIPAddressType	IPAddress;
	///Mac地址
	TThostFtdcMacAddressType	MacAddress;
};

///交易所报单操作
struct CThostFtdcExchangeOrderActionField
{
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///报单编号
	TThostFtdcOrderSysIDType	OrderSysID;
	///操作标志
	char	ActionFlag;
	///价格
	double	LimitPrice;
	///数量变化
	int	VolumeChange;
	///操作日期
	TThostFtdcDateType	ActionDate;
	///操作时间
	TThostFtdcTimeType	ActionTime;
	///交易所交易员代码
	TThostFtdcTraderIDType	TraderID;
	///安装编号
	int	InstallID;
	///本地报单编号
	TThostFtdcOrderLocalIDType	OrderLocalID;
	///操作本地编号
	TThostFtdcOrderLocalIDType	ActionLocalID;
	///会员代码
	TThostFtdcParticipantIDType	ParticipantID;
	///客户代码
	TThostFtdcClientIDType	ClientID;
	///业务单元
	TThostFtdcBusinessUnitType	BusinessUnit;
	///报单操作状态
	char	OrderActionStatus;
	///用户代码
	TThostFtdcUserIDType	UserID;
	///营业部编号
	TThostFtdcBranchIDType	BranchID;
	///IP地址
	TThostFtdcIPAddressType	IPAddress;
	///Mac地址
	TThostFtdcMacAddressType	MacAddress;
};

///交易所报单操作失败
struct CThostFtdcExchangeOrderActionErrorField
{
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///报单编号
	TThostFtdcOrderSysIDType	OrderSysID;
	///交易所交易员代码
	TThostFtdcTraderIDType	TraderID;
	///安装编号
	int	InstallID;
	///本地报单编号
	TThostFtdcOrderLocalIDType	OrderLocalID;
	///操作本地编号
	TThostFtdcOrderLocalIDType	ActionLocalID;
	///错误代码
	int	ErrorID;
	///错误信息
	TThostFtdcErrorMsgType	ErrorMsg;
};

///交易所成交
struct CThostFtdcExchangeTradeField
{
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///成交编号
	TThostFtdcTradeIDType	TradeID;
	///买卖方向
	char	Direction;
	///报单编号
	TThostFtdcOrderSysIDType	OrderSysID;
	///会员代码
	TThostFtdcParticipantIDType	ParticipantID;
	///客户代码
	TThostFtdcClientIDType	ClientID;
	///交易角色
	char	TradingRole;
	///合约在交易所的代码
	TThostFtdcExchangeInstIDType	ExchangeInstID;
	///开平标志
	char	OffsetFlag;
	///投机套保标志
	char	HedgeFlag;
	///价格
	double	Price;
	///数量
	int	Volume;
	///成交时期
	TThostFtdcDateType	TradeDate;
	///成交时间
	TThostFtdcTimeType	TradeTime;
	///成交类型
	char	TradeType;
	///成交价来源
	char	PriceSource;
	///交易所交易员代码
	TThostFtdcTraderIDType	TraderID;
	///本地报单编号
	TThostFtdcOrderLocalIDType	OrderLocalID;
	///结算会员编号
	TThostFtdcParticipantIDType	ClearingPartID;
	///业务单元
	TThostFtdcBusinessUnitType	BusinessUnit;
	///序号
	int	SequenceNo;
	///成交来源
	char	TradeSource;
};

///成交
struct CThostFtdcTradeField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///报单引用
	TThostFtdcOrderRefType	OrderRef;
	///用户代码
	TThostFtdcUserIDType	UserID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///成交编号
	TThostFtdcTradeIDType	TradeID;
	///买卖方向
	char	Direction;
	///报单编号
	TThostFtdcOrderSysIDType	OrderSysID;
	///会员代码
	TThostFtdcParticipantIDType	ParticipantID;
	///客户代码
	TThostFtdcClientIDType	ClientID;
	///交易角色
	char	TradingRole;
	///合约在交易所的代码
	TThostFtdcExchangeInstIDType	ExchangeInstID;
	///开平标志
	char	OffsetFlag;
	///投机套保标志
	char	HedgeFlag;
	///价格
	double	Price;
	///数量
	int	Volume;
	///成交时期
	TThostFtdcDateType	TradeDate;
	///成交时间
	TThostFtdcTimeType	TradeTime;
	///成交类型
	char	TradeType;
	///成交价来源
	char	PriceSource;
	///交易所交易员代码
	TThostFtdcTraderIDType	TraderID;
	///本地报单编号
	TThostFtdcOrderLocalIDType	OrderLocalID;
	///结算会员编号
	TThostFtdcParticipantIDType	ClearingPartID;
	///业务单元
	TThostFtdcBusinessUnitType	BusinessUnit;
	///序号
	int	SequenceNo;
	///交易日
	TThostFtdcDateType	TradingDay;
	///结算编号
	int	SettlementID;
	///经纪公司报单编号
	int	BrokerOrderSeq;
	///成交来源
	char	TradeSource;
};

///用户会话
struct CThostFtdcUserSessionField
{
	///前置编号
	int	FrontID;
	///会话编号
	int	SessionID;
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///用户代码
	TThostFtdcUserIDType	UserID;
	///登录日期
	TThostFtdcDateType	LoginDate;
	///登录时间
	TThostFtdcTimeType	LoginTime;
	///IP地址
	TThostFtdcIPAddressType	IPAddress;
	///用户端产品信息
	TThostFtdcProductInfoType	UserProductInfo;
	///接口端产品信息
	TThostFtdcProductInfoType	InterfaceProductInfo;
	///协议信息
	TThostFtdcProtocolInfoType	ProtocolInfo;
	///Mac地址
	TThostFtdcMacAddressType	MacAddress;
	///登录备注
	TThostFtdcLoginRemarkType	LoginRemark;
};

///查询最大报单数量
struct CThostFtdcQueryMaxOrderVolumeField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///买卖方向
	char	Direction;
	///开平标志
	char	OffsetFlag;
	///投机套保标志
	char	HedgeFlag;
	///最大允许报单数量
	int	MaxVolume;
};

///投资者结算结果确认信息
struct CThostFtdcSettlementInfoConfirmField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///确认日期
	TThostFtdcDateType	ConfirmDate;
	///确认时间
	TThostFtdcTimeType	ConfirmTime;
};

///出入金同步
struct CThostFtdcSyncDepositField
{
	///出入金流水号
	TThostFtdcDepositSeqNoType	DepositSeqNo;
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///入金金额
	double	Deposit;
	///是否强制进行
	int	IsForce;
	///币种代码
	TThostFtdcCurrencyIDType	CurrencyID;
};

///货币质押同步
struct CThostFtdcSyncFundMortgageField
{
	///货币质押流水号
	TThostFtdcDepositSeqNoType	MortgageSeqNo;
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///源币种
	TThostFtdcCurrencyIDType	FromCurrencyID;
	///质押金额
	double	MortgageAmount;
	///目标币种
	TThostFtdcCurrencyIDType	ToCurrencyID;
};

///经纪公司同步
struct CThostFtdcBrokerSyncField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
};

///正在同步中的投资者
struct CThostFtdcSyncingInvestorField
{
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者分组代码
	TThostFtdcInvestorIDType	InvestorGroupID;
	///投资者名称
	TThostFtdcPartyNameType	InvestorName;
	///证件类型
	char	IdentifiedCardType;
	///证件号码
	TThostFtdcIdentifiedCardNoType	IdentifiedCardNo;
	///是否活跃
	int	IsActive;
	///联系电话
	TThostFtdcTelephoneType	Telephone;
	///通讯地址
	TThostFtdcAddressType	Address;
	///开户日期
	TThostFtdcDateType	OpenDate;
	///手机
	TThostFtdcMobileType	Mobile;
	///手续费率模板代码
	TThostFtdcInvestorIDType	CommModelID;
	///保证金率模板代码
	TThostFtdcInvestorIDType	MarginModelID;
};

///正在同步中的交易代码
struct CThostFtdcSyncingTradingCodeField
{
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///客户代码
	TThostFtdcClientIDType	ClientID;
	///是否活跃
	int	IsActive;
	///交易编码类型
	char	ClientIDType;
};

///正在同步中的投资者分组
struct CThostFtdcSyncingInvestorGroupField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者分组代码
	TThostFtdcInvestorIDType	InvestorGroupID;
	///投资者分组名称
	TThostFtdcInvestorGroupNameType	InvestorGroupName;
};

///正在同步中的交易账号
struct CThostFtdcSyncingTradingAccountField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者帐号
	TThostFtdcAccountIDType	AccountID;
	///上次质押金额
	double	PreMortgage;
	///上次信用额度
	double	PreCredit;
	///上次存款额
	double	PreDeposit;
	///上次结算准备金
	double	PreBalance;
	///上次占用的保证金
	double	PreMargin;
	///利息基数
	double	InterestBase;
	///利息收入
	double	Interest;
	///入金金额
	double	Deposit;
	///出金金额
	double	Withdraw;
	///冻结的保证金
	double	FrozenMargin;
	///冻结的资金
	double	FrozenCash;
	///冻结的手续费
	double	FrozenCommission;
	///当前保证金总额
	double	CurrMargin;
	///资金差额
	double	CashIn;
	///手续费
	double	Commission;
	///平仓盈亏
	double	CloseProfit;
	///持仓盈亏
	double	PositionProfit;
	///期货结算准备金
	double	Balance;
	///可用资金
	double	Available;
	///可取资金
	double	WithdrawQuota;
	///基本准备金
	double	Reserve;
	///交易日
	TThostFtdcDateType	TradingDay;
	///结算编号
	int	SettlementID;
	///信用额度
	double	Credit;
	///质押金额
	double	Mortgage;
	///交易所保证金
	double	ExchangeMargin;
	///投资者交割保证金
	double	DeliveryMargin;
	///交易所交割保证金
	double	ExchangeDeliveryMargin;
	///保底期货结算准备金
	double	ReserveBalance;
	///币种代码
	TThostFtdcCurrencyIDType	CurrencyID;
	///上次货币质入金额
	double	PreFundMortgageIn;
	///上次货币质出金额
	double	PreFundMortgageOut;
	///货币质入金额
	double	FundMortgageIn;
	///货币质出金额
	double	FundMortgageOut;
	///货币质押余额
	double	FundMortgageAvailable;
	///可质押货币金额
	double	MortgageableFund;
	///特殊产品占用保证金
	double	SpecProductMargin;
	///特殊产品冻结保证金
	double	SpecProductFrozenMargin;
	///特殊产品手续费
	double	SpecProductCommission;
	///特殊产品冻结手续费
	double	SpecProductFrozenCommission;
	///特殊产品持仓盈亏
	double	SpecProductPositionProfit;
	///特殊产品平仓盈亏
	double	SpecProductCloseProfit;
	///根据持仓盈亏算法计算的特殊产品持仓盈亏
	double	SpecProductPositionProfitByAlg;
	///特殊产品交易所保证金
	double	SpecProductExchangeMargin;
};

///正在同步中的投资者持仓
struct CThostFtdcSyncingInvestorPositionField
{
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///持仓多空方向
	char	PosiDirection;
	///投机套保标志
	char	HedgeFlag;
	///持仓日期
	char	PositionDate;
	///上日持仓
	int	YdPosition;
	///今日持仓
	int	Position;
	///多头冻结
	int	LongFrozen;
	///空头冻结
	int	ShortFrozen;
	///开仓冻结金额
	double	LongFrozenAmount;
	///开仓冻结金额
	double	ShortFrozenAmount;
	///开仓量
	int	OpenVolume;
	///平仓量
	int	CloseVolume;
	///开仓金额
	double	OpenAmount;
	///平仓金额
	double	CloseAmount;
	///持仓成本
	double	PositionCost;
	///上次占用的保证金
	double	PreMargin;
	///占用的保证金
	double	UseMargin;
	///冻结的保证金
	double	FrozenMargin;
	///冻结的资金
	double	FrozenCash;
	///冻结的手续费
	double	FrozenCommission;
	///资金差额
	double	CashIn;
	///手续费
	double	Commission;
	///平仓盈亏
	double	CloseProfit;
	///持仓盈亏
	double	PositionProfit;
	///上次结算价
	double	PreSettlementPrice;
	///本次结算价
	double	SettlementPrice;
	///交易日
	TThostFtdcDateType	TradingDay;
	///结算编号
	int	SettlementID;
	///开仓成本
	double	OpenCost;
	///交易所保证金
	double	ExchangeMargin;
	///组合成交形成的持仓
	int	CombPosition;
	///组合多头冻结
	int	CombLongFrozen;
	///组合空头冻结
	int	CombShortFrozen;
	///逐日盯市平仓盈亏
	double	CloseProfitByDate;
	///逐笔对冲平仓盈亏
	double	CloseProfitByTrade;
	///今日持仓
	int	TodayPosition;
	///保证金率
	double	MarginRateByMoney;
	///保证金率(按手数)
	double	MarginRateByVolume;
	///执行冻结
	int	StrikeFrozen;
	///执行冻结金额
	double	StrikeFrozenAmount;
	///放弃执行冻结
	int	AbandonFrozen;
};

///正在同步中的合约保证金率
struct CThostFtdcSyncingInstrumentMarginRateField
{
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///投资者范围
	char	InvestorRange;
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///投机套保标志
	char	HedgeFlag;
	///多头保证金率
	double	LongMarginRatioByMoney;
	///多头保证金费
	double	LongMarginRatioByVolume;
	///空头保证金率
	double	ShortMarginRatioByMoney;
	///空头保证金费
	double	ShortMarginRatioByVolume;
	///是否相对交易所收取
	int	IsRelative;
};

///正在同步中的合约手续费率
struct CThostFtdcSyncingInstrumentCommissionRateField
{
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///投资者范围
	char	InvestorRange;
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///开仓手续费率
	double	OpenRatioByMoney;
	///开仓手续费
	double	OpenRatioByVolume;
	///平仓手续费率
	double	CloseRatioByMoney;
	///平仓手续费
	double	CloseRatioByVolume;
	///平今手续费率
	double	CloseTodayRatioByMoney;
	///平今手续费
	double	CloseTodayRatioByVolume;
};

///正在同步中的合约交易权限
struct CThostFtdcSyncingInstrumentTradingRightField
{
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///投资者范围
	char	InvestorRange;
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///交易权限
	char	TradingRight;
};

///查询报单
struct CThostFtdcQryOrderField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///报单编号
	TThostFtdcOrderSysIDType	OrderSysID;
	///开始时间
	TThostFtdcTimeType	InsertTimeStart;
	///结束时间
	TThostFtdcTimeType	InsertTimeEnd;
};

///查询成交
struct CThostFtdcQryTradeField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///成交编号
	TThostFtdcTradeIDType	TradeID;
	///开始时间
	TThostFtdcTimeType	TradeTimeStart;
	///结束时间
	TThostFtdcTimeType	TradeTimeEnd;
};

///查询投资者持仓
struct CThostFtdcQryInvestorPositionField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
};

///查询资金账户
struct CThostFtdcQryTradingAccountField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///币种代码
	TThostFtdcCurrencyIDType	CurrencyID;
};

///查询投资者
struct CThostFtdcQryInvestorField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
};

///查询交易编码
struct CThostFtdcQryTradingCodeField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///客户代码
	TThostFtdcClientIDType	ClientID;
	///交易编码类型
	char	ClientIDType;
};

///查询投资者组
struct CThostFtdcQryInvestorGroupField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
};

///查询合约保证金率
struct CThostFtdcQryInstrumentMarginRateField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///投机套保标志
	char	HedgeFlag;
};

///查询手续费率
struct CThostFtdcQryInstrumentCommissionRateField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
};

///查询合约交易权限
struct CThostFtdcQryInstrumentTradingRightField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
};

///查询经纪公司
struct CThostFtdcQryBrokerField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
};

///查询交易员
struct CThostFtdcQryTraderField
{
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///会员代码
	TThostFtdcParticipantIDType	ParticipantID;
	///交易所交易员代码
	TThostFtdcTraderIDType	TraderID;
};

///查询管理用户功能权限
struct CThostFtdcQrySuperUserFunctionField
{
	///用户代码
	TThostFtdcUserIDType	UserID;
};

///查询用户会话
struct CThostFtdcQryUserSessionField
{
	///前置编号
	int	FrontID;
	///会话编号
	int	SessionID;
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///用户代码
	TThostFtdcUserIDType	UserID;
};

///查询经纪公司会员代码
struct CThostFtdcQryPartBrokerField
{
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///会员代码
	TThostFtdcParticipantIDType	ParticipantID;
};

///查询前置状态
struct CThostFtdcQryFrontStatusField
{
	///前置编号
	int	FrontID;
};

///查询交易所报单
struct CThostFtdcQryExchangeOrderField
{
	///会员代码
	TThostFtdcParticipantIDType	ParticipantID;
	///客户代码
	TThostFtdcClientIDType	ClientID;
	///合约在交易所的代码
	TThostFtdcExchangeInstIDType	ExchangeInstID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///交易所交易员代码
	TThostFtdcTraderIDType	TraderID;
};

///查询报单操作
struct CThostFtdcQryOrderActionField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
};

///查询交易所报单操作
struct CThostFtdcQryExchangeOrderActionField
{
	///会员代码
	TThostFtdcParticipantIDType	ParticipantID;
	///客户代码
	TThostFtdcClientIDType	ClientID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///交易所交易员代码
	TThostFtdcTraderIDType	TraderID;
};

///查询管理用户
struct CThostFtdcQrySuperUserField
{
	///用户代码
	TThostFtdcUserIDType	UserID;
};

///查询交易所
struct CThostFtdcQryExchangeField
{
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
};

///查询产品
struct CThostFtdcQryProductField
{
	///产品代码
	TThostFtdcInstrumentIDType	ProductID;
	///产品类型
	char	ProductClass;
};

///查询合约
struct CThostFtdcQryInstrumentField
{
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///合约在交易所的代码
	TThostFtdcExchangeInstIDType	ExchangeInstID;
	///产品代码
	TThostFtdcInstrumentIDType	ProductID;
};

///查询行情
struct CThostFtdcQryDepthMarketDataField
{
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
};

///查询经纪公司用户
struct CThostFtdcQryBrokerUserField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///用户代码
	TThostFtdcUserIDType	UserID;
};

///查询经纪公司用户权限
struct CThostFtdcQryBrokerUserFunctionField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///用户代码
	TThostFtdcUserIDType	UserID;
};

///查询交易员报盘机
struct CThostFtdcQryTraderOfferField
{
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///会员代码
	TThostFtdcParticipantIDType	ParticipantID;
	///交易所交易员代码
	TThostFtdcTraderIDType	TraderID;
};

///查询出入金流水
struct CThostFtdcQrySyncDepositField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///出入金流水号
	TThostFtdcDepositSeqNoType	DepositSeqNo;
};

///查询投资者结算结果
struct CThostFtdcQrySettlementInfoField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///交易日
	TThostFtdcDateType	TradingDay;
};

///查询交易所保证金率
struct CThostFtdcQryExchangeMarginRateField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///投机套保标志
	char	HedgeFlag;
};

///查询交易所调整保证金率
struct CThostFtdcQryExchangeMarginRateAdjustField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///投机套保标志
	char	HedgeFlag;
};

///查询汇率
struct CThostFtdcQryExchangeRateField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///源币种
	TThostFtdcCurrencyIDType	FromCurrencyID;
	///目标币种
	TThostFtdcCurrencyIDType	ToCurrencyID;
};

///查询货币质押流水
struct CThostFtdcQrySyncFundMortgageField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///货币质押流水号
	TThostFtdcDepositSeqNoType	MortgageSeqNo;
};

///查询报单
struct CThostFtdcQryHisOrderField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///报单编号
	TThostFtdcOrderSysIDType	OrderSysID;
	///开始时间
	TThostFtdcTimeType	InsertTimeStart;
	///结束时间
	TThostFtdcTimeType	InsertTimeEnd;
	///交易日
	TThostFtdcDateType	TradingDay;
	///结算编号
	int	SettlementID;
};

///当前期权合约最小保证金
struct CThostFtdcOptionInstrMiniMarginField
{
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///投资者范围
	char	InvestorRange;
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///单位（手）期权合约最小保证金
	double	MinMargin;
	///取值方式
	char	ValueMethod;
	///是否跟随交易所收取
	int	IsRelative;
};

///当前期权合约保证金调整系数
struct CThostFtdcOptionInstrMarginAdjustField
{
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///投资者范围
	char	InvestorRange;
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///投机空头保证金调整系数
	double	SShortMarginRatioByMoney;
	///投机空头保证金调整系数
	double	SShortMarginRatioByVolume;
	///保值空头保证金调整系数
	double	HShortMarginRatioByMoney;
	///保值空头保证金调整系数
	double	HShortMarginRatioByVolume;
	///套利空头保证金调整系数
	double	AShortMarginRatioByMoney;
	///套利空头保证金调整系数
	double	AShortMarginRatioByVolume;
	///是否跟随交易所收取
	int	IsRelative;
	///做市商空头保证金调整系数
	double	MShortMarginRatioByMoney;
	///做市商空头保证金调整系数
	double	MShortMarginRatioByVolume;
};

///当前期权合约手续费的详细内容
struct CThostFtdcOptionInstrCommRateField
{
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///投资者范围
	char	InvestorRange;
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///开仓手续费率
	double	OpenRatioByMoney;
	///开仓手续费
	double	OpenRatioByVolume;
	///平仓手续费率
	double	CloseRatioByMoney;
	///平仓手续费
	double	CloseRatioByVolume;
	///平今手续费率
	double	CloseTodayRatioByMoney;
	///平今手续费
	double	CloseTodayRatioByVolume;
	///执行手续费率
	double	StrikeRatioByMoney;
	///执行手续费
	double	StrikeRatioByVolume;
};

///期权交易成本
struct CThostFtdcOptionInstrTradeCostField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///投机套保标志
	char	HedgeFlag;
	///期权合约保证金不变部分
	double	FixedMargin;
	///期权合约最小保证金
	double	MiniMargin;
	///期权合约权利金
	double	Royalty;
	///交易所期权合约保证金不变部分
	double	ExchFixedMargin;
	///交易所期权合约最小保证金
	double	ExchMiniMargin;
};

///期权交易成本查询
struct CThostFtdcQryOptionInstrTradeCostField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///投机套保标志
	char	HedgeFlag;
	///期权合约报价
	double	InputPrice;
	///标的价格,填0则用昨结算价
	double	UnderlyingPrice;
};

///期权手续费率查询
struct CThostFtdcQryOptionInstrCommRateField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
};

///股指现货指数
struct CThostFtdcIndexPriceField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///指数现货收盘价
	double	ClosePrice;
};

///输入的执行宣告
struct CThostFtdcInputExecOrderField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///执行宣告引用
	TThostFtdcOrderRefType	ExecOrderRef;
	///用户代码
	TThostFtdcUserIDType	UserID;
	///数量
	int	Volume;
	///请求编号
	int	RequestID;
	///业务单元
	TThostFtdcBusinessUnitType	BusinessUnit;
	///开平标志
	char	OffsetFlag;
	///投机套保标志
	char	HedgeFlag;
	///执行类型
	char	ActionType;
	///保留头寸申请的持仓方向
	char	PosiDirection;
	///期权行权后是否保留期货头寸的标记
	char	ReservePositionFlag;
	///期权行权后生成的头寸是否自动平仓
	char	CloseFlag;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///投资单元代码
	TThostFtdcInvestUnitIDType	InvestUnitID;
	///资金账号
	TThostFtdcAccountIDType	AccountID;
	///币种代码
	TThostFtdcCurrencyIDType	CurrencyID;
	///交易编码
	TThostFtdcClientIDType	ClientID;
	///IP地址
	TThostFtdcIPAddressType	IPAddress;
	///Mac地址
	TThostFtdcMacAddressType	MacAddress;
};

///输入执行宣告操作
struct CThostFtdcInputExecOrderActionField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///执行宣告操作引用
	int	ExecOrderActionRef;
	///执行宣告引用
	TThostFtdcOrderRefType	ExecOrderRef;
	///请求编号
	int	RequestID;
	///前置编号
	int	FrontID;
	///会话编号
	int	SessionID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///执行宣告操作编号
	TThostFtdcExecOrderSysIDType	ExecOrderSysID;
	///操作标志
	char	ActionFlag;
	///用户代码
	TThostFtdcUserIDType	UserID;
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///投资单元代码
	TThostFtdcInvestUnitIDType	InvestUnitID;
	///IP地址
	TThostFtdcIPAddressType	IPAddress;
	///Mac地址
	TThostFtdcMacAddressType	MacAddress;
};

///执行宣告
struct CThostFtdcExecOrderField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///执行宣告引用
	TThostFtdcOrderRefType	ExecOrderRef;
	///用户代码
	TThostFtdcUserIDType	UserID;
	///数量
	int	Volume;
	///请求编号
	int	RequestID;
	///业务单元
	TThostFtdcBusinessUnitType	BusinessUnit;
	///开平标志
	char	OffsetFlag;
	///投机套保标志
	char	HedgeFlag;
	///执行类型
	char	ActionType;
	///保留头寸申请的持仓方向
	char	PosiDirection;
	///期权行权后是否保留期货头寸的标记
	char	ReservePositionFlag;
	///期权行权后生成的头寸是否自动平仓
	char	CloseFlag;
	///本地执行宣告编号
	TThostFtdcOrderLocalIDType	ExecOrderLocalID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///会员代码
	TThostFtdcParticipantIDType	ParticipantID;
	///客户代码
	TThostFtdcClientIDType	ClientID;
	///合约在交易所的代码
	TThostFtdcExchangeInstIDType	ExchangeInstID;
	///交易所交易员代码
	TThostFtdcTraderIDType	TraderID;
	///安装编号
	int	InstallID;
	///执行宣告提交状态
	char	OrderSubmitStatus;
	///报单提示序号
	int	NotifySequence;
	///交易日
	TThostFtdcDateType	TradingDay;
	///结算编号
	int	SettlementID;
	///执行宣告编号
	TThostFtdcExecOrderSysIDType	ExecOrderSysID;
	///报单日期
	TThostFtdcDateType	InsertDate;
	///插入时间
	TThostFtdcTimeType	InsertTime;
	///撤销时间
	TThostFtdcTimeType	CancelTime;
	///执行结果
	char	ExecResult;
	///结算会员编号
	TThostFtdcParticipantIDType	ClearingPartID;
	///序号
	int	SequenceNo;
	///前置编号
	int	FrontID;
	///会话编号
	int	SessionID;
	///用户端产品信息
	TThostFtdcProductInfoType	UserProductInfo;
	///状态信息
	TThostFtdcErrorMsgType	StatusMsg;
	///操作用户代码
	TThostFtdcUserIDType	ActiveUserID;
	///经纪公司报单编号
	int	BrokerExecOrderSeq;
	///营业部编号
	TThostFtdcBranchIDType	BranchID;
	///投资单元代码
	TThostFtdcInvestUnitIDType	InvestUnitID;
	///资金账号
	TThostFtdcAccountIDType	AccountID;
	///币种代码
	TThostFtdcCurrencyIDType	CurrencyID;
	///IP地址
	TThostFtdcIPAddressType	IPAddress;
	///Mac地址
	TThostFtdcMacAddressType	MacAddress;
};

///执行宣告操作
struct CThostFtdcExecOrderActionField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///执行宣告操作引用
	int	ExecOrderActionRef;
	///执行宣告引用
	TThostFtdcOrderRefType	ExecOrderRef;
	///请求编号
	int	RequestID;
	///前置编号
	int	FrontID;
	///会话编号
	int	SessionID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///执行宣告操作编号
	TThostFtdcExecOrderSysIDType	ExecOrderSysID;
	///操作标志
	char	ActionFlag;
	///操作日期
	TThostFtdcDateType	ActionDate;
	///操作时间
	TThostFtdcTimeType	ActionTime;
	///交易所交易员代码
	TThostFtdcTraderIDType	TraderID;
	///安装编号
	int	InstallID;
	///本地执行宣告编号
	TThostFtdcOrderLocalIDType	ExecOrderLocalID;
	///操作本地编号
	TThostFtdcOrderLocalIDType	ActionLocalID;
	///会员代码
	TThostFtdcParticipantIDType	ParticipantID;
	///客户代码
	TThostFtdcClientIDType	ClientID;
	///业务单元
	TThostFtdcBusinessUnitType	BusinessUnit;
	///报单操作状态
	char	OrderActionStatus;
	///用户代码
	TThostFtdcUserIDType	UserID;
	///执行类型
	char	ActionType;
	///状态信息
	TThostFtdcErrorMsgType	StatusMsg;
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///营业部编号
	TThostFtdcBranchIDType	BranchID;
	///投资单元代码
	TThostFtdcInvestUnitIDType	InvestUnitID;
	///IP地址
	TThostFtdcIPAddressType	IPAddress;
	///Mac地址
	TThostFtdcMacAddressType	MacAddress;
};

///执行宣告查询
struct CThostFtdcQryExecOrderField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///执行宣告编号
	TThostFtdcExecOrderSysIDType	ExecOrderSysID;
	///开始时间
	TThostFtdcTimeType	InsertTimeStart;
	///结束时间
	TThostFtdcTimeType	InsertTimeEnd;
};

///交易所执行宣告信息
struct CThostFtdcExchangeExecOrderField
{
	///数量
	int	Volume;
	///请求编号
	int	RequestID;
	///业务单元
	TThostFtdcBusinessUnitType	BusinessUnit;
	///开平标志
	char	OffsetFlag;
	///投机套保标志
	char	HedgeFlag;
	///执行类型
	char	ActionType;
	///保留头寸申请的持仓方向
	char	PosiDirection;
	///期权行权后是否保留期货头寸的标记
	char	ReservePositionFlag;
	///期权行权后生成的头寸是否自动平仓
	char	CloseFlag;
	///本地执行宣告编号
	TThostFtdcOrderLocalIDType	ExecOrderLocalID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///会员代码
	TThostFtdcParticipantIDType	ParticipantID;
	///客户代码
	TThostFtdcClientIDType	ClientID;
	///合约在交易所的代码
	TThostFtdcExchangeInstIDType	ExchangeInstID;
	///交易所交易员代码
	TThostFtdcTraderIDType	TraderID;
	///安装编号
	int	InstallID;
	///执行宣告提交状态
	char	OrderSubmitStatus;
	///报单提示序号
	int	NotifySequence;
	///交易日
	TThostFtdcDateType	TradingDay;
	///结算编号
	int	SettlementID;
	///执行宣告编号
	TThostFtdcExecOrderSysIDType	ExecOrderSysID;
	///报单日期
	TThostFtdcDateType	InsertDate;
	///插入时间
	TThostFtdcTimeType	InsertTime;
	///撤销时间
	TThostFtdcTimeType	CancelTime;
	///执行结果
	char	ExecResult;
	///结算会员编号
	TThostFtdcParticipantIDType	ClearingPartID;
	///序号
	int	SequenceNo;
	///营业部编号
	TThostFtdcBranchIDType	BranchID;
	///IP地址
	TThostFtdcIPAddressType	IPAddress;
	///Mac地址
	TThostFtdcMacAddressType	MacAddress;
};

///交易所执行宣告查询
struct CThostFtdcQryExchangeExecOrderField
{
	///会员代码
	TThostFtdcParticipantIDType	ParticipantID;
	///客户代码
	TThostFtdcClientIDType	ClientID;
	///合约在交易所的代码
	TThostFtdcExchangeInstIDType	ExchangeInstID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///交易所交易员代码
	TThostFtdcTraderIDType	TraderID;
};

///执行宣告操作查询
struct CThostFtdcQryExecOrderActionField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
};

///交易所执行宣告操作
struct CThostFtdcExchangeExecOrderActionField
{
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///执行宣告操作编号
	TThostFtdcExecOrderSysIDType	ExecOrderSysID;
	///操作标志
	char	ActionFlag;
	///操作日期
	TThostFtdcDateType	ActionDate;
	///操作时间
	TThostFtdcTimeType	ActionTime;
	///交易所交易员代码
	TThostFtdcTraderIDType	TraderID;
	///安装编号
	int	InstallID;
	///本地执行宣告编号
	TThostFtdcOrderLocalIDType	ExecOrderLocalID;
	///操作本地编号
	TThostFtdcOrderLocalIDType	ActionLocalID;
	///会员代码
	TThostFtdcParticipantIDType	ParticipantID;
	///客户代码
	TThostFtdcClientIDType	ClientID;
	///业务单元
	TThostFtdcBusinessUnitType	BusinessUnit;
	///报单操作状态
	char	OrderActionStatus;
	///用户代码
	TThostFtdcUserIDType	UserID;
	///执行类型
	char	ActionType;
	///营业部编号
	TThostFtdcBranchIDType	BranchID;
	///IP地址
	TThostFtdcIPAddressType	IPAddress;
	///Mac地址
	TThostFtdcMacAddressType	MacAddress;
};

///交易所执行宣告操作查询
struct CThostFtdcQryExchangeExecOrderActionField
{
	///会员代码
	TThostFtdcParticipantIDType	ParticipantID;
	///客户代码
	TThostFtdcClientIDType	ClientID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///交易所交易员代码
	TThostFtdcTraderIDType	TraderID;
};

///错误执行宣告
struct CThostFtdcErrExecOrderField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///执行宣告引用
	TThostFtdcOrderRefType	ExecOrderRef;
	///用户代码
	TThostFtdcUserIDType	UserID;
	///数量
	int	Volume;
	///请求编号
	int	RequestID;
	///业务单元
	TThostFtdcBusinessUnitType	BusinessUnit;
	///开平标志
	char	OffsetFlag;
	///投机套保标志
	char	HedgeFlag;
	///执行类型
	char	ActionType;
	///保留头寸申请的持仓方向
	char	PosiDirection;
	///期权行权后是否保留期货头寸的标记
	char	ReservePositionFlag;
	///期权行权后生成的头寸是否自动平仓
	char	CloseFlag;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///投资单元代码
	TThostFtdcInvestUnitIDType	InvestUnitID;
	///资金账号
	TThostFtdcAccountIDType	AccountID;
	///币种代码
	TThostFtdcCurrencyIDType	CurrencyID;
	///交易编码
	TThostFtdcClientIDType	ClientID;
	///IP地址
	TThostFtdcIPAddressType	IPAddress;
	///Mac地址
	TThostFtdcMacAddressType	MacAddress;
	///错误代码
	int	ErrorID;
	///错误信息
	TThostFtdcErrorMsgType	ErrorMsg;
};

///查询错误执行宣告
struct CThostFtdcQryErrExecOrderField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
};

///错误执行宣告操作
struct CThostFtdcErrExecOrderActionField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///执行宣告操作引用
	int	ExecOrderActionRef;
	///执行宣告引用
	TThostFtdcOrderRefType	ExecOrderRef;
	///请求编号
	int	RequestID;
	///前置编号
	int	FrontID;
	///会话编号
	int	SessionID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///执行宣告操作编号
	TThostFtdcExecOrderSysIDType	ExecOrderSysID;
	///操作标志
	char	ActionFlag;
	///用户代码
	TThostFtdcUserIDType	UserID;
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///投资单元代码
	TThostFtdcInvestUnitIDType	InvestUnitID;
	///IP地址
	TThostFtdcIPAddressType	IPAddress;
	///Mac地址
	TThostFtdcMacAddressType	MacAddress;
	///错误代码
	int	ErrorID;
	///错误信息
	TThostFtdcErrorMsgType	ErrorMsg;
};

///查询错误执行宣告操作
struct CThostFtdcQryErrExecOrderActionField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
};

///投资者期权合约交易权限
struct CThostFtdcOptionInstrTradingRightField
{
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///投资者范围
	char	InvestorRange;
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///买卖方向
	char	Direction;
	///交易权限
	char	TradingRight;
};

///查询期权合约交易权限
struct CThostFtdcQryOptionInstrTradingRightField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///买卖方向
	char	Direction;
};

///输入的询价
struct CThostFtdcInputForQuoteField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///询价引用
	TThostFtdcOrderRefType	ForQuoteRef;
	///用户代码
	TThostFtdcUserIDType	UserID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///投资单元代码
	TThostFtdcInvestUnitIDType	InvestUnitID;
	///IP地址
	TThostFtdcIPAddressType	IPAddress;
	///Mac地址
	TThostFtdcMacAddressType	MacAddress;
};

///询价
struct CThostFtdcForQuoteField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///询价引用
	TThostFtdcOrderRefType	ForQuoteRef;
	///用户代码
	TThostFtdcUserIDType	UserID;
	///本地询价编号
	TThostFtdcOrderLocalIDType	ForQuoteLocalID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///会员代码
	TThostFtdcParticipantIDType	ParticipantID;
	///客户代码
	TThostFtdcClientIDType	ClientID;
	///合约在交易所的代码
	TThostFtdcExchangeInstIDType	ExchangeInstID;
	///交易所交易员代码
	TThostFtdcTraderIDType	TraderID;
	///安装编号
	int	InstallID;
	///报单日期
	TThostFtdcDateType	InsertDate;
	///插入时间
	TThostFtdcTimeType	InsertTime;
	///询价状态
	char	ForQuoteStatus;
	///前置编号
	int	FrontID;
	///会话编号
	int	SessionID;
	///状态信息
	TThostFtdcErrorMsgType	StatusMsg;
	///操作用户代码
	TThostFtdcUserIDType	ActiveUserID;
	///经纪公司询价编号
	int	BrokerForQutoSeq;
	///投资单元代码
	TThostFtdcInvestUnitIDType	InvestUnitID;
	///IP地址
	TThostFtdcIPAddressType	IPAddress;
	///Mac地址
	TThostFtdcMacAddressType	MacAddress;
};

///询价查询
struct CThostFtdcQryForQuoteField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///开始时间
	TThostFtdcTimeType	InsertTimeStart;
	///结束时间
	TThostFtdcTimeType	InsertTimeEnd;
};

///交易所询价信息
struct CThostFtdcExchangeForQuoteField
{
	///本地询价编号
	TThostFtdcOrderLocalIDType	ForQuoteLocalID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///会员代码
	TThostFtdcParticipantIDType	ParticipantID;
	///客户代码
	TThostFtdcClientIDType	ClientID;
	///合约在交易所的代码
	TThostFtdcExchangeInstIDType	ExchangeInstID;
	///交易所交易员代码
	TThostFtdcTraderIDType	TraderID;
	///安装编号
	int	InstallID;
	///报单日期
	TThostFtdcDateType	InsertDate;
	///插入时间
	TThostFtdcTimeType	InsertTime;
	///询价状态
	char	ForQuoteStatus;
	///IP地址
	TThostFtdcIPAddressType	IPAddress;
	///Mac地址
	TThostFtdcMacAddressType	MacAddress;
};

///交易所询价查询
struct CThostFtdcQryExchangeForQuoteField
{
	///会员代码
	TThostFtdcParticipantIDType	ParticipantID;
	///客户代码
	TThostFtdcClientIDType	ClientID;
	///合约在交易所的代码
	TThostFtdcExchangeInstIDType	ExchangeInstID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///交易所交易员代码
	TThostFtdcTraderIDType	TraderID;
};

///输入的报价
struct CThostFtdcInputQuoteField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///报价引用
	TThostFtdcOrderRefType	QuoteRef;
	///用户代码
	TThostFtdcUserIDType	UserID;
	///卖价格
	double	AskPrice;
	///买价格
	double	BidPrice;
	///卖数量
	int	AskVolume;
	///买数量
	int	BidVolume;
	///请求编号
	int	RequestID;
	///业务单元
	TThostFtdcBusinessUnitType	BusinessUnit;
	///卖开平标志
	char	AskOffsetFlag;
	///买开平标志
	char	BidOffsetFlag;
	///卖投机套保标志
	char	AskHedgeFlag;
	///买投机套保标志
	char	BidHedgeFlag;
	///衍生卖报单引用
	TThostFtdcOrderRefType	AskOrderRef;
	///衍生买报单引用
	TThostFtdcOrderRefType	BidOrderRef;
	///应价编号
	TThostFtdcOrderSysIDType	ForQuoteSysID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///投资单元代码
	TThostFtdcInvestUnitIDType	InvestUnitID;
	///交易编码
	TThostFtdcClientIDType	ClientID;
	///IP地址
	TThostFtdcIPAddressType	IPAddress;
	///Mac地址
	TThostFtdcMacAddressType	MacAddress;
};

///输入报价操作
struct CThostFtdcInputQuoteActionField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///报价操作引用
	int	QuoteActionRef;
	///报价引用
	TThostFtdcOrderRefType	QuoteRef;
	///请求编号
	int	RequestID;
	///前置编号
	int	FrontID;
	///会话编号
	int	SessionID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///报价操作编号
	TThostFtdcOrderSysIDType	QuoteSysID;
	///操作标志
	char	ActionFlag;
	///用户代码
	TThostFtdcUserIDType	UserID;
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///投资单元代码
	TThostFtdcInvestUnitIDType	InvestUnitID;
	///交易编码
	TThostFtdcClientIDType	ClientID;
	///IP地址
	TThostFtdcIPAddressType	IPAddress;
	///Mac地址
	TThostFtdcMacAddressType	MacAddress;
};

///报价
struct CThostFtdcQuoteField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///报价引用
	TThostFtdcOrderRefType	QuoteRef;
	///用户代码
	TThostFtdcUserIDType	UserID;
	///卖价格
	double	AskPrice;
	///买价格
	double	BidPrice;
	///卖数量
	int	AskVolume;
	///买数量
	int	BidVolume;
	///请求编号
	int	RequestID;
	///业务单元
	TThostFtdcBusinessUnitType	BusinessUnit;
	///卖开平标志
	char	AskOffsetFlag;
	///买开平标志
	char	BidOffsetFlag;
	///卖投机套保标志
	char	AskHedgeFlag;
	///买投机套保标志
	char	BidHedgeFlag;
	///本地报价编号
	TThostFtdcOrderLocalIDType	QuoteLocalID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///会员代码
	TThostFtdcParticipantIDType	ParticipantID;
	///客户代码
	TThostFtdcClientIDType	ClientID;
	///合约在交易所的代码
	TThostFtdcExchangeInstIDType	ExchangeInstID;
	///交易所交易员代码
	TThostFtdcTraderIDType	TraderID;
	///安装编号
	int	InstallID;
	///报价提示序号
	int	NotifySequence;
	///报价提交状态
	char	OrderSubmitStatus;
	///交易日
	TThostFtdcDateType	TradingDay;
	///结算编号
	int	SettlementID;
	///报价编号
	TThostFtdcOrderSysIDType	QuoteSysID;
	///报单日期
	TThostFtdcDateType	InsertDate;
	///插入时间
	TThostFtdcTimeType	InsertTime;
	///撤销时间
	TThostFtdcTimeType	CancelTime;
	///报价状态
	char	QuoteStatus;
	///结算会员编号
	TThostFtdcParticipantIDType	ClearingPartID;
	///序号
	int	SequenceNo;
	///卖方报单编号
	TThostFtdcOrderSysIDType	AskOrderSysID;
	///买方报单编号
	TThostFtdcOrderSysIDType	BidOrderSysID;
	///前置编号
	int	FrontID;
	///会话编号
	int	SessionID;
	///用户端产品信息
	TThostFtdcProductInfoType	UserProductInfo;
	///状态信息
	TThostFtdcErrorMsgType	StatusMsg;
	///操作用户代码
	TThostFtdcUserIDType	ActiveUserID;
	///经纪公司报价编号
	int	BrokerQuoteSeq;
	///衍生卖报单引用
	TThostFtdcOrderRefType	AskOrderRef;
	///衍生买报单引用
	TThostFtdcOrderRefType	BidOrderRef;
	///应价编号
	TThostFtdcOrderSysIDType	ForQuoteSysID;
	///营业部编号
	TThostFtdcBranchIDType	BranchID;
	///投资单元代码
	TThostFtdcInvestUnitIDType	InvestUnitID;
	///资金账号
	TThostFtdcAccountIDType	AccountID;
	///币种代码
	TThostFtdcCurrencyIDType	CurrencyID;
	///IP地址
	TThostFtdcIPAddressType	IPAddress;
	///Mac地址
	TThostFtdcMacAddressType	MacAddress;
};

///报价操作
struct CThostFtdcQuoteActionField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///报价操作引用
	int	QuoteActionRef;
	///报价引用
	TThostFtdcOrderRefType	QuoteRef;
	///请求编号
	int	RequestID;
	///前置编号
	int	FrontID;
	///会话编号
	int	SessionID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///报价操作编号
	TThostFtdcOrderSysIDType	QuoteSysID;
	///操作标志
	char	ActionFlag;
	///操作日期
	TThostFtdcDateType	ActionDate;
	///操作时间
	TThostFtdcTimeType	ActionTime;
	///交易所交易员代码
	TThostFtdcTraderIDType	TraderID;
	///安装编号
	int	InstallID;
	///本地报价编号
	TThostFtdcOrderLocalIDType	QuoteLocalID;
	///操作本地编号
	TThostFtdcOrderLocalIDType	ActionLocalID;
	///会员代码
	TThostFtdcParticipantIDType	ParticipantID;
	///客户代码
	TThostFtdcClientIDType	ClientID;
	///业务单元
	TThostFtdcBusinessUnitType	BusinessUnit;
	///报单操作状态
	char	OrderActionStatus;
	///用户代码
	TThostFtdcUserIDType	UserID;
	///状态信息
	TThostFtdcErrorMsgType	StatusMsg;
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///营业部编号
	TThostFtdcBranchIDType	BranchID;
	///投资单元代码
	TThostFtdcInvestUnitIDType	InvestUnitID;
	///IP地址
	TThostFtdcIPAddressType	IPAddress;
	///Mac地址
	TThostFtdcMacAddressType	MacAddress;
};

///报价查询
struct CThostFtdcQryQuoteField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///报价编号
	TThostFtdcOrderSysIDType	QuoteSysID;
	///开始时间
	TThostFtdcTimeType	InsertTimeStart;
	///结束时间
	TThostFtdcTimeType	InsertTimeEnd;
};

///交易所报价信息
struct CThostFtdcExchangeQuoteField
{
	///卖价格
	double	AskPrice;
	///买价格
	double	BidPrice;
	///卖数量
	int	AskVolume;
	///买数量
	int	BidVolume;
	///请求编号
	int	RequestID;
	///业务单元
	TThostFtdcBusinessUnitType	BusinessUnit;
	///卖开平标志
	char	AskOffsetFlag;
	///买开平标志
	char	BidOffsetFlag;
	///卖投机套保标志
	char	AskHedgeFlag;
	///买投机套保标志
	char	BidHedgeFlag;
	///本地报价编号
	TThostFtdcOrderLocalIDType	QuoteLocalID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///会员代码
	TThostFtdcParticipantIDType	ParticipantID;
	///客户代码
	TThostFtdcClientIDType	ClientID;
	///合约在交易所的代码
	TThostFtdcExchangeInstIDType	ExchangeInstID;
	///交易所交易员代码
	TThostFtdcTraderIDType	TraderID;
	///安装编号
	int	InstallID;
	///报价提示序号
	int	NotifySequence;
	///报价提交状态
	char	OrderSubmitStatus;
	///交易日
	TThostFtdcDateType	TradingDay;
	///结算编号
	int	SettlementID;
	///报价编号
	TThostFtdcOrderSysIDType	QuoteSysID;
	///报单日期
	TThostFtdcDateType	InsertDate;
	///插入时间
	TThostFtdcTimeType	InsertTime;
	///撤销时间
	TThostFtdcTimeType	CancelTime;
	///报价状态
	char	QuoteStatus;
	///结算会员编号
	TThostFtdcParticipantIDType	ClearingPartID;
	///序号
	int	SequenceNo;
	///卖方报单编号
	TThostFtdcOrderSysIDType	AskOrderSysID;
	///买方报单编号
	TThostFtdcOrderSysIDType	BidOrderSysID;
	///应价编号
	TThostFtdcOrderSysIDType	ForQuoteSysID;
	///营业部编号
	TThostFtdcBranchIDType	BranchID;
	///IP地址
	TThostFtdcIPAddressType	IPAddress;
	///Mac地址
	TThostFtdcMacAddressType	MacAddress;
};

///交易所报价查询
struct CThostFtdcQryExchangeQuoteField
{
	///会员代码
	TThostFtdcParticipantIDType	ParticipantID;
	///客户代码
	TThostFtdcClientIDType	ClientID;
	///合约在交易所的代码
	TThostFtdcExchangeInstIDType	ExchangeInstID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///交易所交易员代码
	TThostFtdcTraderIDType	TraderID;
};

///报价操作查询
struct CThostFtdcQryQuoteActionField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
};

///交易所报价操作
struct CThostFtdcExchangeQuoteActionField
{
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///报价操作编号
	TThostFtdcOrderSysIDType	QuoteSysID;
	///操作标志
	char	ActionFlag;
	///操作日期
	TThostFtdcDateType	ActionDate;
	///操作时间
	TThostFtdcTimeType	ActionTime;
	///交易所交易员代码
	TThostFtdcTraderIDType	TraderID;
	///安装编号
	int	InstallID;
	///本地报价编号
	TThostFtdcOrderLocalIDType	QuoteLocalID;
	///操作本地编号
	TThostFtdcOrderLocalIDType	ActionLocalID;
	///会员代码
	TThostFtdcParticipantIDType	ParticipantID;
	///客户代码
	TThostFtdcClientIDType	ClientID;
	///业务单元
	TThostFtdcBusinessUnitType	BusinessUnit;
	///报单操作状态
	char	OrderActionStatus;
	///用户代码
	TThostFtdcUserIDType	UserID;
	///IP地址
	TThostFtdcIPAddressType	IPAddress;
	///Mac地址
	TThostFtdcMacAddressType	MacAddress;
};

///交易所报价操作查询
struct CThostFtdcQryExchangeQuoteActionField
{
	///会员代码
	TThostFtdcParticipantIDType	ParticipantID;
	///客户代码
	TThostFtdcClientIDType	ClientID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///交易所交易员代码
	TThostFtdcTraderIDType	TraderID;
};

///期权合约delta值
struct CThostFtdcOptionInstrDeltaField
{
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///投资者范围
	char	InvestorRange;
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///Delta值
	double	Delta;
};

///发给做市商的询价请求
struct CThostFtdcForQuoteRspField
{
	///交易日
	TThostFtdcDateType	TradingDay;
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///询价编号
	TThostFtdcOrderSysIDType	ForQuoteSysID;
	///询价时间
	TThostFtdcTimeType	ForQuoteTime;
	///业务日期
	TThostFtdcDateType	ActionDay;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
};

///当前期权合约执行偏移值的详细内容
struct CThostFtdcStrikeOffsetField
{
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///投资者范围
	char	InvestorRange;
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///执行偏移值
	double	Offset;
	///执行偏移类型
	char	OffsetType;
};

///期权执行偏移值查询
struct CThostFtdcQryStrikeOffsetField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
};

///输入批量报单操作
struct CThostFtdcInputBatchOrderActionField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///报单操作引用
	int	OrderActionRef;
	///请求编号
	int	RequestID;
	///前置编号
	int	FrontID;
	///会话编号
	int	SessionID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///用户代码
	TThostFtdcUserIDType	UserID;
	///投资单元代码
	TThostFtdcInvestUnitIDType	InvestUnitID;
	///IP地址
	TThostFtdcIPAddressType	IPAddress;
	///Mac地址
	TThostFtdcMacAddressType	MacAddress;
};

///批量报单操作
struct CThostFtdcBatchOrderActionField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///报单操作引用
	int	OrderActionRef;
	///请求编号
	int	RequestID;
	///前置编号
	int	FrontID;
	///会话编号
	int	SessionID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///操作日期
	TThostFtdcDateType	ActionDate;
	///操作时间
	TThostFtdcTimeType	ActionTime;
	///交易所交易员代码
	TThostFtdcTraderIDType	TraderID;
	///安装编号
	int	InstallID;
	///操作本地编号
	TThostFtdcOrderLocalIDType	ActionLocalID;
	///会员代码
	TThostFtdcParticipantIDType	ParticipantID;
	///客户代码
	TThostFtdcClientIDType	ClientID;
	///业务单元
	TThostFtdcBusinessUnitType	BusinessUnit;
	///报单操作状态
	char	OrderActionStatus;
	///用户代码
	TThostFtdcUserIDType	UserID;
	///状态信息
	TThostFtdcErrorMsgType	StatusMsg;
	///投资单元代码
	TThostFtdcInvestUnitIDType	InvestUnitID;
	///IP地址
	TThostFtdcIPAddressType	IPAddress;
	///Mac地址
	TThostFtdcMacAddressType	MacAddress;
};

///交易所批量报单操作
struct CThostFtdcExchangeBatchOrderActionField
{
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///操作日期
	TThostFtdcDateType	ActionDate;
	///操作时间
	TThostFtdcTimeType	ActionTime;
	///交易所交易员代码
	TThostFtdcTraderIDType	TraderID;
	///安装编号
	int	InstallID;
	///操作本地编号
	TThostFtdcOrderLocalIDType	ActionLocalID;
	///会员代码
	TThostFtdcParticipantIDType	ParticipantID;
	///客户代码
	TThostFtdcClientIDType	ClientID;
	///业务单元
	TThostFtdcBusinessUnitType	BusinessUnit;
	///报单操作状态
	char	OrderActionStatus;
	///用户代码
	TThostFtdcUserIDType	UserID;
	///IP地址
	TThostFtdcIPAddressType	IPAddress;
	///Mac地址
	TThostFtdcMacAddressType	MacAddress;
};

///查询批量报单操作
struct CThostFtdcQryBatchOrderActionField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
};

///组合合约安全系数
struct CThostFtdcCombInstrumentGuardField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///
	double	GuarantRatio;
};

///组合合约安全系数查询
struct CThostFtdcQryCombInstrumentGuardField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
};

///输入的申请组合
struct CThostFtdcInputCombActionField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///组合引用
	TThostFtdcOrderRefType	CombActionRef;
	///用户代码
	TThostFtdcUserIDType	UserID;
	///买卖方向
	char	Direction;
	///数量
	int	Volume;
	///组合指令方向
	char	CombDirection;
	///投机套保标志
	char	HedgeFlag;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///IP地址
	TThostFtdcIPAddressType	IPAddress;
	///Mac地址
	TThostFtdcMacAddressType	MacAddress;
};

///申请组合
struct CThostFtdcCombActionField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///组合引用
	TThostFtdcOrderRefType	CombActionRef;
	///用户代码
	TThostFtdcUserIDType	UserID;
	///买卖方向
	char	Direction;
	///数量
	int	Volume;
	///组合指令方向
	char	CombDirection;
	///投机套保标志
	char	HedgeFlag;
	///本地申请组合编号
	TThostFtdcOrderLocalIDType	ActionLocalID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///会员代码
	TThostFtdcParticipantIDType	ParticipantID;
	///客户代码
	TThostFtdcClientIDType	ClientID;
	///合约在交易所的代码
	TThostFtdcExchangeInstIDType	ExchangeInstID;
	///交易所交易员代码
	TThostFtdcTraderIDType	TraderID;
	///安装编号
	int	InstallID;
	///组合状态
	char	ActionStatus;
	///报单提示序号
	int	NotifySequence;
	///交易日
	TThostFtdcDateType	TradingDay;
	///结算编号
	int	SettlementID;
	///序号
	int	SequenceNo;
	///前置编号
	int	FrontID;
	///会话编号
	int	SessionID;
	///用户端产品信息
	TThostFtdcProductInfoType	UserProductInfo;
	///状态信息
	TThostFtdcErrorMsgType	StatusMsg;
	///IP地址
	TThostFtdcIPAddressType	IPAddress;
	///Mac地址
	TThostFtdcMacAddressType	MacAddress;
};

///申请组合查询
struct CThostFtdcQryCombActionField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
};

///交易所申请组合信息
struct CThostFtdcExchangeCombActionField
{
	///买卖方向
	char	Direction;
	///数量
	int	Volume;
	///组合指令方向
	char	CombDirection;
	///投机套保标志
	char	HedgeFlag;
	///本地申请组合编号
	TThostFtdcOrderLocalIDType	ActionLocalID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///会员代码
	TThostFtdcParticipantIDType	ParticipantID;
	///客户代码
	TThostFtdcClientIDType	ClientID;
	///合约在交易所的代码
	TThostFtdcExchangeInstIDType	ExchangeInstID;
	///交易所交易员代码
	TThostFtdcTraderIDType	TraderID;
	///安装编号
	int	InstallID;
	///组合状态
	char	ActionStatus;
	///报单提示序号
	int	NotifySequence;
	///交易日
	TThostFtdcDateType	TradingDay;
	///结算编号
	int	SettlementID;
	///序号
	int	SequenceNo;
	///IP地址
	TThostFtdcIPAddressType	IPAddress;
	///Mac地址
	TThostFtdcMacAddressType	MacAddress;
};

///交易所申请组合查询
struct CThostFtdcQryExchangeCombActionField
{
	///会员代码
	TThostFtdcParticipantIDType	ParticipantID;
	///客户代码
	TThostFtdcClientIDType	ClientID;
	///合约在交易所的代码
	TThostFtdcExchangeInstIDType	ExchangeInstID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///交易所交易员代码
	TThostFtdcTraderIDType	TraderID;
};

///产品报价汇率
struct CThostFtdcProductExchRateField
{
	///产品代码
	TThostFtdcInstrumentIDType	ProductID;
	///报价币种类型
	TThostFtdcCurrencyIDType	QuoteCurrencyID;
	///汇率
	double	ExchangeRate;
};

///产品报价汇率查询
struct CThostFtdcQryProductExchRateField
{
	///产品代码
	TThostFtdcInstrumentIDType	ProductID;
};

///查询询价价差参数
struct CThostFtdcQryForQuoteParamField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
};

///询价价差参数
struct CThostFtdcForQuoteParamField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///最新价
	double	LastPrice;
	///价差
	double	PriceInterval;
};

///当前做市商期权合约手续费的详细内容
struct CThostFtdcMMOptionInstrCommRateField
{
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///投资者范围
	char	InvestorRange;
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///开仓手续费率
	double	OpenRatioByMoney;
	///开仓手续费
	double	OpenRatioByVolume;
	///平仓手续费率
	double	CloseRatioByMoney;
	///平仓手续费
	double	CloseRatioByVolume;
	///平今手续费率
	double	CloseTodayRatioByMoney;
	///平今手续费
	double	CloseTodayRatioByVolume;
	///执行手续费率
	double	StrikeRatioByMoney;
	///执行手续费
	double	StrikeRatioByVolume;
};

///做市商期权手续费率查询
struct CThostFtdcQryMMOptionInstrCommRateField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
};

///做市商合约手续费率
struct CThostFtdcMMInstrumentCommissionRateField
{
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///投资者范围
	char	InvestorRange;
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///开仓手续费率
	double	OpenRatioByMoney;
	///开仓手续费
	double	OpenRatioByVolume;
	///平仓手续费率
	double	CloseRatioByMoney;
	///平仓手续费
	double	CloseRatioByVolume;
	///平今手续费率
	double	CloseTodayRatioByMoney;
	///平今手续费
	double	CloseTodayRatioByVolume;
};

///查询做市商合约手续费率
struct CThostFtdcQryMMInstrumentCommissionRateField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
};

///当前报单手续费的详细内容
struct CThostFtdcInstrumentOrderCommRateField
{
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///投资者范围
	char	InvestorRange;
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///投机套保标志
	char	HedgeFlag;
	///报单手续费
	double	OrderCommByVolume;
	///撤单手续费
	double	OrderActionCommByVolume;
};

///报单手续费率查询
struct CThostFtdcQryInstrumentOrderCommRateField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
};

///市场行情
struct CThostFtdcMarketDataField
{
	///交易日
	TThostFtdcDateType	TradingDay;
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///合约在交易所的代码
	TThostFtdcExchangeInstIDType	ExchangeInstID;
	///最新价
	double	LastPrice;
	///上次结算价
	double	PreSettlementPrice;
	///昨收盘
	double	PreClosePrice;
	///昨持仓量
	double	PreOpenInterest;
	///今开盘
	double	OpenPrice;
	///最高价
	double	HighestPrice;
	///最低价
	double	LowestPrice;
	///数量
	int	Volume;
	///成交金额
	double	Turnover;
	///持仓量
	double	OpenInterest;
	///今收盘
	double	ClosePrice;
	///本次结算价
	double	SettlementPrice;
	///涨停板价
	double	UpperLimitPrice;
	///跌停板价
	double	LowerLimitPrice;
	///昨虚实度
	double	PreDelta;
	///今虚实度
	double	CurrDelta;
	///最后修改时间
	TThostFtdcTimeType	UpdateTime;
	///最后修改毫秒
	int	UpdateMillisec;
	///业务日期
	TThostFtdcDateType	ActionDay;
};

///行情基础属性
struct CThostFtdcMarketDataBaseField
{
	///交易日
	TThostFtdcDateType	TradingDay;
	///上次结算价
	double	PreSettlementPrice;
	///昨收盘
	double	PreClosePrice;
	///昨持仓量
	double	PreOpenInterest;
	///昨虚实度
	double	PreDelta;
};

///行情静态属性
struct CThostFtdcMarketDataStaticField
{
	///今开盘
	double	OpenPrice;
	///最高价
	double	HighestPrice;
	///最低价
	double	LowestPrice;
	///今收盘
	double	ClosePrice;
	///涨停板价
	double	UpperLimitPrice;
	///跌停板价
	double	LowerLimitPrice;
	///本次结算价
	double	SettlementPrice;
	///今虚实度
	double	CurrDelta;
};

///行情最新成交属性
struct CThostFtdcMarketDataLastMatchField
{
	///最新价
	double	LastPrice;
	///数量
	int	Volume;
	///成交金额
	double	Turnover;
	///持仓量
	double	OpenInterest;
};

///行情最优价属性
struct CThostFtdcMarketDataBestPriceField
{
	///申买价一
	double	BidPrice1;
	///申买量一
	int	BidVolume1;
	///申卖价一
	double	AskPrice1;
	///申卖量一
	int	AskVolume1;
};

///行情申买二、三属性
struct CThostFtdcMarketDataBid23Field
{
	///申买价二
	double	BidPrice2;
	///申买量二
	int	BidVolume2;
	///申买价三
	double	BidPrice3;
	///申买量三
	int	BidVolume3;
};

///行情申卖二、三属性
struct CThostFtdcMarketDataAsk23Field
{
	///申卖价二
	double	AskPrice2;
	///申卖量二
	int	AskVolume2;
	///申卖价三
	double	AskPrice3;
	///申卖量三
	int	AskVolume3;
};

///行情申买四、五属性
struct CThostFtdcMarketDataBid45Field
{
	///申买价四
	double	BidPrice4;
	///申买量四
	int	BidVolume4;
	///申买价五
	double	BidPrice5;
	///申买量五
	int	BidVolume5;
};

///行情申卖四、五属性
struct CThostFtdcMarketDataAsk45Field
{
	///申卖价四
	double	AskPrice4;
	///申卖量四
	int	AskVolume4;
	///申卖价五
	double	AskPrice5;
	///申卖量五
	int	AskVolume5;
};

///行情更新时间属性
struct CThostFtdcMarketDataUpdateTimeField
{
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///最后修改时间
	TThostFtdcTimeType	UpdateTime;
	///最后修改毫秒
	int	UpdateMillisec;
	///业务日期
	TThostFtdcDateType	ActionDay;
};

///行情交易所代码属性
struct CThostFtdcMarketDataExchangeField
{
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
};

///指定的合约
struct CThostFtdcSpecificInstrumentField
{
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
};

///合约状态
struct CThostFtdcInstrumentStatusField
{
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///合约在交易所的代码
	TThostFtdcExchangeInstIDType	ExchangeInstID;
	///结算组代码
	TThostFtdcSettlementGroupIDType	SettlementGroupID;
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///合约交易状态
	char	InstrumentStatus;
	///交易阶段编号
	int	TradingSegmentSN;
	///进入本状态时间
	TThostFtdcTimeType	EnterTime;
	///进入本状态原因
	char	EnterReason;
};

///查询合约状态
struct CThostFtdcQryInstrumentStatusField
{
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///合约在交易所的代码
	TThostFtdcExchangeInstIDType	ExchangeInstID;
};

///投资者账户
struct CThostFtdcInvestorAccountField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///投资者帐号
	TThostFtdcAccountIDType	AccountID;
	///币种代码
	TThostFtdcCurrencyIDType	CurrencyID;
};

///浮动盈亏算法
struct CThostFtdcPositionProfitAlgorithmField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者帐号
	TThostFtdcAccountIDType	AccountID;
	///盈亏算法
	char	Algorithm;
	///备注
	TThostFtdcMemoType	Memo;
	///币种代码
	TThostFtdcCurrencyIDType	CurrencyID;
};

///会员资金折扣
struct CThostFtdcDiscountField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者范围
	char	InvestorRange;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///资金折扣比例
	double	Discount;
};

///查询转帐银行
struct CThostFtdcQryTransferBankField
{
	///银行代码
	TThostFtdcBankIDType	BankID;
	///银行分中心代码
	TThostFtdcBankBrchIDType	BankBrchID;
};

///转帐银行
struct CThostFtdcTransferBankField
{
	///银行代码
	TThostFtdcBankIDType	BankID;
	///银行分中心代码
	TThostFtdcBankBrchIDType	BankBrchID;
	///银行名称
	TThostFtdcBankNameType	BankName;
	///是否活跃
	int	IsActive;
};

///查询投资者持仓明细
struct CThostFtdcQryInvestorPositionDetailField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
};

///投资者持仓明细
struct CThostFtdcInvestorPositionDetailField
{
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///投机套保标志
	char	HedgeFlag;
	///买卖
	char	Direction;
	///开仓日期
	TThostFtdcDateType	OpenDate;
	///成交编号
	TThostFtdcTradeIDType	TradeID;
	///数量
	int	Volume;
	///开仓价
	double	OpenPrice;
	///交易日
	TThostFtdcDateType	TradingDay;
	///结算编号
	int	SettlementID;
	///成交类型
	char	TradeType;
	///组合合约代码
	TThostFtdcInstrumentIDType	CombInstrumentID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///逐日盯市平仓盈亏
	double	CloseProfitByDate;
	///逐笔对冲平仓盈亏
	double	CloseProfitByTrade;
	///逐日盯市持仓盈亏
	double	PositionProfitByDate;
	///逐笔对冲持仓盈亏
	double	PositionProfitByTrade;
	///投资者保证金
	double	Margin;
	///交易所保证金
	double	ExchMargin;
	///保证金率
	double	MarginRateByMoney;
	///保证金率(按手数)
	double	MarginRateByVolume;
	///昨结算价
	double	LastSettlementPrice;
	///结算价
	double	SettlementPrice;
	///平仓量
	int	CloseVolume;
	///平仓金额
	double	CloseAmount;
};

///资金账户口令域
struct CThostFtdcTradingAccountPasswordField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者帐号
	TThostFtdcAccountIDType	AccountID;
	///密码
	TThostFtdcPasswordType	Password;
	///币种代码
	TThostFtdcCurrencyIDType	CurrencyID;
};

///交易所行情报盘机
struct CThostFtdcMDTraderOfferField
{
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///交易所交易员代码
	TThostFtdcTraderIDType	TraderID;
	///会员代码
	TThostFtdcParticipantIDType	ParticipantID;
	///密码
	TThostFtdcPasswordType	Password;
	///安装编号
	int	InstallID;
	///本地报单编号
	TThostFtdcOrderLocalIDType	OrderLocalID;
	///交易所交易员连接状态
	char	TraderConnectStatus;
	///发出连接请求的日期
	TThostFtdcDateType	ConnectRequestDate;
	///发出连接请求的时间
	TThostFtdcTimeType	ConnectRequestTime;
	///上次报告日期
	TThostFtdcDateType	LastReportDate;
	///上次报告时间
	TThostFtdcTimeType	LastReportTime;
	///完成连接日期
	TThostFtdcDateType	ConnectDate;
	///完成连接时间
	TThostFtdcTimeType	ConnectTime;
	///启动日期
	TThostFtdcDateType	StartDate;
	///启动时间
	TThostFtdcTimeType	StartTime;
	///交易日
	TThostFtdcDateType	TradingDay;
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///本席位最大成交编号
	TThostFtdcTradeIDType	MaxTradeID;
	///本席位最大报单备拷
	TThostFtdcReturnCodeType	MaxOrderMessageReference;
};

///查询行情报盘机
struct CThostFtdcQryMDTraderOfferField
{
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///会员代码
	TThostFtdcParticipantIDType	ParticipantID;
	///交易所交易员代码
	TThostFtdcTraderIDType	TraderID;
};

///查询客户通知
struct CThostFtdcQryNoticeField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
};

///客户通知
struct CThostFtdcNoticeField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///消息正文
	TThostFtdcContentType	Content;
	///经纪公司通知内容序列号
	TThostFtdcSequenceLabelType	SequenceLabel;
};

///用户权限
struct CThostFtdcUserRightField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///用户代码
	TThostFtdcUserIDType	UserID;
	///客户权限类型
	char	UserRightType;
	///是否禁止
	int	IsForbidden;
};

///查询结算信息确认域
struct CThostFtdcQrySettlementInfoConfirmField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
};

///装载结算信息
struct CThostFtdcLoadSettlementInfoField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
};

///经纪公司可提资金算法表
struct CThostFtdcBrokerWithdrawAlgorithmField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///可提资金算法
	char	WithdrawAlgorithm;
	///资金使用率
	double	UsingRatio;
	///可提是否包含平仓盈利
	char	IncludeCloseProfit;
	///本日无仓且无成交客户是否受可提比例限制
	char	AllWithoutTrade;
	///可用是否包含平仓盈利
	char	AvailIncludeCloseProfit;
	///是否启用用户事件
	int	IsBrokerUserEvent;
	///币种代码
	TThostFtdcCurrencyIDType	CurrencyID;
	///货币质押比率
	double	FundMortgageRatio;
	///权益算法
	char	BalanceAlgorithm;
};

///资金账户口令变更域
struct CThostFtdcTradingAccountPasswordUpdateV1Field
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///原来的口令
	TThostFtdcPasswordType	OldPassword;
	///新的口令
	TThostFtdcPasswordType	NewPassword;
};

///资金账户口令变更域
struct CThostFtdcTradingAccountPasswordUpdateField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者帐号
	TThostFtdcAccountIDType	AccountID;
	///原来的口令
	TThostFtdcPasswordType	OldPassword;
	///新的口令
	TThostFtdcPasswordType	NewPassword;
	///币种代码
	TThostFtdcCurrencyIDType	CurrencyID;
};

///查询组合合约分腿
struct CThostFtdcQryCombinationLegField
{
	///组合合约代码
	TThostFtdcInstrumentIDType	CombInstrumentID;
	///单腿编号
	int	LegID;
	///单腿合约代码
	TThostFtdcInstrumentIDType	LegInstrumentID;
};

///查询组合合约分腿
struct CThostFtdcQrySyncStatusField
{
	///交易日
	TThostFtdcDateType	TradingDay;
};

///组合交易合约的单腿
struct CThostFtdcCombinationLegField
{
	///组合合约代码
	TThostFtdcInstrumentIDType	CombInstrumentID;
	///单腿编号
	int	LegID;
	///单腿合约代码
	TThostFtdcInstrumentIDType	LegInstrumentID;
	///买卖方向
	char	Direction;
	///单腿乘数
	int	LegMultiple;
	///派生层数
	int	ImplyLevel;
};

///数据同步状态
struct CThostFtdcSyncStatusField
{
	///交易日
	TThostFtdcDateType	TradingDay;
	///数据同步状态
	char	DataSyncStatus;
};

///查询联系人
struct CThostFtdcQryLinkManField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
};

///联系人
struct CThostFtdcLinkManField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///联系人类型
	char	PersonType;
	///证件类型
	char	IdentifiedCardType;
	///证件号码
	TThostFtdcIdentifiedCardNoType	IdentifiedCardNo;
	///名称
	TThostFtdcPartyNameType	PersonName;
	///联系电话
	TThostFtdcTelephoneType	Telephone;
	///通讯地址
	TThostFtdcAddressType	Address;
	///邮政编码
	TThostFtdcZipCodeType	ZipCode;
	///优先级
	int	Priority;
	///开户邮政编码
	TThostFtdcUOAZipCodeType	UOAZipCode;
	///全称
	TThostFtdcInvestorFullNameType	PersonFullName;
};

///查询经纪公司用户事件
struct CThostFtdcQryBrokerUserEventField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///用户代码
	TThostFtdcUserIDType	UserID;
	///用户事件类型
	char	UserEventType;
};

///查询经纪公司用户事件
struct CThostFtdcBrokerUserEventField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///用户代码
	TThostFtdcUserIDType	UserID;
	///用户事件类型
	char	UserEventType;
	///用户事件序号
	int	EventSequenceNo;
	///事件发生日期
	TThostFtdcDateType	EventDate;
	///事件发生时间
	TThostFtdcTimeType	EventTime;
	///用户事件信息
	TThostFtdcUserEventInfoType	UserEventInfo;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
};

///查询签约银行请求
struct CThostFtdcQryContractBankField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///银行代码
	TThostFtdcBankIDType	BankID;
	///银行分中心代码
	TThostFtdcBankBrchIDType	BankBrchID;
};

///查询签约银行响应
struct CThostFtdcContractBankField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///银行代码
	TThostFtdcBankIDType	BankID;
	///银行分中心代码
	TThostFtdcBankBrchIDType	BankBrchID;
	///银行名称
	TThostFtdcBankNameType	BankName;
};

///投资者组合持仓明细
struct CThostFtdcInvestorPositionCombineDetailField
{
	///交易日
	TThostFtdcDateType	TradingDay;
	///开仓日期
	TThostFtdcDateType	OpenDate;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///结算编号
	int	SettlementID;
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///组合编号
	TThostFtdcTradeIDType	ComTradeID;
	///撮合编号
	TThostFtdcTradeIDType	TradeID;
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///投机套保标志
	char	HedgeFlag;
	///买卖
	char	Direction;
	///持仓量
	int	TotalAmt;
	///投资者保证金
	double	Margin;
	///交易所保证金
	double	ExchMargin;
	///保证金率
	double	MarginRateByMoney;
	///保证金率(按手数)
	double	MarginRateByVolume;
	///单腿编号
	int	LegID;
	///单腿乘数
	int	LegMultiple;
	///组合持仓合约编码
	TThostFtdcInstrumentIDType	CombInstrumentID;
	///成交组号
	int	TradeGroupID;
};

///预埋单
struct CThostFtdcParkedOrderField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///报单引用
	TThostFtdcOrderRefType	OrderRef;
	///用户代码
	TThostFtdcUserIDType	UserID;
	///报单价格条件
	char	OrderPriceType;
	///买卖方向
	char	Direction;
	///组合开平标志
	TThostFtdcCombOffsetFlagType	CombOffsetFlag;
	///组合投机套保标志
	TThostFtdcCombHedgeFlagType	CombHedgeFlag;
	///价格
	double	LimitPrice;
	///数量
	int	VolumeTotalOriginal;
	///有效期类型
	char	TimeCondition;
	///GTD日期
	TThostFtdcDateType	GTDDate;
	///成交量类型
	char	VolumeCondition;
	///最小成交量
	int	MinVolume;
	///触发条件
	char	ContingentCondition;
	///止损价
	double	StopPrice;
	///强平原因
	char	ForceCloseReason;
	///自动挂起标志
	int	IsAutoSuspend;
	///业务单元
	TThostFtdcBusinessUnitType	BusinessUnit;
	///请求编号
	int	RequestID;
	///用户强评标志
	int	UserForceClose;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///预埋报单编号
	TThostFtdcParkedOrderIDType	ParkedOrderID;
	///用户类型
	char	UserType;
	///预埋单状态
	char	Status;
	///错误代码
	int	ErrorID;
	///错误信息
	TThostFtdcErrorMsgType	ErrorMsg;
	///互换单标志
	int	IsSwapOrder;
	///资金账号
	TThostFtdcAccountIDType	AccountID;
	///币种代码
	TThostFtdcCurrencyIDType	CurrencyID;
	///交易编码
	TThostFtdcClientIDType	ClientID;
	///投资单元代码
	TThostFtdcInvestUnitIDType	InvestUnitID;
	///IP地址
	TThostFtdcIPAddressType	IPAddress;
	///Mac地址
	TThostFtdcMacAddressType	MacAddress;
};

///输入预埋单操作
struct CThostFtdcParkedOrderActionField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///报单操作引用
	int	OrderActionRef;
	///报单引用
	TThostFtdcOrderRefType	OrderRef;
	///请求编号
	int	RequestID;
	///前置编号
	int	FrontID;
	///会话编号
	int	SessionID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///报单编号
	TThostFtdcOrderSysIDType	OrderSysID;
	///操作标志
	char	ActionFlag;
	///价格
	double	LimitPrice;
	///数量变化
	int	VolumeChange;
	///用户代码
	TThostFtdcUserIDType	UserID;
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///预埋撤单单编号
	TThostFtdcParkedOrderActionIDType	ParkedOrderActionID;
	///用户类型
	char	UserType;
	///预埋撤单状态
	char	Status;
	///错误代码
	int	ErrorID;
	///错误信息
	TThostFtdcErrorMsgType	ErrorMsg;
	///投资单元代码
	TThostFtdcInvestUnitIDType	InvestUnitID;
	///IP地址
	TThostFtdcIPAddressType	IPAddress;
	///Mac地址
	TThostFtdcMacAddressType	MacAddress;
};

///查询预埋单
struct CThostFtdcQryParkedOrderField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
};

///查询预埋撤单
struct CThostFtdcQryParkedOrderActionField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
};

///删除预埋单
struct CThostFtdcRemoveParkedOrderField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///预埋报单编号
	TThostFtdcParkedOrderIDType	ParkedOrderID;
};

///删除预埋撤单
struct CThostFtdcRemoveParkedOrderActionField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///预埋撤单编号
	TThostFtdcParkedOrderActionIDType	ParkedOrderActionID;
};

///经纪公司可提资金算法表
struct CThostFtdcInvestorWithdrawAlgorithmField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者范围
	char	InvestorRange;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///可提资金比例
	double	UsingRatio;
	///币种代码
	TThostFtdcCurrencyIDType	CurrencyID;
	///货币质押比率
	double	FundMortgageRatio;
};

///查询组合持仓明细
struct CThostFtdcQryInvestorPositionCombineDetailField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///组合持仓合约编码
	TThostFtdcInstrumentIDType	CombInstrumentID;
};

///成交均价
struct CThostFtdcMarketDataAveragePriceField
{
	///当日均价
	double	AveragePrice;
};

///校验投资者密码
struct CThostFtdcVerifyInvestorPasswordField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///密码
	TThostFtdcPasswordType	Password;
};

///用户IP
struct CThostFtdcUserIPField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///用户代码
	TThostFtdcUserIDType	UserID;
	///IP地址
	TThostFtdcIPAddressType	IPAddress;
	///IP地址掩码
	TThostFtdcIPAddressType	IPMask;
	///Mac地址
	TThostFtdcMacAddressType	MacAddress;
};

///用户事件通知信息
struct CThostFtdcTradingNoticeInfoField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///发送时间
	TThostFtdcTimeType	SendTime;
	///消息正文
	TThostFtdcContentType	FieldContent;
	///序列系列号
	TThostFtdcSequenceSeriesType	SequenceSeries;
	///序列号
	int	SequenceNo;
};

///用户事件通知
struct CThostFtdcTradingNoticeField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者范围
	char	InvestorRange;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///序列系列号
	TThostFtdcSequenceSeriesType	SequenceSeries;
	///用户代码
	TThostFtdcUserIDType	UserID;
	///发送时间
	TThostFtdcTimeType	SendTime;
	///序列号
	int	SequenceNo;
	///消息正文
	TThostFtdcContentType	FieldContent;
};

///查询交易事件通知
struct CThostFtdcQryTradingNoticeField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
};

///查询错误报单
struct CThostFtdcQryErrOrderField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
};

///错误报单
struct CThostFtdcErrOrderField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///报单引用
	TThostFtdcOrderRefType	OrderRef;
	///用户代码
	TThostFtdcUserIDType	UserID;
	///报单价格条件
	char	OrderPriceType;
	///买卖方向
	char	Direction;
	///组合开平标志
	TThostFtdcCombOffsetFlagType	CombOffsetFlag;
	///组合投机套保标志
	TThostFtdcCombHedgeFlagType	CombHedgeFlag;
	///价格
	double	LimitPrice;
	///数量
	int	VolumeTotalOriginal;
	///有效期类型
	char	TimeCondition;
	///GTD日期
	TThostFtdcDateType	GTDDate;
	///成交量类型
	char	VolumeCondition;
	///最小成交量
	int	MinVolume;
	///触发条件
	char	ContingentCondition;
	///止损价
	double	StopPrice;
	///强平原因
	char	ForceCloseReason;
	///自动挂起标志
	int	IsAutoSuspend;
	///业务单元
	TThostFtdcBusinessUnitType	BusinessUnit;
	///请求编号
	int	RequestID;
	///用户强评标志
	int	UserForceClose;
	///错误代码
	int	ErrorID;
	///错误信息
	TThostFtdcErrorMsgType	ErrorMsg;
	///互换单标志
	int	IsSwapOrder;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///投资单元代码
	TThostFtdcInvestUnitIDType	InvestUnitID;
	///资金账号
	TThostFtdcAccountIDType	AccountID;
	///币种代码
	TThostFtdcCurrencyIDType	CurrencyID;
	///交易编码
	TThostFtdcClientIDType	ClientID;
	///IP地址
	TThostFtdcIPAddressType	IPAddress;
	///Mac地址
	TThostFtdcMacAddressType	MacAddress;
};

///查询错误报单操作
struct CThostFtdcErrorConditionalOrderField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///报单引用
	TThostFtdcOrderRefType	OrderRef;
	///用户代码
	TThostFtdcUserIDType	UserID;
	///报单价格条件
	char	OrderPriceType;
	///买卖方向
	char	Direction;
	///组合开平标志
	TThostFtdcCombOffsetFlagType	CombOffsetFlag;
	///组合投机套保标志
	TThostFtdcCombHedgeFlagType	CombHedgeFlag;
	///价格
	double	LimitPrice;
	///数量
	int	VolumeTotalOriginal;
	///有效期类型
	char	TimeCondition;
	///GTD日期
	TThostFtdcDateType	GTDDate;
	///成交量类型
	char	VolumeCondition;
	///最小成交量
	int	MinVolume;
	///触发条件
	char	ContingentCondition;
	///止损价
	double	StopPrice;
	///强平原因
	char	ForceCloseReason;
	///自动挂起标志
	int	IsAutoSuspend;
	///业务单元
	TThostFtdcBusinessUnitType	BusinessUnit;
	///请求编号
	int	RequestID;
	///本地报单编号
	TThostFtdcOrderLocalIDType	OrderLocalID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///会员代码
	TThostFtdcParticipantIDType	ParticipantID;
	///客户代码
	TThostFtdcClientIDType	ClientID;
	///合约在交易所的代码
	TThostFtdcExchangeInstIDType	ExchangeInstID;
	///交易所交易员代码
	TThostFtdcTraderIDType	TraderID;
	///安装编号
	int	InstallID;
	///报单提交状态
	char	OrderSubmitStatus;
	///报单提示序号
	int	NotifySequence;
	///交易日
	TThostFtdcDateType	TradingDay;
	///结算编号
	int	SettlementID;
	///报单编号
	TThostFtdcOrderSysIDType	OrderSysID;
	///报单来源
	char	OrderSource;
	///报单状态
	char	OrderStatus;
	///报单类型
	char	OrderType;
	///今成交数量
	int	VolumeTraded;
	///剩余数量
	int	VolumeTotal;
	///报单日期
	TThostFtdcDateType	InsertDate;
	///委托时间
	TThostFtdcTimeType	InsertTime;
	///激活时间
	TThostFtdcTimeType	ActiveTime;
	///挂起时间
	TThostFtdcTimeType	SuspendTime;
	///最后修改时间
	TThostFtdcTimeType	UpdateTime;
	///撤销时间
	TThostFtdcTimeType	CancelTime;
	///最后修改交易所交易员代码
	TThostFtdcTraderIDType	ActiveTraderID;
	///结算会员编号
	TThostFtdcParticipantIDType	ClearingPartID;
	///序号
	int	SequenceNo;
	///前置编号
	int	FrontID;
	///会话编号
	int	SessionID;
	///用户端产品信息
	TThostFtdcProductInfoType	UserProductInfo;
	///状态信息
	TThostFtdcErrorMsgType	StatusMsg;
	///用户强评标志
	int	UserForceClose;
	///操作用户代码
	TThostFtdcUserIDType	ActiveUserID;
	///经纪公司报单编号
	int	BrokerOrderSeq;
	///相关报单
	TThostFtdcOrderSysIDType	RelativeOrderSysID;
	///郑商所成交数量
	int	ZCETotalTradedVolume;
	///错误代码
	int	ErrorID;
	///错误信息
	TThostFtdcErrorMsgType	ErrorMsg;
	///互换单标志
	int	IsSwapOrder;
	///营业部编号
	TThostFtdcBranchIDType	BranchID;
	///投资单元代码
	TThostFtdcInvestUnitIDType	InvestUnitID;
	///资金账号
	TThostFtdcAccountIDType	AccountID;
	///币种代码
	TThostFtdcCurrencyIDType	CurrencyID;
	///IP地址
	TThostFtdcIPAddressType	IPAddress;
	///Mac地址
	TThostFtdcMacAddressType	MacAddress;
};

///查询错误报单操作
struct CThostFtdcQryErrOrderActionField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
};

///错误报单操作
struct CThostFtdcErrOrderActionField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///报单操作引用
	int	OrderActionRef;
	///报单引用
	TThostFtdcOrderRefType	OrderRef;
	///请求编号
	int	RequestID;
	///前置编号
	int	FrontID;
	///会话编号
	int	SessionID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///报单编号
	TThostFtdcOrderSysIDType	OrderSysID;
	///操作标志
	char	ActionFlag;
	///价格
	double	LimitPrice;
	///数量变化
	int	VolumeChange;
	///操作日期
	TThostFtdcDateType	ActionDate;
	///操作时间
	TThostFtdcTimeType	ActionTime;
	///交易所交易员代码
	TThostFtdcTraderIDType	TraderID;
	///安装编号
	int	InstallID;
	///本地报单编号
	TThostFtdcOrderLocalIDType	OrderLocalID;
	///操作本地编号
	TThostFtdcOrderLocalIDType	ActionLocalID;
	///会员代码
	TThostFtdcParticipantIDType	ParticipantID;
	///客户代码
	TThostFtdcClientIDType	ClientID;
	///业务单元
	TThostFtdcBusinessUnitType	BusinessUnit;
	///报单操作状态
	char	OrderActionStatus;
	///用户代码
	TThostFtdcUserIDType	UserID;
	///状态信息
	TThostFtdcErrorMsgType	StatusMsg;
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///营业部编号
	TThostFtdcBranchIDType	BranchID;
	///投资单元代码
	TThostFtdcInvestUnitIDType	InvestUnitID;
	///IP地址
	TThostFtdcIPAddressType	IPAddress;
	///Mac地址
	TThostFtdcMacAddressType	MacAddress;
	///错误代码
	int	ErrorID;
	///错误信息
	TThostFtdcErrorMsgType	ErrorMsg;
};

///查询交易所状态
struct CThostFtdcQryExchangeSequenceField
{
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
};

///交易所状态
struct CThostFtdcExchangeSequenceField
{
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///序号
	int	SequenceNo;
	///合约交易状态
	char	MarketStatus;
};

///根据价格查询最大报单数量
struct CThostFtdcQueryMaxOrderVolumeWithPriceField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///买卖方向
	char	Direction;
	///开平标志
	char	OffsetFlag;
	///投机套保标志
	char	HedgeFlag;
	///最大允许报单数量
	int	MaxVolume;
	///报单价格
	double	Price;
};

///查询经纪公司交易参数
struct CThostFtdcQryBrokerTradingParamsField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///币种代码
	TThostFtdcCurrencyIDType	CurrencyID;
};

///经纪公司交易参数
struct CThostFtdcBrokerTradingParamsField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///保证金价格类型
	char	MarginPriceType;
	///盈亏算法
	char	Algorithm;
	///可用是否包含平仓盈利
	char	AvailIncludeCloseProfit;
	///币种代码
	TThostFtdcCurrencyIDType	CurrencyID;
	///期权权利金价格类型
	char	OptionRoyaltyPriceType;
};

///查询经纪公司交易算法
struct CThostFtdcQryBrokerTradingAlgosField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
};

///经纪公司交易算法
struct CThostFtdcBrokerTradingAlgosField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///持仓处理算法编号
	char	HandlePositionAlgoID;
	///寻找保证金率算法编号
	char	FindMarginRateAlgoID;
	///资金处理算法编号
	char	HandleTradingAccountAlgoID;
};

///查询经纪公司资金
struct CThostFtdcQueryBrokerDepositField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
};

///经纪公司资金
struct CThostFtdcBrokerDepositField
{
	///交易日期
	TThostFtdcTradeDateType	TradingDay;
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///会员代码
	TThostFtdcParticipantIDType	ParticipantID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///上次结算准备金
	double	PreBalance;
	///当前保证金总额
	double	CurrMargin;
	///平仓盈亏
	double	CloseProfit;
	///期货结算准备金
	double	Balance;
	///入金金额
	double	Deposit;
	///出金金额
	double	Withdraw;
	///可提资金
	double	Available;
	///基本准备金
	double	Reserve;
	///冻结的保证金
	double	FrozenMargin;
};

///查询保证金监管系统经纪公司密钥
struct CThostFtdcQryCFMMCBrokerKeyField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
};

///保证金监管系统经纪公司密钥
struct CThostFtdcCFMMCBrokerKeyField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///经纪公司统一编码
	TThostFtdcParticipantIDType	ParticipantID;
	///密钥生成日期
	TThostFtdcDateType	CreateDate;
	///密钥生成时间
	TThostFtdcTimeType	CreateTime;
	///密钥编号
	int	KeyID;
	///动态密钥
	TThostFtdcCFMMCKeyType	CurrentKey;
	///动态密钥类型
	char	KeyKind;
};

///保证金监管系统经纪公司资金账户密钥
struct CThostFtdcCFMMCTradingAccountKeyField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///经纪公司统一编码
	TThostFtdcParticipantIDType	ParticipantID;
	///投资者帐号
	TThostFtdcAccountIDType	AccountID;
	///密钥编号
	int	KeyID;
	///动态密钥
	TThostFtdcCFMMCKeyType	CurrentKey;
};

///请求查询保证金监管系统经纪公司资金账户密钥
struct CThostFtdcQryCFMMCTradingAccountKeyField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
};

///用户动态令牌参数
struct CThostFtdcBrokerUserOTPParamField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///用户代码
	TThostFtdcUserIDType	UserID;
	///动态令牌提供商
	TThostFtdcOTPVendorsIDType	OTPVendorsID;
	///动态令牌序列号
	TThostFtdcSerialNumberType	SerialNumber;
	///令牌密钥
	TThostFtdcAuthKeyType	AuthKey;
	///漂移值
	int	LastDrift;
	///成功值
	int	LastSuccess;
	///动态令牌类型
	char	OTPType;
};

///手工同步用户动态令牌
struct CThostFtdcManualSyncBrokerUserOTPField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///用户代码
	TThostFtdcUserIDType	UserID;
	///动态令牌类型
	char	OTPType;
	///第一个动态密码
	TThostFtdcPasswordType	FirstOTP;
	///第二个动态密码
	TThostFtdcPasswordType	SecondOTP;
};

///投资者手续费率模板
struct CThostFtdcCommRateModelField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///手续费率模板代码
	TThostFtdcInvestorIDType	CommModelID;
	///模板名称
	TThostFtdcCommModelNameType	CommModelName;
};

///请求查询投资者手续费率模板
struct CThostFtdcQryCommRateModelField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///手续费率模板代码
	TThostFtdcInvestorIDType	CommModelID;
};

///投资者保证金率模板
struct CThostFtdcMarginModelField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///保证金率模板代码
	TThostFtdcInvestorIDType	MarginModelID;
	///模板名称
	TThostFtdcCommModelNameType	MarginModelName;
};

///请求查询投资者保证金率模板
struct CThostFtdcQryMarginModelField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///保证金率模板代码
	TThostFtdcInvestorIDType	MarginModelID;
};

///仓单折抵信息
struct CThostFtdcEWarrantOffsetField
{
	///交易日期
	TThostFtdcTradeDateType	TradingDay;
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
	///买卖方向
	char	Direction;
	///投机套保标志
	char	HedgeFlag;
	///数量
	int	Volume;
};

///查询仓单折抵信息
struct CThostFtdcQryEWarrantOffsetField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///合约代码
	TThostFtdcInstrumentIDType	InstrumentID;
};

///查询投资者品种/跨品种保证金
struct CThostFtdcQryInvestorProductGroupMarginField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///品种/跨品种标示
	TThostFtdcInstrumentIDType	ProductGroupID;
	///投机套保标志
	char	HedgeFlag;
};

///投资者品种/跨品种保证金
struct CThostFtdcInvestorProductGroupMarginField
{
	///品种/跨品种标示
	TThostFtdcInstrumentIDType	ProductGroupID;
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///交易日
	TThostFtdcDateType	TradingDay;
	///结算编号
	int	SettlementID;
	///冻结的保证金
	double	FrozenMargin;
	///多头冻结的保证金
	double	LongFrozenMargin;
	///空头冻结的保证金
	double	ShortFrozenMargin;
	///占用的保证金
	double	UseMargin;
	///多头保证金
	double	LongUseMargin;
	///空头保证金
	double	ShortUseMargin;
	///交易所保证金
	double	ExchMargin;
	///交易所多头保证金
	double	LongExchMargin;
	///交易所空头保证金
	double	ShortExchMargin;
	///平仓盈亏
	double	CloseProfit;
	///冻结的手续费
	double	FrozenCommission;
	///手续费
	double	Commission;
	///冻结的资金
	double	FrozenCash;
	///资金差额
	double	CashIn;
	///持仓盈亏
	double	PositionProfit;
	///折抵总金额
	double	OffsetAmount;
	///多头折抵总金额
	double	LongOffsetAmount;
	///空头折抵总金额
	double	ShortOffsetAmount;
	///交易所折抵总金额
	double	ExchOffsetAmount;
	///交易所多头折抵总金额
	double	LongExchOffsetAmount;
	///交易所空头折抵总金额
	double	ShortExchOffsetAmount;
	///投机套保标志
	char	HedgeFlag;
};

///查询监控中心用户令牌
struct CThostFtdcQueryCFMMCTradingAccountTokenField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
};

///监控中心用户令牌
struct CThostFtdcCFMMCTradingAccountTokenField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///经纪公司统一编码
	TThostFtdcParticipantIDType	ParticipantID;
	///投资者帐号
	TThostFtdcAccountIDType	AccountID;
	///密钥编号
	int	KeyID;
	///动态令牌
	TThostFtdcCFMMCTokenType	Token;
};

///查询产品组
struct CThostFtdcQryProductGroupField
{
	///产品代码
	TThostFtdcInstrumentIDType	ProductID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
};

///投资者品种/跨品种保证金产品组
struct CThostFtdcProductGroupField
{
	///产品代码
	TThostFtdcInstrumentIDType	ProductID;
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///产品组代码
	TThostFtdcInstrumentIDType	ProductGroupID;
};

///交易所公告
struct CThostFtdcBulletinField
{
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///交易日
	TThostFtdcDateType	TradingDay;
	///公告编号
	int	BulletinID;
	///序列号
	int	SequenceNo;
	///公告类型
	TThostFtdcNewsTypeType	NewsType;
	///紧急程度
	char	NewsUrgency;
	///发送时间
	TThostFtdcTimeType	SendTime;
	///消息摘要
	TThostFtdcAbstractType	Abstract;
	///消息来源
	TThostFtdcComeFromType	ComeFrom;
	///消息正文
	TThostFtdcContentType	Content;
	///WEB地址
	TThostFtdcURLLinkType	URLLink;
	///市场代码
	TThostFtdcMarketIDType	MarketID;
};

///查询交易所公告
struct CThostFtdcQryBulletinField
{
	///交易所代码
	TThostFtdcExchangeIDType	ExchangeID;
	///公告编号
	int	BulletinID;
	///序列号
	int	SequenceNo;
	///公告类型
	TThostFtdcNewsTypeType	NewsType;
	///紧急程度
	char	NewsUrgency;
};

///转帐开户请求
struct CThostFtdcReqOpenAccountField
{
	///业务功能码
	TThostFtdcTradeCodeType	TradeCode;
	///银行代码
	TThostFtdcBankIDType	BankID;
	///银行分支机构代码
	TThostFtdcBankBrchIDType	BankBranchID;
	///期商代码
	TThostFtdcBrokerIDType	BrokerID;
	///期商分支机构代码
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	///交易日期
	TThostFtdcTradeDateType	TradeDate;
	///交易时间
	TThostFtdcTradeTimeType	TradeTime;
	///银行流水号
	TThostFtdcBankSerialType	BankSerial;
	///交易系统日期 
	TThostFtdcTradeDateType	TradingDay;
	///银期平台消息流水号
	int	PlateSerial;
	///最后分片标志
	char	LastFragment;
	///会话号
	int	SessionID;
	///客户姓名
	TThostFtdcIndividualNameType	CustomerName;
	///证件类型
	char	IdCardType;
	///证件号码
	TThostFtdcIdentifiedCardNoType	IdentifiedCardNo;
	///性别
	char	Gender;
	///国家代码
	TThostFtdcCountryCodeType	CountryCode;
	///客户类型
	char	CustType;
	///地址
	TThostFtdcAddressType	Address;
	///邮编
	TThostFtdcZipCodeType	ZipCode;
	///电话号码
	TThostFtdcTelephoneType	Telephone;
	///手机
	TThostFtdcMobilePhoneType	MobilePhone;
	///传真
	TThostFtdcFaxType	Fax;
	///电子邮件
	TThostFtdcEMailType	EMail;
	///资金账户状态
	char	MoneyAccountStatus;
	///银行帐号
	TThostFtdcBankAccountType	BankAccount;
	///银行密码
	TThostFtdcPasswordType	BankPassWord;
	///投资者帐号
	TThostFtdcAccountIDType	AccountID;
	///期货密码
	TThostFtdcPasswordType	Password;
	///安装编号
	int	InstallID;
	///验证客户证件号码标志
	char	VerifyCertNoFlag;
	///币种代码
	TThostFtdcCurrencyIDType	CurrencyID;
	///汇钞标志
	char	CashExchangeCode;
	///摘要
	TThostFtdcDigestType	Digest;
	///银行帐号类型
	char	BankAccType;
	///渠道标志
	TThostFtdcDeviceIDType	DeviceID;
	///期货单位帐号类型
	char	BankSecuAccType;
	///期货公司银行编码
	TThostFtdcBankCodingForFutureType	BrokerIDByBank;
	///期货单位帐号
	TThostFtdcBankAccountType	BankSecuAcc;
	///银行密码标志
	char	BankPwdFlag;
	///期货资金密码核对标志
	char	SecuPwdFlag;
	///交易柜员
	TThostFtdcOperNoType	OperNo;
	///交易ID
	int	TID;
	///用户标识
	TThostFtdcUserIDType	UserID;
};

///转帐销户请求
struct CThostFtdcReqCancelAccountField
{
	///业务功能码
	TThostFtdcTradeCodeType	TradeCode;
	///银行代码
	TThostFtdcBankIDType	BankID;
	///银行分支机构代码
	TThostFtdcBankBrchIDType	BankBranchID;
	///期商代码
	TThostFtdcBrokerIDType	BrokerID;
	///期商分支机构代码
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	///交易日期
	TThostFtdcTradeDateType	TradeDate;
	///交易时间
	TThostFtdcTradeTimeType	TradeTime;
	///银行流水号
	TThostFtdcBankSerialType	BankSerial;
	///交易系统日期 
	TThostFtdcTradeDateType	TradingDay;
	///银期平台消息流水号
	int	PlateSerial;
	///最后分片标志
	char	LastFragment;
	///会话号
	int	SessionID;
	///客户姓名
	TThostFtdcIndividualNameType	CustomerName;
	///证件类型
	char	IdCardType;
	///证件号码
	TThostFtdcIdentifiedCardNoType	IdentifiedCardNo;
	///性别
	char	Gender;
	///国家代码
	TThostFtdcCountryCodeType	CountryCode;
	///客户类型
	char	CustType;
	///地址
	TThostFtdcAddressType	Address;
	///邮编
	TThostFtdcZipCodeType	ZipCode;
	///电话号码
	TThostFtdcTelephoneType	Telephone;
	///手机
	TThostFtdcMobilePhoneType	MobilePhone;
	///传真
	TThostFtdcFaxType	Fax;
	///电子邮件
	TThostFtdcEMailType	EMail;
	///资金账户状态
	char	MoneyAccountStatus;
	///银行帐号
	TThostFtdcBankAccountType	BankAccount;
	///银行密码
	TThostFtdcPasswordType	BankPassWord;
	///投资者帐号
	TThostFtdcAccountIDType	AccountID;
	///期货密码
	TThostFtdcPasswordType	Password;
	///安装编号
	int	InstallID;
	///验证客户证件号码标志
	char	VerifyCertNoFlag;
	///币种代码
	TThostFtdcCurrencyIDType	CurrencyID;
	///汇钞标志
	char	CashExchangeCode;
	///摘要
	TThostFtdcDigestType	Digest;
	///银行帐号类型
	char	BankAccType;
	///渠道标志
	TThostFtdcDeviceIDType	DeviceID;
	///期货单位帐号类型
	char	BankSecuAccType;
	///期货公司银行编码
	TThostFtdcBankCodingForFutureType	BrokerIDByBank;
	///期货单位帐号
	TThostFtdcBankAccountType	BankSecuAcc;
	///银行密码标志
	char	BankPwdFlag;
	///期货资金密码核对标志
	char	SecuPwdFlag;
	///交易柜员
	TThostFtdcOperNoType	OperNo;
	///交易ID
	int	TID;
	///用户标识
	TThostFtdcUserIDType	UserID;
};

///变更银行账户请求
struct CThostFtdcReqChangeAccountField
{
	///业务功能码
	TThostFtdcTradeCodeType	TradeCode;
	///银行代码
	TThostFtdcBankIDType	BankID;
	///银行分支机构代码
	TThostFtdcBankBrchIDType	BankBranchID;
	///期商代码
	TThostFtdcBrokerIDType	BrokerID;
	///期商分支机构代码
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	///交易日期
	TThostFtdcTradeDateType	TradeDate;
	///交易时间
	TThostFtdcTradeTimeType	TradeTime;
	///银行流水号
	TThostFtdcBankSerialType	BankSerial;
	///交易系统日期 
	TThostFtdcTradeDateType	TradingDay;
	///银期平台消息流水号
	int	PlateSerial;
	///最后分片标志
	char	LastFragment;
	///会话号
	int	SessionID;
	///客户姓名
	TThostFtdcIndividualNameType	CustomerName;
	///证件类型
	char	IdCardType;
	///证件号码
	TThostFtdcIdentifiedCardNoType	IdentifiedCardNo;
	///性别
	char	Gender;
	///国家代码
	TThostFtdcCountryCodeType	CountryCode;
	///客户类型
	char	CustType;
	///地址
	TThostFtdcAddressType	Address;
	///邮编
	TThostFtdcZipCodeType	ZipCode;
	///电话号码
	TThostFtdcTelephoneType	Telephone;
	///手机
	TThostFtdcMobilePhoneType	MobilePhone;
	///传真
	TThostFtdcFaxType	Fax;
	///电子邮件
	TThostFtdcEMailType	EMail;
	///资金账户状态
	char	MoneyAccountStatus;
	///银行帐号
	TThostFtdcBankAccountType	BankAccount;
	///银行密码
	TThostFtdcPasswordType	BankPassWord;
	///新银行帐号
	TThostFtdcBankAccountType	NewBankAccount;
	///新银行密码
	TThostFtdcPasswordType	NewBankPassWord;
	///投资者帐号
	TThostFtdcAccountIDType	AccountID;
	///期货密码
	TThostFtdcPasswordType	Password;
	///银行帐号类型
	char	BankAccType;
	///安装编号
	int	InstallID;
	///验证客户证件号码标志
	char	VerifyCertNoFlag;
	///币种代码
	TThostFtdcCurrencyIDType	CurrencyID;
	///期货公司银行编码
	TThostFtdcBankCodingForFutureType	BrokerIDByBank;
	///银行密码标志
	char	BankPwdFlag;
	///期货资金密码核对标志
	char	SecuPwdFlag;
	///交易ID
	int	TID;
	///摘要
	TThostFtdcDigestType	Digest;
};

///转账请求
struct CThostFtdcReqTransferField
{
	///业务功能码
	TThostFtdcTradeCodeType	TradeCode;
	///银行代码
	TThostFtdcBankIDType	BankID;
	///银行分支机构代码
	TThostFtdcBankBrchIDType	BankBranchID;
	///期商代码
	TThostFtdcBrokerIDType	BrokerID;
	///期商分支机构代码
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	///交易日期
	TThostFtdcTradeDateType	TradeDate;
	///交易时间
	TThostFtdcTradeTimeType	TradeTime;
	///银行流水号
	TThostFtdcBankSerialType	BankSerial;
	///交易系统日期 
	TThostFtdcTradeDateType	TradingDay;
	///银期平台消息流水号
	int	PlateSerial;
	///最后分片标志
	char	LastFragment;
	///会话号
	int	SessionID;
	///客户姓名
	TThostFtdcIndividualNameType	CustomerName;
	///证件类型
	char	IdCardType;
	///证件号码
	TThostFtdcIdentifiedCardNoType	IdentifiedCardNo;
	///客户类型
	char	CustType;
	///银行帐号
	TThostFtdcBankAccountType	BankAccount;
	///银行密码
	TThostFtdcPasswordType	BankPassWord;
	///投资者帐号
	TThostFtdcAccountIDType	AccountID;
	///期货密码
	TThostFtdcPasswordType	Password;
	///安装编号
	int	InstallID;
	///期货公司流水号
	int	FutureSerial;
	///用户标识
	TThostFtdcUserIDType	UserID;
	///验证客户证件号码标志
	char	VerifyCertNoFlag;
	///币种代码
	TThostFtdcCurrencyIDType	CurrencyID;
	///转帐金额
	double	TradeAmount;
	///期货可取金额
	double	FutureFetchAmount;
	///费用支付标志
	char	FeePayFlag;
	///应收客户费用
	double	CustFee;
	///应收期货公司费用
	double	BrokerFee;
	///发送方给接收方的消息
	TThostFtdcAddInfoType	Message;
	///摘要
	TThostFtdcDigestType	Digest;
	///银行帐号类型
	char	BankAccType;
	///渠道标志
	TThostFtdcDeviceIDType	DeviceID;
	///期货单位帐号类型
	char	BankSecuAccType;
	///期货公司银行编码
	TThostFtdcBankCodingForFutureType	BrokerIDByBank;
	///期货单位帐号
	TThostFtdcBankAccountType	BankSecuAcc;
	///银行密码标志
	char	BankPwdFlag;
	///期货资金密码核对标志
	char	SecuPwdFlag;
	///交易柜员
	TThostFtdcOperNoType	OperNo;
	///请求编号
	int	RequestID;
	///交易ID
	int	TID;
	///转账交易状态
	char	TransferStatus;
};

///银行发起银行资金转期货响应
struct CThostFtdcRspTransferField
{
	///业务功能码
	TThostFtdcTradeCodeType	TradeCode;
	///银行代码
	TThostFtdcBankIDType	BankID;
	///银行分支机构代码
	TThostFtdcBankBrchIDType	BankBranchID;
	///期商代码
	TThostFtdcBrokerIDType	BrokerID;
	///期商分支机构代码
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	///交易日期
	TThostFtdcTradeDateType	TradeDate;
	///交易时间
	TThostFtdcTradeTimeType	TradeTime;
	///银行流水号
	TThostFtdcBankSerialType	BankSerial;
	///交易系统日期 
	TThostFtdcTradeDateType	TradingDay;
	///银期平台消息流水号
	int	PlateSerial;
	///最后分片标志
	char	LastFragment;
	///会话号
	int	SessionID;
	///客户姓名
	TThostFtdcIndividualNameType	CustomerName;
	///证件类型
	char	IdCardType;
	///证件号码
	TThostFtdcIdentifiedCardNoType	IdentifiedCardNo;
	///客户类型
	char	CustType;
	///银行帐号
	TThostFtdcBankAccountType	BankAccount;
	///银行密码
	TThostFtdcPasswordType	BankPassWord;
	///投资者帐号
	TThostFtdcAccountIDType	AccountID;
	///期货密码
	TThostFtdcPasswordType	Password;
	///安装编号
	int	InstallID;
	///期货公司流水号
	int	FutureSerial;
	///用户标识
	TThostFtdcUserIDType	UserID;
	///验证客户证件号码标志
	char	VerifyCertNoFlag;
	///币种代码
	TThostFtdcCurrencyIDType	CurrencyID;
	///转帐金额
	double	TradeAmount;
	///期货可取金额
	double	FutureFetchAmount;
	///费用支付标志
	char	FeePayFlag;
	///应收客户费用
	double	CustFee;
	///应收期货公司费用
	double	BrokerFee;
	///发送方给接收方的消息
	TThostFtdcAddInfoType	Message;
	///摘要
	TThostFtdcDigestType	Digest;
	///银行帐号类型
	char	BankAccType;
	///渠道标志
	TThostFtdcDeviceIDType	DeviceID;
	///期货单位帐号类型
	char	BankSecuAccType;
	///期货公司银行编码
	TThostFtdcBankCodingForFutureType	BrokerIDByBank;
	///期货单位帐号
	TThostFtdcBankAccountType	BankSecuAcc;
	///银行密码标志
	char	BankPwdFlag;
	///期货资金密码核对标志
	char	SecuPwdFlag;
	///交易柜员
	TThostFtdcOperNoType	OperNo;
	///请求编号
	int	RequestID;
	///交易ID
	int	TID;
	///转账交易状态
	char	TransferStatus;
	///错误代码
	int	ErrorID;
	///错误信息
	TThostFtdcErrorMsgType	ErrorMsg;
};

///冲正请求
struct CThostFtdcReqRepealField
{
	///冲正时间间隔
	int	RepealTimeInterval;
	///已经冲正次数
	int	RepealedTimes;
	///银行冲正标志
	char	BankRepealFlag;
	///期商冲正标志
	char	BrokerRepealFlag;
	///被冲正平台流水号
	int	PlateRepealSerial;
	///被冲正银行流水号
	TThostFtdcBankSerialType	BankRepealSerial;
	///被冲正期货流水号
	int	FutureRepealSerial;
	///业务功能码
	TThostFtdcTradeCodeType	TradeCode;
	///银行代码
	TThostFtdcBankIDType	BankID;
	///银行分支机构代码
	TThostFtdcBankBrchIDType	BankBranchID;
	///期商代码
	TThostFtdcBrokerIDType	BrokerID;
	///期商分支机构代码
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	///交易日期
	TThostFtdcTradeDateType	TradeDate;
	///交易时间
	TThostFtdcTradeTimeType	TradeTime;
	///银行流水号
	TThostFtdcBankSerialType	BankSerial;
	///交易系统日期 
	TThostFtdcTradeDateType	TradingDay;
	///银期平台消息流水号
	int	PlateSerial;
	///最后分片标志
	char	LastFragment;
	///会话号
	int	SessionID;
	///客户姓名
	TThostFtdcIndividualNameType	CustomerName;
	///证件类型
	char	IdCardType;
	///证件号码
	TThostFtdcIdentifiedCardNoType	IdentifiedCardNo;
	///客户类型
	char	CustType;
	///银行帐号
	TThostFtdcBankAccountType	BankAccount;
	///银行密码
	TThostFtdcPasswordType	BankPassWord;
	///投资者帐号
	TThostFtdcAccountIDType	AccountID;
	///期货密码
	TThostFtdcPasswordType	Password;
	///安装编号
	int	InstallID;
	///期货公司流水号
	int	FutureSerial;
	///用户标识
	TThostFtdcUserIDType	UserID;
	///验证客户证件号码标志
	char	VerifyCertNoFlag;
	///币种代码
	TThostFtdcCurrencyIDType	CurrencyID;
	///转帐金额
	double	TradeAmount;
	///期货可取金额
	double	FutureFetchAmount;
	///费用支付标志
	char	FeePayFlag;
	///应收客户费用
	double	CustFee;
	///应收期货公司费用
	double	BrokerFee;
	///发送方给接收方的消息
	TThostFtdcAddInfoType	Message;
	///摘要
	TThostFtdcDigestType	Digest;
	///银行帐号类型
	char	BankAccType;
	///渠道标志
	TThostFtdcDeviceIDType	DeviceID;
	///期货单位帐号类型
	char	BankSecuAccType;
	///期货公司银行编码
	TThostFtdcBankCodingForFutureType	BrokerIDByBank;
	///期货单位帐号
	TThostFtdcBankAccountType	BankSecuAcc;
	///银行密码标志
	char	BankPwdFlag;
	///期货资金密码核对标志
	char	SecuPwdFlag;
	///交易柜员
	TThostFtdcOperNoType	OperNo;
	///请求编号
	int	RequestID;
	///交易ID
	int	TID;
	///转账交易状态
	char	TransferStatus;
};

///冲正响应
struct CThostFtdcRspRepealField
{
	///冲正时间间隔
	int	RepealTimeInterval;
	///已经冲正次数
	int	RepealedTimes;
	///银行冲正标志
	char	BankRepealFlag;
	///期商冲正标志
	char	BrokerRepealFlag;
	///被冲正平台流水号
	int	PlateRepealSerial;
	///被冲正银行流水号
	TThostFtdcBankSerialType	BankRepealSerial;
	///被冲正期货流水号
	int	FutureRepealSerial;
	///业务功能码
	TThostFtdcTradeCodeType	TradeCode;
	///银行代码
	TThostFtdcBankIDType	BankID;
	///银行分支机构代码
	TThostFtdcBankBrchIDType	BankBranchID;
	///期商代码
	TThostFtdcBrokerIDType	BrokerID;
	///期商分支机构代码
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	///交易日期
	TThostFtdcTradeDateType	TradeDate;
	///交易时间
	TThostFtdcTradeTimeType	TradeTime;
	///银行流水号
	TThostFtdcBankSerialType	BankSerial;
	///交易系统日期 
	TThostFtdcTradeDateType	TradingDay;
	///银期平台消息流水号
	int	PlateSerial;
	///最后分片标志
	char	LastFragment;
	///会话号
	int	SessionID;
	///客户姓名
	TThostFtdcIndividualNameType	CustomerName;
	///证件类型
	char	IdCardType;
	///证件号码
	TThostFtdcIdentifiedCardNoType	IdentifiedCardNo;
	///客户类型
	char	CustType;
	///银行帐号
	TThostFtdcBankAccountType	BankAccount;
	///银行密码
	TThostFtdcPasswordType	BankPassWord;
	///投资者帐号
	TThostFtdcAccountIDType	AccountID;
	///期货密码
	TThostFtdcPasswordType	Password;
	///安装编号
	int	InstallID;
	///期货公司流水号
	int	FutureSerial;
	///用户标识
	TThostFtdcUserIDType	UserID;
	///验证客户证件号码标志
	char	VerifyCertNoFlag;
	///币种代码
	TThostFtdcCurrencyIDType	CurrencyID;
	///转帐金额
	double	TradeAmount;
	///期货可取金额
	double	FutureFetchAmount;
	///费用支付标志
	char	FeePayFlag;
	///应收客户费用
	double	CustFee;
	///应收期货公司费用
	double	BrokerFee;
	///发送方给接收方的消息
	TThostFtdcAddInfoType	Message;
	///摘要
	TThostFtdcDigestType	Digest;
	///银行帐号类型
	char	BankAccType;
	///渠道标志
	TThostFtdcDeviceIDType	DeviceID;
	///期货单位帐号类型
	char	BankSecuAccType;
	///期货公司银行编码
	TThostFtdcBankCodingForFutureType	BrokerIDByBank;
	///期货单位帐号
	TThostFtdcBankAccountType	BankSecuAcc;
	///银行密码标志
	char	BankPwdFlag;
	///期货资金密码核对标志
	char	SecuPwdFlag;
	///交易柜员
	TThostFtdcOperNoType	OperNo;
	///请求编号
	int	RequestID;
	///交易ID
	int	TID;
	///转账交易状态
	char	TransferStatus;
	///错误代码
	int	ErrorID;
	///错误信息
	TThostFtdcErrorMsgType	ErrorMsg;
};

///查询账户信息请求
struct CThostFtdcReqQueryAccountField
{
	///业务功能码
	TThostFtdcTradeCodeType	TradeCode;
	///银行代码
	TThostFtdcBankIDType	BankID;
	///银行分支机构代码
	TThostFtdcBankBrchIDType	BankBranchID;
	///期商代码
	TThostFtdcBrokerIDType	BrokerID;
	///期商分支机构代码
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	///交易日期
	TThostFtdcTradeDateType	TradeDate;
	///交易时间
	TThostFtdcTradeTimeType	TradeTime;
	///银行流水号
	TThostFtdcBankSerialType	BankSerial;
	///交易系统日期 
	TThostFtdcTradeDateType	TradingDay;
	///银期平台消息流水号
	int	PlateSerial;
	///最后分片标志
	char	LastFragment;
	///会话号
	int	SessionID;
	///客户姓名
	TThostFtdcIndividualNameType	CustomerName;
	///证件类型
	char	IdCardType;
	///证件号码
	TThostFtdcIdentifiedCardNoType	IdentifiedCardNo;
	///客户类型
	char	CustType;
	///银行帐号
	TThostFtdcBankAccountType	BankAccount;
	///银行密码
	TThostFtdcPasswordType	BankPassWord;
	///投资者帐号
	TThostFtdcAccountIDType	AccountID;
	///期货密码
	TThostFtdcPasswordType	Password;
	///期货公司流水号
	int	FutureSerial;
	///安装编号
	int	InstallID;
	///用户标识
	TThostFtdcUserIDType	UserID;
	///验证客户证件号码标志
	char	VerifyCertNoFlag;
	///币种代码
	TThostFtdcCurrencyIDType	CurrencyID;
	///摘要
	TThostFtdcDigestType	Digest;
	///银行帐号类型
	char	BankAccType;
	///渠道标志
	TThostFtdcDeviceIDType	DeviceID;
	///期货单位帐号类型
	char	BankSecuAccType;
	///期货公司银行编码
	TThostFtdcBankCodingForFutureType	BrokerIDByBank;
	///期货单位帐号
	TThostFtdcBankAccountType	BankSecuAcc;
	///银行密码标志
	char	BankPwdFlag;
	///期货资金密码核对标志
	char	SecuPwdFlag;
	///交易柜员
	TThostFtdcOperNoType	OperNo;
	///请求编号
	int	RequestID;
	///交易ID
	int	TID;
};

///查询账户信息响应
struct CThostFtdcRspQueryAccountField
{
	///业务功能码
	TThostFtdcTradeCodeType	TradeCode;
	///银行代码
	TThostFtdcBankIDType	BankID;
	///银行分支机构代码
	TThostFtdcBankBrchIDType	BankBranchID;
	///期商代码
	TThostFtdcBrokerIDType	BrokerID;
	///期商分支机构代码
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	///交易日期
	TThostFtdcTradeDateType	TradeDate;
	///交易时间
	TThostFtdcTradeTimeType	TradeTime;
	///银行流水号
	TThostFtdcBankSerialType	BankSerial;
	///交易系统日期 
	TThostFtdcTradeDateType	TradingDay;
	///银期平台消息流水号
	int	PlateSerial;
	///最后分片标志
	char	LastFragment;
	///会话号
	int	SessionID;
	///客户姓名
	TThostFtdcIndividualNameType	CustomerName;
	///证件类型
	char	IdCardType;
	///证件号码
	TThostFtdcIdentifiedCardNoType	IdentifiedCardNo;
	///客户类型
	char	CustType;
	///银行帐号
	TThostFtdcBankAccountType	BankAccount;
	///银行密码
	TThostFtdcPasswordType	BankPassWord;
	///投资者帐号
	TThostFtdcAccountIDType	AccountID;
	///期货密码
	TThostFtdcPasswordType	Password;
	///期货公司流水号
	int	FutureSerial;
	///安装编号
	int	InstallID;
	///用户标识
	TThostFtdcUserIDType	UserID;
	///验证客户证件号码标志
	char	VerifyCertNoFlag;
	///币种代码
	TThostFtdcCurrencyIDType	CurrencyID;
	///摘要
	TThostFtdcDigestType	Digest;
	///银行帐号类型
	char	BankAccType;
	///渠道标志
	TThostFtdcDeviceIDType	DeviceID;
	///期货单位帐号类型
	char	BankSecuAccType;
	///期货公司银行编码
	TThostFtdcBankCodingForFutureType	BrokerIDByBank;
	///期货单位帐号
	TThostFtdcBankAccountType	BankSecuAcc;
	///银行密码标志
	char	BankPwdFlag;
	///期货资金密码核对标志
	char	SecuPwdFlag;
	///交易柜员
	TThostFtdcOperNoType	OperNo;
	///请求编号
	int	RequestID;
	///交易ID
	int	TID;
	///银行可用金额
	double	BankUseAmount;
	///银行可取金额
	double	BankFetchAmount;
};

///期商签到签退
struct CThostFtdcFutureSignIOField
{
	///业务功能码
	TThostFtdcTradeCodeType	TradeCode;
	///银行代码
	TThostFtdcBankIDType	BankID;
	///银行分支机构代码
	TThostFtdcBankBrchIDType	BankBranchID;
	///期商代码
	TThostFtdcBrokerIDType	BrokerID;
	///期商分支机构代码
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	///交易日期
	TThostFtdcTradeDateType	TradeDate;
	///交易时间
	TThostFtdcTradeTimeType	TradeTime;
	///银行流水号
	TThostFtdcBankSerialType	BankSerial;
	///交易系统日期 
	TThostFtdcTradeDateType	TradingDay;
	///银期平台消息流水号
	int	PlateSerial;
	///最后分片标志
	char	LastFragment;
	///会话号
	int	SessionID;
	///安装编号
	int	InstallID;
	///用户标识
	TThostFtdcUserIDType	UserID;
	///摘要
	TThostFtdcDigestType	Digest;
	///币种代码
	TThostFtdcCurrencyIDType	CurrencyID;
	///渠道标志
	TThostFtdcDeviceIDType	DeviceID;
	///期货公司银行编码
	TThostFtdcBankCodingForFutureType	BrokerIDByBank;
	///交易柜员
	TThostFtdcOperNoType	OperNo;
	///请求编号
	int	RequestID;
	///交易ID
	int	TID;
};

///期商签到响应
struct CThostFtdcRspFutureSignInField
{
	///业务功能码
	TThostFtdcTradeCodeType	TradeCode;
	///银行代码
	TThostFtdcBankIDType	BankID;
	///银行分支机构代码
	TThostFtdcBankBrchIDType	BankBranchID;
	///期商代码
	TThostFtdcBrokerIDType	BrokerID;
	///期商分支机构代码
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	///交易日期
	TThostFtdcTradeDateType	TradeDate;
	///交易时间
	TThostFtdcTradeTimeType	TradeTime;
	///银行流水号
	TThostFtdcBankSerialType	BankSerial;
	///交易系统日期 
	TThostFtdcTradeDateType	TradingDay;
	///银期平台消息流水号
	int	PlateSerial;
	///最后分片标志
	char	LastFragment;
	///会话号
	int	SessionID;
	///安装编号
	int	InstallID;
	///用户标识
	TThostFtdcUserIDType	UserID;
	///摘要
	TThostFtdcDigestType	Digest;
	///币种代码
	TThostFtdcCurrencyIDType	CurrencyID;
	///渠道标志
	TThostFtdcDeviceIDType	DeviceID;
	///期货公司银行编码
	TThostFtdcBankCodingForFutureType	BrokerIDByBank;
	///交易柜员
	TThostFtdcOperNoType	OperNo;
	///请求编号
	int	RequestID;
	///交易ID
	int	TID;
	///错误代码
	int	ErrorID;
	///错误信息
	TThostFtdcErrorMsgType	ErrorMsg;
	///PIN密钥
	TThostFtdcPasswordKeyType	PinKey;
	///MAC密钥
	TThostFtdcPasswordKeyType	MacKey;
};

///期商签退请求
struct CThostFtdcReqFutureSignOutField
{
	///业务功能码
	TThostFtdcTradeCodeType	TradeCode;
	///银行代码
	TThostFtdcBankIDType	BankID;
	///银行分支机构代码
	TThostFtdcBankBrchIDType	BankBranchID;
	///期商代码
	TThostFtdcBrokerIDType	BrokerID;
	///期商分支机构代码
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	///交易日期
	TThostFtdcTradeDateType	TradeDate;
	///交易时间
	TThostFtdcTradeTimeType	TradeTime;
	///银行流水号
	TThostFtdcBankSerialType	BankSerial;
	///交易系统日期 
	TThostFtdcTradeDateType	TradingDay;
	///银期平台消息流水号
	int	PlateSerial;
	///最后分片标志
	char	LastFragment;
	///会话号
	int	SessionID;
	///安装编号
	int	InstallID;
	///用户标识
	TThostFtdcUserIDType	UserID;
	///摘要
	TThostFtdcDigestType	Digest;
	///币种代码
	TThostFtdcCurrencyIDType	CurrencyID;
	///渠道标志
	TThostFtdcDeviceIDType	DeviceID;
	///期货公司银行编码
	TThostFtdcBankCodingForFutureType	BrokerIDByBank;
	///交易柜员
	TThostFtdcOperNoType	OperNo;
	///请求编号
	int	RequestID;
	///交易ID
	int	TID;
};

///期商签退响应
struct CThostFtdcRspFutureSignOutField
{
	///业务功能码
	TThostFtdcTradeCodeType	TradeCode;
	///银行代码
	TThostFtdcBankIDType	BankID;
	///银行分支机构代码
	TThostFtdcBankBrchIDType	BankBranchID;
	///期商代码
	TThostFtdcBrokerIDType	BrokerID;
	///期商分支机构代码
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	///交易日期
	TThostFtdcTradeDateType	TradeDate;
	///交易时间
	TThostFtdcTradeTimeType	TradeTime;
	///银行流水号
	TThostFtdcBankSerialType	BankSerial;
	///交易系统日期 
	TThostFtdcTradeDateType	TradingDay;
	///银期平台消息流水号
	int	PlateSerial;
	///最后分片标志
	char	LastFragment;
	///会话号
	int	SessionID;
	///安装编号
	int	InstallID;
	///用户标识
	TThostFtdcUserIDType	UserID;
	///摘要
	TThostFtdcDigestType	Digest;
	///币种代码
	TThostFtdcCurrencyIDType	CurrencyID;
	///渠道标志
	TThostFtdcDeviceIDType	DeviceID;
	///期货公司银行编码
	TThostFtdcBankCodingForFutureType	BrokerIDByBank;
	///交易柜员
	TThostFtdcOperNoType	OperNo;
	///请求编号
	int	RequestID;
	///交易ID
	int	TID;
	///错误代码
	int	ErrorID;
	///错误信息
	TThostFtdcErrorMsgType	ErrorMsg;
};

///查询指定流水号的交易结果请求
struct CThostFtdcReqQueryTradeResultBySerialField
{
	///业务功能码
	TThostFtdcTradeCodeType	TradeCode;
	///银行代码
	TThostFtdcBankIDType	BankID;
	///银行分支机构代码
	TThostFtdcBankBrchIDType	BankBranchID;
	///期商代码
	TThostFtdcBrokerIDType	BrokerID;
	///期商分支机构代码
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	///交易日期
	TThostFtdcTradeDateType	TradeDate;
	///交易时间
	TThostFtdcTradeTimeType	TradeTime;
	///银行流水号
	TThostFtdcBankSerialType	BankSerial;
	///交易系统日期 
	TThostFtdcTradeDateType	TradingDay;
	///银期平台消息流水号
	int	PlateSerial;
	///最后分片标志
	char	LastFragment;
	///会话号
	int	SessionID;
	///流水号
	int	Reference;
	///本流水号发布者的机构类型
	char	RefrenceIssureType;
	///本流水号发布者机构编码
	TThostFtdcOrganCodeType	RefrenceIssure;
	///客户姓名
	TThostFtdcIndividualNameType	CustomerName;
	///证件类型
	char	IdCardType;
	///证件号码
	TThostFtdcIdentifiedCardNoType	IdentifiedCardNo;
	///客户类型
	char	CustType;
	///银行帐号
	TThostFtdcBankAccountType	BankAccount;
	///银行密码
	TThostFtdcPasswordType	BankPassWord;
	///投资者帐号
	TThostFtdcAccountIDType	AccountID;
	///期货密码
	TThostFtdcPasswordType	Password;
	///币种代码
	TThostFtdcCurrencyIDType	CurrencyID;
	///转帐金额
	double	TradeAmount;
	///摘要
	TThostFtdcDigestType	Digest;
};

///查询指定流水号的交易结果响应
struct CThostFtdcRspQueryTradeResultBySerialField
{
	///业务功能码
	TThostFtdcTradeCodeType	TradeCode;
	///银行代码
	TThostFtdcBankIDType	BankID;
	///银行分支机构代码
	TThostFtdcBankBrchIDType	BankBranchID;
	///期商代码
	TThostFtdcBrokerIDType	BrokerID;
	///期商分支机构代码
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	///交易日期
	TThostFtdcTradeDateType	TradeDate;
	///交易时间
	TThostFtdcTradeTimeType	TradeTime;
	///银行流水号
	TThostFtdcBankSerialType	BankSerial;
	///交易系统日期 
	TThostFtdcTradeDateType	TradingDay;
	///银期平台消息流水号
	int	PlateSerial;
	///最后分片标志
	char	LastFragment;
	///会话号
	int	SessionID;
	///错误代码
	int	ErrorID;
	///错误信息
	TThostFtdcErrorMsgType	ErrorMsg;
	///流水号
	int	Reference;
	///本流水号发布者的机构类型
	char	RefrenceIssureType;
	///本流水号发布者机构编码
	TThostFtdcOrganCodeType	RefrenceIssure;
	///原始返回代码
	TThostFtdcReturnCodeType	OriginReturnCode;
	///原始返回码描述
	TThostFtdcDescrInfoForReturnCodeType	OriginDescrInfoForReturnCode;
	///银行帐号
	TThostFtdcBankAccountType	BankAccount;
	///银行密码
	TThostFtdcPasswordType	BankPassWord;
	///投资者帐号
	TThostFtdcAccountIDType	AccountID;
	///期货密码
	TThostFtdcPasswordType	Password;
	///币种代码
	TThostFtdcCurrencyIDType	CurrencyID;
	///转帐金额
	double	TradeAmount;
	///摘要
	TThostFtdcDigestType	Digest;
};

///日终文件就绪请求
struct CThostFtdcReqDayEndFileReadyField
{
	///业务功能码
	TThostFtdcTradeCodeType	TradeCode;
	///银行代码
	TThostFtdcBankIDType	BankID;
	///银行分支机构代码
	TThostFtdcBankBrchIDType	BankBranchID;
	///期商代码
	TThostFtdcBrokerIDType	BrokerID;
	///期商分支机构代码
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	///交易日期
	TThostFtdcTradeDateType	TradeDate;
	///交易时间
	TThostFtdcTradeTimeType	TradeTime;
	///银行流水号
	TThostFtdcBankSerialType	BankSerial;
	///交易系统日期 
	TThostFtdcTradeDateType	TradingDay;
	///银期平台消息流水号
	int	PlateSerial;
	///最后分片标志
	char	LastFragment;
	///会话号
	int	SessionID;
	///文件业务功能
	char	FileBusinessCode;
	///摘要
	TThostFtdcDigestType	Digest;
};

///返回结果
struct CThostFtdcReturnResultField
{
	///返回代码
	TThostFtdcReturnCodeType	ReturnCode;
	///返回码描述
	TThostFtdcDescrInfoForReturnCodeType	DescrInfoForReturnCode;
};

///验证期货资金密码
struct CThostFtdcVerifyFuturePasswordField
{
	///业务功能码
	TThostFtdcTradeCodeType	TradeCode;
	///银行代码
	TThostFtdcBankIDType	BankID;
	///银行分支机构代码
	TThostFtdcBankBrchIDType	BankBranchID;
	///期商代码
	TThostFtdcBrokerIDType	BrokerID;
	///期商分支机构代码
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	///交易日期
	TThostFtdcTradeDateType	TradeDate;
	///交易时间
	TThostFtdcTradeTimeType	TradeTime;
	///银行流水号
	TThostFtdcBankSerialType	BankSerial;
	///交易系统日期 
	TThostFtdcTradeDateType	TradingDay;
	///银期平台消息流水号
	int	PlateSerial;
	///最后分片标志
	char	LastFragment;
	///会话号
	int	SessionID;
	///投资者帐号
	TThostFtdcAccountIDType	AccountID;
	///期货密码
	TThostFtdcPasswordType	Password;
	///银行帐号
	TThostFtdcBankAccountType	BankAccount;
	///银行密码
	TThostFtdcPasswordType	BankPassWord;
	///安装编号
	int	InstallID;
	///交易ID
	int	TID;
	///币种代码
	TThostFtdcCurrencyIDType	CurrencyID;
};

///验证客户信息
struct CThostFtdcVerifyCustInfoField
{
	///客户姓名
	TThostFtdcIndividualNameType	CustomerName;
	///证件类型
	char	IdCardType;
	///证件号码
	TThostFtdcIdentifiedCardNoType	IdentifiedCardNo;
	///客户类型
	char	CustType;
};

///验证期货资金密码和客户信息
struct CThostFtdcVerifyFuturePasswordAndCustInfoField
{
	///客户姓名
	TThostFtdcIndividualNameType	CustomerName;
	///证件类型
	char	IdCardType;
	///证件号码
	TThostFtdcIdentifiedCardNoType	IdentifiedCardNo;
	///客户类型
	char	CustType;
	///投资者帐号
	TThostFtdcAccountIDType	AccountID;
	///期货密码
	TThostFtdcPasswordType	Password;
	///币种代码
	TThostFtdcCurrencyIDType	CurrencyID;
};

///验证期货资金密码和客户信息
struct CThostFtdcDepositResultInformField
{
	///出入金流水号，该流水号为银期报盘返回的流水号
	TThostFtdcDepositSeqNoType	DepositSeqNo;
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///入金金额
	double	Deposit;
	///请求编号
	int	RequestID;
	///返回代码
	TThostFtdcReturnCodeType	ReturnCode;
	///返回码描述
	TThostFtdcDescrInfoForReturnCodeType	DescrInfoForReturnCode;
};

///交易核心向银期报盘发出密钥同步请求
struct CThostFtdcReqSyncKeyField
{
	///业务功能码
	TThostFtdcTradeCodeType	TradeCode;
	///银行代码
	TThostFtdcBankIDType	BankID;
	///银行分支机构代码
	TThostFtdcBankBrchIDType	BankBranchID;
	///期商代码
	TThostFtdcBrokerIDType	BrokerID;
	///期商分支机构代码
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	///交易日期
	TThostFtdcTradeDateType	TradeDate;
	///交易时间
	TThostFtdcTradeTimeType	TradeTime;
	///银行流水号
	TThostFtdcBankSerialType	BankSerial;
	///交易系统日期 
	TThostFtdcTradeDateType	TradingDay;
	///银期平台消息流水号
	int	PlateSerial;
	///最后分片标志
	char	LastFragment;
	///会话号
	int	SessionID;
	///安装编号
	int	InstallID;
	///用户标识
	TThostFtdcUserIDType	UserID;
	///交易核心给银期报盘的消息
	TThostFtdcAddInfoType	Message;
	///渠道标志
	TThostFtdcDeviceIDType	DeviceID;
	///期货公司银行编码
	TThostFtdcBankCodingForFutureType	BrokerIDByBank;
	///交易柜员
	TThostFtdcOperNoType	OperNo;
	///请求编号
	int	RequestID;
	///交易ID
	int	TID;
};

///交易核心向银期报盘发出密钥同步响应
struct CThostFtdcRspSyncKeyField
{
	///业务功能码
	TThostFtdcTradeCodeType	TradeCode;
	///银行代码
	TThostFtdcBankIDType	BankID;
	///银行分支机构代码
	TThostFtdcBankBrchIDType	BankBranchID;
	///期商代码
	TThostFtdcBrokerIDType	BrokerID;
	///期商分支机构代码
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	///交易日期
	TThostFtdcTradeDateType	TradeDate;
	///交易时间
	TThostFtdcTradeTimeType	TradeTime;
	///银行流水号
	TThostFtdcBankSerialType	BankSerial;
	///交易系统日期 
	TThostFtdcTradeDateType	TradingDay;
	///银期平台消息流水号
	int	PlateSerial;
	///最后分片标志
	char	LastFragment;
	///会话号
	int	SessionID;
	///安装编号
	int	InstallID;
	///用户标识
	TThostFtdcUserIDType	UserID;
	///交易核心给银期报盘的消息
	TThostFtdcAddInfoType	Message;
	///渠道标志
	TThostFtdcDeviceIDType	DeviceID;
	///期货公司银行编码
	TThostFtdcBankCodingForFutureType	BrokerIDByBank;
	///交易柜员
	TThostFtdcOperNoType	OperNo;
	///请求编号
	int	RequestID;
	///交易ID
	int	TID;
	///错误代码
	int	ErrorID;
	///错误信息
	TThostFtdcErrorMsgType	ErrorMsg;
};

///查询账户信息通知
struct CThostFtdcNotifyQueryAccountField
{
	///业务功能码
	TThostFtdcTradeCodeType	TradeCode;
	///银行代码
	TThostFtdcBankIDType	BankID;
	///银行分支机构代码
	TThostFtdcBankBrchIDType	BankBranchID;
	///期商代码
	TThostFtdcBrokerIDType	BrokerID;
	///期商分支机构代码
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	///交易日期
	TThostFtdcTradeDateType	TradeDate;
	///交易时间
	TThostFtdcTradeTimeType	TradeTime;
	///银行流水号
	TThostFtdcBankSerialType	BankSerial;
	///交易系统日期 
	TThostFtdcTradeDateType	TradingDay;
	///银期平台消息流水号
	int	PlateSerial;
	///最后分片标志
	char	LastFragment;
	///会话号
	int	SessionID;
	///客户姓名
	TThostFtdcIndividualNameType	CustomerName;
	///证件类型
	char	IdCardType;
	///证件号码
	TThostFtdcIdentifiedCardNoType	IdentifiedCardNo;
	///客户类型
	char	CustType;
	///银行帐号
	TThostFtdcBankAccountType	BankAccount;
	///银行密码
	TThostFtdcPasswordType	BankPassWord;
	///投资者帐号
	TThostFtdcAccountIDType	AccountID;
	///期货密码
	TThostFtdcPasswordType	Password;
	///期货公司流水号
	int	FutureSerial;
	///安装编号
	int	InstallID;
	///用户标识
	TThostFtdcUserIDType	UserID;
	///验证客户证件号码标志
	char	VerifyCertNoFlag;
	///币种代码
	TThostFtdcCurrencyIDType	CurrencyID;
	///摘要
	TThostFtdcDigestType	Digest;
	///银行帐号类型
	char	BankAccType;
	///渠道标志
	TThostFtdcDeviceIDType	DeviceID;
	///期货单位帐号类型
	char	BankSecuAccType;
	///期货公司银行编码
	TThostFtdcBankCodingForFutureType	BrokerIDByBank;
	///期货单位帐号
	TThostFtdcBankAccountType	BankSecuAcc;
	///银行密码标志
	char	BankPwdFlag;
	///期货资金密码核对标志
	char	SecuPwdFlag;
	///交易柜员
	TThostFtdcOperNoType	OperNo;
	///请求编号
	int	RequestID;
	///交易ID
	int	TID;
	///银行可用金额
	double	BankUseAmount;
	///银行可取金额
	double	BankFetchAmount;
	///错误代码
	int	ErrorID;
	///错误信息
	TThostFtdcErrorMsgType	ErrorMsg;
};

///银期转账交易流水表
struct CThostFtdcTransferSerialField
{
	///平台流水号
	int	PlateSerial;
	///交易发起方日期
	TThostFtdcTradeDateType	TradeDate;
	///交易日期
	TThostFtdcDateType	TradingDay;
	///交易时间
	TThostFtdcTradeTimeType	TradeTime;
	///交易代码
	TThostFtdcTradeCodeType	TradeCode;
	///会话编号
	int	SessionID;
	///银行编码
	TThostFtdcBankIDType	BankID;
	///银行分支机构编码
	TThostFtdcBankBrchIDType	BankBranchID;
	///银行帐号类型
	char	BankAccType;
	///银行帐号
	TThostFtdcBankAccountType	BankAccount;
	///银行流水号
	TThostFtdcBankSerialType	BankSerial;
	///期货公司编码
	TThostFtdcBrokerIDType	BrokerID;
	///期商分支机构代码
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	///期货公司帐号类型
	char	FutureAccType;
	///投资者帐号
	TThostFtdcAccountIDType	AccountID;
	///投资者代码
	TThostFtdcInvestorIDType	InvestorID;
	///期货公司流水号
	int	FutureSerial;
	///证件类型
	char	IdCardType;
	///证件号码
	TThostFtdcIdentifiedCardNoType	IdentifiedCardNo;
	///币种代码
	TThostFtdcCurrencyIDType	CurrencyID;
	///交易金额
	double	TradeAmount;
	///应收客户费用
	double	CustFee;
	///应收期货公司费用
	double	BrokerFee;
	///有效标志
	char	AvailabilityFlag;
	///操作员
	TThostFtdcOperatorCodeType	OperatorCode;
	///新银行帐号
	TThostFtdcBankAccountType	BankNewAccount;
	///错误代码
	int	ErrorID;
	///错误信息
	TThostFtdcErrorMsgType	ErrorMsg;
};

///请求查询转帐流水
struct CThostFtdcQryTransferSerialField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者帐号
	TThostFtdcAccountIDType	AccountID;
	///银行编码
	TThostFtdcBankIDType	BankID;
	///币种代码
	TThostFtdcCurrencyIDType	CurrencyID;
};

///期商签到通知
struct CThostFtdcNotifyFutureSignInField
{
	///业务功能码
	TThostFtdcTradeCodeType	TradeCode;
	///银行代码
	TThostFtdcBankIDType	BankID;
	///银行分支机构代码
	TThostFtdcBankBrchIDType	BankBranchID;
	///期商代码
	TThostFtdcBrokerIDType	BrokerID;
	///期商分支机构代码
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	///交易日期
	TThostFtdcTradeDateType	TradeDate;
	///交易时间
	TThostFtdcTradeTimeType	TradeTime;
	///银行流水号
	TThostFtdcBankSerialType	BankSerial;
	///交易系统日期 
	TThostFtdcTradeDateType	TradingDay;
	///银期平台消息流水号
	int	PlateSerial;
	///最后分片标志
	char	LastFragment;
	///会话号
	int	SessionID;
	///安装编号
	int	InstallID;
	///用户标识
	TThostFtdcUserIDType	UserID;
	///摘要
	TThostFtdcDigestType	Digest;
	///币种代码
	TThostFtdcCurrencyIDType	CurrencyID;
	///渠道标志
	TThostFtdcDeviceIDType	DeviceID;
	///期货公司银行编码
	TThostFtdcBankCodingForFutureType	BrokerIDByBank;
	///交易柜员
	TThostFtdcOperNoType	OperNo;
	///请求编号
	int	RequestID;
	///交易ID
	int	TID;
	///错误代码
	int	ErrorID;
	///错误信息
	TThostFtdcErrorMsgType	ErrorMsg;
	///PIN密钥
	TThostFtdcPasswordKeyType	PinKey;
	///MAC密钥
	TThostFtdcPasswordKeyType	MacKey;
};

///期商签退通知
struct CThostFtdcNotifyFutureSignOutField
{
	///业务功能码
	TThostFtdcTradeCodeType	TradeCode;
	///银行代码
	TThostFtdcBankIDType	BankID;
	///银行分支机构代码
	TThostFtdcBankBrchIDType	BankBranchID;
	///期商代码
	TThostFtdcBrokerIDType	BrokerID;
	///期商分支机构代码
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	///交易日期
	TThostFtdcTradeDateType	TradeDate;
	///交易时间
	TThostFtdcTradeTimeType	TradeTime;
	///银行流水号
	TThostFtdcBankSerialType	BankSerial;
	///交易系统日期 
	TThostFtdcTradeDateType	TradingDay;
	///银期平台消息流水号
	int	PlateSerial;
	///最后分片标志
	char	LastFragment;
	///会话号
	int	SessionID;
	///安装编号
	int	InstallID;
	///用户标识
	TThostFtdcUserIDType	UserID;
	///摘要
	TThostFtdcDigestType	Digest;
	///币种代码
	TThostFtdcCurrencyIDType	CurrencyID;
	///渠道标志
	TThostFtdcDeviceIDType	DeviceID;
	///期货公司银行编码
	TThostFtdcBankCodingForFutureType	BrokerIDByBank;
	///交易柜员
	TThostFtdcOperNoType	OperNo;
	///请求编号
	int	RequestID;
	///交易ID
	int	TID;
	///错误代码
	int	ErrorID;
	///错误信息
	TThostFtdcErrorMsgType	ErrorMsg;
};

///交易核心向银期报盘发出密钥同步处理结果的通知
struct CThostFtdcNotifySyncKeyField
{
	///业务功能码
	TThostFtdcTradeCodeType	TradeCode;
	///银行代码
	TThostFtdcBankIDType	BankID;
	///银行分支机构代码
	TThostFtdcBankBrchIDType	BankBranchID;
	///期商代码
	TThostFtdcBrokerIDType	BrokerID;
	///期商分支机构代码
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	///交易日期
	TThostFtdcTradeDateType	TradeDate;
	///交易时间
	TThostFtdcTradeTimeType	TradeTime;
	///银行流水号
	TThostFtdcBankSerialType	BankSerial;
	///交易系统日期 
	TThostFtdcTradeDateType	TradingDay;
	///银期平台消息流水号
	int	PlateSerial;
	///最后分片标志
	char	LastFragment;
	///会话号
	int	SessionID;
	///安装编号
	int	InstallID;
	///用户标识
	TThostFtdcUserIDType	UserID;
	///交易核心给银期报盘的消息
	TThostFtdcAddInfoType	Message;
	///渠道标志
	TThostFtdcDeviceIDType	DeviceID;
	///期货公司银行编码
	TThostFtdcBankCodingForFutureType	BrokerIDByBank;
	///交易柜员
	TThostFtdcOperNoType	OperNo;
	///请求编号
	int	RequestID;
	///交易ID
	int	TID;
	///错误代码
	int	ErrorID;
	///错误信息
	TThostFtdcErrorMsgType	ErrorMsg;
};

///请求查询银期签约关系
struct CThostFtdcQryAccountregisterField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者帐号
	TThostFtdcAccountIDType	AccountID;
	///银行编码
	TThostFtdcBankIDType	BankID;
	///银行分支机构编码
	TThostFtdcBankBrchIDType	BankBranchID;
	///币种代码
	TThostFtdcCurrencyIDType	CurrencyID;
};

///客户开销户信息表
struct CThostFtdcAccountregisterField
{
	///交易日期
	TThostFtdcTradeDateType	TradeDay;
	///银行编码
	TThostFtdcBankIDType	BankID;
	///银行分支机构编码
	TThostFtdcBankBrchIDType	BankBranchID;
	///银行帐号
	TThostFtdcBankAccountType	BankAccount;
	///期货公司编码
	TThostFtdcBrokerIDType	BrokerID;
	///期货公司分支机构编码
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	///投资者帐号
	TThostFtdcAccountIDType	AccountID;
	///证件类型
	char	IdCardType;
	///证件号码
	TThostFtdcIdentifiedCardNoType	IdentifiedCardNo;
	///客户姓名
	TThostFtdcIndividualNameType	CustomerName;
	///币种代码
	TThostFtdcCurrencyIDType	CurrencyID;
	///开销户类别
	char	OpenOrDestroy;
	///签约日期
	TThostFtdcTradeDateType	RegDate;
	///解约日期
	TThostFtdcTradeDateType	OutDate;
	///交易ID
	int	TID;
	///客户类型
	char	CustType;
	///银行帐号类型
	char	BankAccType;
};

///银期开户信息
struct CThostFtdcOpenAccountField
{
	///业务功能码
	TThostFtdcTradeCodeType	TradeCode;
	///银行代码
	TThostFtdcBankIDType	BankID;
	///银行分支机构代码
	TThostFtdcBankBrchIDType	BankBranchID;
	///期商代码
	TThostFtdcBrokerIDType	BrokerID;
	///期商分支机构代码
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	///交易日期
	TThostFtdcTradeDateType	TradeDate;
	///交易时间
	TThostFtdcTradeTimeType	TradeTime;
	///银行流水号
	TThostFtdcBankSerialType	BankSerial;
	///交易系统日期 
	TThostFtdcTradeDateType	TradingDay;
	///银期平台消息流水号
	int	PlateSerial;
	///最后分片标志
	char	LastFragment;
	///会话号
	int	SessionID;
	///客户姓名
	TThostFtdcIndividualNameType	CustomerName;
	///证件类型
	char	IdCardType;
	///证件号码
	TThostFtdcIdentifiedCardNoType	IdentifiedCardNo;
	///性别
	char	Gender;
	///国家代码
	TThostFtdcCountryCodeType	CountryCode;
	///客户类型
	char	CustType;
	///地址
	TThostFtdcAddressType	Address;
	///邮编
	TThostFtdcZipCodeType	ZipCode;
	///电话号码
	TThostFtdcTelephoneType	Telephone;
	///手机
	TThostFtdcMobilePhoneType	MobilePhone;
	///传真
	TThostFtdcFaxType	Fax;
	///电子邮件
	TThostFtdcEMailType	EMail;
	///资金账户状态
	char	MoneyAccountStatus;
	///银行帐号
	TThostFtdcBankAccountType	BankAccount;
	///银行密码
	TThostFtdcPasswordType	BankPassWord;
	///投资者帐号
	TThostFtdcAccountIDType	AccountID;
	///期货密码
	TThostFtdcPasswordType	Password;
	///安装编号
	int	InstallID;
	///验证客户证件号码标志
	char	VerifyCertNoFlag;
	///币种代码
	TThostFtdcCurrencyIDType	CurrencyID;
	///汇钞标志
	char	CashExchangeCode;
	///摘要
	TThostFtdcDigestType	Digest;
	///银行帐号类型
	char	BankAccType;
	///渠道标志
	TThostFtdcDeviceIDType	DeviceID;
	///期货单位帐号类型
	char	BankSecuAccType;
	///期货公司银行编码
	TThostFtdcBankCodingForFutureType	BrokerIDByBank;
	///期货单位帐号
	TThostFtdcBankAccountType	BankSecuAcc;
	///银行密码标志
	char	BankPwdFlag;
	///期货资金密码核对标志
	char	SecuPwdFlag;
	///交易柜员
	TThostFtdcOperNoType	OperNo;
	///交易ID
	int	TID;
	///用户标识
	TThostFtdcUserIDType	UserID;
	///错误代码
	int	ErrorID;
	///错误信息
	TThostFtdcErrorMsgType	ErrorMsg;
};

///银期销户信息
struct CThostFtdcCancelAccountField
{
	///业务功能码
	TThostFtdcTradeCodeType	TradeCode;
	///银行代码
	TThostFtdcBankIDType	BankID;
	///银行分支机构代码
	TThostFtdcBankBrchIDType	BankBranchID;
	///期商代码
	TThostFtdcBrokerIDType	BrokerID;
	///期商分支机构代码
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	///交易日期
	TThostFtdcTradeDateType	TradeDate;
	///交易时间
	TThostFtdcTradeTimeType	TradeTime;
	///银行流水号
	TThostFtdcBankSerialType	BankSerial;
	///交易系统日期 
	TThostFtdcTradeDateType	TradingDay;
	///银期平台消息流水号
	int	PlateSerial;
	///最后分片标志
	char	LastFragment;
	///会话号
	int	SessionID;
	///客户姓名
	TThostFtdcIndividualNameType	CustomerName;
	///证件类型
	char	IdCardType;
	///证件号码
	TThostFtdcIdentifiedCardNoType	IdentifiedCardNo;
	///性别
	char	Gender;
	///国家代码
	TThostFtdcCountryCodeType	CountryCode;
	///客户类型
	char	CustType;
	///地址
	TThostFtdcAddressType	Address;
	///邮编
	TThostFtdcZipCodeType	ZipCode;
	///电话号码
	TThostFtdcTelephoneType	Telephone;
	///手机
	TThostFtdcMobilePhoneType	MobilePhone;
	///传真
	TThostFtdcFaxType	Fax;
	///电子邮件
	TThostFtdcEMailType	EMail;
	///资金账户状态
	char	MoneyAccountStatus;
	///银行帐号
	TThostFtdcBankAccountType	BankAccount;
	///银行密码
	TThostFtdcPasswordType	BankPassWord;
	///投资者帐号
	TThostFtdcAccountIDType	AccountID;
	///期货密码
	TThostFtdcPasswordType	Password;
	///安装编号
	int	InstallID;
	///验证客户证件号码标志
	char	VerifyCertNoFlag;
	///币种代码
	TThostFtdcCurrencyIDType	CurrencyID;
	///汇钞标志
	char	CashExchangeCode;
	///摘要
	TThostFtdcDigestType	Digest;
	///银行帐号类型
	char	BankAccType;
	///渠道标志
	TThostFtdcDeviceIDType	DeviceID;
	///期货单位帐号类型
	char	BankSecuAccType;
	///期货公司银行编码
	TThostFtdcBankCodingForFutureType	BrokerIDByBank;
	///期货单位帐号
	TThostFtdcBankAccountType	BankSecuAcc;
	///银行密码标志
	char	BankPwdFlag;
	///期货资金密码核对标志
	char	SecuPwdFlag;
	///交易柜员
	TThostFtdcOperNoType	OperNo;
	///交易ID
	int	TID;
	///用户标识
	TThostFtdcUserIDType	UserID;
	///错误代码
	int	ErrorID;
	///错误信息
	TThostFtdcErrorMsgType	ErrorMsg;
};

///银期变更银行账号信息
struct CThostFtdcChangeAccountField
{
	///业务功能码
	TThostFtdcTradeCodeType	TradeCode;
	///银行代码
	TThostFtdcBankIDType	BankID;
	///银行分支机构代码
	TThostFtdcBankBrchIDType	BankBranchID;
	///期商代码
	TThostFtdcBrokerIDType	BrokerID;
	///期商分支机构代码
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	///交易日期
	TThostFtdcTradeDateType	TradeDate;
	///交易时间
	TThostFtdcTradeTimeType	TradeTime;
	///银行流水号
	TThostFtdcBankSerialType	BankSerial;
	///交易系统日期 
	TThostFtdcTradeDateType	TradingDay;
	///银期平台消息流水号
	int	PlateSerial;
	///最后分片标志
	char	LastFragment;
	///会话号
	int	SessionID;
	///客户姓名
	TThostFtdcIndividualNameType	CustomerName;
	///证件类型
	char	IdCardType;
	///证件号码
	TThostFtdcIdentifiedCardNoType	IdentifiedCardNo;
	///性别
	char	Gender;
	///国家代码
	TThostFtdcCountryCodeType	CountryCode;
	///客户类型
	char	CustType;
	///地址
	TThostFtdcAddressType	Address;
	///邮编
	TThostFtdcZipCodeType	ZipCode;
	///电话号码
	TThostFtdcTelephoneType	Telephone;
	///手机
	TThostFtdcMobilePhoneType	MobilePhone;
	///传真
	TThostFtdcFaxType	Fax;
	///电子邮件
	TThostFtdcEMailType	EMail;
	///资金账户状态
	char	MoneyAccountStatus;
	///银行帐号
	TThostFtdcBankAccountType	BankAccount;
	///银行密码
	TThostFtdcPasswordType	BankPassWord;
	///新银行帐号
	TThostFtdcBankAccountType	NewBankAccount;
	///新银行密码
	TThostFtdcPasswordType	NewBankPassWord;
	///投资者帐号
	TThostFtdcAccountIDType	AccountID;
	///期货密码
	TThostFtdcPasswordType	Password;
	///银行帐号类型
	char	BankAccType;
	///安装编号
	int	InstallID;
	///验证客户证件号码标志
	char	VerifyCertNoFlag;
	///币种代码
	TThostFtdcCurrencyIDType	CurrencyID;
	///期货公司银行编码
	TThostFtdcBankCodingForFutureType	BrokerIDByBank;
	///银行密码标志
	char	BankPwdFlag;
	///期货资金密码核对标志
	char	SecuPwdFlag;
	///交易ID
	int	TID;
	///摘要
	TThostFtdcDigestType	Digest;
	///错误代码
	int	ErrorID;
	///错误信息
	TThostFtdcErrorMsgType	ErrorMsg;
};

///二级代理操作员银期权限
struct CThostFtdcSecAgentACIDMapField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///用户代码
	TThostFtdcUserIDType	UserID;
	///资金账户
	TThostFtdcAccountIDType	AccountID;
	///币种
	TThostFtdcCurrencyIDType	CurrencyID;
	///境外中介机构资金帐号
	TThostFtdcAccountIDType	BrokerSecAgentID;
};

///二级代理操作员银期权限查询
struct CThostFtdcQrySecAgentACIDMapField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///用户代码
	TThostFtdcUserIDType	UserID;
	///资金账户
	TThostFtdcAccountIDType	AccountID;
	///币种
	TThostFtdcCurrencyIDType	CurrencyID;
};

///灾备中心交易权限
struct CThostFtdcUserRightsAssignField
{
	///应用单元代码
	TThostFtdcBrokerIDType	BrokerID;
	///用户代码
	TThostFtdcUserIDType	UserID;
	///交易中心代码
	int	DRIdentityID;
};

///经济公司是否有在本标示的交易权限
struct CThostFtdcBrokerUserRightAssignField
{
	///应用单元代码
	TThostFtdcBrokerIDType	BrokerID;
	///交易中心代码
	int	DRIdentityID;
	///能否交易
	int	Tradeable;
};

///灾备交易转换报文
struct CThostFtdcDRTransferField
{
	///原交易中心代码
	int	OrigDRIdentityID;
	///目标交易中心代码
	int	DestDRIdentityID;
	///原应用单元代码
	TThostFtdcBrokerIDType	OrigBrokerID;
	///目标易用单元代码
	TThostFtdcBrokerIDType	DestBrokerID;
};

///Fens用户信息
struct CThostFtdcFensUserInfoField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///用户代码
	TThostFtdcUserIDType	UserID;
	///登录模式
	char	LoginMode;
};

///当前银期所属交易中心
struct CThostFtdcCurrTransferIdentityField
{
	///交易中心代码
	int	IdentityID;
};

///禁止登录用户
struct CThostFtdcLoginForbiddenUserField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///用户代码
	TThostFtdcUserIDType	UserID;
	///IP地址
	TThostFtdcIPAddressType	IPAddress;
};

///查询禁止登录用户
struct CThostFtdcQryLoginForbiddenUserField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///用户代码
	TThostFtdcUserIDType	UserID;
};

///UDP组播组信息
struct CThostFtdcMulticastGroupInfoField
{
	///组播组IP地址
	TThostFtdcIPAddressType	GroupIP;
	///组播组IP端口
	int	GroupPort;
	///源地址
	TThostFtdcIPAddressType	SourceIP;
};

///资金账户基本准备金
struct CThostFtdcTradingAccountReserveField
{
	///经纪公司代码
	TThostFtdcBrokerIDType	BrokerID;
	///投资者帐号
	TThostFtdcAccountIDType	AccountID;
	///基本准备金
	double	Reserve;
	///币种代码
	TThostFtdcCurrencyIDType	CurrencyID;
};

///银期预约开户确认请求
struct CThostFtdcReserveOpenAccountConfirmField
{
	///业务功能码
	TThostFtdcTradeCodeType	TradeCode;
	///银行代码
	TThostFtdcBankIDType	BankID;
	///银行分支机构代码
	TThostFtdcBankBrchIDType	BankBranchID;
	///期商代码
	TThostFtdcBrokerIDType	BrokerID;
	///期商分支机构代码
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	///交易日期
	TThostFtdcTradeDateType	TradeDate;
	///交易时间
	TThostFtdcTradeTimeType	TradeTime;
	///银行流水号
	TThostFtdcBankSerialType	BankSerial;
	///交易系统日期 
	TThostFtdcTradeDateType	TradingDay;
	///银期平台消息流水号
	int	PlateSerial;
	///最后分片标志
	char	LastFragment;
	///会话号
	int	SessionID;
	///客户姓名
	TThostFtdcIndividualNameType	CustomerName;
	///证件类型
	char	IdCardType;
	///证件号码
	TThostFtdcIdentifiedCardNoType	IdentifiedCardNo;
	///性别
	char	Gender;
	///国家代码
	TThostFtdcCountryCodeType	CountryCode;
	///客户类型
	char	CustType;
	///地址
	TThostFtdcAddressType	Address;
	///邮编
	TThostFtdcZipCodeType	ZipCode;
	///电话号码
	TThostFtdcTelephoneType	Telephone;
	///手机
	TThostFtdcMobilePhoneType	MobilePhone;
	///传真
	TThostFtdcFaxType	Fax;
	///电子邮件
	TThostFtdcEMailType	EMail;
	///资金账户状态
	char	MoneyAccountStatus;
	///银行帐号
	TThostFtdcBankAccountType	BankAccount;
	///银行密码
	TThostFtdcPasswordType	BankPassWord;
	///安装编号
	int	InstallID;
	///验证客户证件号码标志
	char	VerifyCertNoFlag;
	///币种代码
	TThostFtdcCurrencyIDType	CurrencyID;
	///摘要
	TThostFtdcDigestType	Digest;
	///银行帐号类型
	char	BankAccType;
	///期货公司银行编码
	TThostFtdcBankCodingForFutureType	BrokerIDByBank;
	///交易ID
	int	TID;
	///投资者帐号
	TThostFtdcAccountIDType	AccountID;
	///期货密码
	TThostFtdcPasswordType	Password;
	///预约开户银行流水号
	TThostFtdcBankSerialType	BankReserveOpenSeq;
	///预约开户日期
	TThostFtdcTradeDateType	BookDate;
	///预约开户验证密码
	TThostFtdcPasswordType	BookPsw;
	///错误代码
	int	ErrorID;
	///错误信息
	TThostFtdcErrorMsgType	ErrorMsg;
};

///银期预约开户
struct CThostFtdcReserveOpenAccountField
{
	///业务功能码
	TThostFtdcTradeCodeType	TradeCode;
	///银行代码
	TThostFtdcBankIDType	BankID;
	///银行分支机构代码
	TThostFtdcBankBrchIDType	BankBranchID;
	///期商代码
	TThostFtdcBrokerIDType	BrokerID;
	///期商分支机构代码
	TThostFtdcFutureBranchIDType	BrokerBranchID;
	///交易日期
	TThostFtdcTradeDateType	TradeDate;
	///交易时间
	TThostFtdcTradeTimeType	TradeTime;
	///银行流水号
	TThostFtdcBankSerialType	BankSerial;
	///交易系统日期 
	TThostFtdcTradeDateType	TradingDay;
	///银期平台消息流水号
	int	PlateSerial;
	///最后分片标志
	char	LastFragment;
	///会话号
	int	SessionID;
	///客户姓名
	TThostFtdcIndividualNameType	CustomerName;
	///证件类型
	char	IdCardType;
	///证件号码
	TThostFtdcIdentifiedCardNoType	IdentifiedCardNo;
	///性别
	char	Gender;
	///国家代码
	TThostFtdcCountryCodeType	CountryCode;
	///客户类型
	char	CustType;
	///地址
	TThostFtdcAddressType	Address;
	///邮编
	TThostFtdcZipCodeType	ZipCode;
	///电话号码
	TThostFtdcTelephoneType	Telephone;
	///手机
	TThostFtdcMobilePhoneType	MobilePhone;
	///传真
	TThostFtdcFaxType	Fax;
	///电子邮件
	TThostFtdcEMailType	EMail;
	///资金账户状态
	char	MoneyAccountStatus;
	///银行帐号
	TThostFtdcBankAccountType	BankAccount;
	///银行密码
	TThostFtdcPasswordType	BankPassWord;
	///安装编号
	int	InstallID;
	///验证客户证件号码标志
	char	VerifyCertNoFlag;
	///币种代码
	TThostFtdcCurrencyIDType	CurrencyID;
	///摘要
	TThostFtdcDigestType	Digest;
	///银行帐号类型
	char	BankAccType;
	///期货公司银行编码
	TThostFtdcBankCodingForFutureType	BrokerIDByBank;
	///交易ID
	int	TID;
	///预约开户状态
	char	ReserveOpenAccStas;
	///错误代码
	int	ErrorID;
	///错误信息
	TThostFtdcErrorMsgType	ErrorMsg;
};



#endif
