#pragma once

typedef enum account_status {
	OK,
	OVER_MAX_CREDIT_LIMIT,
	ACCOUNT_NOT_INSTANTIATED
}account_status_e;

char* account_get_status(account_status_e status);

typedef struct account* account_t;

account_t account_create(int account_no, double credit_limit, double balance);

account_status_e account_destroy(account_t* self);

account_status_e account_withdraw(account_t self, double amount);

account_status_e account_deposit(account_t self, double amount);

double account_get_balance(account_t self);

double account_get_credit_limit(account_t self);

int account_get_account_no(account_t self);