/* pyfetion.c
 * Heihaier <admin@heihaier.org>
 * http://www.heihaier.org
 */

#include "pyfetion.h"
#include <string.h>

/* Methods */
/* Fetion Init */
/* BOOL fx_init(void); */
PyObject * pyf_init(PyObject * self, PyObject * args)
{
	BOOL b = fx_init();
	if(b == TRUE)
	  Py_RETURN_TRUE;
	else
	  Py_RETURN_FALSE;
}

/* void fx_terminate(void); */
PyObject * pyf_terminate(PyObject * self, PyObject * args)
{
	fx_terminate();
	Py_RETURN_NONE;
}

/* BOOL fx_close_network(); */
PyObject * pyf_close_network(PyObject * self, PyObject * args)
{
	BOOL b = fx_close_network();
	if(b == TRUE)
	  Py_RETURN_TRUE;
	else
	  Py_RETURN_FALSE;
}

/* Login and Out */
/* BOOL fs_login(const char *, const char *); */
PyObject * pyf_s_login(PyObject * self, PyObject * args)
{
	char * uid, * pwd;

	if(!PyArg_ParseTuple(args, "ss", &uid, &pwd))
	  return NULL;
	if(fs_login(uid, pwd))
	  Py_RETURN_TRUE;
	else
	  Py_RETURN_FALSE;
}

/* void fx_set_login_status(int); */
PyObject * pyf_set_login_status(PyObject * self, PyObject * args)
{
	const char * status;

	if(!PyArg_ParseTuple(args, "s", &status))
	  return NULL;
	fx_set_login_status(status_str_int(status));

	Py_RETURN_NONE;
}

/* int fx_login(const char *, const char *, EventListener, void *); */
PyObject * pyf_login(PyObject * self, PyObject * args)
{
	char * uid, * pwd;
	PyObject * fargs;

	if(!PyArg_ParseTuple(args, "ssOO", &uid, &pwd, &login_cb, &fargs))
	  return NULL;
	if(!PyCallable_Check(login_cb)) return NULL;
	Py_XINCREF(login_cb);

	if(fx_login(uid, pwd, login_callback_func, fargs))
	  Py_RETURN_TRUE;
	else
	  Py_RETURN_FALSE;
}

/* void fx_loginout() */
PyObject * pyf_loginout(PyObject * self, PyObject * args)
{
	fx_loginout();

	Py_RETURN_NONE;
}

/* Set System Message Callback Functions */
/* void fx_set_system_msg_cb(EventListener, void *); */
PyObject * pyf_set_system_msg_cb(PyObject * self, PyObject * args)
{
	if(!PyArg_ParseTuple(args, "OO", &system_msg_cb, &sys_msg_cb_args))
	  return NULL;
	if(!PyCallable_Check(system_msg_cb)) return NULL;
	Py_XINCREF(system_msg_cb);

	fx_set_system_msg_cb(system_msg_callback_func, sys_msg_cb_args);

	Py_RETURN_NONE;
}

/* Receive message functions */
/* Fetion_MSG * fx_get_msg(long); */
PyObject * pyf_get_msg(PyObject * self, PyObject * args)
{
	long uid;
	Fetion_MSG * msg;

	if(!PyArg_ParseTuple(args, "k", &uid))
	  return NULL;
	msg = fx_get_msg(uid);
	if(msg == NULL)
	  Py_RETURN_NONE;

	PyObject * o = fetion_msg_pydict(msg);
	fx_destroy_msg(msg);
	return o;
}

/* Send SMS Functions */
/* BOOL fs_send_sms(const long, const char *); */
PyObject * pyf_s_send_sms(PyObject * self, PyObject * args)
{
	long who;
	char * msg;

	if(!PyArg_ParseTuple(args, "ks", &who, &msg))
	  return NULL;
	if(fs_send_sms(who, msg))
	  Py_RETURN_TRUE;
	else
	  Py_RETURN_FALSE;
}

/* BOOL fs_send_sms_by_mobile_no(const char *, const char *); */
PyObject * pyf_s_send_sms_by_mobile_no(PyObject * self, PyObject * args)
{
	char * mobile, * msg;

	if(!PyArg_ParseTuple(args, "ss", &mobile, &msg))
	  return NULL;
	if(fs_send_sms_by_mobile_no(mobile, msg))
	  Py_RETURN_TRUE;
	else
	  Py_RETURN_FALSE;
}

/* BOOL fs_send_sms_to_self(const char *); */
PyObject * pyf_s_send_sms_to_self(PyObject * self, PyObject * args)
{
	char * msg;

	if(!PyArg_ParseTuple(args, "s", &msg))
	  return NULL;
	if(fs_send_sms_to_self(msg))
	  Py_RETURN_TRUE;
	else
	  Py_RETURN_FALSE;
}

/* int fx_send_sms(const long, const char *, EventListener, void *); */
PyObject * pyf_send_sms(PyObject * self, PyObject * args)
{
	long who;
	char * msg;

	if(!PyArg_ParseTuple(args, "ks", &who, &msg))
	  return NULL;
	return Py_BuildValue("i", fx_send_sms(who, msg, system_msg_callback_func, sys_msg_cb_args));
}

/* int fx_send_sms_to_self(const char *, EventListener, void *); */
PyObject * pyf_send_sms_to_self(PyObject * self, PyObject * args)
{
	char * msg;

	if(!PyArg_ParseTuple(args, "s", &msg))
	  return NULL;
	return Py_BuildValue("i", fx_send_sms_to_self(msg, system_msg_callback_func, sys_msg_cb_args));
}

/* int fx_send_sms_by_mobile_no(const char *, const char *, EventListener, void *); */
PyObject * pyf_send_sms_by_mobile_no(PyObject * self, PyObject * args)
{
	char * mobile_no;
	char * msg;

	if(!PyArg_ParseTuple(args, "ss", &mobile_no, &msg))
	  return NULL;
	return Py_BuildValue("i", fx_send_sms_by_mobile_no(mobile_no, msg, system_msg_callback_func, sys_msg_cb_args));
}

/* void fx_set_longsms(BOOL) */
PyObject * pyf_set_longsms(PyObject * self, PyObject * args)
{
	PyObject * pb;

	if(!PyArg_ParseTuple(args, "O", &pb))
	  return NULL;
	if(!PyBool_Check(pb))
	  return NULL;
	if(pb == Py_True)
	  fx_set_longsms(TRUE);
	else
	  fx_set_longsms(FALSE);

	Py_RETURN_NONE;
}

/* Dialog message */
/* BOOL fs_login_dialog(long); */
PyObject * pyf_s_begin_dialog(PyObject * self, PyObject * args)
{
	long who;

	if(!PyArg_ParseTuple(args, "k", &who))
	  return NULL;
	if(fs_begin_dialog(who))
	  Py_RETURN_TRUE;
	else
	  Py_RETURN_FALSE;
}

/* BOOL fs_dialog_send(long, const char *); */
PyObject * pyf_s_dialog_send(PyObject * self, PyObject * args)
{
	long who;
	char * msg;

	if(!PyArg_ParseTuple(args, "ks", &who, &msg))
	  return NULL;
	if(fs_dialog_send(who, msg))
	  Py_RETURN_TRUE;
	else
	  Py_RETURN_FALSE;
}

/* void fs_end_dialog(long); */
PyObject * pyf_s_end_dialog(PyObject * self, PyObject * args)
{
	long who;

	if(!PyArg_ParseTuple(args, "k", &who))
	  return NULL;
	fs_end_dialog(who);

	Py_RETURN_NONE;
}

/* int fx_begin_dialog(long, EventListenet, void *); */
PyObject * pyf_begin_dialog(PyObject * self, PyObject * args)
{
	long who;

	if(!PyArg_ParseTuple(args, "k", &who))
	  return NULL;
	return Py_BuildValue("i", fx_begin_dialog(who, system_msg_callback_func, sys_msg_cb_args));
}

/* int fx_dialog_send(long, const char *, EventListener, void *); */
PyObject * pyf_dialog_send(PyObject * self, PyObject * args)
{
	long who;
	char * msg;

	if(!PyArg_ParseTuple(args, "ks", &who, &msg))
	  return NULL;
	return Py_BuildValue("i", fx_dialog_send(who, msg, system_msg_callback_func, sys_msg_cb_args));
}

/* int fx_end_dialog(long); */
PyObject * pyf_end_dialog(PyObject * self, PyObject * args)
{
	long who;

	if(!PyArg_ParseTuple(args, "k", &who))
	  return NULL;
	fx_end_dialog(who);

	Py_RETURN_NONE;
}

/* Get or Set User Info */
/* const char * fx_get_usr_uid(void); */
PyObject * pyf_get_usr_uid(PyObject * self, PyObject * args)
{
	const char * s = fx_get_usr_uid();
	return Py_BuildValue("s", s);
}

/* cosnt char * fx_get_usr_passwd(void); */
PyObject * pyf_get_usr_passwd(PyObject * self, PyObject * args)
{
	const char * s = fx_get_usr_passwd();
	return Py_BuildValue("s", s);
}

/* const char * fx_get_usr_show_name(void); */
PyObject * pyf_get_usr_show_name(PyObject * self, PyObject * args)
{
	const char * s = fx_get_usr_show_name();
	return Py_BuildValue("s", s);
}

/* const char * fx_get_usr_uri(void); */
PyObject * pyf_get_usr_uri(PyObject * self, PyObject * args)
{
	const char * s = fx_get_usr_uri();
	return Py_BuildValue("s", s);
}

/* const char * fx_get_usr_mobilenum(void); */
PyObject * pyf_get_usr_mobilenum(PyObject * self, PyObject * args)
{
	const char * s = fx_get_usr_mobilenum();
	return Py_BuildValue("s", s);
}

