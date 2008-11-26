/* pyfetion.c
 * Heihaier <admin@heihaier.org>
 * http://www.heihaier.org
 */

#include "pyfetion.h"
#include <string.h>

/* Methods */
/* Fetion Init */
PyObject * pyf_init(PyObject * self, PyObject * args)
{
	BOOL b = fx_init();
	if(b == TRUE)
	  Py_RETURN_TRUE;
	else
	  Py_RETURN_FALSE;
}

PyObject * pyf_terminate(PyObject * self, PyObject * args)
{
	fx_terminate();
	Py_RETURN_NONE;
}

PyObject * pyf_close_network(PyObject * self, PyObject * args)
{
	BOOL b = fx_close_network();
	if(b == TRUE)
	  Py_RETURN_TRUE;
	else
	  Py_RETURN_FALSE;
}

/* Login and Out */
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

PyObject * pyf_set_login_status(PyObject * self, PyObject * args)
{
	const char * status;

	if(!PyArg_ParseTuple(args, "s", &status))
	  return NULL;
	fx_set_login_status(status_str_int(status));

	Py_RETURN_NONE;
}

PyObject * pyf_login(PyObject * self, PyObject * args)
{
	char * uid, * pwd;
	PyObject * fargs;

	if(!PyArg_ParseTuple(args, "ssOO", &uid, &pwd, &login_cb, &fargs))
	  return NULL;
	if(fx_login(uid, pwd, login_callback_func, fargs))
	  Py_RETURN_TRUE;
	else
	  Py_RETURN_FALSE;
}

PyObject * pyf_loginout(PyObject * self, PyObject * args)
{
	fx_loginout();

	Py_RETURN_NONE;
}

/* Set System Message Callback Functions */
PyObject * pyf_set_system_msg_cb(PyObject * self, PyObject * args)
{
	PyObject * fargs;

	if(!PyArg_ParseTuple(args, "OO", &system_msg_cb, &fargs))
	  return NULL;
	fx_set_system_msg_cb(system_msg_callback_func, fargs);

	Py_RETURN_NONE;
}

/* Receive message functions */
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
	// free_fetion_msg(msg);
	return o;
}

/* Send SMS Functions */
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

PyObject * pyf_send_sms(PyObject * self, PyObject * args)
{
	long who;
	char * msg;

	if(!PyArg_ParseTuple(args, "ks", &who, &msg))
	  return NULL;
	return Py_BuildValue("i", fx_send_sms(who, msg, NULL, NULL));
}

PyObject * pyf_send_sms_to_self(PyObject * self, PyObject * args)
{
	char * msg;

	if(!PyArg_ParseTuple(args, "s", &msg))
	  return NULL;
	return Py_BuildValue("i", fx_send_sms_to_self(msg, NULL, NULL));
}

PyObject * pyf_send_sms_by_mobile_no(PyObject * self, PyObject * args)
{
	char * mobile_no;
	char * msg;

	if(!PyArg_ParseTuple(args, "ss", &mobile_no, &msg))
	  return NULL;
	return Py_BuildValue("i", fx_send_sms_by_mobile_no(mobile_no, msg, NULL, NULL));
}

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

PyObject * pyf_s_end_dialog(PyObject * self, PyObject * args)
{
	long who;

	if(!PyArg_ParseTuple(args, "k", &who))
	  return NULL;
	fs_end_dialog(who);

	Py_RETURN_NONE;
}

PyObject * pyf_begin_dialog(PyObject * self, PyObject * args)
{
	long who;

	if(!PyArg_ParseTuple(args, "k", &who))
	  return NULL;
	return Py_BuildValue("i", fx_begin_dialog(who, NULL, NULL));
}

PyObject * pyf_dialog_send(PyObject * self, PyObject * args)
{
	long who;
	char * msg;

	if(!PyArg_ParseTuple(args, "ks", &who, &msg))
	  return NULL;
	return Py_BuildValue("i", fx_dialog_send(who, msg, NULL, NULL));
}

PyObject * pyf_end_dialog(PyObject * self, PyObject * args)
{
	long who;

	if(!PyArg_ParseTuple(args, "k", &who))
	  return NULL;
	fx_end_dialog(who);

	Py_RETURN_NONE;
}

