/* pyfetion.h
 * Heihaier <admin@heihaier.org>
 * http://www.heihaier.org
 */

#ifndef __PYFETION_H__
#define __PYFETION_H__

#include "methods_help.h"
#include <Python.h>
#include <libfetion.h>

/* Methods */
/* Fetion Init */
PyObject * pyf_init(PyObject * self, PyObject * args);
PyObject * pyf_terminate(PyObject * self, PyObject * args);
PyObject * pyf_close_network(PyObject * self, PyObject * args);
/* Login and Out */
PyObject * pyf_s_login(PyObject * self, PyObject * args);
PyObject * pyf_set_login_status(PyObject * self, PyObject * args);
PyObject * pyf_login(PyObject * self, PyObject * args);
PyObject * pyf_loginout(PyObject * self, PyObject * args);
/* Set System Message Callback Functions */
PyObject * pyf_set_system_msg_cb(PyObject * self, PyObject * args);
/* Receive message functions */
PyObject * pyf_get_msg(PyObject * self, PyObject * args);
/* Send SMS Functions */
PyObject * pyf_s_send_sms(PyObject * self, PyObject * args);
PyObject * pyf_s_send_sms_by_mobile_no(PyObject * self, PyObject * args);
PyObject * pyf_s_send_sms_to_self(PyObject * self, PyObject * args);
PyObject * pyf_send_sms(PyObject * self, PyObject * args);
PyObject * pyf_send_sms_to_self(PyObject * self, PyObject * args);
PyObject * pyf_send_sms_by_mobile_no(PyObject * self, PyObject * args);
PyObject * pyf_set_longsms(PyObject * self, PyObject * args);
/* Dialog message */
PyObject * pyf_s_begin_dialog(PyObject * self, PyObject * args);
PyObject * pyf_s_dialog_send(PyObject * self, PyObject * args);
PyObject * pyf_s_end_dialog(PyObject * self, PyObject * args);
PyObject * pyf_begin_dialog(PyObject * self, PyObject * args);
PyObject * pyf_dialog_send(PyObject * self, PyObject * args);
PyObject * pyf_end_dialog(PyObject * self, PyObject * args);
/* Get or Set User Info */
PyObject * pyf_get_usr_uid(PyObject * self, PyObject * args);
PyObject * pyf_get_usr_passwd(PyObject * self, PyObject * args);
PyObject * pyf_get_usr_show_name(PyObject * self, PyObject * args);
PyObject * pyf_get_usr_uri(PyObject * self, PyObject * args);
PyObject * pyf_get_usr_mobilenum(PyObject * self, PyObject * args);
PyObject * pyf_get_usr_score(PyObject * self, PyObject * args);
PyObject * pyf_set_user_state(PyObject * self, PyObject * args);
PyObject * pyf_get_user_state(PyObject * self, PyObject * args);
PyObject * pyf_set_user_impresa(PyObject * self, PyObject * args);
PyObject * pyf_set_user_nickname(PyObject * self, PyObject * args);
PyObject * pyf_get_user_refuse_sms_day(PyObject * self, PyObject * args);
PyObject * pyf_set_user_refuse_sms_day(PyObject * self, PyObject * args);
PyObject * pyf_get_expirestime(PyObject * self, PyObject * args);
PyObject * pyf_data_get_PersonalInfo(PyObject * self, PyObject * args);
/* Get contacts info */
PyObject * pyf_get_group(PyObject * self, PyObject * args);
PyObject * pyf_get_account(PyObject * self, PyObject * args);
PyObject * pyf_get_blacklist(PyObject * self, PyObject * args);
PyObject * pyf_get_qun(PyObject * self, PyObject * args);
PyObject * pyf_get_account_by_id(PyObject * self, PyObject * args);
PyObject * pyf_get_qun_by_id(PyObject * self, PyObject * args);
PyObject * pyf_is_pc_user_by_id(PyObject * self, PyObject * args);
PyObject * pyf_is_qun_by_id(PyObject * self, PyObject * args);
PyObject * pyf_is_pc_user_by_account(PyObject * self, PyObject * args);
PyObject * pyf_is_authed_by_id(PyObject * self, PyObject * args);
PyObject * pyf_is_authed_by_account(PyObject * self, PyObject * args);
PyObject * pyf_is_InBlacklist_by_id(PyObject * self, PyObject * args);
PyObject * pyf_is_InBlacklist_by_account(PyObject * self, PyObject * args);
PyObject * pyf_move_group_buddy_by_id(PyObject * self, PyObject * args);
PyObject * pyf_move_group_buddy(PyObject * self, PyObject * args);
PyObject * pyf_is_on_line_by_id(PyObject * self, PyObject * args);
PyObject * pyf_is_on_line_by_account(PyObject * self, PyObject * args);
PyObject * pyf_get_online_status_by_id(PyObject * self, PyObject * args);
PyObject * pyf_get_online_status_by_account(PyObject * self, PyObject * args);
PyObject * pyf_get_refuse_sms_day(PyObject * self, PyObject * args);
PyObject * pyf_updata_account_info_by_id(PyObject * self, PyObject * args);
PyObject * pyf_updata_account_info_all(PyObject * self, PyObject * args);
PyObject * pyf_get_account_show_name(PyObject * self, PyObject * args);
PyObject * pyf_get_qun_show_name(PyObject * self, PyObject * args);
PyObject * pyf_get_account_group_id(PyObject * self, PyObject * args);
/* Group Opt Functions */
PyObject * pyf_s_rename_buddylist(PyObject * self, PyObject * args);
PyObject * pyf_s_delete_buddylist(PyObject * self, PyObject * args);
PyObject * pyf_rename_buddylist(PyObject * self, PyObject * args);
PyObject * pyf_add_buddylist(PyObject * self, PyObject * args);
PyObject * pyf_add_buddy_by_uid(PyObject * self, PyObject * args);
PyObject * pyf_add_buddy_by_mobile(PyObject * self, PyObject * args);
PyObject * pyf_handleContactRequest(PyObject * self, PyObject * args);
PyObject * pyf_delete_buddylist(PyObject * self, PyObject * args);
/* Buddy Opt Functions */
PyObject * pyf_s_set_buddyinfo(PyObject * self, PyObject * args);
PyObject * pyf_set_buddyinfo(PyObject * self, PyObject * args);
PyObject * pyf_delete_buddy_by_id(PyObject * self, PyObject * args);
PyObject * pyf_delete_buddy_by_account(PyObject * self, PyObject * args);
PyObject * pyf_addto_blacklist_by_id(PyObject * self, PyObject * args);
PyObject * pyf_addto_blacklist_by_account(PyObject * self, PyObject * args);
PyObject * pyf_addto_blacklist_by_uri(PyObject * self, PyObject * args);
PyObject * pyf_removefrom_blacklist_by_id(PyObject * self, PyObject * args);
PyObject * pyf_removefrom_blacklist_by_account(PyObject * self, PyObject * args);
PyObject * pyf_removefrom_blacklist_by_uri(PyObject * self, PyObject * args);
/* Extend Functions */
PyObject * pyf_send_nudge(PyObject * self, PyObject * args);
PyObject * pyf_set_serve_address(PyObject * self, PyObject * args);
PyObject * pyf_set_unknow_serve_address(PyObject * self, PyObject * args);
PyObject * pyf_get_serve_address(PyObject * self, PyObject * args);
PyObject * pyf_set_proxy(PyObject * self, PyObject * args);
PyObject * pyf_get_proxy(PyObject * self, PyObject * args);
PyObject * pyf_test_network(PyObject * self, PyObject * args);
/* Misc Functions */
PyObject * pyf_simple_paser_msg(PyObject * self, PyObject * args);
//PyObject * pyf_(PyObject * self, PyObject * args);