/* int fx_get_usr_score(void); */
PyObject * pyf_get_usr_score(PyObject * self, PyObject * args)
{
	int i = fx_get_usr_score();
	return Py_BuildValue("i", i);
}

/* int fx_set_user_state(int, char *, EventListener, void*); */
PyObject* pyf_set_user_state(PyObject * self, PyObject * args)
{
	char * state, * desc;
	
	if(!PyArg_ParseTuple(args, "ss", &state, &desc))
	  return NULL;
	
	return Py_BuildValue("i", fx_set_user_state(status_str_int(state), desc, system_msg_callback_func, sys_msg_cb_args));
}

/* int fx_get_user_state(void); */
PyObject * pyf_get_user_state(PyObject * self, PyObject * args)
{
	int s = fx_get_user_state();

	return Py_BuildValue("s", status_int_str(s));
}

/* int fx_set_user_impresa(const char *, EventListener, void *); */
PyObject * pyf_set_user_impresa(PyObject * self, PyObject * args)
{
	char * s;
	int i;

	if(!PyArg_ParseTuple(args, "s", &s))
	  return NULL;
	i = fx_set_user_impresa(s, system_msg_callback_func, sys_msg_cb_args);
	return Py_BuildValue("i", i);
}

/* int fx_set_user_nickname(cosnt char *, EventListener, void *); */
PyObject * pyf_set_user_nickname(PyObject * self, PyObject * args)
{
	char * s;
	int i;

	if(!PyArg_ParseTuple(args, "s", &s))
	  return NULL;
	i = fx_set_user_nickname(s, system_msg_callback_func, sys_msg_cb_args);
	return Py_BuildValue("i", i);
}

/* int fx_get_refuse_sms_day(void); */
PyObject * pyf_get_user_refuse_sms_day(PyObject * self, PyObject * args)
{
	int i = fx_get_user_refuse_sms_day();

	return Py_BuildValue("i", i);
}

/* int fx_set_refuse_sms_day(int, EventListener, void *); */
PyObject * pyf_set_user_refuse_sms_day(PyObject * self, PyObject * args)
{
	int i, r;

	if(!PyArg_ParseTuple(args, "i", &i))
	  return NULL;
	r = fx_set_user_refuse_sms_day(i, system_msg_callback_func, sys_msg_cb_args);

	return Py_BuildValue("i", r);
}

/* int fx_get_expirestime(void); */
PyObject * pyf_get_expirestime(PyObject * self, PyObject * args)
{
	int s = fx_get_expirestime();
	return Py_BuildValue("i", s);
}

/* Fetion_Personal * fx_data_get_PersonalInfo(void); */
PyObject * pyf_data_get_PersonalInfo(PyObject * self, PyObject * args)
{
	Fetion_Personal * info;

	info = (Fetion_Personal*)fx_data_get_PersonalInfo();
	if(info == NULL)
	  Py_RETURN_NONE;
	else
	  return fetion_personal_pydict(info);
}

/* Get contacts info */
/* DList * fx_get_group(); */
PyObject * pyf_get_group(PyObject * self, PyObject * args)
{
	Fetion_Group * group = NULL;
	DList * list = (DList*)fx_get_group();
	PyObject * pylist = PyList_New(0);
	assert(pylist);

	while(list)
	{
		group = (Fetion_Group*)list->data;
		if(group)
		  PyList_Append(pylist, fetion_group_pydict(group));
		list = d_list_next(list);
	}
	return pylist;
}

/* DList * fx_get_account(); */
PyObject * pyf_get_account(PyObject * self, PyObject * args)
{
	Fetion_Account * account = NULL;
	DList * list = (DList*)fx_get_account();
	PyObject * pylist = PyList_New(0);
	assert(pylist);

	while(list)
	{
		account = (Fetion_Account*)list->data;
		if(account)
		  PyList_Append(pylist, fetion_account_pydict(account));
		list = d_list_next(list);
	}
	return pylist;
}

/* DList * fx_get_blacklist(); */
PyObject * pyf_get_blacklist(PyObject * self, PyObject * args)
{
	Fetion_Black * black = NULL;
	DList * list = (DList*)fx_get_blacklist();
	PyObject * pylist = PyList_New(0);
	assert(pylist);

	while(list)
	{
		black = (Fetion_Black*)list->data;
		if(black)
		  PyList_Append(pylist, fetion_black_pydict(black));
		list = d_list_next(list);
	}
	return pylist;
}

/* DList * fx_get_qun(); */
PyObject * pyf_get_qun(PyObject * self, PyObject * args)
{
	Fetion_Qun * qun = NULL;
	DList * list = (DList*)fx_get_qun();
	PyObject * pylist = PyList_New(0);
	assert(pylist);

	while(list)
	{
		qun = (Fetion_Qun*)list->data;
		if(qun)
		  PyList_Append(pylist, fetion_qun_pydict(qun));
		list = d_list_next(list);
	}
	return pylist;
}

/* Fetion_Account * fx_get_account_by_id(long); */
PyObject * pyf_get_account_by_id(PyObject * self, PyObject * args)
{
	long id;
	Fetion_Account * account;

	if(!PyArg_ParseTuple(args, "k", &id))
	  return NULL;
	account = (Fetion_Account*)fx_get_account_by_id(id);
	if(account == NULL)
	  Py_RETURN_NONE;

	return fetion_account_pydict(account);
}

/* Fetion_Qun * fx_get_qun_by_id(long); */
PyObject * pyf_get_qun_by_id(PyObject * self, PyObject * args)
{
	long id;

	if(!PyArg_ParseTuple(args, "k", &id))
	  return NULL;
	Fetion_Qun * qun = (Fetion_Qun*)fx_get_qun_by_id(id);

	return fetion_qun_pydict(qun);
}

/* BOOL fx_is_qun_by_id(long); */
PyObject * pyf_is_qun_by_id(PyObject * self, PyObject * args)
{
	long id;

	if(!PyArg_ParseTuple(args, "k", &id))
	  return NULL;
	if(fx_is_qun_by_id(id))
	  Py_RETURN_TRUE;
	else
	  Py_RETURN_FALSE;
}

/* BOOL fx_is_pc_user_by_id(long); */
PyObject * pyf_is_pc_user_by_id(PyObject * self, PyObject * args)
{
	long id;

	if(!PyArg_ParseTuple(args, "k", &id))
	  return NULL;
	if(fx_is_pc_user_by_id(id))
	  Py_RETURN_TRUE;
	else
	  Py_RETURN_FALSE;
}

/* BOOL fx_is_pc_user_by_account(const Fetion_Account *); */
PyObject * pyf_is_pc_user_by_account(PyObject * self, PyObject * args)
{
	PyObject * account;

	if(!PyArg_ParseTuple(args, "O", &account))
	  return NULL;
	if(!PyDict_Check(account))
	  return NULL;

	Fetion_Account * pfa = pydict_fetion_account(account);
	BOOL b = fx_is_pc_user_by_account(pfa);
	fetion_account_free(pfa);
	if(b)
	  Py_RETURN_TRUE;
	else
	  Py_RETURN_FALSE;
}

/* int fx_is_authed_by_id(long); */
PyObject * pyf_is_authed_by_id(PyObject * self, PyObject * args)
{
	long id;
	int i;

	if(!PyArg_ParseTuple(args, "k", &id))
	  return NULL;
	i = fx_is_authed_by_id(id);
	return Py_BuildValue("i", i);
}

/* BOOL fx_is_authed_by_account(Fetion_Account *); */
PyObject * pyf_is_authed_by_account(PyObject * self, PyObject * args)
{
	PyObject * account;

	if(!PyArg_ParseTuple(args, "O", &account))
	  return NULL;
	if(!PyDict_Check(account))
	  return NULL;

	Fetion_Account * pfa = pydict_fetion_account(account);
	int i = fx_is_authed_by_account(pfa);
	fetion_account_free(pfa);

	return Py_BuildValue("i", i);
}

/* BOOL fx_is_InBlacklist_by_id(const long); */
PyObject * pyf_is_InBlacklist_by_id(PyObject * self, PyObject * args)
{
	long id;

	if(!PyArg_ParseTuple(args, "k", &id))
	  return NULL;
	if(fx_is_InBlacklist_by_id(id))
	  Py_RETURN_TRUE;
	else
	  Py_RETURN_FALSE;
}

/* BOOL fx_is_InBlacklist_by_account(cosnt Fetion_Account *); */
PyObject * pyf_is_InBlacklist_by_account(PyObject * self, PyObject * args)
{
	PyObject * dict;

	if(!PyArg_ParseTuple(args, "O", &dict))
	  return NULL;
	if(!PyDict_Check(dict))
	  return NULL;
	Fetion_Account * pfa = pydict_fetion_account(dict);
	BOOL b = fx_is_InBlacklist_by_account(pfa);
	fetion_account_free(pfa);
	if(b)
	  Py_RETURN_TRUE;
	else
	  Py_RETURN_FALSE;
}

/* int fx_move_group_buddy_by_id(long, int, EventListener, void *); */
PyObject * pyf_move_group_buddy_by_id(PyObject * self, PyObject * args)
{
	long uid;
	int i, group_id;

	if(!PyArg_ParseTuple(args, "ki", &uid, &group_id))
	  return NULL;
	i = fx_move_group_buddy_by_id(uid, group_id, system_msg_callback_func, sys_msg_cb_args);

	return Py_BuildValue("i", i);
}

/* int fx_move_group_buddy(const Fetion_Account *, int, EventListener, void *); */
PyObject * pyf_move_group_buddy(PyObject * self, PyObject * args)
{
	int group_id, i;
	PyObject * pdfa;

	if(!PyArg_ParseTuple(args, "Oi", &pdfa, &group_id))
	  return NULL;
	if(!PyDict_Check(pdfa))
	  return NULL;
	Fetion_Account * pfa = pydict_fetion_account(pdfa);
	i = fx_move_group_buddy(pfa, group_id, system_msg_callback_func, sys_msg_cb_args);
	fetion_account_free(pfa);

	return Py_BuildValue("i", i);
}

