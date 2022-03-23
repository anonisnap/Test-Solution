#include <stdlib.h>
#include "account.h"

typedef struct account {
	int account_no;
	double credit_limit; // This is the amount you can go below 0
	double balance;
} account;

account_t account_create(int account_no, double credit_limit, double balance) {
	account_t _new_account = calloc(sizeof(account), 1);

	if (NULL == _new_account) {
		return NULL;
	}

	_new_account->account_no = account_no;
	_new_account->credit_limit = credit_limit;
	_new_account->balance = balance;

	return _new_account;
}

account_status_e account_destroy(account_t* self) {
	if (NULL == *self) {
		return ACCOUNT_NOT_INSTANTIATED;
	}
	else {
		free(*self);
		*self = NULL;
		return OK;
	}
}

account_status_e account_withdraw(account_t self, double amount)
{
	if (NULL == self) {
		return ACCOUNT_NOT_INSTANTIATED;
	}
	else if (self->balance - amount < 0 - self->credit_limit) {
		return OVER_MAX_CREDIT_LIMIT;
	}
	else {
		self->balance -= amount;
		return OK;
	}
}

account_status_e account_deposit(account_t self, double amount)
{
	self->balance += amount;
	return OK;
}

double account_get_balance(account_t self)
{
	return self->balance;
}

double account_get_credit_limit(account_t self)
{
	return self->credit_limit;
}

int account_get_account_no(account_t self)
{
	return self->account_no;
}

char* account_get_status(account_status_e status)
{
	switch (status)
	{
	case OK:
		return "Ok";
	case OVER_MAX_CREDIT_LIMIT:
		return "Over Max Credit";
	case ACCOUNT_NOT_INSTANTIATED:
		return "Account not Instantiated";
	default:
		return "STATUS NOT FOUND";
	};
}