//
//  CurrentUserInformation.h
//  F103CZFW
//
//  Created by 张利广 on 13-5-21.
//  Copyright (c) 2013年 zhang liguang. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSInteger, CurrentUserInformationSecretCode)
{
    CurrentUserInformationSecretCodeNO                   = 0,       //无需加密
    CurrentUserInformationSecretCodeUserID               = 1,       //对用户userid加密
    CurrentUserInformationSecretCodeTel                  = 2,       //对用户tel加密
    CurrentUserInformationSecretCodeIdentityCard         = 3,       //对用户身份证号加密
    CurrentUserInformationSecretCodeBankCard             = 4         //对用户银行卡号加密
};
typedef void(^UserCheckInfoCompletedBlock)();


@interface CurrentUserInformation : NSObject

@property (nonatomic,copy)NSString       *userName;//输入的name
@property (nonatomic,copy)NSString       *personName; // 新的用户名
@property (nonatomic,copy)NSString       *touxiangsde;// 头像链接
@property (nonatomic,copy)NSString       *userId;
@property (nonatomic,copy)NSString       *vipbiaozhi;
@property (nonatomic,copy)NSString       *vipzigefenxiang;
@property (nonatomic,copy)NSString       *usrcustid;
@property (nonatomic,copy)NSString       *vipzige;

@property (nonatomic,assign)int          shiming; // 实名和开通汇付
@property (nonatomic,copy)NSString       *touxiang;
@property (nonatomic,copy) NSString      *toubiaocishu;
@property (nonatomic,copy) NSString      *mobile;
@property (nonatomic,copy) NSString      *iszdtou;
@property (nonatomic,copy) NSString      *hfkai;// 开通恒丰
@property (nonatomic,copy) NSString      *zhenshiname;
@property (nonatomic,copy) NSString      *shenfenzhenghao;
@property (nonatomic,copy) NSString      *jymimafou;
@property (nonatomic,copy) NSString      *banbenhao;
@property (nonatomic,copy) NSString      *startTime;
@property (nonatomic,copy) NSString      *wenjuanxianshi;

@property (nonatomic,copy) NSString      *fengxianwenjuan;
@property (nonatomic,copy) NSString      *fengxianwenjuanwode;

@property (nonatomic,copy) NSString      *weishangbang;//1已绑定徽商0未绑定 ,只绑卡
@property (nonatomic,copy) NSString      *jiaoyimshezhi;//1设置交易密码0未设置
@property (nonatomic,copy) NSString      *huishangshiming;//徽商实名，开立徽商电子账户 //1实名2未实名
@property (nonatomic,copy) NSString      *jihuohuishang;//激活徽商的状态0无状态1未激活2已激活

@property (nonatomic,copy) NSString      *idenshuxing;//用户信息网络数据属性，0-7种情况判断（0是只注册未开账户）===身份属性
@property (nonatomic,copy) NSString      *defidenshuxing;//用户信息默认账户0-1-2-4===默认属性
//用户请求的角色的手机号
@property (nonatomic,copy) NSString       *defmobile;
@property (nonatomic,copy) NSString       *isautho;//1 未授权 2 授权
@property (nonatomic,copy) NSString       *isenterp;//1个人2企业
@property (nonatomic,copy) NSString       *ismindeng;//是否投资过民登--0未投资过，1投资过
@property (nonatomic,copy) NSString       *mdEye;//民登
@property (nonatomic,copy) NSString       *rtEye;//融托
@property (nonatomic,copy) NSString       *rtWithMdEye;//融托民登外层

@property (nonatomic,copy) NSString      *Password;//用户密码
@property (nonatomic,copy) NSString      *userAccountType;//用户信息属性类型===1为投资账户2为借款账户4为担保账户，0-未开通账户
@property (nonatomic,copy) NSString      *fengxiandj;//评估等级（0-未评估，1-保守型，2-稳健型，3-积极型，4-过期）

///用户登录状态
@property (nonatomic, assign) NSInteger userLoginState;
//带有加密的userid
@property (nonatomic,copy) NSString * userid_secret;


@property (nonatomic,copy) NSString *istouchuan;//绑卡的时候是否为透传接口

//测试使用的变量，用来修改userID的，只是用来在app未退出时，禁止将userID再改回来
@property (nonatomic, assign) NSInteger noChangeUserid;
// 请求数据成功修改头像
//@property (nonatomic, copy) void(^blockChangeUserIcon)(CurrentUserInformation *);

+(CurrentUserInformation *)sharedCurrentUserInfo;

+(void)initializaionUserInformation:(NSDictionary *)userInfoDic;
- (void)cleanAllUserInfo;

-(void)checkUserInfoWithNetWork;
-(void)checkUserInfoWithNetWorkWithBlock:(UserCheckInfoCompletedBlock)completeBlock;

-(void)userQuiteWithApp;

-(void)checkFigureJudge;
- (void)userFromArachiver;//获取用户信息user
+ (void)saveUserObjectWithUser:(CurrentUserInformation *)user;

-(void)getUserInformationDataFromNetwork;


//返回带有加密字符的参数，加密方式先交换位置，再插入交换位置的所生成的字符串，最后转化成base64形式
-(NSString *)retStringWithBase64:(CurrentUserInformationSecretCode)code;

//返回带有加密字符的参数，加密方式先交换位置，再插入交换位置的所生成的字符串，最后转化成base64形式
-(NSString *)retStringWithBase64:(CurrentUserInformationSecretCode)code WithString:(NSString *)codeString;



@end