/* Get or Set User Info */
PyObject * pyf_get_usr_uid(PyObject * self, PyObject * args)
{
	const char * s = fx_get_usr_uid();
	return Py_BuildValue("s", s);
}

PyObject * pyf_get_usr_passwd(PyObject * self, PyObject * args)
{
	const char * s = fx_get_usr_passwd();
	return Py_BuildValue("s", s);
}

PyObject * pyf_get_usr_show_name(PyObject * self, PyObject * args)
{
	const char * s = fx_get_usr_show_name();
	return Py_BuildValue("s", s);
}

PyObject * pyf_get_usr_uri(PyObject * self, PyObject * args)
{
	const char * s = fx_get_usr_uri();
	return Py_BuildValue("s", s);
}

PyObject * pyf_get_usr_mobilenum(PyObject * self, PyObject * args)
{
	const char * s = fx_get_usr_mobilenum();
	return Py_BuildValue("s", s);
}

PyObject * pyf_get_usr_score(PyObject * self, PyObject * args)
{
	int i = fx_get_usr_score();
	return Py_BuildValue("i", i);
}

PyObject* pyf_set_user_state(PyObject * self, PyObject * args)
{
	char * state, * desc;
	
	if(!PyArg_ParseTuple(args, "ss", &state, &desc))
	  return NULL;
	
	return Py_BuildValue("i", fx_set_user_state(status_str_int(state), desc, NULL, NULL));
}

PyObject * pyf_get_user_state(PyObject * self, PyObject * args)
{
	int s = fx_get_user_state();

	return Py_BuildValue("s", status_int_str(s));
}

PyObject * pyf_set_user_impresa(PyObject * self, PyObject * args)
{
	char * s;
	int i;

	if(!PyArg_ParseTuple(args, "s", &s))
	  return NULL;
	i = fx_set_user_impresa(s, NULL, NULL);
	return Py_BuildValue("i", i);
}

PyObject * pyf_set_user_nickname(PyObject * self, PyObject * args)
{
	char * s;
	int i;

	if(!PyArg_ParseTuple(args, "s", &s))
	  return NULL;
	i = fx_set_user_nickname(s, NULL, NULL);
	return Py_BuildValue("i", i);
}

PyObject * pyf_get_user_refuse_sms_day(PyObject * self, PyObject * args)
{
	int i = fx_get_user_refuse_sms_day();

	return Py_BuildValue("i", i);
}

PyObject * pyf_set_user_refuse_sms_day(PyObject * self, PyObject * args)
{
	int i, r;

	if(!PyArg_ParseTuple(args, "i", &i))
	  return NULL;
	r = fx_set_user_refuse_sms_day(i, NULL, NULL);

	return Py_BuildValue("i", r);
}

PyObject * pyf_get_expirestime(PyObject * self, PyObject * args)
{
	int s = fx_get_expirestime();
	return Py_BuildValue("i", s);
}

PyObject * pyf_data_get_PersonalInfo(PyObject * self, PyObject * args)
{
	Fetion_Personal * info;

	info = (Fetion_Personal*)fx_data_get_PersonalInfo();
	if(info == NULL)
	  Py_RETURN_NONE;
	else
	{
		PyObject * o = fetion_personal_pydict(info);
		free_fetion_personal(info);
		return o;
	}
}

/* Get contacts info */
PyObject * pyf_get_group(PyObject * self, PyObject * args)
{
	Fetion_Group * group = NULL;
	DList * l, * list = (DList*)fx_get_group();
	PyObject * pylist = PyList_New(0);
	assert(pylist);

	l = list;
	while(list)
	{
		group = (Fetion_Group*)list->data;
		if(group)
		{
			PyList_Append(pylist, fetion_group_pydict(group));
			free_fetion_group(group);
		}
		list = d_list_next(list);
	}
	d_list_free(l);
	return pylist;
}

PyObject * pyf_get_account(PyObject * self, PyObject * args)
{
	Fetion_Account * account = NULL;
	DList * l, * list = (DList*)fx_get_account();
	PyObject * pylist = PyList_New(0);
	assert(pylist);

	l = list;
	while(list)
	{
		account = (Fetion_Account*)list->data;
		if(account)
		{
			PyList_Append(pylist, fetion_account_pydict(account));
			free_fetion_account(account);
		}
		list = d_list_next(list);
	}
	d_list_free(l);
	return pylist;
}

