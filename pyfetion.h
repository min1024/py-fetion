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
PyObject * pyf_set_login_status(PyObject * self, PyObject * args);
PyObject * pyf_login(PyObject * self, PyObject * args);
PyObject * pyf_relogin(PyObject * self, PyObject * args);
PyObject * pyf_logout(PyObject * self, PyObject * args);
/* Set System Message Callback Functions */
PyObject * pyf_set_system_msg_cb(PyObject * self, PyObject * args);
/* Receive message functions */
PyObject * pyf_get_msg(PyObject * self, PyObject * args);
/* Send SMS Functions */
PyObject * pyf_send_sms(PyObject * self, PyObject * args);
PyObject * pyf_send_sms_to_self(PyObject * self, PyObject * args);
PyObject * pyf_send_sms_by_mobile(PyObject * self, PyObject * args);
PyObject * pyf_set_long_sms(PyObject * self, PyObject * args);
/* Dialog message */
PyObject * pyf_begin_dialog(PyObject * self, PyObject * args);
PyObject * pyf_dialog_send(PyObject * self, PyObject * args);
PyObject * pyf_end_dialog(PyObject * self, PyObject * args);
/* Get or Set User Info */
PyObject * pyf_get_user_uid(PyObject * self, PyObject * args);
PyObject * pyf_get_user_password(PyObject * self, PyObject * args);
PyObject * pyf_get_user_show_name(PyObject * self, PyObject * args);
PyObject * pyf_get_user_uri(PyObject * self, PyObject * args);
PyObject * pyf_get_user_mobile(PyObject * self, PyObject * args);
PyObject * pyf_get_user_score(PyObject * self, PyObject * args);
PyObject * pyf_set_user_state(PyObject * self, PyObject * args);
PyObject * pyf_get_user_state(PyObject * self, PyObject * args);
PyObject * pyf_set_user_impresa(PyObject * self, PyObject * args);
PyObject * pyf_set_user_nickname(PyObject * self, PyObject * args);
PyObject * pyf_get_user_refuse_sms_day(PyObject * self, PyObject * args);
PyObject * pyf_set_user_refuse_sms_day(PyObject * self, PyObject * args);
PyObject * pyf_get_expires_time(PyObject * self, PyObject * args);
PyObject * pyf_get_personal_info(PyObject * self, PyObject * args);
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
PyObject * pyf_is_in_blacklist_by_id(PyObject * self, PyObject * args);
PyObject * pyf_is_in_blacklist_by_account(PyObject * self, PyObject * args);
PyObject * pyf_move_group_buddy_by_id(PyObject * self, PyObject * args);
PyObject * pyf_move_group_buddy(PyObject * self, PyObject * args);
PyObject * pyf_is_online_by_id(PyObject * self, PyObject * args);
PyObject * pyf_is_online_by_account(PyObject * self, PyObject * args);
PyObject * pyf_get_online_status_by_id(PyObject * self, PyObject * args);
PyObject * pyf_get_online_status_by_account(PyObject * self, PyObject * args);
PyObject * pyf_get_refuse_sms_day(PyObject * self, PyObject * args);
PyObject * pyf_update_account_info_by_id(PyObject * self, PyObject * args);
PyObject * pyf_update_account_info_all(PyObject * self, PyObject * args);
PyObject * pyf_get_account_show_name(PyObject * self, PyObject * args);
PyObject * pyf_get_qun_show_name(PyObject * self, PyObject * args);
PyObject * pyf_get_account_group_id(PyObject * self, PyObject * args);
/* Group Opt Functions */
PyObject * pyf_rename_buddylist(PyObject * self, PyObject * args);
PyObject * pyf_add_buddylist(PyObject * self, PyObject * args);
PyObject * pyf_add_buddy_by_uid(PyObject * self, PyObject * args);
PyObject * pyf_add_buddy_by_mobile(PyObject * self, PyObject * args);
PyObject * pyf_handle_contact_request(PyObject * self, PyObject * args);
PyObject * pyf_delete_buddylist(PyObject * self, PyObject * args);
/* Buddy Opt Functions */
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
PyObject * pyf_set_proxy_enable(PyObject * self, PyObject * args);
PyObject * pyf_is_proxy_enable(PyObject * self, PyObject * args);
PyObject * pyf_test_network(PyObject * self, PyObject * args);
PyObject * pyf_get_original_id(PyObject * self, PyObject * args);
/* Misc Functions */
PyObject * pyf_simple_paser_msg(PyObject * self, PyObject * args);
//PyObject * pyf_(PyObject * self, PyObject * args);

/* Init function */
extern "C" 
{
	void initpyfetion(void);
}

