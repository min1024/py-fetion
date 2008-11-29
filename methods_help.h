/* methods_help.h
 * Heihaier <admin@heihaier.org>
 * http://www.heihaier.org
 */

#ifndef __METHODS_HELP_H__
#define __METHODS_HELP_H__

#define HELP_INIT	"init(None)\n\
\n\
If you want to use the pyfetion, you must invoke this function at first.\n\
\n\
Returns:\n\
\tTrue  : init successfully.\n\
\tFalse : init fail."

#define HELP_TERMINATE	"terminate(None)\n\
\n\
Shutdown the pyfetion, when pyfetion ins't used any more.\n\
\n\
Returns: None"

#define HELP_CLOSE_NETWORK	"close_network(None)\n\
\n\
Shutdown the connect to fetion's servers.\n\
\n\
Returns:\n\
\tTrue  : close network successfully.\n\
\tFalse : close network fail."

#define HELP_SET_LOGIN_STATUS	"set_login_status(login_status)\n\
\n\
Set the user login status.\n\
\n\
Parameters:\n\
\tlogin_status : string, The login status of you want to set.\n\
\t\tunset\n\
\t\tonline\n\
\t\tbusy\n\
\t\taway\n\
\t\tdinner\n\
\t\toffline\n\
\t\tmeeting\n\
\t\tphone\n\
\t\textended_away\n\
\t\tnum_primitives\n\
\t\twaiting_auth\n\
\t\trefuse\n\
\t\tblack\n\
\t\tmobile\n\
\n\
Returns : None"

#define HELP_LOGIN	"login(uid, password, callback_func, args)\n\
\n\
Login fetion.\n\
\n\
Parameters:\n\
\tuid : string, The login info the user id or mobile number.\n\
\tpassword : string, The login info of the user password.\n\
\tcallback_func : function, The login callback function.\n\
\t\tdef login_cb(msg, arg):\n\
\t\t\tParameters:\n\
\t\t\t\tmsg : string, The login message.\n\
\t\t\t\t\tconnecting\n\
\t\t\t\t\twait_auth\n\
\t\t\t\t\tauth_ok\n\
\t\t\t\t\tfail\n\
\t\t\t\t\tnetwork_error\n\
\t\t\t\t\tunkown_error\n\
\t\t\t\t\tunkown_usr\n\
\t\t\t\t\tgcl_getting\n\
\t\t\t\t\tgcl_ok\n\
\t\t\t\t\tgcl_fail\n\
\t\t\t\t\tgp_getting\n\
\t\t\t\t\tgp_ok\n\
\t\t\t\t\tgp_fail\n\
\t\t\t\t\tok\n\
\t\t\t\t\ttimeout\n\
\t\t\t\t\turi_error\n\
\t\t\t\t\tserver_error\n\
\t\t\t\t\tserver_refuse\n\
\t\t\t\targ : object, The callback function argument.\n\
\targs : object, The callback function argument.\n\
\n\
Returns:\n\
\t0 : fail immediately.\n\
\totherwise : you can get the result from login callback function."

#define HELP_RELOGIN	"relogin(None)\n\
\n\
Relogin fetion when your fetion have break from the server.\n\
\n\
Returns:\n\
\t0 : fail immediately.\n\
\totherwise : you can get the result from login callback function."

#define HELP_LOGOUT	"logout(None)\n\
\n\
Loginout fetion.\n\
\n\
Returns: None"