PyObject * pyf_get_blacklist(PyObject * self, PyObject * args)
{
	Fetion_Black * black = NULL;
	DList * l, * list = (DList*)fx_get_blacklist();
	PyObject * pylist = PyList_New(0);
	assert(pylist);

	l = list;
	while(list)
	{
		black = (Fetion_Black*)list->data;
		if(black)
		{
			PyList_Append(pylist, fetion_black_pydict(black));
			// free_fetion_black(black);
		}
		list = d_list_next(list);
	}
	d_list_free(l);
	return pylist;
}

PyObject * pyf_get_qun(PyObject * self, PyObject * args)
{
	Fetion_Qun * qun = NULL;
	DList * l, * list = (DList*)fx_get_qun();
	PyObject * pylist = PyList_New(0);
	assert(pylist);

	l = list;
	while(list)
	{
		qun = (Fetion_Qun*)list->data;
		if(qun)
		{
			PyList_Append(pylist, fetion_qun_pydict(qun));
			//free_fetion_qun(qun);
		}
		list = d_list_next(list);
	}
	d_list_free(l);
	return pylist;
}

PyObject * pyf_get_account_by_id(PyObject * self, PyObject * args)
{
	long id;
	Fetion_Account * account;

	if(!PyArg_ParseTuple(args, "k", &id))
	  return NULL;
	account = (Fetion_Account*)fx_get_account_by_id(id);
	if(account == NULL)
	  Py_RETURN_NONE;

	PyObject * o = fetion_account_pydict(account);
	free_fetion_account(account);
	
	return o;
}

PyObject * pyf_get_qun_by_id(PyObject * self, PyObject * args)
{
	long id;

	if(!PyArg_ParseTuple(args, "k", &id))
	  return NULL;

	Fetion_Qun * qun = (Fetion_Qun*)fx_get_qun_by_id(id);

	PyObject * pydict = fetion_qun_pydict(qun);
	//free_fetion_qun(qun);

	return pydict;
}

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

PyObject * pyf_is_pc_user_by_account(PyObject * self, PyObject * args)
{
	PyObject * account;

	if(!PyArg_ParseTuple(args, "O", &account))
	  return NULL;
	if(!PyDict_Check(account))
	  return NULL;

	Fetion_Account * pfa = pydict_fetion_account(account);
	BOOL b = fx_is_pc_user_by_account(pfa);
	free_fetion_account(pfa);
	if(b)
	  Py_RETURN_TRUE;
	else
	  Py_RETURN_FALSE;
}

PyObject * pyf_is_authed_by_id(PyObject * self, PyObject * args)
{
	long id;
	int i;

	if(!PyArg_ParseTuple(args, "k", &id))
	  return NULL;
	i = fx_is_authed_by_id(id);
	return Py_BuildValue("i", i);
}

PyObject * pyf_is_authed_by_account(PyObject * self, PyObject * args)
{
	PyObject * account;

	if(!PyArg_ParseTuple(args, "O", &account))
	  return NULL;
	if(!PyDict_Check(account))
	  return NULL;

	Fetion_Account * pfa = pydict_fetion_account(account);
	int i = fx_is_authed_by_account(pfa);
	free_fetion_account(pfa);

	return Py_BuildValue("i", i);
}

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

PyObject * pyf_is_InBlacklist_by_account(PyObject * self, PyObject * args)
{
	PyObject * dict;

	if(!PyArg_ParseTuple(args, "O", &dict))
	  return NULL;
	if(!PyDict_Check(dict))
	  return NULL;
	Fetion_Account * pfa = pydict_fetion_account(dict);
	BOOL b = fx_is_InBlacklist_by_account(pfa);
	free_fetion_account(pfa);
	if(b)
	  Py_RETURN_TRUE;
	else
	  Py_RETURN_FALSE;
}

PyObject * pyf_move_group_buddy_by_id(PyObject * self, PyObject * args)
{
	long uid;
	int i, group_id;

	if(!PyArg_ParseTuple(args, "ki", &uid, &group_id))
	  return NULL;
	i = fx_move_group_buddy_by_id(uid, group_id, NULL, NULL);

	return Py_BuildValue("i", i);
}