/* BOOL fx_is_on_line_by_id(long); */
PyObject * pyf_is_on_line_by_id(PyObject * self, PyObject * args)
{
	long id;
	
	if(!PyArg_ParseTuple(args, "k", &id))
	  return NULL;
	if(fx_is_on_line_by_id(id))
	  Py_RETURN_TRUE;
	else
	  Py_RETURN_FALSE;
}

/* BOOL fx_is_on_line_by_account(const Fetion_Account *); */
PyObject * pyf_is_on_line_by_account(PyObject * self, PyObject * args)
{
	PyObject * pdfa;

	if(!PyArg_ParseTuple(args, "O", &pdfa))
	  return NULL;
	if(!PyDict_Check(pdfa))
	  return NULL;
	Fetion_Account * pfa = pydict_fetion_account(pdfa);
	BOOL b = fx_is_on_line_by_account(pfa);
	fetion_account_free(pfa);
	if(b)
	  Py_RETURN_TRUE;
	else
	  Py_RETURN_FALSE;
}

/* int fx_get_online_status_by_id(const long); */
PyObject * pyf_get_online_status_by_id(PyObject * self, PyObject * args)
{
	long uid;
	int status;

	if(!PyArg_ParseTuple(args, "k", &uid))
	  return NULL;
	status = fx_get_online_status_by_id(uid);
	
	return Py_BuildValue("s", status_int_str(status));
}

/* int fx_get_online_status_by_account(const Fetion_Account *); */
PyObject * pyf_get_online_status_by_account(PyObject * self, PyObject * args)
{
	PyObject * pdfa;
	int status;

	if(!PyArg_ParseTuple(args, "O", &pdfa))
	  return NULL;
	if(!PyDict_Check(pdfa))
	  return NULL;
	Fetion_Account * pfa = pydict_fetion_account(pdfa);
	status = fx_get_online_status_by_account(pfa);
	fetion_account_free(pfa);

	return Py_BuildValue("s", status_int_str(status));
}

/* int fx_get_refuse_sms_day(const Fetion_Account *); */
PyObject * pyf_get_refuse_sms_day(PyObject * self, PyObject * args)
{
	PyObject * pdfa;

	if(!PyArg_ParseTuple(args, "O", &pdfa))
	  return NULL;
	if(!PyDict_Check(pdfa))
	  return NULL;
	Fetion_Account * pfa = pydict_fetion_account(pdfa);
	int i = fx_get_refuse_sms_day(pfa);
	fetion_account_free(pfa);

	return Py_BuildValue("i", i);
}

/* void fx_updata_account_info_by_id(long); */
PyObject * pyf_updata_account_info_by_id(PyObject * self, PyObject * args)
{
	long id;

	if(!PyArg_ParseTuple(args, "k", &id))
	  return NULL;
	fx_updata_account_info_by_id(id);

	Py_RETURN_NONE;
}

/* void fx_updata_account_info_all(); */
PyObject * pyf_updata_account_info_all(PyObject * self, PyObject * args)
{
	fx_updata_account_info_all();

	Py_RETURN_NONE;
}

/* char * fx_get_account_show_name(cosnt Fetion_Account *, BOOL); */
PyObject * pyf_get_account_show_name(PyObject * self, PyObject * args)
{
	PyObject * pb, * pdfa;
	char * s;
	BOOL b;

	if(!PyArg_ParseTuple(args, "OO", &pdfa, &pb))
	  return NULL;
	if(!PyDict_Check(pdfa))
	  return NULL;
	if(!PyBool_Check(pb))
	  return NULL;
	Fetion_Account * pfa = pydict_fetion_account(pdfa);
	if(pb == Py_True)
	  b = TRUE;
	else
	  b = FALSE;
	s = fx_get_account_show_name(pfa, b);
	fetion_account_free(pfa);

	return Py_BuildValue("s", s);
}

/* char * fx_get_qun_shwo_name(Fetion_Qun *); */
PyObject * pyf_get_qun_show_name(PyObject * self, PyObject * args)
{
	PyObject * pdfq;
	char * s;

	if(!PyArg_ParseTuple(args, "O", &pdfq))
	  return NULL;
	Fetion_Qun * pfq = (Fetion_Qun*)pydict_fetion_qun(pdfq);
	s = fx_get_qun_show_name(pfq);
	fetion_qun_free(pfq);

	return Py_BuildValue("s", s);
}

/* int fx_get_account_group_id(const Fetion_Account *); */
PyObject * pyf_get_account_group_id(PyObject * self, PyObject * args)
{
	PyObject * pdfa;
	int i;

	if(!PyArg_ParseTuple(args, "O", &pdfa))
	  return NULL;
	Fetion_Account * pfa = (Fetion_Account*)pydict_fetion_account(pdfa);
	i = fx_get_account_group_id(pfa);
	fetion_account_free(pfa);

	return Py_BuildValue("i", i);
}

/* Group Opt Functions */
/* BOOL fs_rename_buddylist(int, char *); */
PyObject * pyf_s_rename_buddylist(PyObject * self, PyObject * args)
{
	int id;
	char * name;

	if(!PyArg_ParseTuple(args, "is", &id, &name))
	  return NULL;
	if(fs_rename_buddylist(id, name))
	  Py_RETURN_TRUE;
	else
	  Py_RETURN_FALSE;
}

/* BOOL fs_delete_buddylist(int); */
PyObject * pyf_s_delete_buddylist(PyObject * self, PyObject * args)
{
	int id;

	if(!PyArg_ParseTuple(args, "i", &id))
	  return NULL;
	if(fs_delete_buddylist(id))
	  Py_RETURN_TRUE;
	else
	  Py_RETURN_FALSE;
}

/* int fx_rename_buddylist(int, const char *, EventListener, void *); */
PyObject * pyf_rename_buddylist(PyObject * self, PyObject * args)
{
	int id, i;
	char * name;

	if(!PyArg_ParseTuple(args, "is", &id, &name))
	  return NULL;
	i = fx_rename_buddylist(id, name, system_msg_callback_func, sys_msg_cb_args);
	return Py_BuildValue("i", i);
}

/* int fx_add_buddylist(const char *, EventListener, void *); */
PyObject * pyf_add_buddylist(PyObject * self, PyObject * args)
{
	int i;
	char * name;

	if(!PyArg_ParseTuple(args, "s", &name))
	  return NULL;
	i = fx_add_buddylist(name, system_msg_callback_func, sys_msg_cb_args);
	return Py_BuildValue("i", i);
}

/* int fx_add_buddy_by_uid(const char *, const char *, int, const char *, EventListener, void *); */
PyObject * pyf_add_buddy_by_uid(PyObject * self, PyObject * args)
{
	char * uid, * local_name, *desc;
	int groupid, i;

	if(!PyArg_ParseTuple(args, "ssis", &uid, &local_name, &groupid, &desc))
	  return NULL;
	i = fx_add_buddy_by_uid(uid, local_name, groupid, desc, system_msg_callback_func, sys_msg_cb_args);

	return Py_BuildValue("i", i);
}

/* int fx_add_buddy_by_mobile(const char *, const char *, int, const char *, EventListener, void *); */
PyObject * pyf_add_buddy_by_mobile(PyObject * self, PyObject * args)
{
	char * mobile, * local_name, *desc;
	int groupid, i;

	if(!PyArg_ParseTuple(args, "ssis", &mobile, &local_name, &groupid, &desc))
	  return NULL;
	i = fx_add_buddy_by_mobile(mobile, local_name, groupid, desc, system_msg_callback_func, sys_msg_cb_args);

	return Py_BuildValue("i", i);
}

/* int fx_handleContactRequest(const char *, int, int, const char *); */
PyObject * pyf_handleContactRequest(PyObject * self, PyObject * args)
{
	char * uri, * local_name;
	int i, isPassed, group;

	if(!PyArg_ParseTuple(args, "siis", &uri, &isPassed, &group, &local_name))
	  return NULL;
	i = fx_handleContactRequest(uri, isPassed, group, local_name);

	return Py_BuildValue("i", i);
}

/* int fx_delete_buddylist(int, EventListener, void *); */
PyObject * pyf_delete_buddylist(PyObject * self, PyObject * args)
{
	int i, id;

	if(!PyArg_ParseTuple(args, "i", &id))
	  return NULL;
	i = fx_delete_buddylist(id, system_msg_callback_func, sys_msg_cb_args);

	return Py_BuildValue("i", i);
}

/* Buddy Opt Functions */
/* BOOL fs_set_buddyinfo(long, const char *); */
PyObject * pyf_s_set_buddyinfo(PyObject * self, PyObject * args)
{
	long uid;
	char * localname;

	if(!PyArg_ParseTuple(args, "ks", &uid, &localname))
	  return NULL;
	if(fs_set_buddyinfo(uid, localname))
	  Py_RETURN_TRUE;
	else
	  Py_RETURN_FALSE;
}

/* int fx_set_buddyinfo(long, const char *, EventListener, void *); */
PyObject * pyf_set_buddyinfo(PyObject * self, PyObject * args)
{
	int i;
	long uid;
	char * localname;

	if(!PyArg_ParseTuple(args, "ks", &uid, &localname))
	  return NULL;
	i = fx_set_buddyinfo(uid, localname, system_msg_callback_func, sys_msg_cb_args);

	return Py_BuildValue("i", i);
}

/* int fx_delete_buddy_by_id(long, EventListener, void *); */
PyObject * pyf_delete_buddy_by_id(PyObject * self, PyObject * args)
{
	int i;
	long uid;

	if(!PyArg_ParseTuple(args, "k", &uid))
	  return NULL;
	i = fx_delete_buddy_by_id(uid, system_msg_callback_func, sys_msg_cb_args);

	return Py_BuildValue("i", i);
}