#define HELP_SET_SYSTEM_MSG_CB	"set_system_msg_cb(callback_fun, args)\n\
\n\
Set the system message callback function.\n\
\n\
Parameters:\n\
\tcallback_func : function, The callback function.\n\
\t\tdef system_msg_cb(msg, wp, lp, arg):\n\
\t\t\tParameters:\n\
\t\t\t\tmsg : string, system message.\n\
\t\t\t\t\tnew_message : lp is the message sender id.\n\
\t\t\t\t\tnew_qun_message : lp is the message sender id.\n\
\t\t\t\t\tsys_message : lp is the message sender id.\n\
\t\t\t\t\tundge_message : lp is the message sender id.\n\
\t\t\t\t\tsms_ok\n\
\t\t\t\t\tsms_fail\n\
\t\t\t\t\tsms_timeout\n\
\t\t\t\t\tsms_unkown_error\n\
\t\t\t\t\tsms_fail_limit\n\
\t\t\t\t\tdia_bg_trying\n\
\t\t\t\t\tdia_bg_ok\n\
\t\t\t\t\tdia_bg_fail\n\
\t\t\t\t\tdia_send_ok\n\
\t\t\t\t\tdia_send_fail\n\
\t\t\t\t\tdia_send_timeout\n\
\t\t\t\t\tdia_unkown_error\n\
\t\t\t\t\tstatus_unset\n\
\t\t\t\t\tstatus_online\n\
\t\t\t\t\tstatus_busy\n\
\t\t\t\t\tstatus_offline\n\
\t\t\t\t\tstatus_away\n\
\t\t\t\t\tstatus_meeting\n\
\t\t\t\t\tstatus_phone\n\
\t\t\t\t\tstatus_dinner\n\
\t\t\t\t\tstatus_extended_away\n\
\t\t\t\t\tstatus_num_primitives\n\
\t\t\t\t\tstatus_waiting_auth\n\
\t\t\t\t\tstatus_refuse\n\
\t\t\t\t\tstatus_black\n\
\t\t\t\t\tstatus_mobile\n\
\t\t\t\t\tstatus_smsextened\n\
\t\t\t\t\taccount_updata_ok\n\
\t\t\t\t\tadd_group_ok\n\
\t\t\t\t\tadd_group_fail\n\
\t\t\t\t\tadd_group_timeout\n\
\t\t\t\t\tdel_group_ok\n\
\t\t\t\t\tdel_group_fail\n\
\t\t\t\t\tdel_group_timeout\n\
\t\t\t\t\trename_group_ok\n\
\t\t\t\t\trename_group_fail\n\
\t\t\t\t\trename_group_timeout\n\
\t\t\t\t\tset_buddy_info_ok\n\
\t\t\t\t\tset_buddy_info_fail\n\
\t\t\t\t\test_buddy_info_timeout\n\
\t\t\t\t\taddaccount_app\n\
\t\t\t\t\tadd_buddy_ok\n\
\t\t\t\t\tsys_err_network\n\
\t\t\t\t\tsys_deregistered\n\
\t\t\t\t\tset_state_ok\n\
\t\t\t\t\tset_state_fail\n\
\t\t\t\t\tset_state_timeout\n\
\t\t\t\t\tset_impresa_ok\n\
\t\t\t\t\tset_impresa_fail\n\
\t\t\t\t\tset_nickname_ok\n\
\t\t\t\t\tset_nickname_fail\n\
\t\t\t\t\tset_refuse_sms_day_ok\n\
\t\t\t\t\tset_refuse_sms_day_fail\n\
\t\t\t\t\tadd_blacklist_ok\n\
\t\t\t\t\tadd_blacklist_fail\n\
\t\t\t\t\tadd_blacklist_timeout\n\
\t\t\t\t\tremove_blacklist_ok\n\
\t\t\t\t\tremove_blacklist_fail\n\
\t\t\t\t\tremove_blacklist_timeout\n\
\t\t\t\t\tdel_buddy_ok\n\
\t\t\t\t\tdel_buddy_fail\n\
\t\t\t\t\tdel_buddy_timeout\n\
\t\t\t\t\tmove_group_ok\n\
\t\t\t\t\tmove_group_fail\n\
\t\t\t\t\treceive_file\n\
\t\t\t\t\tcurrent_version\n\
\t\t\t\t\tget_qunlist_ok\n\
\t\t\t\t\tget_qunlist_fail\n\
\t\t\t\t\tqun_gp_ok\n\
\t\t\t\t\tqun_send_ok\n\
\t\t\t\t\tqun_send_timeout\n\
\t\t\t\t\tqun_send_fail\n\
\t\t\t\t\tqun_sms_ok\n\
\t\t\t\t\tqun_sms_timeout\n\
\t\t\t\t\tqun_sms_fail\n\
\t\t\t\t\tqun_sms_fail_limit\n\
\t\t\t\twp : number, wParam.\n\
\t\t\t\tlp : number, lParam.\n\
\t\t\t\targs : object, system callback funtion argument.\n\
\targs : object, The callback function argument.\n\
\n\
Returns: None"