PyObject * pyf_move_group_buddy(PyObject * self, PyObject * args)
{
	int group_id, i;
	PyObject * pdfa;

	if(!PyArg_ParseTuple(args, "Oi", &pdfa, &group_id))
	  return NULL;
	if(!PyDict_Check(pdfa))
	  return NULL;
	Fetion_Account * pfa = pydict_fetion_account(pdfa);
	i = fx_move_group_buddy(pfa, group_id, NULL, NULL);
	free_fetion_account(pfa);

	return Py_BuildValue("i", i);
}

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

PyObject * pyf_is_on_line_by_account(PyObject * self, PyObject * args)
{
	PyObject * pdfa;

	if(!PyArg_ParseTuple(args, "O", &pdfa))
	  return NULL;
	if(!PyDict_Check(pdfa))
	  return NULL;
	Fetion_Account * pfa = pydict_fetion_account(pdfa);
	BOOL b = fx_is_on_line_by_account(pfa);
	free_fetion_account(pfa);
	if(b)
	  Py_RETURN_TRUE;
	else
	  Py_RETURN_FALSE;
}

PyObject * pyf_get_online_status_by_id(PyObject * self, PyObject * args)
{
	long uid;
	int status;

	if(!PyArg_ParseTuple(args, "k", &uid))
	  return NULL;
	status = fx_get_online_status_by_id(uid);
	
	return Py_BuildValue("s", status_int_str(status));
}

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
	free_fetion_account(pfa);

	return Py_BuildValue("s", status_int_str(status));
}

PyObject * pyf_get_refuse_sms_day(PyObject * self, PyObject * args)
{
	PyObject * pdfa;

	if(!PyArg_ParseTuple(args, "O", &pdfa))
	  return NULL;
	if(!PyDict_Check(pdfa))
	  return NULL;
	Fetion_Account * pfa = pydict_fetion_account(pdfa);
	int i = fx_get_refuse_sms_day(pfa);
	free_fetion_account(pfa);

	return Py_BuildValue("i", i);
}

PyObject * pyf_updata_account_info_by_id(PyObject * self, PyObject * args)
{
	long id;

	if(!PyArg_ParseTuple(args, "k", &id))
	  return NULL;
	fx_updata_account_info_by_id(id);

	Py_RETURN_NONE;
}

PyObject * pyf_updata_account_info_all(PyObject * self, PyObject * args)
{
	fx_updata_account_info_all();

	Py_RETURN_NONE;
}

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
	free_fetion_account(pfa);

	return Py_BuildValue("s", s);
}

PyObject * pyf_get_qun_show_name(PyObject * self, PyObject * args)
{
	return NULL;
}

PyObject * pyf_get_account_group_id(PyObject * self, PyObject * args)
{
	return NULL;
}

/* Group Opt Functions */
PyObject * pyf_s_rename_buddylist(PyObject * self, PyObject * args)
{
	return NULL;
}

PyObject * pyf_s_delete_buddylist(PyObject * self, PyObject * args)
{
	return NULL;
}

PyObject * pyf_rename_buddylist(PyObject * self, PyObject * args)
{
	return NULL;
}

PyObject * pyf_add_buddylist(PyObject * self, PyObject * args)
{
	return NULL;
}

PyObject * pyf_add_buddy_by_uid(PyObject * self, PyObject * args)
{
	return NULL;
}

PyObject * pyf_add_buddy_by_mobile(PyObject * self, PyObject * args)
{
	return NULL;
}

PyObject * pyf_handleContactRequest(PyObject * self, PyObject * args)
{
	return 0;
}

PyObject * pyf_delete_buddylist(PyObject * self, PyObject * args)
{
	return NULL;
}

/* Buddy Opt Functions */
PyObject * pyf_s_set_buddyinfo(PyObject * self, PyObject * args)
{
	return NULL;
}

PyObject * pyf_set_buddyinfo(PyObject * self, PyObject * args)
{
	return NULL;
}

PyObject * pyf_delete_buddy_by_id(PyObject * self, PyObject * args)
{
	return NULL;
}

PyObject * pyf_delete_buddy_by_account(PyObject * self, PyObject * args)
{
	return NULL;
}