/* int fx_delete_buddy_by_account(Fetion_Account *, EventListener, void *); */
PyObject * pyf_delete_buddy_by_account(PyObject * self, PyObject * args)
{
	PyObject * pdfa;
	int i;

	if(!PyArg_ParseTuple(args, "O", &pdfa))
	  return NULL;
	Fetion_Account * pfa = (Fetion_Account*)pydict_fetion_account(pdfa);
	i = fx_delete_buddy_by_account(pfa, system_msg_callback_func, sys_msg_cb_args);
	fetion_account_free(pfa);

	return Py_BuildValue("i", i);
}

/* int fx_addto_blacklist_by_id(const long, EventListener, void *); */
PyObject * pyf_addto_blacklist_by_id(PyObject * self, PyObject * args)
{
	long uid;
	int i;
	
	if(!PyArg_ParseTuple(args, "k", &uid))
	  return NULL;
	i = fx_addto_blacklist_by_id(uid, system_msg_callback_func, sys_msg_cb_args);

	return Py_BuildValue("i", i);
}

/* int fx_addto_blacklist_by_account(Fetio_Account *, EventListener, void *); */
PyObject * pyf_addto_blacklist_by_account(PyObject * self, PyObject * args)
{
	PyObject * pdfa;
	int i;

	if(!PyArg_ParseTuple(args, "O", &pdfa))
	  return NULL;
	Fetion_Account * pfa = (Fetion_Account*)pydict_fetion_account(pdfa);
	i = fx_addto_blacklist_by_account(pfa, system_msg_callback_func, sys_msg_cb_args);
	fetion_account_free(pfa);

	return Py_BuildValue("i", i);
}

/* int fx_addto_blacklist_by_uri(const char * uri, EventListener, void *); */
PyObject * pyf_addto_blacklist_by_uri(PyObject * self, PyObject * args)
{
	int i;
	char * uri;

	if(!PyArg_ParseTuple(args, "s", &uri))
	  return NULL;
	i = fx_addto_blacklist_by_uri(uri, system_msg_callback_func, sys_msg_cb_args);

	return Py_BuildValue("i", i);
}

/* int fx_removefrom_blacklist_by_id(const long, EventListener, void *); */
PyObject * pyf_removefrom_blacklist_by_id(PyObject * self, PyObject * args)
{
	int i;
	long uid;

	if(!PyArg_ParseTuple(args, "k", &uid))
	  return NULL;
	i = fx_removefrom_blacklist_by_id(uid, system_msg_callback_func, sys_msg_cb_args);

	return Py_BuildValue("i", i);
}

/* fx_removefrom_blacklist_by_account(Fetion_Account *, EventListener, void *); */
PyObject * pyf_removefrom_blacklist_by_account(PyObject * self, PyObject * args)
{
	PyObject * pdfa;
	int i;

	if(!PyArg_ParseTuple(args, "O", &pdfa))
	  return NULL;
	Fetion_Account * pfa = (Fetion_Account*)pydict_fetion_account(pdfa);
	i = fx_removefrom_blacklist_by_account(pfa, system_msg_callback_func, sys_msg_cb_args);
	fetion_account_free(pfa);

	return Py_BuildValue("i", i);
}

/* int fx_removefrom_blacklist_by_uri(const char *, EventListener, void *); */
PyObject * pyf_removefrom_blacklist_by_uri(PyObject * self, PyObject * args)
{
	char * uri;
	int i;

	if(!PyArg_ParseTuple(args, "s", &uri))
	  return NULL;
	i = fx_removefrom_blacklist_by_uri(uri, system_msg_callback_func, sys_msg_cb_args);

	return Py_BuildValue("i", i);
}

/* Extend Functions */
/* BOOL fx_send_nudge(long); */
PyObject * pyf_send_nudge(PyObject * self, PyObject * args)
{
	long who;

	if(!PyArg_ParseTuple(args, "k", &who))
	  return NULL;
	if(fx_send_nudge(who))
	  Py_RETURN_TRUE;
	else
	  Py_RETURN_FALSE;
}

/* BOOL fx_set_serve_address(const char *); */
PyObject * pyf_set_serve_address(PyObject * self, PyObject * args)
{
	char * address;

	if(!PyArg_ParseTuple(args, "s", &address))
	  return NULL;
	if(fx_set_serve_address(address))
	  Py_RETURN_TRUE;
	else
	  Py_RETURN_FALSE;
}

/* void fx_set_unknow_serve_address(void); */
PyObject * pyf_set_unknow_serve_address(PyObject * self, PyObject * args)
{
	fx_set_unknow_serve_address();

	Py_RETURN_NONE;
}

/* char * fx_get_serve_address(void); */
PyObject * pyf_get_serve_address(PyObject * self, PyObject * args)
{
	char * s = fx_get_serve_address();

	return Py_BuildValue("s", s);
}

/* BOOL fx_set_proxy(PROXY_ITEM *); */
PyObject * pyf_set_proxy(PyObject * self, PyObject * args)
{
	PyObject * pdpi;
	BOOL b;

	if(!PyArg_ParseTuple(args, "O", &pdpi))
	  return NULL;
	PROXY_ITEM * item = (PROXY_ITEM*)pydict_proxy_item(pdpi);
	b = fx_set_proxy(item);
	proxy_item_free(item);

	if(b)
	  Py_RETURN_TRUE;
	else
	  Py_RETURN_FALSE;
}

/* PROXY_ITEM * fx_get_proxy(); */
PyObject * pyf_get_proxy(PyObject * self, PyObject * args)
{
	return Py_BuildValue("O", proxy_item_pydict(fx_get_proxy()));
}

/* int fx_test_network(PROXY_ITEM *, EventListener, void *); */
PyObject * pyf_test_network(PyObject * self, PyObject * args)
{
	PyObject * pdpi;
	int i;

	if(!PyArg_ParseTuple(args, "O", &pdpi))
	  return NULL;
	PROXY_ITEM * item = (PROXY_ITEM*)pydict_proxy_item(pdpi);
	i = fx_test_network(item, system_msg_callback_func, sys_msg_cb_args);
	proxy_item_free(item);

	return Py_BuildValue("i", i);
}

/* Misc Functions */
/* char * fx_simple_paser_msg(const char *); */
PyObject * pyf_simple_paser_msg(PyObject * self, PyObject * args)
{
	char * msg, * s;

	if(!PyArg_ParseTuple(args, "s", &msg))
	  return NULL;
	s = fx_simple_paser_msg(msg);

	return Py_BuildValue("s", s);
}

/* init function */
void initpyfetion(void)
{
	PyObject * pyfetion;
	pyfetion = Py_InitModule("pyfetion", pyfetionMethods);
	if(!pyfetion) return;

	/* Initialize the python threads */
	PyEval_InitThreads();
}

/* Fetion_Account */
Fetion_Account * pydict_fetion_account(PyObject * dict)
{
	if(!PyDict_Check(dict))
	  return NULL;

	Fetion_Account * account = fetion_account_malloc();
	if(!account) return NULL;

	PyObject * obj = PyDict_GetItemString(dict, "id");
	account->id = PyLong_AsLong(obj);

	obj = PyDict_GetItemString(dict, "uri");
	account->uri = PyString_AsString(obj);

	obj = PyDict_GetItemString(dict, "local_name");
	account->local_name = PyString_AsString(obj);

	obj = PyDict_GetItemString(dict, "buddy_lists");
	account->buddy_lists = PyString_AsString(obj);

	obj = PyDict_GetItemString(dict, "online_status");
	account->online_status = status_str_int(PyString_AsString(obj));

	PyObject * personal = PyDict_GetItemString(dict, "personal");
	if(PyDict_Check(personal))
	  account->personal = pydict_fetion_personal(personal);
	else
	  account->personal = NULL;

	return account;
}

PyObject * fetion_account_pydict(const Fetion_Account * account)
{
	if(!account) return NULL;

	PyObject * dict = PyDict_New();
	assert(dict);
	PyDict_SetItemString(dict, "id", Py_BuildValue("k", account->id));
	PyDict_SetItemString(dict, "uri", Py_BuildValue("s", account->uri));
	PyDict_SetItemString(dict, "local_name", Py_BuildValue("s", account->local_name));
	PyDict_SetItemString(dict, "buddy_lists", Py_BuildValue("s", account->buddy_lists));
	PyDict_SetItemString(dict, "online_status", Py_BuildValue("s", status_int_str(account->online_status)));

	if(account->personal)
	  PyDict_SetItemString(dict, "personal", Py_BuildValue("O", fetion_personal_pydict(account->personal)));
	else
	{
		Py_INCREF(Py_None);
		PyDict_SetItemString(dict, "personal", Py_BuildValue("O", Py_None));
	}

	return dict;
}

Fetion_Account * fetion_account_malloc(void)
{
	return (Fetion_Account*)malloc(sizeof(Fetion_Account));
}

void fetion_account_free(Fetion_Account * account)
{
	if(!account) return;
	fetion_personal_free(account->personal);
	free(account);
}

/* Fetion_MSG */
PyObject * fetion_msg_pydict(const Fetion_MSG * msg)
{
	if(!msg) return NULL;

	PyObject * dict = PyDict_New();
	assert(dict);
	PyDict_SetItemString(dict, "uid", Py_BuildValue("k", msg->uid));
	PyDict_SetItemString(dict, "message", Py_BuildValue("s", msg->message));
	PyDict_SetItemString(dict, "msgformat", Py_BuildValue("s", msg->msgformat));
	PyDict_SetItemString(dict, "ext_id", Py_BuildValue("i", msg->ext_id));

	return dict;
}