#define HELP_GET_MSG	"get_msg(uid)\n\
\n\
Get the uid's message.\n\
\n\
Parameters:\n\
\tuid : number, The message's sender.\n\
\n\
Returns:\n\
\tNone : The uid no send message.\n\
\tDict : The message.\n\
\t\tuid : number\n\
\t\tmessage : string\n\
\tmsgformat : string\n\
\text_id : number"

#define HELP_SEND_SMS	"send_sms(who, message)\n\
\n\
Send sms.\n\
\n\
Parameters:\n\
\twho : number, The user uid which you want to send.\n\
\tmessage : string, The content which you want to send.\n\
\n\
Returns:\n\
\t0 : send sms fail immediately.\n\
\totherwise : you can get the result from the system message callback function."

#define HELP_SEND_SMS_TO_SELF	"send_sms_to_self(message)\n\
\n\
Send sms to self.\n\
\n\
Parameters:\n\
\tmessage : string, The content which you want to send.\n\
\n\
Returns:\n\
\t0 : send sms fail immediately.\n\
\totherwise : you can get the result from the system message callback function."

#define HELP_SEND_SMS_BY_MOBILE	"send_sms_by_mobile(mobile, message)\n\
\n\
Send sms by mobile number.\n\
\n\
Parameters:\n\
\tmobile : string, The mobile number which you want to send.\n\
\tmessage : string, The content which you want to send.\n\
\n\
Returns:\n\
\t0 : send sms fail immediately.\n\
\totherwise : you can get the result from the system callback function."

#define HELP_SET_LONG_SMS	"set_long_sms(bl)\n\
\n\
Set the send sms mode, it maybe longsms or sms normally.\n\
\n\
Parameters:\n\
\tbl : bool, the True is send longsms mode, False set normally mode.\n\
\n\
Returns: None"

#define HELP_BEGIN_DIALOG	"begin_dialog(who)\n\
\n\
Begin the dialog function.\n\
\n\
Parameters:\n\
\twho : number, The somebody who you want to have a dialog.\n\
\n\
Returns:\n\
\tnon zero : successfully.\n\
\totherwise : fail."

#define HELP_DIALOG_SEND	"dialog_send(who, message)\n\
\n\
Send a message to somebody in a dialog.\n\
\n\
Parameters:\n\
\twho : number, The somebody who you want to send.\n\
\tmessage : string, The content which you want to send.\n\
\n\
Returns:\n\
\tnon zero : successfully.\n\
\totherwise : fail."

#define HELP_END_DIALOG	"end_dialog(who)\n\
\n\
End a dialog with somebody.\n\
\n\
Parameters:\n\
\twho : number, The somebody who you want to end a dialog.\n\
\n\
Returns: None"

#define HELP_GET_USER_UID	"get_user_uid(None)\n\
\n\
Get a current user id uid.\n\
\n\
Returns:\n\
\tNone : fail.\n\
\tString : user id"

#define HELP_GET_USER_PASSWORD	"get_user_password(None)\n\
\n\
Get a current user is password.\n\
\n\
Returns:\n\
\tNone : fail.\n\
\tString : user password"

#define HELP_GET_USER_SHOW_NAME	"get_user_show_name(None)\n\
\n\
Get a current user is name.\n\
\n\
Returns:\n\
\tNone : fail.\n\
\tString : user show name."

#define HELP_GET_USER_URI	"get_user_uri(None)\n\
\n\
Get a current user is uri.\n\
\n\
Returns:\n\
\tNone : fail.\n\
\tString : user uri."

#define HELP_GET_USER_MOBILE	"get_user_mobile(None)\n\
\n\
Get a current user is mobile number.\n\
\n\
Returns:\n\
\tNone : fail.\n\
\tString : user mobile number."

#define HELP_GET_USER_SCORE	"get_user_score(None)\n\
\n\
Get the user is score.\n\
\n\
Returns: the value of score."

#define HELP_SET_USER_STATE	"set_user_state(state, desc)\n\
\n\
Set the user state.\n\
\n\
Parameters:\n\
\tstate : string, user status.\n\
\t\tunset\n\
\t\tonline\n\
\t\tbusy\n\
\t\taway\n\
\t\tdinner\n\
\t\toffline\n\
\t\tmeeting\n\
\t\tphone\n\
\t\textended_away\n\
\t\tnum_primitives\n\
\t\twaiting_auth\n\
\t\trefuse\n\
\t\tblack\n\
\t\tmobile\n\
\n\
\tdesc : string, if you set the state is by your self define, set the connect of desc.\n\
\n\
Returns:\n\
\tnon zero : successfully.\n\
\totherwise : fail."