/* Init function */
extern "C" void initpyfetion(void);

/* Fetion_Account */
Fetion_Account * pydict_fetion_account(PyObject * dict);
PyObject * fetion_account_pydict(const Fetion_Account * account);
/* Fetion_MSG */
PyObject * fetion_msg_pydict(const Fetion_MSG * msg);
Fetion_MSG * pydict_fetion_msg(PyObject * dict);
/* Fetion_Personal */
PyObject * fetion_personal_pydict(const Fetion_Personal * personal);
Fetion_Personal * pydict_fetion_personal(PyObject * dict);
/* Fetion_Group */
PyObject * fetion_group_pydict(const Fetion_Group * group);
Fetion_Group * pydict_fetion_group(PyObject * dict);
/* Fetion_Black */
PyObject * fetion_black_pydict(const Fetion_Black * black);
Fetion_Black * pydict_fetion_black(PyObject * dict);
/* Fetion_BList */
PyObject * fetion_blist_pydict(const Fetion_BList * blist);
Fetion_BList * pydict_fetion_blist(PyObject * dict);
/* Fetion_Qun */
PyObject * fetion_qun_pydict(const Fetion_Qun * qun);
Fetion_Qun * pydict_fetion_qun(PyObject * dict);

/* Fetion_QunInfo */
PyObject * fetion_quninfo_pydict(const Fetion_QunInfo * quninfo);
Fetion_QunInfo * pydict_fetion_quninfo(PyObject * dict);