Fetion_MSG * pydict_fetion_msg(PyObject * dict)
{
	if(!PyDict_Check(dict)) return NULL;

	Fetion_MSG * msg = fetion_msg_malloc();
	if(!msg) return NULL;

	PyObject * obj = PyDict_GetItemString(dict, "uid");
	msg->uid = PyLong_AsLong(obj);

	obj = PyDict_GetItemString(dict, "message");
	msg->message = PyString_AsString(obj);

	obj = PyDict_GetItemString(dict, "msgformat");
	msg->msgformat = PyString_AsString(obj);

	obj = PyDict_GetItemString(dict, "ext_id");
	msg->ext_id = PyLong_AsLong(obj);

	return msg;
}

Fetion_MSG * fetion_msg_malloc(void)
{
	return (Fetion_MSG*)malloc(sizeof(Fetion_MSG));
}

void fetion_msg_free(Fetion_MSG * msg)
{
	free(msg);
}

/* Fetion_Personal */
PyObject * fetion_personal_pydict(const Fetion_Personal * personal)
{
	if(!personal) return NULL;

	PyObject * dict = PyDict_New();
	assert(dict);

	PyDict_SetItemString(dict, "nickname", Py_BuildValue("s", personal->nickname));
	PyDict_SetItemString(dict, "impresa", Py_BuildValue("s", personal->impresa));
	PyDict_SetItemString(dict, "gender", Py_BuildValue("i", personal->gender));
	PyDict_SetItemString(dict, "nation", Py_BuildValue("s", personal->nation));
	PyDict_SetItemString(dict, "province", Py_BuildValue("s", personal->province));
	PyDict_SetItemString(dict, "city", Py_BuildValue("i", personal->city));
	PyDict_SetItemString(dict, "portrait_crc", Py_BuildValue("i", personal->portrait_crc));
	PyDict_SetItemString(dict, "mobile_no", Py_BuildValue("s", personal->mobile_no));
	PyDict_SetItemString(dict, "name", Py_BuildValue("s", personal->name));
	PyDict_SetItemString(dict, "birth_date", Py_BuildValue("s", personal->birth_date));
	PyDict_SetItemString(dict, "lunar_animal", Py_BuildValue("i", personal->lunar_animal));
	PyDict_SetItemString(dict, "horoscope", Py_BuildValue("i", personal->horoscope));
	PyDict_SetItemString(dict, "profile", Py_BuildValue("s", personal->profile));
	PyDict_SetItemString(dict, "blood_type", Py_BuildValue("i", personal->blood_type));
	PyDict_SetItemString(dict, "occupation", Py_BuildValue("s", personal->occupation));
	PyDict_SetItemString(dict, "hobby", Py_BuildValue("s", personal->hobby));
	PyDict_SetItemString(dict, "personal_email", Py_BuildValue("s", personal->personal_email));
	PyDict_SetItemString(dict, "work_email", Py_BuildValue("s", personal->work_email));
	PyDict_SetItemString(dict, "other_email", Py_BuildValue("s", personal->other_email));
	PyDict_SetItemString(dict, "primary_email", Py_BuildValue("i", personal->primary_email));
	PyDict_SetItemString(dict, "job_title", Py_BuildValue("s", personal->job_title));
	PyDict_SetItemString(dict, "home_phone", Py_BuildValue("s", personal->home_phone));
	PyDict_SetItemString(dict, "work_phone", Py_BuildValue("s", personal->work_phone));
	PyDict_SetItemString(dict, "other_phone", Py_BuildValue("s", personal->other_phone));
	PyDict_SetItemString(dict, "company", Py_BuildValue("s", personal->company));
	PyDict_SetItemString(dict, "compnay_website", Py_BuildValue("s", personal->company_website));
	PyDict_SetItemString(dict, "match_enabled", Py_BuildValue("i", personal->match_enabled));

	return dict;
}

Fetion_Personal * pydict_fetion_personal(PyObject * dict)
{
	if(!PyDict_Check(dict)) return NULL;

	Fetion_Personal * personal = fetion_personal_malloc();
	if(!personal) return NULL;

	PyObject * obj = PyDict_GetItemString(dict, "nickname");
	personal->nickname = PyString_AsString(obj);

	obj = PyDict_GetItemString(dict, "impresa");
	personal->impresa = PyString_AsString(obj);

	obj = PyDict_GetItemString(dict, "gender");
	personal->gender = (int)PyInt_AsLong(obj);

	obj = PyDict_GetItemString(dict, "nation");
	personal->nation = PyString_AsString(obj);

	obj = PyDict_GetItemString(dict, "province");
	personal->province = PyString_AsString(obj);

	obj = PyDict_GetItemString(dict, "city");
	personal->city = (int)PyInt_AsLong(obj);

	obj = PyDict_GetItemString(dict, "portrait_crc");
	personal->portrait_crc = (int)PyInt_AsLong(obj);

	obj = PyDict_GetItemString(dict, "mobile_no");
	personal->mobile_no = PyString_AsString(obj);

	obj = PyDict_GetItemString(dict, "name");
	personal->name = PyString_AsString(obj);

	obj = PyDict_GetItemString(dict, "birth_date");
	personal->birth_date = PyString_AsString(obj);

	obj = PyDict_GetItemString(dict, "lunar_animal");
	personal->lunar_animal = (int)PyInt_AsLong(obj);

	obj = PyDict_GetItemString(dict, "horoscope");
	personal->horoscope = (int)PyInt_AsLong(obj);

	obj = PyDict_GetItemString(dict, "profile");
	personal->profile = PyString_AsString(obj);

	obj = PyDict_GetItemString(dict, "blood_type");
	personal->blood_type = (int)PyInt_AsLong(obj);

	obj = PyDict_GetItemString(dict, "occupation");
	personal->occupation = PyString_AsString(obj);

	obj = PyDict_GetItemString(dict, "hobby");
	personal->hobby = PyString_AsString(obj);

	obj = PyDict_GetItemString(dict, "personal_email");
	personal->personal_email = PyString_AsString(obj);

	obj = PyDict_GetItemString(dict, "work_email");
	personal->work_email = PyString_AsString(obj);

	obj = PyDict_GetItemString(dict, "other_email");
	personal->other_email = PyString_AsString(obj);

	obj = PyDict_GetItemString(dict, "primary_email");
	personal->primary_email = (int)PyInt_AsLong(obj);

	obj = PyDict_GetItemString(dict, "job_title");
	personal->job_title = PyString_AsString(obj);

	obj = PyDict_GetItemString(dict, "home_phone");
	personal->home_phone = PyString_AsString(obj);

	obj = PyDict_GetItemString(dict, "work_phone");
	personal->work_phone = PyString_AsString(obj);

	obj = PyDict_GetItemString(dict, "other_phone");
	personal->other_phone = PyString_AsString(obj);

	obj = PyDict_GetItemString(dict, "company");
	personal->company = PyString_AsString(obj);

	obj = PyDict_GetItemString(dict, "company_website");
	personal->company_website = PyString_AsString(obj);

	obj = PyDict_GetItemString(dict, "match_enabled");
	personal->match_enabled = (int)PyInt_AsLong(obj);

	return personal;
}

Fetion_Personal * fetion_personal_malloc(void)
{
	return (Fetion_Personal*)malloc(sizeof(Fetion_Personal));
}

void fetion_personal_free(Fetion_Personal * personal)
{
	free(personal);
}

/* Fetion_Group */
PyObject * fetion_group_pydict(const Fetion_Group * group)
{
	if(!group) return NULL;

	PyObject * dict = PyDict_New();
	assert(dict);

	PyDict_SetItemString(dict, "id", Py_BuildValue("i", group->id));
	PyDict_SetItemString(dict, "name", Py_BuildValue("s", group->name));

	return dict;
}

Fetion_Group * pydict_fetion_group(PyObject * dict)
{
	if(!PyDict_Check(dict)) return NULL;

	Fetion_Group * group = fetion_group_malloc();
	if(!group) return NULL;

	PyObject * obj = PyDict_GetItemString(dict, "id");
	group->id = (int)PyInt_AsLong(obj);

	obj = PyDict_GetItemString(dict, "name");
	group->name = PyString_AsString(obj);

	return group;
}

Fetion_Group * fetion_group_malloc(void)
{
	return (Fetion_Group*)malloc(sizeof(Fetion_Group));
}

void fetion_group_free(Fetion_Group * group)
{
	free(group);
}

/* Fetion_Black */
PyObject * fetion_black_pydict(const Fetion_Black * black)
{
	if(!black) return NULL;

	PyObject * dict = PyDict_New();
	assert(dict);

	PyDict_SetItemString(dict, "uid", Py_BuildValue("i", black->uid));
	PyDict_SetItemString(dict, "uri", Py_BuildValue("s", black->uri));
	PyDict_SetItemString(dict, "local_name", Py_BuildValue("s", black->local_name));

	return dict;
}

Fetion_Black * pydict_fetion_black(PyObject * dict)
{
	if(!PyDict_Check(dict)) return NULL;

	Fetion_Black * black = fetion_black_malloc();
	if(!black) return NULL;

	PyObject * obj = PyDict_GetItemString(dict, "uid");
	black->uid = PyLong_AsLong(obj);

	obj = PyDict_GetItemString(dict, "uri");
	black->uri = PyString_AsString(obj);

	obj = PyDict_GetItemString(dict, "local_name");
	black->local_name = PyString_AsString(obj);

	return black;
}

Fetion_Black * fetion_black_malloc(void)
{
	return (Fetion_Black*)malloc(sizeof(Fetion_Black));
}

void fetion_black_free(Fetion_Black * black)
{
	free(black);
}