#define HELP_GET_USER_STATE	"get_user_state(None)\n\
\n\
Get the user state.\n\
\n\
Returns: the current user state."

#define HELP_SET_USER_IMPRESA	"set_user_impresa(impresa)\n\
\n\
Set the user impresa.\n\
\n\
Parameters:\n\
\timpresa : string, The impresa which you want to set.\n\
\n\
Returns:\n\
\tnon zero : successfully.\n\
\totherwise : fail."

#define HELP_SET_USER_NICKNAME	"set_user_nickname(nickname)\n\
\n\
Set the user nickname.\n\
\n\
Parameters:\n\
\tnickname : string, The nickname which you want ot set.\n\
\n\
Returns:\n\
\tnon zero : successfully.\n\
\totherwise : fail."

#define HELP_GET_USER_REFUSE_SMS_DAY	"get_user_refuse_sms_day(None)\n\
\n\
Get the user how long day to receive the sms message.\n\
\n\
Returns: the day."

#define HELP_SET_USER_REFUSE_SMS_DAY	"set_user_refuse_sms_day(days)\n\
\n\
Set the user how long to receive the sms message.\n\
\n\
Parameters:\n\
\tdays : number, The day which you want to set, if day = 0, show will receive sms, or it is the refuse sms days.\n\
\n\
Returns:\n\
\tnon zero : successfully.\n\
\totherwise : fail."

#define HELP_GET_EXPIRE_TIME	"get_expires_time(None)\n\
\n\
Get the expires time of the fetion.\n\
\n\
Returns: the expirestime, if expires time = 0, you should quit fetion."

#define HELP_GET_PERSONAL_INFO	"get_personal_info(None)\n\
\n\
Get a current user id personal information.\n\
\n\
Returns: Dict, the Fetion Personal information.\n\
\tnickname : string\n\
\timpresa : string\n\
\tgender : number\n\
\tnation : string\n\
\tprovince : string\n\
\tcity : number\n\
\tportrait_crc : number\n\
\tmobile_no : string\n\
\tname : string\n\
\tbirth_date : string\n\
\tlunar_animal : number\n\
\thoroscope : number\n\
\tprofile : string\n\
\tblood_type : number\n\
\toccupation : string\n\
\thobby : string\n\
\tpersonal_email : string\n\
\twork_email : string\n\
\tother_email : string\n\
\tprimary_email : number\n\
\tjob_title : string\n\
\thome_phone : string\n\
\twork_phone : string\n\
\tother_phone: string\n\
\tcompany : string\n\
\tcompany_website : string\n\
\tmatch_enabled : number\n\
\trefuse_sms_day : number"

#define HELP_GET_GROUP	"get_group(None)\n\
\n\
Get the fetion's group information.\n\
\n\
Returns:\n\
\tNone : fail.\n\
\tList : group list.\n\
\t\tid : number\n\
\t\tnmae : string"

#define HELP_GET_ACCOUNT	"get_account(None)\n\
\n\
Get the fetion's all accounts information.\n\
\n\
Returns:\n\
\tNone : fail.\n\
\tList : account list\n\
\t\tid : number\n\
\t\turi : string\n\
\t\tlocal_name : string\n\
\t\tbuddy_lists : string\n\
\t\tonline_status : string\n\
\t\tpersonal : Fetion Personal (See pyfetion.data_get_PersonalInfo)"

#define HELP_GET_BLACKLIST	"get_blacklist(None)\n\
\n\
Get the fetion's all black's accounts information.\n\
\n\
Returns:\n\
\tNone : fail.\n\
\tList : black list\n\
\tuid : number\n\
\turi : string\n\
\tlocal_name : string"