/* Fetion_Account */
Fetion_Account * pydict_fetion_account(PyObject * dict);
PyObject * fetion_account_pydict(const Fetion_Account * account);
Fetion_Account * fetion_account_malloc(void);
void fetion_account_free(Fetion_Account * account);
/* Fetion_MSG */
PyObject * fetion_msg_pydict(const Fetion_MSG * msg);
Fetion_MSG * pydict_fetion_msg(PyObject * dict);
Fetion_MSG * fetion_msg_malloc(void);
void fetion_msg_free(Fetion_MSG * msg);
/* Fetion_Personal */
PyObject * fetion_personal_pydict(const Fetion_Personal * personal);
Fetion_Personal * pydict_fetion_personal(PyObject * dict);
Fetion_Personal * fetion_personal_malloc(void);
void fetion_personal_free(Fetion_Personal * personal);
/* Fetion_Group */
PyObject * fetion_group_pydict(const Fetion_Group * group);
Fetion_Group * pydict_fetion_group(PyObject * dict);
Fetion_Group * fetion_group_malloc(void);
void fetion_group_free(Fetion_Group * group);
/* Fetion_Black */
PyObject * fetion_black_pydict(const Fetion_Black * black);
Fetion_Black * pydict_fetion_black(PyObject * dict);
Fetion_Black * fetion_black_malloc(void);
void fetion_black_free(Fetion_Black * black);
/* Fetion_BList */
PyObject * fetion_blist_pydict(const Fetion_BList * blist);
Fetion_BList * pydict_fetion_blist(PyObject * dict);
Fetion_BList * fetion_blist_malloc(void);
void fetion_blist_free(Fetion_BList * blist);
/* Fetion_Qun */
PyObject * fetion_qun_pydict(const Fetion_Qun * qun);
Fetion_Qun * pydict_fetion_qun(PyObject * dict);
Fetion_Qun * fetion_qun_malloc(void);
void fetion_qun_free(Fetion_Qun * qun);
/* Fetion_QunInfo */
PyObject * fetion_quninfo_pydict(const Fetion_QunInfo * quninfo);
Fetion_QunInfo * pydict_fetion_quninfo(PyObject * dict);
Fetion_QunInfo * fetion_quninfo_malloc(void);
void fetion_quninfo_free(Fetion_QunInfo * quninfo);
/* Fetion_QunMember */
PyObject * fetion_qunmember_pydict(const Fetion_QunMember * qunmember);
Fetion_QunMember * pydict_fetion_qunmember(PyObject * dict);
Fetion_QunMember * fetion_qunmember_malloc(void);
void fetion_qunmember_free(Fetion_QunMember * qunmember);
/* PROXY_ITEM */
PyObject * proxy_item_pydict(const PROXY_ITEM * proxy_item);
PROXY_ITEM * pydict_proxy_item(PyObject * dict);
PROXY_ITEM * proxy_item_malloc(void);
void proxy_item_free(PROXY_ITEM * item);
/* status */
int status_str_int(const char * status);
const char * status_int_str(int status);

/* callback functions */
void login_callback_func(int message, WPARAM wParam, LPARAM lParam, void *args);
void system_msg_callback_func(int message, WPARAM wParam, LPARAM lParam, void *args);

/* callback object */
static PyObject * login_cb = NULL;
static PyObject * system_msg_cb = NULL;
static PyObject * sys_msg_cb_args = NULL;
static PyObject * login_cb_args = NULL;