/* Fetion_BList */
PyObject * fetion_blist_pydict(const Fetion_BList * blist)
{
	Fetion_Group * group;
	Fetion_Account * account;
	Fetion_Black * blacklist;
	Fetion_Qun * qun;
	PyObject * plist;

	if(!blist) return NULL;

	PyObject * dict = PyDict_New();
	assert(dict);

	PyDict_SetItemString(dict, "account_count", Py_BuildValue("i", blist->account_count));

	DList * list = blist->group;
	if(list)
	{
		plist = PyList_New(0);
		assert(plist);
		while(list)
		{
			group = (Fetion_Group*)list->data;
			if(group)
			{
				PyObject * pdict = fetion_group_pydict(group);
				PyList_Append(plist, pdict);
			}
			list = d_list_next(list);
		}
		PyDict_SetItemString(dict, "group", Py_BuildValue("O", plist));
	}
	else
	{
		Py_INCREF(Py_None);
		PyDict_SetItemString(dict, "group", Py_BuildValue("O", Py_None));
	}


	list = blist->account;
	if(list)
	{
		plist = PyList_New(0);
		assert(plist);
		while(list)
		{
			account = (Fetion_Account*)list->data;
			if(account)
			{
				PyObject * pdict = fetion_account_pydict(account);
				PyList_Append(plist, pdict);
			}
			list = d_list_next(list);
		}
		PyDict_SetItemString(dict, "account", Py_BuildValue("O", plist));
	}
	else
	{
		Py_INCREF(Py_None);
		PyDict_SetItemString(dict, "account", Py_BuildValue("O", Py_None));
	}

	list = blist->blacklist;
	if(list)
	{
		plist = PyList_New(0);
		assert(plist);
		while(list)
		{
			blacklist = (Fetion_Black*)list->data;
			if(blacklist)
			{
				PyObject * pdict = fetion_black_pydict(blacklist);
				PyList_Append(plist, pdict);
			}
			list = d_list_next(list);
		}
		PyDict_SetItemString(dict, "blacklist", Py_BuildValue("O", plist));
	}
	else
	{
		Py_INCREF(Py_None);
		PyDict_SetItemString(dict, "blacklist", Py_BuildValue("O", Py_None));
	}

	list = blist->qun;
	if(list)
	{
		plist = PyList_New(0);
		assert(plist);
		while(list)
		{
			qun = (Fetion_Qun*)list->data;
			if(qun)
			{
				PyObject * pdict = fetion_qun_pydict(qun);
				PyList_Append(plist, pdict);
			}
			list = d_list_next(list);
		}
		PyDict_SetItemString(dict, "qun", Py_BuildValue("O", plist));
	}
	else
	{
		Py_INCREF(Py_None);
		PyDict_SetItemString(dict, "qun", Py_BuildValue("O", Py_None));
	}

	return dict;
}

Fetion_BList * pydict_fetion_blist(PyObject * dict)
{
	Py_ssize_t s, i;

	if(!PyDict_Check(dict)) return NULL;

	Fetion_BList * blist = fetion_blist_malloc();
	if(!blist) return NULL;
	
	PyObject * obj = PyDict_GetItemString(dict, "account_count");
	blist->account_count = (int)PyInt_AsLong(obj);

	obj = PyDict_GetItemString(dict, "group");
	s = PyList_Size(obj);
	if(s > 0)
	{
		DList * list = d_list_alloc();
		for(i=0; i<s; i++)
		{
			Fetion_Group * pfg = (Fetion_Group*)pydict_fetion_group(PyList_GetItem(obj, i));
			d_list_append(list, pfg);
		}
		blist->group = list;
	}
	else
	  blist->group = NULL;

	obj = PyDict_GetItemString(dict, "account");
	s = PyList_Size(obj);
	if(s > 0)
	{
		DList * list = d_list_alloc();
		for(i=0; i<s; i++)
		{
			Fetion_Account * pfa = (Fetion_Account*)pydict_fetion_account(PyList_GetItem(obj, i));
			d_list_append(list, pfa);
		}
		blist->account = list;
	}
	else
	  blist->account = NULL;

	obj = PyDict_GetItemString(dict, "blacklist");
	s = PyList_Size(obj);
	if(s > 0)
	{
		DList * list = d_list_alloc();
		for(i=0; i<s; i++)
		{
			Fetion_Black * pfb = (Fetion_Black*)pydict_fetion_black(PyList_GetItem(obj, i));
			d_list_append(list, pfb);
		}
		blist->blacklist = list;
	}
	else
	  blist->blacklist = NULL;

	obj = PyDict_GetItemString(dict, "qun");
	s = PyList_Size(obj);
	if(s > 0)
	{
		DList * list = d_list_alloc();
		for(i=0; i<s; i++)
		{
			Fetion_Qun * pfq = (Fetion_Qun*)pydict_fetion_qun(PyList_GetItem(obj, i));
			d_list_append(list, pfq);
		}
		blist->qun = list;
	}
	blist->qun = NULL;

	return blist;
}

Fetion_BList * fetion_blist_malloc(void)
{
	return (Fetion_BList*)malloc(sizeof(Fetion_BList));
}

void fetion_blist_free(Fetion_BList * blist)
{
	if(!blist) return;
	if(blist->group)
	{
		DList * l, * list = blist->group;
		l = list;
		while(list)
		{
			fetion_group_free((Fetion_Group*)list->data);
			list = d_list_next(list);
		}
		d_list_free(l);
	}
	if(blist->account)
	{
		DList * l, * list = blist->account;
		l = list;
		while(list)
		{
			fetion_account_free((Fetion_Account*)list->data);
			list = d_list_next(list);
		}
		d_list_free(l);
	}
	if(blist->blacklist)
	{
		DList * l, * list = blist->blacklist;
		l = list;
		while(list)
		{
			fetion_black_free((Fetion_Black*)list->data);
			list = d_list_next(list);
		}
		d_list_free(l);
	}
	if(blist->qun)
	{
		DList * l, * list = blist->qun;
		l = list;
		while(list)
		{
			fetion_qun_free((Fetion_Qun*)list->data);
			list = d_list_next(list);
		}
		d_list_free(l);
	}
	free(blist);
}

/* Fetion_Qun */
PyObject * fetion_qun_pydict(const Fetion_Qun * qun)
{
	if(!qun) return NULL;

	PyObject * dict = PyDict_New();
	assert(dict);

	PyDict_SetItemString(dict, "id", Py_BuildValue("k", qun->id));
	PyDict_SetItemString(dict, "uri", Py_BuildValue("s", qun->uri));
	PyDict_SetItemString(dict, "identity", Py_BuildValue("i", qun->identity));

	if(qun->quninfo)
	  PyDict_SetItemString(dict, "quninfo", Py_BuildValue("O", fetion_quninfo_pydict(qun->quninfo)));
	else
	{
		Py_INCREF(Py_None);
		PyDict_SetItemString(dict, "quninfo", Py_BuildValue("O", Py_None));
	}

	return dict;
}

Fetion_Qun * pydict_fetion_qun(PyObject * dict)
{
	if(!PyDict_Check(dict)) return NULL;

	Fetion_Qun * qun = fetion_qun_malloc();
	if(!qun) return NULL;
	PyObject * obj = PyDict_GetItemString(dict, "id");
	qun->id = PyLong_AsLong(obj);
	obj = PyDict_GetItemString(dict, "uri");
	qun->uri = PyString_AsString(obj);
	obj = PyDict_GetItemString(dict, "identity");
	qun->identity = (int)PyInt_AsLong(obj);
	obj = PyDict_GetItemString(dict, "quninfo");
	if(PyDict_Check(obj))
	  qun->quninfo = pydict_fetion_quninfo(obj);
	else
	  qun->quninfo = NULL;

	return qun;
}

Fetion_Qun * fetion_qun_malloc(void)
{
	return (Fetion_Qun*)malloc(sizeof(Fetion_Qun));
}

void fetion_qun_free(Fetion_Qun * qun)
{
	if(!qun) return;
	fetion_quninfo_free(qun->quninfo);
	free(qun);
}

/* Fetion_QunInfo */
PyObject * fetion_quninfo_pydict(const Fetion_QunInfo * quninfo)
{
	if(!quninfo) return NULL;

	PyObject * dict = PyDict_New();
	assert(dict);

	PyDict_SetItemString(dict, "uri", Py_BuildValue("s", quninfo->uri));
	PyDict_SetItemString(dict, "group_attributes_version", Py_BuildValue("i", quninfo->group_attributes_version));
	PyDict_SetItemString(dict, "name", Py_BuildValue("s", quninfo->name));
	PyDict_SetItemString(dict, "category", Py_BuildValue("i", quninfo->category));
	PyDict_SetItemString(dict, "introduce", Py_BuildValue("s", quninfo->introduce));
	PyDict_SetItemString(dict, "bulletin", Py_BuildValue("s", quninfo->bulletin));
	PyDict_SetItemString(dict, "portrait_crc", Py_BuildValue("i", quninfo->portrait_crc));
	PyDict_SetItemString(dict, "searchable", Py_BuildValue("i", quninfo->searchable));
	PyDict_SetItemString(dict, "current_member_count", Py_BuildValue("i", quninfo->current_member_count));
	PyDict_SetItemString(dict, "limit_member_count", Py_BuildValue("i", quninfo->limit_member_count));
	PyDict_SetItemString(dict, "group_activity", Py_BuildValue("s", quninfo->group_activity));

	if(quninfo->QunMember)
	{
		PyObject * plqm = PyList_New(0);
		assert(plqm);
		PyDict_SetItemString(dict, "QunMember", Py_BuildValue("O", plqm));
		DList * list = quninfo->QunMember;
		while(list)
		{
			Fetion_QunMember * pqm = (Fetion_QunMember*)list->data;
			if(pqm)
			  PyList_Append(plqm, fetion_qunmember_pydict(pqm));
			list = d_list_next(list);

		}
	}
	else
	{
		Py_INCREF(Py_None);
		PyDict_SetItemString(dict, "QunMember", Py_BuildValue("O", Py_None));
	}

	return dict;
}