#define HELP_GET_QUN	"get_qun(None)\n\
\n\
Get the fetion's qun information.\n\
\n\
Returns:\n\
\tNone : fail.\n\
\tList : qun list\n\
\t\tid : number\n\
\t\turi : string\n\
\t\tidentity : number\n\
\t\tquninfo : Fetion QunInfo Dict\n\
\t\t\turi : string\n\
\t\t\tgroup_attributes_version : number\n\
\t\t\tname : string\n\
\t\t\tcategory : number\n\
\t\t\tintroduce : string\n\
\t\t\tbulletin : string\n\
\t\t\tportrait_crc : string\n\
\t\t\tsearchable : string\n\
\t\t\tcurrent_member_count : number\n\
\t\t\tlimit_member_count : number\n\
\t\t\tgroup_activity : string\n\
\t\t\tQunMember : Fetion QunMember list\n\
\t\t\t\turi : string\n\
\t\t\t\tid : number\n\
\t\t\t\tnikcname : string\n\
\t\t\t\tiicnickname : string\n\
\t\t\t\tidentity : number\n\
\t\t\t\tstate : number\n\
\t\t\t\tclient_type : string"

#define HELP_GET_ACCOUNT_BY_ID	"get_account_by_id(id)\n\
\n\
Get a account which uid's the gvied id.\n\
\n\
Parameters:\n\
\t id : number, The user id which you want to get.\n\
\n\
Returns:\n\
\tNone : fail.\n\
\tDict : Fetion Account\n\
\t\tid : number\n\
\t\turi : string\n\
\t\tlocal_name : string\n\
\t\tbuddy_lists : string\n\
\t\tonline_status : string\n\
\t\tpersonal : Fetion Personal (See pyfetion.data_get_PersonalInfo)"

#define HELP_GET_QUN_BY_ID	"get_qun_by_id(id)\n\
\n\
Get qun which uid's gived id.\n\
\n\
Parameters:\n\
\tid : number, The qun id which you want to get.\n\
\n\
Returns:\n\
\tNone : fail.\n\
\tDict : Fetion Qun (See pyfetion.get_qun)"

#define HELP_IS_PC_USER_BY_ID	"is_pc_user_by_id(id)\n\
\n\
Judge this id is PC user or not.\n\
\n\
Parameters:\n\
\tid : number, The user id.\n\
\n\
Returns:\n\
\tTrue  : The user id is PC user.\n\
\tFalse : The user id isn't PC user."

#define HELP_IS_PC_USER_BY_ACCOUNT	"is_pc_user_by_account(account)\n\
\n\
Judge this account is PC user or not.\n\
\n\
Parameters:\n\
\taccount : dict, The fetion account. (See pyfetion.get_account_by_id)\n\
\n\
Returns:\n\
\tTrue  : The user id is PC user.\n\
\tFalse : The user id isn't PC user."

#define HELP_IS_AUTHED_BY_ID	"is_authed_by_id(id)\n\
\n\
Judge this id is auth to you add it.\n\
\n\
Parameters:\n\
\tid : number, The user id.\n\
\n\
Returns:\n\
\tTrue  : The user id is authed.\n\
\tFalse : The user id isn't authed."

#define HELP_IS_AUTHED_BY_ACCOUNT	"is_authed_by_account(account)\n\
\n\
Judge this account is auth to you add it.\n\
\n\
Parameters:\n\
\taccount : dict, The fetion account. (See pyfetion.get_account_by_id)\n\
\n\
Returns:\n\
\tTrue  : The user id is authed.\n\
\tFalse : The user id isn't authed."

#define HELP_IS_IN_BLACKLIST_BY_ID	"is_in_blacklist_by_id(id)\n\
\n\
Judge this account is in the blacklist.\n\
\n\
Parameters:\n\
\tid : number, The user id.\n\
\n\
Returns:\n\
\tTrue  : The user is in your blacklist.\n\
\tFalse : The user isn't in your blacklist."

#define HELP_IS_IN_BLACKLIST_BY_ACCOUNT	"is_in_blacklist_by_account(account)\n\
\n\
Judge this account is in the blacklist.\n\
\n\
Parameters:\n\
\taccount : dict, The fetion account. (See pyfetion.get_account_by_id)\n\
\n\
Returns:\n\
\tTrue  : The user is in your blacklist.\n\
\tFalse : The user isn't in your blacklist."

#define HELP_MOVE_GROUP_BUDDY_BY_ID	"move_group_buddy_by_id(uid, group_id)\n\
\n\
Modify the group which account was belonged.\n\
\n\
Parameters:\n\
\tuid : number, The user id.\n\
\tgroup_id : number, The group id\n\
\n\
Returns:\n\
\t0 : fail immediately.\n\
\totherwise : you can get the result from the system callback function."

