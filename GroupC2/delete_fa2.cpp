#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<sqlite3.h>
using namespace std;


void createDataBase() {
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
   char *sqlTable, *sqlTable1, *sqlTable2, *sqlTable3, *sqlTable4;
   const char **data;

   /* Open database */
rc = sqlite3_open("Project_automata.db", &db);


//SQL Create Table FA
sqlTable = "CREATE TABLE FA("\
            "id INT PRIMARY KEY NOT NULL,"\
            "fa_type CHAR(50) NOT NULL,"\
            "description CHAR(50) NOT NULL);";
rc = sqlite3_exec(db, sqlTable, NULL, 0, &zErrMsg);

//SQL Create Table Alphabet
sqlTable1 = "CREATE TABLE alphabet("\
            "fa_id INT NOT NULL,"\
            "symbol CHAR NOT NULL ,"\
            "PRIMARY KEY (fa_id,symbol) ,"\
            "FOREIGN KEY (fa_id) REFERENCES fa(id));";
rc = sqlite3_exec(db, sqlTable1, NULL, 0, &zErrMsg);

//SQL Create Table states
sqlTable2 = "CREATE TABLE states("\
            "fa_id  INT,"\
            "state INT NOT NULL,"\
            "start_state  INT NOT NULL, "\
            "final_state INT NOT NULL, "\
            "PRIMARY KEY (fa_id,state) , "\
            "FOREIGN KEY (fa_id) REFERENCES fa(id));";
rc = sqlite3_exec(db, sqlTable2, NULL, 0, &zErrMsg);
   if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error transition: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }
    else {
        fprintf(stdout, "successfully!\n");
    }


sqlTable3 = "CREATE TABLE transition("\
            "fa_id  INT NOT NULL,"\
            "state  INT NOT NULL ,"\
            "symbol CHAR NOT NULL ,"\
            "next_state INT ,"\
            "PRIMARY KEY (fa_id ,state ,symbol ,next_state),"\
            "FOREIGN KEY (fa_id) REFERENCES fa(id),"\
            "FOREIGN KEY (state) REFERENCES states(state),"\
            "FOREIGN KEY (symbol) REFERENCES alphabet(symbol),"\
            "FOREIGN KEY (next_state) REFERENCES states(state));";
rc = sqlite3_exec(db, sqlTable3,NULL,0,&zErrMsg);


sqlite3_close(db);
}


int callback(void *data, int argc, char **argv, char **azColName) {
   int i;
   fprintf(stderr, "%s: ", (const char*)data);

   for(i = 0; i<argc; i++) {
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   printf("\n");
   return 0;
}

void deleteDatabase(){
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
   sql3 = "DELETE from states where fa_id=6; " \
         "SELECT * from states";
rc = sqlite3_exec(db, sql3, callback, (void*)data, &zErrMsg);
      cout<<"Delete ID from TABLE transition\n"<<endl;
   sql4 = "DELETE from transition where fa_id=8;" \
         "SELECT * from transition";
     rc = sqlite3_exec(db, sql4, callback, (void*)data, &zErrMsg);


   if( rc != SQLITE_OK ) {
      fprintf(stderr, "SQL error: %s\n", zErrMsg);
      sqlite3_free(zErrMsg);
   } else {
      fprintf(stdout, "delete database successfully\n");
   }
   sqlite3_close(db);

}

main(){


     createDataBase();
     deleteDatabase();


}
