/**
 * @file mx314.cpp regression case for bug MXS-314 ("")
 *
 * - check if Maxscale alive
 */

#include <my_config.h>
#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <string>
#include "testconnections.h"

using std::string;
using namespace std;

int main(int argc, char *argv[])
{
    MYSQL_STMT* stmt;
    int start = 300, p = 0;
    string query = "select 1";

    TestConnections * Test = new TestConnections(argc, argv);
    Test->set_timeout(50);

    Test->connect_maxscale();

    stmt = mysql_stmt_init(Test->conn_rwsplit);

    for(int i = 0;i<start;i++)
        query += ",1";

    Test->tprintf("Query: %s\n", query.c_str());

    for(int i = start;i<1000;i++)
    {
        Test->set_timeout(5);
        cout << i << " ";
        if(mysql_stmt_prepare(stmt,query.c_str(),query.length()))
        {
            Test->add_result(1, "Error: %s\n", mysql_error(Test->conn_rwsplit));
            Test->add_result(1, "Failed at %d\n", i);
//            Test->copy_all_logs();
//            return 1;
        }
        if(mysql_stmt_reset(stmt))
        {
            Test->add_result(1, "Error: %s\n", mysql_error(Test->conn_rwsplit));
            Test->add_result(1, "Failed at %d\n", i);
//            Test->copy_all_logs();
//            return 1;
        }
        query += ",1";
        if(i - p > 20)
        {
            p = i;
            cout << endl;
        }
    }
    cout << endl;
    Test->set_timeout(20);
    mysql_stmt_close(stmt);
    Test->close_maxscale_connections();
    Test->copy_all_logs();
    return(Test->global_result);
}
