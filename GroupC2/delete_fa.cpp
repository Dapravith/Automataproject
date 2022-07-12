#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>
using namespace std;

int callback(void *data, int argc, char **argv, char **azColName) {
   int i;
   fprintf(stderr, "%s: ", (const char*)data);

   for(i = 0; i<argc; i++) {
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   printf("\n");
   return 0;
}

int main(int argc, char* argv[]) {
   sqlite3 *db;
   char *zErrMsg = 0;
   int rc;
   char *sql1,*sql2,*sql3,*sql4;
   const char* data = "ID";
   const char* data1 = "fa_id";

   /* Open database */
   rc = sqlite3_open("project_automata.db", &db);

   if( rc ) {
      fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
      return(0);
   } else {
      fprintf(stderr, "Opened database successfully\n");
   }

   /* Create merged SQL statement */
   cout<<"Delete ID from TABLE FA\n"<<endl;
   sql1 = "DELETE from FA where ID=1; " \
         "SELECT * from FA";
    /* Execute SQL statement */
   rc = sqlite3_exec(db, sql1, callback, (void*)data, &zErrMsg);
    cout<<"Delete ID from TABLE alphabet\n"<<endl;
   sql2 = "DELETE from alphabet where fa_id=5; " \
         "SELECT * from alphabet";
   /* Execute SQL statement */
   rc = sqlite3_exec(db, sql2, callback, (void*)data, &zErrMsg);
   cout<<"Delete ID from TABLE states\n"<<endl;
   sql3 = "DELETE from states where fa_id=7; " \
         "SELECT * from states";
rc = sqlite3_exec(db, sql3, callback, (void*)data, &zErrMsg);
      cout<<"Delete ID from TABLE transition\n"<<endl;
   sql4 = "DELETE from transition where fa_id=4;" \
         "SELECT * from transition";
     rc = sqlite3_exec(db, sql4, callback, (void*)data, &zErrMsg);


   if( rc != SQLITE_OK ) {
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   } else {
      fprintf(stdout, "delete database successfully\n");
   }
   sqlite3_close(db);
   return 0;
}