/* Fetion_QunMember */
PyObject * fetion_qunmember_pydict(const Fetion_QunMember * qunmember);
Fetion_QunMember * pydict_fetion_qunmember(PyObject * dict);

/* status */
int status_str_int(const char * status);
const char * status_int_str(int status);

/* callback functions */
void login_callback_func(int message, WPARAM wParam, LPARAM lParam, void *args);
void system_msg_callback_func(int message, WPARAM wParam, LPARAM lParam, void *args);

/* callback object */
PyObject * login_cb = NULL;
PyObject * system_msg_cb = NULL;

static PyMethodDef pyfetionMethods[] =
{
	{"init", pyf_init, METH_VARARGS, HELP_INIT},
	{"terminate",  pyf_terminate, METH_VARARGS, HELP_TERMINATE},
	{"close_network",  pyf_close_network, METH_VARARGS, HELP_CLOSE_NETWORK},
	{"s_login", pyf_s_login , METH_VARARGS, HELP_S_LOGIN},
	{"set_login_status", pyf_set_login_status , METH_VARARGS, HELP_SET_LOGIN_STATUS},
	{"login", pyf_login , METH_VARARGS, HELP_LOGIN},
	{"loginout", pyf_loginout , METH_VARARGS, HELP_LOGINOUT},
	{"set_system_msg_cb",pyf_set_system_msg_cb , METH_VARARGS, HELP_SET_SYSTEM_MSG_CB},
	{"get_msg", pyf_get_msg , METH_VARARGS, HELP_GET_MSG},
	{"s_send_sms", pyf_s_send_sms , METH_VARARGS, HELP_S_SEND_SMS},
	{"s_send_sms_by_mobile_no", pyf_s_send_sms_by_mobile_no , METH_VARARGS, HELP_S_SEND_SMS_BY_MOBILE_NO},
	{"s_send_sms_to_self", pyf_s_send_sms_to_self , METH_VARARGS, HELP_S_SEND_SMS_TO_SELF},
	{"send_sms", pyf_send_sms , METH_VARARGS, HELP_SEND_SMS},
	{"send_sms_to_self", pyf_send_sms_to_self , METH_VARARGS, HELP_SEND_SMS_TO_SELF},
	{"send_sms_by_mobile_no", pyf_send_sms_by_mobile_no , METH_VARARGS, HELP_SEND_SMS_BY_MOBILE_NO},
	{"set_longsms", pyf_set_longsms, METH_VARARGS, HELP_SET_LONGSMS},
	{"s_begin_dialog", pyf_s_begin_dialog , METH_VARARGS, HELP_S_BEGIN_DIALOG},
	{"s_dialog_send", pyf_s_dialog_send , METH_VARARGS, HELP_S_DIALOG_SEND},
	{"s_end_dialog", pyf_s_end_dialog , METH_VARARGS, HELP_S_END_DIALOG},
	{"begin_dialog", pyf_begin_dialog , METH_VARARGS, HELP_BEGIN_DIALOG},
	{"dialog_send", pyf_dialog_send , METH_VARARGS, HELP_DIALOG_SEND},
	{"end_dialog", pyf_end_dialog , METH_VARARGS, HELP_END_DIALOG},
	{"get_usr_uid", pyf_get_usr_uid , METH_VARARGS, HELP_GET_USR_UID},
	{"get_usr_passwd", pyf_get_usr_passwd, METH_VARARGS, HELP_GET_USR_PASSWD},
	{"get_usr_show_name", pyf_get_usr_show_name, METH_VARARGS, HELP_GET_USR_SHOW_NAME},
	{"get_usr_uri", pyf_get_usr_uri , METH_VARARGS, HELP_GET_USR_URI},
	{"get_usr_mobilenum", pyf_get_usr_mobilenum , METH_VARARGS, HELP_GET_USR_MOBILENUM},
	{"get_usr_score", pyf_get_usr_score, METH_VARARGS, HELP_GET_USR_SCORE},
	{"set_user_state", pyf_set_user_state , METH_VARARGS, HELP_SET_USER_STATE},
	{"get_user_state", pyf_get_user_state , METH_VARARGS, HELP_GET_USER_STATE},
	{"set_user_impresa", pyf_set_user_impresa, METH_VARARGS, HELP_SET_USER_IMPRESA},
	{"set_user_nickname", pyf_set_user_nickname, METH_VARARGS, HELP_SET_USER_NICKNAME},
	{"get_user_refuse_sms_day", pyf_get_user_refuse_sms_day, METH_VARARGS, HELP_GET_USER_REFUSE_SMS_DAY},
	{"set_user_refuse_sms_day", pyf_set_user_refuse_sms_day, METH_VARARGS, HELP_SET_USER_REFUSE_SMS_DAY},
	{"get_expirestime", pyf_get_expirestime , METH_VARARGS, HELP_GET_EXPIRETIME},
	{"data_get_PersonalInfo", pyf_data_get_PersonalInfo , METH_VARARGS, HELP_DATA_GET_PERSONALINFO},
	{"get_group", pyf_get_group , METH_VARARGS, HELP_GET_GROUP},
	{"get_account", pyf_get_account , METH_VARARGS, HELP_GET_ACCOUNT},
	{"get_blacklist", pyf_get_blacklist , METH_VARARGS, HELP_GET_BLACKLIST},
	{"get_qun", pyf_get_qun , METH_VARARGS, HELP_GET_QUN},
	{"get_account_by_id", pyf_get_account_by_id , METH_VARARGS, HELP_GET_ACCOUNT_BY_ID},
	{"get_qun_by_id", pyf_get_qun_by_id, METH_VARARGS, HELP_GET_QUN_BY_ID},
	{"is_pc_user_by_id", pyf_is_pc_user_by_id , METH_VARARGS, HELP_IS_PC_USER_BY_ID},
	{"is_pc_user_by_account", pyf_is_pc_user_by_account , METH_VARARGS, HELP_IS_PC_USER_BY_ACCOUNT},
	{"is_authed_by_id", pyf_is_authed_by_id , METH_VARARGS, HELP_IS_AUTHED_BY_ID},
	{"is_authed_by_account", pyf_is_authed_by_account , METH_VARARGS, HELP_IS_AUTHED_BY_ACCOUNT},
	{"is_InBlacklist_by_id", pyf_is_InBlacklist_by_id , METH_VARARGS, HELP_IS_INBLACKLIST_BY_ID},
	{"is_InBlacklist_by_account", pyf_is_InBlacklist_by_account , METH_VARARGS, HELP_IS_INBLACKLIST_BY_ACCOUNT},
	{"move_group_buddy_by_id", pyf_move_group_buddy_by_id, METH_VARARGS, HELP_MOVE_GROUP_BUDDY_BY_ID},
	{"move_group_buddy", pyf_move_group_buddy, METH_VARARGS, HELP_MOVE_GROUP_BUDDY},
	{"is_on_line_by_id", pyf_is_on_line_by_id , METH_VARARGS, HELP_IS_ON_LINE_BY_ID},
	{"is_on_line_by_account", pyf_is_on_line_by_account , METH_VARARGS, HELP_IS_ON_LINE_BY_ACCOUNT},
	{"get_online_status_by_id", pyf_get_online_status_by_id , METH_VARARGS, HELP_GET_ON_LINE_STATUS_BY_ID},
	{"get_online_ststus_by_account", pyf_get_online_status_by_account , METH_VARARGS, HELP_GET_ON_LINE_STATUS_BY_ACCOUNT},
	{"get_refuse_sms_day", pyf_get_refuse_sms_day, METH_VARARGS, HELP_GET_REFUSE_SMS_DAY},
	{"updata_account_info_by_id", pyf_updata_account_info_by_id , METH_VARARGS, HELP_UPDATA_ACCOUNT_INFO_BY_ID},
	{"updata_account_info_all", pyf_updata_account_info_all , METH_VARARGS, HELP_UPDATA_ACCOUNT_INFO_ALL},
	{"get_account_show_name", pyf_get_account_show_name , METH_VARARGS, HELP_GET_ACCOUNT_SHOW_NAME},
	{"get_qun_show_name", pyf_get_qun_show_name , METH_VARARGS, HELP_GET_QUN_SHOW_NAME},
	{"get_account_group_id", pyf_get_account_group_id , METH_VARARGS, HELP_GET_ACCOUNT_GROUP_ID},
	{"s_rename_buddylist", pyf_s_rename_buddylist , METH_VARARGS, HELP_S_RENAME_BUDDYLIST},
	{"s_delete_buddylist", pyf_s_delete_buddylist, METH_VARARGS, HELP_S_DELETE_BUDDYLIST},
	{"rename_buddylist", pyf_rename_buddylist, METH_VARARGS, HELP_RENAME_BUDDYLIST},
	{"add_buddylist", pyf_add_buddylist, METH_VARARGS, HELP_ADD_BUDDYLIST},
	{"add_buddy_by_uid", pyf_add_buddy_by_uid , METH_VARARGS, HELP_ADD_BUDDY_BY_UID},
	{"add_buddy_by_mobile", pyf_add_buddy_by_mobile, METH_VARARGS, HELP_ADD_BUDDY_BY_MOBILE},
	{"handleContactRequest", pyf_handleContactRequest, METH_VARARGS, HELP_HANDLECONTACTREQUEST},
	{"delete_buddylist", pyf_delete_buddylist, METH_VARARGS, HELP_DELETE_BUDDYLIST},
	{"s_set_buddyinfo", pyf_s_set_buddyinfo, METH_VARARGS, HELP_S_SET_BUDDYINFO},
	{"set_buddyinfo", pyf_set_buddyinfo, METH_VARARGS, HELP_SET_BUDDYINFO},
	{"delete_buddy_by_id", pyf_delete_buddy_by_id, METH_VARARGS, HELP_DELETE_BUDDY_BY_ID},
	{"delete_buddy_by_account", pyf_delete_buddy_by_account, METH_VARARGS, HELP_DELETE_BUDDY_BY_ACCOUNT},
	{"addto_blacklist_by_id", pyf_addto_blacklist_by_id, METH_VARARGS, HELP_ADDTO_BLACKLIST_BY_ID},
	{"addto_blacklist_by_account", pyf_addto_blacklist_by_account, METH_VARARGS, HELP_ADDTO_BLACKLIST_BY_ACCOUNT},
	{"addto_blacklist_by_uri", pyf_addto_blacklist_by_uri, METH_VARARGS, HELP_ADDTO_BLACKLIST_BY_URI},
	{"removefrom_blacklist_by_id", pyf_removefrom_blacklist_by_id, METH_VARARGS, HELP_REMOVEFROM_BLACKLIST_BY_ID},
	{"removefrom_blacklist_by_account", pyf_removefrom_blacklist_by_account, METH_VARARGS, HELP_REMOVEFROM_BLACKLIST_BY_ACCOUNT},
	{"removefrom_blacklist_by_uri", pyf_removefrom_blacklist_by_uri, METH_VARARGS, HELP_REMOVEFROM_BLACKLIST_BY_URI},
	{"send_nudge", pyf_send_nudge, METH_VARARGS, HELP_SEND_NUDGE},
	{"set_serve_address", pyf_set_serve_address, METH_VARARGS, HELP_SET_SERVE_ADDRESS},
	{"set_unknow_serve_address", pyf_set_unknow_serve_address, METH_VARARGS, HELP_SET_UNKNOW_SERVE_ADDRESS},
	{"get_serve_address", pyf_get_serve_address, METH_VARARGS, HELP_GET_SERVE_ADDRESS},
	{"set_proxy", pyf_set_proxy, METH_VARARGS, HELP_SET_PROXY},
	{"get_proxy", pyf_get_proxy, METH_VARARGS, HELP_GET_PROXY},
	{"test_network", pyf_test_network, METH_VARARGS, HELP_TEST_NETWORK},
	{"simple_paser_msg", pyf_simple_paser_msg, METH_VARARGS, HELP_SIMPLE_PASER_MSG},
	{NULL, NULL, 0, NULL}
};

#endif	/* __PYFETION_H__ */
