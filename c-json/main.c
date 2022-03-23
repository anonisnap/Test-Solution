#include <stdio.h>
#include "cJSON.h"
#include "account.h"

main() {
	// Test of cJSON Library

	account_t account = account_create(10, 200, 400);

	// Create a JSON Object
	cJSON* jsonObj = cJSON_CreateObject();

	// Add Information to the JSON Object
	cJSON_AddNumberToObject(jsonObj, "Account Number", account_get_account_no(account));
	cJSON_AddNumberToObject(jsonObj, "Credit Limit", account_get_credit_limit(account));
	cJSON_AddNumberToObject(jsonObj, "Balance", account_get_balance(account));
	
	// Convert JSON Object to Formatted String
	char* s = cJSON_Print(jsonObj);

	// Print JSON Formatted String
	printf("%s\n\n", s);

	// Prints a String, parsed from a raw JSON string
	printf("%s\n", cJSON_Print(cJSON_Parse("\{\"Name\":\"Sander\"\,\"Age\":26}")));
}