Fetion_QunInfo * pydict_fetion_quninfo(PyObject * dict)
{
	if(!PyDict_Check(dict)) return NULL;

	Fetion_QunInfo * pqi = fetion_quninfo_malloc();
	if(!pqi) return NULL;

	PyObject * obj = PyDict_GetItemString(dict, "uri");
	pqi->uri = PyString_AsString(obj);

	obj = PyDict_GetItemString(dict, "group_attributes_version");
	pqi->group_attributes_version = (int)PyInt_AsLong(obj);

	obj = PyDict_GetItemString(dict, "name");
	pqi->name = PyString_AsString(obj);

	obj = PyDict_GetItemString(dict, "category");
	pqi->category = (int)PyInt_AsLong(obj);

	obj = PyDict_GetItemString(dict, "introduce");
	pqi->introduce = PyString_AsString(obj);

	obj = PyDict_GetItemString(dict, "bulletin");
	pqi->bulletin = PyString_AsString(obj);

	obj = PyDict_GetItemString(dict, "portrait_crc");
	pqi->portrait_crc = (int)PyInt_AsLong(obj);

	obj = PyDict_GetItemString(dict, "searchable");
	pqi->searchable = (int)PyInt_AsLong(obj);

	obj = PyDict_GetItemString(dict, "current_member_count");
	pqi->current_member_count = (int)PyInt_AsLong(obj);

	obj = PyDict_GetItemString(dict, "limit_member_count");
	pqi->limit_member_count = (int)PyInt_AsLong(obj);

	obj = PyDict_GetItemString(dict, "group_activity");
	pqi->group_activity = PyString_AsString(obj);

	obj = PyDict_GetItemString(dict, "QunMember");
	if(PyList_Check(obj))
	{
		DList * list = d_list_alloc();
		Py_ssize_t i, s = PyList_Size(obj);
		for(i=0; i<s; i++)
		  d_list_append(list, pydict_fetion_qunmember(PyList_GetItem(obj, i)));
		pqi->QunMember = list;
	}
	else
	  pqi->QunMember = NULL;

	return pqi;
}

Fetion_QunInfo * fetion_quninfo_malloc(void)
{
	return (Fetion_QunInfo*)malloc(sizeof(Fetion_QunInfo));
}

void fetion_quninfo_free(Fetion_QunInfo * quninfo)
{
	if(!quninfo) return;
	if(quninfo->QunMember)
	{
		DList * l, * list = quninfo->QunMember;
		l = list;
		while(list)
		{
			fetion_qunmember_free((Fetion_QunMember*)list->data);
			list = d_list_next(list);
		}
		d_list_free(l);
	}
	free(quninfo);
}

/* Fetion_QunMember */
PyObject * fetion_qunmember_pydict(const Fetion_QunMember * qunmember)
{
	if(!qunmember) return NULL;

	PyObject * pdqm = PyDict_New();
	assert(pdqm);

	PyDict_SetItemString(pdqm, "uri", Py_BuildValue("s", qunmember->uri));
	PyDict_SetItemString(pdqm, "id", Py_BuildValue("k", qunmember->id));
	PyDict_SetItemString(pdqm, "nickname", Py_BuildValue("s", qunmember->nickname));
	PyDict_SetItemString(pdqm, "iicnickname", Py_BuildValue("s", qunmember->iicnickname));
	PyDict_SetItemString(pdqm, "identity", Py_BuildValue("i", qunmember->identity));
	PyDict_SetItemString(pdqm, "state", Py_BuildValue("i", qunmember->state));
	PyDict_SetItemString(pdqm, "client_type", Py_BuildValue("s", qunmember->client_type));

	return pdqm;
}

Fetion_QunMember * pydict_fetion_qunmember(PyObject * dict)
{
	if(!PyDict_Check(dict)) return NULL;

	Fetion_QunMember * pqm = fetion_qunmember_malloc();
	if(!pqm) return NULL;

	PyObject * obj = PyDict_GetItemString(dict, "uri");
	pqm->uri = PyString_AsString(obj);

	obj = PyDict_GetItemString(dict, "id");
	pqm->id = PyLong_AsLong(obj);

	obj = PyDict_GetItemString(dict, "nickname");
	pqm->nickname = PyString_AsString(obj);

	obj = PyDict_GetItemString(dict, "iicnickname");
	pqm->iicnickname = PyString_AsString(obj);

	obj = PyDict_GetItemString(dict, "identity");
	pqm->identity = (int)PyInt_AsLong(obj);

	obj = PyDict_GetItemString(dict, "state");
	pqm->state = (int)PyInt_AsLong(obj);

	obj = PyDict_GetItemString(dict, "client_type");
	pqm->client_type = PyString_AsString(obj);

	return pqm;
}

Fetion_QunMember * fetion_qunmember_malloc(void)
{
	return (Fetion_QunMember*)malloc(sizeof(Fetion_QunMember));
}

void fetion_qunmember_free(Fetion_QunMember * qunmember)
{
	free(qunmember);
}

/* PROXY_ITEM */
PyObject * proxy_item_pydict(const PROXY_ITEM * proxy_item)
{
	if(!proxy_item) return NULL;

	const char * s = NULL;
	PyObject * dict = PyDict_New();

	PyDict_SetItemString(dict, "host", Py_BuildValue("s", proxy_item->host));
	PyDict_SetItemString(dict, "port", Py_BuildValue("s", proxy_item->port));
	PyDict_SetItemString(dict, "name", Py_BuildValue("s", proxy_item->name));
	PyDict_SetItemString(dict, "pwd", Py_BuildValue("s", proxy_item->pwd));

	switch(proxy_item->type)
	{
	case PROXY_DIRECT:
		s = "direct";
		break;
	case PROXY_HTTP:
		s = "http";
		break;
	case PROXY_SOCKS4:
		s = "socks4";
		break;
	case PROXY_SOCKS5:
		s = "socks5";
		break;
	case PROXY_MAX:
		break;
	}

	PyDict_SetItemString(dict, "type", Py_BuildValue("s", s));

	return dict;
}

PROXY_ITEM * pydict_proxy_item(PyObject * dict)
{
	char * s = NULL;

	if(!PyDict_Check(dict)) return NULL;

	PROXY_ITEM * item = proxy_item_malloc();
	if(!item) return NULL;

	PyObject * obj = PyDict_GetItemString(dict, "host");
	item->host = PyString_AsString(obj);

	obj = PyDict_GetItemString(dict, "port");
	item->port = PyString_AsString(obj);

	obj = PyDict_GetItemString(dict, "name");
	item->name = PyString_AsString(obj);

	obj = PyDict_GetItemString(dict, "pwd");
	item->pwd = PyString_AsString(obj);

	obj = PyDict_GetItemString(dict, "type");
	s = PyString_AsString(obj);

	if(strcmp(s, "direct"))
	  item->type = PROXY_DIRECT;
	else if(strcmp(s, "http"))
	  item->type = PROXY_HTTP;
	else if(strcmp(s, "socks4"))
	  item->type = PROXY_SOCKS4;
	else if(strcmp(s, "socks5"))
	  item->type = PROXY_SOCKS5;

	return item;
}

PROXY_ITEM * proxy_item_malloc(void)
{
	return (PROXY_ITEM*)malloc(sizeof(PROXY_ITEM));
}

void proxy_item_free(PROXY_ITEM * item)
{
	free(item);
}

/* status */
int status_str_int(const char * status)
{
	int i;

	if(strcmp(status, "unset") == 0)
	  i = FX_STATUS_UNSET;
	else if(strcmp(status, "online") == 0)
	  i = FX_STATUS_ONLINE;
	else if(strcmp(status, "busy") == 0)
	  i = FX_STATUS_BUSY;
	else if(strcmp(status, "away") == 0)
	  i = FX_STATUS_AWAY;
	else if(strcmp(status, "dinner") == 0)
	  i = FX_STATUS_DINNER;
	else if(strcmp(status, "offline") == 0)
	  i = FX_STATUS_OFFLINE;
	else if(strcmp(status, "meeting") == 0)
	  i = FX_STATUS_MEETING;
	else if(strcmp(status, "phone") == 0)
	  i = FX_STATUS_PHONE;
	else if(strcmp(status, "extended_away") == 0)
	  i = FX_STATUS_EXTENDED_AWAY;
	else if(strcmp(status, "num_primitives") == 0)
	  i = FX_STATUS_NUM_PRIMITIVES;
	else if(strcmp(status, "waiting_auth") == 0)
	  i = FX_STATUS_WAITING_AUTH;
	else if(strcmp(status, "refuse") == 0)
	  i = FX_STATUS_REFUSE;
	else if(strcmp(status, "black") == 0)
	  i = FX_STATUS_BLACK;
	else if(strcmp(status, "mobile") == 0)
	  i = FX_STATUS_MOBILE;
	else
	  i = 0;

	return i;
}

const char * status_int_str(int status)
{
	switch(status)
	{
	case FX_STATUS_UNSET:
		return "unset";
	case FX_STATUS_ONLINE:
		return "online";
	case FX_STATUS_BUSY:
		return "busy";
	case FX_STATUS_OFFLINE:
		return "offline";
	case FX_STATUS_AWAY:
		return "away";
	case FX_STATUS_MEETING:
		return "meeting";
	case FX_STATUS_PHONE:
		return "phone";
	case FX_STATUS_DINNER:
		return "dinner";
	case FX_STATUS_EXTENDED_AWAY:
		return "extended_away";
	case FX_STATUS_NUM_PRIMITIVES:
		return "num_primitives";
	case FX_STATUS_WAITING_AUTH:
		return "waiting_auth";
	case FX_STATUS_REFUSE:
		return "refuse";
	case FX_STATUS_BLACK:
		return "black";
	case FX_STATUS_MOBILE:
		return "mobile";
	}

	return NULL;
}

