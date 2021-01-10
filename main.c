#include <stdio.h>
#include <sqlite3.h>

#define CHECK_ERROR(error) if (error != SQLITE_OK) fprintf(stderr, "Error: %s\n", sqlite3_errstr(error));

void initializeDatabase() {
	sqlite3 *database;

	// Create / Open database
	int error_code = sqlite3_open_v2("calendar.db", &database,
			SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, NULL);
	CHECK_ERROR(error_code);
	
	const char *statement = "create table events(\
		id			int primary key	NOT null,\
		title		text			NOT null,\
		description	text			NOT null,\
		date		text			NOT null,\
		time		text			NOT null,\
		repeat		text			NOT null,\
		category	text			NOT null\
	);";

	sqlite3_stmt *stmt;

	// Prepare a SQL statement
	error_code = sqlite3_prepare_v2(database, statement, -1, &stmt, NULL);
	CHECK_ERROR(error_code);
	
	printf("%d\n", error_code);
	printf("hello?\n");

	error_code = sqlite3_step(stmt);
	CHECK_ERROR(error_code);
}

void createEvent() {

}

void readEvent() {

}

void updateEvent() {

}

void deleteEvent() {

}

int main() {
	initializeDatabase();
	return 0;
}