static PyMethodDef pyfetionMethods[] =
{
	{"init", pyf_init, METH_VARARGS, HELP_INIT},
	{"terminate",  pyf_terminate, METH_VARARGS, HELP_TERMINATE},
	{"close_network",  pyf_close_network, METH_VARARGS, HELP_CLOSE_NETWORK},
	{"set_login_status", pyf_set_login_status , METH_VARARGS, HELP_SET_LOGIN_STATUS},
	{"login", pyf_login , METH_VARARGS, HELP_LOGIN},
	{"relogin", pyf_relogin , METH_VARARGS, HELP_RELOGIN},
	{"logout", pyf_logout , METH_VARARGS, HELP_LOGOUT},
	{"set_system_msg_cb",pyf_set_system_msg_cb , METH_VARARGS, HELP_SET_SYSTEM_MSG_CB},
	{"get_msg", pyf_get_msg , METH_VARARGS, HELP_GET_MSG},
	{"send_sms", pyf_send_sms , METH_VARARGS, HELP_SEND_SMS},
	{"send_sms_to_self", pyf_send_sms_to_self , METH_VARARGS, HELP_SEND_SMS_TO_SELF},
	{"send_sms_by_mobile", pyf_send_sms_by_mobile , METH_VARARGS, HELP_SEND_SMS_BY_MOBILE},
	{"set_long_sms", pyf_set_long_sms, METH_VARARGS, HELP_SET_LONG_SMS},
	{"begin_dialog", pyf_begin_dialog , METH_VARARGS, HELP_BEGIN_DIALOG},
	{"dialog_send", pyf_dialog_send , METH_VARARGS, HELP_DIALOG_SEND},
	{"end_dialog", pyf_end_dialog , METH_VARARGS, HELP_END_DIALOG},
	{"get_user_uid", pyf_get_user_uid , METH_VARARGS, HELP_GET_USER_UID},
	{"get_user_password", pyf_get_user_password, METH_VARARGS, HELP_GET_USER_PASSWORD},
	{"get_user_show_name", pyf_get_user_show_name, METH_VARARGS, HELP_GET_USER_SHOW_NAME},
	{"get_user_uri", pyf_get_user_uri , METH_VARARGS, HELP_GET_USER_URI},
	{"get_user_mobile", pyf_get_user_mobile , METH_VARARGS, HELP_GET_USER_MOBILE},
	{"get_user_score", pyf_get_user_score, METH_VARARGS, HELP_GET_USER_SCORE},
	{"set_user_state", pyf_set_user_state , METH_VARARGS, HELP_SET_USER_STATE},
	{"get_user_state", pyf_get_user_state , METH_VARARGS, HELP_GET_USER_STATE},
	{"set_user_impresa", pyf_set_user_impresa, METH_VARARGS, HELP_SET_USER_IMPRESA},
	{"set_user_nickname", pyf_set_user_nickname, METH_VARARGS, HELP_SET_USER_NICKNAME},
	{"get_user_refuse_sms_day", pyf_get_user_refuse_sms_day, METH_VARARGS, HELP_GET_USER_REFUSE_SMS_DAY},
	{"set_user_refuse_sms_day", pyf_set_user_refuse_sms_day, METH_VARARGS, HELP_SET_USER_REFUSE_SMS_DAY},
	{"get_expires_time", pyf_get_expires_time , METH_VARARGS, HELP_GET_EXPIRE_TIME},
	{"get_personal_info", pyf_get_personal_info , METH_VARARGS, HELP_GET_PERSONAL_INFO},
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
	{"is_in_blacklist_by_id", pyf_is_in_blacklist_by_id , METH_VARARGS, HELP_IS_IN_BLACKLIST_BY_ID},
	{"is_in_blacklist_by_account", pyf_is_in_blacklist_by_account , METH_VARARGS, HELP_IS_IN_BLACKLIST_BY_ACCOUNT},
	{"move_group_buddy_by_id", pyf_move_group_buddy_by_id, METH_VARARGS, HELP_MOVE_GROUP_BUDDY_BY_ID},
	{"move_group_buddy", pyf_move_group_buddy, METH_VARARGS, HELP_MOVE_GROUP_BUDDY},
	{"is_online_by_id", pyf_is_online_by_id , METH_VARARGS, HELP_IS_ONLINE_BY_ID},
	{"is_online_by_account", pyf_is_online_by_account , METH_VARARGS, HELP_IS_ONLINE_BY_ACCOUNT},
	{"get_online_status_by_id", pyf_get_online_status_by_id , METH_VARARGS, HELP_GET_ONLINE_STATUS_BY_ID},
	{"get_online_status_by_account", pyf_get_online_status_by_account , METH_VARARGS, HELP_GET_ONLINE_STATUS_BY_ACCOUNT},
	{"get_refuse_sms_day", pyf_get_refuse_sms_day, METH_VARARGS, HELP_GET_REFUSE_SMS_DAY},
	{"update_account_info_by_id", pyf_update_account_info_by_id , METH_VARARGS, HELP_UPDATE_ACCOUNT_INFO_BY_ID},
	{"update_account_info_all", pyf_update_account_info_all , METH_VARARGS, HELP_UPDATE_ACCOUNT_INFO_ALL},
	{"get_account_show_name", pyf_get_account_show_name , METH_VARARGS, HELP_GET_ACCOUNT_SHOW_NAME},
	{"get_qun_show_name", pyf_get_qun_show_name , METH_VARARGS, HELP_GET_QUN_SHOW_NAME},
	{"get_account_group_id", pyf_get_account_group_id , METH_VARARGS, HELP_GET_ACCOUNT_GROUP_ID},
	{"rename_buddylist", pyf_rename_buddylist, METH_VARARGS, HELP_RENAME_BUDDYLIST},
	{"add_buddylist", pyf_add_buddylist, METH_VARARGS, HELP_ADD_BUDDYLIST},
	{"add_buddy_by_uid", pyf_add_buddy_by_uid , METH_VARARGS, HELP_ADD_BUDDY_BY_UID},
	{"add_buddy_by_mobile", pyf_add_buddy_by_mobile, METH_VARARGS, HELP_ADD_BUDDY_BY_MOBILE},
	{"handle_contact_request", pyf_handle_contact_request, METH_VARARGS, HELP_HANDLE_CONTACT_REQUEST},
	{"delete_buddylist", pyf_delete_buddylist, METH_VARARGS, HELP_DELETE_BUDDYLIST},
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
	{"set_proxy_enable", pyf_set_proxy_enable, METH_VARARGS, HELP_SET_PROXY_ENABLE},
	{"is_proxy_enable", pyf_is_proxy_enable, METH_VARARGS, HELP_IS_PROXY_ENABLE},
	{"test_network", pyf_test_network, METH_VARARGS, HELP_TEST_NETWORK},
	{"simple_paser_msg", pyf_simple_paser_msg, METH_VARARGS, HELP_SIMPLE_PASER_MSG},
	{"get_original_id", pyf_get_original_id, METH_VARARGS, HELP_GET_ORIGINAL_ID},
	{NULL, NULL, 0, NULL}
};

#endif	/* __PYFETION_H__ */