#define HELP_MOVE_GROUP_BUDDY	"move_group_buddy(account, group_id)\n\
\n\
Modify the group which account was belonged.\n\
\n\
Parameters:\n\
\taccount : dict, The fetion account. (See pyfetion.get_account_by_id)\n\
\tgroup_id : number, The group id.\n\
\n\
Returns:\n\
\t0 : fail immediately.\n\
\totherwise : you can get the result from the system callback function."

#define HELP_IS_ONLINE_BY_ID	"is_online_by_id(id)\n\
\n\
Judge this id is online or not.\n\
\n\
Parameters:\n\
\tid : number, The user id.\n\
\n\
Returns:\n\
\tTrue  : The user is online.\n\
\tFalse : The user isn't online."

#define HELP_IS_ONLINE_BY_ACCOUNT	"is_online_by_account(account)\n\
\n\
Judge this account is online or not.\n\
\n\
Parameters:\n\
\taccount : dict, The fetion account. (See pyfetion.get_account_by_id)\n\
\n\
Returns:\n\
\tTrue  : The user is online.\n\
\tFalse : The user isn't online."

#define HELP_GET_ONLINE_STATUS_BY_ID	"get_online_status_by_id(id)\n\
\n\
Return fetion uid's online status.\n\
\n\
Parameters:\n\
\tid : number, The user id.\n\
\n\
Returns: user status"

#define HELP_GET_ONLINE_STATUS_BY_ACCOUNT	"get_online_status_by_account(account)\n\
\n\
Return fetion account's online status.\n\
\n\
Parameters:\n\
\taccount : dict, The fetion account. (See pyfetion.get_account_by_id)\n\
\n\
Returns: user status"

#define HELP_GET_REFUSE_SMS_DAY	"get_refuse_sms_day(account)\n\
\n\
Return fetion account's refuse_sms_day.\n\
\n\
Parameters:\n\
\taccount : dict, The fetion account. (See pyfetion.get_account_by_id)\n\
\n\
Returns: the numbers of refuse sms day."

#define HELP_UPDATE_ACCOUNT_INFO_BY_ID	"update_account_info_by_id(id)\n\
\n\
Update the account info which uid's the gived id.\n\
\n\
Parameters:\n\
\tid : number, The user id.\n\
\n\
Returns: None"

#define HELP_UPDATE_ACCOUNT_INFO_ALL	"update_account_info_all(None)\n\
\n\
Update all the account info.\n\
\n\
Returns: None"

#define HELP_GET_ACCOUNT_SHOW_NAME	"get_account_show_name(account, needImpresa)\n\
\n\
Get the show name of the account.\n\
\n\
Parameters:\n\
\taccount : dict, The fetion account. (See pyfetion.get_account_by_id)\n\
\tneedImpresa : bool, Is need the impresa in show name\n\
\n\
Returns: The show name of account."

#define HELP_GET_QUN_SHOW_NAME	"get_qun_show_name(qun)\n\
\n\
Get the show name of the qun.\n\
\n\
Parameters:\n\
\tqun : dict, The fetion qun. (See pyfetion.get_qun)\n\
\n\
Returns: The show name of the qun."

#define HELP_GET_ACCOUNT_GROUP_ID	"get_account_group_id(account)\n\
\n\
Get the group id of the account.\n\
\n\
Parameters:\n\
\taccount : dict, The fetion account. (See pyfetion.get_account_by_id)\n\
\n\
Returns:\n\
\t-1 : fail.\n\
\totherwise : the account's group id."

#define HELP_RENAME_BUDDYLIST	"rename_buddylist(id, name)\n\
\n\
Rename the group.\n\
\n\
Parameters:\n\
\tid : number, The group which you want to rename.\n\
\tname : string, The name which you want to set.\n\
\n\
Returns:\n\
\t0 : fail immediately.\n\
\totherwise : you can get the result from the system calback function."

#define HELP_ADD_BUDDYLIST	"add_buddylist(name)\n\
\n\
Add a buddylist.\n\
\n\
Parameters:\n\
\tname : string, The group name.\n\
\n\
Returns:\n\
\t0 : fail immediately.\n\
\totherwise : you can get the result from the system calback function."

#define HELP_ADD_BUDDY_BY_UID	"add_buddy_by_uid(uid, local_name, groupid, desc)\n\
\n\
Add a account by fetion id.\n\
\n\
Parameters:\n\
\tuid : string, The uid of account which you want to add.\n\
\tlocal_name : string, The name of account which you want to add.\n\
\tgroupid : number, The group id of account which you want to add.\n\
\tdesc : string, the name of you send to the user see.\n\
\n\
Returns:\n\
\t0 : fail immediately.\n\
\totherwise : you can get the result from the system calback function."