/* callback functions */
void login_callback_func(int message, WPARAM wParam, LPARAM lParam, void *args)
{	
	const char * s = NULL;

	if(!login_cb) return;

	switch(message)
	{
	case FX_LOGIN_CONNECTING:
		s = "connecting";
		break;
	case FX_LOGIN_WAIT_AUTH:
		s = "wait_auth";
		break;
	case FX_LOGIN_AUTH_OK:
		s = "auth_ok";
		break;
	case FX_LOGIN_FAIL:
		s = "fail";
		break;
	case FX_LOGIN_NETWORK_ERROR:
		s = "network_error";
		break;
	case FX_LOGIN_UNKOWN_ERROR:
		s = "unkown_error";
		break;
	case FX_LOGIN_UNKOWN_USR:
		s = "unkown_usr";
		break;
	case FX_LOGIN_GCL_GETTING:
		s = "gcl_getting";
		break;
	case FX_LOGIN_GCL_OK:
		s = "gcl_ok";
		break;
	case FX_LOGIN_GCL_FAIL:
		s = "gcl_fail";
		break;
	case FX_LOGIN_GP_GETTING:
		s = "gp_getting";
		break;
	case FX_LOGIN_GP_OK:
		s = "gp_ok";
		break;
	case FX_LOGIN_GP_FAIL:
		s = "gp_fail";
		break;
	case FX_LOGIN_OK:
		s = "ok";
		break;
	case FX_LOGIN_TIMEOUT:
		s = "timeout";
		break;
	case FX_LOGIN_URI_ERROR:
		s = "uri_error";
		break;
	case FX_LOGIN_SERVER_ERROR:
		s = "server_error";
		break;
	case FX_LOGIN_SERVER_REFUSE:
		s = "server_refuse";
		break;
	}

	PyGILState_STATE gstate = PyGILState_Ensure();

	/* call login python callback function */
	PyObject_CallFunction(login_cb, (char*)"(sO)", s, args);

	PyGILState_Release(gstate);
}

void system_msg_callback_func(int message, WPARAM wParam, LPARAM lParam, void *args)
{
	const char * s = NULL;

	if(!system_msg_cb) return;

	switch(message)
	{
	case FX_NEW_MESSAGE:
		s = "new_message";
		break;
	case FX_NEW_QUN_MESSAGE:
		s = "new_qun_message";
		break;
	case FX_SYS_MESSAGE:
		s = "sys_message";
		break;
	case FX_UNDGE_MESSAGE:
		s = "undge_message";
		break;
	case FX_SMS_OK:
		s = "sms_ok";
		break;
	case FX_SMS_FAIL:
		s = "sms_fail";
		break;
	case FX_SMS_TIMEOUT:
		s = "sms_timeout";
		break;
	case FX_SMS_UNKOWN_ERROR:
		s = "sms_unkown_error";
		break;
	case FX_SMS_FAIL_LIMIT:
		s = "sms_fail_limit";
		break;
	case FX_DIA_BG_TRYING:
		s = "dia_bg_trying";
		break;
	case FX_DIA_BG_OK:
		s = "dia_bg_ok";
		break;
	case FX_DIA_BG_FAIL:
		s = "dia_bg_fail";
		break;
	case FX_DIA_SEND_OK:
		s = "dia_send_ok";
		break;
	case FX_DIA_SEND_FAIL:
		s = "dia_send_fail";
		break;
	case FX_DIA_SEND_TIMEOUT:
		s = "dia_send_timeout";
		break;
	case FX_DIA_UNKOWN_ERROR:
		s = "dia_unkown_error";
		break;
	case FX_STATUS_UNSET:
		s = "status_unset";
		break;
	case FX_STATUS_ONLINE:
		s = "status_online";
		break;
	case FX_STATUS_BUSY:
		s = "status_busy";
		break;
	case FX_STATUS_OFFLINE:
		s = "status_offline";
		break;
	case FX_STATUS_AWAY:
		s = "status_away";
		break;
	case FX_STATUS_MEETING:
		s = "status_meeting";
		break;
	case FX_STATUS_PHONE:
		s = "status_phone";
		break;
	case FX_STATUS_DINNER:
		s = "status_dinnner";
		break;
	case FX_STATUS_EXTENDED_AWAY:
		s = "status_extended_away";
		break;
	case FX_STATUS_NUM_PRIMITIVES:
		s = "status_num_primitives";
		break;
	case FX_STATUS_WAITING_AUTH:
		s = "status_waiting_auth";
		break;
	case FX_STATUS_REFUSE:
		s = "status_refuse";
		break;
	case FX_STATUS_BLACK:
		s = "status_black";
		break;
	case FX_STATUS_MOBILE:
		s = "status_mobile";
		break;
	case FX_STATUS_SMSEXTENED:
		s = "status_smsextened";
		break;
	case FX_ACCOUNT_UPDATA_OK:
		s = "account_updata_ok";
		break;
	case FX_ADD_GROUP_OK:
		s = "add_group_ok";
		break;
	case FX_ADD_GROUP_FAIL:
		s = "add_group_fail";
		break;
	case FX_ADD_GROUP_TIMEOUT:
		s = "add_group_timeout";
		break;
	case FX_DEL_GROUP_OK:
		s = "del_group_ok";
		break;
	case FX_DEL_GROUP_FAIL:
		s = "del_group_fail";
		break;
	case FX_DEL_GROUP_TIMEOUT:
		s = "del_group_timeout";
		break;
	case FX_RENAME_GROUP_OK:
		s = "rename_group_ok";
		break;
	case FX_RENAME_GROUP_FAIL:
		s = "rename_group_fail";
		break;
	case FX_RENAME_GROUP_TIMEOUT:
		s = "rename_group_timeout";
		break;
	case FX_SET_BUDDY_INFO_OK:
		s = "set_buddy_info_ok";
		break;
	case FX_SET_BUDDY_INFO_FAIL:
		s = "set_buddy_info_fail";
		break;
	case FX_SET_BUDDY_INFO_TIMEOUT:
		s = "set_buddy_info_timeout";
		break;
	case FX_ADDACCOUNT_APP:
		s = "addaccount_app";
		break;
	case FX_ADD_BUDDY_OK:
		s = "add_buddy_ok";
		break;
	case FX_SYS_ERR_NETWORK:
		s = "sys_err_network";
		break;
	case FX_SYS_DEREGISTERED:
		s = "sys_deregistered";
		break;
	case FX_SET_STATE_OK:
		s = "set_state_ok";
		break;
	case FX_SET_STATE_FAIL:
		s = "set_state_fail";
		break;
	case FX_SET_STATE_TIMEOUT:
		s = "set_state_timeout";
		break;
	case FX_SET_IMPRESA_OK:
		s = "set_impresa_ok";
		break;
	case FX_SET_IMPRESA_FAIL:
		s = "set_impresa_fail";
		break;
	case FX_SET_NICKNAME_OK:
		s = "set_nickname_ok";
		break;
	case FX_SET_NICKNAME_FAIL:
		s = "set_nickname_fail";
		break;
	case FX_SET_REFUSE_SMS_DAY_OK:
		s = "set_refuse_sms_day_ok";
		break;
	case FX_SET_REFUSE_SMS_DAY_FAIL:
		s = "set_refuse_sms_day_fail";
		break;
	case FX_ADD_BLACKLIST_OK:
		s = "add_blacklist_ok";
		break;
	case FX_ADD_BLACKLIST_FAIL:
		s = "add_blacklist_fail";
		break;
	case FX_ADD_BLACKLIST_TIMEOUT:
		s = "add_blacklist_timeout";
		break;
	case FX_REMOVE_BLACKLIST_OK:
		s = "remove_blacklist_ok";
		break;
	case FX_REMOVE_BLACKLIST_FAIL:
		s = "remove_blacklist_fail";
		break;
	case FX_REMOVE_BLACKLIST_TIMEOUT:
		s = "remove_blacklist_timeout";
		break;
	case FX_DEL_BUDDY_OK:
		s = "del_buddy_ok";
		break;
	case FX_DEL_BUDDY_FAIL:
		s = "del_buddy_fail";
		break;
	case FX_DEL_BUDDY_TIMEOUT:
		s = "del_buddy_timeout";
		break;
	case FX_MOVE_GROUP_OK:
		s = "move_group_ok";
		break;
	case FX_MOVE_GROUP_FAIL:
		s = "move_group_fail";
		break;
	case FX_RECEIVE_FILE:
		s = "receive_file";
		break;
	case FX_CURRENT_VERSION:
		s = "current_version";
		break;
	case FX_GET_QUNLIST_OK:
		s = "get_qunlist_ok";
		break;
	case FX_GET_QUNLIST_FAIL:
		s = "get_qunlist_fail";
		break;
	case FX_QUN_GP_OK:
		s = "qun_gp_ok";
		break;
	case FX_QUN_SEND_OK:
		s = "qun_send_ok";
		break;
	case FX_QUN_SEND_TIMEOUT:
		s = "qun_send_timeout";
		break;
	case FX_QUN_SEND_FAIL:
		s = "qun_send_fail";
		break;
	case FX_QUN_SMS_OK:
		s = "qun_sms_ok";
		break;
	case FX_QUN_SMS_TIMEOUT:
		s = "qun_sms_timeout";
		break;
	case FX_QUN_SMS_FAIL:
		s = "qun_sms_fail";
		break;
	case FX_QUN_SMS_FAIL_LIMIT:
		s = "qun_sms_fail_limit";
		break;
	}

	PyGILState_STATE gstate = PyGILState_Ensure();
	
	/* call system message python callback function */
	PyObject_CallFunction(system_msg_cb, (char*)"(sIkO)", s, (unsigned int)wParam, (unsigned long)lParam, args);

	PyGILState_Release(gstate);

}