PyObject * pyf_addto_blacklist_by_id(PyObject * self, PyObject * args)
{
	return NULL;
}

PyObject * pyf_addto_blacklist_by_account(PyObject * self, PyObject * args)
{
	return NULL;
}

PyObject * pyf_addto_blacklist_by_uri(PyObject * self, PyObject * args)
{
	return NULL;
}

PyObject * pyf_removefrom_blacklist_by_id(PyObject * self, PyObject * args)
{
	return NULL;
}

PyObject * pyf_removefrom_blacklist_by_account(PyObject * self, PyObject * args)
{
	return NULL;
}

PyObject * pyf_removefrom_blacklist_by_uri(PyObject * self, PyObject * args)
{
	return NULL;
}

/* Extend Functions */
PyObject * pyf_send_nudge(PyObject * self, PyObject * args)
{
	return 0;
}

PyObject * pyf_set_serve_address(PyObject * self, PyObject * args)
{
	return 0;
}

PyObject * pyf_set_unknow_serve_address(PyObject * self, PyObject * args)
{
	return 0;
}

PyObject * pyf_get_serve_address(PyObject * self, PyObject * args)
{
	return 0;
}

PyObject * pyf_set_proxy(PyObject * self, PyObject * args)
{
	return NULL;
}

PyObject * pyf_set_unknow_proxy(PyObject * self, PyObject * args)
{
	return NULL;
}

PyObject * pyf_get_proxy(PyObject * self, PyObject * args)
{
	return NULL;
}

PyObject * pyf_test_network(PyObject * self, PyObject * args)
{
	return 0;
}

/* Misc Functions */
PyObject * pyf_simple_paser_msg(PyObject * self, PyObject * args)
{
	return NULL;
}

/* init function */
void initpyfetion(void)
{
	PyObject * pyfetion;
	pyfetion = Py_InitModule("pyfetion", pyfetionMethods);
}

/* Fetion_Account */
Fetion_Account * pydict_fetion_account(PyObject * dict)
{
	if(!PyDict_Check(dict))
	  return NULL;

	Fetion_Account * account = (Fetion_Account*)malloc(sizeof(Fetion_Account));
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

	Fetion_MSG * msg = (Fetion_MSG*)malloc(sizeof(Fetion_MSG));
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

	Fetion_Personal * personal = (Fetion_Personal*)malloc(sizeof(Fetion_Personal));
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

	Fetion_Group * group = (Fetion_Group*)malloc(sizeof(Fetion_Group));
	if(!group) return NULL;

	PyObject * obj = PyDict_GetItemString(dict, "id");
	group->id = (int)PyInt_AsLong(obj);

	obj = PyDict_GetItemString(dict, "name");
	group->name = PyString_AsString(obj);

	return group;
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

	Fetion_Black * black = (Fetion_Black*)malloc(sizeof(Fetion_Black));
	if(!black) return NULL;

	PyObject * obj = PyDict_GetItemString(dict, "uid");
	black->uid = PyLong_AsLong(obj);

	obj = PyDict_GetItemString(dict, "uri");
	black->uri = PyString_AsString(obj);

	obj = PyDict_GetItemString(dict, "local_name");
	black->local_name = PyString_AsString(obj);

	return black;
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
/*	Py_ssize_t s, i;

	if(!PyDict_Check(dict)) return -1;
	if(!blist) return -1;
	
	PyObject * obj = PyDict_GetItemString(dict, "account_count");
	blist->account_count = (int)PyInt_AsLong(obj);

	obj = PyDict_GetItemString(dict, "group");
	s = PyList_Size(obj);
	for(i=0; i<s; i++)
	{
	}*/

	return NULL;
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
	return NULL;
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

	return dict;
}

Fetion_QunInfo * pydict_fetion_quninfo(PyObject * dict)
{
	return 0;
}

/* Fetion_QunMember */
PyObject * fetion_qunmember_pydict(const Fetion_QunMember * qunmember)
{
	return 0;
}

Fetion_QunMember * pydict_fetion_qunmember(PyObject * dict)
{
	return 0;
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
	printf("login callback ... \n");
}

void system_msg_callback_func(int message, WPARAM wParam, LPARAM lParam, void *args)
{
	printf("system msg callback ... \n");
}