#define HELP_ADD_BUDDY_BY_MOBILE	"add_buddy_by_mobile(mobile, local_name, groupid, desc)\n\
\n\
Add a account by mobile number.\n\
\n\
Parameters:\n\
\tmobile : string, The mobile number of account which you want to add.\n\
\tlocal_name : string, The name of account which you want to add.\n\
\tgroupid : number, The group id of account which you want to add.\n\
\tdesc : string, the name of you send to the user see.\n\
\n\
Returns:\n\
\t0 : fail immediately.\n\
\totherwise : you can get the result from the system calback function."

#define HELP_HANDLE_CONTACT_REQUEST	"handle_contact_request(uri, isPassed, group, local_name)\n\
\n\
Handle a request of addaccount.\n\
\n\
Parameters:\n\
\turi : string, The uri of account which you to add with you.\n\
\tisPassed : number\n\
\tgroup : number, The group id.\n\
\tlocal_name : string, The name of you send to the user seee.\n\
\n\
Returns:\n\
\t0 : fail immediately.\n\
\totherwise : you can get the result from the system calback function."

#define HELP_DELETE_BUDDYLIST	"delete_buddylist(id)\n\
\n\
Delete a group.\n\
\n\
Parameters:\n\
\tid : number, The group id which you want to delete.\n\
\n\
Returns:\n\
\t0 : fail immediately.\n\
\totherwise : you can get the result from the system calback function."

#define HELP_SET_BUDDYINFO	"set_buddyinfo(uid, localname)\n\
\n\
Set the local name of the account.\n\
\n\
Parameters:\n\
\tuid : number, The account which you want to set.\n\
\tlocalname : string, The local name which you want to set.\n\
\n\
Returns:\n\
\t0 : fail immediately.\n\
\totherwise : you can get the result from the system calback function."

#define HELP_DELETE_BUDDY_BY_ID	"delete_buddy_by_id(uid)\n\
\n\
Delete the account.\n\
\n\
Parameters:\n\
\tuid : number, The account which you want to delete.\n\
\n\
Returns:\n\
\t0 : fail immediately.\n\
\totherwise : you can get the result from the system calback function."

#define HELP_DELETE_BUDDY_BY_ACCOUNT	"delete_buddy_by_account(account)\n\
\n\
Delete the account.\n\
\n\
Parameters:\n\
\taccount : dict, The fetion account. (See pyfetion.get_account_by_id)\n\
\n\
Returns:\n\
\t0 : fail immediately.\n\
\totherwise : you can get the result from the system calback function."

#define HELP_ADDTO_BLACKLIST_BY_ID	"addto_blacklist_by_id(uid)\n\
\n\
Add the user to blacklist.\n\
\n\
Parameters:\n\
\tuid : number, The id which you want to add to blacklist.\n\
\n\
Returns:\n\
\t0 : fail immediately.\n\
\totherwise : you can get the result from the system calback function."

#define HELP_ADDTO_BLACKLIST_BY_ACCOUNT	"addto_blacklist_by_account(account)\n\
\n\
Add the user to blacklist.\n\
\n\
Parameters:\n\
\taccount : dict, The account which you want to add to blacklist. (See pyfetion.get_account_by_id)\n\
\n\
Returns:\n\
\t0 : fail immediately.\n\
\totherwise : you can get the result from the system calback function."

#define HELP_ADDTO_BLACKLIST_BY_URI	"addto_blacklist_by_uri(uri)\n\
\n\
Add the uri user to blacklist.\n\
\n\
Parameters:\n\
\turi : string, The account's uri which you want to add to blacklist.\n\
\n\
Returns:\n\
\t0 : fail immediately.\n\
\totherwise : you can get the result from the system calback function."

#define HELP_REMOVEFROM_BLACKLIST_BY_ID	"removefrom_blacklist_by_id(uid)\n\
\n\
Remove the user from blacklist.\n\
\n\
Parameters:\n\
\tuid : number, The id which you want to remove from blacklist.\n\
\n\
Returns:\n\
\t0 : fail immediately.\n\
\totherwise : you can get the result from the system calback function."

#define HELP_REMOVEFROM_BLACKLIST_BY_ACCOUNT	"removefrom_blacklist_by_account(account)\n\
\n\
Remove the user from blacklist.\n\
\n\
Parameters:\n\
\taccount : dict, The account which you want to remove from blacklist. (See pyfetion.get_account_by_id)\n\
\n\
Returns:\n\
\t0 : fail immediately.\n\
\totherwise : you can get the result from the system calback function."

#define HELP_REMOVEFROM_BLACKLIST_BY_URI	"removefrom_blacklist_by_uri(uri)\n\
\n\
Remove the uri user from blacklist.\n\
\n\
Parameters:\n\
\turi : string, The account's uri which you want to remove from blacklist.\n\
\n\
Returns:\n\
\t0 : fail immediately.\n\
\totherwise : you can get the result from the system calback function."

#define HELP_SEND_NUDGE	"send_nudge(who)\n\
\n\
Send a nudge.\n\
\n\
Parameters:\n\
\twho : number, who which you want to send.\n\
\n\
Returns:\n\
\tTrue  : success.\n\
\tFalse : fail."

#define HELP_SET_SERVE_ADDRESS	"set_serve_address(serve_address)\n\
\n\
Set the fetion proxy ip and port.\n\
\n\
Parameters:\n\
\tserve_address : string, the proxy address format is ip:port (192.168.0.1:8080)\n\
\n\
Returns:\n\
\tTrue  : success.\n\
\tFalse : fail."

#define HELP_SET_UNKNOW_SERVE_ADDRESS	"set_unkonw_serve_address(None)\n\
\n\
Let the fetion get the serve_address ip and port by it self.\n\
\n\
Returns: None"

#define HELP_GET_SERVE_ADDRESS	"get_serve_address(None)\n\
\n\
Get the current fetion id's proxy server ip.\n\
\n\
Returns: the server address, the format is ip:port (192.168.0.1:8080)."

#define HELP_SET_PROXY	"set_proxy(proxy)\n\
\n\
Set the proxy when you use proxy to connect the network.\n\
\n\
Parameters:\n\
\tproxy : dict, The proxy information.\n\
\t\thost : string\n\
\t\tport : string\n\
\t\tname : string\n\
\t\tpwd : string\n\
\t\ttype : string\n\
\t\t\tdirect\n\
\t\t\thttp\n\
\t\t\tsocks4\n\
\t\t\tsocks5\n\
\n\
Returns:\n\
\tTrue  : success\n\
\tFalse : fail."

#define HELP_GET_PROXY	"get_proxy(None)\n\
\n\
Get the Get the proxy information.\n\
\n\
Returns: proxy information. (See pyfetion.set_proxy)"

#define HELP_SET_PROXY_ENABLE	"set_proxy_enable(status)\n\
\n\
Set the proxy isEnabled.\n\
\n\
Parameters:\n\
\tstatus : bool, True is enable proxy, False is disable proxy.\n\
\n\
Returns: None"

#define HELP_IS_PROXY_ENABLE	"is_proxy_enable(None)\n\
\n\
Get the proxy isEnabled.\n\
\n\
Returns:\n\
\tTrue  : The proxy is enabled.\n\
\tFalse : The proxy is disabled."

#define HELP_TEST_NETWORK	"test_network(proxy)\n\
\n\
Get the fetion network is working of proxy.\n\
\n\
Parameters:\n\
\tproxy : proxy information (See pyfetion.set_proxy).\n\
\n\
Returns:\n\
\t0 : fail immediately.\n\
\totherwise : you can get the result from the system calback function."

#define HELP_SIMPLE_PASER_MSG	"simple_paser_msg(msg)\n\
\n\
Simple paser the msg filter the <Font></Font> tags.\n\
\n\
Parameters:\n\
\tmsg, string, the original msg.\n\
\n\
Returns:\n\
\tNone : fail, msg format is wrong.\n\
\totherwise : The no format message."

#define HELP_GET_ORIGINAL_ID	"get_original_id(id)\n\
\n\
Get the original id of the user.\n\
\n\
Parameters:\n\
\tid : number, the user id.\n\
\n\
Returns:\n\
\tIf the user is PC user, it will return the fetion id.\n\
\tIf the user is Mobile user, it will return the user's mobile."

#endif /* __METHODS_HTLP_H__ */

